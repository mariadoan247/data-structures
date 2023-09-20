// Practice Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void Increment(int *a)
{
    a[0]++;
    a[1]++;
}

class Student
{
public:

    int SID;
};

int main()
{
    // is 7 (key) in the array?
    // if so, where is 7
    int x[5] = {1, 3, 7, 9, 11};

    int flag = 0;

    for (int i = 0; i < 5; i++)
    {
        if (x[i] == 7)
        {
            cout << i << endl;

            flag = 1;

            break;
        }
    }

    if (flag != 1)
        cout << "7 not in the array";

   // Student y[2];

    //y[0].SID = 1;

 //   y[1].SID = 5;

   // int* ptr;

   // ptr = x;

   // cout << ptr[0] << endl << ptr[1];

   // Increment(x); 
 //   for (int i = 0; i < 4; ++i)
  //  {
  //      cin >> x[i];
  //  }

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
