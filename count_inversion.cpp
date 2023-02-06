void merge(long long a[],long long int s,long long int e,long long int &cnt){
        // Finding mid of the array
        long long int mid = s+(e-s)/2;
        // finding lenth of first half of the array
        long long int len1 = mid-s+1;
        // finding lenth of second half of the array
        long long int len2 = e - mid;
        // creating first array of size len1
        long long *first = new long long[len1];
        // creating second array of size len2
        long long *second = new long long[len2];
        // storing starting index of array
        long long int start = s;
        // copying value from array to first array
        for(long long int i = 0;i<len1;i++)
        first[i] = a[start++];
        // copying value from array to second array
        start = mid + 1;
        for(long long int i=0;i<len2;i++)
        second[i] = a[start++];
        // Now we have two sorted array first and second 
        // applying concept of --> merge two sorted array
        long long int i = 0,j = 0,mainindex = s;
        while(i<len1 && j<len2){
            if(first[i]<=second[j])
            a[mainindex++] = first[i++];
            else{
            // we add here that how many element shift due to insertion of
            // element of array second
            cnt+=len1-i;
            a[mainindex++] = second[j++]; 
            }
        }
        while(i<len1)
            a[mainindex++] = first[i++];
        while(j<len2)
            a[mainindex++] = second[j++]; 
    }
    void solve(long long a[],long long int s,long long int e,long long int &cnt){
        //Base Case
        if(s>=e) return;
        // Finding mid
        long long int mid  = s+(e-s)/2;
        // Recursive Call for left part
        solve(a,s,mid,cnt);
        // Recursive Call for right part
        solve(a,mid+1,e,cnt);
        // mergeing both part of array
        merge(a,s,e,cnt);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Approach 1 --> Brute Force [O(n^2) , O(n)] -> TLE
        // int cnt = 0;
        // for(int  i = 0;i<N;i++)
        //     for(int j = i+1;j<N;j++)
        //       if(arr[j]<arr[i]) cnt++;
        // return cnt;
        
        //  Approach 2 --> Using merge sort -> O(nlogn),O(n)
        long long int cnt = 0;
        // calling solve function
        solve(arr,0,N-1,cnt);
        // returning ans
        return cnt;
    }
    #include <bits/stdc++.h>
using namespace std;
int main()
{
    long long arr[5] = {2, 4, 1, 3, 5};
    cout<<inversionCount(arr,5)<<endl;;
    return 0;
}
