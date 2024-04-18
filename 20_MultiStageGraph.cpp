#include <bits/stdc++.h>
using namespace std;
class MultiStageGraph
{
    int n, m, k;
    vector<vector<int>> cost;
    vector<int> d, p, fcost;
public:
    MultiStageGraph(int vertices, int edges, vector<vector<int>> &c)
    {
        n = vertices;
        m = edges;
        k = 1;
        d.resize(n + 1);
        fcost.resize(n + 1);
        this->cost = c;
    }
    void getStages(int s)
    {
        if (s == n)
            return;
        // go to neighbors of s vertex
        for (int i = 1; i <= n; i++)
        {
            // edge exist
            if (cost[s][i] != 1000 && cost[s][i] != 0)
            {
                k++;
                getStages(i);
                break;
            }
        }
    }
    int chooseVertex(int j)
    {
        int mini = 1000;
        int r = -1;
        for (int i = j + 1; i <= n; i++)
        {
            if (cost[j][i] != 0 && cost[j][i] != 1000)
            {
                if (cost[j][i] + fcost[i] < mini)
                {
                    mini = cost[j][i] + fcost[i];
                    r = i;
                }
            }
        }
        return r;
    }
    void fCost()
    {
        p.resize(k + 1);
        fcost[n] = 0; // last vertex cost is zero
        for (int j = n - 1; j >= 1; j--)
        {
            int r = chooseVertex(j);
            if (r == -1)
                continue;
            fcost[j] = cost[j][r] + fcost[r];
            d[j] = r; // storing the next min vertex it came from
        }
        p[1] = 1;
        p[k] = n;
        for (int j = 2; j < n; j++)
        {
            p[j] = d[p[j - 1]];
        }
        cout << "Cost :-  " << fcost[1] << endl;
        cout << "Path taken : - ";
        for (int i = 1; i <= k; i++)
            cout << p[i] << "\t";
    }
};
int main()
{
    int n=4 , m=4 ;
    // cout << "Enter number of vertex " ; cin >> n ;
    // cout << "Enter number of edges " ; cin >> m;
    // vector<vector<int>> cost(n+1 , vector<int>(n+1,1000));
    // for(int i=1 ; i<=n ; i++)
    // {
    //     cost[i][i]=0;
    // }
    // for(int i=0;i<m;i++)
    // {
    //     int u,v,w ;
    //     cout << "Enter edge :- " << endl ;
    //     cout << "Enter vertex 1 :- " ; cin >> u ;
    //     cout << "Enter vertex 2 :- " ; cin >> v ;
    //     cout << "Enter weight of the edge " ; cin >> w ;
    //     cost[u][v]=w;   // directed graph
    // }
    vector<vector<int>> cost{
        {0, 1000, 1000, 1000, 1000},
        {1000, 0, 1, 2, 1000},
        {1000, 1000, 0, 1000, 3},
        {1000, 1000, 1000, 0, 1},
        {1000, 1000, 1000, 1000, 0}};
    MultiStageGraph G(n, m, cost);
    G.getStages(1);
    G.fCost();
    return 0;
}
