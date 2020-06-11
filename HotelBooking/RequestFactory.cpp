#include "RequestFactory.h"
/*
class RequestFactory : public RequestFactoryInterface
{
public:
	typedef std::function< std::shared_ptr<Request>(const std::string&, const std::ostream&)> RequestCreateFunc;

	RequestFactory(const std::ostream&);
	~RequestFactory();
	RequestFactory(const RequestFactory& other) = delete;
	RequestFactory& operator=(const RequestFactory& other) = delete;

	void Add(Request::RequestType type, RequestCreateFunc creation_function);
	std::shared_ptr<Request> Create(const std::string& params, Request::RequestType type);

private:
	typedef std::map<Request::RequestType, RequestCreateFunc> FactoryMap;
	FactoryMap m_factory_map;
	const std::ostream m_out;
};*/

RequestFactory::RequestFactory(std::ostream& out, std::shared_ptr<BookingDBInterface> booking_db) :
	m_out(out), m_factory_map(), RequestFactoryInterface(booking_db)
{
	//empty
}

void RequestFactory::Add(Request::RequestType type, RequestCreateFunc creation_function)
{
	m_factory_map[type] = creation_function;
}

std::shared_ptr<Request> RequestFactory::Create(const std::string& params, Request::RequestType type) throw (WrongTypeException)
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
