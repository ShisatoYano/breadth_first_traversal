#include <iostream>
#include <list>
using namespace std;

// directed graph using adjacency list representation
class Graph {
    int v;
    list<int> *array;
public:
    Graph(int v);

    void add_edge(int v, int w);

    void breadth_first_search(int s);
};

Graph::Graph(int v) {
    this->v = v;
    array = new list<int>[v];
}

void Graph::add_edge(int v, int w) {
    array[v].push_back(w);
}

void Graph::breadth_first_search(int s) {
    // mark all vertices as not visited
    bool *visited = new bool[v];
    for (int i = 0; i < v; ++i) {
        visited[i] = false;
    }

    // create a queue
    list<int> queue;

    // mark the current node as visited
    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;
    while (!queue.empty()) {
        // dequeue a vertex from queue
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // get all adjacent vertices of the dequeued vertex s
        for (i = array[s].begin(); i != array[s].end() ; ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main() {
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";

    g.breadth_first_search(2);

    return 0;
}
