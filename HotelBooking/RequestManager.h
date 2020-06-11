#ifndef REQUEST_MANAGER_H
#define REQUEST_MANAGER_H

#include <iosfwd>
#include <exception>
#include <memory>
#include "BookingDBInterface.h"

class BookingDBInterface;
class ProtocolParserInterface;
class RequestFactoryInterface;

struct ProceedRequestFailure : public std::exception
{
	const char* what() const throw()
	{
		return "Failed to proceed request";
	}
};

class RequestManager
{
public:
	explicit RequestManager(const std::istream& in, const std::ostream& out, std::shared_ptr<BookingDBInterface> bookingDB, std::shared_ptr<ProtocolParserInterface> protocol_parser, std::shared_ptr<RequestFactoryInterface> factory);
	~RequestManager();
	RequestManager(const RequestManager& other_RequestManager) = delete;
	RequestManager& operator=(const RequestManager& other_RequestManager) = delete;
	void ProceedRequest(void) throw (ProceedRequestFailure);
private:
	
};

/*in ProceedRequest
call from hash table correct function
Send returning value to stream_out in needed
*/
/*
void ProceedRequest(void) throw (ProceedRequestFailure)
{
	string buffer;
	in >> buffer;
	type = protocol_parser.getType(buffer)
	request* = factory(type, buffer, out);
	request();
}
*/


#endif // !REQUEST_MANAGER_H


