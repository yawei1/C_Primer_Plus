/*Created by Yawei Zhang Feb 28 2016*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define NAME 40
#define MAX 18
#define MAXLINE 81

struct player {
	int uni_num;
	char fname[NAME];
	char lname[NAME];
	int points;
	int rebound;
	int assists;
	int made_three;
	float three_propotion;
};

void init(struct player *players);
void get_info(struct player *players);
void cal_average(struct player *players);
void display(struct player *players);
void print(struct player *players);

int main(int argc, char *argv[])
{	
	struct player players[MAX];

	// initailize all players data
	init(players);

	// read data from files
	get_info(players);

	// calculate averages
	cal_average(players);

	// display 
	display(players);

	return 0;
}

void init(struct player *players)
{
	for(int i = 0; i < MAX; i++) {
		players[i].uni_num = -1;
		players[i].points = 0;
		players[i].rebound = 0;
		players[i].assists = 0;
		players[i].made_three = 0;
		players[i].three_propotion = 0;
	}
}

void get_info(struct player *players)
{
	FILE *fp;
	char file_name[NAME];
	printf("Enter the file name to read: ");
	scanf("%s", file_name);


	if((fp = fopen(file_name, "r")) == NULL) {
		fprintf(stderr, "Can't open file %s.\n", file_name);
		exit(EXIT_FAILURE);
	}
	
	int uni_num, points, rebound, assists, made_three;
	char fname[NAME];
	char lname[NAME];
	while(fscanf(fp,"%d %s %s %d %d %d %d\n",&uni_num, fname, lname, &points, &rebound, &assists, &made_three) == 7) {
		bool is_in = false;
		for(int i = 0; i < MAX; i++) {
			if (players[i].uni_num == uni_num) {	
				players[i].points += points;
				players[i].rebound += rebound;
				players[i].assists += assists;
				players[i].made_three += made_three;
				is_in = true;
			}
		}
		if (!is_in) {
			for(int i = 0; i < MAX; i++) {
				if (players[i].uni_num == -1) {;
					players[i].uni_num = uni_num;
					strcpy(players[i].fname, fname);
					strcpy(players[i].lname, lname);
					players[i].points += points;
					players[i].rebound += rebound;
					players[i].assists += assists;
					players[i].made_three += made_three;
					is_in = true;
					break;
				}									
			}
			
		}
		if (!is_in) {
			printf("This team has wayyyyyyy too many players. It's not fair.\n");
			exit(EXIT_FAILURE);
		}
	}

	if (fclose(fp) != 0) {
		fprintf(stderr, "Error closing file.\n");
	}
}

void cal_average(struct player *players)
{
	for(int i = 0; i < MAX; i++) {
		if(players[i].uni_num != -1) {
			players[i].three_propotion = 3.0 * players[i].made_three / (float)players[i].points;
		}
	}
}

void display(struct player *players)
{
	int total_points = 0;
	int total_rebound = 0;
	int total_assists = 0;
	int total_made_three = 0;
	float total_three_propotion = 0.0;

	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	for(int i = 0; i < MAX; i++) {
		if(players[i].uni_num != -1) {
			printf("No. %d %s %s's stats is:\n", players[i].uni_num, players[i].fname, players[i].lname);
			printf("Points %d, Rebounds %d, Assists %d, 3-Point Feild Goals %d\n3-Point Propotion in Total points %.2f\n", players[i].points, players[i].rebound, 
				players[i].assists, players[i].made_three, players[i].three_propotion);
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			total_points += players[i].points;
			total_rebound += players[i].rebound;
			total_assists += players[i].assists;
			total_made_three += players[i].made_three;
		}
	}
	if (total_points) {
		total_three_propotion = 3.0 * (float)total_made_three / (float)total_points;
	}
	printf("The stats of Golden State Warriors start line up are:\n");
	printf("Points %d, Rebounds %d, Assists %d, 3-Point Feild Goals %d\n3-Point Propotion in Total points %.2f\n", total_points,
		total_rebound, total_assists, total_made_three, total_three_propotion);
}

void print(struct player *players)
{
	for (int i = 0; i < MAX; i++) {
		printf("No. %d, %d, %s %s.\n", i, players[i].uni_num, players[i].fname, players[i].lname);
	}
}