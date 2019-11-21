//Realizovat' algoritm Nidlmana-Vunsha
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
   string s1,s2;
   int n1,n2,k=0;
   cin>>s1;
   cin>>s2;
   n1=s1.length();
   n2=s2.length();
   int a[n1+1][n2+1];
   for (int i=0; i<=n2; i++)
     for (int j=0; j<=n1; j++)
       {
           a[i][j]=0;
       }
  cout<<"Common elements are: ";
   for (int i=1; i<=n2; i++)
        {

            for (int j=1; j<=n1; j++)
                {
                    if (s1[j-1]==s2[i-1])
                    {
                        a[i][j]=a[i-1][j-1]+1;
                        if (a[i][j]>k)
                        {
                            k++;
                            cout<<s1[j-1]<<" ";
                        }
                    }
                    else
                    {
                        a[i][j]=max(a[i-1][j],a[i][j-1]);
                    }
                }
        }
   cout<<endl;
   system("pause");
}
