#include <iostream>
#include <stack>
#include <queue>

using namespace std;


// the node class is used to creat list representation 
class Node {

public:

    int SID = -1;

    Node* next = NULL;
};


// here is the graph class 
// assume we work on an undirected graph of 6 nodes (fix size) 
// it has a matrix representation and a list representation 
// ask students to input matrix representation
// and design a function to convert that to a list representation 
class Graph {

public:

    Graph();

    void SetMatrix(int a, int b); // set Matrix[a][b] = Matrix[b][a] = 1
                                  // a and b must be in [0,5] 
                                  // already implemented

    void DeleteMatrix();  // reset matrix to zero
                          // already implemented

    void Convert(); // convert matrix representation to list
                    // in the list, make sure nodes are sorted in an ascending order
                    // @TODO: you need to implement this method

    void EnumerateList(); // enumerate all nodes in the list
                          // already implemented

    int* DFS(int idx);  // depth first search based on list representation
                        // idx represents the first node to visit
                        // whenever there is a tie, choose the smallest node to visit first
                        // return a pointer to an array of 6 nodes based on the order they are visited
                        // for example, if DFS visits 3, 5, 2, 0, 1, 4; then the array should have
                        // x[0]=3, x[1]=5, x[2]=2, x[3]=0, x[4]=1, x[5]=4
                        // @TODO: you need to implement this method

private:

    int Matrix[6][6];

    Node* List[6];

};


// Converts the matrix representation to a list representation. In the list, the nodes are sorted in
// ascending order.
void Graph::Convert()
{
    for (int i = 0; i < 6; ++i) // The outer loop will keep track of the rows of the matrix
    {
        Node* parent = new Node; // Keeps track of the parent node
        Node* temp = new Node; // The temp node will be modified instead of List[i]
        List[i] = temp; // temp will be assigned to List[i]
        for (int j = 0; j < 6; ++j) // This nested for loop will go through the columns of the matrix
        {
            if (Matrix[i][j] == 1) // If the slot is marked then we will enter it as an adjacent node
            {
                temp->SID = j; // temps SID will be assigned as the column number
                temp->next = new Node; // initialize the next node
                parent = temp; // assign parent as temp
                temp = temp->next; // assign temp as its next node
            }
        }
        parent->next = NULL; // this will make sure there are no -1s at the end of the chains
    }
}

// This method performs depth first search based on list representation. The idx represents the first node to 
// visit. Whenver there is a tie, the smallest node will be visited first. It will return a pointer to an 
// array of 6 nodes based on the order they are visited. For example, if DFS visits 3, 5, 2, 0, 1, 4; then 
// the array should have x[0]=3, x[1]=5, x[2]=2, x[3]=0, x[4]=1, x[5]=4.
int* Graph::DFS(int idx)
{
    static int dfs[6]; // This is the array that will be returned with the visited nodes in oder
    static int marked[6]; // this array will keep track of what arrays have been visited.
    int i = 0; // This will hold the index of the visited nodes
    int prev = 0; // These prev variables will keep track of the previous nodes that were visited.
    int prev0 = 0; // This is needed because if we reach a dead end with one of the nodes we have to
    int prev1 = 0; // go back to the previous node.
    int prev2 = 0;
    int tempidx = idx; // The tempidx will be assigned with idx, so it will be modified instead of idx
    Node* temp = List[idx]; // temp will be assigned with List[idx], so temp will be modified instead
    dfs[i] = idx; // We insert the first vistied node into dfs
    marked[idx] = 1; // We mark that node in the marked array

    while (i < 5) // We will go through this while loop until we reach the last index of dfs. This means we
    {             // visited all the nodes.
        int j = temp->SID; // j will be assigned with the SID of temp
        if (marked[j] == 0)
        {
            prev = prev0; // We update the prev variables in these first four lines.
            prev0 = prev1;
            prev1 = prev2;
            prev2 = tempidx;
            ++i; // We will increment i to insert j at the correct index.
            dfs[i] = j; // we insert j into the dfs array since it has now been visited
            marked[j] = 1; // we mark j as visited
            tempidx = j; // assign tempidx as j
            temp = List[tempidx]; // assign temp as List[tempidx] to get to the next Node
        }
        else if (temp->next != NULL) // If we have already visited the node then we will assign temp
        {                            // with its next node.
            temp = temp->next;
        }
        else // If we reach a dead end
        {
            tempidx = prev2; // We assign tempidx with prev2
            prev2 = prev1; // In the next three lines we will be reassigning the prev variables
            prev1 = prev0;
            prev0 = prev;
            temp = List[tempidx]; // assign temp with List[tempidx] to get to the previous visited node.
        }
    }
    return dfs; // return the ptr to the dfs array which contains the visited nodes in order.
}


// enumerate nodes in a list
void Graph::EnumerateList() {

    Node* temp;

    for (int i = 0; i < 6; i++) {

        cout << i << " -> ";

        if (List[i] != NULL) {

            temp = List[i];

            cout << temp->SID;

            while (temp->next != NULL) {

                temp = temp->next;

                cout << " -> " << temp->SID << ' ';
            }
            cout << endl;
        }
    }
}


// SetMatrix Function
void Graph::SetMatrix(int a, int b) {

    Matrix[a][b] = 1;

    Matrix[b][a] = 1;
}


// DeleteMatrix Function
void Graph::DeleteMatrix() {

    for (int i = 0; i < 6; i++) {

        for (int j = 0; j < 6; j++) {

            Matrix[i][j] = 0;
        }
    }
}


// constructor
Graph::Graph() {

    for (int i = 0; i < 6; i++) {

        for (int j = 0; j < 6; j++) {

            Matrix[i][j] = 0;
        }

        List[i] = NULL;
    }
}



int main()
{

    Graph graph;

    int a, b; // the values of a and b are between 0 and 5
    int* visit;

    // always input 8 edges
    for (int i = 0; i < 8; i++) {

        cin >> a >> b;

        graph.SetMatrix(a, b);
    }

    int idx;
    cin >> idx;

    // always immediately convert matrix into list
    cout << "Adjacency List" << endl;
    graph.Convert();
    graph.DeleteMatrix();
    graph.EnumerateList();

    cout << "DFS" << endl;
    visit = graph.DFS(idx);

    for (int i = 0; i < 6; i++) {

        cout << visit[i] << ' ';
    }

    return 0;
}

