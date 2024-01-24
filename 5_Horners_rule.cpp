#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int Horners(vector<int> arr , int i , int x)
{
    if(i==arr.size())
    return 0;
    return arr[i] + x*Horners(arr,i+1,x);
}
void input_generator(vector<pair<int,int>> &store)
{
    for(int i=10 ; i<=1e4 ; i+=500)
    {
        vector<int> arr(i);
        generate(arr.begin(),arr.end(),rand);

        int t=0;
        for(int m=1; m<=10 ;m++)
        {
            auto start = high_resolution_clock::now();
            Horners(arr,0,4);  // let x=4 
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);

            t+=duration.count() ;
        }
        t= t/10;
        cout << i << "\t" << t << endl;
        store.push_back({i,t});
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
    return 0;
}