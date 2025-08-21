#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class DFSTraversal {
    vector<vector<int> > adjacency;

public:
    explicit DFSTraversal(const int v) {
        adjacency.resize(v);
    }

    /* Insert an edge (undirected graph) */
    void insertedEdge(const int s, const int d) {
        adjacency[s].push_back(d);
        adjacency[d].push_back(s);
    }

    /* Iterative DFS using stack */
    void dfsDisplay(const int source) const {
        vector<bool> visitedNodes(adjacency.size(), false);
        vector<int> parentNodes(adjacency.size(), -1);
        stack<int> stk;

        stk.push(source);
        visitedNodes[source] = true;
        parentNodes[source] = -1;

        while (!stk.empty()) {
            const int p = stk.top();
            stk.pop();

            cout << "DFS traversal is : " << p << endl;

            for (int i: adjacency[p]) {
                if (!visitedNodes[i]) {
                    visitedNodes[i] = true;
                    stk.push(i);
                    parentNodes[i] = p;
                }
            }
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of Vertices and Edges : " << endl;
    cin >> vertices >> edges;

    DFSTraversal dfs(vertices);

    cout << "Enter edges : " << endl;
    for (int i = 0; i < edges; i++) {
        int s, d;
        cin >> s >> d;
        dfs.insertedEdge(s, d);
    }

    cout << "Enter the source where you want to traverse the graph : " << endl;
    int source;
    cin >> source;

    dfs.dfsDisplay(source);

    return 0;
}
