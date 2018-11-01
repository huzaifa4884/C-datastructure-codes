#include<iostream>

using namespace std;

struct node
{
	int data;
	node *prev;
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
		void append(int x)
		{
			if (head == NULL)
			{
				head = new node;
				head->data = x;
				head->next = NULL;
				head  ->prev = NULL;
				return;
			}
			node *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			node *temp1 = new node;
			temp1->data = x;
			temp1->next = NULL;
			temp1->prev = temp;
			temp->next = temp1;
		}
		void insert(int x , int n)
		{
			if (head == NULL)
			{
				cout<<"What fuck bro are you high";
				return;
			}
			node *temp = head;
			while(temp->next != NULL)
			{
				if (temp->data == n)
				{
					node *temp1 = new node;
					temp1->data = x;
					temp1->next = temp->next;
					temp->next = temp1;
					temp1->prev = temp;
				}
				temp = temp->next;
			}
			if(temp->data == n)
			{
				node *temp1 = new node;
				temp1->data = x;
				temp1->next = temp->next;
				temp->next = temp1;
				temp1->prev = temp;
				return;
			}
			else return;
		}
		void insert_ind(int x , int ind)
		{
			if (head == NULL)
			{
				cout<<"WTF are you mad theres nothind in list";
				return;
			}
			int c = 1;
			node *temp = head;
			while(temp->next != NULL)
			{
				if (ind == 0)
				{
					node* temp1 = new node;
					temp1->data = x;
					temp1->next = head;
					head->prev = temp1;
					temp1->prev = NULL;
					head = temp1;
					return;
				}
				temp = temp->next;
				c++;
				if (c == ind)
				{
					break;
				}
			}
			node *temp1 = new node;
			temp1->data = x;
			temp1->next = temp->next;
			temp1->prev = temp;
			temp->next = temp1;
			return;
		}
		void print()
		{
			node *temp;
			temp = head;
			while(temp != NULL)
			{
			cout<<temp->data<<"  ";
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
	l.append(2);
	l.append(3);
	l.append(22);
	l.append(3);
	l.append(4);
	l.append(3);
	l.insert_ind(4,0);
	l.print();
}
