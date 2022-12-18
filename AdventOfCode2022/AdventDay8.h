#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class AdventDay8{
public:
	static int Solve(fstream& file);
	static int CountVisibleTrees();
	static tuple<bool,int> CheckRight(int column, int start, int maxSize, int treeHeight);
	static tuple<bool, int> CheckLeft(int column, int start, int maxSize, int treeHeight);
	static tuple<bool, int> CheckUp(int row, int start, int maxSize, int treeHeight);
	static tuple<bool, int> CheckDown(int row, int start, int maxSize, int treeHeight);
};

