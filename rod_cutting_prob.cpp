#include<bits/stdc++.h>

using namespace std;

/**
 *  Function to find the maximum of two values
 **/
int max(int a,int b)
{
    return (a>b)?a :b ;
}

/**
 *  Function to calculate the optimal solution(price) of the rod of length n with memoization
 **/
int cut_rod(int arr[],int n,int cost[])
{
    if(cost[n]>=0)
    {
        return cost[n];
    }
    int q;
    if(n==0)
        q=0;
    else
    {
        q=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            q=max( q ,arr[i] + cut_rod(arr,n-i,cost) );
        }
    }
    cost[n]=q;
    return cost[n];
}

int initi(int arr[],int n)
{
    int cost[n+1];
    for(int i=0;i<=n;i++)
        cost[i]=INT_MIN;
    return cut_rod(arr,n,cost);
}

int main()
{
    int n;
    cin >> n;
    // Array containing the prices of all lengths of a rod 
    int price[n+1];
    
    for(int i=1;i<=n;i++)
        cin >> price[i];
    
    cout << initi(price,n);
}