// HW3_CS2413.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
using namespace std;


class Student {

public:

    int SID = 0;

    float GPA = 0;

    Student* ptr = NULL;
};


class HashTable {

public:

    int Insert(Student* y); // insert a student x based on x.SID 
                            // return 1 if insertion is successful 
                            // return -1 if insertion fails (e.g. table full) 

    float Search(int key);  // search for a student with SID=key in the table 
                            // return GPA if student is found 
                            // return -1 if student is not found 

    int Remove(int key);    // remove a student with SID=key from the table 
                            // return 1 if student is found and removed 
                            // return -1 if student is not found 

    void Enumerate();       // enumerate all numbers, already implemented for you 

    int LinearProbing();    // Finds the next empty slot in the table

    void UpdateLink(int i); // Updates the link array

private:

    Student* x[5] = { NULL, NULL, NULL, NULL, NULL }; // array of student pointers 

    int link[5] = { -1,-1,-1,-1,-1 }; // link array, all initialized to -1

    int Counter[5] = { 0, 0, 0, 0, 0 };

    int hash(int key); // hash function, already implemented for you 

    int sizeX = 5; // size of array of student pointers
};

// Finds the next empty slot in the table
int HashTable::LinearProbing()
{
    int i = 0;

    while (i < sizeX && x[i] != NULL) // Traverses the array of student pointers
    {                                 // until an empty slot is found or i is
        ++i;                          // greater than the size of the array
    }

    return i;
}

// Updates the link array
void HashTable::UpdateLink(int index)
{
    int update = LinearProbing();

    if (link[index] == -1 && update < sizeX) // If the link is -1 and the update
    {                                        // is less than the size of the x
        link[index] = update;                // array, link is updated to the
    }                                        // next empty slot
}

// Inserts a student x based on x.SID. Returns 1 if successful and -1 if not
int HashTable::Insert(Student* y)
{
    int insert = hash(y->SID); // where y will be inserted in the array

    while (insert != -1)
    {
        if (x[insert] == NULL) // If the slot is empty the student is inserted
        {
            x[insert] = y;
            ++Counter[insert]; // Increment the counter at the insert index
            return 1;
        }
        else if (x[insert]->ptr == NULL) // IF the slot is empty, but its next
        {                                // is empty, the student is inserted
            x[insert]->ptr = y;
            ++Counter[insert]; // Increment the counter at the insert index
            return 1;
        }
        else
        {
            UpdateLink(insert); // Update link
            
            insert = link[insert]; // Assign insert with the link to the next slot
        }
    }

    return -1;
}

// Searches for a student with SID=key in the table. 
// Returns the GPA if found and -1 if not.
float HashTable::Search(int key)
{
    int search = hash(key); // Where the key could be located accoriding to the 
                            // the hash function
    while (search != -1)
    {
        if (x[search] != NULL) 
        {
            if (x[search]->SID == key) // If the first node at the slot contains 
            {                          // contains the key return the GPA
                return x[search]->GPA;
            }
            else if (x[search]->ptr != NULL && x[search]->ptr->SID == key)
            {
                return x[search]->ptr->GPA; // If the first node doesn't contain the 
            }                               // key and its pointer does, return the
        }                                   // next pointer.
        else
        {
            return -1; // If the slot is empty return -1
        }

        search = link[search]; // Update search to the next linked slot
    }

    return -1; // If not found at all return -1
}

// Removes a student with SID=key from the table.
// Returns 1 if successful and -1 if not
int HashTable::Remove(int key)
{
    int remove = hash(key); // Where the key could be located accoriding to the 
                            // the hash function
    while (remove != -1)
    {
        if (x[remove] != NULL)
        {
            if (x[remove]->SID == key) // If the first node at the slot contains 
            {                          // the key, remove the node and return 1
                x[remove] = x[remove]->ptr;
                --Counter[remove]; // Decrement the counter at the remove index
                return 1;
            }
            // If the first node doesn't contain the key and its pointer does, remove 
            // the next pointer and return 1
            else if (x[remove]->ptr != NULL && x[remove]->ptr->SID == key)
            {
                x[remove]->ptr = x[remove]->ptr->ptr;
                --Counter[remove]; // Decrement the counter at the remove index
                return 1; 
            }             
        }
        else              
        {
            return -1; // If the slot is empty return -1
        }

        remove = link[remove]; // Update remove to the next linked slot
    }

    return -1; // If not found at all return -1
}

int HashTable::hash(int key) {

    return key % 2;
}

void HashTable::Enumerate() {

    Student* temp;

    for (int i = 0; i < 5; i++) {

        temp = x[i];

        while (temp != NULL) {       // print the chain

            cout << temp->SID << ' ';

            temp = temp->ptr;
        }

        cout << link[i] << '\n';  // last number is the corresponding link value, then change line 
                                  // so, basically, each line for one chain + corresponding link 
    }

}

int main()
{
    HashTable table;

    for (int i = 0; i < 10; i++) {
        Student* x = new Student;
        cin >> x->SID >> x->GPA;
        x->ptr = NULL;
        table.Insert(x);
    }

    int operationChoice, SearchKey, RemoveKey;

    cin >> operationChoice >> SearchKey >> RemoveKey;

    if (operationChoice == 1) {

        table.Enumerate();
    }
    else if (operationChoice == 2) {

        cout << table.Search(SearchKey);
    }
    else if (operationChoice == 3) {

        table.Remove(RemoveKey);
        table.Enumerate();

    }
    else {

        cout << "Enter a valid choice";
    }

    return 0;
}