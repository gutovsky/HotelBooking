#include "Hotel.h"

Hotel::Hotel(const std::string& hotel_name) :
	m_hotel_name(hotel_name)
{
	//empty
}

const std::string& Hotel::GetName(void) const
{
	return m_hotel_name;
}

bool operator<(const Hotel& hotel1, const Hotel& hotel2)
{
	return (hotel1.GetName() < hotel2.GetName());
}