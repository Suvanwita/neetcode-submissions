class DisjointSet{
public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        size.assign(n,1);
    }

    int findPar(int node){
        if(parent[node]==node)
            return node;
        return parent[node]=findPar(parent[node]);
    }

    void unionBySize(int u,int v){
        int pu=findPar(u);
        int pv=findPar(v);
        if(pu==pv)
            return;
        if(size[pu]>size[pv]){
            size[pu]+=size[pv];
            parent[pv]=pu;
        }else{
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);

        for(auto e:edges){
            if(ds.findPar(e[0])!=ds.findPar(e[1]))
                ds.unionBySize(e[0],e[1]);
            else
                return false;
        }

        int comp=0;
        for(int i=0;i<n;i++){
            if(ds.findPar(i)==i)
                comp++;
        }
        if(comp==1)
            return true;
        return false;
    }
};
