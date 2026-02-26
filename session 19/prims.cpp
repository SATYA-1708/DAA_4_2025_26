
class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
    
        vector<vector<pair<int,int>>> adj(V);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({w,v});
            adj[v].push_back({w,u});
        }

        vector<bool> visited(V,false);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,0});
        
        int minCost = 0;
        
        while(!pq.empty()) {
        
            int wi = pq.top().first;
            int ui = pq.top().second;
            pq.pop();

            if(visited[ui]){
                continue;
            }

            visited[ui] = true;
            minCost += wi;

            for(auto pr : adj[ui]) {
                int vi = pr.second;
                int currW = pr.first;

                if(!visited[vi]) {
                    pq.push({currW,vi});
                }
            }    
        }
        return minCost;
    }
};