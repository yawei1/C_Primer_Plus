/*Created by Yawei Zhang 8th Oct*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define RANGE 10
#define SIZE 100

void sort(int *num, int NUM);
int get_ran_num(int range);

int main(int argc, char **argv)
{
	int *num;
	num = (int *)malloc(100 * sizeof(int));
	assert(num);
	for(int i = 0; i < SIZE; i++) {
		num[i] = get_ran_num(RANGE);	
	}
        for(int i = 0; i < SIZE; i++) {
                printf("%d, ", num[i]);
        }
	printf("\n");
	sort(num, SIZE);
	for(int i = 0; i < SIZE; i++) {
		printf("%d, ", num[i]);
	}
	printf("Done.\n");
	free(num);
	return 0;
}

int get_ran_num(int range) 
{
	int num;
	num = rand() % range + 1;
	return num;
}
void sort(int *num, int NUM)
{
	for(int i = 0; i < NUM-1; i++) {
		for (int j = i + 1; j < NUM; j++){
			int temp = num[i];
			if (num[i] < num[j]) {
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
}
