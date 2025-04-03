/* 
Hybrid- combines two or more types of inheritance (e.g., hierarchical and multiple).
*/
#include<iostream>

class Person 
{
    public:
    void introduce() { std::cout << "I am a person" << std::endl; }
};

class Faculty : public Person 
{
    public:
    void teach() { std::cout << "I teach" << std::endl; }
};

class Student : public Person 
{
    public:
    void study() { std::cout << "I study" << std::endl; }
};

class LibraryMember : public Faculty, public Student 
{
    public:
    void readBooks() { std::cout << "I use Library" << std::endl; }
};

int main() {
    LibraryMember lm;
    // lm.introduce(); // Ambiguous - from both Faculty and Student
    lm.work();   // From Faculty
    lm.study();  // From Student
    lm.readBooks(); // Own method
}
