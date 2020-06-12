#pragma once

#include <string>
#include <memory>

class Request;
class RequestFactoryInterface;

class ProtocolParserInterface
{
public:
	ProtocolParserInterface(void) = default;
	virtual ~ProtocolParserInterface(void) = 0;
	virtual std::shared_ptr<Request> GetRequest(const std::string& buffer) = 0;
protected:
	ProtocolParserInterface(const ProtocolParserInterface& otherB) = default;
	ProtocolParserInterface& operator=(const ProtocolParserInterface& other) = default;
};

inline ProtocolParserInterface::~ProtocolParserInterface(void) { }