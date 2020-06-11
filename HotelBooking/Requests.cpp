#include "Requests.h"
#include "Booking.h"
#include <iostream>



BookRequest::BookRequest(long long int time, const std::string& hotel_name, unsigned int client_id, int room_cout, 
						std::ostream& out, std::shared_ptr<BookingDBInterface> bookingDB) :
	m_time(time), m_hotel_name(hotel_name), m_client_id(client_id), m_room_cout(room_cout), Request(out, bookingDB)
{
	//empty
}

void BookRequest::Execute(void)
{
	m_bookingDB->AddNewBooking(m_hotel_name, Booking(m_time, m_client_id, m_room_cout));
}

std::shared_ptr<Request> BookRequest::Create(const std::string& params,
	std::ostream& out, std::shared_ptr<BookingDBInterface> bookingDB)
{
	long long int time;
	std::string hotel_name;
	unsigned int client_id;
	int room_cout;

	time = GetTime(params);
	hotel_name = GetHotelName(params);
	client_id = GetClientID(params);
	room_cout = GetRoomCount(params);

	std::shared_ptr<Request> book_request = std::make_shared<BookRequest>(time, hotel_name, client_id, room_cout, out, bookingDB);
	return book_request;
}

long long int BookRequest::GetTime(const std::string& params)
{
	return std::stoll(GetParam(params, TIME_POSITION), nullptr, BASE10);
}

const std::string BookRequest::GetHotelName(const std::string& params)
{
	return GetParam(params, HOTEL_NAME_POSITION);
}

unsigned int BookRequest::GetClientID(const std::string& params)
{
	return std::stol(GetParam(params, CLIENT_ID_POSITION), nullptr, BASE10);
}

int BookRequest::GetRoomCount(const std::string& params)
{
	return std::stol(GetParam(params, ROOM_COUNT_POSITION), nullptr, BASE10);
}


void ClientsRequest::Execute(void)
{
	m_out << m_bookingDB->GetNumOfClients(m_hotel_name) << std::endl;
}

std::shared_ptr<Request> ClientsRequest::Create(const std::string& params,
	std::ostream& out, std::shared_ptr<BookingDBInterface> bookingDB)
{
	std::string hotel_name = GetHotelName(params);
	std::shared_ptr<Request> client_request = std::make_shared<ClientsRequest>(hotel_name, out, bookingDB);
	return client_request;
}

ClientsRequest::ClientsRequest(const std::string& hotel_name, std::ostream& out, std::shared_ptr<BookingDBInterface> bookingDB) :
	m_hotel_name(hotel_name), Request(out, bookingDB)
{
	//empty
}

const std::string ClientsRequest::GetHotelName(const std::string& params)
{
	return GetParam(params, HOTEL_NAME_POSITION);
}


void RoomsRequest::Execute(void)
{
	m_out << m_bookingDB->GetNumOfRooms(m_hotel_name) << std::endl;
}

std::shared_ptr<Request> RoomsRequest::Create(const std::string& params,
	std::ostream& out, std::shared_ptr<BookingDBInterface> bookingDB)
{
	std::string hotel_name = GetHotelName(params);
	std::shared_ptr<Request> client_request = std::make_shared<RoomsRequest>(hotel_name, out, bookingDB);
	return client_request;
}

RoomsRequest::RoomsRequest(const std::string& hotel_name, std::ostream& out, std::shared_ptr<BookingDBInterface> bookingDB) :
	m_hotel_name(hotel_name), Request(out, bookingDB)
{
	//empty
}

const std::string RoomsRequest::GetHotelName(const std::string& params)
{
	return GetParam(params, HOTEL_NAME_POSITION);
}



