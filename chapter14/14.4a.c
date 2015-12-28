/*Created by Yawei Zhang Dec 27th 2015*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXNAME 30



struct names {
	char firstName[MAXNAME];
	char midName[MAXNAME];
	char lastName[MAXNAME];
};

struct info {
	int ssn;
	struct names name;
};

void print(struct info people[], int count);

int main(int argc, char *argv[])
{
	int num = 5;
	struct info people[num];
	printf("Please enter 5 people's name and ssn.\n");
	for (int i = 0; i < num; i++) {
		printf("No.%d first name.\n", i+1);
		fgets(people[i].name.firstName, MAXNAME, stdin);
		size_t fnLen = strlen(people[i].name.firstName);
        if (fnLen > 0 && people[i].name.firstName[fnLen-1] == '\n')
            people[i].name.firstName[fnLen-1] = '\0';
		printf("No.%d middle name(input empty line if no middle name).\n", i+1);
		fgets(people[i].name.midName, MAXNAME, stdin);
		if (people[i].name.midName[0] == '\n') {
			people[i].name.midName[0] = '\0';
		}
		printf("No.%d last name.\n", i+1);
		fgets(people[i].name.lastName, MAXNAME, stdin);
		size_t laLen = strlen(people[i].name.lastName);
        if (laLen > 0 && people[i].name.lastName[laLen-1] == '\n')
            people[i].name.lastName[laLen-1] = '\0';
		printf("No.%d ssn.\n", i+1);
		scanf("%d", &people[i].ssn);
		while(getchar() != '\n')
			continue;		
	}

	print(people, num);
	return 0;
}

void print(struct info people[], int count)
{
	printf("========================================================\n");
	for (int i = 0; i < count; i++) {
		if (people[i].name.midName[0] == '\0') {
			printf("%s, %s - %d.\n", people[i].name.lastName, people[i].name.firstName, people[i].ssn);
		}
		else {
			printf("%s, %s %c.- %d.\n", people[i].name.lastName, people[i].name.firstName, toupper(people[i].name.midName[0]), people[i].ssn);
		}
	}
}