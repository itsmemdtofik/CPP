/**
 * ! OOP in C++
 *
 * OOP stands for Object-Oriented Programming.
 * Procedural programming is about writing procedures or functions that perform operations on the data, while object-oriented programming is about creating objects that contain both data and functions.
 *
 * Object-oriented programming has several advantages over procedural programming:
 * OOP is faster and easier to execute
 * OOP provides a clear structure for the programs
 * OOP helps to keep the C++ code DRY "Don't Repeat Yourself", and makes the code easier to maintain, modify and debug
 * OOP makes it possible to create full reusable applications with less code and shorter development time
 *
 * !Tip: The "Don't Repeat Yourself" (DRY) principle is about reducing the repetition of code. You should extract out the codes that are common for the application, and place them at a single place and reuse them instead of repeating it.
 *
 * So, a class is a template for objects, and an object is an instance of a class
 * When the individual objects are created, they inherit all the variables and functions from the class.
 *
 */

class MyClass
{
public:
    int myNum;
    string myString;
};

/**
 * !Example explained
 * 
 * The class keyword is used to create a class called MyClass.
 * The public keyword is an access specifier, which specifies that members (attributes and methods) of the class are accessible from outside the class. You will learn more about access specifiers later.
 * Inside the class, there is an integer variable myNum and a string variable myString. When variables are declared within a class, they are called attributes
 * At last, end the class definition with a semicolon ;.
 */