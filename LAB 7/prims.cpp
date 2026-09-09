#include<bits/stdc++.h>
using namespace std;

typedef pair <int,int> iip;
int prim(vector<vector<iip>> &graph,int n){
  priority_queue < iip,vector <iip> ,greater<iip> > pq;
  vector <bool> inMST(n,false);

}

int main()
{
    int n=4;


    priority_queue < int,vector <int> ,greater<int> > pq;
    pq.push(20);
      pq.push(2);
        pq.push(10);
        cout << pq.top() << endl;
        pq.pop();
        cout << pq.top() << endl;


} 