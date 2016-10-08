#include<iostream>
#include<string.h>
#define MAX 50
using namespace std;

class Set {
	int i;
	char a[MAX];
    friend class String;
	public:
	 Set() {
	 	i=0;
	 } 
};

class String {
    int cnt;
	Set str[50];

public:
	String() {
		cnt=0;
	}
	void display();
	void copy();
	void concat();
	int sub();
	void equal();
	void rev();
	int len(int);
	void choice();
};
void String::equal(){
char l1[20],l2[20];
    int i=0,j=0;
    cout<<"enter first string=>";
    cin>>l1;
    cout<<"enter second string=>";
    cin>>l2;
    while((l1[i]!='\0')&&(l2[j]!='\0')&&(l1[i]==l2[j]))
    {
      i=i+1;
      j=j+1;
    }
    if((l1[i]=='\0')&&(l2[i]=='\0'))
      cout<<"\nstrings are equal\n";
    else
      cout<<"\nstrings are  not equal\n";

}
void String::copy() {
    int i;
    char ch;
    cout<<"Enter # to end string";
    cin>>str[cnt].a;
    cnt++;
    cout<<"Do u want to continue adding more strings?";
    cin>>ch;
    if(ch=='y')
     	copy();

}
int String::len(int atPres){
	  int count=0;
      int i;
	  for(i=0;i<MAX;i++){
	  	if(str[atPres].a[i]=='\0')
       	   break;
        else
      	   count=count+1;
     }
     return count;
}

void String::display(){
	int i,atPres=0;
	while(atPres<cnt){
	  if(atPres!=0)
	  	cout<<" ";
	  cout<<str[atPres].a;
    atPres++;
   }
}

void String::concat(){
	int i,Len;
	cout<<cnt;
    cout<<"Add two strings to be concatenated\n";
    copy();
    cout<<"Second string will be added to first string that you have entered.\n";
    Len=len(cnt-2);
    for(i=0;i<len(cnt-1);i++)
    	str[cnt-2].a[Len++]=str[cnt-1].a[i];
    	cout<<str[cnt-2].a;

}
void String::rev(){
    int Len=len(cnt-1);
    int i,j=Len-1;
    for(i=0;i<Len;i++) 
    	str[cnt].a[i]=str[cnt-1].a[j--];
    cout<<"String one is \n";
    cout<<str[cnt].a;
    cnt++;
}
int String::sub() {

  int l1,l2,flag,i,j;
  char str1[20],str2[20];
    cout<<"enter first string=>";
    cin>>str1;
    cout<<"enter second string=>";
    cin>>str2;
    l1=strlen(str1);
    l2=strlen(str2);
    i=0;
    while(i<l1)
    {
      j=0;
      flag=1;
      while(j<l2)
      {
        if(str1[i]!=str2[j])
        {
          flag=0;
          break;
        }
        else
        {
          flag=1;
          j++;
          i++;
        }
      }
      if(flag)
      {
        return i;
      }
      else
        i++;
    }
    return(-1);
 }
void String::choice(){
    int choice;
    char ch; 
    do{
     cout<<"Choose operation:";
     cout<<"\n1.input string\n2.concat two strings\n3find substring\n4.check for equal\n5.reverse\n6.Length of string\n7.Display all strings";
     cin>>choice;
     switch(choice) {
      case 1:copy();break;
      case 2:concat();break;
      case 3:int m;
             m=sub();
             if(m==-1)
                cout<<"substring  not found\n";
             else
                cout<<"substring   found\n";
             break;
      case 4:equal();
             break;
      case 5:cout<<"Enter string to reverse";
             copy();
             rev();
             break;
      case 6:cout<<"Enter string to check length\n";
             copy();
             cout<<"Length is: ";
             cout<<len(cnt-1);break;
      case 7:display();break;
      default:cout<<"\nWrong input";
     }
    cout<<"\nDo u want to continue?";
    cin>>ch;
    }while(ch=='y');

}

int main() {

    
    String s1,s2;
    s1.choice();
  
return 0;
}
/*
OUTPUT:
Choose operation:
1.input string
2.concat two strings
3find substring
4.check for equal
5.reverse
6.Length of string
7.Display all strings1
Enter # to end string    
hello
Do u want to continue adding more strings?y
Enter # to end stringworld
Do u want to continue adding more strings?n

Do u want to continue?y
Choose operation:
1.input string
2.concat two strings
3find substring
4.check for equal
5.reverse
6.Length of string
7.Display all strings2
2Add two strings to be concatenated
Enter # to end string
how
Do u want to continue adding more strings?y
Enter # to end stringare
Do u want to continue adding more strings?n
Second string will be added to first string that you have entered.
howare
Do u want to continue?y
Choose operation:
1.input string
2.concat two strings
3find substring
4.check for equal
5.reverse
6.Length of string
7.Display all strings3
enter first string=>     
miami
enter second string=>mi
substring   found

Do u want to continue?y
Choose operation:
1.input string
2.concat two strings
3find substring
4.check for equal
5.reverse
6.Length of string
7.Display all strings4
enter first string=>miamiami
enter second string=>miam

strings are  not equal

Do u want to continue?y
Choose operation:
1.input string
2.concat two strings
3find substring
4.check for equal
5.reverse
6.Length of string
7.Display all strings5
Enter string to reverseEnter # to end string
india
Do u want to continue adding more strings?n
String one is 
aidni
Do u want to continue?y
Choose operation:
1.input string
2.concat two strings
3find substring
4.check for equal
5.reverse
6.Length of string
7.Display all strings 
6
Enter string to check length
Enter # to end string
newworld      
Do u want to continue adding more strings?n
Length is: 8
Do u want to continue?y
Choose operation:
1.input string
2.concat two strings
3find substring
4.check for equal
5.reverse
6.Length of string
7.Display all strings7
hello world howare are india aidni newworld
Do u want to continue?n

ENDPROGRAM

*/