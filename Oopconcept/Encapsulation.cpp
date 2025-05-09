/**
 * ! Encapsulation in C++
 *
 * The meaning of encapsulation is to make sure that "sensitive" data is hidden from users.
 * To acheive this, you must declare class variables / attributes as private.
 * If you want others to read or modify the value of a private member, you can provide the public
 * get() and set() methods.
 *
 *
 */

/**
 * ! Lets try to access the private members using get() and set() methods.
 * 
 */

#include <iostream>
#include <string>

class Employee
{

private:
    int salary;

public:
    void setSalary(int s)
    {
        salary = s;
    }

    int getSalary()
    {
        return salary;
    }
};

int main()
{
    Employee emp;
    emp.setSalary(500000);

    std::cout << "The salary of employee : " << emp.getSalary() << "\n";
    return 0;
}

/**
 * Example explained:
 * The salary attribute is private, which have restricted access.
 * The public setSalary() method takes a parameter (s) and assigns it to the salary attribute (salary = s).
 * The public getSalary() method returns the value of the private salary attribute.
 * Inside main(), we create an object of the Employee class. Now we can use the setSalary() method to set the value of the private attribute to 50000. Then we call the getSalary() method on the object to return the value.
 * 
 * !Why Encapsulation:
 * It is considered good practice to declare your class attributes as private (as often as you can). 
 * Encapsulation ensures better control of your data, because you (or others) can change one part of the code without affecting other parts.
 * Increased security of data
 */