#pragma once
#include "DynamicArray.h"
#include "Resource.h"
#include <string.h>

template <typename T>
class ResourceManager
{
public:
	ResourceManager() {}
	~ResourceManager() 
	{
		UnloadAllResources();
	}

	T LoadResource(char* szFilename)
	{
		// Check if resource is already loaded
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			if (strcmp(m_ResourceList[i]->m_szFilename, szFilename) == 0)
			{
				return m_ResourceList[i]->m_pData;
			}
		}

		Resource* pResource = new Resource(szFilename);
		m_ResourceList->PushBack(pResource);
		return pResource
	}

	void UnloadAllResources()
	{
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			delete m_ResourceList[i];
		}

		m_ResourceList.Clear();
	}

	DynamicArray<Resource<T>*> m_ResourceList;
};

