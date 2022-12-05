#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	int x, y, z;
	string A, B;
	in >> x;
	in >> y;
	in >> z;
	getline(in, A);
	getline(in, A);
	getline(in, B);
	in.close();
	int n = A.size() + 1;
	int m = B.size() + 1;
	int** matr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		matr[i][0] = i * x;
	}
	for (int i = 0; i < m; i++)
	{
		matr[0][i] = i * y;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			int tmp;
			if (A[i - 1] != B[j - 1])
			{
				tmp = matr[i - 1][j - 1] + z;
			}
			else
			{
				tmp = matr[i - 1][j - 1];
			}
			int min = matr[i - 1][j] + x;
			if (min > tmp)
			{
				min = tmp;
			}
			if (min > matr[i][j - 1] + y)
			{
				min = matr[i][j - 1] + y;
			}
			matr[i][j] = min;
		}
	}
	out << matr[n - 1][m - 1];

	return 0;
}