#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "sensor.hpp"
#include "light.hpp"
#include "humidity.hpp"
#include "sound.hpp"
#include "temperature.hpp"
#include "scheduler.hpp"

using namespace std;

class serveur
{
private:


public:
	light l;
	sound s;
	humidity h;
	temperature t;
	scheduler sc;

	serveur() {
		this->l.value = 0;
		this->l.name = 'l';
		this->s.value = 0;
		this->s.name = 's';
		this->h.value = 0;
		this->h.name = 'h';
		this->t.value = 0;
		this->t.name = 't';
	};


	serveur(temperature t, sound s, humidity h, light l) {
		this->t = t;
		this->h = h;
		this->l = l;
		this->s = s;
	};

	serveur(scheduler schedu) {
		this->t = schedu.t;
		this->h = schedu.h;
		this->l = schedu.l;
		this->s = schedu.s;
	};

	serveur(const serveur&) {

	};
	serveur& operator=(const serveur&) {};
	~serveur() {};

	void consoleWrite() {

		std::cout << "La valeur de la temperature est de " << this->t.value << endl;
		std::cout << "La valeur de l'humidité est de " << this->h.value << endl;
		std::cout << "La valeur de la lumiere est de " << this->l.value << endl;
		std::cout << "La valeur du son est de " << this->s.value << endl;
	};


	void fileWrite() {
		char reponse;

		cout << endl;
		cout << "Voulez vous enregistrer la valeur du capteur sound au sein d'un fichier log? (O/N)" << endl;
		cin >> reponse;

		if (reponse == 'O') {
			string const fichiersound("C:/Users/OUBRAIM/fichiersound.txt");
			ofstream fluxsound(fichiersound.c_str());

			if (fluxsound)
			{
				fluxsound << "Voici les valeurs du son:" << endl;
				fluxsound << "Le son est de " << s.value << "." << endl;
			}
			else
			{
				cout << "ERREUR: Impossible d'ouvrir le fichier sound." << endl;
			}
		}

		cout << endl;
		cout << "Voulez vous enregistrer la valeur du capteur temperature au sein d'un fichier log? (O/N)" << endl;
		cin >> reponse;
		
		if (reponse == 'O') {
			string const fichiertemperature("C:/Users/OUBRAIM/fichiertemperature.txt");
			ofstream fluxtemperature(fichiertemperature.c_str());

			if (fluxtemperature)
			{
				fluxtemperature << "Voici les valeurs de la temperature:" << endl;
				fluxtemperature << "La temperature est de " << t.value << "." << endl;
			}
			else
			{
				cout << "ERREUR: Impossible d'ouvrir le fichier temperature." << endl;
			}
		}

		cout << endl;
		cout << "Voulez vous enregistrer la valeur du capteur light au sein d'un fichier log? (O/N)" << endl;
		cin >> reponse;

		if (reponse == 'O') {
			string const fichierlight("C:/Users/OUBRAIM/fichierlight.txt");
			ofstream fluxlight(fichierlight.c_str());

			if (fluxlight)
			{
				fluxlight << "Voici les valeurs de la light:" << endl;
				fluxlight << "Le lumière est de " << l.value << "." << endl;
			}
			else
			{
				cout << "ERREUR: Impossible d'ouvrir le fichier light." << endl;
			}
		}

		cout << endl;
		cout << "Voulez vous enregistrer la valeur du capteur humidity au sein d'un fichier log? (O/N)" << endl;
		cin >> reponse;

		if (reponse == 'O') {
			string const fichierhumidity("C:/Users/OUBRAIM/fichierhumidity.txt");
			ofstream fluxhumidity(fichierhumidity.c_str());

			if (fluxhumidity)
			{
				fluxhumidity << "Voici les valeurs de l'humidité: " << endl;
				fluxhumidity << "l'humidité est de " << h.value << "." << endl;
			}
			else
			{
				cout << "ERREUR: Impossible d'ouvrir le fichier humidité." << endl;
			}
		}
	};

	friend class scheduler;
};

