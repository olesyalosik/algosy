#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	int n;
	long long min;
	in >> n;
	long long* arr = new long long[n];
	for (int i =0; i<n; i++)
	{
		in >> arr[i];
	}
	min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	if (arr[0]!=min)
	{
		out << "No";
		return 0;
	}
	else
	{
		if (n % 2 == 0)
		{
			for (int i = n / 2 - 1; i >= 0; i--)
			{
				if (i == n / 2 - 1)
				{
					if (arr[i] > arr[2 * i + 1])
					{
						out << "No";
						return 0;
					}
				}
				else
				{
					if (arr[2 * i + 1] < arr[i] || arr[2 * i + 2] < arr[i])
					{
						out << "No";
						return 0;
					}
				}
			}
		}
		else
		{
			for (int i = n / 2 - 1; i >= 0; i--)
				{

					if (arr[2 * i + 1] < arr[i] || arr[2 * i + 2] < arr[i])
					{
						out << "No";
						return 0;
					}
				}
		}
		out << "Yes";
	}
	return 0;
}
