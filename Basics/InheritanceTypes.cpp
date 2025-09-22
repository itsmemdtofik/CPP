/**
Inheritance:
What: A class (derived) can acquire properties and behaviors of another class (base). It models an “is-a” relationship.

Common forms / types:
Single inheritance — one base, one derived.
Multilevel inheritance — A → B → C (chain).
Hierarchical inheritance — one base, many derived classes.
Multiple inheritance — derived inherits from multiple bases (C++ specific).
Hybrid inheritance — combination of the above.
Virtual inheritance — used to solve the diamond problem when multiple inheritance produces duplicate base subobjects.

Access specifiers for inheritance:
public inheritance: base public → derived public, base protected → derived protected.
protected inheritance: base public/protected → derived protected.
private inheritance (default for class): base public/protected → derived private.
Key pitfalls: Name ambiguity in multiple inheritance; the diamond problem (multiple copies of an ancestor) — solved using virtual inheritance.
*/

#include <iostream>

class Animal {
public:
    void eat() { std::cout << "Animal eats\n"; }
};

/* single inheritance */
class Dog : public Animal {
public:
    void bark() { std::cout << "Dog barks\n"; }
};

/* multiple inheritance example*/
class Flyer {
public:
    void fly() { std::cout << "fly\n"; }
};

class Swimmer {
public:
    void swim() { std::cout << "swim\n"; }
};

class Duck : public Flyer, public Swimmer {
};

/* multilevel inheritance */
class A {
public:
    A() { std::cout << "A\n"; }
};

class B : public A {
public:
    B() { std::cout << "B\n"; }
};

class C : public B {
public:
    C() { std::cout << "C\n"; }
};

int main() {
    Dog d;
    d.eat();
    d.bark();
    Duck duck;
    duck.fly();
    duck.swim();

    C c; // prints A B C (constructor chain)
}
