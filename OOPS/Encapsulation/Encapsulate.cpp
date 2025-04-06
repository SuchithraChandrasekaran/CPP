/*
Encapsulation
Definition: Wrapping data (variables) and methods (functions) into a single unit, i.e., a class.
*/
class Student 
{
    private:
    int rollno; // hidden from outside

    public://member functions alone are visible outside the class
    void setRollnum(int num) 
    {
        rollno = num;
    }

    int getSpeed() 
    {
        return rollno;
    }
};
