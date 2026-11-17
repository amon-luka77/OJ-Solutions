#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    const int N = 1e5;

    int n, m, k; cin >> n >> m >> k;

    static pair<int, int> edge[N + 1], query[N + 1];

    #define ft first
    #define sc second

    static map<pair<int, int>, int> edgeId;
    
    for(int i = 1, x, y; i <= n && cin >> x >> y; i ++) {
        if(x > y) swap(x, y);
        edgeId[{x, y}] = i;
    }

    static struct DSU {
        int parent[N + 1], sz[N + 1];
        
        struct 

        int find_set(int k) {return k == parent[k] ? k : find_set(parent[k]);}

        void 
    }

    static struct Segtree {
        vector<pair<int, int>> node;
        

        void updated(int l, )
    }

    while(q --) {

    }
}