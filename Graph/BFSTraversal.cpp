#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BFSTraversal {
    vector<vector<int> > adjacency;

public:
    explicit BFSTraversal(const int v) {
        adjacency.resize(v);
    }

    /* Insert an edge (undirected graph) */
    void insertedEdge(const int s, const int d) {
        adjacency[s].push_back(d);
        adjacency[d].push_back(s);
    }

    /* BFS traversal from a given source */
    void bfsDisplay(const int source) const {
        vector<bool> visitedNodes(adjacency.size(), false);
        vector<int> parentNodes(adjacency.size(), -1);
        queue<int> q;

        visitedNodes[source] = true;
        parentNodes[source] = -1;
        q.push(source);

        while (!q.empty()) {
            const int print = q.front();
            q.pop();
            cout << "Printing element : " << print << endl;

            for (int i: adjacency[print]) {
                if (!visitedNodes[i]) {
                    visitedNodes[i] = true;
                    q.push(i);
                    parentNodes[i] = print;
                }
            }
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of Vertices and Edges : " << endl;
    cout << "This is good C++ Programming" << endl << endl;

    cin >> vertices >> edges;
    BFSTraversal bfs(vertices);

    cout << "Enter the edges : " << endl;
    for (int i = 0; i < edges; i++) {
        int s, d;
        cin >> s >> d;
        bfs.insertedEdge(s, d);
    }

    cout << "Enter the source from where you want to traverse : " << endl;
    cout << "C++ is a good programming" << endl << endl;
    cout << "C++ Programming is a good programming...Which is my favourite programming" << endl << endl;

    int source;
    cin >> source;

    bfs.bfsDisplay(source);

    return 0;
}
