    #include<bits/stdc++.h>
    using namespace std;
    int firstOccurrences(vector<int> &A, int k)
    {
        int left_size=0;
        int right_size=A.size()-1;
        int result1= -1;
        while(left_size <= right_size)
        {
            int mid=left_size+(right_size-left_size)/2;
            if(A[mid]==k)
            {
                result1=mid;
                right_size=mid-1;
            }
            else if(A[mid] < k)
            {
                left_size=mid+1;
            }
            else
            {
                right_size=mid-1;
            }
        }
        return result1;
    }   
    int lastOccurrences(vector<int> &A, int k)
    {
        int left_size=0;
        int right_size=A.size()-1;
        int result2= -1;
        while(left_size <= right_size)
        {
            int mid=left_size+(right_size-left_size)/2;
            if(A[mid]==k)
            {
                result2=mid;
                left_size=mid+1;
            }
            else if(A[mid] < k)
            {
                left_size=mid+1;
            }
            else
            {
                right_size=mid-1;
            }
        }
        return result2;
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
        int result1= firstOccurrences(A,k);
        int result2= lastOccurrences(A,k);
        if(result1 != result2)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        return 0;
    }