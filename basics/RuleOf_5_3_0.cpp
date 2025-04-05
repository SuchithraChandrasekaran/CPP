/* Implementation of Rule of 5
Destructor
Copy Constructor
Copy Assignment Operator
Move Constructor
Move Assignment Operator
*/
class ResourceManager 
{
private:
    int* data; // a single integer pointer

public:
    // Regular constructor
    ResourceManager(int value) 
    {
        data = new int(value);
    }
    
    // 1. Destructor
    ~ResourceManager() 
    {
        delete data;
    }
    
    // 2. Copy constructor
    ResourceManager(const ResourceManager& other) 
    {
        data = new int(*other.data);
    }
    
    // 3. Copy assignment operator
    ResourceManager& operator=(const ResourceManager& other) 
    {
        if (this != &other) 
        {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }
    
    // 4. Move constructor
    ResourceManager(ResourceManager&& other) 
    {
        data = other.data;
        other.data = nullptr;
    }
    
    // 5. Move assignment operator
    ResourceManager& operator=(ResourceManager&& other) 
   {
        if (this != &other) 
        {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
    
    // Optional: accessor method
    int getValue()  
    {
        return *data;
    }
    
    // Optional: modifier method
    void setValue(int value) 
    {
        *data = value;
    }
};
