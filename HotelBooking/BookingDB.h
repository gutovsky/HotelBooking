#ifndef BOOKING_DB_H
#define BOOKING_DB_H

#include "BookingDBInterface.h"
#include "BookingList.h"
#include <map>
#include <memory>
#include "Hotel.h"

class BookingDB : public BookingDBInterface
{
public:
	typedef std::map<Hotel, std::shared_ptr<BookingList>> BookingMap;
	typedef std::map<Hotel, std::shared_ptr<BookingList>>::iterator BookingMapIt;
	typedef std::map<Hotel, std::shared_ptr<BookingList>>::const_iterator const_BookingMapIt;

	explicit BookingDB(int period_to_save_in_sec);
	~BookingDB(void) = default;
	BookingDB(const BookingDB& other_bookingDB) = delete;
	BookingDB& operator=(const BookingDB& other_bookingDB) = delete;

	void AddNewBooking(const std::string& hotel_name, const Booking& booking) throw (BookingList::NewBookingException);
	unsigned int GetNumOfClients(const std::string& hotel_name) const;
	unsigned long GetNumOfRooms(const std::string& hotel_name) const;

private:
	BookingMap hotel_bookings;
	const int m_period_to_save;
	long long m_curr_time;
};

#endif // !BOOKING_DB_H

