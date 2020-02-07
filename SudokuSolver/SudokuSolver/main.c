#include <stdio.h>
#include <stdlib.h>
#include "struct_check.h"

void prework(int map[9][9]);
int find_cases(int map[9][9], int cases[9][9][10], int row, int col);
int error_check(int map[9][9], int n, int row, int col);
int solver(int map[9][9], check* list, int index, int voids, int answer);


int main(void)
{
	int i, j, k;
	int map[9][9];
	int cases[9][9][10] = { 0 };
	int voids;
	int num;
	int err;
	check list[81];


	prework(map);

	for (voids = 0, i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (err = error_check(map, map[i][j], i, j) == 1)
			{
				break;
			}

			if (map[i][j] == 0)
			{
				num = find_cases(map, cases, i, j);

				if (num != 0)
				{
					map[i][j] = num;
				}
				else
				{
					list[voids].row = i;
					list[voids].col = j;
					list[voids].numbers = 0;

					for (k = 1; k < 10; k++)
					{
						if (cases[i][j][k] == 0)
						{
							list[voids].num[list[voids].numbers] = k;
							list[voids].numbers++;
						}
					}

					voids++;
				}
			}
		}

		if (err == 1)
			break;
	}

	if (err == 1 || solver(map, list, 0, voids, 0) == 0)
	{
		printf("\n");
		printf(" * Cannot Solve.\n\n\n");
	}

	system("pause");


	return 0;
}