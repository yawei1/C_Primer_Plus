/*Created by Yawei Zhang Oct 22nd 2015*/
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 20

int main(int argc, char *argv[]) 
{
	FILE *fp;
	char line[MAXLINE];

	for (int i = 1; i < argc; i++) {
		//show all files
		if ((fp = fopen(argv[i], "r")) == NULL) {
			fprintf(stderr, "Cannot open file %s.\n", argv[i]);
		}
		fprintf(stdout, "File %s: \n", argv[i]);
		while(fgets(line, MAXLINE, fp) != NULL) {
			fputs(line, stdout);
		}
		fclose(fp);
	}

	printf("%d files printed. Done.\n", argc);
	return 0;
}
