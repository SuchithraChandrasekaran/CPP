# C++11 (formerly known as C++03) 

#### Introduced major enhancements to the C++ language, 
#### Making it more expressive, efficient, and easier to use. 
#### Important new features in C++11:

## 1. Auto Keyword
Automatically deduces the type of a variable from its initializer.

- auto x = 42;         // int
- auto name = "Suchithra"; // const char*

## 2. Range-based for Loop
Simplifies iteration over containers like arrays, vectors, etc.

    std::vector<int> v = {1, 2, 3};
    for (auto val : v) 
    {
      std::cout << val << "\n";
    }
## 3. Lambda Expressions
Enables writing inline anonymous functions.

    auto add = [](int a, int b) { return a + b; };
    std::cout << add(5, 3); // Outputs 8

## 4. nullptr
Introduces a type-safe null pointer constant, replacing NULL.

    int* ptr = nullptr;
### The difference between nullptr, and NULL

    nullptr (C++11 and beyond)
    i)Type-safe null pointer constant

    ii)Has a dedicated type: std::nullptr_t

    iii)No ambiguity in function overloading

    iv)Preferred in modern C++

    int* ptr = nullptr;  // Type-safe

### NULL (Pre-C++11, C-style)
    i)Typically defined as #define NULL 0

    ii)It's just an integer constant, not a pointer!

    iii)Can lead to ambiguity in function calls

    int* ptr = NULL;  // Not type-safe

### Function Overload Ambiguity with NULL

    void func(int);       
    void func(int*);

    func(NULL);    // Ambiguous: is it int or int*?

    func(nullptr); // Clearly calls func(int*)

## 5. Smart Pointers (std::unique_ptr, std::shared_ptr)
Improves memory management and avoids memory leaks.

    #include <memory>
    std::unique_ptr<int> p(new int(5));

## 6. Move Semantics and Rvalue References
Optimizes performance by avoiding unnecessary deep copies.

    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = std::move(v1); // Moves instead of copying

## 7. Thread Support
Built-in multithreading with thread, mutex, header files.

    #include <thread>
    void func() { std::cout << "Thread!\n"; }
    std::thread t(func);
    t.join();

## 8. decltype Keyword
Deduce the type of an expression.

    int x = 0;
    decltype(x) y = 10; // y is also int
