int FibonacciRecursive(int i)
{
	if (i < 2)
	{
		return i;
	}

	return FibonacciRecursive(i - 1) + FibonacciRecursive(i - 2);
}

int FibonacciNoneRecursive(int i)
{
	if (i < 2)
	{
		return i;
	}

	int n_1 = 0;
	int n_2 = 1;
	int result;

	for (int j = 2; j <= i; j++)
	{
		result = n_1 + n_2;
		n_1 = n_2;
		n_2 = result;
	}
	return result;
}