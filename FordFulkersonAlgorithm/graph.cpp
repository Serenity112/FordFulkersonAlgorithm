using namespace std;
#include <string>
#include <limits.h>
#include <iostream>

#include "graph.h"
#include "queue.h"

#define inf DBL_MAX

Graph::Graph(int size)
{
	this->size = size;
	matrix = new double* [size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new double[size];
		for (int j = 0; j < size; j++)
			matrix[i][j] = inf;
	}
}

bool bfs(Graph& rGraph, int s, int t, int* parent)
{
    bool* visited = new bool[rGraph.size];
    for (int i = 0; i < rGraph.size; i++)
        visited[i] = false;

    Queue<int> queue;
    queue.push(s);
    visited[s] = true;
    parent[s] = -1;


    cout << "Start cycle" << endl;
    // Standard BFS Loop
    while (!queue.empty()) {
        int i = queue.front();
        queue.pop();

        for (int j = 0; j < rGraph.size; j++) {
            if (visited[j] == false && rGraph.matrix[i][j] > 0) {
                if (j == t) {
                    parent[j] = i;
                    return true;
                }

                queue.push(j);
                parent[j] = i;
                visited[j] = true;
            }
        }
    }

    return false;
}

double FordFulkerson(Graph& graph, int s, int t)
{
    cout << "Graph: " << endl;
    for (int i = 0; i < graph.size; i++)
    {
        for (int j = 0; j < graph.size; j++)
        {
            cout << graph.matrix[i][j] << " ";
        }
        cout << endl;
    }

    int size = graph.size;
    Graph rGraph(size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            rGraph.matrix[i][j] = graph.matrix[i][j];

    int* parent = new int[size]; 

    double max_flow = 0.0;

    while (bfs(rGraph, s, t, parent)) {

        double path_flow = INT_MAX;
        for (int i = t; i != s; i = parent[i]) {
            int j = parent[i];
            path_flow = min(path_flow, rGraph.matrix[j][i]);
        }

        for (int i = t; i != s; i = parent[i]) {
            int j = parent[i];
            rGraph.matrix[j][i] -= path_flow;
            rGraph.matrix[i][j] += path_flow;
        }

        max_flow += path_flow;
    }

    cout << "max: " << max_flow << endl;

    return max_flow;
}