
#include <iostream>
#include <math.h>
using namespace std;
class poly;
class term
{
public :
	int coeff, deg;
};
class poly
{
public :
	int n;
	term T[100];
public :
	friend ostream& operator << (ostream&out,poly&p);
	friend istream& operator >> (istream&in,poly&p);
	friend poly sum (poly,poly);
	friend poly mult (poly, poly);
	void eval();
};
istream&operator>>(istream&in,poly&p)
{
	cout<<"\n Enter the total number of terms :"<<endl;
	in>>p.n;
	for(int i=0;i<p.n; i++)
	{
		cout<<"\n Enter the coefficients :"<<endl;
		in>>p.T[i].coeff;
		cout<<"\n Enter the degree :"<<endl;
		in>>p.T[i].deg;

	}
	return in;
}
ostream&operator<<(ostream&out,poly&p)
{
	out<<"\n The total number of terms are :"<<endl;
	out<<p.n;
	out<<"\n The polynomial is :"<<endl;
	for(int i=0; i<p.n; i++)
	{
		if(p.T[i].deg==0)
		{
			out<<p.T[i].coeff;
		}
		else
			out<<p.T[i].coeff<<"x^"<<p.T[i].deg<<"+";
		}
	return out;
}
void poly :: eval()
{int x, ans=0;
cout<<"enter the value of 'x'"<<endl;
cin>>x;
for(int i=0; i<n; i++)
  {
	ans = ans + T[i].coeff*(pow(x,T[i].deg));
  }
cout<<"the evaluation of the polynomial is :"<<ans<<endl;

}
poly add(poly c1,poly c2)

	{
	poly temp;
	int i=0,j=0,k=0;
	while((i<c1.n)&&(j<c2.n))
	{
	if(c1.T[i].deg==c2.T[j].deg)
	{
	temp.T[k].coeff=c1.T[i].coeff+c2.T[j].coeff;
	temp.T[k].deg=c1.T[i].deg;
	i++;j++;
	}
	else
	if(c1.T[i].deg<c2.T[j].deg)
	{
		temp.T[k].coeff=c2.T[j].coeff;
		temp.T[k].deg=c2.T[j].deg;
	j++;
	}
	else
	{
		temp.T[k].coeff=c1.T[i].coeff;
		temp.T[k].deg=c1.T[i].deg;
	i++;
	}
	k++;
	}
	while(i!=c1.n)
	{
		temp.T[k].coeff=c1.T[i].coeff;
		temp.T[k].deg=c1.T[i].deg;
	i++;
	k++;
	}
	while(j!=c2.n)
	{
		temp.T[k].coeff=c2.T[j].coeff;
				temp.T[k].deg=c2.T[j].deg;
	j++;
	k++;
	}
	temp.n=k;
	return(temp);
	}
poly mul (poly c1,poly c2)
{
	int c,e,flag;
	int i,j,k=0;

	poly d;
	d.n=0;
	for(i=0;i<c1.n;i++)
	{
		for(j=0;j<c2.n;j++)
		{
           c=c1.T[i].coeff*c2.T[j].coeff;
           e=c1.T[i].deg+c2.T[j].deg;
           k=0;
flag=0;
while(k<d.n&&flag==0)
           {
	if(d.T[k].deg==e)
	   {
		flag=1;
		break;
	   }
	else
	   {
		k++;
	   }
           }
if(flag==1)
           {
	d.T[k].coeff=d.T[k].coeff+c;
           }
else
           {
	d.T[k].coeff=c;
	d.T[k].deg=e;
	d.n++;
	k++;
           }
		}
	}
	cout<<"\nThe Multiplication of two polynomial is\n";

return d;

}

int main()
{


	int ch;
	char ans;
	poly p1,p2;
	poly s,m;

do
  {
	cout<<"\n1.Accept  and display first polynomial\n";
	cout<<"\n2.Accept and display second polynomial\n";
//	cout<<"\n3.Display first polynomial\n";
	//cout<<"\n4.Display second polynomial\n";
	cout<<"\n3.Evaluate first polynomial\n";
	cout<<"\n4.Evaluate second polynomial\n";
	cout<<"\n5.Add two polynomials\n";
	cout<<"\n6.Multiply two polynomial\n";
cout<<"\nEnter your choice\n";
	cin>>ch;
switch(ch)
	  {
	case 1:cin>>p1;
	cout<<p1;
	break;
	case 2:cin>>p2;
	cout<<p2;
	break;
	case 3:p1.eval();
	break;
	case 4:p2.eval();
	break;
	case 5:s=add(p1,p2);
	cout<<s;
	break;
	case 6:m=mul(p1,p2);
	cout<<m;
	break;
	/*case 7:
	break;
	case 8:
	break;*/
	default:cout<<"\nInvalid input\n";
	break;
	  }
	cout<<"\nDo you want to continue?\n";
	cin>>ans;
	}while(ans=='y');
	return 0;

}

/*
OUTPUT:
1.Accept  and display first polynomial

2.Accept and display second polynomial

3.Evaluate first polynomial

4.Evaluate second polynomial

5.Add two polynomials

6.Multiply two polynomial

Enter your choice
1    

 Enter the total number of terms :
3

 Enter the coefficients :
5

 Enter the degree :
3

 Enter the coefficients :
4

 Enter the degree :
2

 Enter the coefficients :
2

 Enter the degree :
1

 The total number of terms are :
3
 The polynomial is :
5x^3+4x^2+2x^1
Do you want to continue?
y

1.Accept  and display first polynomial

2.Accept and display second polynomial

3.Evaluate first polynomial

4.Evaluate second polynomial

5.Add two polynomials

6.Multiply two polynomial

Enter your choice
2

 Enter the total number of terms :
4

 Enter the coefficients :
4

 Enter the degree :
4

 Enter the coefficients :
3

 Enter the degree :
3

 Enter the coefficients :
2

 Enter the degree :
2

 Enter the coefficients :
1

 Enter the degree :
1

 The total number of terms are :
4
 The polynomial is :
4x^4+3x^3+2x^2+1x^1
Do you want to continue?
y

1.Accept  and display first polynomial

2.Accept and display second polynomial

3.Evaluate first polynomial

4.Evaluate second polynomial

5.Add two polynomials

6.Multiply two polynomial

Enter your choice
3
enter the value of 'x'
1
the evaluation of the polynomial is :11

Do you want to continue?
y

1.Accept  and display first polynomial

2.Accept and display second polynomial

3.Evaluate first polynomial

4.Evaluate second polynomial

5.Add two polynomials

6.Multiply two polynomial

Enter your choice
5

 The total number of terms are :
4
 The polynomial is :
4x^4+8x^3+6x^2+3x^1
Do you want to continue?
y

1.Accept  and display first polynomial

2.Accept and display second polynomial

3.Evaluate first polynomial

4.Evaluate second polynomial

5.Add two polynomials

6.Multiply two polynomial

Enter your choice
6

The Multiplication of two polynomial is

 The total number of terms are :
6
 The polynomial is :
20x^7+31x^6+30x^5+19x^4+8x^3+2x^2
Do you want to continue?
n
END PROGRAM
*/

