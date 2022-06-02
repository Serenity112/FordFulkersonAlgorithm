using namespace std;
#include <string>
#include <limits.h>
#include <iostream>

#include "graph.h"
#include "queue.h"

Graph::Graph(int size)
{
	this->size = size;
	matrix = new double* [size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new double[size];
		for (int j = 0; j < size; j++)
			matrix[i][j] = 0;
	}
}

Graph::~Graph()
{
    delete [] matrix;
}

double minimum(double n1, double n2)
{
    if (n1 <= n2)
        return n1;
    else
        return n2;
}

bool bfs(Graph& residualGraph, int source, int stock, int* parent)
{
    bool* visited = new bool[residualGraph.size];
    for (int i = 0; i < residualGraph.size; i++)
        visited[i] = false;

    Queue<int> queue;
    queue.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!queue.empty()) {
        int i = queue.front();
        queue.pop();

        for (int j = 0; j < residualGraph.size; j++) {
            if (visited[j] == false && residualGraph.matrix[i][j] > 0) {
                if (j == stock) {
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

double FordFulkerson(Graph& graph, int source, int stock)
{
    int size = graph.size;
    Graph residualGraph(size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            residualGraph.matrix[i][j] = graph.matrix[i][j];

    int* parent = new int[size]; 

    double max_flow = 0.0;

    while (bfs(residualGraph, source, stock, parent)) 
    {
        double path_flow = INT_MAX;
        for (int i = stock; i != source; i = parent[i]) 
        {
            int j = parent[i];
            path_flow = minimum(path_flow, residualGraph.matrix[j][i]);
        }

        for (int i = stock; i != source; i = parent[i]) 
        {
            int j = parent[i];
            residualGraph.matrix[j][i] -= path_flow;
            residualGraph.matrix[i][j] += path_flow;
        }
    
        max_flow += path_flow;
    }

    return max_flow;
}