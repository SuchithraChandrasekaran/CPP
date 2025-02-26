/* A simple implementation of mutex and unique_lock 
multiple threads access shared resources, there is a possibility of a data race. 
To avoid this, use mutex and locks to synchronize shared resource access.*/

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
mutex mtx;
void print_block(int n, char c) 
{
        unique_lock<mutex> locker(mtx);
        for (int i = 0; i < n; ++i) 
        {
            cout <<i << " "  << c;
            cout << endl;
        }
}

int main() 
{
    thread t1(print_block, 20, '*');
    thread t2(print_block, 20, '$');

    t1.join();
    t2.join();

    return 0;
}
