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

void del(node* start,int m) 
{ 
    if (start == NULL) 
        return; 
  
    node *temp = start, *prev_1 = NULL; 
    while (temp -> data != name) 
    { 
        if (curr->next == start) 
        { 
            printf("\nList doesn't have node with value = %d", key); 
            return; 
        } 
  
        prev_1 = curr; 
        curr = curr -> next; 
    } 
  
    // Check if node is the only node in list 
    if (curr -> next == start && prev_1 == NULL) 
    { 
        (start) = NULL; 
        free(curr); 
        return; 
    } 
  
    // If list has more than one node, 
    // check if it is the first node 
    if (curr == start) 
    { 
        // Move prev_1 to last node 
        prev_1 = (start) -> prev; 
  
        // Move start ahead 
        *start = (start) -> next; 
  
        // Adjust the pointers of prev_1 and start node 
        prev_1 -> next = start; 
        start -> prev = prev_1; 
        free(curr); 
    } 
  
    // check if it is the last node 
    else if (curr->next == start) 
    { 
        // Adjust the pointers of prev_1 and start node 
        prev_1 -> next = start; 
        start-> prev = prev_1; 
        free(curr); 
    } 
    else
    { 
        // create new pointer, points to next of curr node 
        struct Node *temp = curr -> next; 
  
        // Adjust the pointers of prev_1 and temp node 
        prev_1 -> next = temp; 
        temp -> prev = prev_1; 
        free(curr); 
    } 
} 
  