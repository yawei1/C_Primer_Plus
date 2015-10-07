/*Created by Yawei Zhang Oct 6th 2015*/
#include <stdio.h>
int call_count;
int get_call_count(void);
int main(int argc, char *argv[])
{
	char i;
	printf("Enter if you want to call get_call_count function (y/n, q to quit):\n");
	scanf("%c", &i);
	while (i != 'q') {
		if (i == 'y')
			call_count = get_call_count();
		printf("%d\n", call_count);
		printf("Enter if you want to call get_call_count function (y/n, q to quit):\n");
		scanf("%c", &i);
	}
	return 0;
}

int get_call_count(void)
{
	call_count++;
	return call_count;
}