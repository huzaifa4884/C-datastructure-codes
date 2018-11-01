#include <iostream>
#include <conio.h>

using namespace std;
struct node
{
	char info[15];
};
class trial
{
	private:
		node obj1, *temp1 , *temp2, *temp3;
		int i,length;
		char *p , *q;
	public:
		trial()
		{
			temp1 = temp2 = temp3 = NULL;
		}
		~trial()
		{
			delete temp1, temp2 , temp3;
			delete[] p;
		}
		void starting()
		{
			cout<<"making use of new delete"<<endl;
			temp1 = new node;
			temp2 = new node;
			cout<<"info about temp1"<<endl;
			cin>>temp1->info;
			cout<<"info about temp2"<<endl;
			cin>>temp2->info;
			cout<<"info about temp3"<<endl;
			temp3 = &obj1;
			cin>>temp3->info;
			
			cout<<"show info about temp1  :"<<temp1->info;
			cout<<"show indo about temp2  :"<<temp2->info;
			cout<<"show indo about temp3  :"<<temp3->info;
			cout<<endl<<endl<<"now enter length of array"<<endl;
			cin>>length;
			p = new char[length];
			q = p;
			cout<<"now enter characters to fill an array";
			for (int i =0; i<length; i++)
			{
				cin>>*p;
				p = p + 1;
			}
			p = q;
			for (int i =0; i<length; i++)
			{
				cout<<*p;
				p = p + 1;
			}
			p = q;
			
		}
};

int main()
{
	trial l;
	l.starting();
	getch();
}
//int main()
//{
//	int x =5;
//	int *p;
//	p =  &x;
//	cout<<*p<<endl;
//	cout<<x<<endl;
//	*p =9;
//	cout<<"&X        "<<&x<<endl;
//	cout<<"*&PTR     "<<*&p<<endl;
//	cout<<"&*p       "<<&*p<<endl;
//	cout<<"p         "<<p<<endl;
//	cout<<*p<<endl;
//	cout<<x<<endl;
//	int *ptr1 = new int;
//	int *ptr2 = new int;
//	*ptr2 = 44;
//	*ptr1 = *ptr2;
//	cout<<*ptr1<<"   address   "<<ptr1<<endl;
//	cout<<*ptr2<<"   address   "<<ptr2;
//	delete ptr1;
//	delete ptr2;
//	cout<<endl<<"deleted successfully";
//}
