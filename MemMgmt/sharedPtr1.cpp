/* std::shared_ptr is used in C++ for shared ownership of dynamically allocated objects. 
It helps manage memory efficiently & prevents memory leaks by automatically deleting 
the object when the last owner (shared pointer) goes out of scope. */

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Employee
{
	private :
	string name;
	
	public :
	Employee(string strName)
	{
		name = strName;
		cout << "Employee is added " << strName << endl;
	}
	Employee()
	{
		name ="Unfilled";
		cout << "Employee added _ name unfilled " <<endl;
	}

	~Employee()
	{
		cout << "Employee details deleted for " << name << "  " <<endl;
	}

	void displayDetails()
	{
		cout <<"Employee name  " <<name << endl ;
	}

};

void function()
{
	shared_ptr <Employee> e(new Employee("XYZ")); //count =1
	//1. XYZ is created //2.e is created
	
	e->displayDetails();
	
	//Employee *e= new Employee("ABC");
	
	//delete e;// if deleting not happening , memory leak
	
	//e->displayDetails();//dangling pointer, since accessing after  deallocating the memory 
}

int main()
{

 function();
 Employee *e1 =new Employee("DEF");
 shared_ptr<Employee> emp= make_shared<Employee>("DEF");
 //faster and safer
 
 emp->displayDetails();
 // or the other way 
 (*emp).displayDetails();
}

/*
Expected Output

Employee is added XYZ
Employee name  XYZ
Employee details deleted for XYZ  
Employee is added DEF
Employee is added DEF
Employee name  DEF
Employee name  DEF
Employee details deleted for DEF

*/
