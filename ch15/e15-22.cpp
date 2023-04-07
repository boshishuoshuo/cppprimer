class Figure
{
    public:
        Figure(double, double);
    protected:
        double xSize, ySize;

};

class Figure2D : public Figure
{
    public:
        Figure2D(double, double);
        virtual double area() = 0;
        virtual double perimeter() = 0;
};

class Figure3D : public Figure
{
    public:
        Figure3D(double, double, double);
        virtual double cubage() = 0;
    protected:
        double zSize;
};

class Rectangle : public Figure2D
{
    public:
        Rectangle(double, double);
        virtual double area();
        virtual double perimeter();
};

class Circle : public Figure2D
{
    public:
        Circle(double, double);
        virtual double area();
        virtual double perimeter();
};

class Sphere : public Figure3D
{
    public:
        Sphere(double, double, double);
        virtual double cubage();
};

class Cone : public Figure3D
{
    public:
        Cone(double, double, double);
        virtual double cubage();
};