#ifndef MAXFLOWMANAGER_H
#define MAXFLOWMANAGER_H

using namespace std;
#include <string>

#include "list.h"
#include "edge.h"

double findMaxFlow(List<Edge>& edgeList, string s, string t);

List<Edge> getEdgeList(string fileName);

#endif