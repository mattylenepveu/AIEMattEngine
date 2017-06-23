#pragma once
#include <memory.h>
#include <crtdbg.h>

// Class uses a templated type
template <typename T>
class DynamicArray
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//
	// Parameters:
	//		initialSize: An integer that is set to 0 by default
	//--------------------------------------------------------------------------------------
	DynamicArray(int initialSize = 0) 
	{
		// Makes the nCapacity int equal to the initialSize int
		int nCapacity = initialSize;

		// If the nCapacity int is less than or equal to 0, then make it equal to 1
		if (nCapacity <= 0)
			nCapacity = 1;

		// Makes a "new" array with the size equal to nCapacity variable
		m_pData = new T[nCapacity];
		_ASSERT(m_pData);

		// Makes the m_nCapacity int equal to nCapacity
		m_nCapacity = nCapacity;
		m_nUsed = 0;
	}

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~DynamicArray() 
	{
		delete m_pData;
	}

	//--------------------------------------------------------------------------------------
	// An additional Constructor.
	//
	// Parameters:
	//		other: Refers to the dynamic array
	//--------------------------------------------------------------------------------------
	DynamicArray(const DynamicArray& other)
	{
		// Lets m_nCapacity and m_nUsed be equal to the capcity and used of Dynamic Array
		m_nCapacity = other.m_nCapacity;
		m_nUsed = other.m_nUsed;
		
		// Makes a "new" array with the size now equal to the dynamic arrays capacity
		m_pData = new T[other.m_nCapacity];
		_ASSERT(m_pData);

		// Copies the memory of dynamic arrays and size of templated type multiplied by capacity of dynamic array
		memcpy(m_pData, other.m_pData, sizeof(T) * other.m_nCapacity);
	}

	//--------------------------------------------------------------------------------------
	// Pushes data into the array from the back of it
	//
	// Parameters:
	//		value: The value we are pushing back in the array
	//--------------------------------------------------------------------------------------
	void PushBack(T value)
	{
		// If used is greater than capacity, then resize the array
		if (m_nUsed >= m_nCapacity)
			Resize();

		// Inserts value in array
		m_pData[m_nUsed] = value;
		++m_nUsed;
	}

	//--------------------------------------------------------------------------------------
	// Pushes data into the array from the front of it
	//
	// Parameters:
	//		value: The value we are pushing in the array from front
	//--------------------------------------------------------------------------------------
	void PushFront(T value)
	{
		Insert(0, value);
	}

	//--------------------------------------------------------------------------------------
	// Inserts data into the array
	//
	// Parameters:
	//		index: The location of where the data will be inserted in the array
	//		value: The value we are pushing back in the array
	//--------------------------------------------------------------------------------------
	void Insert(int index, T value)
	{
		// If used is greater than capacity, then resize the array
		if (m_nUsed >= m_nCapacity)
			Resize();

		// Copies the memory into the array via the index
		memcpy(m_pData + index + 1, m_pData + index, sizeof(T) * (m_nUsed - index));

		// Inserts the value where indexed in
		m_pData[index] = value;
		++m_nUsed;
	}

	//--------------------------------------------------------------------------------------
	// Pops values off of the array from the back
	//
	// Return:
	//		Returns a templated type refering to the removed array index
	//--------------------------------------------------------------------------------------
	T PopBack()
	{
		--m_nUsed;
		return m_pData[m_nUsed];
	}

	//--------------------------------------------------------------------------------------
	// Removes any value from the array
	//
	// Parameters:
	//		index: Takes in the index of the array of which the value there will be removed
	// Return:
	//		Returns a templated type refering to the removed array index
	//--------------------------------------------------------------------------------------
	T Remove(int index)
	{
		// Value equal to value in spot index of the array
		T value = m_pData[index];

		// Reworks the array to be full again
		for (int i = index; i < m_nUsed; ++i)
		{
			m_pData[i] = m_pData[i + 1];
		}
		--m_nUsed;

		// Returns the removed value
		return value;
	}

	//--------------------------------------------------------------------------------------
	// Pops values off of the array from the front
	//
	// Return:
	//		Returns a templated type refering to the removed array index
	//--------------------------------------------------------------------------------------
	T PopFront()
	{
		return Remove(0);
	}

	//--------------------------------------------------------------------------------------
	// Clears the array and makes used equal to zero
	//--------------------------------------------------------------------------------------
	void Clear()
	{
		m_nUsed = 0;
	}

	//--------------------------------------------------------------------------------------
	// Shrinks the size of the array
	//--------------------------------------------------------------------------------------
	void Shrink()
	{
		// Makes the capacity equal to the used variable
		int nCapacity = m_nUsed;

		// Makes sure the capacity is not zero or less
		if (nCapacity <= 0)
			nCapacity = 1;

		// Makes "new" data with the size being equal to the used variable
		T* newData = new T[m_nUsed];
		_ASSERT(newData);

		// Copies the memory into newData
		memcpy(newData, m_pData, sizeof(T)* m_nUsed);
		delete m_pData;

		// Maskes the newData equal to the old data
		m_pData = newData;

		// Makes the capacity double in size
		m_nCapacity *= 2;
	}

	//--------------------------------------------------------------------------------------
	// Overloads the square brackets symbol
	//
	// Parameters:
	//		index: Takes in the index of the array
	// Return:
	//		Returns a templated type refering to the array index
	//--------------------------------------------------------------------------------------
	T& operator[](const int index)
	{
		return m_pData[index];
	}

	//--------------------------------------------------------------------------------------
	// Returns the size of the array
	//
	// Return:
	//		Returns the m_nUsed variable
	//--------------------------------------------------------------------------------------
	int Size()
	{
		return m_nUsed;
	}

	//--------------------------------------------------------------------------------------
	// Returns the capacity of the array
	//
	// Return:
	//		Returns the m_nCapacity variable
	//--------------------------------------------------------------------------------------
	int Capacity()
	{
		return m_nCapacity;
	}

private:
	DynamicArray& operator= (const DynamicArray& other) = default;
	DynamicArray(DynamicArray&& other) = default;
	DynamicArray& operator= (DynamicArray&& other) = default;

	//--------------------------------------------------------------------------------------
	// Resizes the array after a value has been removed from it
	//--------------------------------------------------------------------------------------
	void Resize()
	{
		// Makes "new" data with the size being twice as big as the capacity
		T* newData = new T[m_nCapacity * 2];
		_ASSERT(newData);

		// Copies the memory into newData
		memcpy(newData, m_pData, sizeof(T)* m_nUsed);

		// Deletes the old data and copies the new data into that variable
		delete m_pData;
		m_pData = newData;

		// Makes the capacity variable double
		m_nCapacity = m_nCapacity * 2;
	}

	int m_nCapacity;
	int m_nUsed;

	// Defines the array of templated data
	T* m_pData;
};