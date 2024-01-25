#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int search(vector<int> &arr ,int i,int x)
{
    if(i==arr.size())
    return -1;
    if(arr[i]==x) return x;
    else search(arr,i+1,x);
}
// best case search 1st number :- T.c = constant
void input_generator(vector<pair<int,int>> &store)
{
    for(int n=1e2; n<1e4 ; n+=100)
    {
        vector<int> arr(n);
        for(int i=1 ; i<n ;i++)
        arr[i-1] = i ;
        int t=0 ;
        for(int m=1 ; m<=10;m++)
        {
            auto start=high_resolution_clock::now();
            search(arr,0,n+2) ;
            auto stop=high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop-start);
            t+=duration.count();
        }
        t=t/10;
        store.push_back({n,t});

    }
}
int main()
{
    vector<pair<int,int>> store;
    input_generator(store);

    cout << "Number of inputs \tTime taken\n\n";
    for(auto i :store)
    {
        cout << i.first << " \t" << i.second << endl;
    } 
}
