 #include <iostream>

using namespace std;

struct node
{
	int info;
	node *left,*right;
};

class avl
{
	private:
		node *temp;
	public:
		node *root;
		int num;
		
		avl()
		{
			temp = root = NULL;
			num = 0;
		}
		int hight(node *temp , int count = 0)
		{
			cout<<"kad call";
			if (temp == NULL)
			{
				return count;
			}
			count++;
			if (temp->left != NULL)
			{
				hight(temp->left,count);
				return count;
			}
			if (temp->right!= NULL)
			{	
				hight(temp->right,count);
				cout<<count<<endl;
				return count;
			}
			count--;
			return count;
		}
		void balancing(node *temp)	// Function to balance the tree
		{
			cout<<"balancing call"<<endl;
			if (temp == NULL)
			{
				cout<<"What do i do with it";
				return;
			}
			int lh = hight(temp->left);
			int rh = hight(temp->right);
			if (lh - rh >= 2 || lh - rh <= -2)
			{
				cout<<"Now time for rotate function";
			}
		}
		node* insertion(node *temp)
		{
			if (temp == NULL)
			{
				temp = new node;
				temp->info = num;
				temp->left = NULL;
				temp->right = NULL;
				root = temp;
				return temp;
			}
			if (temp->info == num)
			{
				cout<<"Number is Already present";
				return temp;
			}
			else
			{
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
						temp->right->left = NULL;
						temp->right->right = NULL;
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
                      temp->left->left = NULL;
                      temp->left->right = NULL;
                      return temp;
                    }
				}
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
			cout<<temp->info<<endl;
			if (temp->right != NULL)
			{
				in_ord(temp->right);
			}
		}
		
		~avl()
		{
			delete temp;
			delete root;
		}
//		postorder(node* p, int indent=4)
//		{
//    		if(p != NULL)
//			 {
//        		if(p->left) postorder(p->left, indent+4);
//        		if(p->right) postorder(p->right, indent+4);
//        		if (indent)
//				{
//            		cout << "   " << ' ';
//        		}
//        		cout<< p->info << "\n ";
//    		}
//		}
};


int main()
{
	avl l;
	cin>>l.num;
	l.insertion(l.root);
	cin>>l.num;
	l.insertion(l.root);
	cin>>l.num;
	l.insertion(l.root);
	cin>>l.num;
	l.insertion(l.root);
	cin>>l.num;
	l.insertion(l.root);
	l.in_ord(l.root);
	
	
//	l.postorder(l.root);
}
