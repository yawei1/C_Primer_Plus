/*Created by Yawei Zhang Oct 31st 2015*/
/*-------------------------------------------
I have changed this problem a little. This
program will not only print out the lines
that contains the input string, but also 
count the number that it appears in the file.
---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 81
#define MAX 1000

int cal_count(char buf[], char string[], char *pos, int length);

int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;
	char *pos;
	char buf[MAX];
	char string[MAX];
	char file_name[LEN];

	int count = 0;
	int length = 0;
	
	if (argc != 3) {
		fprintf(stderr, "Usage: %s [string] [file name]", argv[0]);
		exit(1);
	}

	ch = argv[1][0];
	while(ch != '\0') {
		string[length] = argv[1][length];
		length++;
		ch = argv[1][length];
	}
	string[length] = '\0';
	if ((fp = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "Can't open file %s.\n", argv[2]);
		exit(2);
	}

	while(fgets(buf, MAX, fp) != NULL) {
		pos = strstr(buf, argv[1]);
		if (pos != NULL) {
			fputs (buf, stdout);
			count++;
			count += cal_count(buf, string, pos, length);
		}
	}
	printf("%s appeared %d times in file %s.\n", string, count, argv[2]);
	if (fclose(fp) != 0) {
		fprintf(stderr, "Error closing file.\n");
	}
	return 0;
}

int cal_count(char buf[], char string[], char *pos, int length)
{
	int count = 0, i = 0, j = 0, k = 0;
	char new_buf[MAX];
	char *new_pos;

	while((buf + i) != pos) {
		i++;
	}
	j = i + length;
	while(buf[j] != '\0') {
		new_buf[k] = buf[j];
		j++;
		k++;
	}
	new_buf[k] = '\0';
	new_pos = strstr(new_buf, string);
	if (new_pos != NULL) {
		count++;
		count += cal_count(new_buf, string, new_pos, length);
	}
	return count;
}
