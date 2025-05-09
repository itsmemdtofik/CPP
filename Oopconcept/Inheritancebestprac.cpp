/**
 * ! Inheritance Best Practice in C++
 */

#include <iostream>
#include <string>

/**
 * Base class for vehicles
 */
class Vehicle
{
protected: // Changed from public to protected for better encapsulation
    std::string brand;

public:
    // Constructor to initialize brand
    explicit Vehicle(const std::string &brandName = "Ford") : brand(brandName) {}

    // Virtual destructor for proper polymorphic deletion
    virtual ~Vehicle() = default;

    // Make display virtual to allow overriding
    virtual void display() const
    {
        std::cout << "Vehicle brand: " << brand << "\n";
    }

    // Getter for brand (better encapsulation)
    std::string getBrand() const { return brand; }
};

/**
 * Derived class for cars
 */
class Car : public Vehicle
{
private:
    std::string model;

public:
    // Constructor initializing both base and derived members
    Car(const std::string &brandName = "Ford", const std::string &modelName = "Mustang")
        : Vehicle(brandName), model(modelName) {}

    // Override display method
    void display() const override
    {
        std::cout << "Car - Brand: " << brand << ", Model: " << model << "\n";
    }

    // Getter for model
    std::string getModel() const { return model; }
};

int main()
{
    Car car;
    car.display(); // Now shows more specific information

    // Using getters instead of direct member access
    std::cout << car.getBrand() + " " + car.getModel() << "\n";

    return 0;
}