#include <iostream>

using namespace std;

const int c = 10; // the total cost of knapsack
const int w[] = {2, 2, 6, 5, 4}; // the weight of objects
const int v[] = {6, 3, 5, 4, 6}; // the value of objects
const int n = sizeof(w) / sizeof(w[0]);

int x[n]; // the result of array

void knapsack(int m[][11], const int w[], const int v[], const int n)
{
	// put the bottom rows
	for (int j = 0; j <= c; j++)
	{
		if (w[0] > j)
		{
			m[0][j] = 0;
		} else {
			m[0][j]	= v[0];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= c; j++) {
			if (w[i] > j)
			{
				m[i][j]	= m[i - 1][j];
			} else {
				int without = m[i - 1][j];
				int with = m[i - 1][j - w[i]] + v[i];
				m[i][j] = without > with ? without : with;
			}
		}
	}

}

void answer(int m[][11], const int n)
{

	int j = 10;
	int i;
	for (i = n - 1; i >= 1; i --)
	{
		if (m[i][j] == m[i - 1][j])
		{
			x[i] = 0;
		} else {
			x[i] = 1;
			j = j - w[i];
		}
	}

	x[0] = m[0][j] > 0 ? 1 : 0;
}

int main()
{
	int m[5][11];
	memset(m, 0, sizeof(m));
	knapsack(m, w, v, n);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			printf("%2d ", m[i][j]);
		}

		cout << endl;
	}

	answer(m, n);
	cout << "the best answer is :" << endl;
	for (int i = 0; i < 5; i++) {
		cout << x[i] << " ";
	}

	cout << endl;


	return 0;
}
















