#include<fstream>
#include<iostream>
#include<math.h>
using namespace std;

struct node
{
    string name;
    node *next;
    node *prev;
}

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

void insert(node* head, string name) 
{ 
    if (head == NULL) 
    { 
    	node* new_node = new node; 
        new_node->name = name; 
        new_node->next = new_node;
		new_node->prev = new_node; 
        head = new_node;
		return ;
	}
	node* last = head->prev;  
   	node* new_node = new node; 
    new_node->name = name; 
    new_node->next = head; 
  	head->prev = new_node; 
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
            insert(head1,name);
        }
        else
        {
            insert(head2,name);
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
}

int main()
{
    Create();
    Inlist();
    display();
    return 0;
}