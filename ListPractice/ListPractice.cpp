// ListPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
// #include <vector>

using namespace std;

class Node
{

public:

    int data;

    //Node* ptr; // This ptr should point to a Node object

    //Doubly LinkedLIst
    Node* ptr = NULL;

    //Node* ptr_next = NULL;
};

int main()
{

    Node A, B, C;

    //reversing
    stack<Node> s;

    // instead of doing this manually you should try to use a different method
    A.data = 7;
    B.data = 5;
    C.data = 11;

    A.ptr = &B; // & gets the address
    B.ptr = &C;
    C.ptr = NULL; // null indicates the end of the list

   /* // For doubly LL
    A.ptr_prev = NULL;
    B.ptr_prev = &A;
    C.ptr_prev = &B;*/

    Node* head = &A;
    //Node* head2 = &C; // For Doubly LL

    //Node* temp = head2; // We need to use a temp var because we don't want to lose the head

   // Node D;

    //D.data = 3;

    // here is where application
    
    // How to reverse a LL
    s.push(*head); //push

    head = head->ptr; //update head pointer to B

    s.push(*head); //push, stack size is 2

    head = head->ptr; //update head pointing to C

    s.push(*head); //push stack size is 3

    head = head->ptr; //update head pointer to NULL

    head = &s.top(); //Update head to C

    s.pop(); //pop C, size now 2

    head->ptr = &s.top(); //Update next pointer to B
    
    s.pop(); //pop B, size now 1

    head->ptr->ptr = &s.top(); //Update next next pointer to A

    s.pop(); //pop A, nothing left


    /*//Delete the top
    head1 = head1->ptr_next;

    head1->ptr_prev->ptr_next = NULL;

    head1->ptr_prev = NULL;*/

    /*//Inserting D into doubly LL
    head1->ptr_prev = &D;

    D.ptr_next = head1;

    head1 = &D; */

   // D.ptr = head; // Must assign head to D.ptr first or you'll get an infinite loop
                  // This is because if you assign &D to head and then assign head to D.ptr
   // head = &D;    // it would just keep printing D's data

   // D.ptr = temp->ptr; // Insertion in the middle

    //temp->ptr = &D;

 //   temp->ptr->ptr->ptr = &D; //Insertion at the end

   // D.ptr = NULL;

   //head = head->ptr;

    Node* temp = head;

    /*head->ptr = head->ptr->ptr;

    Node* temp = head;*/

    /*head->ptr->ptr = NULL; // Delete tail

    Node* temp = head;*/

    //int counter = 1;

    while (temp != NULL) // traverse the list
    {
        cout << temp->data << endl;

        temp = temp->ptr; 
    }

    return 0;

    /*
    inefficient method use linked list instead
    
    int x[3] = {5, 11, 7};

    cout << &x[0] << endl;

    cout << &x[1] << endl;

    cout << &x[2] << endl;

    vector<int> y;

    y.push_back(7);

    cout << &y.at(0) << endl;

    y.push_back(5);

    cout << &y.at(0) << endl;

    y.push_back(11);

    cout << &y.at(0) << endl;

    return 0;*/
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
