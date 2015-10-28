/*Created by Yawei Zhang 10 26th 2015*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 81
#define MAXLINE 1000

int print_line(FILE *source, int i);

int main(int argc, char *argv[]) 
{
	char file1[LEN];
	char file2[LEN];
	int i = 0, j = 0;
	FILE *fp1, *fp2;

	printf("This program will print two files line by line in turn.\n");
	printf("Enter the first file name: ");
	scanf("%s", &file1);
	printf("Enter the second file name: ");
	scanf("%s", &file2);

	if ((fp1 = fopen(file1, "r")) == NULL) {
		fprintf(stderr, "Can't open %s.\n", file1);
		exit(1);
	}
	if ((fp2 = fopen(file2, "r")) == NULL) {
		fprintf(stderr, "Can't open %s.\n", file2);
		exit(2);
	}

	while (i == 0 || j == 0) {
		if (i == 0) {
			i = print_line(fp1, i);
		}
		if (j == 0) {
			j = print_line(fp2, j);
		}
	}
	fclose(fp1);
	fclose(fp2);
	printf("Done.\n");
	return 0;
}

int print_line(FILE *source, int i)
{
	char line[MAXLINE];
	if (fgets(line, MAXLINE, source) != NULL) {
		fputs(line, stdout);
		return i;
	}
	i = 1;
	return i;

}