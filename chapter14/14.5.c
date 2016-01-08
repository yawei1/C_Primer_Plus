/*Created by Yawei Zhang Jan 8th 2016*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXNAME 30
#define CSIZE 4

struct name {
	char firstName[MAXNAME];
	char lastName[MAXNAME];
};

struct student {
	struct name stuName;
	float grade[3];
	float avg;
};

void get_info(struct student students[], int num);
void print_info(struct student students[], int num);
void print_class_avg(struct student students[], int num);

int main(int argc, char *argv[])
{
	struct student students[CSIZE];
	get_info(students, CSIZE);
	print_info(students, CSIZE);
}

void get_info(struct student students[], int num)
{
	for (int i = 0; i < num; i++) {
		printf("Hello, please enter the student's first name: ");
		fgets(students[i].stuName.firstName, MAXNAME, stdin);
		size_t fnLen = strlen(students[i].stuName.firstName);
	    if (fnLen > 0 && students[i].stuName.firstName[fnLen-1] == '\n')
	        students[i].stuName.firstName[fnLen-1] = '\0';
	    students[i].stuName.firstName[0] = toupper(students[i].stuName.firstName[0]);

	    printf("Then, please enter the student's last name: ");
		fgets(students[i].stuName.lastName, MAXNAME, stdin);
		size_t lnLen = strlen(students[i].stuName.lastName);
	    if (lnLen > 0 && students[i].stuName.lastName[lnLen-1] == '\n')
	        students[i].stuName.lastName[lnLen-1] = '\0';
	   	students[i].stuName.lastName[0] = toupper(students[i].stuName.lastName[0]);
	    
	    printf("Enter the grades: \n");
	    float sum = 0;
	    for (int j = 0; j < 3; j++) {
	    	printf("No.%d grade: ", j+1);
	    	scanf("%f", &students[i].grade[j]);
	    	sum += students[i].grade[j];
	    	while(getchar() != '\n')
				continue;
	    }
	    students[i].avg = sum / 3;
	}
}

void print_info(struct student students[], int num)
{
	printf("Now print out each student's information\n");
	for (int i = 0; i < num; i++) {
		printf("=========================================\n");
		printf("Student %d \n", i+1);
		printf("Name: %s %s\n", students[i].stuName.firstName, students[i].stuName.lastName);
		printf("Grades: ");
		for (int j = 0; j < 3; j++) {
			printf("%.2f ", students[i].grade[j]);
		}
		printf("\n");
		printf("Average Grade: %.2f\n", students[i].avg);
	}
	print_class_avg(students, num);
}

void print_class_avg(struct student students[], int num)
{
	float class_avg[3];
	printf("=========================================\n");
	printf("The class average grades are: ");
	for(int i = 0; i < 3; i++) {
		for (int j = 0; j < num; j++){
			class_avg[i] += students[j].grade[i]; 
		}
		class_avg[i] = class_avg[i] / 3.0;
		printf("%.2f ", class_avg[i]);
	}
	printf("\n");
}