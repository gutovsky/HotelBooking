#pragma once

#include <memory>
#include <functional>
#include <string>
#include "RequestInterface.h"
#include "BookingDBInterface.h"

class RequestFactoryInterface
{
public:
	typedef std::function< std::shared_ptr<Request>(const std::string&, std::ostream&, std::shared_ptr<BookingDBInterface>)> RequestCreateFunc;

	explicit RequestFactoryInterface(std::shared_ptr<BookingDBInterface> m_bookingDB);
	virtual ~RequestFactoryInterface() = 0;

	virtual void Add(Request::RequestType type, RequestCreateFunc creation_function) = 0;
	virtual std::shared_ptr<Request> Create(const std::string& params, Request::RequestType type) = 0;
protected:
	std::shared_ptr<BookingDBInterface> m_bookingDB;
	RequestFactoryInterface(const RequestFactoryInterface& other) = default;
	RequestFactoryInterface& operator=(const RequestFactoryInterface& other) = default;
};

inline RequestFactoryInterface::~RequestFactoryInterface(void) { }