//============================================================================
// Name        : Pizza_Parlour.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 5

class pizza_parlour {
    int front,rear,count,num,pizza;
    string I[MAX];
    string x;
public:
    pizza_parlour() {
        front=0;
        rear=-1;
        count=0;
        num=1;
        pizza=0;
    }
    void getPizza() {
    	int size;
    	cout<<"Enter the respective number for ";
        cout<<"entering the choice of Pizza:\n";
        cin>>pizza;
        switch(pizza) {
        case 1:x="Margeritta";
               break;
        case 2:x="Double Cheese Margeritta";
               break;
        case 3:x="Farm House";
               break;
        case 4:x="Singles";
               break;
        case 5:x="Mexican Delight";
               break;
        case 6:x="Desi Dhamaka";
               break;
        case 7:x="Italian";
               break;
       default:"Sorry, choice is invalid, enter again.";
               getPizza();
               break;
        }

    }
    void menu();
    void displayAll();
    void placeOrder();
    int pickUpOrder();
    int removeOrder();
    int isFull();
    int isEmp();
};
void pizza_parlour::displayAll() {
	int i;
	if(isEmp()==0) {
	cout<<"Next orders are:\n";
	for(i=front;i<rear;i++) {
		cout<<I[i]<<"  ";
	}
	}

}
void pizza_parlour::menu() {
	cout<<"===== Here is your menu: ====\n";
	cout<<"1. Margeritta\n";
	cout<<"2. Double Cheese Margeritta\n";
	cout<<"3. Farm House\n";
	cout<<"4. Singles\n";
	cout<<"5. Mexican Delight\n";
	cout<<"6. Desi Dhamaka\n";
	cout<<"7. Italian\n";
	cout<<"==============================\n";

}
void pizza_parlour::placeOrder() {//sorts while adding new data
 menu();
 if(rear==-1)
     ++rear;
 if(isFull()==0) {
	 getPizza();
	 I[rear++]=x;
	 count++;
 }
 else {
	cout<<"\nPlease wait, our hands are currently full";
 }
}
int pizza_parlour::pickUpOrder() {
// num=(count+1)%(front+1);
char ch;
 if(isEmp()==0){
    cout<<"The order number "<<num;
    cout<<" is the next in line, to pick up:\n "<<I[front]<<"\n";
	cout<<"Are you order number "<<num;
	cin>>ch;
	if(ch=='y') {
		I[front++]==" ";
		num++;
	}
}
 return 0;
}

int pizza_parlour::isFull() {
    if((rear+1)%MAX==front)
      return 1;//isfull condition
    else
     return 0;
}
int pizza_parlour::isEmp() {
    if(rear==front||rear==-1){
        cout<<"\nOops, it seems we have no orders queued for delivery";
        cout<<"\nPlace your order first!";
    	return 1;//isempty condition
    }
    else
        return 0;
}
int main() {
	pizza_parlour q;

    int i,count=1;
    int choice;
    char ch;
    do{
    cout<<"Hello, How can we help you?\nEnter \n1.  to Place Order\n2.  to Pick up Order";
    cout<<"\n3.  Display current orders";
    cin>>choice;
    switch(choice){
    case 1:q.placeOrder();
           break;
    case 2:q.pickUpOrder();
           break;
    case 3:q.displayAll();
           break;
    default:cout<<"Wrong choice";
            break;
    }
    cout<<"\nThank You for ordering with us!\n";
    cout<<"Do you want to order again?y/n\n";
    cin>>ch;
    }while(ch=='y');
    return 0;
}
/* OUTPUT
Hello, How can we help you?
Enter
1.  to Place Order
2.  to Pick up Order
1
===== Here is your menu: ====
1. Margeritta
2. Double Cheese Margeritta
3. Farm House
4. Singles
5. Mexican Delight
6. Desi Dhamaka
7. Italian
==============================
Enter the respective number for entering the choice of Pizza:
1

Thank You for ordering with us!
Do you want to order again?y/n
y
Hello, How can we help you?
Enter
1.  to Place Order
2.  to Pick up Order1
===== Here is your menu: ====
1. Margeritta
2. Double Cheese Margeritta
3. Farm House
4. Singles
5. Mexican Delight
6. Desi Dhamaka
7. Italian
==============================
Enter the respective number for entering the choice of Pizza:
2

Thank You for ordering with us!
Do you want to order again?y/n
y
Hello, How can we help you?
Enter
1.  to Place Order
2.  to Pick up Order2
The order number 1 is the next in line, to pick up:
 Margeritta
Are you order number 1y

Thank You for ordering with us!
Do you want to order again?y/n
y
Hello, How can we help you?
Enter
1.  to Place Order
2.  to Pick up Order2
The order number 2 is the next in line, to pick up:
 Double Cheese Margeritta
Are you order number 2y

Thank You for ordering with us!
Do you want to order again?y/n
y
Hello, How can we help you?
Enter
1.  to Place Order
2.  to Pick up Order1
===== Here is your menu: ====
1. Margeritta
2. Double Cheese Margeritta
3. Farm House
4. Singles
5. Mexican Delight
6. Desi Dhamaka
7. Italian
==============================
Enter the respective number for entering the choice of Pizza:
5

Thank You for ordering with us!
Do you want to order again?y/n
y
Hello, How can we help you?
Enter
1.  to Place Order
2.  to Pick up Order2
The order number 3 is the next in line, to pick up:
 Mexican Delight
Are you order number 3y

Thank You for ordering with us!
Do you want to order again?y/n
n
*/

