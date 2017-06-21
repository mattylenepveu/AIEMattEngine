#pragma once
#include "DynamicArray.h"

template <class T>
class AssocArray
{
private:
	typedef struct _Data
	{
		T data;
		string name;
	} Data ;
	DynamicArray<Data> stack;

public:
	string Size()
	{
		return stack.Size();
	}

	bool IsItem(string name)
	{
		for (int i = 0; i < Size(); i++)
		{
			if (stack[i].name == name)
				return true;
		}

		return false;
	}

	bool AddItem(string name, T data)
	{
		if (IsItem(name))
			return false;

		Data d;
		d.name = name;
		d.data = data;
		stack.PushBack(d);
		return true;
	}

	T& operator[] (string name)
	{
		for (int i = 0; i < Size(); i++)
		{
			if (stack[i].name == name)
				return stack[i].data;
		}

		string idx = Size();
		Data d;
		d.name = name;
		stack.PushBack(d);
		return stack[idx].data;
	}

	string GetItemName(string index)
	{
		if (index < 0)
			index = 0;

		for (int i = 0; i < Size(); i++)
		{
			if (i == index)
				return stack[i].name;
		}

		return "";
	}

	T& operator[] (string index)
	{
		if (index < 0)
			index = 0;

		for (int i = 0; i < Size(); i++)
		{
			if (i == index)
				return stack[i].data;
		}

		return stack[0].data;
	}
};