#include <iostream>
#include "DynamicArray.h"
#include "Stack.h"
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

	// Defines capacity for Dynamic Array
	DynamicArray<int> myArray(3);

	// Tests the size and capacity of Dynamic Array
	cout << "Initial Size of Array: " << endl;
	cout << "	Used: " << myArray.Size() << endl;
	cout << "	Capacity: " << myArray.Capacity() << endl;
	cout << endl;

	cout << "Adding Values to array..." << endl;
	cout << endl;

	// Tests push back for Dynamic Array
	myArray.PushBack(9);
	myArray.PushBack(8);
	myArray.PushBack(7);
	myArray.PushBack(6);
	myArray.PushBack(5);

	// Tests if values are in right space
	cout << "Values after Push Back are: " << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << "	Space " << (i + 1) << ": " << myArray[i] << endl;
	}
	cout << endl;

	// Tests the new size of the new Dynamic Array
	cout << "New Size of Array: " << endl;
	cout << "	Used: " << myArray.Size() << endl;
	cout << "	Capacity: " << myArray.Capacity() << endl;
	cout << endl;

	// Tests the push front function for Dynamic Array
	myArray.PushFront(6);

	// Checks the new values
	cout << "Values after Push Front are: " << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << "	Space " << (i + 1) << ": " << myArray[i] << endl;
	}
	cout << endl;

	// Tests insert function of Dynamic Array
	myArray.Insert(1, 4);

	// Checks the new values
	cout << "Values after insert are: " << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << "	Space " << (i + 1) << ": " << myArray[i] << endl;
	}
	cout << endl;

	// Tests the pop back function of Dynamic Array
	int popBack = myArray.PopBack();
	cout << "Values Popped: " << popBack << endl;
	cout << endl;

	// Checks the new values
	cout << "Values after popping back are: " << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << "	Space " << (i + 1) << ": " << myArray[i] << endl;
	}
	cout << endl;

	// Tests the remove function in Dynamic Array
	int remove = myArray.Remove(0);
	cout << "Values Removed: " << remove << endl;
	cout << endl;

	// Checks the new values
	cout << "Values after removing are: " << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << "	Space " << (i + 1) << ": " << myArray[i] << endl;
	}
	cout << endl;

	// Tests the pop front function of Dynamic Array
	int popFront = myArray.PopFront();
	cout << "Values Popped: " << popFront << endl;
	cout << endl;

	// Checks the new values
	cout << "Values after popping front are: " << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << "	Space " << (i + 1) << ": " << myArray[i] << endl;
	}
	cout << endl;

	// Tests the clear function of Dynamic Array
	myArray.Clear();
	cout << "Clearing array..." << endl;
	cout << endl;

	// Checks if the size of array is now zero
	int size = myArray.Size();
	cout << "Size of the Array: " << size << endl;
	cout << endl;

	// Finish Dynamic Array testing
	cout << "Dynamic Array Tested!" << endl;
	cout << endl;

	system("pause");
	system("cls");

	// Stack Unit Test

	// Defines a capacity for Stack
	Stack<int> myStack(3);

	// Checks the size of Stack is zero
	cout << "Initial Size of Stack: " << myStack.Size() << endl;
	cout << endl;

	// Tests the IsEmpty function of the Stack (should be true)
	bool empty = myStack.IsEmpty();

	if (empty)
		cout << "Stack is Empty!" << endl;
	else
		cout << "Stack is not empty!" << endl;

	cout << endl;

	cout << "Adding values 3, 5, 2, 6 and 9 to stack..." << endl;
	cout << endl;

	// Tests the push function of the Stack
	myStack.Push(3);
	myStack.Push(5);
	myStack.Push(2);
	myStack.Push(6);
	myStack.Push(9);

	// Checks the new size of Stack
	cout << "New Size of Stack: " << myStack.Size() << endl;
	cout << endl;

	// Tests the IsEmpty function again of the Stack (should be false)
	bool emptyTwo = myStack.IsEmpty();

	if (emptyTwo)
		cout << "Stack is Empty!" << endl;
	else
		cout << "Stack is not empty!" << endl;

	cout << endl;

	cout << "Popping number 9 off the top of the stack..." << endl;
	cout << endl;

	// Tests the Pop function of the Stack
	myStack.Pop();

	// Checks the new size of the Stack
	cout << "New Size of Stack: " << myStack.Size() << endl;
	cout << endl;

	// Tests the Top function of the Stack
	cout << "Top value on stack: " << myStack.Top() << endl;
	cout << endl;

	// Tests the SecondLast function of the Stack
	cout << "Second value from the top on stack: " << myStack.SecondLast() << endl;
	cout << endl;

	// Finish Stack testing
	cout << "Stack Tested!" << endl;
	cout << endl;

	system("pause");

	// Terminates program (return type)
	return 0;
}