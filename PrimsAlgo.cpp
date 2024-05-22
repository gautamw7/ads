#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int, pair<int, int>> Edge;

struct Compare{
    bool operator()(Edge &E1,Edge &E2 ){
        return E1.first > E2.first;
    }
};


class Graph{
private:
    int size;
    vector<vector<pair<int,int>>> adjList;
public:

    Graph(int nNodes){
        this->size = nNodes;
        adjList.resize(size);
    }

    void addEdge(int start, int end, int weight){
        if(start < 0 || end < 0 || end >= size || start >= size){
            cout << "Error: Node invalid" << endl;
            return;
        }
        adjList[start].push_back({end, weight});
        adjList[end].push_back({start, weight});
    }

    void display(){
        for(int i = 0; i < size ; i++){
            cout << "Vector " << i << ": ";
            for(auto Edge : adjList[i]){
                cout << "->" << Edge.first << " (Weight: " << Edge.second << ") ";
            }
            cout << endl;
        }
    }

    void primsMST(int startIndex){
        priority_queue<Edge, vector<Edge>, Compare> pq;

        vector<Edge> mst;

        // to check if it in
        vector<bool> inMst(size, false);
        inMst[startIndex] = true;

        for(auto edge : adjList[startIndex] ){
            pq.push({edge.second, {startIndex, edge.first}});
        }

        int EdgeCount = 0;
        while(!pq.empty() && EdgeCount < size - 1){
            Edge current = pq.top();
            pq.pop();

            int weight = current.first;
            int u = current.second.first;
            int v = current.second.second;

            // if the end vertices exists then we skip
            if(inMst[v]){
                continue;
            }

            // put int the MST and increase the count
            mst.push_back(current);
            EdgeCount++;

            // inMSt is true
            inMst[v] = true;

            // add all the end vertices connection if they don't exist in the priority queue
            for(auto edge : adjList[v]){
                if(!inMst[edge.first]){
                    pq.push({edge.second, {v, edge.first}});
                }
            }
        }
        cout << endl << "MST of Graph : " << endl;
        for(auto edge : mst){
            cout << edge.second.first << " -> " << edge.second.second << " (Weight: " << edge.first << " )" << endl;
        }
    }

};

int main() {
    Graph graph(6); // Create a graph with vertices numbered 0 through 5

    // Adding weighted edges (undirected)
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 10);
    graph.addEdge(3, 4, 6);
    graph.addEdge(3, 5, 1);
    graph.addEdge(4, 5, 7);

    // Display the weighted graph
    graph.display();

    // Find and display the MST using Kruskal's algorithm
    graph.primsMST(0);


    return 0;
}