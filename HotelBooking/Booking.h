#pragma once

class Booking
{
public:
	explicit Booking(long long timestamp, unsigned int client_id, int room_count);
	~Booking(void) = default;
	Booking(const Booking& other_booking) = default;
	Booking& operator=(const Booking& other_booking) = default;

	long long GetTime(void) const;
	unsigned int GetClientID(void) const;
	int GetRoomCount(void) const;
private:

	long long m_timestamp;
	unsigned int m_client_id;
	unsigned int m_room_count;
};

