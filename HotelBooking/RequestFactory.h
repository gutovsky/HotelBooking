#ifndef REQUEST_FACTORY_H
#define REQUEST_FACTORY_H

#include "RequestFactoryInterface.h"
#include <map>
#include <iostream>
#include "RequestInterface.h"

class RequestFactory : public RequestFactoryInterface
{
public:
	explicit RequestFactory(std::ostream& out, std::shared_ptr<BookingDBInterface> booking_db);
	~RequestFactory() = default;
	RequestFactory(const RequestFactory& other) = delete;
	RequestFactory& operator=(const RequestFactory& other) = delete;

	struct WrongTypeException : public std::exception
	{
		const char* what() const throw ()
		{
			return "Type is unknown";
		}
	};

	void Add(Request::RequestType type, RequestFactoryInterface::RequestCreateFunc creation_function);
	std::shared_ptr<Request> Create(const std::string& params, Request::RequestType type) throw (WrongTypeException);

private:
	typedef std::map<Request::RequestType, RequestCreateFunc> FactoryMap;
	FactoryMap m_factory_map;
	std::ostream& m_out;
};

#endif // !REQUEST_FACTORY_H
