/*Created by Yawei Zhang Oct 26th 2015*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 81

int main(int argc, char *argv[])
{
	char input_name[LEN];
	char output_name[LEN];
	char temp[LEN];
	FILE *in, *out;
	char ch, point;
	int i = 0;
	int count = 0;

	printf("Enter the file that you want to reduce: ");
	scanf("%s", &input_name);
	if ((in = fopen(input_name, "r")) == NULL) {
		fprintf(stderr, "Can't open file %s.\n", input_name);
		exit(1);
	}
	strcpy(temp, input_name);
	point = temp[0];
	while(point != '.' && point != '\0') {
		i++;
		point = temp[i];
		
	}
	strncpy(output_name, temp, i);
	strcat(output_name, ".red");
	if ((out = fopen(output_name, "w")) == NULL) {
		fprintf(stderr, "Can't create output file.\n");
		exit(2);
	}

	while((ch = getc(in)) != EOF) {
		if (count++ % 3 == 0)
			putc(ch, out);
	}
	if (fclose(in) != 0 || fclose(out) != 0) {
		fprintf(stderr, "Error in closing files.\n");
		exit(3);
	}
	return 0;
}