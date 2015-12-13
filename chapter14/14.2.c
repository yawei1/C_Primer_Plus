/*Created by Yawei Zhang Dec 10th 2015*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// standlize the month name, return the index of the month
int standard(char mon[]);

// validation the input
int validMonth(int monidx);

// return the days of that months
int obtainDays(int monidx);

// check if that year is a leap year
int leapYear(int year);

// calculate total days until that day that year
int calTotal(int monidx, int date, int isleap);


struct month {
	char name[20];
	char abbrev[4];
	int days;
	int monnum;
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
	int date;
	char input[10];
	char mon[10];
	int monidx;
	int year;
	int days;
	int isleap;
	int total;

	// obtain a year
	printf("Enter the year(empty line to quit): ");

	while(fgets(input, 10, stdin) != NULL && input[0] != '\n') {

		if (!isdigit(input[0])) {
			printf("%s is not a valid year. Enter the year again(empty line to quit): ", input);
			continue;
		}
		year = atoi(input);

		// check if that year is a leap year
		isleap = leapYear(year);
		

		// obtain a valid month
		printf ("Enter the month (number, name or abbreviation): ");
		
		int f;
		while(fgets(mon, 10, stdin) == NULL || input[0] == '\n' || !(validMonth(monidx = standard(mon)))) {
			printf("Not a valid input, enter the month (number, name or abbreviation): ");
			// printf("%d\n",f);
		}
		// printf("%d\n",f);

		// transfer the input to month idx
		// monidx = standard(mon);
		
		// obtain a valid date
		// days = obtainDays(monidx);
		printf("Enter the date (1-%d): ",obtainDays(monidx));
		while(scanf("%d", &date) <= 0) {
			if (isleap && monidx == 2) {
				printf("Not a valid date, please input a valid date(1-29): ");
			}
			printf("Not a valid date, please input a valid date(1-%d): ", obtainDays(monidx));
		}

		// calculate the days
		total = calTotal(monidx, date, isleap);

		// print the results
		if (total) {
			int lastDigit = date % 10;
			if (lastDigit == 1) {
				printf("There are %d day(s) through %s %dst from begining of %d.\n", total, months[monidx].name, date, year);
			}
			else if(lastDigit == 2) {
				printf("There are %d day(s) through %s %dnd from begining of %d.\n", total, months[monidx].name, date, year);
			}
			else if (lastDigit == 3) {
				printf("There are %d day(s) through %s %drd from begining of %d.\n", total, months[monidx].name, date, year);
			}
			else
				printf("There are %d day(s) through %s %dth from begining of %d.\n", total, months[monidx].name, date, year);
		}
		else
			printf("Oops, I ate too much today.\n");

		while(getchar() != '\n')
			continue;
		// Do it again
		printf("Enter the year(empty line to quit): ");
	}
	return 0;
}

int standard(char mon[])
{
	if (isdigit(mon[0])) {
		size_t s = strlen(mon);
		mon[s-1] = '\0';
		//find the month according to its index
		int m = atoi(mon);
		return m-1;
	}
	else {
		// lowcase the month name
		size_t s = strlen(mon);
		mon[s-1] = '\0';
		int i = 0;
		while(mon[i] != '\0') {
			mon[i] = tolower(mon[i]);
			i++;
		}
		// upcase the fist letter
		mon[0] = toupper(mon[0]);

		if (i > 3) {
			//compare with the whole months' names
			for(int j = 0; j < 12; j++) {
				if (strcmp(mon, months[j].name) == 0) {
				    return j;
				}
			}
		}
		else {
			for(int j = 0; j < 12; j++) {
				if (strcmp(mon, months[j].abbrev) == 0) {
					return j;
				}
			}
		}
	}
	return -1;
}

int validMonth(int monidx)
{
	if (monidx >= 0 && monidx < 12) {
		return 1;
	}
	else {
		return 0;
	}
}

int obtainDays(int monidx)
{
	return months[monidx].days;
}

int leapYear(int year)
{
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return 1;
			}
			return 0;
		}
		return 1;
	}
	return 0;
}

int calTotal(int monidx, int date, int isleap) 
{
	int total = 0;
	for(int i = 0; i < monidx; i++) {
		total += months[i].days;
	}
	total += date;
	if (isleap && monidx > 1) {
		return ++total;
	}
	else
		return total;
}