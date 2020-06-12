#pragma once

#include "RequestInterface.h"
#include <string>

class BookRequest : public Request
{
public:
	~BookRequest(void) = default;
	void Execute(void);
	static std::shared_ptr<Request> Create(const std::string& params,
		std::ostream& out, std::shared_ptr<BookingDBInterface> bookingDB);
	BookRequest(long long int time, const std::string& hotel_name, unsigned int client_id, int room_cout,
		std::ostream& out, std::shared_ptr<BookingDBInterface> bookingDB);
private:
	long long int m_time;
	const std::string m_hotel_name;
	unsigned int m_client_id;
	int m_room_cout;

	static const int TIME_POSITION = 1;
	static const int HOTEL_NAME_POSITION = 2;
	static const int CLIENT_ID_POSITION = 3;
	static const int ROOM_COUNT_POSITION = 4;

	static long long int GetTime(const std::string& params);
	static const std::string GetHotelName(const std::string& params);
	static unsigned int GetClientID(const std::string& params);
	static int GetRoomCount(const std::string& params);
};

class ClientsRequest : public Request
{
public:
	~ClientsRequest(void) = default;
	void Execute(void);
	static std::shared_ptr<Request> Create(const std::string& params,
		std::ostream& out, std::shared_ptr<BookingDBInterface> bookingDB);
	ClientsRequest(const std::string& hotel_name, std::ostream& out, std::shared_ptr<BookingDBInterface> bookingDB);
private:
	const std::string m_hotel_name;

	static const int HOTEL_NAME_POSITION = 1;

	static const std::string GetHotelName(const std::string& params);
};

class RoomsRequest : public Request
{
public:
	~RoomsRequest(void) = default;
	void Execute(void);
	static std::shared_ptr<Request> Create(const std::string& params,
		std::ostream& out, std::shared_ptr<BookingDBInterface> bookingDB);
	RoomsRequest(const std::string& hotel_name, std::ostream& out, std::shared_ptr<BookingDBInterface> bookingDB);
private:
	const std::string m_hotel_name;

	static const int HOTEL_NAME_POSITION = 1;

	static const std::string GetHotelName(const std::string& params);
};

