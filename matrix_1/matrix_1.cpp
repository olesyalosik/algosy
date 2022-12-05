//матрица смежности 

#include <iostream>
#include <fstream>

using namespace std;

struct Pair
{
	int v1;
	int v2;
	friend istream& operator>>(istream& in, Pair& ver)
	{
		in >> ver.v1 >> ver.v2;
	}
};

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, m;
	in >> n >> m;
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		Pair P;
		in >> P;
		matrix[P.v1-1][P.v2-1] = 1;
		matrix[P.v2-1][P.v1-1] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			out << matrix[i][j]<<" ";
		}
		out << endl;
	}
	return 0;
}