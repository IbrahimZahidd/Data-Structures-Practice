/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>

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

void allPaths(vector<Edge> graph[], vector<bool> vis, int curr, string path, int tar) {
    if(curr==tar) {
        cout<<path<<endl;
        return;
    }
    for(int i=0;i<graph[curr].size();i++) {
        Edge e = graph[curr][i];
        if(!vis[e.dest]) {
            vis[curr] = true;
            allPaths(graph, vis, e.dest, path+to_string(e.dest), tar);
            vis[curr] = false;
        }
    }
}

int main()
{
    // number of vertices in a graph
    int V=7;
    vector<Edge> graph[V];
    vector<bool> vis(7, false);
    createGraph(graph);
    
    // printing Vertex's 2 neighbours
    for(int i=0; i<graph[3].size();i++) {
        Edge e = graph[3][i];
        cout<<e.dest<<" ";
    }
    cout<<endl;
    
    string path = "0";
    
    // allPath's output is:
    cout<<"The allPaths between 0 and 5 are: ";
    allPaths(graph, vis, 0, path, 5);
    cout<<endl;
}
