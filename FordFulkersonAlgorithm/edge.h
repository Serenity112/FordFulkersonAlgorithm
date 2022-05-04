#ifndef EDGE_H
#define EDGE_H

using namespace std;
#include <string>

struct Edge
{
public:
	string vertex1;
	string vertex2;
	double weight;

	Edge(string vertex1, string vertex2, double weight)
	{
		this->vertex1 = vertex1;
		this->vertex2 = vertex2;
		this->weight = weight;
	}

	Edge()
	{
		this->vertex1 = "";
		this->vertex2 = "";
		this->weight = 0.0;
	}
};

#endif