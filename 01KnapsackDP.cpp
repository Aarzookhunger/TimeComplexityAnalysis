/*
	In 0/1 Knapsack problem, we're given a maximum weight that a bag can hold and according to that we've to choose the items from given list such that profit obtained 
 	is maximised.
*/

#include<bits/stdc++.h>
using namespace std ; 
int main()
{
  vector<int> profit ={5,15,10,20} ;
  vector<int> weight = {3,2,1,4} ;
  int n=profit.size() ;
  int maxW = 5 ;

  vector<int> curr (maxW+1,0) , prev(maxW+1,0);  
  for(int i=1 ; i<n ; i++)
	{
		for(int wt = 0 ; wt<=maxW; wt++)
		{
			int NotTake = 0 + prev[wt];
			int Take = INT_MIN;
			if(weight[i]<=wt)
			Take = profit[i] + prev[wt-weight[i]];
			curr[wt] = max(Take,NotTake);
		}
		prev=curr;
	}
	cout << "Maximum obtainable profit is :- " <<  prev[maxW] << endl ;
    return 0 ;
}
