/*Created by Yawei Zhang Oct 31st 2015*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
#define MAX 1000

int main(int argc, char *argv[])
{
	int line = 0;
	int i;
	char img[LEN];
	char buf[MAX];
	FILE *fp;

	printf("Enter the image file name: ");
	scanf("%s", img);

	if ((fp = fopen(img, "r")) == NULL) {
		fprintf(stderr, "Can't open file %s.\n", img);
		exit(1);
	}
	while(fgets(buf, MAX, fp) != NULL) {
		i = 0;
		while(buf[i] != '\0') {
			switch(buf[i]) {
				case '0':
					printf(" ");
					break;
				case '1':
					printf(".");
					break;
				case '2':
					printf("'");
					break;
				case '3':
					printf(":");
					break;
				case '4':
					printf("~");
					break;
				case '5':
					printf("*");
					break;
				case '6':
					printf("=");
					break;
				case '7':
					printf("&");
					break;
				case '8':
					printf("%%");
					break;
				case '9':
					printf("#");
					break;
			}
			i++;
		}
		printf("\n");
	}
	if (fclose(fp) != 0) {
		fprintf(stderr, "Error closing file.\n");
	}
	return 0;

}
