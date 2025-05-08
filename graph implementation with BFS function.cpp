/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge {
public:
    int src;
    int dest;
    Edge(int src, int dest) {
        this->src=src;
        this->dest=dest;
    }

};

void createGraph(vector<Edge> graph[]) {
    
    graph[0].push_back(Edge(0, 1));
    graph[0].push_back(Edge(0, 2));
    
    graph[1].push_back(Edge(1, 0));
    graph[1].push_back(Edge(1, 3));
    
    graph[2].push_back(Edge(2, 0));
    graph[2].push_back(Edge(2, 4));
    
    graph[3].push_back(Edge(3, 1));
    graph[3].push_back(Edge(3, 4));
    graph[3].push_back(Edge(3, 5));
    
    graph[4].push_back(Edge(4, 2));
    graph[4].push_back(Edge(4, 3));
    graph[4].push_back(Edge(4, 5));
    
    graph[5].push_back(Edge(5, 3));
    graph[5].push_back(Edge(5, 4));
    graph[5].push_back(Edge(5, 6));
    
    graph[6].push_back(Edge(6, 5));
}

void bfs1(vector<Edge> graph[], int V) {
    vector<bool> vis(V,false);
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if(vis[curr] == false) {
            cout<<curr<<" ";
            vis[curr] = true;
            for(int i = 0; i<graph[curr].size();i++){
                Edge e = graph[curr][i];
                q.push(e.dest);
            }
        }
    }
}

void bfs2(vector<Edge> graph[], int start, vector<bool> &vis) {
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if(vis[curr] == false) {
            cout<<curr<<" ";
            vis[curr] = true;
            for(int i = 0; i<graph[curr].size();i++){
                Edge e = graph[curr][i];
                q.push(e.dest);
            }
        }
    }
}

int main()
{
    // number of vertices in a graph
    int V=7;
    vector<Edge> graph[V];
    createGraph(graph);
    
    // printing Vertex's 2 neighbours
    for(int i=0; i<graph[3].size();i++) {
        Edge e = graph[3][i];
        cout<<e.dest<<" ";
    }
    cout<<endl;
    
    // BFS1 output is:
    cout<<"The BFS Method 1 output is: ";
    bfs1(graph, V);
    cout<<endl;
    
    // BFS2 output is:
    cout<<"The BFS Method 2 output is: ";
    vector<bool> vis(V,false);
    int start;
    for(int i=0;i<V;i++) {
        if(vis[i] == false) {
            bfs2(graph, i, vis);
        }
    }
    cout<<endl;
}
