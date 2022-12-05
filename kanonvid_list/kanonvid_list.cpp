#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
struct Pair {
	int father;
	int son;
	friend istream& operator>>(istream& in, Pair& p)
	{
		in >> p.father >> p.son;
		return in;
	}
};
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	ios_base::sync_with_stdio(false);
	in.tie(NULL);
	int n;
	in >> n;
	Pair root;
	root.father = 0;
	vector<int> fathers;
	fathers.resize(n);
	for (int i = 0; i < n; i++)
	{
		fathers[i] = 0;
	}
	Pair tmp;
	for (int i = 0; i < n-1; i++)
	{
		in >> tmp;
		fathers[tmp.son - 1] = tmp.father;
	}
	for (int f : fathers)
	{
		out << f << " ";
	}
	return 0;
}