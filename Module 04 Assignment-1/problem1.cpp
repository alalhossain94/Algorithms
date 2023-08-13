#include<bits/stdc++.h>
using namespace std;
const int n=1e5+7;
int A[n];
void merge(int l, int r, int mid)
{
    int left_size=mid-l+1;
    int L[left_size+1];

    int right_size=r-(mid+1)+1;
    int R[right_size+1];
    for(int i=l, j=0; i<=mid; i++, j++)
    {
        L[j]=A[i];
    }
    for(int i=mid+1, j=0; i<=r; i++, j++)
    {
        R[j]=A[i];
    }
    L[left_size]= INT_MIN;
    R[right_size]=INT_MIN;

    int left_ptr=0; 
    int right_ptr=0;
    for(int i=l; i<=r; i++)
    {
         if(L[left_ptr] >= R[right_ptr])
         {
            A[i]=L[left_ptr];
            left_ptr++;
         }
         else
         {
            A[i]=R[right_ptr];
            right_ptr++;
         }
    }
}
void mergesort(int l, int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    mergesort(l, mid);
    mergesort(mid+1, r);
    merge(l, r, mid);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    mergesort(0, n-1);
    for(int i=0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}