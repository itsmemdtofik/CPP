/**
 * ! Files handling in C++
 *
 * The fstream library allows us to work with files.
 * To use the fstream library, include both the standard <iostream> AND <fstream> header file.
 * To write to the file, use the insertion operator (<<).
 *
 */

/*
 * 1  | Class    | Description
 * 2  | -------- | ------------------------------------------
 * 3  | ofstream | Creates and writes to files
 * 4  | ifstream | Reads from files
 * 5  | fstream  | A combination of ofstream and ifstream:
 * 6  |          | creates, reads, and writes to files
 */

#include <iostream>
#include <fstream>

int main()
{

    // Creat and open a txt files
    std::ofstream MyFile("/Users/itsmemdtofik/Downloads/C++/Oopconcept/Data.txt");

    // Write to the files
    MyFile << "Files can be tricky, but it is fun enough!";

    // Close the files
    MyFile.close();

    // Reading the file here whatever written previous
    std::string text;
    std::ifstream MyReadFile("Data.txt");

    // Use a while loop with getline() function to display
    std::cout << " Reading from the written files." << std::endl;
    while (std::getline(MyReadFile, text))
    {
        std::cout << text << std::endl;
    }

    return 0;
}