#include<iostream>

using namespace std;

struct node
{
	int num;
	node *left, *right;
}
class tree
{
	private:
		node *temp;
	public:
		node *root;
		tree()
		{
			root = temp = NULL;
		}
		~tree()
		{
			delete root;
			delete temp;
		}
}
