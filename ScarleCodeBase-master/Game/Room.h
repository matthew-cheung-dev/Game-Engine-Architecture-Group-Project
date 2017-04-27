#pragma once
#include <memory>
#include <vector>
#include <d3d11_1.h>
#include <list>
#include <string>

#include "GameObject2D.h"

class Levels;
class PlatfromTile;
class LadderTile;
//class RopeTile;
class Collectables;
class Enemy;
class Player2D;

class CameraFollow2D;
struct GameData;

class Room
{
public:
	friend class Levels;
	~Room() = default;

	std::string getRoomName() { return title; }
	std::vector<std::string> getRoomMap() { return map; }
	list<GameObject2D *> getColldingObjects(); 

	Player2D* getPlayer() { return player; }
	CameraFollow2D* getPlayerCamera() { return m_playerCam; }
	Collectables* getCollectable() { return pickUp; }
	Collectables* getRespawner() { return respawner; }

	void CreateRoom(GameData* _GD, ID3D11Device* _pd3dDevice);
	void Tick(GameData* _GD);
	void Draw(DrawData2D* _DD);


private:
	Room(Levels&);
	Levels& level;

	std::string title;
	std::vector<std::string> map;

	Vector2 enemyStartPos;

	//float incrementY;
	//possibly need to add a bool to stop two players being created 

	Enemy* enemyHor;
	LadderTile* ladder;
	//RopeTile* Rope;
	PlatfromTile* plat;
	Collectables* pickUp;
	Collectables* respawner;

	Player2D* player;
	CameraFollow2D* m_playerCam;


	list<GameObject2D *> InSceneObjects;//list to hold all objects created
	list<GameObject2D*> m_collider;
};



