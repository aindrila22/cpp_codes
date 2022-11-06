#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define rep(i,a,b) for(int i=a; i<b; i++)

signed main(){
    int n;
    cin>>n;

    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }

    map<int, int> freq;//can also write--     unordered_map<int, int> freq; 
    rep(i,0,n){
        freq[a[i]]++;
    }

    map<int, int> :: iterator it;//can also write--     unordered_map<int, int> :: iterator it; 
    for(it=freq.begin(); it!=freq.end(); it++){
        cout<<it->first<<" -> "<<it->second<<endl;
    }
}

/***time complexity
 * insertion, access and deletion time of map = O(logn), implemented using red black trees
 * insertion, access and deletion time of unordered_map = O(1) , O(1) , O(n), implemented using hashtables [array of buckets]
*/
