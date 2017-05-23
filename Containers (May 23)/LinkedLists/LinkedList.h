#pragma once
#include "ListNode.h"

template <typename t>
class LinkedList
{
public:
	LinkedList() {};
	~LinkedList() {};

	void PushFront(T data)
	{
		newNode = new ListNode;
	};

	void PushBack(T data)
	{
	};

	void insert(int index, T data)
	{
		newNode = new ListNode;

		newNode.data = newData;

		newNode.next = nodeAfter;
		newNode.prev = nodeBefore;

		nodeBefore.next = newNode;
		nodeAfter.prev = newNode;
	};

	void begin()
	{
	};

	void end()
	{
	};

	void first()
	{
	};

	void last()
	{
	};

	void count()
	{
	};

	void erase(int index)
	{
	};

	void remove(T data)
	{
	};

	void PopBack()
	{
	};

	void PopFront()
	{
	};

	void empty()
	{
	};

	void clear()
	{
	};

	void erase(ListNode<T>*)
	{
	};

	ListNode<T>* start;
	ListNode<T>* end;
};

