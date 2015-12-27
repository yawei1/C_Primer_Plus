/*Created by Yawei Zhang Dec 25th 2015*/
#include <stdio.h>
#include <string.h>

#define MAXTITLE 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
	char title[MAXTITLE];
	char author[MAXAUTL];
	float value;
};

void order_print(struct book library[], int count);
void str_print(struct book library[], int count);
void value_print(struct book library[], int count);
void str_sort_book(struct book *books[], int count);
void value_sort_book(struct book *books[], int count);



int main(int argc, char *argv[]) 
{
	struct book library[MAXBKS];
	int count = 0;

	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");

	while(count < MAXBKS && fgets(library[count].title, MAXTITLE, stdin) != NULL && library[count].title[0] != '\n') {
		size_t titleLen = strlen(library[count].title);
        if (titleLen > 0 && library[count].title[titleLen-1] == '\n')
            library[count].title[titleLen-1] = '\0';

		printf("Now enter the author.\n");
		fgets(library[count].author, MAXAUTL, stdin);
		size_t authorLen = strlen(library[count].author);
        if (authorLen > 0 && library[count].author[authorLen-1] == '\n')
            library[count].author[authorLen-1] = '\0';

		printf("Now enter the value.\n");
		scanf("%f", &library[count++].value);
		while(getchar() != '\n')
			continue;
		if (count < MAXBKS)
			printf("enther the next title.\n");
	}
	if (count > 0) {
		printf("=========================================================\n");
		order_print(library, count);
		printf("=========================================================\n");
		str_print(library, count);
		printf("=========================================================\n");
		value_print(library, count);
	}
	else
		printf("No books? Too bad.\n");

	return 0;
}

void order_print(struct book library[], int count)
{
	printf("Here is your book list(input order).\n");
	for (int i = 0; i < count; i++) {
		printf("%s by %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
	}

}

void str_print(struct book library[], int count)
{
	printf("Here is your book list(title order).\n");

	// define the pointers
	struct book *books[count];

	for (int i = 0; i < count; i++) {
		books[i] = &library[i];
	} 
	str_sort_book(books, count);
	for (int i = 0; i < count; i++) {
		printf("%s by %s: $%.2f\n", books[i]->title, books[i]->author, books[i]->value);
	}
}

void value_print(struct book library[], int count)
{
	printf("Here is your book list(value order).\n");
	struct book *books[count];
	for (int i = 0; i < count; i++) {
		books[i] = &library[i];
	} 
	value_sort_book(books, count);
	for (int i = 0; i < count; i++) {
		printf("%s by %s: $%.2f\n", books[i]->title, books[i]->author, books[i]->value);
	}
}

void str_sort_book(struct book *books[], int count)
{
	struct book *temp;
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (strcmp(books[i]->title, books[j]->title) > 0) {
				temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}
		}
	}
}

void value_sort_book(struct book *books[], int count)
{
	struct book *temp;
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (books[i]->value > books[j]->value) {
				temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}
		}
	}

}