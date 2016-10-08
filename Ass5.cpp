#include<iostream>
using namespace std;

class node {
  friend class list;
  int bit;
  node *next,*prev;
  public :
  node(int d) {
	bit=d;
	next=NULL;
	prev=NULL;
  }
};
class list {
  node *start;
  public:
	list() {
		start=NULL;
	}
    void delete_list();
	  void create_binary();
    void create_number(int);
    void create_decimal();
    list ones_com();
    void twos_comp();
    void add(list,list);
    void display();
    int count();

};
void list::delete_list() {
  node *ptr,*temp;
  ptr=start;
  while(ptr->next!=NULL) {
    temp=ptr;
    ptr=ptr->next;
    temp->next=NULL;
    delete temp;
    ptr->prev=NULL;
   
  }
  if(ptr->next==NULL && ptr->prev==NULL)
    start=NULL;
}
void list::create_number(int bit) {
   node *ptr,*temp;
   temp=new node(bit);
   if(start==NULL)
   	start=temp;
   else {
   	ptr=start;
   	while(ptr->next!=NULL) {
   		ptr=ptr->next;
   	}
   	ptr->next=temp;
   	temp->prev=ptr;
   }
}
void list::create_binary() {
  int n,bit;
  cout<<"How many bits are going to be entered?";
  cin>>n;
  cout<<"Enter the binary number bit by bit:\n";
  do{
  cin>>bit;
  create_number(bit);
  n--;
  }while(n>0);
}
void list::create_decimal() {
 int num,bit;
 node *ptr;
 cout<<"Enter the number in decimal to convert to binary";
 cin>>num;
 while(num!=0) {
  bit=num%2;
  create_number(bit);
  num=num/2;
  }

     ptr=start;
     cout<<"number(s) is"<<"\n";
     while(ptr->next!=NULL) {
     	ptr=ptr->next;
     }
     while(ptr!=NULL) { //*ptr=null implies adress and data=null
        cout<<ptr->bit<<" ";
        ptr=ptr->prev;
     }
     cout<<"\n";
}
list list::ones_com() {
  node *ptr,*temp,*trav_com;
  list com;//com=complemented object list
  int bit=0;
  ptr=start;
  while(ptr!=NULL) {
    temp=new node(bit);
        if(ptr->bit==1) {
              temp->bit=0;

        }
        else {
            temp->bit=1;

        }
        if(com.start==NULL)
            com.start=temp;

        else {
            trav_com=com.start;
            while(trav_com->next!=NULL) {
                trav_com=trav_com->next;//go to the end of the loop and add nodes.
             //cout<<"\nsaved node"; doesn't prin this!!
            }
            trav_com->next=temp;
            temp->prev=trav_com;
        }
        ptr=ptr->next;

  }
  return com;
}


void list::twos_comp() {

	node *ptr,*temp,*trav;
	list complement,two,one=ones_com();
    int count_=one.count(),i=0;
    while(i<count_) {
      temp=new node(0);
      if(two.start==NULL)
    	two.start=temp;
      else {
    	ptr=two.start;
    	while(ptr->next!=NULL) {
    		ptr=ptr->next;
    	}
    	ptr->next=temp;
    	temp->prev=ptr;
      }
      i++;
    }
    if(i==count_){
       temp=new node(1);
       ptr->next=temp;
       temp->prev=ptr;
    }
    complement.add(one,two); //adding one after reversing the bits of the given list, to get the complement.

}
void list::add(list a, list b) {
    node *ptr1,*ptr2,*temp,*temp_1,*trav;
    int carry=0,bit=0,sum=0,x,y;
    ptr1=a.start;
    ptr2=b.start;
    while(ptr1->next!=NULL) {
        ptr1=ptr1->next;
        }
    while(ptr2->next!=NULL) {
        ptr2=ptr2->next;
        }
    while(ptr1!=NULL && ptr2!=NULL) { //if you switch list 1 and 2 nodes wrt this loop,we get segmentation fault.
        x=ptr1->bit;
        y=ptr2->bit;
        sum=x^y^carry; //^ gives XOR gate
        carry=(x&(carry|y))|(x&y);
                               //set the carry value using full adder carry condition.
        temp=new node(sum);
        if(start==NULL)
          start=temp;
        else {
          trav=start;
          while(trav->prev!=NULL) {           //traverse new list till the end.
            trav=trav->prev;
           }
          trav->prev=temp;                  //store values the other way around.
          temp->next=trav;

        }
          ptr1=ptr1->prev;
          ptr2=ptr2->prev;
     }

     
      while(ptr1!=NULL){
     temp_1=new node(ptr1->bit^carry);
     temp_1->next=temp;
     temp->prev=temp_1;
     temp=temp_1;
     carry=ptr1->bit&carry;
     }
     

     
       while(ptr2!=NULL){
     temp_1=new node(ptr2->bit^carry);
     temp_1->next=temp;
     temp->prev=temp_1;
     temp=temp_1;
     carry=ptr2->bit&carry;
     }
    


     if(carry==1) {
     	temp_1=new node(1);
     	temp_1->next=temp;
     	temp->prev=temp_1;
     }

     node *ptr;
     ptr=start;
     cout<<"number(s) is"<<"\n";
     while(ptr->prev!=NULL) {
     	ptr=ptr->prev;
     }
     while(ptr!=NULL) { //*ptr=null implies adress and data=null
        cout<<ptr->bit<<" ";
        ptr=ptr->next;
     }
     cout<<"\n";
}
void list::display() {
   node *ptr;
   ptr=start;
   cout<<"number(s) is"<<"\n";
   while(ptr!=NULL) {
   	cout<<ptr->bit<<" ";
   	ptr=ptr->next;
   }
   cout<<"\n";


}
int list::count() {
   node *ptr;
   int count=1;
   ptr=start;
   while(ptr->next!=NULL) {
   	count=count +1;
   	ptr=ptr->next;
   }
   return count;
}

int main() {

 list l1,l2,res,l4,l3;
 int c,choice;
 char ch;
 l1.create_binary();
 cout<<"The first ";
 l1.display();
 do{
 cout<<"Choose operations to be done on number:\n1.1's complement\n2.count of nodes\n3.2's complement\n4.Add two numbers\n5.Convert from decimal to binary.";

 cin>>choice;
 switch (choice){
 case 1:cout<<"The ones complement of entered ";
        l3=l1.ones_com();
        l3.display();
        break;
 case 2:cout<<"In first list created ";
        c=l1.count();
        cout<<",total number of nodes is equal to "<<c<<"\n";
        break;
 case 3:cout<<"The twos complement of first";
        l1.twos_comp();
        break;
 case 4:l2.create_binary();
        cout<<"Second ";
        l2.display();
        cout<<"Addition of the two ";
        res.add(l1,l2);
        l2.delete_list();
        res.delete_list();
        break;
 case 5:l4.create_decimal();
        break;
 default:cout<<"invalid choice";
         break;
}
 cout<<"Do u want to continue?y/n";
 cin>>ch;
}while(ch=='y');
 cout<<"Thank you";
return 0;

}
