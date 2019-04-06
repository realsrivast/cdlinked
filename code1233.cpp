
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

int main()
{
    Create();
    Inlist();
    c
    display(head1);
    display(head2);
    return 0;
}
