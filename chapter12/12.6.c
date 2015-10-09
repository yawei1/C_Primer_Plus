/*Created by Yawei Zhang Oct 8th 2015*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define SIZE 1000
#define RANGE 10
#define SEED 10

int main(int argc, char *argv[])
{
	int * count;
	count = (int *)malloc(RANGE * sizeof(int));
        assert(count);
	for (int s = 1; s <= SEED; s++) {
		for (int i = 0; i < RANGE; i++) {
			count[i] = 0;
		}
		srand(s);
		for (int i = 0; i < SIZE; i++) {
			int num = rand() % RANGE  + 1;
			for (int i = 0; i < RANGE; i++) {
				if (num == i+1) {
					count[i]++;
				}
			}
		}
		for (int i = 0; i < RANGE; i++) {
			printf("%d, ", count[i]);
		}
		printf("DONE.\n");
	}
	free(count);	
	return 0;
}


