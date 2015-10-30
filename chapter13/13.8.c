/*Created by Yawei Zhang Oct 28th 2015*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char ch, ori_ch;
	int count = 0;
	FILE *fp;

	ori_ch = argv[1][0];


	if (argc < 2 || argv[1][1] != '\0') {
		fprintf(stderr, "Usage (for files): %s [character] [file 1 name] [file 2 name] ...\n", argv[0]);
		fprintf(stderr, "Usage (for command line): %s [character] [input] (empty line to end) ...\n", argv[0]);
		exit(1);
	}

	
	if (argc == 2) {
		ch = getchar();
		while (1) {
			if (ch == '\n') {
				if ((ch = getchar()) == '\n' || ((ch = getchar()) == '\0')) {
					break;
				}
			}
			if (ch == ori_ch) {
				count++;
			}
			ch = getchar();
		}
		fprintf(stdout, "Character '%c' appeared %d times in the input.\n", ori_ch, count);
	}
	else {
		for(int i = 2; i < argc; i++) {
			count = 0;
			if ((fp = fopen(argv[i], "r")) == NULL) {
				fprintf(stderr, "Can't open file %s", argv[i]);
				continue;
			}
			while ((ch = getc(fp)) != EOF) {
				if (ch == ori_ch) {
					count++;
				}
			}
			fprintf(stdout, "Character '%c' appeared %d times in file %s.\n", ori_ch, count, argv[i]);
			fclose(fp);
		}
	}

	printf("Done.\n");
	return 0;
}
