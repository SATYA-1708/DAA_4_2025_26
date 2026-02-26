class Solution {
public:
    vector<int> parent, rank;
    
    int findParent(int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionSet(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        
        if(pu == pv) return;
        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });
        
        parent.resize(V);
        rank.resize(V, 0);
        
        for(int i = 0; i < V; i++)
            parent[i] = i;
        
        int mstWeight = 0;
        int edgesUsed = 0;

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if(findParent(u) != findParent(v)) {
                unionSet(u, v);
                mstWeight += w;
                edgesUsed++;
                
                if(edgesUsed == V - 1)
                    break;
            }
        }
        
        return mstWeight;
    }
};