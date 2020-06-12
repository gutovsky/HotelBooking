#include "RequestFactory.h"

RequestFactory::RequestFactory(std::ostream& out, std::shared_ptr<BookingDBInterface> booking_db) :
	m_out(out), m_factory_map(), RequestFactoryInterface(booking_db)
{
	//empty
}

void RequestFactory::Add(Request::RequestType type, RequestCreateFunc creation_function)
{
	m_factory_map[type] = creation_function;
}

std::shared_ptr<Request> RequestFactory::Create(const std::string& params, Request::RequestType type)
{
	if (1 == m_factory_map.count(type))
	{
		return m_factory_map[type](params, m_out, m_bookingDB);
	}
	else
	{
		throw WrongTypeException();
	}
}
