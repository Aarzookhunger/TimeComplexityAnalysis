#include<bits/stdc++.h>
using namespace std ;
class PrimsAlgo
{
    private:
    int n, m ,minCost;
    vector<vector<int>> G;
    vector<int> near; 
    public :
    PrimsAlgo(int vertices,int edges)
    {
        n = vertices ;
        m = edges ;
        G.resize(n+1) ;
        for(int i=0 ; i<=n ; i++)
            G[i].resize(n+1,1e9) ;
        for(int i= 0 ; i<=n ; i++)
        G[i][i] = 0;
        
        near.resize(n+1,0);
        minCost=0;
    }
    void createGraph()
    {
        for(int i=0 ; i<m ; i++)
        {
            int u,v,w ;
            cout << "Enter edge :- " << endl ;
            cout << "Enter vertex 1 :- " ; cin >> u ;
            cout << "Enter vertex 2 :- " ; cin >> v ;
            cout << "Enter weight of the edge " ; cin >> w ;
            G[u][v] = w;
            G[v][u] = w ;
        }
    }
    pair<int,int> minWt()
    {
        int u,v,minC = 1e9; 
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1; j<=n ; j++)
            {
                if(G[i][j]!=0 && minC > G[i][j])
                {
                    minC = G[i][j] ;
                    u =i ;
                    v=j;
                }
            }
        }
        return {u,v} ;
    }
    int chooseVertex()
    {
        int u =0, minC = 1e9 ;
        for(int i=1 ; i<=n ; i++)
        {
            int j = near[i] ;
            
            if(j!=0 && G[i][j]!=0 && G[i][j]!=1e9 && minC > G[i][j])
            {
                minC = G[i][j] ;
                u = i ;
            }
        }
        return u ;
    }
    int nearUpdVert (int u)
    {
        int w , minC = 1e9 ;
        for(int i=1 ;i <=n ; i++)
        {
            if(near[i]!=0 && G[i][near[i]]!=1e9 &&G[i][near[i]] >= G[u][i])
            {
                near[i] = u ;
                w=i ;
            }
        }
        return w; 
    }
    void Prims (vector<vector<int>> &MST)
    {
        pair<int,int> temp = minWt();
        int k=temp.first ;
        int l=temp.second ;
        cout << k << "\t" << l << endl ;
        MST[1][1] = k ;
        MST[1][2] = l ;
        for(int i=1 ; i<=n ; i++)
        {
            if(G[i][k]!=1e9 && G[i][l]!=1e9 && G[i][k]!=0 &&  G[i][k]!=0 && G[i][k]<G[i][l])
            near[i]=k;
            else near[i]=l;
        }
        near[k] = near[l] = 0;
        minCost += G[k][l] ;
        
        cout << endl << "NEAR" << endl ;
        for(auto i : near)
        cout << i << "\t" ;
        cout << endl ;
        
        for(int j=2 ; j <= n ; j++)
        {
            if(j==m) break ;
            int u = chooseVertex();
            cout << "Choose " << endl ;
            cout << u << endl ;
            cout << near[u] << endl ;
            
            MST[j][1] = u;
            MST[j][2] = near[u] ;
            if(G[u][near[u]]!=1e9 && G[u][near[u]]!=0 )
            minCost += G[u][near[u]];
            near[u] =0 ;
            for(int k=1; k<=n ; k++)
            {
                int w = nearUpdVert(u);
                near[w] = u ;
            }
        }  
        cout << "MINCOST IS " << minCost << endl ;
    }
};

int main()
{
    int n, m ;
    cout << "Enter number of vertices " ; 
    cin >> n ;
    cout << "\nEnter number of edges " ; 
    cin >> m ;

    PrimsAlgo P(n,m) ;
    P.createGraph() ;
    vector<vector<int>> MST(n+1,vector<int>(3,0)) ;
    P.Prims(MST) ;

    for(int i=1 ; i<n ; i++)
    {
        cout << MST[i][1] << "\t" << MST[i][2] << endl ;
    }
    return 0 ;
}
