
#include "Hero.h"

namespace spitfire {
namespace server {

Hero::Hero()
{
	m_experience = m_id = m_itemamount = m_itemid = m_level
		= m_loyalty = m_management = m_managementadded = m_managementbuffadded
		= m_power = m_poweradded = m_powerbuffadded = m_remainpoint
		= m_status = m_stratagem = m_stratagemadded = m_stratagembuffadded
		= m_upgradeexp = 0;
	m_name = "";
	m_logourl = "";
	movement = 0;
}

Hero::~Hero()
{

}

amf3object Hero::ToObject()
{
	amf3object obj = amf3object();
	obj["experience"] = m_experience;
	obj["id"] = m_id;
	obj["itemAmount"] = m_itemamount;
	//obj["itemId"] = m_itemid;
	obj["level"] = m_level;
	obj["logoUrl"] = m_logourl;
	obj["loyalty"] = m_loyalty;
	obj["management"] = m_management;
	obj["managementAdded"] = m_managementadded;
	obj["managementBuffAdded"] = m_managementbuffadded;
	obj["name"] = m_name;
	obj["power"] = m_power;
	obj["powerAdded"] = m_poweradded;
	obj["powerBuffAdded"] = m_powerbuffadded;
	obj["remainPoint"] = m_remainpoint;
	obj["status"] = m_status;
	obj["stratagem"] = m_stratagem;
	obj["stratagemAdded"] = m_stratagemadded;
	obj["stratagemBuffAdded"] = m_stratagembuffadded;
	obj["upgradeExp"] = m_upgradeexp;
	return obj;
}

}
}