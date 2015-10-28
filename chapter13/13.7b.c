/*Created by Yawei Zhang Oct 27th 2015*/
#include <stdio.h>
#include <stdlib.h>
#define LEN 81
#define MAXLINE 1000

int print_line1(FILE *source, int i);
int print_line2(FILE *source, int i);

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	int i = 0;
	int j = 0;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s [file 1 name] [file 2 name]", argv[0]);
		exit(1);
	}

	if ((fp1 = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s.\n", argv[1]);
		exit(2);
	}
	if ((fp2 = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "Can't open %s.\n", argv[2]);
		exit(3);
	}

	while (i == 0 || j == 0) {
		if (i == 0) {
			i = print_line1(fp1, i);				
		}
		if (i == 0 && j == 0) {
			printf("  ");
		}
		if (j == 0) {
			j = print_line2(fp2, j);
		} 
		if (j != 0 && i == 0) {
			printf("\n");
		}
	}
	fclose(fp1);
	fclose(fp2);
	printf("Done.\n");
	return 0;
}

int print_line1(FILE *source, int i)
{
	char line[MAXLINE];
	char ch;
	int s = 0;
	if (fgets(line, MAXLINE, source) != NULL) {
		ch = line[s];
		while(ch != '\0') {
			s++;
			ch = line[s];
		} 
		line[s-1] = '\0';
		fputs(line, stdout);
		return i;
	}
	i = 1;
	return i;

}

int print_line2(FILE *source, int i)
{
	char line[MAXLINE];
	if (fgets(line, MAXLINE, source) != NULL) {
		fputs(line, stdout);
		return i;
	}
	i = 1;
	return i;

}