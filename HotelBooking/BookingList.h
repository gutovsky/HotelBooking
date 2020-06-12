#pragma once

#include "Booking.h"
#include <list>
#include <exception>

class BookingList
{
public:
	explicit BookingList(int period_to_save_in_sec);
	~BookingList(void) = default;
	BookingList(const BookingList& other_booking) = delete;
	BookingList& operator=(const BookingList& other_booking) = delete;

	struct NewBookingException : public std::exception
	{
		const char* what() const throw()
		{
			return "Cant add new booking";
		}
	};

	void AddNewBooking(const Booking& new_booking);
	unsigned long GetNumOfRooms(long long curr_time);
	unsigned int GetNumOfClients(long long curr_time);

private:
	const int m_period_to_save;
	long long m_prev_update_time;
	unsigned int m_num_of_clients;
	unsigned long m_num_of_rooms;
	std::list<Booking> m_booking_list;
		
	void UpdateState(long long curr_time);
	bool InTimeRange(long long curr_time, const Booking& booking);
};
