//Реализовать timsort без использования дополнительной памяти.
#include <iostream>
#include <cstdlib>

using namespace std;
const int RUN=32;

void insertionSort(int a[], int left, int right)
{
    for (int i=left+1; i<=right; i++)
    {
        int temp=a[i];
        int j=i-1;
        while ((a[j]>temp) && (j>=left))
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

void merge(int a[], int l, int m, int r)
{
    int len1=m-l+1, len2=r-m;
    int left[len1], right[len2];

    for (int i=0; i<len1; i++)
        left[i]=a[l+i];

    for (int i=0; i<len2; i++)
        right[i]=a[m+1+i];

    int i=0;
    int j=0;
    int k=l;

    while ((i<len1) && (j<len2))
    {
        if (left[i]<=right[j])
        {
            a[k]=left[i];
            i++;
        }
        else
        {
            a[k]=right[j];
            j++;
        }
        k++;
    }

    while (i<len1)
    {
        a[k]=left[i];
        k++;
        i++;
    }

    while (j<len2)
    {
        a[k]=right[j];
        k++;
        j++;
    }
}

void Tim(int a[], int n)
{
    for (int i=0; i<n; i+=RUN)
        insertionSort(a,i,min((i+31),(n-1)));

    for (int i=RUN; i<n; i=2*i)
    {
        for (int left=0; left<n; left+=2*i)
        {
            int mid = left+i-1;
            int right = min((left+2*i-1),(n-1));
            merge(a,left,mid,right);
        }
    }
}

int main()
{
    int k;
    cin>>k;
    int a[k];
    for (int i=0; i<k; i++)
      cin>>a[i];
    int n=sizeof(a)/sizeof(a[0]);

    Tim(a,n);
    for (int i=0; i<k; i++)
      cout<<a[i]<<" ";
    system("pause");
}

