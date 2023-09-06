// my code
void f(vector<vector<pair<int,int>>>& adj, int index, vector<int>&ans,vector<int>& visited, int dist)
{
    ans[index] = min(dist,ans[index]);
    for(auto it:adj[index])
    {
        int AdjacentIndex = it.first;
        int wtToReachAdj = it.second;
      if (visited[AdjacentIndex] == 0) {
        visited[AdjacentIndex] = 1;
        f(adj, AdjacentIndex, ans, visited, dist + wtToReachAdj);
        visited[AdjacentIndex] = 0;
      }
    }
}

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    vector<vector<pair<int,int>>> adj(vertices);
    for(int i=0; i<edge.size() ; i++ )
    {
        adj[edge[i][0]].push_back({edge[i][1],edge[i][2]});
        adj[edge[i][1]].push_back({edge[i][0],edge[i][2]});
    }

    int v=vertices;
    vector<int> ans(v,1e9);
    vector<int> visited(v,0);
    f(adj,source,ans,visited,0);

    for(int i=0 ; i<vertices ; i++)
    {
        if(ans[i]==1e9) ans[i]=-1;
    }

    return ans;

}
