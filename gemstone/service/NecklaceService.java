package service;

import entity.Gemstone;
import entity.Necklace;
import util.FileManager;

import java.util.List;
import java.util.Scanner;

public class NecklaceService {
    private Necklace necklace;
    private Scanner scanner;

    public NecklaceService() {
        this.necklace = new Necklace();
        this.scanner = new Scanner(System.in);
    }

    public void start() {
        loadInitialData();
        showMenu();
    }

    private void loadInitialData() {
        try {
            List<Gemstone> gemstones = FileManager.loadGemstones("gemstones.txt");
            for (Gemstone gemstone : gemstones) {
                necklace.addGemstone(gemstone);
            }
            System.out.println("Данные успешно загружены из файла.");
        } catch (Exception e) {
            System.out.println("Не удалось загрузить данные из файла. Создана пустая коллекция.");
        }
    }

    private void showMenu() {
        while (true) {
            System.out.println("\n=== МЕНЮ УПРАВЛЕНИЯ ОЖЕРЕЛЬЕМ ===");
            System.out.println("1. Показать все камни");
            System.out.println("2. Добавить камень");
            System.out.println("3. Отсортировать камни по ценности");
            System.out.println("4. Найти камни по прозрачности");
            System.out.println("5. Показать общую информацию");
            System.out.println("6. Сохранить данные");
            System.out.println("0. Выход");
            System.out.print("Выберите действие: ");

            int choice = scanner.nextInt();
            scanner.nextLine(); // consume newline

            switch (choice) {
                case 1:
                    showAllGemstones();
                    break;
                case 2:
                    addGemstone();
                    break;
                case 3:
                    sortGemstones();
                    break;
                case 4:
                    findGemstonesByTransparency();
                    break;
                case 5:
                    showTotalInfo();
                    break;
                case 6:
                    saveData();
                    break;
                case 0:
                    System.out.println("Выход из программы.");
                    return;
                default:
                    System.out.println("Неверный выбор. Попробуйте снова.");
            }
        }
    }

    private void showAllGemstones() {
        if (necklace.getGemstones().isEmpty()) {
            System.out.println("Ожерелье пустое.");
        } else {
            System.out.println(necklace);
        }
    }

    private void addGemstone() {
        try {
            System.out.print("Тип камня (precious/semi-precious): ");
            String type = scanner.nextLine();
            
            System.out.print("Название: ");
            String name = scanner.nextLine();
            
            System.out.print("Вес (карат): ");
            double weight = scanner.nextDouble();
            
            System.out.print("Цена за карат: ");
            double price = scanner.nextDouble();
            
            System.out.print("Прозрачность (0-1): ");
            double transparency = scanner.nextDouble();
            scanner.nextLine(); // consume newline
            
            System.out.print(type.equals("precious") ? "Редкость: " : "Происхождение: ");
            String additional = scanner.nextLine();
            
            Gemstone gemstone = GemstoneFactory.createGemstone(type, name, weight, price, transparency, additional);
            necklace.addGemstone(gemstone);
            System.out.println("Камень успешно добавлен.");
        } catch (Exception e) {
            System.out.println("Ошибка при добавлении камня: " + e.getMessage());
        }
    }

    private void sortGemstones() {
        necklace.sortByPrice();
        System.out.println("Камни отсортированы по ценности (по убыванию).");
        showAllGemstones();
    }

    private void findGemstonesByTransparency() {
        System.out.print("Минимальная прозрачность (0-1): ");
        double min = scanner.nextDouble();
        
        System.out.print("Максимальная прозрачность (0-1): ");
        double max = scanner.nextDouble();
        
        List<Gemstone> result = necklace.findGemstonesByTransparency(min, max);
        
        if (result.isEmpty()) {
            System.out.println("Камни с заданной прозрачностью не найдены.");
        } else {
            System.out.println("Найденные камни:");
            for (int i = 0; i < result.size(); i++) {
                System.out.println((i + 1) + ". " + result.get(i));
            }
        }
    }

    private void showTotalInfo() {
        System.out.printf("Общий вес ожерелья: %.2f карат\n", necklace.getTotalWeight());
        System.out.printf("Общая стоимость ожерелья: $%.2f\n", necklace.getTotalPrice());
        System.out.printf("Количество камней: %d\n", necklace.getGemstones().size());
    }

    private void saveData() {
        try {
            FileManager.saveGemstones(necklace.getGemstones(), "gemstones.txt");
            System.out.println("Данные успешно сохранены в файл.");
        } catch (Exception e) {
            System.out.println("Ошибка при сохранении данных: " + e.getMessage());
        }
    }
}