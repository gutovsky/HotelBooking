#pragma once

#include "ProtocolParserInterface.h"
#include "RequestFactoryInterface.h"
#include "RequestInterface.h"
#include <map>

class ProtocolParser : public ProtocolParserInterface
{
public:
	explicit ProtocolParser(std::shared_ptr<RequestFactoryInterface> factory);
	~ProtocolParser(void) = default;
	ProtocolParser(const ProtocolParser& other) = delete;
	ProtocolParser& operator=(const ProtocolParser& other) = delete;

	struct BadRequestException : public std::exception
	{
		const char* what() const throw ()
		{
			return "Bad request";
		}
	};
	std::shared_ptr<Request> GetRequest(const std::string& buffer);
private:
	Request::RequestType GetType(std::string& buffer);
	std::shared_ptr<RequestFactoryInterface> m_request_factory;
	std::map<const std::string, Request::RequestType> m_requets_types;
};

