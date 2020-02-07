#include <stdio.h>


void prework(int map[9][9])
{
	int i, j;
	char ch;

	printf("\n");
	printf(" :: 9*9 Sudoku Solver ::\n\n");
	printf("   C 1 2 3 4 5 6 7 8 9\n");
	printf(" R   - - - - - - - - -\n");

	for (i = 0; i < 9; i++)
	{
		printf(" %d : ", i + 1);

		for (j = 0; j < 17; j++)
		{
			scanf("%c", &ch);

			if (j % 2 == 0)
			{
				if (ch == ' ')
				{
					map[i][j / 2] = 0;
				}
				else
				{
					map[i][j / 2] = ch - '0';
				}
			}
		}

		do {
			scanf("%c", &ch);

		} while (ch != '\n');
	}
}