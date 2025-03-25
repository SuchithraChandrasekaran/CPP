/*Callbacks (Function Pointers as Arguments)
A callback function is a function passed as an argument to another function.*/

#include <iostream>
using namespace std;

void buttonPress() 
{
    cout << "Button Pressed!" << endl;
}

// Function that accepts a callback
void registerCallback(void (*callback)()) 
{
  /*callback is simply a function pointer passed to registerCallback()
  When callback(); is executed inside registerCallback(),
  it calls the function that was passed as an argument.*/

    callback(); // Call the function dynamically
}

int main() 
{
    registerCallback(buttonPress);
}

/* Expected output

Button Pressed ! */
