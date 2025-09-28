package util;

import entity.Gemstone;
import entity.PreciousGemstone;
import entity.SemiPreciousGemstone;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class FileManager {
    public static void saveGemstones(List<Gemstone> gemstones, String filename) throws IOException {
        try (PrintWriter writer = new PrintWriter(new FileWriter(filename))) {
            for (Gemstone gemstone : gemstones) {
                if (gemstone instanceof PreciousGemstone) {
                    PreciousGemstone precious = (PreciousGemstone) gemstone;
                    writer.printf("precious,%s,%.2f,%.2f,%.2f,%s\n",
                            precious.getName(), precious.getWeight(), precious.getPrice(),
                            precious.getTransparency(), precious.getRarity());
                } else if (gemstone instanceof SemiPreciousGemstone) {
                    SemiPreciousGemstone semiPrecious = (SemiPreciousGemstone) gemstone;
                    writer.printf("semi-precious,%s,%.2f,%.2f,%.2f,%s\n",
                            semiPrecious.getName(), semiPrecious.getWeight(), semiPrecious.getPrice(),
                            semiPrecious.getTransparency(), semiPrecious.getOrigin());
                }
            }
        }
    }

    public static List<Gemstone> loadGemstones(String filename) throws IOException {
        List<Gemstone> gemstones = new ArrayList<>();
        
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length >= 6) {
                    String type = parts[0];
                    String name = parts[1];
                    double weight = Double.parseDouble(parts[2]);
                    double price = Double.parseDouble(parts[3]);
                    double transparency = Double.parseDouble(parts[4]);
                    String additional = parts[5];

                    if (type.equals("precious")) {
                        gemstones.add(new PreciousGemstone(name, weight, price, transparency, additional));
                    } else if (type.equals("semi-precious")) {
                        gemstones.add(new SemiPreciousGemstone(name, weight, price, transparency, additional));
                    }
                }
            }
        }
        
        return gemstones;
    }
}