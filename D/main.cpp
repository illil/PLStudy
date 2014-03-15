#include <iostream>
#include "String.h"
#include "Stack.h"
#include "factorial.h"
#include "fibonacci.h"

int main()
{
	std::cout << "Factorial_Recursive : " << FactorialRecursive(6) << std::endl;
	std::cout << "Factorial_None_Recursive : " << FactorialNonRecursive(6) << std::endl;
	std::cout << "Fibonacci_Recursive : " << FibonacciRecursive(7) << std::endl;
	std::cout << "Fibonacci_None_Recursive : " << FibonacciNoneRecursive(7) << std::endl;

	return 0;
}
