#include <iostream>
#include <vector>
using namespace std;

class DisjointSet{
    public:
        vector<int>size,rank,parent;
        DisjointSet(int n){
            parent = vector<int>(n+1);
            size = vector<int>(n,1);
            rank = vector<int>(n,0);
            for (int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        int findParent(int u){
            if (u==parent[u]){
                return u;
            }
            return parent[u] = findParent(parent[u]);
        }
        void unionBySize(int u,int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if (size[ulp_u] <= size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
        
};