#include<iostream>
#include "linkedlist-mod.cpp"//to include the linked list program
using namespace std;/*how to create a c++ header file*/

class stack//implementing stcak
{
	public:
	Node *top;//variable to point to the top
	LinkedList ll;
	stack()//default constructor
	{
		top=ll.head;;//assinging head to top
	}
	void push(int value)//push to add element in the top
	{
		ll.insertAt(1,value);//inserting at first position 
		top=ll.head;//modifying the top
	}
	void pop()//to delete the end element
	{
		ll.DeleteAt(1);//deleting the first element
		top=ll.head;//modifiying the top
	}
	bool isEmpty()//ckecking wheter it is emptyf 
	{
		if (top==NULL)
		return true;
		return false;
	}
	int size()
	{
		return ll.countItems();
	}
	void topdisplay()
	{
	
	}
	void display()
	{
		ll.display();
	}
};
int main()
{
	stack s1;
	int i;
	for(i=0;i<5;i++)
	{
		s1.push(i);
	}
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	return 0;
}
