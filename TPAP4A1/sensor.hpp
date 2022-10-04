#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <random>
#include <time.h>

using namespace std;

class sensor
{
private:

public:
	int value;
	char name;

	sensor() //constructeur par défaut
	{
		this->value = 0;
		this->name = 'a';
	};
	sensor(int nombre, char lettre) //constructeur paramétré
	{
		this->value = nombre;
		this->name = lettre;
	};
	sensor(char lettre) //constructeur paramétré
	{
		this->value = aleaGenVal();
		this->name = lettre;
	};
	sensor(const sensor &s) { //constructeur par recopie
		this->value = s.value;
		this->name = s.name;
	};
	//sensor& operator=(const sensor&) {};
	~sensor() {};
	

	int aleaGenVal() {
		//srand((unsigned int)time(0));
		return rand() % 50;
	}
	

	
	friend class scheduler;
};



