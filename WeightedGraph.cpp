#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

class Graph{
private:
    int size;
    vector<vector<pair<int ,int>>> adjList;  // char and weight
public:
    Graph(int nNodes){
        this->size = nNodes + 1;
        adjList.resize(size);
    }

    void addEdge(int start, int end, int weight){
        if (start < 0 || end < 0 || start >= size || end >= size) {
            cout << "Error: Invalid node index\n";
            return;
        }

        adjList[start].push_back({end, weight});
        adjList[end].push_back({start, weight});
    }

    void display(){
        for(int i = 0; i < size ; i++){
            cout << "Vector " << i << ":";
            for(auto edge : adjList[i]){
                cout << " -> " << edge.first << "( Weight : " << edge.second << " )";
            }
            cout << endl;
        }
    }

    void deleteEdge(int start, int end){
        auto it = find_if(adjList[start].begin(), adjList[start].end(), [end](const pair<int,int>& p){
            return p.first == end;
        });
        if(it != adjList[start].end()){
            adjList[start].erase(it);
        }else{
            cout << "Edge from " << start << " to " << end << " not found." << endl;
        }

        it = find_if(adjList[end].begin(), adjList[end].end(), [start](const pair<int,int> &p){
            return p.first == start;
        });
        if(it != adjList[end].end()){
            adjList[end].erase(it);
        }else{
            cout << "Edge from " << end << " to " << start << " not found." << endl;
        }
    }

};

int main() {
    Graph graph(5); // Create a graph with vertices numbered 1 through 5

    // Adding weighted edges (undirected)
    graph.addEdge(1, 2, 5);
    graph.addEdge(1, 4, 3);
    graph.addEdge(2, 3, 2);
    graph.addEdge(2, 4, 1);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 7);
    graph.addEdge(3, 5, 6);

    graph.deleteEdge(3, 4);
    graph.deleteEdge(1, 4);
    // Display the weighted graph
    graph.display();

    return 0;
}