class DSU{
    vector<int> parent;
    vector<int> size;
    public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int a){
        if(parent[a] == a){
            return a;
        }
        return parent[a] = find(parent[a]);
    }
    void uni(int a,int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(size[a] < size[b]){
                swap(a,b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
class Solution {
public:
    int MST(int n,vector<vector<int>> &edges,int block,int e){
        int weight = 0;
        int m = edges.size();
        DSU temp(n);
        if(e != -1){
            temp.uni(edges[e][0],edges[e][1]);
            weight += edges[e][2];
        }
        for(int i=0;i<m;i++){
            if(i == block)continue;
            if(temp.find(edges[i][0]) == temp.find(edges[i][1]))continue;
            temp.uni(edges[i][0],edges[i][1]);
            weight += edges[i][2];
        }
        for(int i=0;i<n;i++){
            if(temp.find(i) != temp.find(0)){
                return INT_MAX;
            }
        }
        return weight;
    }
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[2]<b[2];
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for(int i=0;i<m;i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),cmp);
        int mst = MST(n,edges,-1,-1);
        // cout<<mst<<"\n";
        vector<int> cr,pcr;
        for(int i=0;i<m;i++){
            // taking 
            if(mst < MST(n,edges,i,-1)){
                cr.push_back(edges[i][3]);
            }
            // not taking
            else if(mst == MST(n,edges,-1,i)){
                pcr.push_back(edges[i][3]);
            }
        }
        return {cr,pcr};
    }
};