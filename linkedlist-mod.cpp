#include<iostream>
using namespace std;
class Node // each circles
{
	public:
	//data
	int data;
	//pointer to point ot next element
	Node *nxt;
	Node()
	{
		nxt=NULL;
	}
};

class LinkedList
{
	public:
	//head
	Node *head;
	Node *last;
	LinkedList()
	{
		head=NULL;
		last=NULL;
	}
	//insert
	void insert(int value)
	{
		//creating the new object
		Node *temp=new Node;
		//assinging the value to the new memory location
		temp->data=value;  
		//we need to assingn the pointing variable of last to the new object created
		//if it is the first element 
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			last->nxt=temp;
		}
		last=temp;
	}
	//display
	void display()
	{
		Node *current;//current stores the address of the current node
		current = head; //initializing current
		while(current!=NULL)// loop to swipe throughj the link list 
		{
			cout<<current->data<<"-> ";//printing the data in each
			current=current->nxt;//modifing the current node
		}
		cout<<"NULL"<<endl;
	}
	//insertAT
	void insertAt(int pos,int value)
	{
		Node *temp=new Node;// dynamically creating the memory for new node
		temp->data=value;//storing value in the new node
		if(pos >1)//if insertion is not at the first position
		{
			int i=1; //control variable
			Node *current=head;
			while(i<pos-1)//loop acessing each element
			{
				current=current->nxt;//acessing the next element
				if(current==NULL)
				{
					cout<<"\nThat many elements are not present in the linked list\n";
					break;
				}
				i++;//increamenting i		
			}
			if(current!=NULL)
			{
				temp->nxt=current->nxt;//storing the adress of (pos+1)th element in the new node
				current->nxt=temp;//storing the address of new node in (pos-1)th position
				if(temp->nxt==NULL)
				{
					last=temp;
				}
			}
		}
		else
		{
			temp->nxt=head;
			head=temp;
			if(head->nxt==NULL)
			last=head;
		}
	}
	//delete
	void Delete()
	{
		Node *current=head; //curent acceces each node
		while(current->nxt->nxt!=NULL)//loop to search fro end of linklist
		{
			current=current->nxt;//going to the next element
		}	
		Node*p=last;
		current->nxt=NULL;//making the current element the last 
		last->data=NULL; //erasing the value at the node that is to be deleted
		delete p;//delete last element
		last=current;// modifing last to the now location
	}
	void DeleteAt(int pos)
	{
		if(pos==1)
		{
			delete head;
			head=head->nxt;
		}
		else
		{
			Node *current,*temp;
			int i=1;
			current=head;
			while(i<pos-1)
			{
				current=current->nxt;
				i++;
			}
			temp=current;
			delete current->nxt;
			current->nxt=temp->nxt->nxt;
		}
	}
	int countItems()
	{
		int i=0;
		Node*current=head;
		while(current!=NULL)
		{
			current=current->nxt;
			i++;
		}
		return i;
	}
	void displayrevM()//primary function because we need the value of head 
	{
		displayrev(head);//calling the reversing fuction with the valie of head
		displayrevS(head);//calling the reversing function made by shubhanker
	}
	void displayrev(Node* start) //recursieve function starting from head
	{
		if(start->nxt==NULL) //condition checking (is the current is null) and thereby acess the last node
		{
			cout<<"NULL<-"<<start->data;//once last element is reached print the data
			return ;//going back to the previous function
		}
		else
		displayrev(start->nxt);//if the current node is nit the last one calling the fucntion again to acess the next node
		
		cout<<"<-"<<start->data;//once the above conditons are checked starts printing the data part of each node
	}
	void displayrevS(Node *current)
	{
		if(current==NULL) return;
		else
		{
			displayrevS(current->nxt);
			cout<<endl<<current->data;
		}
	}
	void revLLM()
	{
		Node*temp=head;
		revLL(head);
		temp->nxt=NULL;
		
	}
	void revLL(Node *current)
	{
		//we need to go through each node
		if(current==NULL) return;//control condition
		else if(current->nxt==NULL) 
		{
			last=head;
			head=current;
			return;
		}
		else
		{
			revLL(current->nxt);
			current->nxt->nxt=current;
		}

	}
	/*void insertN()
	{
		// if
		//Node *temp=new Node;
		//
		//temp->data=value;
		
		Node **curr=&head; //data_type *A=&d; means A points to d 
		//*curr=temp; // Node **curr=&head; is same as >> (Node **curr;  *curr=&head;) means *curr holds the address the address of head  ?????????????????????????????!!!!!!!!!!!!!!!!!!!!!!!!
		cout<<**curr->data;
	}*/
	
};
/*int main()
{
	LinkedList A;
	A.insert(5);
	A.insert(3);
	A.insert(4);
	A.insert(7);
	A.insertAt(5,9);
	A.Delete();
	A.display();
	A.insert(6);
	A.insert(11);
	A.display();
	//A.revLLM();
	//A.display();
	A.Delete();
	A.display();
	A.insert(6);
A.display();
	//A.insertAt(3,56);
	//A.display();
	//A.insertN();
	return 0;
}*/
