/*
The purpose of this code is to find out solution for any equation (including the equation containing trigonometric functions and exponents as well.
It can also give you normal integration and integration by the two other methods that are
		trapezoidal rule :
		simp-son's rule :
	The Trapezoid Rule is nothing more than the average of the left-hand and right-hand Riemann Sums. It provides a more accurate approximation of total change than either sum does alone. Simpson's 	Rule is a weighted average that results in an even more accurate approximation.	
Also this code can multiply matrices and provide you the cofactors and inverse of the matrix:
WORKING OF THE CODE:
1. There is a structure which contain two int values and one char value for accepting the variables. Integers are for coefficients and the power.
The we have an integrating function and a differentiating function which simply does coeff=coeff*pow and then pow--or whatever is required. 

*/

#include<iomanip.h>
#include<conio.h>
#include<math.h>
#include<constrea.h>
#include<stdlib.h>
#include<dos.h>
class nr
{       public:
	int coef,pow;
	char term;
	void input()
	{

		cout<<"enter the coefficient\t";
		cin>>coef;
		cout<<"enter the variable";
		cin>>term;
		cout<<"enter the power \t\n";
		cin>>pow;
		cout<<"the term is"<<coef<<term<<pow<<"\n";

	}
	void view()
	{
		cout<<coef<<term;
	}
	void deriv()
	{
		if(term=='x'||term=='y')
		  {
			coef*=pow;
			pow--;
		  }
		else if(term=='s')
		{
			term='c';
		}
		else if(term=='c')
		{
			term='s';
		}
	}
	void ig()
	{
		if(term=='x'||term=='y')
		  {
			coef=coef/(pow+1);
			pow++;
		  }
		else if(term=='s')
		{
			term='c';
			coef*=-1;
		}
		else if(term=='c')
		{
			term='s';
		}

	}
};
void mm()
{
	int a[10][10],b[10][10],c[10][10];
	int m,n,i,j,k;
	cout<<"enter the dimension of the matrix";
	cin>>m>>n;
	cout<<"enter the elements of the first mattrix";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"enter the elements of the second matrix";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>b[i][j];
		}
	}
	cout<<"the third matrix is \n";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=0;
			for(k=0;k<n;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<c[i][j]<<" ##";
		}
		cout<<"\n";
	}
}
double sol(nr obj[10],double n,double q,double z)
{

	double t=0;
		for(double i=0;i<n;i++)
		{       if(obj[i].term=='x')
			{
				t+=obj[i].coef*pow(q,obj[i].pow);

			}
			 if(obj[i].term=='y')
			{
				t+=obj[i].coef*pow(z,obj[i].pow);

			}
			else if(obj[i].term=='s')
			{
				t+=obj[i].coef*sin(pow(q,obj[i].pow));

			}
			else if(obj[i].term=='c')
			{
				t+=obj[i].coef*cos(pow(q,obj[i].pow));

			}
		}
       return(t);

}
double dsol(nr obj[10],double n,double q)
{
	nr dbj[10];
	 for(double i=0;i<n;i++)
	 {
	     dbj[i].coef=obj[i].coef;
	     dbj[i].pow=obj[i].pow;
	     dbj[i].term=obj[i].term;
	 }
	 for(i=0;i<n;i++)
	 {
		dbj[i].deriv();

	 }

	double t=0;
	for(i=0;i<n;i++)
	{
		if(dbj[i].term=='x'||dbj[i].term=='y')
		{
			t+=dbj[i].coef*pow(q,dbj[i].pow);
		}
		else if(dbj[i].term=='s')
		{
			t+=dbj[i].coef*sin(q);
		}
		else if(dbj[i].term=='c')
		{
			t+=dbj[i].coef*cos(q);
		}
	}
       return(t);
}
void newr(nr obj[10],double n)
{
	double xn=20;
	double h,i,j;

	i=sol(obj,n,2,0);
	cout<<i;

	do
	{
		i=sol(obj,n,xn,0);
		j=dsol(obj,n,xn);
		h=i/j;
		xn=xn-h;
	}while(h>=0.00001);
		i=sol(obj,n,xn,0);
		j=dsol(obj,n,xn);
		h=i/j;
		xn=xn-h;
		cout<<"the root is :"<<xn;

}
void trap(nr obj[10],double n)
{
	long double i,h=0,xn,b,a,s=0;
	cout<<"enter the lower and upper limit and then divison";
	cin>>a>>b>>xn;
	h=(b-a)/xn;
	double c=0;
	for(i=a;i<=b;i+=h)
	{

		if(i==a||i==b)
		{
			s+=h*sol(obj,n,i,0)/2;

		}
		else
		{
			s+=h*sol(obj,n,i,0);

		}
	}
	cout<<"Answer by the trapezoidal method = "<<s;
	for(i=0;i<n;i++)
	{
		obj[i].ig();
	}
	i=sol(obj,n,b,0)-sol(obj,n,a,0);
	c=(i-s)/i;
	cout<<"\nexact answer is= "<<i;
	cout<<"\n % error="<<c*100;

}
void simp(nr obj[10],double n)
{
	long double i,h=0,xn,b,a,s=0;
	cout<<"enter the lower and upper limit and then divison";
	cin>>a>>b>>xn;
	h=(b-a)/xn;
	int j;
	double c=0;
	for(i=a;i<=b;i+=h)
	{
		j++;
		if(i==a||i==b)
		{
			s+=h*sol(obj,n,i,0);
		}
		else if(j%2==0)
		{
			s+=2*h*sol(obj,n,i,0);
		}
		else
		{
			s+=4*h*sol(obj,n,i,0);
		}
	}
	s=s/3;
	cout<<"Answer by the simpson method is = "<<s;
	for(i=0;i<n;i++)
	{
		obj[i].ig();
	}
	i=sol(obj,n,b,0)-sol(obj,n,a,0);
	c=(i-s)/i;
	cout<<"\nexact answer is ="<<i;
	cout<<"\n% error="<<c*100;

}
float determinant(float [][25], float);
void cofactor(float [][25], float);
void transpose(float [][25], float [][25], float);
void in()
{

      float a[25][25], k, d;
      int i, j;
      cout<<"Enter the order of the Matrix :";
      cin>>k;
      cout<<"Enter the elements ofthe Matrix ";
      for (i = 0;i < k; i++)
	{
	 for (j = 0;j < k; j++)
	   {
		    cin>>a[i][j];
	    }
	}
	d = determinant(a, k);
	if (d == 0)
	 cout<<("\nInverse of Entered Matrix is not possible\n");
	else
	 cofactor(a, k);

    }
float determinant(float a[25][25], float k)
{
      float s = 1, det = 0, b[25][25];
      int i, j, m, n, c;
      if (k == 1)
	{
	 return (a[0][0]);
	}
      else
	{
	 det = 0;
	 for (c = 0; c < k; c++)
	   {
	    m = 0;
	    n = 0;
	    for (i = 0;i < k; i++)
	      {
		for (j = 0 ;j < k; j++)
		  {
			   b[i][j] = 0;
			    if (i != 0 && j != c)
			     {
				       b[m][n] = a[i][j];
				       if (n < (k - 2))
					n++;
				     else
					{
					 n = 0;
					 m++;
					 }
			     }

		   }

		 }
	      det = det + s * (a[0][c] * determinant(b, k - 1));
	      s = -1 * s;
	      }
	}
	return (det);
}
void cofactor(float num[25][25], float f)
{
    float b[25][25], fac[25][25];
     int p, q, m, n, i, j;
     for (q = 0;q < f; q++)
     {
       for (p = 0;p < f; p++)
	{
	 m = 0;
	 n = 0;
	 for (i = 0;i < f; i++)
	 {
	   for (j = 0;j < f; j++)
	    {
	      if (i != q && j != p)
	      {
		b[m][n] = num[i][j];
		if (n < (f - 2))
		 n++;
		else
		 {
		   n = 0;
		   m++;
		   }
		}
	    }
	  }
	  fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
	}
      }
      transpose(num, fac, f);
    }
void transpose(float num[25][25], float fac[25][25], float r)
{
      int i, j;
      float b[25][25], inverse[25][25], d;
      for (i = 0;i < r; i++)
	{
	 for (j = 0;j < r; j++)
	   {
	     b[i][j] = fac[j][i];
	    }
	}
      d = determinant(num, r);
      for (i = 0;i < r; i++)
	{
	 for (j = 0;j < r; j++)
	   {
	    inverse[i][j] = b[i][j] / d;
	    }
	}
       cout<<"\n\n\nThe inverse of matrix is : \n";
       for (i = 0;i < r; i++)
	{
	 for (j = 0;j < r; j++)
	   {
	     cout<<inverse[i][j]<<"  ";
	    }
	cout<<"\n";
	 }
	 double x[3][1],y[3][1];
	cout<<"enter the result matrix";
	for(i=0;i<3;i++)
	{
		for(j=0;j<1;j++)
		{
			cin>>x[i][j];
		}
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<1;j++)
		{
			for(int k=0;k<3;k++)
			{
			     y[i][j]+=inverse[i][k]*x[k][j];
			}
		}
	}
	cout<<"the result matrix is";
	for(i=0;i<3;i++)
	{
		for(j=0;j<1;j++)
		{
			cout<<y[i][j]<<" \n " ;
		}
	}
}
void main()
{
	clrscr();
	double n,i;
	constream cout;
	nr obj[10];
	int ch;
	do
	{
	getch();
	clrscr();
	cout<<setclr(500);
	cout<<"1). NEWTON RAPHSON METHOD \n2). MATRIX MULTIPLICATION";
	cout<<"\n3). TRAPEZOIDAL RULE \n4). SIMPSON'S RULE\n5)GAUSS JORDAN\n6).EXIT\n\n";
	delay(2000);
	cout<< "OKAYYYYY LETS GO";
	delay(2000);
	cout<<"\nENTER YOUR CHOICE";
	cin>>ch;
	switch (ch)
	{
		case 1:
				cout<<"enter the no of terms in your equation";
				cin>>n;
				for(i=0;i<n;i++)
				{
					obj[i].input();
				}
				newr(obj,n);
				break;
		case 2: 	mm();
				break;
		case 3:
				cout<<"enter the no of terms in your equation";
				cin>>n;
				for(i=0;i<n;i++)
				{
					obj[i].input();
				}
				trap(obj,n);
				break;
		case 4:
				cout<<"enter the no of terms in your equation";
				cin>>n;
				for( i=0;i<n;i++)
				{
					obj[i].input();
				}
				simp(obj,n);
				break;

		case 5:   	in();
				break;
		case 6: 	exit(-1);
				break;
		default :	cout<<"invalid input";
	}
	}while(ch!=6);
	getch();
}