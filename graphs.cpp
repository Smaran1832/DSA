#include <bits/stdc++.h>
using namespace std;


//theory
/*

An undirected graph is a graph where edges are bidirectional, with no direction associated with them, i.e, there will be an undirected edge. In an undirected graph, the pair of vertices representing any edge is unordered. Thus, the pairs (u, v) and (v, u) represent the same edge.
A directed graph is a graph where all the edges are directed from one vertex to another, i.e, there will be a directed edge. It contains an ordered pair of vertices. It implies each edge is represented by a directed pair <u, v>. Therefore, <u, v> and <v, u> represent two different edges.

1 2 3 5 is a path.
1 2 3 2 1 is not a path, because a node can’t appear twice in a path.

Total Degree of a graph = 2 x E
Example, (2+2+3+2+3) = 2 x 6 => 12 = 12


*/

// count number of undirected graphs that can be formed
// number of graphs arrangements that can be formed from the perspective of each node = n*(n-1)
// since undirected we divide by 2
// now for each combination there is an option to either connect it or don't 2^x 
long long count(int n) {
        int x;
        x = (n*(n-1))/2;
        return pow(2,x);
    }

//adajaceny list as per the number of vertices and edges
vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>> AD_list(V,vector<int>());
        for(auto p:edges){
            AD_list[p.first].push_back(p.second);
            AD_list[p.second].push_back(p.first);
        }
        return AD_list;
    }

//dfs recursion with visited list
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ans){
        ans.push_back(node);
        visited[node]=true;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]) dfs(adj[node][i],adj,visited,ans);
        }
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        vector<int> ans;
        vector<bool> visited(adj.size(),false);
        
        dfs(0,adj,visited,ans);
        
        return ans;
    }    

//bfs traversal queue needed 
vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    vector<int> ans;
    queue<int> nodes;
    vector<bool> visited(adj.size(), false);
    
    nodes.push(0);
    visited[0] = true; // Mark the start node as visited immediately after pushing if we try moving it to pop there are chances of multiple entries

    while (!nodes.empty()) {
        int current_node = nodes.front();
        nodes.pop();
        ans.push_back(current_node);
        
        for (int i = 0; i < adj[current_node].size(); i++) {
            int neighbor = adj[current_node][i];
            if (!visited[neighbor]) {
                nodes.push(neighbor);
                visited[neighbor] = true; // Mark the neighbor as visited when pushing to the queue
            }
        }
    }
    
    return ans;
}    


//connected components
   void dfs(int node,vector<int>adj[],vector<int>&temp,vector<bool>&visited){
       visited[node]=1;
       temp.push_back(node);
       for(int k=0;k<adj[node].size();k++){
           if(!visited[adj[node][k]])
           dfs(adj[node][k],adj,temp,visited);
       }
   }
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
        vector<int>adj[v];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(v,0);
        vector<vector<int>>ans;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                vector<int>temp;
                dfs(i,adj,temp,visited);
                sort(temp.begin(),temp.end());
                ans.push_back(temp);
            }
        }
        return ans;
    }

//number of connected components with matrix 
void dfs(int node,vector<vector<int>> &mat,vector<bool> &visited){
        visited[node]=true;
        for(int j=0;j<mat.size();j++){
            if(mat[node][j]==1 && !visited[j]){
                dfs(j,mat,visited);
            }    
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<bool> visited(isConnected.size(),false);
        int provincescount=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                vector<int> component;
                dfs(i,isConnected,visited,component);
                provincescount++;
            }
        }

        return provincescount;
    }



int main(){
    return 0;
}
