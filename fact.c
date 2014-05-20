#include <stdio.h>

long long factorial(long long);
long long factorial2(long long);
int stack;

int main()
{
	stack = 0;
	long long number;
	long long fact = 1;

	printf("Enter a number to calculate its factorial.\nFactorial of: ");
	scanf("%lld", &number);

	if(number < 0)
		printf("Negative integers are not allowed.\n");
	else
	{
		fact = factorial(number);
		printf("%d! = %lld\n", number, fact);
	}

	return 0;
}

long long factorial(long long n)
{
	int s = stack;
	stack++;
	millisleep(250);
	if (n == 0)
	{
		printf("Stack: %d\nStack request: Terminate\n", stack);
		printf("Stack %d ending\nStack result: 1\n", s);
		return 1;
	}
	else
	{
		printf("Stack: %d\nStack request: %lld * %lld\n", stack, n, factorial2(n-1));
		long long fact = factorial(n-1);
		printf("Stack %d ending\nStack result: %lld\n", s, fact);
		return(n * fact);
	}
}

long long factorial2(long long n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return(n * factorial2(n-1));
	}
}

int millisleep(int n)
{
	int sleep = n * 1000;
	usleep(sleep);
}

