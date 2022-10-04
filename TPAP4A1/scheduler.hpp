#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "sensor.hpp"
#include "light.hpp"
#include "humidity.hpp"
#include "sound.hpp"
#include "temperature.hpp"

using namespace std;

class scheduler
{
private:

public:
	light l;
	sound s;
	humidity h;
	temperature t;

	scheduler() {
		this->l.value = 0;
		this->l.name = 'l';
		this->s.value = 0;
		this->s.name = 's';
		this->h.value = 0;
		this->h.name = 'h';
		this->t.value = 0;
		this->t.name = 't';
	};

	scheduler(light l, sound s, humidity h, temperature t) {
		this->l.value = l.value;
		this->l.name = l.name;
		this->s.value = s.value;
		this->s.name = s.name;
		this->h.value = h.value;
		this->h.name = h.name;
		this->t.value = t.value;
		this->t.name = t.name;
	};

	scheduler(const scheduler& n) {
		this->l.value = n.l.value;
		this->l.name = n.l.name;
		this->s.value = n.s.value;
		this->s.name = n.s.name;
		this->h.value = n.h.value;
		this->h.name = n.h.name;
		this->t.value = n.t.value;
		this->t.name = n.t.name;

	};
	scheduler& operator=(const scheduler&) {};
	~scheduler() {};

	friend class sensor;

	void datarecove() { //recuperation des valeurs
		int valeur;
		char encore='O',reponse;
		
		cout << "Quel delai voulez vous entre chaque valeurs? " << endl;
		cin >> valeur;
		cout<< endl;
		cout << "Valeur actuel pour la lumiere (debut): " << this->l.value << endl;
		cout << "Valeur actuel pour l'humidite (debut): " << this->h.value << endl;
		cout << "Valeur actuel pour temperature (debut): " << this->t.value << endl;
		cout << "Valeur actuel pour son (debut): " << this->s.value << endl;

		while (encore == 'O') {

			this->l.value = l.aleaGenVal();
			this->s.value = s.aleaGenVal();
			this->h.value = h.aleaGenVal();
			this->t.value = t.aleaGenVal();

			cout << endl;
			cout << "Voulez vous afficher les nouvelles valeurs des capteurs? (O/N)" << endl;
			cin >> reponse;

			Sleep(valeur * 500);

			if (reponse == 'O') {
				cout << endl;
				cout << "Valeur nouvelle pour la lumiere (final): " << this->l.value << endl;
				cout << "Valeur nouvelle pour l'humidite (final): " << this->h.value << endl;
				cout << "Valeur nouvelle pour temperature (final): " << this->t.value << endl;
				cout << "Valeur nouvelle pour son (final): " << this->s.value << endl;

			}

			cout << endl;
			cout << "Voulez vous encore des donnees? (O/N)" << endl;
			cin >> encore;
		};

	};
};
