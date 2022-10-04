#include <iostream>
#include <fstream>
#include <windows.h>
#include "serveur.hpp"
#include "scheduler.hpp"
#include "sensor.hpp"
#include "light.hpp"
#include "humidity.hpp"
#include "sound.hpp"
#include "temperature.hpp"


int main() {

	light lum;
	humidity hum;
	sound soun;
	temperature temp;

	scheduler sche(lum,soun,hum,temp);
	sche.datarecove();

	serveur serv(sche);
	serv.consoleWrite();
	serv.fileWrite();


   return 0;
}