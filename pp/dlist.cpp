#include <iostream>

using namespace std;

struct node
{
	int info;
	node *next;
	node *prev;
};

class list
{
	private:
		node *head;
	public:
		list()
		{
			head = NULL;
		}
		
		void insert(int num)
		{
			node *temp = head;
			if (head == NULL)
			{
				temp = new node;
				temp->next = NULL;
				temp->prev = NULL;
				temp->info = num;
				head = temp;
				return;
			}
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new node;
			temp->next->info = num;
			temp->next->next = NULL;
			temp->next->prev = temp;
			return;
		}
		void insert_bi(int num,int ind)
		{
			node *temp = head;
			if (head == NULL)
			{
				cout<<"no chay sa shta na no kuna ke de chunjay wo chay da ftn de call ko wrsha append ftn call ka";
				return;
			}
			int count = 0;
			while(temp->next !=NULL && count != ind-1)
			{
				temp = temp->next;
				count++;
			}
			node *temp2 = new node;
			temp2->info = num;
			temp2->next = temp->next;
			temp2->prev = temp;
			temp->next = temp2;
			return;
		}
		void print()
		{
			node *temp = head;
			while(temp != NULL)
			{
				cout<<temp->info<<"    zalima ochala"<<endl;
				temp = temp->next;
			}
		}
		void deletion(int num)
		{
			node *temp = head;
			while (temp->next != NULL)
			{
				if (temp->next->info == num)
				{
					break;
				}
				temp = temp->next;
			}
			node *temp2 = temp->next->next;
			delete temp->next;
			temp->next = temp2;
			temp2->prev = temp;
		}
		~list()
		{
			delete head;
		}
};
int main()
{
	list ls;
	ls.insert(23);
	ls.insert(24);
	ls.insert(25);
	ls.insert(26);
	ls.insert(27);
	ls.insert_bi(245,1);
	ls.deletion(27);
	ls.print();
	
}
