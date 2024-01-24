#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int get_sum(vector<int> &arr , int i)
{
    if(i==arr.size())
    return 0; 
    return arr[i] + get_sum(arr,i+1);
}
void input_generator(vector<pair<int,int>> &store)
{
    for(int i=1000 ; i<=1e4; i+=300)
    {
        vector<int> arr(i);
        for(int j=1 ; j<=i ;j++)
        arr[j-1] = j;
    
        int t=0;
        for(int m=1 ; m<=10 ; m++)
        {
            auto start = high_resolution_clock::now();
            get_sum(arr,0);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);

            t+=duration.count() ;
        }
        t= t/10;
        store.push_back({t,i});

    }
}
int main()
{
    vector<pair<int,int>> store;
    input_generator(store);

    cout << "Time " << "\t" << "Number of inputs " << endl << endl;
    for(auto i : store)
    {
        cout << i.first << "\t" << i.second << endl;
    }
    return 0;
}