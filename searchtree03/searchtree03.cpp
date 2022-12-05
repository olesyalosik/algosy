#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Node {
	int key;
	int parent;
	int value;
	bool flag;
};

int main() {
	ifstream min("bst.in");
	ofstream mout("bst.out");

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	min >> num;
	int x;
	min >> x;
	vector <Node> nodes(num + 1);
	nodes[1] = { x,0,x,false };
	bool flag = true;
	int m, p;
	char c;
	Node parentnode;
	for (int i = 2; i <= num; i++) {
		min >> m >> p >> c;
		nodes[i] = { m,p,m,false };
		parentnode = nodes[nodes[i].parent];

		if (nodes[i].parent > 1) {
			if ((parentnode.key < nodes[parentnode.parent].key && c == 'L') || (parentnode.key >= nodes[parentnode.parent].key && c == 'R')) {
				nodes[i].value = parentnode.value;
			}
			else {
				nodes[i].value = nodes[parentnode.parent].key;
				nodes[i].flag = true;
			}

			if (parentnode.flag) {
				nodes[i].flag = true;
			}
		}
		else {
			nodes[i].value = parentnode.key;
		}

		if ((c == 'L' && nodes[i].key >= parentnode.key) || (c == 'R' && nodes[i].key < parentnode.key)) {
			flag = false;
		}

		if (nodes[i].flag) {
			if ((c == 'L' && nodes[i].key < nodes[i].value) || (c == 'R' && nodes[i].key >= nodes[i].value)) {
				flag = false;
			}
		}

		if (!flag)
			break;
	}
	if (flag)
		mout << "YES";
	else
		mout << "NO";
}