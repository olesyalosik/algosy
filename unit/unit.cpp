#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, m;
	in >> n >> m;
	priority_queue<int> sequences;
	for (int i = 0; i < m * n; i++)
	{
		int tmp;
		in >> tmp;
		sequences.push(tmp);
	}
	vector<int> newsequence;
	newsequence.resize(m * n);
	for (int i = m * n - 1; i >= 0; i--)
	{
		int tmp = sequences.top();
		sequences.pop();
		newsequence[i] = tmp;
	}
	for (int i : newsequence)
	{
		out << i << " ";
	}
	return 0;
}