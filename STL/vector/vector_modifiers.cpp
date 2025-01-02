/*******************************************************
To illustrate the Modifiers in vector 
*******************************************************/
#include <iostream>
#include <vector> 
using namespace std; 

int main() 
{ 
	// Assign vector 
	vector<int> v; 

	// fill the vector with 10 five times 
	v.assign(5, 10); 

	cout << "The vector elements are: "; 
	for (int i = 0; i < v.size(); i++) 
		cout << v[i] << " "; 

	// inserts 15 to the last position 
	v.push_back(15); 
	int n = v.size(); 
	
	cout << "\nThe last element pushed back is: " << v[n-1];
	cout << "\nThe vector size is             : " << n; 
	cout << "\nThe index of "<<v[n-1]<<" is             : " << n;

	// prints the vector 
	cout << "\nThe vector elements are: "; 
	for (int i = 0; i < v.size(); i++) 
		cout << v[i] << " "; 
	// removes last element 
	v.pop_back(); 

	// prints the vector 
	cout << "\nThe vector elements are, after pop_back(): "; 
	for (int i = 0; i < v.size(); i++) 
		cout << v[i] << " "; 

	// inserts 5 at the beginning 
	v.insert(v.begin(), 5); 

	cout << "\nThe first element, after insert at begin(), is: " << v[0]; 

	// removes the first element 
	v.erase(v.begin()); 

	cout << "\nThe first element, after erase at begin() is: " << v[0]; 

	// inserts at the beginning 
	v.emplace(v.begin(), 5); 
	cout << "\nThe first element, after emplace is: " << v[0]; 

	// Inserts 20 at the end 
	v.emplace_back(20); 
	n = v.size(); 
	cout << "\nThe last element, after emplace_back is: " << v[n - 1]; 

	// erases the vector 
	v.clear(); 
	cout << "\nVector size after clear(): " << v.size(); 

	// two vector to perform swap 
	vector<int> v1, v2; 
	v1.push_back(1); 
	v1.push_back(2); 
	v2.push_back(3); 
	v2.push_back(4); 

	cout << "\n\nVector 1: "; 
	for (int i = 0; i < v1.size(); i++) 
		cout << v1[i] << " "; 

	cout << "\nVector 2: "; 
	for (int i = 0; i < v2.size(); i++) 
		cout << v2[i] << " "; 

	// Swaps v1 and v2 
	v1.swap(v2); 

	cout << "\nAfter Swap \nVector 1: "; 
	for (int i = 0; i < v1.size(); i++) 
		cout << v1[i] << " "; 

	cout << "\nVector 2: "; 
	for (int i = 0; i < v2.size(); i++) 
		cout << v2[i] << " "; 

	/***************************************************************/
	
	// to illustrate the element access in vector
	vector<int> g1; 
	cout <<"\n\nElements in vector g1 ";

	for (int i = 1; i <= 10; i++) 
	{
		g1.push_back(i * 10); 
	    cout <<g1.at(i-1) << " ";
	}	

	cout << "\nRef optr [g]    : g1[2]      = " << g1[2]; 

	cout << "\nat              : g1.at(4)   = " << g1.at(4); 

	cout << "\nfront()         : g1.front() = " << g1.front(); 

	cout << "\nback()          : g1.back()  = " << g1.back(); 

	// pointer to the first element 
	int* pos = g1.data(); 

	cout << "\nThe first element is " << *pos; 
	
	/***************************************************************/
 
	//to illustrate the capacity function in vector 

	vector<int> g2; 
  	cout <<"\n\nElements in vector g2: ";
	for (int i = 1; i <= 5; i++) 
	{
		g2.push_back(i);
		cout <<g2[i-1] << " ";
	}
	cout << "\nSize     : " << g2.size(); 
	cout << "\nCapacity : " << g2.capacity(); 
	cout << "\nMax_Size : " << g2.max_size(); 

	// resizes the vector size to 4 
	g2.resize(4); 

	// prints the vector size after resize() 
	cout << "\nSize aftr resize()    : " << g2.size(); 

	// checks if the vector is empty or not 
	if (g2.empty() == false) 
		cout << "\nVector is not empty"; 
	else
		cout << "\nVector is empty"; 

	// Shrinks the vector 
	g2.shrink_to_fit(); 
	cout << "\nVector elements after shrink_to_fit() are: "; 
	for (auto it = g2.begin(); it != g2.end(); it++) 
		cout << *it << " "; 

	// to illustrate the  iterators in vector 

	vector<int> g3; 

	for (int i = 1; i <= 5; i++) 
		g3.push_back(i); 

	cout << "\nOutput of begin and end      : "; 
	for (auto i = g3.begin(); i != g3.end(); ++i) 
		cout << *i << " "; 

	cout << "\nOutput of cbegin and cend    : "; 
	for (auto i = g3.cbegin(); i != g3.cend(); ++i) 
		cout << *i << " "; 

	cout << "\nOutput of rbegin and rend    : "; 
	for (auto ir = g3.rbegin(); ir != g3.rend(); ++ir) 
		cout << *ir << " "; 

	cout << "\nOutput of crbegin and crend  : "; 
	for (auto ir = g3.crbegin(); ir != g3.crend(); ++ir) 
		cout << *ir << " "; 
		
	return 0; 
} 
