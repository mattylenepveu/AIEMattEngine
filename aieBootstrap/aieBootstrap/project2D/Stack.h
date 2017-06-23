#pragma once
#include "DynamicArray.h"

// Class uses a templated type

template <typename T>
class Stack
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//
	// Parameters:
	//		initialSize: An integer that is set to 0 by default
	//--------------------------------------------------------------------------------------
	Stack(int initialSize = 0) {}

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Stack() {}

	//--------------------------------------------------------------------------------------
	// Checks if the the size of the array is equal to zero
	//
	// Returns:
	//		Returns a bool saying if the arrays empty or not
	//--------------------------------------------------------------------------------------
	bool IsEmpty()
	{
		return (m_pData.Size() = 0);
	}

	//--------------------------------------------------------------------------------------
	// Returns the size of the stack
	//
	// Return:
	//		Returns the size of the stack
	//--------------------------------------------------------------------------------------
	int Size()
	{
		return m_pData.Size();
	}

	//--------------------------------------------------------------------------------------
	// Pushes a value onto the top of the stack
	//
	// Parameters:
	//		value: Refers to the value of which is being put on the stack
	//--------------------------------------------------------------------------------------
	void Push(T value)
	{
		m_pData.PushBack(value);
	}

	//--------------------------------------------------------------------------------------
	// Pops off the value at the top of the stack
	//
	// Return:
	//		Returns the stack with the value popped off
	//--------------------------------------------------------------------------------------
	T Pop()
	{
		return m_pData.PopBack();
	}

	//--------------------------------------------------------------------------------------
	// Refers to the top value of the stack
	//
	// Return:
	//		Returns the top value of the stack
	//--------------------------------------------------------------------------------------
	T Top()
	{
		// Makes the top of the stack equal to the size minus 1 (as the is stack[0])
		int nTop = m_pData.Size() - 1;

		// Returns the top stack with the top indexed
		return m_pData[nTop];
	}

	//--------------------------------------------------------------------------------------
	// Refers to the second value from the top of the stack
	//
	// Return:
	//		Returns the second from top value of the stack
	//--------------------------------------------------------------------------------------
	T SecondLast()
	{
		// Makes the second from top value equal to the size of the stack minus 2
		int nSecondLast = m_pData.Size() - 2;

		// Returns the second from top value with the variable indexed
		return m_pData[nSecondLast];
	}

	// Uses the dynamic array for data
	DynamicArray<T> m_pData;
};