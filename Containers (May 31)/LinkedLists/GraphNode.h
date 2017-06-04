#pragma once
#include "DynamicArray.h"
#include "Stack.h"

// ---------------------------------------------------------------------
// Use LinkedLists instead of DynamicArray once LinkedLists is complete
// ---------------------------------------------------------------------
template <typename T>
class GraphNode
{
public:
	GraphNode() 
	{
		m_bTraversed = false;
	}

	GraphNode(T data)
	{
		m_Data = data;
		m_bTraversed = false;
	}

	~GraphNode() {}

	void AddConnection(GraphNode<T>* other)
	{
		m_Edges.PushBack(other);
	}

	void RemoveConnection(GraphNode<T>* other)
	{
		for (int i = 0; i < m_Edges.Size(); ++i)
		{
			if (m_Edges[i] == other)
			{
				m_Edges.Remove(i);
				return;
			}
		}
	}

	DynamicArray<GraphNode<T>*> m_Edges;
	T m_Data;
	bool m_bTraversed;
};