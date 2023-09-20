#include <iostream>
#include <vector>
using namespace std;

// In this project, implement a minimum heap using vector
//
// Implement two functions 
// -- insert(int key): insert a new key into the heap 
// -- remove(): remove the root key from the heap 
// 
// In the main function, we will first input 10 keys into the heap 
// Then, we will enumarate them from the vector 
// The enumeration function has been implemented for you 
// 

class heap {

public:
    void enumerate(); // enumerate all elements in the heap 

    void insert(int key); // insert a new key into the heap vector 

    void remove(); // remove root key from the heap 

    void createHeap(int i); // recreates a minheap

private:
    vector<int> x;
};

int parent(int i) // Returns the index of the parent of i
{
    return (i - 1) / 2;
}

int leftChild(int i) // Returns the index of the leftChild of i
{
    return 2 * i + 1; 
}

int rightChild(int i) // Returns the index of the rightChild of i
{
    return 2 * i + 2;
}

// inserts the given key into the minheap vector
void heap::insert(int key)
{
    x.push_back(key);
    int i = x.size() - 1;
    
    // While i does not equal 0 and the parent of i is > key, the parent
    // and i will be swapped. This will be done until we create a minheap.
    while (i != 0 and x[parent(i)] > key)
    {
        swap(x[parent(i)], x[i]);
        i = parent(i);
    }
}

// This method will recreate the minheap
void heap::createHeap(int i)
{
    int min = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < x.size() and x[left] < x[right]) min = left;
    else if (right < x.size() and x[left] > x[right]) min = right;

    // We will go through createHeap recursively until min != i or
    // the left and right variables are no longer less than the size of x.
    if (min != i)
    {
        swap(x[min], x[i]);
        createHeap(min);
    }
}

// Removes the smallest element in the minheap
void heap::remove()
{
    // First swap the first and last element
    swap(x[0], x[x.size() - 1]);
    // Then pop out the last element
    x.pop_back();

    // Recreate the minheap
    createHeap(0);
}

void heap::enumerate() {

    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << ' ';
    }
}

int main()
{
    int tmp[10];

    for (int i = 0; i < 10; i++) {

        cin >> tmp[i];
    }

    heap x;
    for (int i = 0; i < 10; i++) {
        x.insert(tmp[i]);
    }

    int operationChoice;

    cin >> operationChoice;

    if (operationChoice == 1) { // enumerate key 

        x.enumerate();
    }
    else if (operationChoice == 2) { // remove the smallest element from the heap and update the heap
        x.remove();
        x.enumerate();
    }
    else {

        cout << "Enter a valid choice";
    }

    return 0;
}


