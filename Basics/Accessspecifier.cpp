/**
 * ! Access Specifier in C++
 *
 * In C++, there are three access specifiers:
 *
 ** public - members are accessible from outside the clas
 ** private - members cannot be accessed (or viewed) from outside the clas
 ** protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes.
 */

#include <iostream>
#include <string>
#include <utility>

// Base class
class Person {
private:
    std::string secret; // Only accessible within this class

protected:
    std::string name; // Accessible in this class and derived classes

public:
    int age; // Accessible everywhere

    Person(std::string name, const int age, std::string secret)
        : secret(std::move(secret)), name(std::move(name)), age(age) {
    }

    void revealSecret() const {
        std::cout << "My secret is: " << secret << std::endl; // OK (private accessed internally)
    }
};

// Derived class
class Employee : public Person {
public:
    std::string company;

    Employee(const std::string &name, const int age, const std::string &secret, std::string company)
        : Person(name, age, secret), company(std::move(company)) {
    }

    void introduce() {
        // ✅ Can access protected member (name)
        std::cout << "Hi, I'm " << name << ", age " << age << std::endl;

        // ❌ Cannot access private member (secret)
        // std::cout << secret;  // Compiler error!

        // ✅ Can access public member (age)
        age = 30; // Allowed
    }
};

int main() {
    Employee emp("Alice", 25, "Loves chocolate", "Tech Corp");

    // ✅ Public access
    std::cout << "Age: " << emp.age << std::endl; // OK (public)
    emp.revealSecret(); // OK (public method)

    // ❌ Private/protected access fails
    // std::cout << emp.name;                          // Error (protected)
    // std::cout << emp.secret;                       // Error (private)

    return 0;
}
