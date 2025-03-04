/******************************************************************************

Single Responsibility Principle (SRP)
Definition: A class should have only one reason to change, 
meaning it should have only one job or responsibility.

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std ;

// Violating SRP: This class handles both user data and file operations.
class User 
{
    public:
        string name;
        string email;
    
        void saveToFile() 
        {
            // Code to save user data to a file (not SRP compliant)
            cout << "Saving user to file..." << std::endl;
        }
};

// Applying SRP: Separate classes for user data and file operations.
class UserData 
{
    public:
        string name;
        string email;
};

class UserFileManager
{
    public:
        void saveToFile( UserData user) 
        {
            cout << "Saving user: " << user.name << " with email: " << user.email << " to file..." << endl;
        }
};

int main()
{
    /*Example using the class that violates SRP
    User user1;
    user1.name = "suchithra";
    user1.email = "suchithrac@example.com";
    user1.saveToFile();
    */
    
    // Example using the classes that adhere to SRP
    UserData user2;
    user2.name = "name2";
    user2.email = "name2@example.com";
    
    UserFileManager fileManager;
    fileManager.saveToFile(user2);

    return 0;
}
