#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void PG(vector<int> &arr ,int i)
{
    if(i==arr.size())
    {
        // for(auto j:arr)
            // print the numbers
            return;
    }
    for(int idx=i; idx<arr.size();idx++)
    {
        swap(arr[idx],arr[i]);
        PG(arr,i+1);
        swap(arr[idx],arr[i]);
    }
}
void input_generator(vector<pair<int,int>> &store)
{
    for(int n=1; n<=20; n+=1)
    {
        vector<int> arr(n);
        for(int i=1 ; i<=n ;i++)
        {
            arr[i-1] = i ;
        }
        int t=0 ;
        for(int m=1 ;m<=10 ;m++)
        {
            auto start=high_resolution_clock::now();
            PG(arr,0);
            auto stop=high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop-start) ;
            t+= duration.count();
        }
        t=t/10;
        cout << n << "\t " << t << endl;
        store.push_back({n,t}) ;
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