/**
 * ! Best practice in Constructor
 *
 * This follows encapsulation (a core OOP principle), where:
 * Data (m_name, m_companyName, m_age) is private (hidden from direct access).
 * Controlled access is provided via public getters/setters.
 * Getters allow read-only access to private members.
 * Setters allow controlled modification of private members.
 */

#include <iostream>
#include <string>

class Employee
{
private:
    std::string m_name;
    std::string m_companyName;
    int m_age;

public:
    // Constructor
    Employee(const std::string &name, const std::string &companyName, int age)
        : m_name(name), m_companyName(companyName), m_age(age) {}

    // Getter methods
    std::string getName() const { return m_name; }
    std::string getCompanyName() const { return m_companyName; }
    int getAge() const { return m_age; }

    // Setter methods
    void setName(const std::string &name) { m_name = name; }
    void setCompanyName(const std::string &companyName) { m_companyName = companyName; }
    void setAge(int age) { m_age = age; }
};

int main()
{
    // Create an Employee object
    Employee emp("John Doe", "Tech Corp", 30);

    // Print employee details using getters
    std::cout << "Employee Name: " << emp.getName() << std::endl;
    std::cout << "Company Name: " << emp.getCompanyName() << std::endl;
    std::cout << "Age: " << emp.getAge() << std::endl;

    // Modify values using setters
    emp.setName("Jane Smith");
    emp.setAge(32);

    // Print updated details
    std::cout << "\nUpdated Employee Details:" << std::endl;
    std::cout << "Name: " << emp.getName() << std::endl;
    std::cout << "Age: " << emp.getAge() << std::endl;

    return 0;
}