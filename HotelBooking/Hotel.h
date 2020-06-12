#pragma once

#include <string>

class Hotel
{
public:
	Hotel(const std::string& hotel_name); //non-explicit
	~Hotel(void) = default;
	Hotel(const Hotel& other_hotel) = delete;
	Hotel& operator=(const Hotel& other_hotel) = delete;

	const std::string& GetName(void) const;
private:

	const std::string m_hotel_name;
};

bool operator<(const Hotel& hotel, const Hotel& hotel2);

