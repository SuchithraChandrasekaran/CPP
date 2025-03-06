//Factory Design Pattern
//FDP -> Object creation at run time

# include<iostream>

using namespace std;

class Vehicle
{
	protected :
	  string name;
	public:
	virtual void makeParts() = 0;
	virtual void showProduct() = 0;
};
	
class Car :public Vehicle
{
	public :
	void makeParts() 
	{
		cout<< "Making car parts " <<endl;
	}
	void showProduct()
	{
		cout<< "Name " <<"Car" <<endl;
	}
};

class Bike :public Vehicle
{
	public :
	void makeParts() 
	{
		cout<< "Making Bike parts " <<endl;
	}
	void showProduct()
	{
		cout<< "Name " <<"Bike" <<endl;
	}
};

class VehicleFactory
{
	public :
	static Vehicle* createVehicle(int type)
	{
	
		Vehicle *Vehicle=NULL;
		
		switch (type)
		{
			case 1:
			{
				Vehicle= new Car();
				break;
			}
			
			case 2:
			{
				Vehicle= new Bike();
				break;
			}
			default:
			{
				return NULL;
			}
		}
		
		Vehicle->makeParts();
		
		return Vehicle;
	}
};


int main()
{
	int type;
	while(1)
	{
		cout<< "\n Enter Vehicle 1 or 2  or 0 for exit \n" ;
		cin >> type;
		if(!type)
			break;
		Vehicle *t = VehicleFactory::createVehicle(type);
		if(t)
		{
			t->showProduct();
			delete t;
		}
	}
	cout<< "exit .." <<endl;
	return 0;
}	
/* Expected output

 Enter vehicle 1 or 2  or 0 for exit 
1
Making car parts 
Name Car

 Enter vehicle 1 or 2  or 0 for exit 
2
Making Bike parts 
Name Bike

 Enter vehicle 1 or 2  or 0 for exit 

*/
