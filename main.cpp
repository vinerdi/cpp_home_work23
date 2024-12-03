#include <iostream>
#include <vector>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void print() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
    double perimeter() const override {
        return 2 * M_PI * radius;
    }
    void print() const override {
        std::cout << "Circle: radius = " << radius << ", area = " << area() << ", perimeter = " << perimeter() << std::endl;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
    double perimeter() const override {
        return 2 * (width + height);
    }
    void print() const override {
        std::cout << "Rectangle: width = " << width << ", height = " << height << ", area = " << area() << ", perimeter = " << perimeter() << std::endl;
    }
};

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}
    double area() const override {
        double s = (a + b + c) / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double perimeter() const override {
        return a + b + c;
    }
    void print() const override {
        std::cout << "Triangle: sides = " << a << ", " << b << ", " << c << ", area = " << area() << ", perimeter = " << perimeter() << std::endl;
    }
};

int main() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(4, 6));
    shapes.push_back(new Triangle(3, 4, 5));

    for (const auto& shape : shapes) {
        shape->print();
    }

    for (auto& shape : shapes) {
        delete shape;
    }

    return 0;
}
