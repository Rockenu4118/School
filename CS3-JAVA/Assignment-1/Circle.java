public class Circle {
    double _radius;

    public Circle(double radius) { _radius = radius; }

    public double getRadius() { return _radius; }

    public double getDiameter() { return 2.0 * _radius; }

    public double getCircumference() { return 2.0 * Math.PI * _radius; }

    public double getArea() { return Math.PI * _radius * _radius; }
}