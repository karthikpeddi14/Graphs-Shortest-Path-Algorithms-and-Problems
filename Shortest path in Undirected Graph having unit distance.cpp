vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {

    vector<vector<int>> adj(n);
    for(int i=0 ; i<edges.size() ; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> ans(n,-1);
    vector<int> visited(n,0);
    queue<pair<int,int>> q;
    q.push({src,0});
    visited[src] = 1;

    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        ans[a] = b;
        q.pop();
        for(auto it:adj[a])
        {
            if(visited[it]==0) q.push({it,b+1});
            visited[it] = 1;
        }
    }
    return ans;
}
