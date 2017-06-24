#pragma once
#include "DynamicArray.h"
#include "Resource.h"
#include <string.h>
#include <crtdbg.h>

template <typename T>
class ResourceManager
{
public:
	//--------------------------------------------------------------------------------------
	// Loads each resource and stores it as data
	//
	// Parameters:
	//		szFilename: A char pointer that takes in any resource
	// Return:
	//		Returns the data
	//--------------------------------------------------------------------------------------
	T* LoadResource(char* szFilename)
	{
		// Returns each resource in the resource list
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			// Checks if the resource is the same as the resource in the resource list
			if (strcmp(m_ResourceList[i]->m_szFilename, szFilename) == 0)
			{
				return m_ResourceList[i]->m_pData;
			}
		}

		// If there are no resorces, then make a "new" resource
		Resource<T>* pResource = new Resource<T>(szFilename);
		_ASSERT(pResource);

		// Pushes the "new" resource into the dynamic array
		m_ResourceList.PushBack(pResource);

		// Returns the resource
		return pResource->m_pData;
	}

	//--------------------------------------------------------------------------------------
	// Unloads all resources (deletes resources)
	//--------------------------------------------------------------------------------------
	void UnloadAllResources()
	{
		// Deletes each resource in the resource list
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			delete m_ResourceList[i];
		}

		// Clears the resource list
		m_ResourceList.Clear();
	}

	//--------------------------------------------------------------------------------------
	// Creates an instance for the resource manager
	//--------------------------------------------------------------------------------------
	static void Create()
	{
		// Creates a "new" instance if was none to begin with
		if (!m_pInstance)
		{
			m_pInstance = new ResourceManager<T>();
			_ASSERT(m_pInstance);
		}
	}

	//--------------------------------------------------------------------------------------
	// Destroys the instance (like a destructor)
	//--------------------------------------------------------------------------------------
	static void Destroy()
	{
		delete m_pInstance;
	}

	//--------------------------------------------------------------------------------------
	// Allows other functions to obtain the instance
	//
	// Return:
	//		Returns the instance
	//--------------------------------------------------------------------------------------
	static ResourceManager<T>* GetInstance()
	{
		return m_pInstance;
	}

private:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	ResourceManager() {}

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~ResourceManager()
	{
		UnloadAllResources();
	}

	// Class uses dynamic array for the resource list
	DynamicArray<Resource<T>*> m_ResourceList;
	static ResourceManager<T>* m_pInstance;
};
// Uses a singleton (which can't be used in a header file)
template <typename T>
ResourceManager<T>* ResourceManager<T>::m_pInstance = nullptr;