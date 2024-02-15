// Sorting Profits/Weights in non-increasing order comes out to be the most optimal one in Knapsack
#include<bits/stdc++.h>
using namespace std; 
using namespace std :: chrono; 
int partition(vector<pair<int,int>> &arr , int low , int high)
{
    int i=low ;
    int j=high ;
    int pivot = arr[low].first ;
    while(i<j)
    {
        while(arr[i].first <= pivot && i<=high-1)
        i++;
        while(arr[j].first > pivot && j>=low+1)
        j--;
        if(i<j) swap(arr[i],arr[j]); 
    }
    swap(arr[low],arr[j]);
    return j;
}
void QuickSort(vector<pair<int,int>> &arr, int low , int high)
{
    if(low<high)
    {
        int j= partition(arr,low,high) ;
        QuickSort(arr,low,j-1);
        QuickSort(arr,j+1,high) ;
    }
}
int partitionPW(vector<pair<float,pair<float,float>>>&arr , int low , int high)
{
    int i=low ;
    int j=high ;
    int pivot = arr[low].first ;
    while(i<j)
    {
        while(arr[i].first <= pivot && i<=high-1)
        i++;
        while(arr[j].first > pivot && j>=low+1)
        j--;
        if(i<j) swap(arr[i],arr[j]); 
    }
    swap(arr[low],arr[j]);
    return j;
}
void QuickSortPW(vector<pair<float,pair<float,float>>>&arr , int low , int high)
{
    if(low<high)
    {
        int j= partitionPW(arr,low,high) ;
        QuickSortPW(arr,low,j-1);
        QuickSortPW(arr,j+1,high) ;
    }
}
void KnapSack(vector<int>&profit , vector<int>& weight , float maxW)
{
    int n=profit.size();
    vector<pair<int,int>> arr(n) ;
    vector<int> X(n);
    // case I -> sort according to non-decreasing weights
    for(int i=0 ; i<n ; i++)
    {
        arr[i] = {weight[i],profit[i]};
    }

    QuickSort(arr,0,n-1);
    float prft =0 ;
    float currWt =0 ;
    int it =0 ;
    float W = maxW;
    while(it<n)
    {
        if(arr[it].first <= W  )
        {
            prft +=arr[it].second ;
            X[it]=1 ;
            W = W-arr[it].first;
        }
        else break;
        it++;
    }
    if(it<n)
    {
        prft += (W / arr[it].first) * (arr[it].second) ;
    }
    cout << "Sorting Weights in non-decreasing order  :- " << prft << endl ;


    // case II -> sort Profits
    for(int i=0 ; i<n ; i++)
    {
        arr[i] = {profit[i],weight[i]};
    }
    QuickSort(arr,0,n-1);
    reverse(arr.begin(),arr.end());

    prft =0 , currWt=0 , it =0;
    W=maxW;
    while(it<n)
    {
        if(arr[it].first <= W  )
        {
            prft +=arr[it].first ;
            X[it]=1 ;
            W = W-arr[it].second;
        }
        else break;
        it++;
    }
    if(it<n)
    {
        prft += (W / arr[it].second) * (arr[it].first) ;
    }
    cout << "Sorting profits in non-increasing order  :- " << prft << endl ;

// CASE - III Sorting in non-increasing order of profits/weights
    vector<pair<float,pair<float,float>>> A(n) ;
    for(int i=0 ; i<n ; i++)
    {
        A[i] ={profit[i]/weight[i],{profit[i],weight[i]}};
    }
    QuickSortPW (A,0,n-1);
    reverse(A.begin(),A.end());
    prft =0 , currWt=0 , it =0;
    W=maxW;
    while(it<n)
    {
        if(A[it].second.second <= W  )
        {
            prft +=A[it].second.first ;
            W = W-A[it].second.second;
        }
        else break;
        it++;
    }
    if(it<n)
    {
        prft += (W / A[it].second.second) * (A[it].second.first) ;
    }
    cout << "Sorting profits/weights in non-increasing order  :- " << prft << endl ;
}
int main()
{
    vector<int> profit ={5,15,10,20} ;
    vector<int> weight = {3,2,1,4} ;
    
    KnapSack(profit,weight,5);
    return 0 ;
}