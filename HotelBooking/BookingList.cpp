#include "BookingList.h"
#include <set>
#include <algorithm>

using std::set;
using std::for_each;

BookingList::BookingList(int period_to_save_in_sec) :
	m_period_to_save(period_to_save_in_sec), m_booking_list(), m_prev_update_time(0),
	m_num_of_clients(0), m_num_of_rooms(0)
{
	//empty
}

unsigned long BookingList::GetNumOfRooms(long long curr_time)
{
	if (m_prev_update_time != curr_time)
	{
		UpdateState(curr_time);
	}
	return m_num_of_rooms;
}

unsigned int BookingList::GetNumOfClients(long long curr_time)
{
	if (m_prev_update_time != curr_time)
	{
		UpdateState(curr_time);
	}
	return m_num_of_clients;
}

void BookingList::AddNewBooking(const Booking& new_booking)
{
	try
	{
		m_booking_list.push_front(new_booking);
	}
	catch (const std::exception& e)
	{
		(void)e;
		throw NewBookingException();
	}
}

void BookingList::UpdateState(long long curr_time)
{
	set<unsigned int> unique_clients;
	unsigned long total_num_of_rooms = 0;

	m_booking_list.remove_if([this, curr_time](const Booking& booking) {return !(this->InTimeRange(curr_time, booking));});

	for (std::list<Booking>::iterator it = m_booking_list.begin(); it != m_booking_list.end(); it++)
	{
		total_num_of_rooms += it->GetRoomCount();
		unique_clients.insert(it->GetClientID());
	}
	
	m_num_of_clients = unique_clients.size();
	m_num_of_rooms = total_num_of_rooms;

	m_prev_update_time = curr_time;
}

bool BookingList::InTimeRange(long long curr_time, const Booking& booking)
{
	long long booking_time = booking.GetTime();

	return (curr_time >= booking_time && curr_time - m_period_to_save < booking_time);
}

