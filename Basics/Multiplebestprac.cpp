/**
 * ! Multiple Inheritance Best Practice in C++
 *
 */

/*
 * 1. Interface Segregation: Using pure abstract base classes (ILoggable, ISerializable) for interfaces
 * 2. Virtual Inheritance: Solving the diamond problem with virtual inheritance from Asset
 * 3. Proper Constructor Chaining: Directly calling the virtual base constructor
 * 4. Clear Overriding: Explicitly using override keyword
 * 5. Reusing Implementations: Calling parent class implementations where appropriate
 * 6. Polymorphic Usage: Demonstrating how to use objects through different base interfaces
 * 7. Access Control: Proper use of public, protected, and private members
 * 8. Virtual Destructors: Ensuring proper cleanup with virtual destructors in base classes
 */

#include <iostream>
#include <string>
#include <memory>

// =============================================
// Best Practice 1: Use interfaces (abstract base classes)
// =============================================

// Interface for objects that can be logged
class ILoggable
{
public:
    virtual ~ILoggable() = default;             // Always make destructor virtual in base classes
    virtual std::string getLogInfo() const = 0; // Pure virtual function
};

// Interface for objects that can be serialized
class ISerializable
{
public:
    virtual ~ISerializable() = default;
    virtual std::string toJson() const = 0;
    virtual void fromJson(const std::string &json) = 0;
};

// =============================================
// Best Practice 2: Use virtual inheritance to solve diamond problem
// =============================================

// Base class with virtual inheritance
class Asset
{
public:
    Asset(const std::string &id) : id_(id) {}
    virtual ~Asset() = default;

    std::string getId() const { return id_; }
    virtual double getValue() const = 0; // Pure virtual

protected:
    void setId(const std::string &id) { id_ = id; }

private:
    std::string id_;
};

// =============================================
// Best Practice 3: Keep inheritance hierarchies shallow
// =============================================

// First derived class
class FinancialAsset : public virtual Asset, public ISerializable
{
public:
    FinancialAsset(const std::string &id, double value)
        : Asset(id), currentValue_(value) {}

    double getValue() const override { return currentValue_; }

    // ISerializable implementation
    std::string toJson() const override
    {
        return R"({"id":")" + getId() + R"(", "value":)" + std::to_string(currentValue_) + "}";
    }

    void fromJson(const std::string &json) override
    {
        // Simplified JSON parsing for example
        size_t idPos = json.find(R"("id":")") + 6;
        size_t idEnd = json.find(R"(")", idPos);
        setId(json.substr(idPos, idEnd - idPos));

        size_t valPos = json.find(R"("value":)") + 8;
        currentValue_ = std::stod(json.substr(valPos));
    }

protected:
    void setValue(double value) { currentValue_ = value; }

private:
    double currentValue_;
};

// Second derived class
class Tradable : public virtual Asset, public ILoggable
{
public:
    Tradable(const std::string &id, const std::string &exchange)
        : Asset(id), exchange_(exchange) {}

    // ILoggable implementation
    std::string getLogInfo() const override
    {
        return "Asset " + getId() + " traded on " + exchange_;
    }

    virtual void executeTrade(double amount)
    {
        std::cout << "Executing trade for " << amount << " of " << getId() << std::endl;
    }

protected:
    std::string exchange_;
};

// =============================================
// Best Practice 4: Combine interfaces and implementation carefully
// =============================================

// Final class with multiple inheritance
class Stock : public FinancialAsset, public Tradable
{
public:
    Stock(const std::string &id, const std::string &exchange, double price, int shares)
        : Asset(id), // Virtual base constructor called directly
          FinancialAsset(id, price * shares),
          Tradable(id, exchange),
          sharesOutstanding_(shares),
          currentPrice_(price)
    {
    }

    // Override getValue to use current price
    double getValue() const override
    {
        return currentPrice_ * sharesOutstanding_;
    }

    // Additional functionality
    void updatePrice(double newPrice)
    {
        currentPrice_ = newPrice;
    }

    // Override executeTrade with stock-specific logic
    void executeTrade(double amount) override
    {
        Tradable::executeTrade(amount);
        std::cout << "Trading " << amount << " shares of " << getId()
                  << " at $" << currentPrice_ << " per share" << std::endl;
    }

    // Implement both interfaces
    std::string toJson() const override
    {
        return FinancialAsset::toJson(); // Reuse parent implementation
    }

    void fromJson(const std::string &json) override
    {
        FinancialAsset::fromJson(json); // Reuse parent implementation
    }

    std::string getLogInfo() const override
    {
        return Tradable::getLogInfo() + " (Stock)"; // Extend parent implementation
    }

private:
    int sharesOutstanding_;
    double currentPrice_;
};

// =============================================
// Best Practice 5: Use polymorphism properly
// =============================================

void logAsset(const ILoggable &asset)
{
    std::cout << "LOG: " << asset.getLogInfo() << std::endl;
}

void serializeAsset(const ISerializable &asset)
{
    std::cout << "JSON: " << asset.toJson() << std::endl;
}

void printAssetValue(const Asset &asset)
{
    std::cout << "Value of " << asset.getId() << ": $" << asset.getValue() << std::endl;
}

int main()
{
    // Create a Stock instance
    Stock apple("AAPL", "NASDAQ", 175.50, 1000);

    // Use through various interfaces
    logAsset(apple);
    serializeAsset(apple);
    printAssetValue(apple);

    // Demonstrate polymorphism
    std::unique_ptr<Asset> asset = std::make_unique<Stock>("MSFT", "NASDAQ", 325.25, 500);
    printAssetValue(*asset);

    // Trade execution
    apple.executeTrade(100);

    // Update and show new value
    apple.updatePrice(180.25);
    printAssetValue(apple);

    return 0;
}