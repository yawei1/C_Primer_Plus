/*Created by Yawei Zhang Oct 31st 2015*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
#define MAX 1000

int main(int argc, char *argv[])
{
	FILE *fp;
	long pos, last = 0;
	char ch;
	char file_name[LEN];
	char buf[MAX];
	

	printf("Enter the file name you want to open: ");
	scanf("%s", &file_name);
	if ((fp = fopen(file_name, "rb")) == NULL) {
		fprintf(stderr, "Can't open file %s.\n", file_name);
		exit(1);
	}
	fseek(fp, 0L, SEEK_END);
	last = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	printf("Enter a position between 0-%ld (a letter to quit):", last);
	while(scanf("%ld", &pos) != 0) {
		fseek(fp, pos, SEEK_SET);
		fgets(buf, MAX, fp);
		fputs(buf, stdout);
		printf("Enter a position between 0-%ld (a letter to quit):", last);
	}

	if(fclose(fp) != 0)
		fprintf(stderr, "Error closing file.\n");
	return 0;
}
