#include <iostream>
#include <conio.h>
using namespace std;

int akk(int m,int n)
{
    if (m==0) return n+1;
    else {
        if (n==0) return akk(m-1,1);
        else return akk(m-1,akk(m,n-1));
    }
}

int main()
{
    int m,n;
    cin>>m>>n;
    cout<<akk(n,m)<<endl;
    _getch();
}
