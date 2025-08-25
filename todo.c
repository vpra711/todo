#include <stdio.h>
#include <stdlib.h>

void create_file(char *filename);
void load_file(char *filename);
void save_file(char *filename);

char *buffer;

int main()
{
	return 0;
}

void load_file(char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("unable to open the file in read mode");
		return;
	}


	fseek(file, 0, SEEK_END);
	unsigned long file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	buffer = (char *) malloc(sizeof(file_size));
	if (buffer == NULL)
	{
		printf("cannot allocate memory - file is too large (or) you dont have ram");
		fclose(file);
		return;
	}

	

	fclose(file);
}

void save_file(char *filename)
{
	FILE *file = fopen(filename, "w");

	if (file == NULL)
	{
		printf("unable to open file in write mode");
		return;
	}

	if (buffer == NULL)
	{
		printf("buffer is null");
		fclose(file);
		return;
	}

	fputs(buffer, file);
	fclose(file);
}
