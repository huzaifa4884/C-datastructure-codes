#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};
class que
{
	private:
		node *front,*rear;
	public:
		que()
		{
			front = NULL;
			rear = NULL;
		}
		void enque(int x)
		{
			if (front == NULL)
			{
				front = new node;
				front->data = x;
				front->next = NULL;
				rear = front;
				return;
			}
			node *temp = new node;
			temp->data = x;
			temp->next = NULL;
			rear->next = temp;
		}
		~que()
		{
			delete front;
			delete rear;
	}
};

int main()
{
	que l;
	l.enque(2);
	l.enque(3);
}
