/*
  Given a graph G, we've to color it's vertexes such that no two adjacent vertex gets same color. For this we've been provided with a k which denotes the number
  of different colors made available to us.
  We use the concept of backtracking to solve this problem.
*/

#include <bits/stdc++.h>
using namespace std;
class GraphColor
{
  int n, m,colors;
  vector<vector<int>> G;
  vector<int> x;

public:
  GraphColor(int vertices, int edges, int c)
  {
    n = vertices;
    m = edges;
    colors=c;
    G.resize(n + 1);
    x.resize(n + 1);
    for (int i = 0; i <= n; i++)
      G[i].resize(n + 1, 1e9);
    for (int i = 0; i <= n; i++)
    {
      x[i] = 0;
      G[i][i] = 0;
    }
  }
  void createGraph()
  {
    for (int i = 0; i < m; i++)
    {
      int u, v;
      cout << "Enter edge :- " << endl;
      cout << "Enter vertex 1 :- ";
      cin >> u;
      cout << "Enter vertex 2 :- ";
      cin >> v;
      G[u][v] = 1;
      G[v][u] = 1;
    }
  }
  void nextColor(int k)
  {
    do
    {
      x[k] = (x[k] + 1) % (colors + 1);
      if (x[k] == 0)
        return;
      else
      {
        int i;
        for (i = 1; i <= n; i++)
        {
          if (G[k][i] != 0 && G[k][i] != 1e9 && x[k]==x[i])
          {
            break;
          }
        }
        if (i == n + 1)
          return;
      }
    } while (1);
  }
  void mColor(int k)
  {
    do
    {
      nextColor(k);
      if(x[k]==0)
      {
        cout << "Not possible to color the graph\n";
        return ;
      }
      else
      {
        if (k == n)
        {
          cout << "Possible to color the graph with " << k << " colors\n";
          for (int i = 1; i <= n; i++)
          {
            cout << x[i] << "\t";
          }
          cout << endl;
          return;
        }
        else
          mColor(k + 1);
      }
    } while (1);
  }
};
int main()
{
  int n, m,c;
  cout << "Enter number of vertices ";
  cin >> n;
  cout << "\nEnter number of edges ";
  cin >> m;
  cout << "Enter number of colors available " ; 
  cin >>c ;

  GraphColor G(n, m,c);
  G.createGraph();
  G.mColor(1);

  return 0;
}
