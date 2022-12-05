#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int hashhash(int x, int i, int m, int c)
{
	return  ((x % m) + c * i) % m;
}

int main()
{
	int m, c, n;
	vector <int> keys;
	vector <int> hash;

	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> m >> c >> n;

	for (int i = 0; i < m; i++)
	{
		hash.push_back(-1);
	}
	int tmp;
	for (int i = 0; i < n; i++)
	{
		in >> tmp;
		for (int j = 0; j < i; j++)
		{
			if (keys[j] == tmp)
			{
				tmp = -1;
				break;
			}
		}
		keys.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		if (keys[i] != -1)
		{
			for (int j = 0; j < m; j++)
			{
				int ind = hashhash(keys[i], j, m, c);
				if (hash[ind]== -1)
				{
					hash[ind] = keys[i];
					break;
				}
			}
		}
	}
	for (int i : hash)
	{
		out << i << " ";
	}
	return 0;
}