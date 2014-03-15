int FactorialRecursive(int i)
{
	if (i == 0)
	{
		return 1;
	}
	return i * FactorialRecursive(i - 1);
}

int FactorialNonRecursive(int i)
{
	int result  = 1;

	for (int j = 1; i >= j; j++)
	{
		result = result * j;
	}

	return result;
}