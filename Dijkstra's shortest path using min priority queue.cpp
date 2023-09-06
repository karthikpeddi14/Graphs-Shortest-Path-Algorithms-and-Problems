vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    vector<vector<pair<int,int>>> adj(vertices);
    for(int i=0; i<edge.size() ; i++ )
    {
        adj[edge[i][0]].push_back({edge[i][1],edge[i][2]});
        adj[edge[i][1]].push_back({edge[i][0],edge[i][2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> ans(vertices,1e9);
    pq.push({0,source});
    
    while(!pq.empty())
    {
        int wt = pq.top().first;
        int index = pq.top().second;
        pq.pop();
        ans[index] = min(ans[index],wt);
        for(auto it:adj[index])
        {
            if(wt+it.second<ans[it.first]) pq.push({wt+it.second,it.first});
        }
    }
    return ans;
}
