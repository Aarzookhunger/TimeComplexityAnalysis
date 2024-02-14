#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono; 
void merge(vector<int>&arr,int start,int mid,int high)
{
    int sizeOne = mid-start+1; 
    int sizeTwo = high-mid ;
    vector<int> arr1(sizeOne);
    vector<int> arr2(sizeTwo);

    for(int i=0 ; i<sizeOne;i++)
    arr1[i] = arr[start+i] ;

    for(int i=0 ; i<sizeTwo ; i++)
    arr2[i] = mid+i;

    int i=0 ,j=0;
    // start merging from the starting index
    int curr= start ;
    while(i<sizeOne && j<sizeTwo)
    {
        if(arr1[i] < arr2[j])
        arr[curr] = arr1[i++];
        else arr[curr] = arr2[j++];
        curr++;
    }
    while(i<sizeOne)
    {
        arr[curr++] = arr1[i++];
    }
    while(j<sizeTwo)
    {
        arr[curr++] = arr2[j++];
    }
}

void MergeSort(vector<int> &arr,int start,int end)
{
    if(start<end)
    {
        int mid = (start+end)/2;
        MergeSort(arr,start,mid);
        MergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}

void input_generator(vector<pair<int,int>> &store)
{
    for(int n=10 ; n<=1e3 ; n+=500)
    {
        vector<int> arr(n);
        generate(arr.begin(),arr.end(),rand);

        int t=0 ;
        for(int m=1 ; m<=10 ; m++)
        {
            auto start = high_resolution_clock::now();
            MergeSort(arr,0,n-1); 
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);

            t+=duration.count() ;
        }
        t/=10 ;
        store.push_back({n,t});
    }
}
int main()
{
    vector<pair<int,int>> store;

    cout << "Number of inputs \t Time Taken\n\n";
    input_generator(store); 
    for(auto i : store)
    {
        cout << i.first << " \t " << i.second << endl ;
    }
    
    return 0;
}