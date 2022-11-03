#include<bits/stdc++.h>
using namespace std;


#define vi vector<int>

signed main(){

    priority_queue<int, vector<int> > pq;//as priority queue is built on max heap
    pq.push(3);
    pq.push(1);
    pq.push(2);

    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    priority_queue<int, vector<int>, greater<int> > pqm;//for min heap
    pqm.push(5);
    pqm.push(9);
    pqm.push(8);

    cout<<pqm.top()<<endl;
    pqm.pop();
    cout<<pqm.top()<<endl;
}