package service;

import entity.Gemstone;
import entity.PreciousGemstone;
import entity.SemiPreciousGemstone;

public class GemstoneFactory {
    public static Gemstone createGemstone(String type, String name, double weight, 
                                         double price, double transparency, String additional) {
        switch (type.toLowerCase()) {
            case "precious":
                return new PreciousGemstone(name, weight, price, transparency, additional);
            case "semi-precious":
                return new SemiPreciousGemstone(name, weight, price, transparency, additional);
            default:
                throw new IllegalArgumentException("Неизвестный тип камня: " + type);
        }
    }
}
