#include "ProtocolParser.h"
#include "Requests.h"

ProtocolParser::ProtocolParser(std::shared_ptr<RequestFactoryInterface> factory) :
	m_request_factory(factory), m_requets_types()
{
	m_request_factory->Add(Request::BOOK, BookRequest::Create);
	m_request_factory->Add(Request::CLIENTS, ClientsRequest::Create);
	m_request_factory->Add(Request::ROOMS, RoomsRequest::Create);

	m_requets_types["BOOK"] = Request::BOOK;
	m_requets_types["CLIENTS"] = Request::CLIENTS;
	m_requets_types["ROOMS"] = Request::ROOMS;
}

std::shared_ptr<Request> ProtocolParser::GetRequest(const std::string& buffer)
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

	try
	{
		return m_requets_types[key];
	}
	catch (const std::exception&)
	{
		throw BadRequestException();
	}
}


