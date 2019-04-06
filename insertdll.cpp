 
void insert(node* head, string name) 
{ 
    if (head == NULL) 
    { 
    	node* new_node = new node; 
        new_node->data = name; 
        new_node->next = new_node;
		new_node->prev = new_node; 
        head = new_node;
		return ;
	}
	node *last = head->prev;  
   	node* new_node = new node; 
    new_node->data = name; 
    new_node->next = head; 
  	head->prev = new_node; 
  	new_node->prev = last; 
	last->next = new_node; 
} 

