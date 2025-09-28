package entity;

public class PreciousGemstone extends Gemstone {
    private String rarity;

    public PreciousGemstone(String name, double weight, double price, double transparency, String rarity) {
        super(name, weight, price, transparency);
        this.rarity = rarity;
    }

    @Override
    public String getType() {
        return "Драгоценный камень";
    }

    public String getRarity() {
        return rarity;
    }

    @Override
    public String toString() {
        return super.toString() + ", Редкость: " + rarity;
    }
}