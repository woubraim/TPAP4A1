#pragma once
#include "sensor.hpp"

class temperature :public sensor
{
private:

public:
	temperature()
	{
		this->value = aleaGenVal();
		this->name = 't';
	};

	temperature(const temperature& t) {
		this->value = t.value;
		this->name = t.name;
	};

};