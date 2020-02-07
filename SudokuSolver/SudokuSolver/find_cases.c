int find_cases(int map[9][9], int cases[9][9][10], int row, int col)
{
	int i, j;
	int row_start, col_start;
	int count = 0;
	int num;

	for (i = 0; i < 9; i++)
	{
		if (map[row][i] != 0)
		{
			cases[row][col][map[row][i]] = 1;
		}

		if (map[i][col] != 0)
		{
			cases[row][col][map[i][col]] = 1;
		}
	}

	row_start = row / 3 * 3;
	col_start = col / 3 * 3;

	for (i = row_start; i < row_start + 3; i++)
	{
		for (j = col_start; j < col_start + 3; j++)
		{
			if (map[i][j] != 0)
			{
				cases[row][col][map[i][j]] = 1;
			}
		}
	}

	for (i = 1; i < 10; i++)
	{
		if (cases[row][col][i] == 0)
		{
			count++;

			num = i;
		}
	}

	if (count == 1)
	{
		return num;
	}

	return 0;
}