#pragma once
#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include <regex>
#include <tuple>
using namespace std;

class AdventDay5 {
public:
	static int ProcessLine(string line);
	static void Final();

private:
	static string RemoveBrackets(string line);
	static void CreateStack(string line);
	static tuple<int, int, int> GetCommands(string line);
	static void ReverseStack();
};
