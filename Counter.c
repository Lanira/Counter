//Made for my Math IA, to replace the Python prototype
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	long countnumbers[96] = {}; //create an array of 97 longs
	long linecount = 0;
	char ch;
	int temp; //don't you always need one?
	FILE *fp; //input file
	FILE *csv; //output file
	if (argc != 3)
	{
		printf("Usage: Counter <input filename> <output filename>\n");
		exit(1);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Failed to load file");
		exit(1);
	}

	while ((ch = getc(fp)) != EOF)
	{
		if (ch=='\n')
		{
			linecount++;
			continue;
		}
		temp = ch -32;
		countnumbers[temp] = countnumbers[temp] + 1;
		//printf("something!"); //generated a 1.26GB plaintext XD
	}
	fclose(fp);

	csv = fopen(argv[2], "w");

	int i;
	for (i=0; i<95; i++)
	{
		if ((i+32)==',')
		{
			fprintf(csv, "(comma), "); //otherwise hell arises with CSV...
			continue;
		}
		if (i == 94){fprintf(csv, "%c", (i+32)); continue;}
		fprintf(csv, "%c, ", (i+32));
	}

	fprintf(csv, "\n");

	int y;
	for (y=0; y<95; y++)
	{
                if (y == 94){fprintf(csv, "%ld", countnumbers[y]); continue;}
		fprintf(csv, "%ld, ", countnumbers[y]);
	}

	fprintf(csv, "\nPassword/Lines: %ld", linecount);
	fclose(csv);
	printf("Finished successfully, probably!\n");
}
