#include <iostream>
using namespace std;

// let's design a Calculator class 
// it has two private operands 
// it has several public functions that operate on the operands 
// please complete the class definition 
class Calculator {

public:

    void setOPs(int a, int b); // define a void "setOPs" function that takes two integers 
           // as input and assign them to the two operands
           // order: first input goes to OP1, second input goes to OP2 

  

    void Swap1(); // define a void "Swap1" function that swaps the two operands 

   

    void Swap2(); // define another void "Swap2" function that swaps the operands 
           // Swap2 and Swap1 should have different designs (e.g. not just to change a name)

    int getOP1(); // define an int "getOP1" function that returns OP1; 

    int getOP2(); // define an int "getOP2" function that returns OP2; 

    int Sum(); // define a "Sum" function that returns the sum of the two operands 

    float Divide(); // define a "Divide" function that returns OP1 / OP2 (should be non-integer) 

private:

    int OP1, OP2; // two operands must be private 
    
};
    void Calculator::setOPs(int a, int b)
    {
        OP1 = a;
        OP2 = b;
    };

    void Calculator::Swap1()
    {
        int temp = OP1;
        OP1 = OP2;
        OP2 = temp;
    }

    void Calculator::Swap2()
    {
        int sum = Sum();
        OP1 = sum - OP1;
        OP2 = sum - OP2;
    }

    int Calculator::getOP1()
    {
        return OP1;
    }

    int Calculator::getOP2()
    {
        return OP2;
    }

    int Calculator::Sum()
    {
        return OP1 + OP2;
    }

    float Calculator::Divide()
    {
        return (float)OP1 / OP2;
    }


int main()
{
    Calculator x;

    // -----------------
    // Part I
    // -----------------

    // take two integer inputs from (by cin) and assign them to the two operands of x
    int a, b;

    cin >> a >> b;

    x.setOPs(a, b);
    
        
    

        // use if statement to swap the two operands to make sure OP1 has the smaller input 
        // example: if we initially have OP1=7 and OP2=5, we should swap them so that OP1=5
        // you should test both swap functions 
        // to test correctness, you should assign a larger value to OP1 initially 
    if (x.getOP1() > x.getOP2())
    {
        x.Swap1();
        }

        // print the two operands (to see if your swap functin is working properly) 
    cout << x.getOP1() << endl << x.getOP2() << endl;

        // calculate sum of the two operands 
        cout << "Sum = " << x.Sum() << endl;

    // calculate ratio of the two operands, result should be non-integer 
    cout << "Ratio = " << x.Divide() << endl;

    // -----------------
    // Part II
    // -----------------

    // now, reset your two operands to be OP1 = 1 and OP2 = 2 
    

        // use any loop statement to generate and print the Fibonacci sequence 
        // till the last number is bigger than 20. 
        // 
        // tip: the Fibonacci sequence is 1, 2, 3, 5, 8, 13, .... 
        // basically, the next number equals the sum of the previous two numbers
        // the first two numbers are always 1 and 2 

        cout << x.getOP1() << ',';
    cout << x.getOP2() << ',';

    while (x.Sum() <= 20) {

        cout << x.Sum() << ',';

        x.setOPs(x.getOP2(), x.Sum());

    }

    return 0;
}

