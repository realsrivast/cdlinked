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

void del(node* head,int m)
{
    node*start;
    start=middle(head);
    node*temp=start;
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
        free(temp);
    }
}
