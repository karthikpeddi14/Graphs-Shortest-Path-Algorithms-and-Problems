void toposort(int node, vector<int>&visited , stack<int>&st, vector<vector<pair<int,int>>>& adj)
{
    visited[node] = 1;
    for(auto it:adj[node])
    {
        if(visited[it.first]==0) toposort(it.first, visited, st, adj);
    }
    st.push(node);
}
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0 ; i<edges.size() ; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }

    stack<int> st;
    vector<int> visited(n,0);
    for(int i=0 ; i<n ; i++)
    {
        if(visited[i]==0) toposort(i,visited,st,adj);
    }

    vector<int> dist(n,1e9);
    dist[0] = 0;
    while(!st.empty())
    {
        int a = st.top();
        st.pop();
        for(auto it:adj[a])
        {
            dist[it.first] = min(dist[a]+ it.second, dist[it.first]);
        }
    }

    for(int i=0 ; i< n ;i++) 
    {
        if(dist[i]==1e9) dist[i] = -1;
    }
    return dist;
}
