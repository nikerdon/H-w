/*Написать функции проверяющие является ли число:
Числом Мерсена
Числом Ферма
Числом Вильсона
Числом Вагстафа
Числом Вивериха
Числом Софи Жермен
Числом Хиггса*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

bool Prime(int n)
{
    bool m[n];
    for(int i=1;i<=n;i++)
    {
        m[i]=true;
    }

    for(int i=2; i*i<=n;i++)
    {
        if (m[i]==true)
            for(int j=i*i; j<=n; j+=i)
                {
                    m[j]=false;
                }
    }
    return m[n];
}

int fact(int a)
{
  int s=1;
  for (int i=1; i<=a; i++)
      s=s*i;
    return s;
}

int Mers(int n)
{
  int i=0;
  while (pow(2,i)<=n)
     {
       i++;
     }
  if (pow(2,i)-1==n) cout<<"Is Mersenne prime"<<endl;
  if (pow(2,i)-1!=n) cout<<"Not Mersenne prime"<<endl;
}

int Ferma(int n)
{
  int i=0;
  while (pow(2,pow(2,i))<=n)
     {
       i++;
     }
  if (pow(2,pow(2,i-1))+1==n) cout<<"Is Fermat prime"<<endl;
  if (pow(2,pow(2,i-1))+1!=n) cout<<"Not Fermat prime"<<endl;
}

int Wil(int n)
{
  float i=0;
  i=(fact(n-1)+1)/pow(n,2);
  if (i-(int)i==0) cout<<"Is Wilson prime"<<endl;
  if (i-(int)i!=0) cout<<"Not Wilson prime"<<endl;
}

int Wag(int n)
{
  float i,j=0;
  i=3*n-1;
  while (pow(2,j)<=i)
     {
       j++;
     }
  if (Prime(j-1)==true && i==pow(2,j-1)) cout<<"Is Wagstaff prime"<<endl;
  else cout<<"Not Wagstaff prime"<<endl;
}

int Wie(int n)
{
  float i=0;
  i=(pow(2,n-1)-1)/(n^2);
  if (i-(int)i==0) cout<<"Is Wieferich prime"<<endl;
  if (i-(int)i!=0) cout<<"Not Wieferich prime"<<endl;
}

int SG(int n)
{
  bool b=false;
  b=Prime(2*n+1);
  if (b==true) cout<<"Is Sophie Germain prime"<<endl;
  if (b==false) cout<<"Not Sophie Germain prime"<<endl;
}

int Hig(int n)
{
  bool m[n];
  for(int i=1;i<=n;i++)
    {
        m[i]=false;
    }
  m[2]=true;
  int pr=2;
  for (int i=2;i<=n;i++)
  {
      if ((Prime(i)==true) && (pr^2%(i-1)==0))
      {
          m[i]=true;
          pr=pr*i;
      }
  }
  if (m[n]==true) cout<<"Is Higgs prime"<<endl;
  if (m[n]==false) cout<<"Not Higgs prime"<<endl;
}

int main()
{
  int n;
  cin>>n;

  if (Prime(n)==true)
  {
     Mers(n);
     Ferma(n);
     Wil(n);
     Wag(n);
     Wie(n);
     SG(n);
     Hig(n);
  }
  if (Prime(n)==false) cout<<"Not a prime number"<<endl;
  system("pause");
}
