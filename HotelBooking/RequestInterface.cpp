#include "RequestInterface.h"

Request::Request(std::ostream& out, std::shared_ptr<BookingDBInterface> bookingDB) :
	m_bookingDB(bookingDB), m_out(out)
{
	//empty;
}

Request::~Request()
{
	//empty
}

std::string Request::GetParam(const std::string& params, unsigned int param_position)
{
	std::string param_required;

	size_t current = 0, prev = 0;
	current = params.find(" ");
	for (unsigned int i = 0; i < param_position; i++)
	{
		prev = current + 1;
		current = params.find(" ", prev);
	}

	param_required = params.substr(prev, current - prev);
	return param_required;
}
