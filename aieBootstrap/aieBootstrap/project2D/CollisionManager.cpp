// Includes from various files
#include "CollisionManager.h"
#include "Collider.h"

// Defines instance as a null pointer by default
CollisionManager* CollisionManager::instance = nullptr;

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
CollisionManager::CollisionManager()
{
	// Empty as we use another constructor
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
CollisionManager::~CollisionManager()
{
	// Empty as we use another destructor
}

//--------------------------------------------------------------------------------------
// Acts as the constructor for this class
//--------------------------------------------------------------------------------------
void CollisionManager::Create()
{
	// Checks if there is no instance
	if (!instance)
		// Creates a "new" instance if there is none
		instance = new CollisionManager();
}

//--------------------------------------------------------------------------------------
// Acts as the destructor for this class
//--------------------------------------------------------------------------------------
void CollisionManager::Destroy()
{
	// Deletes instance to prevent memory leaks
	delete instance;
}

//--------------------------------------------------------------------------------------
// Function allows other classes to access the instance
//
// Return:
//		Returns the instance
//--------------------------------------------------------------------------------------
CollisionManager* CollisionManager::GetInstance()
{
	return instance;
}

//--------------------------------------------------------------------------------------
// Adds an Entity to the collision list for testing of any collision
//
// Parameters:
//		object: An entity pointer that takes in any object in game
//--------------------------------------------------------------------------------------
void CollisionManager::AddObject(Entity* object)
{
	// Adds the object to the collision list
	collisionList.push_back(object);
}

//--------------------------------------------------------------------------------------
// Removes an Entity from the collision list
//
// Parameters:
//		object: An entity pointer that takes in any object in game
//--------------------------------------------------------------------------------------
void CollisionManager::RemoveObject(Entity* object)
{
	// Finds the beginning, end and object in the collision list
	auto iter = find(collisionList.begin(), collisionList.end(), object);

	// Checks if the collision list has an end
	if (iter != collisionList.end())
		// If no end, then erase the iter variable
		collisionList.erase(iter);
}

//--------------------------------------------------------------------------------------
// Tests collision between two box objects
//
// Parameters:
//		object: An entity that takes in any object in game
// Return:
//		An entity pointer which is the entity from a collision list or a null pointer
//--------------------------------------------------------------------------------------
Entity* CollisionManager::TestBoxCollision(Entity* object)
{
	// Runs for loop for every object in the collision list
	for (int i = 0; i < collisionList.size(); ++i)
	{	
		// Checks if the object is the same as in the collision list
		if (object == collisionList[i])
			// If so, then don't calculate collision
			continue;

		// Gets properties of both boxes
		Collider collider1 = object->GetCollider();
		collider1.topLeft += object->GetPosition();
		collider1.bottomRight += object->GetPosition();

		Collider collider2 = collisionList[i]->GetCollider();
		collider2.topLeft += collisionList[i]->GetPosition();
		collider2.bottomRight += collisionList[i]->GetPosition();

		// Checks if the objects are connected
		if (collider1.bottomRight > collider2.topLeft && collider1.topLeft < collider2.bottomRight)
			// If so, then return the object in the collision list
			return collisionList[i];
	}

	// Returns nullptr if nothing is colliding
	return nullptr;
}

//--------------------------------------------------------------------------------------
// Tests collision between a box object and a circular object
//
// Parameters:
//		object: An entity that takes in any object in game
// Return:
//		An entity pointer which is the entity from a collision list or a null pointer
//--------------------------------------------------------------------------------------
Entity* CollisionManager::TestSphereCollision(Entity* object)
{
	// Runs for loop for every object in the collision list
	for (int i = 0; i < collisionList.size(); ++i)
	{
		// Checks if the object is the same as in the collision list
		if (object == collisionList[i])
			// If so, then don't calculate collision
			continue;

		// Gets properties of the box
		Collider collider = collisionList[i]->GetCollider();
		collider.topLeft += collisionList[i]->GetPosition();
		collider.bottomRight += collisionList[i]->GetPosition();

		// Gets properties of the circular object
		Collider sphere = object->GetCollider();
		Vector2 pos = object->GetPosition();
		float rad = sphere.rad;

		// Calculates the collision
		Vector2 A = pos.clamp(collider.bottomRight, collider.topLeft);
		Vector2 V = A - pos;
		float VMag = V.sqrMagnitude();

		// Checks if there was any collision between objects
		if (VMag <= rad * rad)
			// If so, then return the object in the collision list
			return collisionList[i];
	}

	// Returns nullptr if nothing is colliding
	return nullptr;
}

//--------------------------------------------------------------------------------------
// Tests collision between two circular objects
//
// Parameters:
//		object: An entity that takes in any object in game
// Return:
//		An entity pointer which is the entity from a collision list or a null pointer
//--------------------------------------------------------------------------------------
Entity* CollisionManager::TestTwoSphereCollision(Entity* object)
{
	// Runs for loop for every object in the collision list
	for (int i = 0; i < collisionList.size(); ++i)
	{
		// Checks if the object is the same as in the collision list
		if (object == collisionList[i])
			// If so, then don't calculate collision
			continue;

		// Gets properties for both circular objects
		Collider sphere1 = object->GetCollider();
		Vector2 pos1 = object->GetPosition();
		float r1 = sphere1.rad;

		Collider sphere2 = collisionList[i]->GetCollider();
		Vector2 pos2 = collisionList[i]->GetPosition();
		float r2 = sphere2.rad;

		// Calculates the collision
		Vector2 V = pos1 - pos2;
		float VMag = V.sqrMagnitude();

		// Checks if there was any collision between objects
		if (VMag <= (r1 + r2) * (r1 + r2))
			// If so, then return the object in the collision list
			return collisionList[i];
	}

	// Returns nullptr if nothing is colliding
	return nullptr;
}