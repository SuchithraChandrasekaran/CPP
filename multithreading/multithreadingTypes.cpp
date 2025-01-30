#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
std::atomic<int> counter(0);

// Function to be run by a thread
void printMessage(const std::string &msg) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Thread Message: " << msg << std::endl;
}

// Function for synchronization using condition_variable
void workerThread() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });
    std::cout << "Worker Thread Executing\n";
}

// Function for atomic operation
void atomicIncrement() {
    for (int i = 0; i < 1000; i++) {
        counter++;
    }
}

class MyClass {
public:
    void classFunction(int x) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Class Member Function, Value: " << x << std::endl;
    }
};

int main() {
    // 1. Basic Thread
    std::thread t1(printMessage, "Hello from thread!");

    // 2. Lambda Function Thread
    std::thread t2([] {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Lambda function running in thread\n";
    });

    // 3. Thread using Class Member Function
    MyClass obj;
    std::thread t3(&MyClass::classFunction, &obj, 42);

    // 4. Using Condition Variable
    std::thread t4(workerThread);
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();

    // 5. Atomic Variable Usage
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.emplace_back(atomicIncrement);
    }

    // Joining Threads
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    for (auto &t : threads) {
        t.join();
    }

    std::cout << "Final Counter Value: " << counter << std::endl;
    return 0;
}

