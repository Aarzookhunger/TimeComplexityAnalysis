#include<bits/stdc++.h>
using namespace std;
using namespace std :: chrono;
void PG(vector<bool> &arr , int i)
{
    if(i==arr.size())
    {
        // for(auto j: arr)
        // cout << j << "  ";
        // cout << endl;
        return;
    }
    arr[i]=true; 
    PG(arr,i+1);

    arr[i]=false;
    PG(arr,i+1);
}
void input_generator(vector<pair<int,int>> &store)
{
    for(int n=1 ;n<=20 ;n+=2)
    {
        vector<bool> arr(n,true);
        int t=0 ;
        for(int m=1 ;m<=10 ;m++)
        {
            auto start = high_resolution_clock::now();
            PG(arr,0);
            auto stop = high_resolution_clock::now();
            auto duration=duration_cast<milliseconds>(stop-start);
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