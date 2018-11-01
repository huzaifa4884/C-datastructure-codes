#include <iostream>

using namespace std;
struct node
{
	int num;
	node *next;
};
class list
{
	private:
		node *head;
		node *tail;
	public:
		list()
		{
			head = tail = NULL;
		}
		void Append(int n)
		{
			if (head == NULL)
			{
				head = new node;
				head->num = n;
				head->next = NULL;
				return;
			}
				node *temp;
				temp = head;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
//				tail = new node;
//				temp->next = tail;
//				temp->num = n;
//				temp->next = NULL;
				tail = new node;
				temp->next = tail;
				tail->num=n;
				tail->next = NULL;
				
		}
		void Insertion(int n ,int pos)
		{

			node *temp ;
			temp = head;
			int c =0;
			while(temp ->next!= NULL || c == pos)
			{
				c++;
				temp = temp->next;
				
			}
			tail = new node;
			temp->next = tail;
			tail->num = n;
			
			tail->next = NULL;
		}
		void print()
		{
			node *temp ;
			temp = head;
			cout<<endl;
			while (temp != NULL)
			{
				cout<<temp->num;
				temp = temp->next;
			}
		}
		~list()
		{
			delete head;
			delete tail;
		}
};
int main()
{
	list l;
	cout<<"append";
	int n;
	cin>>n;
	l.Append(n);
	l.Append(2);
	l.Append(6);
	l.print();
//	l.Append(6);
//	l.print();
	
}

