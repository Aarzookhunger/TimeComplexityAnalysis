#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void TOH(int n,int A,int B,int C)
{
    if(n>=1)
    {
        TOH(n-1,A,C,B);
        // from A to C using B (1 disc transfer)
        TOH(n-1,B,A,C);
    }
}
void input_generator(vector<pair<int,int>> &store)
{
    for(int n= 10 ; n<=50; n+=5)
    {
        clock_t time_req;
        int t=0;
        for(int m=1 ; m<=10;m++)
        {
            auto start = high_resolution_clock::now();
            TOH(n,1,2,3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);

            t+=duration.count() ;
        }
        t= t/10;
        cout << n << "\t" << t << endl;
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
    return 0;
}