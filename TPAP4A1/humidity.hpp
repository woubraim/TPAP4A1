#pragma once
#include "sensor.hpp"

class humidity :public sensor
{
private:

public:
	humidity() {
		this->value = aleaGenVal();
		this->name = 'h';
	};
	humidity(const humidity& h) {
		this->value = h.value;
		this->name = h.name;
	};
};