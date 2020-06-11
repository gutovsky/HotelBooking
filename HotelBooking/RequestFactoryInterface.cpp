#include "RequestFactoryInterface.h"


RequestFactoryInterface::RequestFactoryInterface(std::shared_ptr<BookingDBInterface> bookingDB)
	: m_bookingDB(bookingDB)
{
	//empty
}

RequestFactoryInterface::~RequestFactoryInterface()
{
	//empty
}