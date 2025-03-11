/*
Low-level programming: Uses pointers and manual memory management with new and delete.
High-level programming: Uses STL (vector and string) and OOP (class with encapsulation)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// High-level: Using OOP and STL
class Person 
{
  private:
      string name;
      int age;
  
  public:
      Person(string n, int a)
      {
          name = n;
          age =a;
      }
  
      void display() 
      {
          cout << "Name: " << name << ", Age: " << age << endl;
      }
};

// Low-level: Manual memory management with pointers
void lowLevelMemory() 
{
    int* num = new int(42); // Dynamically allocated memory
    cout << "Low-level memory allocation: " << *num << endl;
    delete num; // Manually freeing memory
}

// High-level: Using STL vector
void highLevelVector() 
{
    vector<int> numbers = {1, 2, 3, 4, 5};
    cout << "High-level vector elements: ";
    for (int num : numbers) 
    {
        cout << num << " ";
    }
    cout << endl;
}

int main() 
{
    // High-level OOP
    Person p("ABC", 25);
    p.display();

    // Low-level manual memory allocation
    lowLevelMemory();

    // High-level STL
    highLevelVector();

    return 0;
}
/*
Name: ABC, Age: 25
Low-level memory allocation: 42
High-level vector elements: 1 2 3 4 5 
*/
