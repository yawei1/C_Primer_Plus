/*Create by Yawei Zhang July 7th 2015*/
 #include <stdio.h>
#include "pe12-3a.h"

int main(void)
{
	int mode;

	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf ("%d", &mode);
	while (mode >= 0) {
		set_mode(mode);
		printf("Enter 0 for metric mode, 1 for US mode:");
		printf("(-1 to quit): ");
		scanf("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}
