package entity;

public class SemiPreciousGemstone extends Gemstone {
    private String origin;

    public SemiPreciousGemstone(String name, double weight, double price, double transparency, String origin) {
        super(name, weight, price, transparency);
        this.origin = origin;
    }

    @Override
    public String getType() {
        return "Полудрагоценный камень";
    }

    public String getOrigin() {
        return origin;
    }

    @Override
    public String toString() {
        return super.toString() + ", Происхождение: " + origin;
    }
}
