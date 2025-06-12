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

    int getRollnum() 
    {
        return rollno;
    }
};

int main() 
{
    Student s1;
    s1.setRollnum(101); // set roll number
    cout << "Roll Number: " << s1.getRollnum() << endl; // get and display it
    return 0;
}
/* Expected output
Roll Number: 101
*/
