
#include<iostream>
#include<math.h>
#include <fstream>
using namespace std;

struct node
{
    string name;
    node *next;
    node *prev;
};

node* head1 = NULL;
node* head2 = NULL;

int isprime(int n)
{
    if(n==1)
        return 1;
    else
    {
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
                return 0;
            else
                return 1;
        }
    }    
}

void insert1( string name) 
{ 
    if (head1 == NULL) 
    { 
    	node* new_node = new node; 
        new_node->name = name; 
        new_node->next = new_node;
		new_node->prev = new_node; 
        head1 = new_node;
		return ;
	}
	node* last = head1->prev;  
   	node* new_node = new node; 
    new_node->name = name; 
    new_node->next = head1; 
  	head1->prev = new_node; 
  	new_node->prev = last; 
	last->next = new_node; 
} 
void insert2( string name) 
{ 
    if (head2 == NULL) 
    { 
    	node* new_node = new node; 
        new_node->name = name; 
        new_node->next = new_node;
		new_node->prev = new_node; 
        head2 = new_node;
		return ;
	}
	node* last = head2->prev;  
   	node* new_node = new node; 
    new_node->name = name; 
    new_node->next = head2; 
  	head2->prev = new_node; 
  	new_node->prev = last; 
	last->next = new_node; 
} 


void Create()
{
    ofstream F;
    F.open("names.txt");
    string name;
    char choice;
    do
    {
        cout<<"Enter Name: "<<endl;
        cin>>name;
        F<<name<<endl;
        cout<<"More(Y/N)";cin>>choice;
    }
    while(choice!='N');
    F.close();
}

void Inlist()
{
    ifstream F;
    F.open("names.txt");
    char name[20];int count=0;
    while(F.getline(name,20))
    {
        count++;
        if(isprime(count))
        {
            insert1(name);
        }
        else
        {
            insert2(name);
        }
        cout<<endl;
    }
    F.close();
}

void display(node *head)
{
    node *temp = head;
    int flag = 0;
    if(head==NULL)
    {
    	cout<<"Empty list";
    	return;
	}
    while(flag!=1)
    {
        if(temp->next!=head)
        {
            cout<<temp->name<<endl;
            temp = temp->next;
        }
        else
        {
            flag = 1;
        }
        
    }
    cout<<temp->name<<endl;
}
node* middle(node *head)
{
    int flag=0;
    node* temp1=head,*temp2=head;
    while(flag!=1)
    {   
        if((temp2->next)->next!=head)
        {
            temp2=(temp2->next)->next;
            temp1=temp1->next;
        }
        else
        {
            flag=1;
            temp1=temp1->next;
            break;
        }
    }
    return temp1;
}
int count()
{
    int c=1,flag=0;
    node*temp=head1;
    while(flag!=1)
    {
        if(temp->next!=head1)
        {
            c++;
            temp=temp->next;
        }
        else
        {
            flag=1;
        }
        
    }
    return c;
}
void del()
{
    node*start;
    start=middle(head2);
    node*temp=start;
    int m=count();
    while(start!=NULL)
    {
        for(int i=0;i<m;i++)
            temp=temp->next;
        if(start->next!=start)
        {
            start=temp->next;
            (temp->prev)->next=temp->next;
            (temp->next)->prev=temp->prev;
        }
        else
            start=NULL;
        
        temp->next=NULL;
        temp->prev=NULL;
        delete temp;
    }
}

int main()
{
    Create();
    Inlist();
    cout<<"Prime\n";
    display(head1);
    cout<<"Not Prime\n";
    display(head2);
    del();
    cout<<"final list\n";
    display(head2);
    return 0;
}
