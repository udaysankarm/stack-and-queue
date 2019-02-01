#include<iostream>
#include"linkedlist-mod.cpp"
using namespace std;

class queue//implementing queue
{
	public:
	Node *end;//variable to point to the top
	Node *start;
	LinkedList ll;
	queue()//default constructor
	{
		end=ll.head;;//assinging head to top
		start=ll.last;
	}
	void	Enqueue(int value)// add element in the end
	{
		ll.insertAt(1,value);//inserting at first position 
		end=ll.head;//modifying the top
	}
	void Dequeue()//to delete the end element
	{
		ll.Delete();
	}
	bool isEmpty()//ckecking wheter it is emptyf 
	{
		if (end==NULL)
		return true;
		return false;
	}
	int size()
	{
		return ll.countItems();
	}
	/*void fornt()
	{
		cout<<ll.head->data;
	}*/
	void display()
	{
		ll.display();
	}
	/*void end()
	{
		cout<<ll.last->data;
	}*/
	
};
int main()
{
	queue A;
	for(int i=0;i<5;i++)
	A.Enqueue(i);
	A.display();
	A.Dequeue();
	A.display();
	A.Dequeue();
	A.display();
	cout<<A.size()<<endl;
	A.Enqueue(67);
	A.display();
	A.Enqueue(87);
	A.display();
	A.Dequeue();
	A.display();
	return 0;
}
