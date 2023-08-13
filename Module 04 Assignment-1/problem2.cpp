#include<bits/stdc++.h>
using namespace std;

int findIndex(vector<int>&A, int k)
{
    int left_index=0;
    int right_index=A.size()-1;

    while(left_index <= right_index)
    {
        int mid=left_index+(right_index-left_index)/2;
        if(A[mid]==k)
        {
            return mid;
        }
        else if(A[mid]<k)
        {
            left_index=mid+1;
        }
        else
        {
            right_index=mid-1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    int k;
    cin>>k;
    int target_index=findIndex(A, k);
    if(target_index != -1)
    {
        cout<<target_index<<endl;
    }
    else
    {
        cout<<" Not Found "<<endl;
    }
    return 0;
}