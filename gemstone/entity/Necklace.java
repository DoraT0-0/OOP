package entity;

import java.util.ArrayList;
import java.util.List;

public class Necklace {
    private List<Gemstone> gemstones;

    public Necklace() {
        this.gemstones = new ArrayList<>();
    }

    public void addGemstone(Gemstone gemstone) {
        gemstones.add(gemstone);
    }

    public List<Gemstone> getGemstones() {
        return new ArrayList<>(gemstones);
    }

    public double getTotalWeight() {
        return gemstones.stream().mapToDouble(Gemstone::getWeight).sum();
    }

    public double getTotalPrice() {
        return gemstones.stream().mapToDouble(Gemstone::getTotalPrice).sum();
    }

    public void sortByPrice() {
        gemstones.sort((g1, g2) -> Double.compare(g2.getPrice(), g1.getPrice()));
    }

    public List<Gemstone> findGemstonesByTransparency(double minTransparency, double maxTransparency) {
        List<Gemstone> result = new ArrayList<>();
        for (Gemstone gemstone : gemstones) {
            if (gemstone.getTransparency() >= minTransparency && 
                gemstone.getTransparency() <= maxTransparency) {
                result.add(gemstone);
            }
        }
        return result;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Ожерелье:\n");
        for (int i = 0; i < gemstones.size(); i++) {
            sb.append((i + 1) + ". " + gemstones.get(i) + "\n");
        }
        sb.append(String.format("Общий вес: %.2f карат\n", getTotalWeight()));
        sb.append(String.format("Общая стоимость: $%.2f", getTotalPrice()));
        return sb.toString();
    }
}
