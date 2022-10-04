#pragma once
#include "sensor.hpp"

class sound:public sensor
{
private:

public:
	sound()
	{
		this->value = aleaGenVal();
		this->name = 's';
	};
	
	sound(const sound& s) {
		this->value = s.value;
		this->name = s.name;
	};

};