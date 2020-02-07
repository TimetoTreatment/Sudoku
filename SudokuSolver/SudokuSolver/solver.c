#include <stdio.h>
#include "struct_check.h"

int error_check(int map[9][9], int n, int row, int col);

int solver(int map[9][9], check* list, int index, int voids, int answer)
{
	int i, j;

	if (index == voids)
	{
		printf("\n\n");
		printf("       * Answer *\n");

		for (i = 0; i < 9; i++)
		{
			if (i % 3 == 0)
				printf("\n");

			for (j = 0; j < 9; j++)
			{
				if (j % 3 == 0)
					printf(" ");

				printf(" %d", map[i][j]);
			}

			printf("\n");
		}

		printf("\n\n");

		return 1;
	}

	int n = list[index].numbers;
	int row = list[index].row;
	int col = list[index].col;

	for (i = 0; i < n; i++)
	{
		for (j = index; j < voids; j++)
		{
			map[list[j].row][list[j].col] = 0;
		}

		if (error_check(map, list[index].num[i], row, col) == 0)
		{
			map[row][col] = list[index].num[i];

			answer = solver(map, list, index + 1, voids, answer);

			if (answer == 1)
				return answer;
		}
	}

	return answer;
}