/*Created by Yawei Zhang Nov 30th 2015*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int caltotal(char mon[]);

struct month {
	char name[20];
	char abbrev[4];
	int days;
	int monnumb;
};

struct month months[12] = {
	{"January", "Jan", 31, 1},
	{"February", "Feb", 28, 2},
	{"March", "Mar", 31, 3},
	{"April", "Apr", 30, 4},
	{"May", "May", 31, 5},
	{"June", "Jun", 30, 6},
	{"July", "Jul", 31, 7},
	{"August", "Aug", 31, 8},
	{"September", "Sep", 30, 9},
	{"October", "Oct", 31, 10},
	{"November", "Nov", 30, 11},
	{"December", "Dec", 31, 12},
};

int main (int argc, char *argv[])
{
	char input[10];
	int total;
	printf ("Enter the month name (empty line to quit): ");
	

	while(gets(input) != NULL && input[0] != '\0') {
		total = caltotal(input);
		if (total) {
			printf("There are %d days through %s.\n", total, input);
		}
		else
			printf("%s is not a valid input.\n", input);
		printf("Enter the month name (empty line to quit): ");
	}
	return 0;
}

int caltotal(char mon[]) 
{
	char input[10];
	int i = 1;
	int total = 0;

	if(mon[0] == '\0') 
		return 0;
	
	input[0] = toupper(mon[0]);
	while(mon[i] != '\0') {
		input[i] = tolower(mon[i]);
		i++;
	}
	input[i] = '\0';

	for(int i = 0; i < 12; i++) {
		total += months[i].days;
		if (strcmp(input, months[i].name) == 0)
			return total; 
	}
	return 0;
}