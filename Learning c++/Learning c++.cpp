// Learning c++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

int addArray(int arr[], int arraySize)
{
	using namespace std;

	int sum = 0;

	for (int i = 0; i < arraySize; ++i)
	{
		sum += arr[i];
	}

	return sum;
}

void arrayAsParameter()
{
	using namespace std;

	int arry[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 8, 9 };
	int sum = addArray(arry, 10);

	cout << "Total is: " << sum << endl;
}

void fileIORead()
{
	using namespace std;

	char filename[50];
	ifstream stream;
	cin.getline(filename, 50);
	stream.open(filename);

	if (!stream.is_open())
	{
		exit(EXIT_FAILURE);
	}

	char word[50];

	while (stream.good())
	{
		stream >> word;
		cout << word << " ";		
	}

}

void fileIOWrite()
{
	using namespace std;

	ofstream file;							//variable to hold the file
	file.open("IOFile.txt");				//opens the specified file, if it doesn't exist, it will be created
	file << "Hello, world!";				//write to the file
	file.close();							//close the file
}

void Struct()
{											//https://stackoverflow.com/questions/92859/what-are-the-differences-between-struct-and-class-in-c
	using namespace std;

	struct helloWorld						//struct tag		
	{										//within the braces lie the members of the tag
		char hello[8];						//https://stackoverflow.com/questions/18674573/wrong-memory-allocation-new-char-n
		char world[7];
	};

	helloWorld hi = {
		"hello, ",
		"world!"
	};

	cout << hi.hello << hi.world << endl;

}

void switchStatement()
{
	using namespace std;

	int a = 3;

	switch (a)									//switch(variable)
	{
	case 1:										//case value:
		cout << "Number 1!" << endl;
		break;									//don't execute any more code in the switch statement

	case 2:
		cout << "Number 2!" << endl;
		break;

	case 3:
		cout << "Number 3!" << endl;
		break;

	default:									//if none of the above switches are fired, execute (like else)
		cout << "Number coming soon!" << endl;
	}
}

void orOperator()
{
	using namespace std;

	int a = 5;
	int b = 0;

	if (a > 0 || b < 0)					//if(condition || condition) 
	{									//if the first condition or the second condition is true, execute the code below
		cout << "yay" << endl;
	}
}

void ifCondition()
{
	using namespace std;

	int a = 5;

	if (a < 10)								//if (condition)  if the condition is true, the code in the body will execute
	{
		cout << "a is " << a << 
		" and is less than 10!" << endl;
	}	

	else if (a > 10)						//else if(condition) if the above statement is false and this statement true, execute code
	{
		cout << "a is " << a << 
		" and is greater than 10!" << endl;
	}

	else									//if the above conditions are all false, execute this						
	{
		cout << "a is equal to 10!"
			<< endl;
	}
}

void pointer()
{
	using namespace std;

	int a = 123;
	int* pointer = &a;					//datatype* variableName = address of variable

	cout << "pointer: " << pointer << endl;
}

void addressOperator()
{
	using namespace std;

	int a = 123;
	int b = 123;
	int c = a;

	cout << "a: " << &a << endl;		//&variable gives the address in memory of the variable
	cout << "b: " << &b << endl;
	cout << "c: " << &c << endl;		//should have the same address as a
}

void doWhileLoop()
{
	using namespace std;

	int i = 0;
										//do while loop is a while loop but runs the cody in the body once first and then checks the condition
	do									//beginning of do while loop
	{									
		cout << i << endl;
		i += 1;							//add one to variable i (increment i)
	} while (i < 10);					//while(condition);

}

void whileLoop()
{
	using namespace std;

	int i = 0;
	
	while (i < 10)						//while (condition)
	{
		cout << i << endl;
		i = i + 1;						//changing variable that the condition depends on
	}
}

void forLoop()
{
	using namespace std;
										//loop from 0 to 9
	for (int i = 0; i < 10; i = i + 1)	//for( int variable = value; condition; update variable)
	{									//if you want to include 10, use <= 
		cout << i << endl;
	}

}

void arrays()
{										//Method #1 of initializing an array
	int arrayOfNumbers[10];				//datatype variableName[arraySize]
	arrayOfNumbers[0] = 1;				//arrayVariable[arrayIndex] = value
	arrayOfNumbers[1] = 2;
	arrayOfNumbers[2] = 3;
	arrayOfNumbers[3] = 4;
	arrayOfNumbers[4] = 5;
	arrayOfNumbers[5] = 6;
	arrayOfNumbers[6] = 7;
	arrayOfNumbers[7] = 8;
	arrayOfNumbers[8] = 9;
	arrayOfNumbers[9] = 10;				//Array index starts at 0, therefore the last index is array length - 1

	using namespace std;
	cout << "Method 1: " <<			//Add value at index 5 of array with value at index 9 of array.
		arrayOfNumbers[5] +			
		arrayOfNumbers[9] << endl;

										//Method #2 of initializing an array
	int anotherArray[10] = { 1, 2,		//Constructs the array with values instead of doing so manually in method 1
		3, 4, 5, 6, 7, 8, 9, 10 };		

	cout << "Method 2: " << anotherArray[5] + anotherArray[9] << endl;
}

void input()
{
	using namespace std;

	cout << "Give me a number!" << endl;

	int inputNum;
	cin >> inputNum;					//stores data from input in inputNum variable

	cout << endl << "You gave me: " << inputNum << endl;
}

double fib_GR(long a, long b)				//ratio of two numbers, used by fib function to get golden ratio
{
	double A = (double)a;
	double B = (double)b;

	return (B / A);
}

void fib(long start, long end, int steps)			//fibonacci sequence function
{
	using namespace std;

	++steps;										//increment variable by 1
	int temp, i = 0;
	double ratio;

	while (++i < steps)
	{
		temp = end;
		end += start;
		start = temp;

		ratio = fib_GR(start, end);
		cout << start << "\t ratio: " << ratio << "\t step: " << i << endl;
	}
}

void variables()
{
	using namespace std;
	int aNumber = 1;					//creating an integer variable and storing 20 in it
	cout << endl << "I have a number: " << aNumber << endl;

	int bNumber = aNumber + 2;
	cout << endl << "My new number is: " << bNumber << endl;

	
}

void HelloWorld()
{
	using namespace std;				//use the standard stuffs
	cout << "Hello, world!";			//cout is standard out, << passes the data on the right
	cout << endl;						//endl = end line	
}

int main()								//function header
{										//function body start
										//functions being called should be above the function that is doing the calling
	HelloWorld();						//Hello world! - first program
	variables();						//variables - storing data in variables
	fib(1, 1, 10);						//fibonacci sequence - while loop, conditions & arithmetic
	input();							//keyboard input - user input
	arrays();							//initializing and calling values from ararys
	forLoop();							//simple for loop
	whileLoop();						//simple while loop
	doWhileLoop();						//simple do while loop
	addressOperator();					//operator to get address of variable in memory
	pointer();							//creating a pointer
	ifCondition();						//simple if condition
	orOperator();						//simple or condition
	switchStatement();					//switch statement
	Struct();				
	fileIOWrite();						//basic file write
	fileIORead();						//basic file read
	arrayAsParameter();					//how to pass an array into a function

	system("pause");					//stops the windows from closing
	return 0;
}										//fucntion body end

//Videos http://freevideolectures.com/Course/2514/C++-Programming/1



