/*Created by Yawei Zhang Oct 22nd 2015*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LEN 40

void copy_paste(FILE *source, FILE *dest);

int main(int argc, char *argv[])
{
	FILE *fp1;
	FILE *fp2;

	char fc[LEN];
	char fp[LEN];

	printf("Enter the name of the source file: ");
	scanf("%s", &fc);
	printf("Enter the name of the target file: ");
	scanf("%s", &fp);

	if ((fp1 = fopen(fc, "rb")) == NULL) {
		fprintf(stderr, "Can't open file %s.\n", fc);
	}
	if (strcmp(fc, fp) == 0) {
		fprintf(stderr, "Can't copy file %s to itself.\n", fc);
	}
	if ((fp2 = fopen(fp, "wb")) == NULL) {
		fprintf(stderr, "Can't open file %s.\n", fp);
	}

	copy_paste(fp1, fp2);

	fclose(fp1);
	fclose(fp2);
	printf("File %s is copied into fp2 and capitalized.\n", fc, fp);
	return 0;
}

void copy_paste(FILE *source, FILE *dest)
{
	char ch;
	ch = getc(source);
	while(ch != EOF) {
		putc(toupper(ch), dest);
		ch = getc(source);
	}
}