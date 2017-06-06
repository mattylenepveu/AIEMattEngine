#pragma once

// Includes from various files
#include <vector>
#include "Entity.h"
#include "Vector2.h"

class CollisionManager
{
public:
	//--------------------------------------------------------------------------------------
	// Acts as the constructor for this class
	//--------------------------------------------------------------------------------------
	static void Create();

	//--------------------------------------------------------------------------------------
	// Acts as the destructor for this class
	//--------------------------------------------------------------------------------------
	static void Destroy();

	//--------------------------------------------------------------------------------------
	// Function allows other classes to access the instance
	//
	// Return:
	//		Returns the instance
	//--------------------------------------------------------------------------------------
	static CollisionManager* GetInstance();

	//--------------------------------------------------------------------------------------
	// Adds an Entity to the collision list for testing of any collision
	//
	// Parameters:
	//		object: An entity pointer that takes in any object in game
	//--------------------------------------------------------------------------------------
	void AddObject(Entity* object);

	//--------------------------------------------------------------------------------------
	// Removes an Entity from the collision list
	//
	// Parameters:
	//		object: An entity pointer that takes in any object in game
	//--------------------------------------------------------------------------------------
	void RemoveObject(Entity* object);

	//--------------------------------------------------------------------------------------
	// Tests collision between two box objects
	//
	// Parameters:
	//		object: An entity that takes in any object in game
	// Return:
	//		An entity pointer which is the entity from a collision list or a null pointer
	//--------------------------------------------------------------------------------------
	Entity* TestBoxCollision(Entity* object);

	//--------------------------------------------------------------------------------------
	// Tests collision between a box object and a circular object
	//
	// Parameters:
	//		object: An entity that takes in any object in game
	// Return:
	//		An entity pointer which is the entity from a collision list or a null pointer
	//--------------------------------------------------------------------------------------
	Entity* TestSphereCollision(Entity* object);

	//--------------------------------------------------------------------------------------
	// Tests collision between two circular objects
	//
	// Parameters:
	//		object: An entity that takes in any object in game
	// Return:
	//		An entity pointer which is the entity from a collision list or a null pointer
	//--------------------------------------------------------------------------------------
	Entity* TestTwoSphereCollision(Entity* object);

private:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	CollisionManager();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~CollisionManager();

	// Creates an instance which has the type of a CollisionManager pointer
	static CollisionManager* instance;

	// Creates a vector list for entity's objects to be added
	std::vector<Entity*> collisionList;
};