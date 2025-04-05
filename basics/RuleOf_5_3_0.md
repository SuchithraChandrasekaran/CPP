# Rule of Five, Three, and Zero

## Overview
In C++, resource management is critical to ensure proper handling of dynamically allocated memory,
 file handles, or other system resources.

The **Rule of Five**, **Rule of Three**, and **Rule of Zero** are guidelines for writing classes that manage such resources effectively.

---

## Rule of Three

The **Rule of Three**  (C++03 and earlier) states:
If a class defines any of the following special member functions, it should explicitly define all three:
1. **Destructor**: Releases resources when an object is destroyed.

2. **Copy Constructor**: Creates a deep copy of an object during initialization.

3. **Copy Assignment Operator**: Assigns a deep copy to an existing object.


### Why Follow the Rule of Three?
Failure to define all three can lead to:
- Double deletion (two destructors freeing the same resource).
- Dangling pointers (invalid memory access).
- Undefined behavior.

---

## Rule of Five

The **Rule of Five**  (C++11 and later) expands on the Rule of Three by including two additional member functions introduced in C++11:

4. **Move Constructor**: Transfers ownership of resources from a temporary object.

5. **Move Assignment Operator**: Transfers ownership to an existing object.


### Why Follow the Rule of Five?
Move semantics optimize performance by avoiding unnecessary deep copies when working with temporary objects (rvalues). This is particularly useful in modern C++ applications.

---

## Rule of Zero

The **Rule of Zero** suggests avoiding manual resource management. 

These types handle resource management automatically.

### Benefits
- Simplifies code by eliminating the need for special member functions.
- Reduces bugs related to manual resource management.
- Encourages the use of RAII (Resource Acquisition Is Initialization).


---

## Comparison Table

| Feature               | Rule of Three                          | Rule of Five                           | Rule of Zero                         |
|-----------------------|----------------------------------------|----------------------------------------|--------------------------------------|
| **Scope**             | Pre-C++11                              | C++11 and later                        | Always                               |
| **Functions Defined** | Destructor, Copy Constructor, Copy Assignment | Adds Move Constructor and Move Assignment | None                                |
| **Purpose**           | Prevent resource leaks in copy scenarios | Optimize resource transfer + prevent leaks | Use RAII types to avoid manual management |

---

## Best Practices

1. Prefer the **Rule of Zero** whenever possible by using RAII-friendly types like `std::unique_ptr` or `std::vector`.
2. If manual resource management is necessary, follow the **Rule of Five** in modern C++ or the **Rule of Three** in legacy code.
3. Use `= default` or `= delete` to explicitly control special member functions when needed.
4. Ensure move operations are marked as `noexcept` for compatibility with standard library containers.






