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
	int h;//высота
	int l;//количество листьев на расстоянии h от вершины
	int a;
	int b;
	int msl;//длина наибольшего полупути проходящего через вершины
};
Node* root = nullptr;
int mslT = 0;//длина наибольшего полпя
ofstream mout("output.txt");

void push(int x, Node** y)
{
	if ((*y) == nullptr)
	{
		(*y) = new Node;
		(*y)->data = x;
		(*y)->leftc = nullptr;
		(*y)->rightc = nullptr;
		(*y)->h = 0;
		(*y)->a = 0;
		(*y)->l = 0;
		(*y)->b = 0;
		(*y)->msl = 0;
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
	mout << x->data << " " << x->a + x->b << endl;
	printleft(x->leftc);
	printleft(x->rightc);
}

void rpass(Node* x) {
	if (x != nullptr) {
		rpass(x->leftc);
		rpass(x->rightc);
		if (x->leftc == nullptr) {
			if (x->rightc == nullptr) {
				x->l = 1;
				x->h = 0;
				x->msl = 0;
			}
			else {
				x->l = x->rightc->l;
				x->h = x->rightc->h + 1;
				x->msl = x->rightc->h + 1;

			}
		}
		else if (x->rightc == nullptr) {
			x->l = x->leftc->l;
			x->h = x->leftc->h + 1;
			x->msl = x->leftc->h + 1;
		}
		else {
			x->h = max(x->rightc->h, x->leftc->h) + 1;
			x->msl = x->leftc->h + x->rightc->h + 2;
			if (x->leftc->h == x->rightc->h) {
				x->l = x->leftc->l + x->rightc->l;
			}
			else x->l = max(x->rightc->l, x->leftc->l);
		}
		if (x->msl > mslT) {
			mslT = x->msl;
		}
	}
}

long countB(Node* x) {
	long b = 0;
	if (x != nullptr) {
		if (x->msl == mslT) {
			if (x->leftc == nullptr) {
				if (x->rightc != nullptr) {
					b = x->rightc->l;
				}
			}
			else if (x->rightc == nullptr) {
				b = x->leftc->l;
			}
			else {
				b = x->rightc->l * x->leftc->l;
			}
		}
	}
	return b;
}

void dBypass(Node* x) {
	if (x != nullptr) {
		x->b = countB(x);
		if (x->leftc == nullptr) {
			if (x->rightc != nullptr) {
				x->rightc->a = x->a + x->b;
			}
		}
		else if (x->rightc == nullptr) {
			x->leftc->a = x->a + x->b;
		}
		else {
			if (x->leftc->h > x->rightc->h) {
				x->leftc->a = x->a + x->b;
				x->rightc->a = x->b;
			}
			else if (x->leftc->h < x->rightc->h) {
				x->rightc->a = x->a + x->b;
				x->leftc->a = x->b;
			}
			else {
				x->rightc->a = x->b + x->rightc->l * x->a / x->l;
				x->leftc->a = x->b + x->leftc->l * x->a / x->l;
			}
		}
		dBypass(x->leftc);
		dBypass(x->rightc);
	}
	if (mslT == 0)
		root->a = 1;
}

int main()
{
	ifstream min("input.txt");
	int b;
	while (min >> b)
	{
		push(b, &root);
	}
	root = deletekeys(root, root->data);
	rpass(root);
	dBypass(root);
	printleft(root);
	return 0;
}