#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    // creating an unordered_map for making adjecency list
    unordered_map<int, list<int>> adj;
    // function to add edge [u-v] & ([v-u] if gragh is undirected)
    void addedge(int u, int v, bool type)
    {
        // type == 1 for directed graph
        adj[u].push_back(v);
        // type == 0 for undirected graph
        if (type == 0)
            adj[v].push_back(u);
    }
    // function to print adjcecy list
    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
                cout << j << " ";
            cout << endl;
        }
    }
};
int main()
{
    int number_of_nodes;
    cin >> number_of_nodes;
    int number_of_edges;
    cin >> number_of_edges;
    bool isundirected;
    cin >> isundirected;
    // creating a object of graph class
    graph g;
    //
    for (int i = 0; i < number_of_edges; i++)
    {
        // taking input from user u==key , v==value;
        int u, v;
        cin >> u >> v;
        // calling addedge function u-->key , v--> value for map adj
        g.addedge(u, v, isundirected);
    }
    // calling print function to print the adjcecy list
    g.print();
    return 0;
}
/*
input for directed graph
5
6
1
0 1
0 2
3 2
1 4
1 3
4 3
input for undirected graph
5
6
0
0 1
0 2
3 2
1 4
1 3
4 3
*/
