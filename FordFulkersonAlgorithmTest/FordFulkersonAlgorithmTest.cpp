#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <iostream>

#include "..\FordFulkersonAlgorithm\map.h"
#include "..\FordFulkersonAlgorithm\graph.h"
#include "..\FordFulkersonAlgorithm\maxflowmanager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FordFulkersonAlgorithmTest
{
	TEST_CLASS(FordFulkersonAlgorithmTest)
	{
	public:
		
		TEST_METHOD(Path1)
		{

			List<Edge> edgeList;
			edgeList.push_back(Edge("S", "A", 16));
			edgeList.push_back(Edge("S", "B", 13));
			edgeList.push_back(Edge("A", "B", 10));
			edgeList.push_back(Edge("B", "A", 4));
			edgeList.push_back(Edge("A", "C", 12));
			edgeList.push_back(Edge("C", "B", 9));
			edgeList.push_back(Edge("B", "D", 14));
			edgeList.push_back(Edge("D", "C", 7));
			edgeList.push_back(Edge("C", "T", 20));
			edgeList.push_back(Edge("D", "T", 4));

			double maxpath = findMaxFlow(edgeList, "S", "T");

			Assert::AreEqual(maxpath, 23.0);
		}
		

		TEST_METHOD(Path2)
		{
			List<Edge> edgeList;
			edgeList.push_back(Edge("S", "O", 3));
			edgeList.push_back(Edge("S", "P", 3));
			edgeList.push_back(Edge("O", "Q", 3));
			edgeList.push_back(Edge("O", "P", 2));
			edgeList.push_back(Edge("P", "R", 2));
			edgeList.push_back(Edge("Q", "R", 4));
			edgeList.push_back(Edge("Q", "T", 2));
			edgeList.push_back(Edge("R", "T", 3));

			double maxpath = findMaxFlow(edgeList, "S", "T");

			Assert::AreEqual(maxpath, 5.0);
		}
	};
}
