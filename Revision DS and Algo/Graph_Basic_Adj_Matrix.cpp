#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    // Traditional Method
    int n;
    cout << "Enter the number of edges you want to insert in graph:- " << endl;
    cin >> n;

    int graph[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    // Undirected graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int u, v;
            cout << "Enter the source node:- " << endl;
            cin >> u;
            cout << "Enter the destination node you want to insert:- " << endl;
            cin >> v;

            graph[u][v] = 1;
            graph[v][u] = 1;
        }
    }

    // Directed graph

    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
