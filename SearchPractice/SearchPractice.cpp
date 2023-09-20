// SearchPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Stu
{
public:

    int SID;

    float GPA;

    int MAJ;
};

int hashfunc(int old_ID)
{
   return old_ID / 5 - 1; //This would cause a collision
    //return old_ID / 3 - 1;
}

int main()
{
    Stu x[4];

    x[0].SID = 5;
    x[1].SID = 10;
    x[2].SID = 15;
    x[3].SID = 12;

    x[0].GPA = 3.5;
    x[1].GPA = 3.2;
    x[2].GPA = 3.7;
    x[3].GPA = 3.0;

    // 1 for CS and 0 for not CS
    x[0].MAJ = 1;
    x[1].MAJ = 0;
    x[2].MAJ = 1;

    // You also have to change size when hashing
    int size = 5;

    vector<vector<Stu>> y(size); // You can't specify the size of the array dynamically, but you can for vector
    //vector<Stu *> y(size) // This is for linkedList implementation

    // Now implement hf
    //y.at(hashfunc(x[0].SID)) = &x[0]; // This is for linkedList implementation
    //y.at(hashfunc(x[3].SID)); // To insert the element into an existing list you have to traverse the list
    y.at(hashfunc(x[0].SID)).push_back(x[0]);
    y.at(hashfunc(x[1].SID)).push_back(x[1]);
    y.at(hashfunc(x[2].SID)).push_back(x[2]);
    y.at(hashfunc(x[3].SID)).push_back(x[3]);

    int key = 10;

    cout << y.at(hashfunc(key)).at(0).GPA << endl;

    return 0;
}
