/*node* middle(node *head)
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
*/
int count(node*head)
{
    int c=1,flag=0;
    while(flag!=1)
    {
        if(temp->next!=head)
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

