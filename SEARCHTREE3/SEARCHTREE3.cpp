#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	int data;
	Node* leftc;
	Node* rightc;
	int amount;
	int ramount;
	int lamount;
};
Node* root = nullptr;
vector<Node*> values;
vector<int> amounts;


ofstream mout("out.txt");

void push(int x, Node** y)
{
	if ((*y) != nullptr && x == (*y)->data)
	{
		return;
	}
	if ((*y) == nullptr)
	{
		(*y) = new Node;
		(*y)->data = x;
		(*y)->leftc = nullptr;
		(*y)->rightc = nullptr;
		(*y)->amount = 1;
		(*y)->lamount = 0;
		(*y)->ramount = 0;
		return;
	}
	else if (x < (*y)->data)
	{
		push(x, &(*y)->leftc);
	}
	else
	{
		push(x, &(*y)->rightc);
	}
}

Node* MIN(Node* x)
{
	if (x->leftc != nullptr)
	{
		return MIN(x->leftc);
	}
	else
	{
		return x;
	}
}

Node* deletekeys(Node* x, int v)
{
	if (x == nullptr)
	{
		return x;
	}
	if (v < x->data)
	{
		x->leftc = deletekeys(x->leftc, v);
	}
	else if (v > x->data)
	{
		x->rightc = deletekeys(x->rightc, v);
	}
	else {
		if (x->leftc == nullptr && x->rightc == nullptr) {
			return nullptr;
		}
		else if (x->leftc == nullptr)
		{
			return x->rightc;
		}
		else if (x->rightc == nullptr)
		{
			return x->leftc;
		}
		Node* minkey = MIN(x->rightc);
		x->data = minkey->data;
		x->rightc = deletekeys(x->rightc, minkey->data);
	}
	return x;

}

void printleft(Node* x)
{
	if (x == nullptr)
	{
		return;
	}
	mout << x->data << endl;
	printleft(x->leftc);
	printleft(x->rightc);
}

void rpass(Node* x) {
	if (x != nullptr){
		rpass(x->leftc);
		rpass(x->rightc);
		if (x->leftc != nullptr) {
			x->lamount += x->leftc->amount;
			x->lamount += x->leftc->lamount;
			x->lamount += x->leftc->ramount;
		}
		if (x->rightc != nullptr) {
			x->ramount += x->rightc->amount;
			x->ramount += x->rightc->lamount;
			x->ramount += x->rightc->ramount;
		}
		values.push_back(x);
	}
}

void findDeleteKey() {
	for (Node* i : values) {
		if (abs(i->ramount - i->lamount) == 1) {
			amounts.push_back(i->data);
		}
	}
	sort(amounts.begin(), amounts.end());
	if (amounts.size() % 2 != 0)
	{
		if (amounts.size() == 1)
		{
			root = deletekeys(root, amounts[0]);
		}
		else
		{
			root = deletekeys(root, amounts[amounts.size() / 2]);
		}
	}
}

int main()
{
	ifstream min("in.txt");
	int b;
	while (min >> b)
	{
		push(b, &root);
	}
	rpass(root);
	findDeleteKey();
	printleft(root);
	return 0;
}