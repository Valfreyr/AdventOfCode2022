#include "AdventDay7.h"

static int childrenSize;
static int smallest = INT_MAX;
Node::Node(Node* parent, int size)
{
	Parent = parent;
	Size = size;
}

int Node::CalculateSum()
{
	int sum = Size;
	
	for (Node& n : Nodes) {
		sum += n.CalculateSum();
	}

	if (!isFile) {
		Size = sum;
	}
	//if (sum <= 100000) {
	//	childrenSize += Size;
	//}

	return sum;
}

void Node::AddNode(Node &node)
{
	Nodes.push_back(node);
}

Node* Node::FindNode(string name)
{
	for (int i = 0; i < Nodes.size(); i++) {
		string nodeName = Nodes[i].Name;
		if (nodeName == name) {
			return &Nodes[i];
		}
	}

	// should never run
	return nullptr;
}

int Node::FindDirectoriesPart1()
{
	for (Node& n : Nodes) {
		n.FindDirectoriesPart1();
	}

	if (!isFile && Size <= 100000) {
		childrenSize += Size;
	}
	return childrenSize;
}

int Node::FindDirectoryToDelete(int deleteSize)
{
	for (Node& n : Nodes) {
		n.FindDirectoryToDelete(deleteSize);
	}

	if (!isFile && Size >= deleteSize && Size < smallest) {
		smallest = Size;
	}

	return smallest;
}

int AdventDay7::ProcessLine(vector<tuple<string, string, string>> &lines)
{
	Node root = Node(nullptr, 0);
	Node* currentNode = &root;
	regex onlyNumbers = regex("\\d+");
	for (int i = 0; i < lines.size(); i++) {
		tuple<string, string, string> line = lines[i];

		if (get<0>(line) == "$" && get<1>(line) == "cd") {
			if (get<2>(line) == "/") {
				continue;
			}
			else if (get<2>(line) == "..") {
				currentNode = currentNode->Parent;
			}
			else {
				string name = get<2>(line);
				currentNode = currentNode->FindNode(name);
			}
		}
		else if (isdigit(get<0>(line)[0])) {
			Node node = Node(currentNode, stoi(get<0>(line)));
			node.isFile = true;
			node.Name = get<1>(line);
			currentNode->AddNode(node);
			//currentNode->Size += stoi(get<0>(line));
		}
		else if (get<0>(line) == "dir") {
			Node node = Node(currentNode, 0);
			node.isFile = false;
			node.Name = get<1>(line);
			currentNode->AddNode(node);
		}
	}

	int sum = root.CalculateSum();
	int freeSpace = 70000000 - root.Size;
	int deleteSize = 30000000 - freeSpace;
	int directoryPart1 = root.FindDirectoriesPart1();

	//return directoryPart1;
	int nodeToDeleteSize = root.FindDirectoryToDelete(deleteSize);
	return nodeToDeleteSize;
}
