#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
	int data;
	Node* leftc;
	Node* rightc;
};
Node* root = nullptr;

ofstream mout("output.txt");

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

int main()
{
	ifstream min("input.txt");
	int a;
	min >> a;
	int b;
	while (min >> b)
	{
		push(b, &root);
	}
	root = deletekeys(root, a);
	printleft(root);
	return 0;
}