#include <stdio.h>
#include "pe12-3a.h"

void set_mode(int input)
{
	int mode;
	if (input == 0) {
		mode = 0; 
	}
	else if (input == 1) {
		mode = 1;
	}
	else if (input > 1) {
		printf("Invalid mode specified. Mode 1 (US) used.\n");
		mode = 1;
	}
	get_info(mode);
}

void get_info(int mode) 
{
	float distance;
	float fuel;
	if (mode == 0) {
		printf ("Enter distance traveled in kilometers: ");
		scanf ("%f", &distance);
		printf ("Enter fuel consumed in liters: ");
		scanf ("%f", &fuel);
	}
	if (mode == 1) {
		printf ("Enter distnace traveled in miles: ");
		scanf ("%f", &distance);
		printf ("Enter fuel consumed in gallons: ");
		scanf ("%f", &fuel);
	}
	show_info(mode, distance, fuel);
}

void show_info(int mode, float distance, float fuel)
{
	float lph;
	float mpg;
	if (mode == 0) {
		lph = fuel / distance * 100;
		printf ("Fuel consumption is %.2f liters per 100 km.\n", lph);
	}
	else if (mode == 1) {
		mpg = distance / fuel;
		printf ("Fuel consumption is %.1f miles per gallon.\n", mpg);
	}
}
