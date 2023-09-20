// Practice1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // standard input output stream

using namespace std; // so you don't have to keep putting the std

int main() // any C++ starts with a main function
{
	//int x = 3, y = 1, z; // declare x, y, and z as an integer

	//const int weeksize = 7; // it's like a final variable can't be changed

	//int x, y, z;

	///*std::*/cin >> x >> y >> z; // waits for input

	///*std::*/cout << x << '\n' << y << '\n' << z << std::endl;

	//z = x + y;

	//z = x * y; 

	//z = y + ++x;

	//std::cout << (x > y); // prints out 1 for true
	//std::cout << (x < y); // prints out 0 for false
	//std::cout << (x == y); // prints out 0 for false


	//float y = 3.14;

	//char z = 's';

	//x = 7.53; // becomes 7

	int x = 3, y, z;

	// x = x*3 until x > 20
	while (x < 20)
	{
		x = x * 3;

		cout << x << endl;
	} 

	// x = x * 3 for 5 times assign result to y
	/*for (int i = 0; i < 5; ++i)
	{
		x = x * 3;
	}

	y = x;*/

	//if x > 3; x++ assign to y
	/*if (x > 3)
	{
		x++;

		y = x;
	}
	else
	{
		z = x;
	}*/

	return 0;

	//x = 3;

	//y = 5;

	//z = 14;
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
