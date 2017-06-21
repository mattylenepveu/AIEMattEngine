#pragma once
#include "DynamicArray.h"
#include "Resource.h"
#include <string.h>

template <typename T>
class ResourceManager
{
public:
	T* LoadResource(char* szFilename)
	{
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			if (strcmp(m_ResourceList[i]->m_szFilename, szFilename) == 0)
			{
				return m_ResourceList[i]->m_pData;
			}
		}

		Resource<T>* pResource = new Resource<T>(szFilename);
		m_ResourceList.PushBack(pResource);
		return pResource->m_pData;
	}

	void UnloadAllResources()
	{
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			delete m_ResourceList[i];
		}

		m_ResourceList.Clear();
	}

	static void Create()
	{
		if (!m_pInstance)
			m_pInstance = new ResourceManager<T>();
	}

	static void Destroy()
	{
		delete m_pInstance;
	}

	static ResourceManager<T>* GetInstance()
	{
		return m_pInstance;
	}

private:
	ResourceManager() {}
	~ResourceManager()
	{
		UnloadAllResources();
	}

	DynamicArray<Resource<T>*> m_ResourceList;
	static ResourceManager<T>* m_pInstance;
};
template <typename T>
ResourceManager<T>* ResourceManager<T>::m_pInstance = nullptr;