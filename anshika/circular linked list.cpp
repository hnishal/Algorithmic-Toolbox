#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
};
void traverse(node*);
//void insertBeg(node **head);
//void insertEnd(node*);
//void insertPos(node*);
//void deleteBeg(node **head);
//void deleteEnd(node*);
//void deletePos(node*);
//void search(node*);
int main(){
	node *head=NULL;
	node *nodes, *temp;
	int n;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	cout<<"Enter the data in the linked list"<<endl;
	for(int i=0;i<n;i++){
		nodes= new node();
		cin>>nodes->data;
		nodes->next=head;
		if(head==NULL){
		    temp=head=nodes;
		}
		else{
		    temp->next=nodes;
		    temp=nodes;
		}
	}
	int choice;
	do{
	cout<<"---------------Menu-------------------"<<endl;
	cout<<"Enter 1 for traversing"<<endl;
	cout<<"Enter 2 for inserting node in the beginning"<<endl;
	cout<<"Enter 3 for inserting node in the end"<<endl;
	cout<<"Enter 4 for inserting node at a specified position"<<endl;
	cout<<"Enter 5 for deleting node from the beginning"<<endl;
	cout<<"Enter 6 for deleting node from the end"<<endl;
	cout<<"Enter 7 for deleting node at the spscified position"<<endl;
	cout<<"Enter 8 for searching node in the linked list"<<endl;
	cout<<"Enter 9 for exit"<<endl;
	cout<<"Enter the choice"<<endl;
	cin>>choice;
	switch(choice){
		case 1:
		cout<<"The nodes in linked list are:-"<<endl;
		    traverse(head);
		    break;
		/*case 2:
		    insertBeg(&head);
		    cout<<"The nodes in linked list after insertion in the beginning are:-"<<endl;
		    traverse(head);
		    break;
		case 3:
		    insertEnd(head);
		     cout<<"The nodes in linked list after insertion in the end are:-"<<endl;
		    traverse(head);
		    break;
		case 4:
		    insertPos(head);
		    cout<<"The nodes in linked list after insertion in the given position are:-"<<endl;
		    traverse(head);
		    break;
		case 5:
		    deleteBeg(&head);
		    cout<<"The nodes in linked list after deleting node form the beginning :- "<<endl;
		    traverse(head);
		    break;
		case 6:
		    deleteEnd(head);
		    cout<<"The nodes in linked list after deleting node form the end :- "<<endl;
		    traverse(head);
		    break;
		case 7:
		    deletePos(head);
		    cout<<"The nodes in linked list after deletion at a given position is:-"<<endl;
		    traverse(head);
		    break;
		case 8:
		    search(head);
		    break;*/
		case 9:
		    exit(0);
		    break;
		default:
			cout<<"Invalid choice"<<endl;
			break;	
	}
}while(choice!=10);
}
void traverse(node *temp){
	node *ptr;
	//ptr=temp;
    while(ptr!=temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
/*void insertBeg(node **temp){
    node *newnode= new node();
    cout<<"Enter the node which you want to insert in the beginning"<<endl;
    cin>>newnode->data;
    newnode->next=*temp;
    *temp=newnode;
}
void insertEnd(node *temp){
    node *newnode= new node();
    cout<<"Enter the node which you want to insert at th end of linked list"<<endl;
    cin>>newnode->data;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
}
void insertPos(node *temp){
    int pos;
    node* newnode=new node();
    cout<<"Enter the node for insertion"<<endl;
    cin>>newnode->data;
    cout<<"Enter the position"<<endl;
    cin>>pos;
    for(int i=0;i<pos-2;i++){
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
}
void deleteBeg(node **temp){
    node* ptr = *temp;
    *temp= ptr->next;
    delete ptr;
}
void deleteEnd(node *temp){
    node* ptr=temp;
 	node* end;
 	while(ptr->next!=NULL){
 		end=ptr;
 		ptr=ptr->next;
	 }
	 delete ptr;
	 end->next=NULL;
}
void deletePos(node* temp){
    int pos;
    cout<<"Enter the position for deletion of any node"<<endl;
    cin>>pos;
    node* ptr=temp;
 	node* previousNode;
 	for(int i=0;i<pos-1;i++){
 		previousNode=ptr;
 		ptr=ptr->next;
	 }
	 previousNode->next=ptr->next;
	 delete ptr;
}
void search(node* temp){
    int ele;
    cout<<"Enter the element for searching"<<endl;
    cin>>ele;
    int flag=0,c=0;
 	while(temp!=NULL){
 		c++;
 		if(temp->data==ele){
 			flag=1;	
 			break;
		 }
		 temp=temp->next;
	 }
	 if(flag!=0){
	 	cout<<" The Element is found at position= "<<c<<endl;
	 }
	 else{
	 	cout<<"Element not found!!!!!"<<endl;
	 }
}*/
