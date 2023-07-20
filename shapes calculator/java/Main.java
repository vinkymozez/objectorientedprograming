import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Shapes shapeCalculator = new Shapes();
        Scanner scanner = new Scanner(System.in);

        int choice;
        System.out.println("Shapes Calculator");
        System.out.println("1. Rectangle");
        System.out.println("2. Square");
        System.out.println("3. Circle");
        System.out.print("Enter your choice (1/2/3): ");
        choice = scanner.nextInt();

        switch (choice) {
            case 1:
                shapeCalculator.rectangleArea();
                break;
            case 2:
                shapeCalculator.squareArea();
                break;
            case 3:
                shapeCalculator.circleArea();
                break;
            default:
                System.out.println("Invalid choice. Please select 1, 2, or 3.");
        }

        scanner.close(); // Closing the Scanner resource
    }
}
