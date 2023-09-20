#include <iostream>
#include <stack>
using namespace std;

// --------------------------------------------------------------
// --------------------------------------------------------------
// the 'Node' and 'SList' classes are fixed
// please do not modify them (except adding new member functions) 
// please add your implementation of the member functions 
// the 'Enumeration' function has been implemented for you 
// for the 'Insert' function, you probably want to dynamically allocate memory for a newly inserted node 
// --------------------------------------------------------------
// --------------------------------------------------------------

class Node { // "Node" class; each node is a student described by SID

public:

    int SID = 0;

    Node* ptr = NULL;
};


class SList { // singly linked list class; each node is an 'Node' object

public:

    SList() { head = NULL; }

    Node* GetList(); // return head pointer of the list 

    void Enumerate();  // print all elements in the list, from head to tail, separately by a single space ' ' 

    int Search(int key);  // search for 'key' in the list; 
                          // if found, return index of the node (starting from 0) 
                          // if not found, return -1  

    void Insert(int key);  // insert key at the end of the list 

    void Remove(int key); // if key is in the list, remove it 
                            // otherwise, do nothing   

    void Reverse(); // reverse the list (tip: you can use stack)

    // add any other public member functions as you like 
    // ......
    // ...... 

private:

    Node* head;  // head pointer of the list 
};

// Returns head pointer of the list
Node* SList::GetList()
{
    return head;
}

void SList::Enumerate() { // enumeration function, implemented for you 

    Node* temp = head;

    while (temp != NULL) {

        cout << temp->SID << ' ';
        temp = temp->ptr;
    }
};

// Searches for the key in the list. If found returns the index of the Node
// starting from 0, otherwise returns -1.
int SList::Search(int key)
{
    int index = 0; // Initialize index variable to 0
    Node* temp = head; // Assign head to a temporary variable

    while (temp->ptr != NULL) // Traverse the list
    {
        if (temp->SID == key)// If found return the index
        {
            return index;
        }

        temp = temp->ptr;
        ++index;
    }

    return -1;
}

// Inserts the key at the end of the list
void SList::Insert(int key)
{
    Node* insert = new Node(); // Creates new Node
    insert->SID = key; // Assigns key to the SID of insert Node

    if (head == NULL) // If the List is empty
    {
        head = insert;
    }
    else
    {
    Node* temp = head; // Assign head to a temporary variable
    
    while (temp->ptr != NULL) // Traverses the list until before the last Node
    {
        temp = temp->ptr; 
    }

    temp->ptr = insert; // Assigns the new Node to the last Node
    }
}

// If the key is in the list, it will be removed
void SList::Remove(int key)
{
    while (head->SID == key) // If the List is empty
    {
        head = head->ptr;
    }

    Node* temp = head; // Assign head to a temporary variable
    Node* prev = temp; // Declare a variable to hold the previous Node

    while (temp != NULL) // Traverse the list
    {
        if (temp->SID == key) // If found return the index
        {
            prev->ptr = temp->ptr; 
        }
        else // If not found assign the temp to the previous variable
        {
            prev = temp;
        }
            temp = temp->ptr;
    }
}

// Reverses the list
void SList::Reverse()
{
    stack<Node*> s; // Declare an empty stack variable
    Node* temp = head; // Assign head to a temporary variable

    while (temp->ptr != NULL) // Traverse the list until before the last Node
    {                         // and push each Node into the stack
        s.push(temp);
        temp = temp->ptr;
    }
    
    head = temp; // Assign the previous last Node to head

    while (!s.empty()) // Traverse the stack until it is empty
    {
        temp->ptr = s.top(); // Assign the next Node to the top Node in the stack
        s.pop(); // Remove the top Node
        temp = temp->ptr; // Assign temp with the next Node
    }

    temp->ptr = NULL; // Assign the ptr of the new last Node to NULL
}

// --------------------------------------------------------------
// --------------------------------------------------------------
// the following merge function is only for your reference 
// you don't have to use recursion
// --------------------------------------------------------------
// --------------------------------------------------------------

// This method will merge the lists together and return the head of the
// newly merged and sorted list.
Node* MergeLists(Node* ptr1, Node* ptr2)
{
    Node* head;

    // Base Cases
    if (ptr1 == NULL) // When ptr1's list contains a single Node
    {
        return ptr2;
    }
    else if (ptr2 == NULL) // When ptr2's list contains a single Node
    {
        return ptr1;
    }

    if (ptr1->SID <= ptr2->SID)
    {
        // ptr1 will be assigned to head
        head = ptr1; 
        // MergeLists will be called recursively until it reaches the base case
        // and will be assigned to the list in order
        head->ptr = MergeLists(ptr1->ptr, ptr2); 
    }
    else
    {
        // ptr2 will be assigned to head
        head = ptr2;
        // MergeLists will be called recursively until it reaches the base case
        // and will be assigned to the list in order
        head->ptr = MergeLists(ptr1, ptr2->ptr);
    }

    return head;
}

Node* MergeSort(Node* ptr) {  // merge sort (recursive implementation)
                              // input head pointer of a singly linked list
                              // output head pointer of the sorted linked list 


    // Step 1. split the list into two sub-lists 
    // ..........
    // ..........
    // assume ptr1 is head of 1st sublist 
    // assume ptr2 is head of 2nd sublit 
    
    // Base Case: Length of 0 or 1
    if ((ptr == NULL) || (ptr->ptr == NULL)) 
    {
        return ptr;
    }

    Node* ptr1 = ptr; // ptr1 will act as the slow pointer
    Node* ptr2 = ptr->ptr; // ptr2 will act as the fast pointer

    // This while loop will implement our fast slow strategy to obtain
    // our two sublists.
    while (ptr2 != NULL)
    {
        ptr2 = ptr2->ptr; // ptr2 will be changed to the next pointer
        if (ptr2 != NULL) // If ptr2 is not empty
        {
            ptr1 = ptr1->ptr; // ptr1 will be changed to the next pointer
            ptr2 = ptr2->ptr; // ptr2 will be changed again
        }
    }

    ptr2 = ptr1->ptr; // Assign the next pointer from ptr1 to ptr2 which will be 
                      // the head of the second sublist
    ptr1->ptr = NULL; // This will split off the two lists from each other
    ptr1 = ptr; // Assign the ptr to ptr1 again to make it the head of the 
                // first sublist
    

    // Step 2. sort each sublist by calling the MergeSort 
    // ptr1 = MergeSort(ptr1);
    // ptr2 = MergeSort(ptr2);

    ptr1 = MergeSort(ptr1); // This will recursively call MergeSort until the lists
    ptr2 = MergeSort(ptr2); // contain single Nodes


    // Step 3. merge the sorted sublists into a sorted list  
    // ......
    // ......
    // you can define a function for that, or implement it directly here 

    Node* head = MergeLists(ptr1, ptr2); // Assign head with the head pointer returned from
                                         // merging the lists.


    // step 4. return the head pointer of the sorted list 
    // Node* head = ......;
    // return head;

    return head;
}


int main()
{
    SList x;

    int operationChoice, Key2Search, Key2Remove, Key2Insert;

    int InputKey;
    int i = 0, y = 0;
    while (i < 10) {
        cin >> InputKey;
        x.Insert(InputKey);
        i++;
    }

    cin >> operationChoice;

    if (operationChoice == 1)
    {
        Node* head = x.GetList();
        cout << head->SID;
    }
    else if (operationChoice == 2)
    {
        cin >> Key2Search;
        y = x.Search(Key2Search);
        cout << y;
    }
    else if (operationChoice == 3)
    {
        cin >> Key2Insert;
        x.Insert(Key2Insert);
        x.Enumerate();
    }
    else if (operationChoice == 4)
    {
        cin >> Key2Remove;
        x.Remove(Key2Remove);
        x.Enumerate();
    }
    else if (operationChoice == 5)
    {
        x.Reverse();
        x.Enumerate();
    }
    else if (operationChoice == 6)
    {
        Node* sorted_list = MergeSort(x.GetList());

        while (sorted_list != NULL) {

            cout << sorted_list->SID << ' ';

            sorted_list = sorted_list->ptr;
        }
    }
    else
    {
        cout << "Enter a valid choice";
    }
    return 0;

}

