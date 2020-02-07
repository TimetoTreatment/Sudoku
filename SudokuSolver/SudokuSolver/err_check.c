int error_check(int map[9][9], int n, int row, int col)
{
	if (n == 0)
		return 0;

	int i, j;
	int row_start;
	int col_start;

	for (i = 0; i < 9; i++)
	{
		if (map[row][i] == n && i != col)
		{
			return 1;
		}

		if (map[i][col] == n && i != row)
		{
			return 1;
		}
	}

	row_start = row / 3 * 3;
	col_start = col / 3 * 3;

	for (i = row_start; i < row_start + 3; i++)
	{
		for (j = col_start; j < col_start + 3; j++)
		{
			if (map[i][j] == n && i != row && j != col)
			{
				return 1;
			}
		}
	}

	return 0;
}