/*Created by Yawei Zhang Oct 16th 2015*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 81
int main(int argc, char *argv[])
{
	char sen[MAX];

	if (argc != 3) {
		fprintf(stderr, "Usage: %s [keyword] [filename].\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	FILE *fp;
	if ((fp = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, " Cannot open file \"%s\"\n", argv[2]);
		exit(EXIT_FAILURE);
	}
 	while (fgets(sen, MAX, fp) != NULL) {
		for (int i = 0; i < MAX; i++) {
			if (sen[i] == '\0')
				break;
			if (sen[i] == argv[1][0]) {
				fputs(sen, stdout);
				break;
			}
		}
	}
	fclose(fp);
	return 0;
}
