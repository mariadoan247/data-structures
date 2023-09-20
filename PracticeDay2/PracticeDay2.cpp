// PracticeDay2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// class

class Student
{
public:

    string Name;

    void setID(int a);

    int getID();

    Student();

private: 
    
    int SID;
};

void Student::setID(int a)
{
    SID = a;
}

int Student::getID()
{
    return SID;
}

//Constructor
Student::Student()
{
    SID = 0;

    Name = "Jim";
}

// This is a function. Must put before main or you could declare it in main.
int Sum(int a, int b)
{
    int result;

    result = a + b;

    return result;
}

void PrintError()
{
    cout << "Error!!" << endl;
}


int Increment(int a)
{
    // wouldn't actually increment the value because it creates a copy not the original
    // so you would have to do it by passing the value
    a = a + 1;

    int x = 7; // local variables will have more precedence over the main variables

    return a;
}

// Uses the same address as the original
void Increment(int* a)
{
    *a = *a + 1;
}

// This is the main function. Must always return int
int main()
{

    for (int i = 0; i < 3; i++)
    {
        int *temp;

        temp = new int; // do this to make the address different;

        cout << temp << endl;
    }

    //Student x, y, z;

    //x.setID(001);

    //x.Name = "James";

    //cout << x.getID();

    /*int x;

    x = 3;

    int* ptr;

    ptr = &x;

    Increment(ptr);

    cout << x << endl;

    *ptr = *ptr + 1;

    cout << *ptr << endl;

    cout << x << endl;*/

    // declare like this if function was put after the main function
    // int Sum(int a, int b);

    // int x = 3, y = 5, z;


    // z = Sum(x, y);

   //  PrintError();

   // x = Increment(x);

   // cout << x << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
