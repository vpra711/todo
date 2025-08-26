#include <stdio.h>
#include <stdlib.h>

void load_file(char *filename);
void save_file(char *filename);
void display();

char *buffer;

int main()
{
	int operation = 0;
	char filename[50];
	while(1)
	{
		operation = 0;
		scanf("%d", &operation);

		switch(operation)
		{
			case 1:
				printf("\nenter file to load: ");
				scanf("%s", filename);
				load_file(filename);
				break;
			case 2:
				printf("\nenter file to write: ");
				scanf("%s", filename);
				save_file(filename);
				break;
			case 3:
				display();
		}
	}
	return 0;
}

void load_file(char *filename)
{
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("\nunable to open the file in read mode");
		return;
	}

	fseek(file, 0, SEEK_END);
	unsigned long file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	buffer = (char *) malloc(sizeof(file_size));
	if (buffer == NULL)
	{
		printf("\ncannot allocate memory - file is too large (or) you dont have ram");
		fclose(file);
		return;
	}

	if(fgets(buffer, file_size, file) == NULL)
	{
		printf("\nunable to read contents of tbe file");
		return;
	}
	
	fclose(file);
}

void save_file(char *filename)
{
	FILE *file = fopen(filename, "w");
	if (file == NULL)
	{
		printf("\nunable to open file in write mode");
		return;
	}

	if (buffer == NULL)
	{
		printf("\nbuffer is null");
		fclose(file);
		return;
	}

	fputs(buffer, file);
	fclose(file);
}

void display()
{
	if (buffer == NULL)
	{
		printf("\nbuffer is empty");
		return;
	}

	printf("%s", buffer);
}
