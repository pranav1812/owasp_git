#include <iostream>
using namespace std;
struct node{
	int data;
	node *next;
	node *prev;
};
class Linked_list
{
	private:
		node *start;
	public:
		Linked_list()
		{
			start=NULL;
		}
		void insert_end();	
		void display();
		void removeParity();
};
void Linked_list::insert_end()
{
	int n;
	cout<<"Enter the value\n";
	cin>>n;
	node *temp=new node;
	temp->data=n;
	temp->next=NULL;
	temp->prev=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		node *ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->prev=ptr;
	}
}
void Linked_list::removeParity()
{
	int parity;
	int arr[100];
	node *ptr=start;
	while(ptr!=NULL)
	{
		int i=0;
		parity=0;
		for(int i=0;i<sizeof(arr)/4;i++)
		{
			arr[i]=0;
		}
		int a=ptr->data;
		while(a>0)
		{
			arr[i]=a%2;
			a=a/2;
			i++;
		}
		for(int i=0;i<sizeof(arr)/4;i++)
		{
			if(arr[i]==1)
			{
				parity++;
			}
		}
		if(parity%2==0)
		{
			if(ptr==start)
			{
				start=ptr->next;
				ptr->next=NULL;
				ptr->prev=NULL;
				delete(ptr);
				ptr=start;
			}
			else if(ptr->next==NULL)
			{
				node *temp=ptr;
				ptr=ptr->prev;
				ptr->next=NULL;
				temp->prev=NULL;
				delete(temp);
			}
			else
			{
				(ptr->prev)->next=ptr->next;
				(ptr->next)->prev=ptr->prev;
				node *temp=ptr;
				ptr=ptr->prev;
				temp->next=NULL;
				temp->prev==NULL;
				delete(temp);
			}
		}
		else
		{
			ptr=ptr->next;
		}
	}
} 
void Linked_list::display()
{
	node *ptr=start;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"\t";
		ptr=ptr->next;
	}
	cout<<endl;
}
int main()
{
	Linked_list l1;
	int n;
	cout<<"Enter the number of nodes:\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		l1.insert_end();
	}
	l1.display();
	l1.removeParity();
	l1.display();
}
