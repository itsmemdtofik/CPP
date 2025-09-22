/**
 * ! Encapsulation Best Practice in C++
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

// Forward declaration for Pimpl
class EmployeeDatabaseImpl;

class Employee
{
private:
    std::string name;
    int age;
    double salary;
    std::string department;

    // Private validation methods
    bool isValidSalary(double s) const { return s >= 0; }
    bool isValidAge(int a) const { return a >= 18 && a <= 65; }

public:
    // Constructor with validation
    Employee(const std::string &n, int a, double s, const std::string &d)
        : name(n), age(a), salary(s), department(d)
    {
        if (!isValidAge(a))
            throw std::invalid_argument("Invalid age");
        if (!isValidSalary(s))
            throw std::invalid_argument("Invalid salary");
    }

    // Getters (all const)
    std::string getName() const { return name; }
    int getAge() const { return age; }
    double getSalary() const { return salary; }
    std::string getDepartment() const { return department; }

    // Setters with validation
    void setSalary(double s)
    {
        if (!isValidSalary(s))
            throw std::invalid_argument("Invalid salary");
        salary = s;
    }

    void promote(double raiseAmount)
    {
        if (!isValidSalary(salary + raiseAmount))
        {
            throw std::invalid_argument("Invalid salary after raise");
        }
        salary += raiseAmount;
    }

    // Immutable pattern example
    Employee withNewDepartment(const std::string &newDept) const
    {
        return Employee(name, age, salary, newDept);
    }
};

// Database class using Pimpl idiom
class EmployeeDatabase
{
public:
    EmployeeDatabase();
    ~EmployeeDatabase();

    void addEmployee(const Employee &emp) const;
    void removeEmployee(const std::string &name) const;
    const Employee *findEmployee(const std::string &name) const;
    void giveRaise(const std::string &name, double amount) const;

private:
    std::unique_ptr<EmployeeDatabaseImpl> pImpl;
};

// Implementation hidden in source file
class EmployeeDatabaseImpl
{
private:
    std::vector<Employee> employees;

    // Private helper methods
    auto findEmployeeIterator(const std::string &name)
    {
        return std::find_if(employees.begin(), employees.end(),
                            [&name](const Employee &e)
                            { return e.getName() == name; });
    }

public:
    void addEmployee(const Employee &emp)
    {
        if (findEmployeeIterator(emp.getName()) != employees.end())
        {
            throw std::runtime_error("Employee already exists");
        }
        employees.push_back(emp);
    }

    void removeEmployee(const std::string &name)
    {
        auto it = findEmployeeIterator(name);
        if (it == employees.end())
        {
            throw std::runtime_error("Employee not found");
        }
        employees.erase(it);
    }

    const Employee *findEmployee(const std::string &name) const
    {
        auto it = std::find_if(employees.begin(), employees.end(),
                               [&name](const Employee &e)
                               { return e.getName() == name; });
        return it != employees.end() ? &(*it) : nullptr;
    }
};

// EmployeeDatabase methods
EmployeeDatabase::EmployeeDatabase() : pImpl(std::make_unique<EmployeeDatabaseImpl>()) {}
EmployeeDatabase::~EmployeeDatabase() = default;

void EmployeeDatabase::addEmployee(const Employee &emp) const { pImpl->addEmployee(emp); }
void EmployeeDatabase::removeEmployee(const std::string &name) const { pImpl->removeEmployee(name); }
const Employee *EmployeeDatabase::findEmployee(const std::string &name) const { return pImpl->findEmployee(name); }

void EmployeeDatabase::giveRaise(const std::string &name, double amount) const {
    const Employee *emp = findEmployee(name);
    if (!emp)
        throw std::runtime_error("Employee not found");

    Employee modified = *emp;
    modified.promote(amount);
    removeEmployee(name);
    addEmployee(modified);
}

int main()
{
    try
    {
        EmployeeDatabase db;

        db.addEmployee(Employee("John Doe", 30, 60000, "Engineering"));
        db.addEmployee(Employee("Jane Smith", 28, 65000, "Marketing"));

        // Promote an employee
        db.giveRaise("John Doe", 5000);

        // Query employee
        if (const Employee *emp = db.findEmployee("John Doe"))
        {
            std::cout << emp->getName() << " now earns $" << emp->getSalary() << std::endl;
        }

        // Demonstrate immutable pattern
        const auto jane = Employee("Jane Smith", 28, 65000, "Marketing");
        Employee janeHR = jane.withNewDepartment("Human Resources");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}