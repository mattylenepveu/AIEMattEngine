#pragma once
#include <string.h>
#include <crtdbg.h>

// Class is templated so it can use any type
template <typename T>
class Resource
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//
	// Parameters:
	//		szFilename: A char pointer that takes in any resource
	//--------------------------------------------------------------------------------------
	Resource(char* szFilename)
	{
		// Checks the amount of characters in parameter and sets it to variable
		int length = strlen(szFilename) + 1;

		// Creates a "new" filename
		m_szFilename = new char[length];
		_ASSERT(m_szFilename);

		// Copies the filename parameter to the new filename
		strcpy_s(m_szFilename, length, szFilename);

		// Creates "new" data of any type
		m_pData = new T(szFilename);
		_ASSERT(m_pData);
	}

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Resource()
	{
		delete m_pData;
		delete[] m_szFilename;
	}

	char* m_szFilename;
	T* m_pData;
};