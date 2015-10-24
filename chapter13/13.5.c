/*Created by Yawei Zhang Oct 23rd 2015*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFSIZE 1024
#define SLEN 81
void append(FILE *source, FILE *dest);

int main(int argc, char *argv[]) 
{
	FILE *fa, *fs;
	int files = 0;

	if (argc < 1) {
		fprintf(stderr, "Usage: %s [destination file] [append file 1] [append file 2]...", argv[0]);
		exit(1);
	}
	if ((fa = fopen(argv[1], "a")) == NULL) {
		fprintf(stderr, "Can't open %s.\n", argv[1]);
		exit(2);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFFSIZE) != 0) {
		fprintf(stderr, "Can't create output buffer.\n");
		exit(3);
	}
	for (int i = 2; i < argc; i++) {
		if (strcmp(argv[i], argv[1]) == 0) {
			fprintf(stderr, "Can't append file to itself.\n");
			continue;
		}
		if ((fs = fopen(argv[i], "r")) == NULL) {
			fprintf(stderr, "Can't open %s.\n", argv[i]);
			continue;
		}
		if (setvbuf(fs, NULL, _IOFBF, BUFFSIZE) != 0) {
			fputs("Can't create input buffer\n", stderr);
			continue;
		}
		append(fs, fa);
		if (ferror(fs) != 0) 
			fprintf(stderr, "Error in reading file %s.\n", argv[i]);
		if (ferror(fa) != 0)
			fprintf(stderr, "Error in writing file %s.\n", argv[1]);
		fclose(fs);
		files++;
		printf("File %s appended.\n", argv[i]);
	}
	printf("%d files appended.\n", files);
	printf("Done.\n");
	fclose(fa);
	return 0;
}

void append(FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFFSIZE];

	while((bytes = fread(temp, sizeof(char), BUFFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}
