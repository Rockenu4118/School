import java.text.DecimalFormat;
import java.util.Scanner;

public class MainOne
{
    public static void main (String[] args)
    {
        DecimalFormat fmt = new DecimalFormat("0.##");

        double radius = readRadius();
        double circumference = calcCirc(radius);
        double area = calcArea(radius);

        System.out.println("The circumference of the circle is: " + fmt.format(circumference));
        System.out.println("The area of the circle is: " + fmt.format(area));

    }

    public static double readRadius()
    {
        double radius;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the radius of the circle: ");
        radius = scan.nextDouble();
        return radius;
    }

    public static double calcCirc(double radius)
    {
        return 2.0 * Math.PI * radius;
    }

    public static double calcArea(double radius)
    {
        return Math.PI * radius * radius;
    }
}
