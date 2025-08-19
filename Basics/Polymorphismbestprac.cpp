/**
 * ! Polymorphism Best Practice in C++
 *
 */

/*
 * Key Takeaways:
 * 1. Interface Design: The Shape class defines a clear interface with pure virtual functions.
 * 2. Virtual Destructor: Crucial for proper cleanup when deleting through a base pointer.
 * 3. Explicit Overrides: Using the override keyword makes intentions clear and catches errors.
 * 4. Non-Virtual Interface (NVI): displayInfo() is a non-virtual function that provides a         template method calling virtual functions.
 * 5. Smart Pointers: unique_ptr manages ownership and prevents memory leaks.
 * 6. Composition: ShapeGroup demonstrates how to build complex objects by combining simpler ones.
 * 7. Polymorphic Processing: The processShape function works with any Shape derivative.
 */

#include <iostream>
#include <memory>
#include <vector>
#include <cmath>

// Abstract base class - interface for all shapes
class Shape
{
public:
    virtual ~Shape() = default; // Virtual destructor is crucial

    // Pure virtual functions (interface)
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void draw() const = 0;

    // Non-virtual interface (NVI) pattern
    void displayInfo() const
    {
        std::cout << "Shape information:\n";
        std::cout << "Area: " << area() << "\n";
        std::cout << "Perimeter: " << perimeter() << "\n";
        draw();
    }
};

// Concrete derived class - Circle
class Circle : public Shape
{
public:
    explicit Circle(double radius) : radius_(radius) {}

    // Use override to be explicit and catch errors
    double area() const override
    {
        return M_PI * radius_ * radius_;
    }

    double perimeter() const override
    {
        return 2 * M_PI * radius_;
    }

    void draw() const override
    {
        std::cout << "Drawing a circle with radius " << radius_ << "\n";
    }

private:
    double radius_;
};

// Concrete derived class - Rectangle
class Rectangle : public Shape
{
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}

    double area() const override
    {
        return width_ * height_;
    }

    double perimeter() const override
    {
        return 2 * (width_ + height_);
    }

    void draw() const override
    {
        std::cout << "Drawing a rectangle " << width_ << "x" << height_ << "\n";
    }

private:
    double width_;
    double height_;
};

// A composite shape using composition
class ShapeGroup : public Shape
{
public:
    void addShape(std::unique_ptr<Shape> shape)
    {
        shapes_.push_back(std::move(shape));
    }

    double area() const override
    {
        double total = 0.0;
        for (const auto &shape : shapes_)
        {
            total += shape->area();
        }
        return total;
    }

    double perimeter() const override
    {
        double total = 0.0;
        for (const auto &shape : shapes_)
        {
            total += shape->perimeter();
        }
        return total;
    }

    void draw() const override
    {
        std::cout << "Drawing a group of " << shapes_.size() << " shapes:\n";
        for (const auto &shape : shapes_)
        {
            shape->draw();
        }
    }

private:
    std::vector<std::unique_ptr<Shape>> shapes_;
};

// Function demonstrating polymorphism
void processShape(const Shape &shape)
{
    shape.displayInfo();
    std::cout << "-----------------\n";
}

int main()
{
    // Using smart pointers for polymorphic objects
    std::unique_ptr<Shape> circle = std::make_unique<Circle>(5.0);
    std::unique_ptr<Shape> rectangle = std::make_unique<Rectangle>(4.0, 6.0);

    // Process shapes polymorphically
    processShape(*circle);
    processShape(*rectangle);

    // Create a shape group
    auto group = std::make_unique<ShapeGroup>();
    group->addShape(std::make_unique<Circle>(2.0));
    group->addShape(std::make_unique<Rectangle>(3.0, 4.0));
    group->addShape(std::move(circle)); // Transfer ownership

    // Process the group polymorphically
    processShape(*group);

    return 0;
}