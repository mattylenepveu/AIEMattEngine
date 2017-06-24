#include <iostream>
#include "DynamicArray.h"
#include "Stack.h"
#include "AssociativeArray.h"
using namespace std;

//--------------------------------------------------------------------------------------
// Main function where tests are conducted
//
// Return:
//		Returns zero by default
//--------------------------------------------------------------------------------------
int main()
{
	// Dynamic Array Unit Test 

	DynamicArray<int> myArray(3);

	cout << "Initial Size of Array: " << endl;
	cout << "	Used: " << myArray.Size() << endl;
	cout << "	Capacity: " << myArray.Capacity() << endl;
	cout << endl;

	cout << "Adding Values to array..." << endl;
	cout << endl;

	myArray.PushBack(9);
	myArray.PushBack(8);
	myArray.PushBack(7);
	myArray.PushBack(6);
	myArray.PushBack(5);

	cout << "Values after Push Back are: " << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << "	Space " << (i + 1) << ": " << myArray[i] << endl;
	}
	cout << endl;

	cout << "New Size of Array: " << endl;
	cout << "	Used: " << myArray.Size() << endl;
	cout << "	Capacity: " << myArray.Capacity() << endl;
	cout << endl;

	myArray.PushFront(6);

	cout << "Values after Push Front are: " << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << "	Space " << (i + 1) << ": " << myArray[i] << endl;
	}
	cout << endl;

	myArray.Insert(1, 4);

	cout << "Values after insert are: " << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << "	Space " << (i + 1) << ": " << myArray[i] << endl;
	}
	cout << endl;

	int popBack = myArray.PopBack();
	cout << "Values Popped: " << popBack << endl;
	cout << endl;

	cout << "Values after popping back are: " << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << "	Space " << (i + 1) << ": " << myArray[i] << endl;
	}
	cout << endl;

	int remove = myArray.Remove(0);
	cout << "Values Removed: " << remove << endl;
	cout << endl;

	cout << "Values after removing are: " << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << "	Space " << (i + 1) << ": " << myArray[i] << endl;
	}
	cout << endl;

	int popFront = myArray.PopFront();
	cout << "Values Popped: " << popFront << endl;
	cout << endl;

	cout << "Values after popping front are: " << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << "	Space " << (i + 1) << ": " << myArray[i] << endl;
	}
	cout << endl;

	myArray.Clear();
	cout << "Clearing array..." << endl;
	cout << endl;

	int size = myArray.Size();
	cout << "Size of the Array: " << size << endl;
	cout << endl;

	cout << "Dynamic Array Tested!" << endl;
	cout << endl;

	system("pause");
	system("cls");
	return 0;
}