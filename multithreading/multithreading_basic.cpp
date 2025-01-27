#include <iostream>
#include <thread> // For std::thread
#include <string>

using namespace std;

// Function to print numbers
void printNumbers(const string& threadName, int start, int end)
{
    for (int i = start; i <= end; ++i) 
    {
        cout << threadName << ": " << i << endl;
    }
}

int main() 
{
    // Create two threads
    thread thread1(printNumbers, "Thread 1", 1, 5); // Prints 1 to 5
    thread thread2(printNumbers, "Thread 2", 6, 10); // Prints 6 to 10

    // Wait for threads to complete
    thread1.join(); // Ensures thread1 finishes before main continues
    thread2.join(); // Ensures thread2 finishes before main continues

    cout << "Both threads finished execution!" << endl;

    return 0;
}

