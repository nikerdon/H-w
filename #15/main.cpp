//Даны К упорядоченных массивов длины N содержащих целые числа. написать программу. Проверить есть ли число входящее в каждый из массивов.
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
const int x=6,y=6;

bool Se(int a[y][x], int n, int y1)
{
   for (int i=0; i<x; i++)
   {
       if ((a[i][y1]==n) && (y1+1<y))
         {
             y1++;
             Se(a,n,y1);
             break;
         }
       if ((a[i][y1]==n) && (y1=y))
         {
             cout<<"["<<n<<"]";
             break;
         }
       if ((a[i][y1]>n))
         {
            break;
         }
   }
}

int main()
{
   int a[y][x];
   for (int i=0; i<y; i++)
       for (int j=0; j<x; j++)
           cin >> a[j][i];

   for (int i=0; i<x; i++)
   {
       Se(a,a[i][0],1);
   }
    system("pause");
}
