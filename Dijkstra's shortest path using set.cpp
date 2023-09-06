vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    vector<vector<pair<int,int>>> adj(vertices);
    for(int i=0; i<edge.size() ; i++ )
    {
        adj[edge[i][0]].push_back({edge[i][1],edge[i][2]});
        adj[edge[i][1]].push_back({edge[i][0],edge[i][2]});
    }
    set<pair<int,int>> st;
    st.insert({0,source});
    vector<int> ans(vertices,1e9);
    ans[source] = 0;

    while(!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dist = it.first;
        st.erase(it);

        for(auto it:adj[node])
        {
            int nextNode = it.first;
            int  wt = it.second;
            if(wt+dist<ans[nextNode])
            {
                if(ans[nextNode]!=1e9) st.erase({ans[nextNode],nextNode});
                st.insert({wt+dist,nextNode});
                ans[nextNode] = wt+dist;
            }
        }
    }

    for(int i=0 ; i<vertices ; i++) if(ans[i]==1e9) ans[i] = -1;

    return ans;
}
