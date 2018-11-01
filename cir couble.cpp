#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
	node *prev;
};
class clist
{
	private:
		node *head;
	public:
		clist()
		{
			head = NULL;
		}
		void append(int x)
		{
			if (head == NULL)
			{
				head = new node;
				head->data = x;
				head->next = head;
				head->prev = head;
				return;
			}
			node *temp = new node;
			temp->data = x;
			temp->next = head;
			temp->prev = head->prev;
			head->prev->next = temp;
			head->prev = temp;
		}
		void print()
		{
			node *temp = head;
			do	{
				cout<<temp->data<<"   ";
				temp = temp->next;
			}			while(temp != head);

		}
		~clist()
		{
			delete head;
		}
};
int main()
{
	clist l;
	l.append(2);
	l.append(3);
	l.print();
}
