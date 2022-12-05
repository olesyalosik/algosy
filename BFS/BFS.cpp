#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;
struct Pair
{
	int father=0;
	int son=0;
};

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, m=0;
	queue <int> q;
	in >> n;
	int count = 0;
	vector <int> used;
	used.resize(n);
	for (int i = 0; i < n; i++)
	{
			used[i] = 0;
	}
	Pair tmp;
	vector <Pair> graph;
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			in >> matrix[i][j];
			if (matrix[i][j] == 1)
			{
				tmp.father = i + 1;
				tmp.son = j + 1;
				graph.push_back(tmp);
				m++;
			}
		}
	}
	vector<vector<int>> G;
	G.resize(n);
	for (int i = 0; i < m; i++)
	{
		G[graph[i].father - 1].push_back(graph[i].son - 1);
		//G[graph[i].son - 1].push_back(graph[i].father - 1);
	}
	for (int i = 0; i < n; i++)
	{
		if (used[i] == 0)
		{
			count++;
			q.push(i);
			used[i] = count;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (int neighbor : G[cur])
				{
					if (used[neighbor] == 0)
					{
						q.push(neighbor);
						count++;
						used[neighbor] = count;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		out << used[i] << " ";
	}
	return 0;
}