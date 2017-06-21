#include "ObjectPool.h"
#include "Entity.h"
#include "Bubble.h"

ObjectPool::ObjectPool(int nMaxSize)
{
	m_nMaxSize = nMaxSize;
	m_pPool = new Entity*[nMaxSize];

	for (int i = 0; i < nMaxSize; ++i)
	{
		m_pPool[i] = new Bubble();
	}
}

ObjectPool::~ObjectPool()
{
	delete[] m_pPool;

	for (int i = 0; i < m_nMaxSize; ++i)
	{
		delete m_pPool[i];
	}
}

Entity* ObjectPool::Allocate()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (!m_pPool[i]->GetActive())
		{
			m_pPool[i]->SetActive(true);
			return m_pPool[i];
		}
	}

	return nullptr;
}

void ObjectPool::Deallocate(Entity* object)
{
	object->SetActive(false);
}

// Make a seperate class for bubble and get it to draw a bubble (in game)
// Bubble should inherit from entity
// Give the entity class a "SetActive" function
// Uncomment code in "Allocate"
// Replace entity with Bubble in object pool*
// Create an instance of an object pool in the car*
// Car will use allocate function to use the array of bubbles*