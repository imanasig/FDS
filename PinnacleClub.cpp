#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int PRN;
	char name[50];
	node* next;
};

class Pinacle_Club
{ 
    node *head;
 public:
	Pinacle_Club();
	node* create();  
	void display();
	node* search(int );
	int total();
	node* remove();
	node* getnode();
	void insert_Member();
	node* insert_President();
	void insert_Secretary();
	node* concat(node* ,node*);
};

Pinacle_Club::Pinacle_Club()//constructor defined
{
	head = NULL;//initialize head to NULL
}

node *Pinacle_Club::getnode()
{
	node *p;
	p = new node;
	if (p == NULL)
		cout << "Unable to allocate memory\n";
	else
	{	
	cout << "\n Enter The PRN of the Student: ";
	cin >> p->PRN;
	cout << "\n Enter The name of the Student: ";
	cin >> p->name;
	p->next=NULL;
	}	
	return p;
}
void Pinacle_Club::insert_Member()
{
	int key;
	node  *temp, *p,*q;
	p=getnode();
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		cout << "\n Enter The PRN after which you want to insert the node: ";
		cin >> key;
		temp=search(key);
		p->next=temp->next;
		temp->next=p;
	}
	cout << "\nThe member is inserted\n";	
}

//Function to insert at the beginning
node* Pinacle_Club::insert_President()
{
	node  *temp, *p;
	p=getnode();
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
	cout << "\nThe President is inserted\n";
	return(head);
}

void Pinacle_Club::insert_Secretary()
{
	node *temp, *p;
	p=getnode();
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = p;
	}
	cout << "\nThe Secretory is inserted\n";
}
// The Create function
node* Pinacle_Club::create()
{
	char ans;
	node *temp,*p;
	head=NULL;
	
	do
	{
		p = getnode();
		
		if (head==NULL) // Executed only for the first time
		{
			head = p;
			temp=head;
		}
		else
		{
		/*temp last keeps track of the most recently created node*/
			temp->next =p;
			temp = p;
		}
		cout << "\n Do you want to enter more elements?(y/n)";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');
	return(head);
}
// The display function
void Pinacle_Club::display()
{
	node* temp;
	temp = head;
	if (temp == NULL)
	{
		cout << "\nThe list is empty\n";
		return;
	}
	while (temp != NULL)
	{
		cout <<"["<< temp->PRN << ","<<temp->name<<"]"<<"->";
		temp = temp -> next;
	}
}

// The total function
int Pinacle_Club::total()
{
	node *temp;
	int count = 0;
	temp = head;
	if (temp == NULL)
	{		
		return -1 ;
	}
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return(count);
}

		// The display function
node *Pinacle_Club::search(int num)
{
	struct node *temp;
	temp = head;
	
	while (temp != NULL)
	{
		if(num==temp->PRN)
			return temp;
		else
			temp=temp->next;
	}
	return temp;
}

node *Pinacle_Club::concat(node * head1,node *head2)
{
	struct node *temp;
	temp = head1;
	
	while (temp->next != NULL)
	{
		temp=temp->next;
	}
	
	temp->next=head2;
	head=head1;
	return head;
}

node *Pinacle_Club::remove()
{
	node *temp, *q;
	int  key;
	//prev = new node;
	temp = head;
	cout << "\nEnter the PRN of the node you want to delete: ";
	cin >> key;
	while (temp != NULL)
	{
		if (temp->PRN == key)//  traverse till required node to delete
			break;           //  is found
		q = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		cout << "\nNode not found";
	else
	{
		if (temp == head) //first node
			{
			head = head->next;
			temp->next=NULL;
			delete (temp);
			}
		else
			{
				q->next = temp->next;  //intermediate or end node
		        temp->next=NULL;
				delete temp;
		    }
		cout << "\nThe member is deleted\n";
	}
	return head;
}

	// The main function
int main()
{
	Pinacle_Club s;
	node *x,*head=NULL,*head1=NULL,*head2=NULL;
	int choice,num,ch1,count;
	while(1)
	{
		cout << "\n1.Create";
		cout << "\n2.Display Members";
		cout << "\n3.Total Number of Members of Club";
		cout << "\n4.Insert member";
		cout << "\n5.Remove member";
		cout << "\n6.Concate";
		cout << "\n7.Quit";
		cout << "\nEnter Your Choice ( 1-7): ";
		cin >> choice;
		switch (choice)
		{
		case 1:	head=s.create();
			break;
		case 2:	s.display();
			break;
		case 3:count=s.total();
			if(count==-1)
			cout << "\nThe list is empty\n";
			else
			cout<<"\nTotal members="<<count;
			break;
		case 4:
			cout << "\nMenu";
			cout << "\n1.Insert President";
			cout<< "\n2.Insert Member";
			cout << "\n3.Insert Secretary";
			cout << "\nEnter your choice: ";
			cin >> ch1;
			switch (ch1)
			{
			case 1:head=s.insert_President();
				break;
			case 2:s.insert_Member();
				break;
			case 3:s.insert_Secretary();
				break;
			default:cout << "\nInvalid choice";
			}
			break;
		case 5:
			head=s.remove();
			break;	
		case 6:
			cout<<"Enter data for division 1";
			head1=s.create();
			cout<<"Enter data for division 2";
			head2=s.create();
			head=s.concat(head1,head2);
			break;
		case 7: cout<<"\nQuiting a program ";
			exit(0);
		default: cout  << "\nInvalid choice";
		}	
	} 
	return 0;
}
