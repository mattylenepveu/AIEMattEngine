#pragma once
#include "Vector2.h"
#include "Entity.h"
#include "Texture.h"
#include "Renderer2D.h"
using namespace aie;

// Inherits from Entity class
class Flag : public Entity
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Flag();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Flag();

	//--------------------------------------------------------------------------------------
	// Draws the flag for use in game
	//
	// Parameters:
	//		m_2dRenderer: Accesses the renderer class to allow the flag to be drawn
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

private:
	Texture* m_pTexture;
};

