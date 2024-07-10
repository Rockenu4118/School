import java.text.DecimalFormat;
import java.util.Scanner;

public class MainTwo {
    public static void main(String[] args) {
        Circle circle = new Circle(readRadius());

        DecimalFormat fmt = new DecimalFormat("0.##");

        System.out.println("The circumference of the circle is: " + fmt.format(circle.getCircumference()));
        System.out.println("The area of the circle is: " + fmt.format(circle.getArea()));
    }

    public static double readRadius()
    {
        double radius;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the radius of the circle: ");
        radius = scan.nextDouble();
        return radius;
    }
}