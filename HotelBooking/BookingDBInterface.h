#ifndef BOOKING_DB_INTERFACE_H
#define BOOKING_DB_INTERFACE_H

#include <string>

class Booking;

class BookingDBInterface
{
public:
	BookingDBInterface(void) = default;
	virtual ~BookingDBInterface(void) = 0;

	virtual void AddNewBooking(const std::string& hotel_name, const Booking& booking) = 0;
	virtual unsigned int GetNumOfClients(const std::string& hotel_name) const = 0;
	virtual unsigned long GetNumOfRooms(const std::string& hotel_name) const = 0;
protected:
	BookingDBInterface(const BookingDBInterface& other_bookingDB) = default;
	BookingDBInterface& operator=(const BookingDBInterface& other_bookingDB) = default;
};

#endif // !BOOKING_DB_INTERFACE_H