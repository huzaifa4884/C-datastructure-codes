#include <iostream>

using namespace std;

struct node
{
	int data;
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
		~list()
		{
			delete head;
			delete tail;
		}
		void append(int x)
		{
			if (head == NULL)
			{
				head = new node;
				head->data = x;
				head->next = NULL;
				return;
			}
			node *temp;
			temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			tail = new node;
			tail->data = x;
			tail->next = NULL;
			temp->next = tail;
		}
		void insert(int x , int n)
		{
			if (head == NULL)
			{
				append(x);
				return;
			}
			node *temp;
			temp = head;
			while (temp->next != NULL)
			{
				if (temp->data == n)
				{
					break;
				}
				temp = temp->next;
			}
			tail = new node;
			tail->data = x;
			tail->next = temp->next;
			temp->next = tail;
		}
		void insert_index(int x , int ind)
		{
			int c = 0;
			node *temp;
			temp = head;
			while(temp->next != NULL)
			{
				if (ind - 1  == c)
				{
					break;
				}
				c++;
				temp = temp->next;
			}
			tail = new node;
			tail->data = x;
			tail->next = temp->next;
			temp->next = tail;
		}
		void print()
		{
			node *temp;
			temp = head;
			while(temp != NULL)
			{
				cout<<temp->data<<endl;
				temp = temp->next;
			}
		}
};

int main()
{
	list l;
	l.append(2);
	l.append(3);
	//l.append(4);
	l.append(6);
	l.append(7);
	l.insert_index(5 , 3);
	l.insert(4,3);
	l.print();
}
