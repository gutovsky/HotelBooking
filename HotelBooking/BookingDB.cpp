#include "BookingDB.h"
#include <new>
#include <memory>

using std::shared_ptr;
using std::make_shared;

BookingDB::BookingDB(int period_to_save_in_sec) :
	hotel_bookings(), m_period_to_save(period_to_save_in_sec), m_curr_time(0)
{
	//empty;
}

void BookingDB::AddNewBooking(const std::string& hotel_name, const Booking& booking) throw (BookingList::NewBookingException)
{
	BookingMapIt it = hotel_bookings.find(hotel_name);
	m_curr_time = booking.GetTime();
	if (hotel_bookings.end() != it)
	{
		it->second->AddNewBooking(booking);
	}
	else
	{
		shared_ptr<BookingList> new_booking_list = make_shared<BookingList>(m_period_to_save);
		new_booking_list->AddNewBooking(booking);
		hotel_bookings.emplace(hotel_name, new_booking_list);
	}
}

unsigned int BookingDB::GetNumOfClients(const std::string& hotel_name) const
{
	const_BookingMapIt it = hotel_bookings.find(hotel_name);
	unsigned int num_of_clients = 0;
	if (hotel_bookings.end() != it)
	{
		num_of_clients = it->second->GetNumOfClients(m_curr_time);
	}
	return num_of_clients;
}

unsigned long BookingDB::GetNumOfRooms(const std::string& hotel_name) const
{
	const_BookingMapIt it = hotel_bookings.find(hotel_name);
	unsigned int num_of_rooms = 0;
	if (hotel_bookings.end() != it)
	{
		num_of_rooms = it->second->GetNumOfRooms(m_curr_time);
	}
	return num_of_rooms;
}
