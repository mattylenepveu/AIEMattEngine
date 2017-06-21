#pragma once

// Includes from various files
#include <vector>
#include "Matrix3.h"
#include "Collider.h"
using namespace std;

//--------------------------------------------------------------------------------------
// Enum represents the different types of objects in game
//--------------------------------------------------------------------------------------
enum Type
{
	CAR,
	HUMAN,
	SEA
};

class Entity
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Entity();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Entity();

	//--------------------------------------------------------------------------------------
	// Sets the parent of a particular in game object
	//
	// Parameters:
	//		parent: An entity pointer that passes in an object that'll act as the parent
	//--------------------------------------------------------------------------------------
	void setParent(Entity* parent);

	//--------------------------------------------------------------------------------------
	// Sets the child of a particular in game object
	//
	// Parameters:
	//		child: An entity pointer that passes in an object that'll act as the child
	//--------------------------------------------------------------------------------------
	void setChildren(Entity* child);

	//--------------------------------------------------------------------------------------
	// Updates an objects status each frame
	//--------------------------------------------------------------------------------------
	void UpdateTransform();

	//--------------------------------------------------------------------------------------
	// Allows other functions to get a collider
	//
	// Return:
	//		Returns the address of a collider
	//--------------------------------------------------------------------------------------
	Collider& GetCollider();

	//--------------------------------------------------------------------------------------
	// Sets the position of a particular in game object
	//
	// Parameters:
	//		x: A float that gives the x coordinate of an object
	//		y: A float that gives the y coordinate of an object
	//--------------------------------------------------------------------------------------
	void SetPosition(float x, float y);

	//--------------------------------------------------------------------------------------
	// Allows other functions to get the position of an object
	//
	// Return:
	//		Returns the position as a Vector2
	//--------------------------------------------------------------------------------------
	Vector2 GetPosition();

	//--------------------------------------------------------------------------------------
	// Sets the localTransform variable as the globalTransform variable
	//--------------------------------------------------------------------------------------
	void LocalToGlobal();

	//--------------------------------------------------------------------------------------
	// Sets the type of an object for ColliderManager class to know
	//
	// Parameters:
	//		a: Passes in a type from the enum in "Entity.h"
	//--------------------------------------------------------------------------------------
	void SetType(Type a);
	
	//--------------------------------------------------------------------------------------
	// Allows other functions to get the type of an object
	//
	// Return:
	//		Returns the type of an object
	//--------------------------------------------------------------------------------------
	Type GetType();

protected:
	// Sets the parent as an entity pointer
	Entity* Parent;

	// Makes a list of children, all as entity pointers
	vector<Entity*> children;

	// Transforms an object locally as a Matrix3
	Matrix3 localTransform;

	// Transforms an object gloabally as a Matrix3
	Matrix3 globalTransform;

	// Sets the collider variable as a collider
	Collider collider;

	// Sets the type variable as a type
	Type type;
};