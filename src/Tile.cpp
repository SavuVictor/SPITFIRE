

#include "Tile.h"
#include "City.h"
#include "Client.h"

namespace spitfire {
namespace server {

Tile::Tile(void)
{
	m_city = 0;
	m_castleicon = 0;
	m_castleid = -1;
	m_id = -1;
	m_npc = false;
	m_ownerid = -1;
	m_powerlevel = -1;
	m_state = -1;
	m_type = FLAT;
	m_status = -1;
	m_zoneid = -1;
	m_level = -1;
	/*	x = y = -1;*/
}


Tile::~Tile(void)
{
}


amf3object Tile::ToObject()
{
	PlayerCity * city = (PlayerCity*)m_city;
	amf3object obj = amf3object();
	obj["id"] = m_id;
	obj["name"] = city->m_cityname;
	obj["npc"] = m_npc;
	obj["prestige"] = city->m_client->m_prestige;
	obj["honor"] = city->m_client->m_honor;
	obj["state"] = city->m_client->m_status;
	obj["userName"] = city->m_client->m_playername;
	obj["flag"] = city->m_client->m_flag;
	obj["allianceName"] = city->m_client->m_alliancename;
	return obj;
}

string Tile::GetName()
{
	if (m_npc)
	switch (m_type)
	{
	case FOREST:
		return "Forest";
	case DESERT:
		return "Desert";
	case HILL:
		return "Hill";
	case SWAMP:
		return "Swamp";
	case GRASS:
		return "Grass";
	case LAKE:
		return "Lake";
	case FLAT:
		return "Flat";
	case CASTLE:
		return (m_city)?m_city->m_cityname:"Invalid City";
	case NPC:
		return "Barbarian's City";
	}
}

}
}