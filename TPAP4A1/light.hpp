#pragma once
#include "sensor.hpp"
class light:public sensor
{
private:

public:
	light()
	{
		this->value = aleaGenVal();
		this->name = 'l';
	};
	light(const light& l)
	{
		this->value = l.value;
		this->name = l.name;
	};
};