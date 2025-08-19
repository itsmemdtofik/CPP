/**
 * !Multilevel Inheritance Best Practice in C++
 */

#include <iostream>
#include <string>

/*
 * BEST PRACTICES FOR MULTILEVEL INHERITANCE:
 * 1. Keep inheritance chains shallow (2-3 levels max) to avoid complexity
 * 2. Use virtual inheritance if diamond problem might occur
 * 3. Make base class destructors virtual to ensure proper cleanup
 * 4. Prefer composition over deep inheritance hierarchies
 * 5. Document the inheritance hierarchy clearly
 * 6. Use protected instead of private for members that derived classes need
 * 7. Consider making intermediate classes abstract if they shouldn't be instantiated
 */

// Level 1: Base class (most general)
class Vehicle
{
protected:
    std::string manufacturer;
    int year;

public:
    Vehicle(const std::string &maker, int yr) : manufacturer(maker), year(yr)
    {
        std::cout << "Vehicle constructor called" << std::endl;
    }

    virtual ~Vehicle()
    { // Virtual destructor for proper cleanup
        std::cout << "Vehicle destructor called" << std::endl;
    }

    virtual void displayInfo() const
    {
        std::cout << "Manufacturer: " << manufacturer
             << ", Year: " << year << std::endl;
    }

    // Pure virtual function makes this an abstract base class
    virtual void startEngine() const = 0;
};

// Level 2: Intermediate derived class (more specific than Vehicle)
class Car : public Vehicle
{
protected:
    int numDoors;

public:
    Car(const std::string &maker, int yr, int doors)
        : Vehicle(maker, yr), numDoors(doors)
    {
        std::cout << "Car constructor called" << std::endl;
    }

    ~Car() override
    {
        std::cout << "Car destructor called" << std::endl;
    }

    void displayInfo() const override
    {
        Vehicle::displayInfo(); // Reuse base class functionality
        std::cout << "Number of doors: " << numDoors << std::endl;
    }
    void startEngine() const override
    {
        std::cout << "Car engine started with key/button" << std::endl;
    }

    void openSunroof() const
    {
        std::cout << "Sunroof opened" << std::endl;
    }
};

// Level 3: Most specific derived class
class SportsCar : public Car
{
private:
    double topSpeed;

public:
    SportsCar(const std::string &maker, int yr, int doors, double speed)
        : Car(maker, yr, doors), topSpeed(speed)
    {
        std::cout << "SportsCar constructor called" << std::endl;
    }

    ~SportsCar() override
    {
        std::cout << "SportsCar destructor called" << std::endl;
    }

    void displayInfo() const override
    {
        Car::displayInfo(); // Reuse intermediate class functionality
        std::cout << "Top speed: " << topSpeed << " mph" << std::endl;
    }

    void startEngine() const override
    {
        std::cout << "Sports car engine roared to life!" << std::endl;
    }

    void activateSportMode() const
    {
        std::cout << "Sport mode activated. Performance enhanced!" << std::endl;
    }
};

int main()
{
    // Demonstrating multilevel inheritance
    SportsCar myCar("Ferrari", 2023, 2, 210.5);

    std::cout << "\nDisplaying car info:\n";
    myCar.displayInfo();

    std::cout << "\nStarting engine:\n";
    myCar.startEngine();

    std::cout << "\nUsing specific features:\n";
    myCar.openSunroof();       // From Car class
    myCar.activateSportMode(); // From SportsCar class

    // Polymorphism example
    std::cout << "\nPolymorphic behavior:\n";
    Vehicle *vehiclePtr = &myCar;
    vehiclePtr->startEngine(); // Calls SportsCar's version

    return 0;
}