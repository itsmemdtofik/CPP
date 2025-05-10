/**
 * ! Polymorphism in C++
 * 
 * Polymorphism means "many form"
 * An entity can represent multiple behavior
 * 
 */

#include<iostream>
#include<string>

/*
* Base class
*/

class BaseClass {
    public:
        void display(){
            std::cout << " I am from base class!" << std::endl;
        }
};

/*
* Derived class from BaseClass
*/


class DerivedClass : public BaseClass {
    public:
        void display(){
            std::cout << " I am from derived class!" << std::endl;
        }
};

/*
* Another Derived Class from BaseClass
*/

class AnotherDerivedClass : public BaseClass {
    public:
        void display(){
            std::cout << " I am from another derived class!" << std::endl;
        }
};

int main(){

    BaseClass Bobj;
    DerivedClass Dobj;
    AnotherDerivedClass Aobj;

    Bobj.display();
    Dobj.display();
    Aobj.display();
    return 0;
}