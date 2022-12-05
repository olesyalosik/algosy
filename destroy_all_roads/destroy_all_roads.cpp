#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
struct Pair {
	int x;
	int y;
	friend istream& operator>>(istream& in, Pair& a)
	{
		in >> a.x >> a.y;
	}
};

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, m, q;
	in >> n >> m >> q;
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}
	vector<Pair> roads;
	roads.resize(m);
	Pair tmp;
	for (int i = 0; i < m; i++)
	{
		in >> tmp;
		roads[i] = tmp;
	}
	for (int i = 0; i < q; i++)
	{

	}
	return 0;
}