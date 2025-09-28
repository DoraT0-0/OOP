package entity;

public abstract class Gemstone {
    private String name;
    private double weight;
    private double price;
    private double transparency;

    public Gemstone(String name, double weight, double price, double transparency) {
        this.name = name;
        this.weight = weight;
        this.price = price;
        this.transparency = transparency;
    }

    public String getName() {
        return name;
    }

    public double getWeight() {
        return weight;
    }

    public double getPrice() {
        return price;
    }

    public double getTransparency() {
        return transparency;
    }

    public double getTotalPrice() {
        return weight * price;
    }

    public abstract String getType();

    @Override
    public String toString() {
        return String.format("%s: %s, Вес: %.2f карат, Цена: $%.2f, Прозрачность: %.2f", 
                getType(), name, weight, getTotalPrice(), transparency);
    }
}