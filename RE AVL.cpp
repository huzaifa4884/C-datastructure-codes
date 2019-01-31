#include <iostream>

using namespace std;

struct node
{
	int info;
	int h;
	node *left;
	node *right;
};

class AVL
{
	private:
		node *temp;
	public:
		node *root;
		int num;
		AVL()
		{
			temp = NULL;
			root = NULL;
		}
		node *rtl(node *temp)
		{
			node *temp2 = temp->right;
			while (temp2->left != NULL)
			{
				temp2 = temp2->left;
			}
			temp2->left = temp;
			temp->left = NULL;
			temp->right = NULL;
			temp = temp2;
			
			return temp;
		}
		int tbalance(node *temp , int max =0)
		{
			if (temp->h > max )
			{
				max = temp->h;
			}
			if (temp->left != NULL)
			{
				max = tbalance(temp->left,max);
				return max;
			}
			if (temp->right != NULL)
			{
				max = tbalance(temp->right,max);
				return max;
			}
			return max;
		}
		void balancing(node *temp)
		{
			int lh = temp->h;
			int rh = temp->h;
			
			if (temp->left != NULL)
			{
				lh = tbalance(temp->left,temp->h);
			}
			if (temp->right != NULL)
			{
				rh = tbalance(temp->right,temp->h);
			}
			if (lh - rh <= -2)
			{
				cout<<"lh = "<<lh<<endl;
				cout<<"rh = "<<rh<<endl;
				cout<<"left rotate ftn"<<endl;
				temp = rtl(temp);
				return;
			}
			else if (lh - rh >= 2)
			{
				cout<<"lh = "<<lh<<endl;
				cout<<"rh = "<<rh<<endl;
				cout<<"right rotate ftn"<<endl;
			}
			else
			{
				cout<<"lh = "<<lh<<endl;
				cout<<"rh = "<<rh<<endl;
				cout<<"Came accross balnced node which is"<<temp->info<<endl;
			}
		}
		node * insertion(node *temp)
		{
			if (root == NULL)
			{ 
				temp = new node;
				temp->info = num;
				temp->h = 0;
				temp->left = NULL;
				temp->right = NULL;
				root = temp;
				return temp;
			}
			if (num > temp->info)
			{
				if (temp->right != NULL)
				{
					balancing(insertion(temp->right));
					return temp;
				}
				else
				{
					temp->right = new node;
					temp->right->info = num;
					temp->right->h = temp->h + 1;
					temp->right->right = NULL;
					temp->right->left = NULL;
					return temp;
				}
			}
			if (num < temp->info)
			{
				if (temp->left != NULL)
				{
					balancing(insertion(temp->left));
					return temp;
				}
				else
				{
					temp->left = new node;
					temp->left->info = num;
					temp->left->h = temp->h + 1;
					temp->left->left = NULL;
					temp->left->right = NULL;
					return temp;
				}
			}
			if (temp->info == num)
			{
				cout<<"Number Already present";
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
			cout<<temp->info<<"  :  "<<temp->h<<endl;
			if (temp->right != NULL)
			{
				in_ord(temp->right);
			}
		}
		
		~AVL()
		{
			delete temp;
			delete root;
			num = 0;
		}
};

int main()
{
	AVL tr;
	cin>>tr.num;
	tr.insertion(tr.root);
	cin>>tr.num;
	tr.insertion(tr.root);
	cin>>tr.num;
	tr.insertion(tr.root);
	cin>>tr.num;
	tr.insertion(tr.root);
	tr.in_ord(tr.root);
	cin>>tr.num;
	tr.insertion(tr.root);
	tr.in_ord(tr.root);
}
