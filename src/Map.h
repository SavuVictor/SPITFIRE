#pragma once

#include "funcs.h"
#include "Tile.h"
#include "amf3.h"

namespace spitfire {
namespace server {

class City;
class server;

class Map
{
public:
	Map(server * sptr);
	~Map(void);

	server * m_main;
	string * states;

	void CalculateOpenTiles();
	int GetStateFromXY(int x, int y);
	int GetStateFromID(int id);
	int GetRandomOpenTile(int zone);
	amf3object GetTileRangeObject(int32_t clientid, int x1, int x2, int y1, int y2);
	amf3object GetMapCastle(int32_t fieldid, int32_t clientid);
	Tile * GetTileFromID(int id);

	bool AddCity(int id, City * city);

	Tile * m_tile;
	int32_t m_totalflats[DEF_STATES];
	int32_t m_openflats[DEF_STATES];
	int32_t m_npcs[DEF_STATES];
	int32_t m_cities[DEF_STATES];
	int32_t m_occupiedtiles[DEF_STATES];
	int32_t m_occupiabletiles[DEF_STATES];
	struct mapstats
	{
		int players;
		int numbercities;
		int playerrate;
	} m_stats[DEF_STATES];

	vector<int32_t> m_openflatlist[DEF_STATES];
};


}
}