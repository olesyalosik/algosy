#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
struct Pair {
	int father;
	int son;
	friend istream& operator>>(istream& in, Pair& a)
	{
		in >> a.father >> a.son;
	}
};

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	in >> n;
	Pair root;
	root.father = 0;
	vector<Pair> sonfath;
	vector <int> ifroot;
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			in >> matrix[i][j];
		}
	}
	for (int j = 0; j < n; j++)
	{
		int count1 = 0;
		for (int i = 0; i < n; i++)
		{ 
			if (matrix[i][j] == 1)
			{
				Pair p;
				p.son = j + 1;
				p.father = i + 1;
				sonfath.push_back(p);
			}
			else if (matrix[i][j] == 0)
			{
				count1++;
			}
		}
		if (count1 == n)
		{
			root.son = j + 1;
			sonfath.push_back(root);
		}
	}
	for (Pair j : sonfath)
	{
		out << j.father << " ";
	}
	return 0;
}