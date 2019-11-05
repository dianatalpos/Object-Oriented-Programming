

#include "pch.h"
#include <stdio.h>



/*7. a. Read sequences of positive integer numbers (reading of each sequence ends by 0, reading of
all the sequences ends by - 1) and determine the maximum element of each sequence and the
maxim element of the global sequence.
b.Given a vector of numbers, find the longest contiguous subsequence such that all elements are
in a given interval.
*/

void menu()
{
	printf("\nProblems: \n");
	printf("\t1.Read sequences of positive integer numbers (reading of each sequence ends by 0, reading of all the sequences");
	printf("\tends by - 1) and determine the maximum element of each sequence and the maxim element of the global sequence.\n");
	printf("\t2.Given a vector of numbers, find the longest contiguous subsequence such that");
	printf("\tall elements are in a given interval.\n");
	printf("\t3.Print the exponent of a prime number p from the decomposition in prime factors of a given number n\n");
	printf("\tn is a non - null natural number).\n");
	printf("\t4. Exit\n");
	printf("Give the number of a command: ");
}




/*
Function that search the max elem of an vector.
in: seq - a vector a numbers
	dim - the dimension of the vector
out: max - maximum value from the list
*/
int max_elem(int seq[100], int dim)
{
	int max = seq[0];
	for (int i = 1; i < dim; i++)
	{
		if (seq[i] > max)
		{
			max = seq[i];
		}
	}
	return max;
}



/*
Function that finds the longest subsequence that has all the element in the interval [a,b]
in: list - a list of numbers
	dim - the dimension of list
	a - the start of the interval
	b - the end of the interval
out : start - the start position of the subsequence
	  end - the end position of the subsequence

	[3,7]
			0 1 2 3 4 5 6 7 8 9 10 11
	list:   1 7 3 5 6 2 3 4 5 7 6 1
	longest:0 4 3 2	1 0	5 4	3 2	1 0

*/

void find_subseq(int list[], int dim, int a, int b, int &start, int &end)
{
	int longest[100];
	longest[dim] = 0;
	for (int i = dim - 1; i >= 0; i--)
	{
		if (list[i] >= a && list[i] <= b)
		{
			longest[i] = longest[i + 1] + 1;
		}
		else
			longest[i] = 0;
	}
	int max = 0, pos = -1;
	for (int i = 0; i < dim; i++)
		if (longest[i] > max)
		{
			max = longest[i];
			pos = i;
		}
	start = pos;
	end = pos + max - 1;
}




/*
Function that find the exponent of a prime number p
in: n,p - integers
	n - number
	p - factor
out: cont - integer, represent the exponent of p in the decomposition in prime numbers
*/
int exponent(int n, int p)
{
	if (n%p != 0)
		return 0;
	int cont = 0;
	while (n != 0 && n%p == 0)
	{
		cont++;
		n = n / p;
	}
	return cont
}

/*
Function that checks if a number is prime or not
in: n - integer number
out: r - boolean 
	r = 1 if n is prime
	  = 0 otherwise 
*/
bool prime(int n)
{
	if (n < 2)
		return 0;
	if (n % 2 == 0)
		return 0;
	int d = 3;
	while (d*d <= n)
	{
		if (n%d == 0)
			return 0;
	}
	return 1;
}





/*
Function that reads the numbers from the keyboard until -1, after, call the function
for every subsequence that we read (until 0) for finding the maximum value of the sequence
output: maxvalues - a list with the maximum values from all subsequences
		dim - the dimension of the list
*/
void read_A(int maxvalues[], int &dim)
{
	dim = 0;
	int value = 0, subseq[100], max;
	int dim_max = 0;
	while (value != -1)
	{
		int dim_subseq;
		dim_subseq = 0;
		scanf("%d", &value);
		while (value != 0 && value != -1)
		{
			subseq[dim_subseq] = value;
			dim_subseq = dim_subseq + 1;
			scanf("%d", &value);
		}
		if (value == 0)
		{
			max = max_elem(subseq, dim_subseq);
			maxvalues[dim] = max;
			dim += 1;
		}
	}
}


/*
Function that reads a list of natural numbers and two numbers a,b that represent an interval.
If a is grater than b then a will be the end of the interval and b the start of the interval
*/
void read_B(int list[], int &dim, int &a, int &b)
{
	printf("\n Give the dimension of the list: \n");
	scanf_s("%d", &dim);
	printf("\n Give the numbers: ");
	for (int i = 0; i < dim; i++)
	{
		int value = 0;
		scanf("%d", &value);
		list[i] = value;
	}
	printf("\n Give the interval: ");
	scanf("%d", &a);
	scanf("%d", &b);
	int aux = 0;
	if (a > b)
	{
		aux = a;
		a = b;
		b = aux;
	}
}

/*
Function that reads the values forthe third problem.
*/
void read_c(int &n, int &p)
{
	printf("Give a number: \n");
	scanf("%d", &n);
	printf("Give the factor: \n");
	scanf("%d", &p);
}


void ui_a()
{
	int max_values[100], dim;
	printf("Give the sequence of numbers: ");
	read_A(max_values, dim);
	printf("The maximum values are: \n");
	for (int i = 0; i < dim; i++)
	{
		printf("%d ", max_values[i]);
	}
	int max;
	max = max_elem(max_values, dim);
	printf("\nThe maximum value of all the list is: \n");
	printf("%d ", max);
}


void ui_b()
{
	int list[100], dim = 0, a = 0, b = 0;
	read_B(list, dim, a, b);
	int start = -1, end = -1;
	find_subseq(list, dim, a, b, start, end);
	printf("\nThe sequence is:\n");
	for (int i = start; i <= end; i++)
	{
		printf("%d ", list[i]);
	}
}


void ui_c()
{
	int n, p;
	read_c(n,p);
	if (n < 1)
		printf("The number is invalid!\n");
	if (prime(p) == 0)
		printf("The factor is not a prime number! Please give a prime number!\n");
	int result = 0;
	result = exponent(n, p);
	printf("The factor %d appears in the number %d at the power %d.\n", p, n, result);
}



int main()
{
	while (1)
	{
		menu();
		int command;
		scanf("%d", &command);
		if (command == 1)
		{
			ui_a();
		}
		else
			if (command == 2)
			{
				ui_b();
			}
			else 
				if (command == 3)
				{
					ui_c();
				}
				else return 0;


	}
}