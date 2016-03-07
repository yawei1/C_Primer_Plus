/*Created by Yawei Zhang Mar 06 2016*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(int argc, char *argv[])
{
	struct book library[MAXBKS];
	int count = 0;
	int bookcount;
	int delcount = 0;
	int index, option;
	FILE * pbooks;
	int size = sizeof(struct book);

	if ((pbooks = fopen("book.txt", "r+b")) == NULL) {
		fputs("Can't open book.txt file.\n", stderr);
		exit(1);
	}
	rewind(pbooks);
	while(count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
		if(count == 0) {
			puts("Current contents of book.txt: ");
		}
		printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
		puts("You can delete or update the book information.");
		puts("Please select one option:");
		puts("1 Update     2 Delete      3 Skip");
		
		while (scanf("%d", &option) == 1 && (option < 1 || option > 3)) {
			puts("Not a valid operation.");
			puts("Please select one option:");
			puts("1 Update     2 Delete      3 Skip");
		}

  		while(getchar() != '\n') {
  			continue;
  		}

		if (option == 1) {
			char temp[MAXTITL];
			puts("Now change the titles.");
			fgets(temp, MAXTITL, stdin);
			int last = strlen(temp) - 1;
  			if(temp[last] == '\n') {
      			temp[last] = '\0';
      		}
      		strcpy(library[count].title, temp);
			puts("Now enter the author.");
			fgets(temp, MAXAUTL, stdin);
			last = strlen(temp) - 1;
  			if(temp[last] == '\n') {
      			temp[last] = '\0';
      		}
      		strcpy(library[count].author, temp);
      		puts("Now enter the value.");
      		scanf("%f", &library[count].value);
      		while(getchar() != '\n') {
      			continue;
      		}
		}
		else if (option == 2) {
			delcount++;
			printf("You have deleted the book %s by %s $ %.2f.\n", library[count].title, library[count].author, library[count].value);
			library[count].value = -1;
		}
		count++;
		puts("=========================================================");	
	}
	bookcount = count - delcount;
	if (bookcount == MAXBKS) {
		fputs("The book.txt file is full.", stderr);
		exit(2);
	}

	puts("Please add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	char temp[MAXTITL];
	fgets(temp, MAXTITL, stdin);
	int last = strlen(temp) - 1;
	if(temp[last] == '\n') {
		temp[last] = '\0';
	}
	while(temp[0] != '\0') {
		for(int i = 0; i < MAXBKS; i++) {
			if (i < bookcount && library[i].value != -1.0) {
				continue;
			}
			printf("old title %s", library[i].title);
			strcpy(library[i].title, temp);
			printf("title %s", library[i].title);
			puts("Now enter the author.");
			fgets(temp, MAXAUTL, stdin);
			int last = strlen(temp) - 1;
			if(temp[last] == '\n') {
				temp[last] = '\0';
			}
			strcpy(library[i].author, temp);
			printf("Author %s", library[i].author);
			puts("Now enter the value.");
			scanf("%f", &library[i].value);
			while(getchar() != '\n') {
				continue;
			}
			printf("Value %.2f", library[i].value);
			bookcount++;
			break;	
		}
		if(bookcount < MAXBKS) {
			puts("Enter the next title.");
			fgets(temp, MAXTITL, stdin);
			if (temp[0] == '\n') {
				break;
			}
			int last = strlen(temp) - 1;
			if(temp[last] == '\n') {
				temp[last] = '\0';
			}
		}		
	}
	fclose(pbooks);

	if ((pbooks = fopen("book.txt", "w+b")) == NULL) {
		fputs("Can't open book.txt file.\n", stderr);
		exit(1);
	}
	
	// display and write
	rewind(pbooks);
	if(bookcount > 0) {
		puts("Here is the list of your books: ");
		for (index = 0; index < bookcount; index++) {
			if(library[index].value == -1) {
				bookcount++;
				continue;
			}
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
			fwrite(&library[index], size, 1, pbooks);
		}
		
	}
	else {
		puts("No books? Too bad.\n");
	}
	puts("Bye.\n");
	fclose(pbooks);
	return 0;
}