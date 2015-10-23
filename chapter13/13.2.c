/*Created by Yawei Zhang Oct 22nd 2015*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
#define BUFFSIZE 1024

void copy_paste(FILE *source, FILE *dest);

int main(int argc, char *argv[])
{
	char cp_name[LEN];
	char paste_name[LEN];

	FILE *fp1;
	FILE *fp2;

	if (argc != 3) {
		printf("Usage: %s [copy file name] [paste file name]\n", argv[0]);
		exit(1);
	}
	if ((fp1 = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open file %s", argv[1]);
		exit(2);
	}
	if (strcmp(cp_name, paste_name) == 0) {
		fprintf(stderr, "Can't copy file to itself.\n");
	}
	if ((fp2 = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open file %s.\n", argv[2]);
	}
	if (setvbuf(fp1, NULL, _IOFBF, BUFFSIZE) != 0) {
		fputs("Can't create input buffer\n", stderr);
	}
	copy_paste(fp1, fp2);

	fclose(fp1);
	fclose(fp2);
	printf("%s is copied into %s\n.", argv[1], argv[2]);
	return 0;
}

void copy_paste(FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFFSIZE];
	while ((bytes = fread(temp, sizeof(char), BUFFSIZE, source)) > 0) 
		fwrite (temp, sizeof(char), bytes, dest);
}