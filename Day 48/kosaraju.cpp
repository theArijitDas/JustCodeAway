//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:

    void topo(int u, stack<int> &st, vector<bool> &visited, vector<vector<int>> &adj){
        visited[u] = true;
        for(auto v : adj[u]){
            if (!visited[v]){
                topo(v, st, visited, adj);
            }
        }st.push(u);
    }

    // void explore_scc(int u, vector<int> &new_scc, vector<bool> &visited, vector<vector<int>> &adj){
    //     cout<<endl;
    //     visited[u] = true;
    //     new_scc.push_back(u);
    //     for(auto v : adj[u]){
    //         if (!visited[v]){
    //             explore_scc(v, new_scc, visited, adj);
    //         }
    //     }
    // }

    void explore_scc(int u, vector<bool> &visited, vector<vector<int>> &adj){
        visited[u] = true;
        for(auto v : adj[u]){
            if (!visited[v]){
                explore_scc(v, visited, adj);
            }
        }
    }

	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // Apply Topo sort to find order
        stack<int> st;
        vector<bool> visited(V, false);

        for(int i=0; i<V; i++){
            if (!visited[i]){
                topo(i, st, visited, adj);
            }
        }

        // Reverse all the edges
        vector<vector<int>> rev_adj(V);
        for(int u=0; u<V; u++){
            for(auto v : adj[u]){
                rev_adj[v].push_back(u);
            }
        }

        // apply dfs in the above order to find SSC
        for(int i=0; i<V; i++) visited[i] = false;

        // vector<vector<int>> scc;
        int num_scc = 0;
        while(!st.empty()){
            int u =st.top();  st.pop();
            if (!visited[u]){
                explore_scc(u, visited, rev_adj);
                num_scc++;
            }
        }

        return num_scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}