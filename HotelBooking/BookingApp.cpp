#include "BookingApp.h"
#include "BookingDB.h"
#include "RequestFactory.h"
#include "ProtocolParser.h"

BookingApp::BookingApp(std::istream& in, std::ostream& out, unsigned int saving_period_in_sec) :
	m_in(in), m_out(out), m_saving_period(saving_period_in_sec), m_num_of_requests(0)
{
	m_bookingDB = std::make_shared<BookingDB>(m_saving_period);
	std::shared_ptr<RequestFactoryInterface> request_factory = std::make_shared<RequestFactory>(std::cout, m_bookingDB);
	m_requests_parser = std::make_shared<ProtocolParser>(request_factory);
}

void BookingApp::Start(void)
{
	std::string request_buffer;

	getline(m_in, request_buffer);
	m_num_of_requests = stol(request_buffer);
	for (unsigned int i = 0; i < m_num_of_requests; i++)
	{
		getline(m_in, request_buffer);
		std::shared_ptr <Request> request = m_requests_parser->GetRequest(request_buffer);
		request->Execute();
	}
}

