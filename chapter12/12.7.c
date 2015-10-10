/*Created by Yawei Zhang Oct 9th 2015*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int roll_n_dice(int dice, int sides);
int rollem(int sides);

int main(int argc, char *argv[])
{
	int dice, roll;
	int sides;
	char sets;

	
	printf("Enter the number of sets; enter q to stop.\n");
	while(scanf("%d", &sets)) {
		int *res;
		res = (int *)malloc(sets * sizeof(int));
		srand((unsigned int)time(0));
		printf("How many sides and how many dice?\n");
		scanf("%d", &sides);
		scanf("%d", &dice);
		printf("Here are %d sets of %d %d-sided throws:\n", sets, dice, sides);
		for (int i = 0; i < (int)sets; i++) {
			res[i] = roll_n_dice(dice, sides);
			printf("%d ", res[i]);
		}
		printf("\n");
		free(res);
		printf("Enter the number of sets; enter q to stop.\n");
	}
}

int roll_n_dice(int dice, int sides)
{
	int d;
	int total = 0;
	if (sides < 2) {
		printf("Need at least 2 sides.\n");
		return -2;
	} 
	if (dice < 1) {
		printf("Need at least 1 die.\n");
	}
	for (d = 0; d < dice; d++) 
		total += rollem(sides);

	return total;
}

int rollem(int sides)
{
	
	int roll; 
	roll = rand() % sides + 1;
	return roll;
}