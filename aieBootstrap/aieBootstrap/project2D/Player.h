#pragma once
class Player
{
public:
	static Player* Instance();

	static void create() { m_instance = new Player(); }
	static void destroy() { delete m_instance; }

	void setColour(bool colour);
	bool getColour();

	void setFinish(bool fin);
	bool getFinish();

private:
	Player();
	~Player();

	static Player* m_instance;
	bool bColour;
	bool bFin;
};

