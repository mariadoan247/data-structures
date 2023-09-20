#include <iostream>

using namespace std;

class Array
{
public:
    // please implement the following six member functions     
    void Set(int key, int index);  // assign "key" to "x[index]"    
    int* Get();                    // return pointer to a copy of array x                                    
                                   // must be a copy, not x itself     
    void Sort_Bubble();            // bubble sort array x    
    void Sort_Insertion();         // insertion sort array x                         
    int Search_Linear(int key);    // linear search of "key" in the array                                   
                                   // if success, return index of key                                    
                                   // if fail, return -1     
    int Search_Binary(int key);    // binary search of "key" in the array                                   
                                   // if success, return index of key                                    
                                   // if fail, return -1 
private:
    int x[10];                     // array size is fixed to 10 

    int size = sizeof(x) / sizeof(x[0]); // This will be added to be used 
                                         // throughout the code.
                                         // I did sizeof(x) / sizeof(x[0]) because sizeof() 
                                         // counts the total amount of bits in an array 
                                         // and because each element can take up more than one 
                                         // bit of space I would divide it by the amount 
                                         // of bits an element takes up
};

// This method will assign "key" to "x[index]"
void Array::Set(int key, int index)
{
    x[index] = key;
}

// Worked with Rebekah Lee. The method returns pointer to a copy of array x
int* Array::Get()
{
    int* copy = new int[size]; // Creates a pointer of an array the same size as x

    for (int i = 0; i < size; ++i)
    {
        copy[i] = x[i]; // Assigns the corresponding elements of x to copy
    }

    return copy;
}

// This method sorts the array using the bubble sort strategy
void Array::Sort_Bubble()
{
    int swapped = 1; // Initialize the swap variable to 1 to first enter the loop
    while (swapped != 0)
    {
        swapped = 0; // I assign 0 to swap so if all the elements are sorted it 
                     // will exit the while loop
        for (int i = 0; i < size - 1; ++i)
        {
            if (x[i] > x[i + 1])
            {
                swap(x[i], x[i + 1]); // When element at index i is greater
                                      // than the element ahead of it, the 
                                      // elements will be swapped.

                ++swapped; // This will increment swapped to indicate that the 
                           // array still needs to be checked to see if it's 
                           // already sorted
            }
        }
    }
}

// This method sorts the array using the insertion sort strategy
void Array::Sort_Insertion()
{
    // This first loop will keep track of the moving element
    for (int i = 1; i < size; ++i) 
    {
        int idx = i; // Assigns i to idx so i won't be directly changed
        for (int j = idx - 1; j >= 0; --j)
        {
            if (x[idx] < x[j])
            {
                swap(x[j], x[idx]); // Inserts the element at idx to the 
                                    // j index and the element at j
                                    // moves back

                --idx; // Decrements idx because the moving element was
                       // inserted at a lower index
            }
            else break; // Break the loop and go on to the next moving element
        }
    }
}

// This method searches for the given key using the linear search strategy
// If the search is a success it returns the index at which the key was found
// If the serach failed it returns -1
int Array::Search_Linear(int key)
{
    // This loop traverses through the array and compares each element to the key
    // and returns the index of the first occurance of the key in the array
    for (int i = 0; i < size; ++i)
    {
        if (x[i] == key)
        {
            return i;
        }
    }

    // Returns -1 if no index was returned
    return -1;
}

// This method searches for the given key using the binary serach strategy
// If the search is a success it returns the index at which the key was found
// If the serach failed it returns -1
// Worked with Rebekah Lee
int Array::Search_Binary(int key)
{
    int first = 0; // This assigns the first element index to 0
    int last = size - 1; // This assigns the last element index to size - 1 = 9

    // This loop will run when the first index is less than or equal to the last
    while (first <= last) 
    {
        int mid = (first + last) / 2; // This equation provides the middle index

        if (x[mid] == key) 
        {
            return mid; // If key is found at index mid, mid is returned
        }
        else if (key > x[mid])
        {
            first = ++mid; // If key is greater than element at mid,
                           // mid is incremented
        }
        else
        {
            last = --mid; // If key is less than element at mid,
                          // mid is decremented
        }
    }

    // If the key was not found, then -1 is returned
    return -1;
}

int main()
{
    Array A;
    int InputKey, operationChoice, SearchKey, IndexKey;
    int i = 0;
    while (i < 10)
    {
        cin >> InputKey;             // Reads the input numbers from the console        
        A.Set(InputKey, i);
        i++;
    }

    // if operationChoice = 1, directly output elements in A     
    // if operationChoice = 2, sort elements in A by bubble sort and output result     
    // if operationChoice = 3, sort elements in A by insertion sort and output result     
    // if operationChoice = 4, apply linear search to search for "SearchKey" in A    
    // if operationChoice = 5, first apply bubble sort on A, then apply binary search to search for "SearchKey" in A    
    cin >> operationChoice;
    int* temp;

    if (operationChoice == 1)
    {
        temp = A.Get();
        for (int i = 0; i < 10; i++)
        {
            cout << temp[i] << ' ';   // outputs are separated by tabs         
        }
    }
    else if (operationChoice == 2)
    {
        A.Sort_Bubble();
        temp = A.Get();
        for (int i = 0; i < 10; i++)
        {
            cout << temp[i] << ' ';   // outputs are separated by tabs         
        }
    }
    else if (operationChoice == 3)
    {
        A.Sort_Insertion();
        temp = A.Get();
        for (int i = 0; i < 10; i++)
        {
            cout << temp[i] << ' ';   // outputs are separated by tabs         
        }
    }
    else if (operationChoice == 4)
    {
        cin >> SearchKey;
        IndexKey = A.Search_Linear(SearchKey);
        cout << IndexKey << endl;
    }
    else if (operationChoice == 5)
    {
        cin >> SearchKey;
        A.Sort_Bubble();
        IndexKey = A.Search_Binary(SearchKey);
        cout << IndexKey << endl;
    }
    else
    {
        cout << "Enter a valid choice";
    }
    return 0;
}