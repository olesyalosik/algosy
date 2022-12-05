#include<iostream>
#include<vector>
#include<queue>
#include<fstream>

using namespace std;

int t = 1;
void DFS(int v, vector<vector<int>> matrix, vector<bool>& used, vector<int>& met, int n) 
{
	used[v] = true;
	met[v] = t++;
	for (int i = 0; i < n; i++)
	{
		int to = matrix[v][i];
		if (!used[i] && to == 1)
		{
			DFS(i, matrix, used, met, n);
		}
	}
}

int main() 
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	in >> n;
	vector<vector<int>> matrix;
	vector<bool> used;
	vector<int> met;
	matrix.resize(n);
	used.resize(n);
	met.resize(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			in >> tmp;
			matrix[i].push_back(tmp);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (!used[i])
		{
			DFS(i, matrix, used, met, n);
		}
	}
	for (int i = 0; i < n; i++)
	{
		out << met[i] << " ";
	}

	return 0;
}