/*Created by Yawei Zhang Oct 15th 2015*/
/* USE %lf for scanf and printf!*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	double total = 0;
	double num;
	double avg;
	FILE *fp;
	double count = 0;

	if (argc > 2) {
		printf("Usage: too many arguments.\n");
		exit(1);
	} 
	if (argc > 1) {
		if ((fp = fopen(argv[1], "r")) == NULL) {
			printf("Can't open file %s.\n", argv[1]);
			exit(2);
		}
		while (fscanf(fp, "%lf", &num) == 1) {
			total += num;
			count++;
		}
		fclose(fp);
		avg = total / count;
	}
	else {
		printf("Enter float numbers, use e as end.\n");
		while (fscanf(stdin, "%lf", &num) == 1) {
			total += num;
			count++;
		}
		avg = total / count;
	}
	printf("The average of input is %lf\n", avg);
	return 0;
}