#pragma once
#include <memory.h>
#include <crtdbg.h>

template <typename T>
class DynamicArray
{
public:
	DynamicArray(int initialSize = 0) 
	{
		int nCapacity = initialSize;
		if (nCapacity <= 0)
			nCapacity = 1;

		m_pData = new T[nCapacity];
		m_nCapacity = nCapacity;
		m_nUsed = 0;
	}

	~DynamicArray() 
	{
		delete m_pData;
	}

	DynamicArray(const DynamicArray& other)
	{
		m_nCapacity = other.m_nCapacity;
		m_nUsed = other.m_nUsed;
		
		m_pData = new T[other.m_nCapacity];
		memcpy(m_pData, other.m_pData, sizeof(T) * other.m_nCapacity);
	}

	// Tested
	void PushBack(T value)
	{
		if (m_nUsed >= m_nCapacity)
			Resize();

		m_pData[m_nUsed] = value;
		++m_nUsed;
	}

	// Tested
	void PushFront(T value)
	{
		Insert(0, value);
	}

	// Tested
	void Insert(int index, T value)
	{
		if (m_nUsed >= m_nCapacity)
			Resize();

		memcpy(m_pData + index + 1, m_pData + index, sizeof(T) * (m_nUsed - index));

		m_pData[index] = value;
		++m_nUsed;
	}

	// Tested
	T PopBack()
	{
		--m_nUsed;
		return m_pData[m_nUsed];
	}

	// Tested
	T Remove(int index)
	{
		T value = m_pData[index];

		for (int i = index; i < m_nUsed; ++i)
		{
			m_pData[i] = m_pData[i + 1];
		}
		--m_nUsed;

		return value;
	}

	// Tested
	T PopFront()
	{
		return Remove(0);
	}

	void Clear()
	{
		m_nUsed = 0;
	}

	void Shrink()
	{
		int nCapacity = m_nUsed;
		if (nCapacity <= 0)
			nCapacity = 1;

		T* newData = new T[m_nUsed];
		memcpy(newData, m_pData, sizeof(T)* m_nUsed);
		delete m_pData;

		m_pData = newData;
		m_nCapacity *= 2;
	}

	T& operator[](const int index)
	{
		return m_pData[index];
	}

	// Tested
	int Size()
	{
		return m_nUsed;
	}

	// Tested
	int Capacity()
	{
		return m_nCapacity;
	}

private:
	DynamicArray& operator= (const DynamicArray& other) = default;
	DynamicArray(DynamicArray&& other) = default;
	DynamicArray& operator= (DynamicArray&& other) = default;

	void Resize()
	{
		T* newData = new T[m_nCapacity * 2];
		memcpy(newData, m_pData, sizeof(T)* m_nUsed);

		delete m_pData;
		m_pData = newData;

		m_nCapacity = m_nCapacity * 2;
	}

	int m_nCapacity;
	int m_nUsed;
	T* m_pData;
};