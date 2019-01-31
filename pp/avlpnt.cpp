#include <iostream>

using namespace std;

struct node
{
	int info;
	int h;
	node *left;
	node *right;
};

class tree1
{
		
	public:
		node *root;
		tree1()
		{
			root = NULL;
		}
		//************************************
		//Finding height
		//************************************
		int ht(node *temp,int n = 0)
		{
			if (temp->h > n)
			{
				n = temp->h;
			}
			if (temp->left != NULL)
			{
				n = ht(temp->left,n);
				return n;
			}
			if (temp->right != NULL)
			{
				n = ht(temp->right,n);
				return n;
			}
			return n;
		}
		//*****************************************
		// Update hieghts function goes here
		//****************************************
		node *update_heights(node *temp, bool flag = false)
		{
			if (flag == false)
			{
				temp->h = temp->h - 1;
				flag = true;
			}
			if (flag == true)
			{
				
				if (temp->left != NULL)
				{
					temp->left->h = temp->h + 1;
					temp->left = update_heights(temp->left, flag);
				}
				if (temp->right != NULL)
				{
					temp->right->h = temp->h + 1;
					temp->right = update_heights(temp->right,flag);
				}
				return temp;
			}
		}
		//*****************************************
		//Rotations function
		//*****************************************
		
		node *rotateR(node *temp)
		{
			node *temp1 = temp->left;
			temp->left = temp1->right;
			temp1->right = temp;
			temp1 = update_heights(temp1);
			return temp1;
		}
		node *balancing(node *temp)
		{
			int lh = temp->h;
			int rh = temp->h;
			
			if (temp->left != NULL)
			{
				lh = ht(temp->left);
			}
			if (temp->right !=NULL)
			{
				rh = ht(temp->right);
			}
			if (lh - rh <= -2)
			{
				cout<<"  "<<"Left rotate   "<<temp->info<<" bnde"<<endl;
				return temp;
			}
			if (lh - rh >= 2)
			{
				cout<<"  "<<"right rotate  "<<temp->info<<" bnde"<<endl;
				inord(root);
				cout<<endl<<endl;
				temp = rotateR(temp);
				return temp;
			}
			return temp;
		}
		node *insertion(int num , node *temp, int count = 0)
		{
			if (temp == NULL)
			{
				temp = new node;
				temp->info = num;
				temp->h = count;
				temp->right = NULL;
				temp->left = NULL;
				if (count == 0)
				{
					root = temp;
					return root;
				}
				else
				{
					return temp;
				}
			}
			if (num < temp->info)
			{
				count++;
				temp->left = balancing(insertion(num , temp->left, count));
				//temp->left = insertion(num , temp->left, count);
				return temp;
			}
			if (num > temp->info)
			{
				count++;
				temp->right = balancing(insertion(num , temp->right, count));
				//temp->right = insertion(num , temp->right, count);
				return temp;
			}
			if (num == temp->info)
			{
				cout<<endl<<"Number already present";
				return temp;
			}
		}
		void inord(node *temp)
		{
			if (root == NULL)
			{
				cout<<"the tree is empty";
				return;
			}
			if (temp->left != NULL)
			{
				inord(temp->left);
			}
			cout<<temp->info<<"  "<<temp->h<<endl;
			if (temp->right != NULL)
			{
				inord(temp->right);
			}
		}
		~tree1()
		{
			delete root;
		}
};
int main()
{
	tree1 tr;
	int num;
	cin>>num;
	tr.insertion(num,tr.root);
		cin>>num;
	tr.insertion(num, tr.root);
		cin>>num;
	tr.insertion(num,tr.root);
		cin>>num;
	tr.insertion(num, tr.root);
		cin>>num;
	tr.insertion(num,tr.root);
		cin>>num;
	tr.insertion(num,tr.root);
	tr.inord(tr.root);
}
