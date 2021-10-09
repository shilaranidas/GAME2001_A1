// GAME2001_A1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UnorderedArray.h"
#include "OrderedArray.h"

using namespace std;
int main()
{
	UnorderedArray<int> uarray(3);

	uarray.push(3);
	uarray.push(53);
	uarray.push(83);
	uarray.push(23); // <-- Should expand here			// 3 23 82 
	uarray.push(82); // <-- Should expand here

	uarray[2] = 112;

	uarray.pop();
	uarray.remove(2);

	cout << "Unordered array contents: ";

	for (int i = 0; i < uarray.GetSize(); i++)
	{
		cout << uarray[i] << " ";
	}

	cout << endl;

	cout << "Search for 53 was found at index: ";
	cout << uarray.search(53);

	cout << endl << endl;


	OrderedArray<int> array(3);

	array.push(3);
	array.push(53);
	array.push(83);
	array.push(23); // <-- Should expand here			// 3 23 82 
	array.push(82); // <-- Should expand here

	array[2] = 112;

	array.pop();
	array.remove(2);

	cout << "Ordered array contents: ";

	for (int i = 0; i < array.GetSize(); i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;

	cout << "Search for 23 was found at index: ";
	cout << array.search(23);

	cout << endl << endl;
	UnorderedArray<int> uarray2(3,3);//expand by 8
	//now tested for grow size
	cout << "unordered list size before           : " << uarray2.GetSize()<<"; max size:"<< uarray2.GetMaxSize()<<endl;//initial max size 3
	uarray2.push(12);
	uarray2.push(22);
	uarray2.push(11);
	
	cout << "unordered list size after push 3 data:" << uarray2.GetSize() << "; max size:" << uarray2.GetMaxSize() << endl;// max size 3
	uarray2.push(21);
	uarray2.push(32);
	uarray2.push(42);
	uarray2.push(45);
	uarray2.push(24);
	cout << "unordered list size after push 5 data:" << uarray2.GetSize() << "; max size:" << uarray2.GetMaxSize() << endl;// max size 3+8
	uarray2.push(26);
	uarray2.push(42);
	uarray2.push(45);
	uarray2.push(45);
	cout << "unordered list size after push 4 data:" << uarray2.GetSize() << "; max size:" << uarray2.GetMaxSize() << endl;// max size 3+8+8
	cout << "unordered array contents after expand: ";

	for (int i = 0; i < uarray2.GetSize(); i++)
	{
		cout << uarray2[i] << " ";
	}

	cout << endl;



	//check for Adding the ability for the ordered array to prevent duplicate data
	OrderedArray<int> array2(3,2,false);
	array2.push(12);
	array2.push(6);
	array2.push(9);

	cout << "Ordered array contents: ";

	for (int i = 0; i < array2.GetSize(); i++)
	{
		cout << array2[i] << " ";
	}

	cout << endl;
	cout << "insert duplicate value" << endl;
	array2.push(9);
	cout << "Ordered array contents (no change): ";
	for (int i = 0; i < array2.GetSize(); i++)
	{
		cout << array2[i] << " ";
	}

	cout << endl;
	
	return 0;
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
