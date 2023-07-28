#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Graph{
    private:
        unordered_map<string, unordered_set<string>> adjList;

    public:
        void print() {
            unordered_map<string, unordered_set<string>>::iterator kvPair = adjList.begin();
            while (kvPair != adjList.end()) {
                cout  << kvPair->first << ": [ ";  // this prints out the vertex
                unordered_set<string>::iterator edge = kvPair->second.begin();
                while (edge != kvPair->second.end()) {
                    cout  << edge->data() << " ";  // this prints out edges
                    edge++;
                }
                cout << "]" << endl;
                kvPair++;
            }
        }

        bool addVertex(string vertex){
            if(adjList.count(vertex) == 0){
                adjList[vertex];
                return true;
            }
            return false;
        }
        bool addEdge(string v1, string v2){
            //v1 & v2 both exist then this if condition is exectued
            if(adjList.count(v1) != 0 && adjList.count(v2) != 0){
                adjList.at(v1).insert(v2);
                adjList.at(v2).insert(v1);
                return true;
            }
            return false;
        }
        bool removeEdge(string v1, string v2){
            if(adjList.count(v1) != 0 && adjList.count(v2) != 0){
                adjList.at(v1).erase(v2);
                adjList.at(v2).erase(v1);
                return true;
            }
            return false;
        }
};

int main(){
    Graph* myGraph = new Graph();
    myGraph->addVertex("A");
    myGraph->addVertex("B");
    myGraph->addVertex("C");

    myGraph->addEdge("A","B");
    myGraph->addEdge("A","C");
    myGraph->addEdge("B","C");

    //removing edge between A and B
    myGraph->removeEdge("A","B");
    myGraph->print();
}