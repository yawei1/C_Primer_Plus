/*Created by Yawei Zhang Oct 29th 2015*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40

int main(int argc, char *argv[])
{
	FILE *fp;
	int num;
	char ch[2];
	char words[MAX];
	long count, start, last;

	if((fp = fopen("words.txt", "a+")) == NULL) {
		fprintf(stdout, "Can't open \" words\" file.\n");
		exit(1);
	}
	fseek(fp, 0L, SEEK_SET);
	start = ftell(fp);
	fseek(fp, 0L, SEEK_END);
	last = ftell(fp);
	if (start != last)  {
		for (count = 1L; count < last; count++) {
			fseek(fp, -count, SEEK_END);
			ch[0] = getc(fp);
			if (isdigit(ch[0])) {
				ch[1] = '\0';
				num = atoi(ch);
				break;
			}
		}
	}
	else {
		num = 0;
	}
	printf("num: %d\n", num);
	
	puts("Enter words to add to the file: press the Enter");
	puts("key at the beginning of a line to terminate.");
	while(gets(words) != NULL && words[0] != '\0') {
		fprintf(fp, "%d %s\n", ++num, words);
	}
	puts("File contents: ");
	rewind(fp);
	while (fgets(words, MAX - 1, fp) != NULL) {
		fputs(words, stdout);
	}
	if (fclose(fp) != 0) {
		fprintf(stderr, "Error closing file.\n");
	}
	printf("Done.\n");
	return 0;
}
