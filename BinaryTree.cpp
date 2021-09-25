#include<iostream>
using namespace std;

struct btree {
	int data;
	btree* left;
	btree* right;
};

btree* search(btree* bt, int x) {

	if (bt == NULL)
		return NULL;
	else
	{
		if (bt->data == x)
			return bt;
		else
		{
			if (bt->data > x)
			{
				bt->left = search(bt->left, x);
			}
			else
			{
				bt->right = search(bt->right, x);
			}
		}
	}

}

btree* mak(btree* bt) {

	if (bt == NULL)
		return NULL;
	else
		while (bt->right != NULL)
			bt = bt->right;
	return bt;
}

btree* min(btree* bt) {

	if (bt == NULL)
		return NULL;
	else
		while (bt->left != NULL)
			bt = bt->left;
	return bt;
}

int nodesay(btree* bt) {

	if (bt == NULL)
		return 0;
	else
		return nodesay(bt->left) + 1 + nodesay(bt->right);

}

btree* del(btree *tree, int x) {
	if (tree == NULL)
		return NULL;

	if (tree->data == x)
	{
		if (tree->right == NULL && tree->left == NULL)
			return NULL;

		if (tree->right == NULL)
		{
			tree->data = mak(tree->left)->data;
			tree->left = del(tree->left, tree->data);
			return tree;
		}
		tree->data = min(tree->right)->data;
		tree->right = del(tree->right, tree->data);
		return tree;
	}
	else
	{
		if (tree->data >= x)
		{
			tree->left = del(tree->left, x);
		}
		else
			tree->right = del(tree->right, x);
	}
	return tree;
}

btree* insert(btree* bt, int x) {

	if (bt == NULL)
	{
		bt = new btree;
		bt->data = x;
		bt->left = NULL;
		bt->right = NULL;
		return bt;
	}
	else
	{
		if (bt->data > x)
		{
			bt->left = insert(bt->left, x);
			return bt;
		}
		else
		{
			bt->right = insert(bt->right, x);
			return bt;
		}
	}

}

btree* traverse(btree* bt) {

	if (bt == NULL)
		return NULL;
	else
	{
		//NLR--LNR--LRN

		traverse(bt->left);
		cout << "Left" << "\n";
		cout << bt->data << "\n";
		traverse(bt->right);
		cout << "Right" << "\n";

	}

}

void main() {

	btree* bt1;
	bt1 = NULL;

	bt1 = insert(bt1, 54);
	bt1 = insert(bt1, 35);
	bt1 = insert(bt1, 75);
	bt1 = insert(bt1, 22);
	bt1 = insert(bt1, 44);
	bt1 = insert(bt1, 65);
	bt1 = insert(bt1, 90);

	traverse(bt1);

	system("Pause");
}