/* 
Key Characteristics of Singleton
Single Instance             → Only one object of the class exists.
Global Access               → Provides a way to access the instance globally.
Lazy Initialization         → The instance is created only when needed.
Thread Safety (if required) → Ensures the instance is safely initialized in a multi-threaded environment.
Use Case                    → When you need a single shared resource like a database connection, logging system, or configuration manager.

*/
#include <iostream>

using namespace std;

class Singleton 
{
   static Singleton *instance;
   int data;
 
   private:
    Singleton() 
    { 
        cout << "Singleton instance created." << endl; 
    }
    ~Singleton() 
    { 
        cout << "Singleton instance destroyed." << endl; 
    }
   
   public:
   // Static method to access the singleton instance
   static Singleton *getInstance() 
   {
      // If the instance doesn't exist, create it
      if (!instance)
            instance = new Singleton;
      return instance;
   }

   int getData() 
   {
      return this -> data;
   }

   void setData(int data) 
   {
      this -> data = data;
   }
   
   	// Public method to perform some operation
	void someOperation()
	{
		cout << "Singleton is performing some operation." << endl;
	}

	// Delete the copy constructor and assignment operator
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton *Singleton::instance = 0;

int main()
{
   //Singleton *s = s->getInstance();//this is another way to call getInstance()
   Singleton *s = Singleton ::getInstance();
   
   // Use the Singleton instance
	 s->someOperation();
	
   // Attempting to create another instance will not work
	 // Singleton anotherInstance; // This line would not compile

   cout <<"Default value of object  " << s->getData() << endl;
   s->setData(100);
   cout <<"Value after set function called " << s->getData() << endl;
    
   return 0;
}
/* Expected Output
Singleton instance created.
Singleton is performing some operation.
Default value of object  0
Value after set function called 100
*/
