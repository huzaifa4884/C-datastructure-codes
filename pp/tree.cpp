#include <iostream>

using namespace std;


struct node
{
	int info;
	node *left;
	node *right;
};
class tree
{
	private:
		node *temp;
	public:
		node *root;
		int num;
		tree()
		{
			temp = NULL;
			root = NULL;
		}
		node * insertion(node *temp)
		{
			if (temp == NULL)
			{
				temp = new node;
				temp->info = num;
				temp->left = NULL;
				temp->right = NULL;
				return temp;
			}
			if (num < temp->info)
			{
				temp->left = insertion(temp->left);
				return temp;
			}
			if (num > temp->info)
			{
				temp->right = insertion(temp->right);
				return temp;
			}
			if(num == temp->info)
			{
				cout<<"Number already present";
				return temp;
			}
		}
			void in_ord(node *temp)
			{
				if (temp == NULL)
				{	
					cout<<"the tree is empty";
					return;
				}
				if (temp->left != NULL)
				{
					in_ord(temp->left);
				}
				cout<<temp->info<<"  :  "<<endl;
				if (temp->right != NULL)
				{
					in_ord(temp->right);
				}
			}
		~tree()
		{
			delete temp;
			delete root;
		}
};
int main()
{
	tree tr;
	cin>>tr.num;
	tr.root = tr.insertion(tr.root);
	cin>>tr.num;
	tr.root = tr.insertion(tr.root);
	cin>>tr.num;
	tr.root = tr.insertion(tr.root);
	cin>>tr.num;
	tr.root = tr.insertion(tr.root);
	cin>>tr.num;
	tr.root = tr.insertion(tr.root);
	cin>>tr.num;
	tr.root = tr.insertion(tr.root);
	tr.in_ord(tr.root);
	return 0;
}
