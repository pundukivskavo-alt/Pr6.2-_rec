#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int *a, const int size, const int Low, const int High, int i)
{
	a[i]=Low+ rand() % (High - Low + 1);
	if(i<size-1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{ 
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

// середнє арифметичне індексів парних елементів
double AverageIndexEven(int* a, const int size, int i, int S, int k)
{
	if (a[i]%2==0)
	{
		S += i;
		k++;
	}
	if (i<size-1)
			return AverageIndexEven(a, size, i + 1, S, k);
	else
	{
		if (k == 0)
		{
			cout << "no even elements" << endl;
			return 0;
		}
		return (double)S / k;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	const int n = 20;
	int a[n];

	int Low = 10;
	int High = 99;

	Create(a, n, Low, High, 0);
	Print(a, n, 0);

	cout << "Average index of even elements: " << AverageIndexEven(a, n, 0, 0, 0) << endl;
	
	return 0;
}