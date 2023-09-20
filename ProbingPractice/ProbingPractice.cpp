// ProbingPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Stu
{
public:

    int SID = -1;

    float GPA = -1;
};

int hf(int key)
{
    return key / 5 - 1;
}

int main()
{
    Stu x[3];
    Stu HashTable[5];
    int Counter[5] = { 0, 0, 0, 0, 0 };

    Stu x[6];

    x[0].SID = 10;
    x[1].SID = 15;
    x[2].SID = 12;
    x[3].SID = 20;
    x[4].SID = 14;
    x[5].SID = 18;

    x[0].GPA = 3.1;
    x[1].GPA = 3.4;
    x[2].GPA = 3.8;
    x[3].GPA = 3.5;
    x[4].GPA = 3.0;
    x[5].GPA = 3.2;


    int new_SID, temp, size_Table = 5;

    for (int i = 0; i < 6; ++i)
    {
        new_SID = hf(x[i].SID);

        cout << Counter[0] << HashTable[0].GPA;

        if (HashTable[new_SID].SID == -1) // no collision
        {
            HashTable[new_SID] = x[i];

            Counter[new_SID]++;
        }
        else
        {
            temp = (new_SID + 1) % size_Table;

            while (HashTable[temp].SID != -1 && temp != new_SID)
            {
                temp = (temp + 1) % size_Table;
            }

            if (temp != new_SID)
            {
                cout << "no free spot";
            }
            else
            {
                HashTable[temp] = x[i];

                Counter[new_SID]++;
            }
        }
    }
    
    return 0;
}
