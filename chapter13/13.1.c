/*Created by Yawei Zhang Oct 16th 2015*/
#include <stdio.h>
#include <stdlib.h>
#define LEN 81

int main(int argc, char*argv[])
{
	int ch;
	FILE *fp;
	long count;
	char file_name[LEN];

	printf("Enter the file name: ");
	scanf("%s", &file_name);
	if((fp = fopen(file_name, "r")) == NULL) {
		fprintf(stderr, "Can't open file %s.\n", file_name);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp))!= EOF) {
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %ld characters.\n", file_name, count);
	return 0;
}
