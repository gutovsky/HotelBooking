#ifndef REQUEST_H
#define REQUEST_H

#include "BookingDBInterface.h"
#include <iosfwd>
#include <memory>

class Request
{
public:
	enum RequestType
	{
		BOOK = 0,
		CLIENTS = 1,
		ROOMS = 2
	};

	explicit Request(std::ostream& out, std::shared_ptr<BookingDBInterface> bookingDB);
	virtual ~Request(void) = 0;
	virtual void Execute(void) = 0;
protected:
	static const int BASE10 = 10;

	static std::string GetParam(const std::string& params, unsigned int param_position);

	std::shared_ptr<BookingDBInterface> m_bookingDB;
	std::ostream& m_out;
};

#endif REQUEST_H

