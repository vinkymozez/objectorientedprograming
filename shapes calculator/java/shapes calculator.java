import java.util.Scanner;

class Shapes {
    Scanner scanner = new Scanner(System.in);

    double rectangleArea() {
        double length, width;
        System.out.print("Enter length: ");
        length = scanner.nextDouble();
        System.out.print("Enter width: ");
        width = scanner.nextDouble();
        double area = length * width;
        System.out.println("Area of the rectangle is " + area);
        return area;
    }

    double squareArea() {
        double side;
        System.out.print("Enter side length: ");
        side = scanner.nextDouble();
        double area = side * side;
        System.out.println("Area of the square is " + area);
        return area;
    }

    double circleArea() {
        double radius;
        System.out.print("Enter the radius: ");
        radius = scanner.nextDouble();
        double area = Math.PI * radius * radius;
        System.out.println("Area of the circle is " + area);
        return area;
    }
}
