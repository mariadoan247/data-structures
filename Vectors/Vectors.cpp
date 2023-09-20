// Vectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <vector>

using namespace std;

/*Class Vector // what the vector class would look like
{
public:

	insert();

	push_back();

private:

	int* p;

}*/

/*int* push_back(int key)
{
	int new_p[11];

	new_p[0:9] = p[0:9];

	new_p[10] = key;

	return new_p;
}*/

void Increment(vector<int> &x)
{
	x.at(0)++;
}
/*|____|
  |____|2
  |____|1
  |____|0*/
int main()
{
	int x[2] = {3, 4};

	vector<int> y;

	y.push_back(3);

	y.push_back(5);

	// cout << y.at(1);
	// Increment(y);

	return 0;

	/*y.push_back(7);

	y.push_back(11);

	// y.resize(2);

	y.insert(y.begin() + 2, 8); // inserts 8 at position 2

	y.insert(y.begin(), 13); // inserts 13 at position 0

	y.erase(y.begin()); // erases the first element

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
