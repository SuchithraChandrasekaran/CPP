# Copy constructor

A special constructor that creates a new object as a copy of an existing object.

Example:

      MyClass(const MyClass& obj);

      MyClass obj1(10);
      MyClass obj2 = obj1;   // <--- Copy constructor is called here!

#### Why do we need & (reference) in copy constructors?

      MyClass(const MyClass& obj);  // Valid
      
      MyClass(const MyClass obj);   // Invalid (leads to infinite recursion)

#### What happens if you remove &?

      MyClass(MyClass obj);  // Pass by value

###### Here’s the problem:

- When you pass obj by value, it means C++ has to copy it.

- But to copy it, it needs to call the copy constructor again...

- That copy also needs a copy...

- Infinite recursion ➝ Stack overflow! 

The compiler keeps calling the copy constructor again and again,

because to copy obj, it needs to call the copy constructor —

and to do that, it needs to copy obj

#### Why is const optional?

      MyClass(MyClass& obj);         // Valid but risky
      MyClass(const MyClass& obj);   // Recommended

- const is not required but highly recommended.

- It prevents accidental modification of the object being copied.

- Without const, this won’t work:

      MyClass a;
      const MyClass b(10);  // Const object
      MyClass c = b;   // ERROR: Cannot pass const object to non-const reference

### Conclusion:

- & is mandatory to avoid infinite recursion.

- const is recommended to allow copying const objects and to protect source data.


    
