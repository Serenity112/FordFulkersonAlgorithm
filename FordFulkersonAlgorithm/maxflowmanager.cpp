#include "maxflowmanager.h"
#include "graph.h"
#include "map.h"
#include "list.h"
#include "edge.h"

#include <string>
#include <fstream>


List<string> tokenize(string line, string separator = " ")
{
	int start = 0;
	int end = line.find(separator);
	List<string> splittedLines;

	while (end != -1)
	{
		splittedLines.push_back(line.substr(start, end - start));
		start = end + separator.size();
		end = line.find(separator, start);
	}

	splittedLines.push_back(line.substr(start, end - start));

	return splittedLines;
}

List<Edge> getEdgeList(string fileName)
{
	List<Edge> edgeList;

	ifstream finput;
	finput.open(fileName);

	string line;
	while (getline(finput, line))
	{
		List<string> newEdgeSrting = tokenize(line, " ");

		auto newEdge_itr = newEdgeSrting.create_iterator();
		string token1 = newEdge_itr->next();
		string token2 = newEdge_itr->next();
		string token3 = newEdge_itr->next();;
		delete newEdge_itr;

		Edge newEdge(token1, token2, stod(token3));
		edgeList.push_back(newEdge);
	}

	finput.close();
	return edgeList;
}

Map<string, int> giveVertexUniqueNumbers(List<Edge>& edgeList)
{
	Map<string, int>* vertexUniqueNumbers  = new Map<string, int>();

	auto itr = edgeList.create_iterator();
	int vertexCount = 0;

	while (itr->has_next())
	{
		Edge edge = itr->next();

		try
		{
			vertexUniqueNumbers->Insert(edge.vertex1, vertexCount);
			vertexCount++;
		}
		catch (const std::exception&) {}

		try
		{
			vertexUniqueNumbers->Insert(edge.vertex2, vertexCount);
			vertexCount++;
		}
		catch (const std::exception&) {}
	}
	delete itr;

	return *vertexUniqueNumbers;
}

Graph buildGraphByVertex(List<Edge>& edgeList, Map<string, int>& vertexNumerics)
{
	Graph* graph = new Graph(vertexNumerics.size);

	auto itr = edgeList.create_iterator();
	while (itr->has_next())
	{
		Edge edge = itr->next();
		int numVertex1 = vertexNumerics.Find(edge.vertex1);
		int numVertex2 = vertexNumerics.Find(edge.vertex2);
		graph->matrix[numVertex1][numVertex2] = edge.weight;
	}
	delete itr;

	return *graph;
}

double findMaxFlow(List<Edge>& edgeList, string s, string t)
{
	Map<string, int> vertexUniqueNumbers = giveVertexUniqueNumbers(edgeList);

	int size = vertexUniqueNumbers.size;
	int vertex1 = vertexUniqueNumbers.Find(s);
	int vertex2 = vertexUniqueNumbers.Find(t);

	Graph graph = buildGraphByVertex(edgeList, vertexUniqueNumbers);

	double max_path = FordFulkerson(graph, vertex1, vertex2);

	return max_path;
}