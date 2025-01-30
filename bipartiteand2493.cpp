class Solution {
public:
    bool ispartite(unordered_map<int, vector<int>>& adj, int curr,
                   vector<int>& colors, int currColor) {

        colors[curr] = currColor;
        for (int& ngbr : adj[curr]) {
            if (colors[ngbr] == colors[curr]) {
                return false;
            }
            //if 1 then send 0,if 0 then 1
            //that why,passed 1-currcolor
            if (colors[ngbr] == -1) {
                if (ispartite(adj, ngbr, colors, 1 - currColor) ==
                    false) {
                    return false;
                }
            }
        }
        return true;
    }

    int bfs(unordered_map<int,vector<int>>&adj,int currnode,int n){
         vector<bool> visited(n, false);
         //push the currnode in queue and mark it as true;
        queue<int>que;
        que.push(currnode);
         visited[currnode]=true;
         //first node means first level


        int level=1;
        while(!que.empty()){
            int N=que.size();
            while(N--){
                int curr=que.front();
                que.pop();
                //check for the neighbor of currnode
                for(int &ngbr:adj[curr]){
                    if(visited[ngbr]){
                        continue;
                    }
                    que.push(ngbr);
                    visited[ngbr]=true;
                }
            }
            level++;

        }
        return level-1;
       
    }
    int getmaxfromeach(unordered_map<int,vector<int>>&adj,int curr,vector<bool>&visited,vector<int>&levels){
        int maxgroup=levels[curr];
        visited[curr]=true;
        for(int &ngbr:adj[curr]){
            if(!visited[ngbr]){
                maxgroup=max(maxgroup,getmaxfromeach(adj,ngbr,visited,levels));

            }
        }
        return maxgroup;

    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        //make a undirected graph
        for (auto& edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //use bipartite
        vector<int> colors(n, -1);
        for (int node = 0; node < n; node++) {
            if (colors[node] == -1) {
                if (ispartite(adj, node, colors, 1) == false) {
                    return -1;
                }
            }
        }
        //check levels
        //to get the levels,apply bfs from every node
       
        vector<int> levels(n, 0);
        for (int node = 0; node < n; node++) {
            levels[node] = bfs(adj, node, n);
        }
        //find the maxgroup for each component
        int maxgroupcount=0;
        vector<bool>visited(n,false);
        for(int node=0;node<n;node++){
            if(!visited[node]){
                maxgroupcount+=getmaxfromeach(adj,node,visited,levels);
            }

        }
        return maxgroupcount;
        
    }
};