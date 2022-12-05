//список смежности 

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Pair
{
	int v1;
	int v2;
	friend istream& operator>>(istream& in, Pair& ver)
	{
		in >> ver.v1 >> ver.v2;
		return in;
	}
};

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, m;
	in >> n >> m;
	vector<vector<int>> G;
	G.resize(n);
	for (int i = 1; i <= m; i++)
	{
		Pair p;
		in >> p;
		G[p.v1 - 1].push_back(p.v2);
		G[p.v2 - 1].push_back(p.v1);
	}
	for (int i = 0; i < n; i++)
	{
		out << G[i].size() << " ";
		for (int j = 0; j < G[i].size(); j++)
		{
			out << G[i][j] << " ";
		}
		out << endl;
	}
	return 0;
}