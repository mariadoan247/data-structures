// StackPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	
	stack<int> x;

	x.push(5); // The time complexity is not dependent on the input
			   // It has a time complexity of O(1)
			   // Meaning a constant time

	x.push(11);
	
	x.push(7);

	cout << x.size();

	x.pop(); // Only removes top element not return

	x.pop();

	// x.pop();

	vector<int> y;

	y.push_back(5);

	y.push_back(11);

	y.push_back(7);

	// y.pop_back();
	y.erase(y.begin()); //erases the bottom instead of the top

	y.pop_back();

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
