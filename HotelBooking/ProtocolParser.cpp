#include "ProtocolParser.h"
#include "Requests.h"

/*
class ProtocolParser : public ProtocolParserInterface
{
public:
	ProtocolParser(std::shared_ptr<RequestFactoryInterface> factory);
	~ProtocolParser(void);
	Request* GetRequest(const std::string& buffer);
private:
	//GetType();
};
*/

ProtocolParser::ProtocolParser(std::shared_ptr<RequestFactoryInterface> factory) :
	m_request_factory(factory)
{
	m_request_factory->Add(Request::BOOK, BookRequest::Create);
	m_request_factory->Add(Request::CLIENTS, ClientsRequest::Create);
	m_request_factory->Add(Request::ROOMS, RoomsRequest::Create);
}

std::shared_ptr<Request> ProtocolParser::GetRequest(const std::string& buffer) throw (ProtocolParser::BadRequestException)
{
	std::string new_buffer(buffer);
	Request::RequestType type = GetType(new_buffer);
	return (m_request_factory->Create(new_buffer, type));
}

Request::RequestType ProtocolParser::GetType(std::string& buffer)
{
	std::string key;
	size_t position = 0;
	position = buffer.find(" ");
	key = buffer.substr(0, position);

	if (key == "BOOK")
	{
		return Request::BOOK;
	}
	else if (key == "CLIENTS")
	{
		return Request::CLIENTS;
	}
	else if (key == "ROOMS")
	{
		return Request::ROOMS;
	}
	else
	{
		throw BadRequestException();
	}
}


