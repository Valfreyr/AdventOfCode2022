#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include <tuple>

using namespace std;

class AdventDay7 {
public:
	static int ProcessLine(vector<tuple<string, string, string>> &lines);
};

class Node {
public:
	Node(Node *Parent, int Size);
	int CalculateSum();
	void AddNode(Node &node);
	Node* FindNode(string name);
	int FindDirectoriesPart1();
	int FindDirectoryToDelete(int deleteSize);

	Node *Parent = nullptr;
	int Size = 0;
	vector<Node> Nodes;
	string Name;
	bool isFile = false;
};

