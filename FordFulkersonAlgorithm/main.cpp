// C++ program for implementation of Ford Fulkerson
// algorithm
#include <iostream>
#include <limits.h>
#include <string.h>

#include "maxflowmanager.h"

using namespace std;

int main()
{
    List<Edge> edgeList = getEdgeList("input.txt");
    double flow = findMaxFlow(edgeList, "S", "T");
    cout << "Flow: " << flow;


    return 0;
}