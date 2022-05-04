#ifndef GRAPH_H
#define GRAPH_H

using namespace std;
#include <string>

struct Graph
{
	double** matrix;
	int size;

	Graph(int size);
	~Graph();
};

double FordFulkerson(Graph& graph, int vertex1, int vertex2);

#endif