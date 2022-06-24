#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *npx;
};
node *h=NULL;
node *tail=NULL;
int size=0;
struct node *XOR(struct node *a,struct node *b)
{
   
	return (struct node*)((uintptr_t)(a)^(uintptr_t)(b));
}
void isempty()
{
	if(h==NULL)
	cout<<"list is empty"<<"\n";
	else
	cout<<"list is not empty"<<"\n";
}

void insertatend(int x)
{
	node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->npx=XOR(tail,NULL);
	if(h==NULL)
	{
		h=temp;
		size++;
	}
	if(tail!=NULL)
	{
		struct node *next=XOR(tail->npx,NULL);
		tail->npx=XOR(temp,next);
		size++;
	}
	tail=temp;
}
void insertatbegin(int x)
{
	struct node *current=h;
	node *t;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=x;
	if(h==NULL)
	{
		h=t;
		tail=h;
		size++;
	}
	else
	{
		
	current->npx = XOR(t, XOR(NULL, current->npx));
	t->npx=XOR(NULL,current);
	size++;
	}
	h=t;
}

void deleteatlast()
{
	if(h==NULL)
	cout<<"there is not element to delete in deque"<<"\n";
   if(h==tail) {
		delete h;
		h = tail = nullptr;
		size=0;
	} 
	else
	{
		node *prev=XOR(NULL,tail->npx);
		node *prev2=XOR(prev->npx,tail);
		prev->npx=XOR(NULL,prev2);
		tail=prev;
		size--;
		cout<<"element at back is deleted"<<"\n";
	}
}
void deleteatbegin() {
      	if(h==NULL)
     	cout<<"there is not element to delete in deque"<<"\n";
      if(h==tail) {
		delete h;
		h = tail = nullptr;
		size=0;
	} else {
		node *next = XOR(nullptr, h->npx);
		next->npx = XOR(nullptr, XOR(h, next->npx));
		delete h;
		h= next;
		size--;
	    cout<<"element at begin is deleted"<<"\n";
	}
}
void traverse()
{
	node *curr=h;
	node *prev=NULL;
	node *next;
	if(h==NULL)
	{
		cout<<"list is empty";
	}
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		next=XOR(prev,curr->npx);
		prev=curr;
		curr=next;
	}
	cout<<"\n";
}
void get2front()
{
	  if(h==tail) {
		delete h;
		cout<<"there is no 2nd front element"<<"\n";
		h = tail = nullptr;
		size=0;
	} else {
		node *next = XOR(nullptr, h->npx);
		next->npx = XOR(nullptr, XOR(h, next->npx));
		delete h;
		h= next;
		size--;
		cout<<"2nd front is"<<h->data<<"\n";
	}
	
}
void get2back()
{
   if(h==tail) {
		delete h;
		h = tail = nullptr;
		cout<<"there is no 2nd back element"<<"\n";
		size=0;
	} 
	else
	{
		node *prev=XOR(NULL,tail->npx);
		node *prev2=XOR(prev->npx,tail);
		prev->npx=XOR(NULL,prev2);
		tail=prev;
		cout<<"element of 2nd back is:"<<tail->data<<"\n";
		size--;
	}
}
void getfront()
{
	if(h==NULL)
	{
		cout<<"list is empty"<<"\n";
	}
	else
	{
		cout<<"front element is:"<<h->data<<"\n";
	}
}
void getback()
{
	if(h==NULL)
	{
			cout<<"list is empty"<<"\n";
	}
	else
	{
		cout<<"tail element is:"<<tail->data<<"\n";
	}
}
int main() {
	int opt,num;
    do
{
cout<<"1:insert element at head position"<<"\n";
cout<<"2:insert element at tail position"<<"\n";
cout<<"3:delete element at head position"<<"\n";
cout<<"4:delete element at tail position"<<"\n";
cout<<"5:get2nd head element "<<"\n";
cout<<"6:get2nd tail element "<<"\n";
cout<<"7:get size of linked list"<<"\n";
cout<<"8:is list empty"<<"\n";
cout<<"9:get head element "<<"\n";
cout<<"10:get tail element "<<"\n";
cout<<"11:traverse"<<"\n";
cout<<"enter ur choice:";
scanf("%d",&num);
switch(num)
{
	case 1:
	       int e;
           printf("Enter element to insert at begin\n");
           scanf("%d",&e);
           insertatbegin(e);
           break;
    case 2:
           int ele;
           printf("Enter element to insert at back\n");
           scanf("%d",&ele);
           insertatend(ele);
           break;
           
    case 3:
           deleteatbegin();
           break;
    case 4:
           deleteatlast();
           break;
    case 5:
          get2front();
          break;
    case 6:
          get2back();
          break;
    case 7:
          cout<<"size of linked list is:"<<size<<"\n";
          break;
    case 8:
          isempty();
          break;
    case 9:
          getfront();
          break;
    case 10:
          getback();
          break;
    case 11:
          traverse();
          break;
    default:
          printf("Invalid option\n");
          
     }
printf("\n Do you want to continue\n");
printf("\n press 1:YES 2:No\n");
scanf("%d",&opt);
}while(opt!=2);
	return 0;
}