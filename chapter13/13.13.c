/*Created by Yawei Zhang Nov 1st 2015*/
/*---------------------------------------
NOTE: In order to use round()
add -lm at the end of gcc compile command
-----------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define LEN 40
#define MAX 1000

int smooth(int row, int col, int img[][col], int posx, int posy);
int give_nbor(int row, int col, int img[][col], int nbor[], int posx, int posy);

int main(int argc, char *argv[])
{
	int s = 0, col = 0;
	int line = 0;
	char new_i;
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
		line++;
	}
	rewind(fp);
	
	fgets(buf, MAX, fp);
	while(buf[s] != '\0'){
		if (isdigit(buf[s]))
			col++;
		s++;
	}
	
	int IMG[line][col];
	rewind(fp);
	
	for (int i = 0; i < line; i++)
		for (int j = 0; j < col; j++) {
			fscanf(fp, "%d", &IMG[i][j]); 
		}

	for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			new_i = smooth(line, col, IMG, i, j);
			switch(new_i) {
				case 0:
					printf(" ");
					break;
				case 1:
					printf(".");
					break;
				case 2:
					printf("'");
					break;
				case 3:
					printf(":");
					break;
				case 4:
					printf("~");
					break;
				case 5:
					printf("*");
					break;
				case 6:
					printf("=");
					break;
				case 7:
					printf("&");
					break;
				case 8:
					printf("%%");
					break;
				case 9:
					printf("#");
					break;
			}
		}
		printf("\n");	
	}
	if (fclose(fp) != 0) {
		fprintf(stderr, "Error closing file.\n");
	}
	return 0;
}

int smooth(int row, int col, int img[][col], int posx, int posy)
{
	int nbor[4];
	int new_value;
	int num_nbor;
	double temp = 0.0;
	double sum = 0.0;
	num_nbor = give_nbor(row, col, img, nbor, posx, posy);
	int flag = 1;
	for (int i = 0; i < num_nbor; i++) {
		if (abs(img[posx][posy] - nbor[i]) <= 1) {
			flag = 0;
			break;
		} 
	}
	if(flag) {
		for(int i = 0; i < num_nbor; i++) {
			sum += nbor[i];
		}
		temp = sum/num_nbor;
		new_value = (int)(round(temp));
		return new_value;
	}
	else {
		return img[posx][posy];
	}
}

int give_nbor(int row, int col, int img[][col], int nbor[], int posx, int posy)
{
	int num_nbor;
	int i, j, k, l;
	i = posy - 1;
	j = posx - 1;
	k = posy + 1;
	l = posx + 1;
	
	if (0 < posx && posx < row) {
		if (0 < posy && posy < col) {
			num_nbor = 4;
			nbor[0] = img[posx][posy - 1];
			nbor[1] = img[j][posy];
			nbor[2] = img[posx][k];
			nbor[3] = img[l][posy];
		}
		else if (posy == 0) {
			num_nbor = 3;
			nbor[0] = img[j][posy];
			nbor[1] = img[posx][k];
			nbor[2] = img[l][posy];
		}
		else if (posy == col) {
			num_nbor = 3;
			nbor[0] = img[posx][i];
			nbor[1] = img[j][posy];
			nbor[2] = img[l][posy];			
		}
	}
	else if (posx == 0) {
		if (posy == 0) {
			num_nbor = 2;
			nbor[0] = img[posx][k];
			nbor[1] = img[l][posy];
		}
		else if (posy == col) {
			num_nbor = 2;
			nbor[0] = img[posx][i];
			nbor[1] = img[l][posy];
		}
		else {
			num_nbor = 3;
			nbor[0] = img[posx][i];
			nbor[1] = img[posx][k];
			nbor[2] = img[l][posy];				
		}
	}
	else if (posx == row) {
		if (posy == 0) {
			num_nbor = 2;
			nbor[0] = img[j][posy];
			nbor[1] = img[posx][k];
		}
		else if (posy == col) {
			num_nbor = 2;
			nbor[0] = img[posx][i];
			nbor[1] = img[j][posy];
		}
		else {
			num_nbor = 3;
			nbor[0] = img[posx][i];
			nbor[1] = img[j][posy];
			nbor[2] = img[posx][k];				
		}
	}
	return num_nbor;
}