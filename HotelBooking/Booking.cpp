#include "Booking.h"

Booking::Booking(long long timestamp, unsigned int client_id, int room_count) :
	m_timestamp(timestamp), m_client_id(client_id), m_room_count(room_count)
{
	//empty
}

unsigned int Booking::GetClientID(void) const
{
	return m_client_id;
}

int Booking::GetRoomCount(void) const
{
	return m_room_count;
}

long long Booking::GetTime(void) const
{
	return m_timestamp;
}