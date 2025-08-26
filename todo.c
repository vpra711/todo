#include <stdio.h>
#include <stdlib.h>

void load_file();
void save_file();
void display();

char *buffer;
char *filename;

int main(int argc, char *argv[])
{
	int operation = 0;
	if (argc != 2)
	{
		printf("\ninvalid input");
		return 0;
	}

	filename = argv[1];

	while(1)
	{
		operation = 0;
		printf("\nwaiting for operation: ");
		scanf("%d", &operation);

		switch(operation)
		{
			case 1:
				load_file();
				break;
			case 2:
				save_file();
				break;
			case 3:
				display();
		}
	}
	return 0;
}

void create_new_file()
{
	FILE *file = fopen(filename, "w");
	if (file == NULL)
	{
		printf("\nfile creation failed");
		return;
	}
	fclose(file);
}

void load_file()
{
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		char confirmation;
		printf("\nunable to open the file in read mode");
		printf("\ncreate new one? y or n: ");
		scanf("%c", &confirmation);
		if (confirmation == '\n')
		{
			scanf("%c", &confirmation);
		}
		if (confirmation == 'y')
		{
			create_new_file();
		}
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

void save_file()
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
