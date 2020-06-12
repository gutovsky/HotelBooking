#pragma once

#include <iostream>
#include <memory>
#include "BookingDBInterface.h"
#include "ProtocolParserInterface.h"

class BookingApp
{
public:
	explicit BookingApp(std::istream& in = std::cin, std::ostream& out = std::cout, unsigned int saving_period_in_sec = DEFAULT_SAVING_PERIOD_IN_SEC);
	~BookingApp(void) = default;
	BookingApp& operator=(const BookingApp&) = delete;
	BookingApp(const BookingApp&) = delete;
	void Start(void);

private:
	static const int DEFAULT_SAVING_PERIOD_IN_SEC = 86400;

	std::istream& m_in;
	std::ostream& m_out;
	std::shared_ptr<BookingDBInterface> m_bookingDB;
	std::shared_ptr<ProtocolParserInterface> m_requests_parser;
	unsigned int m_num_of_requests;
	unsigned int m_saving_period;
};

