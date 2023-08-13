#include<bits/stdc++.h>
using namespace std;
void mergesort(int A[], int B[], int n, int m, int result[])
{
    int i=0, j=0, k=0;
    while(i<n && j<m)
    {
        if(A[i]> B[j])
        {
            result[k++]=A[i++];
        }
        else 
        {
            result[k++]=B[j++];
        }
    }
    while(i<n)
    {
        result[k++]=A[i++];
    }
    while(j<m)
    {
        result[k++]=B[j++];
    }
}
int main()
{
    int n,m;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    cin>>m;
    int B[m];
    for(int i=0; i<m; i++)
    {
        cin>>B[i];
    }
    int result[n+m];
    mergesort(A,B,n,m,result);
    for(int i=0; i<n+m; i++)
    {
        cout<< result[i]<<" ";
    }
    return 0;
}