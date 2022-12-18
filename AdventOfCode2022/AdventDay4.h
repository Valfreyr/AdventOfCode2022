#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Task.h"

using namespace std;

class AdventDay4 {
public:
	static int ProcessLine(string line);
	
private:
	static vector<string> Split(string text, char delim);
	static Task CreateTask(string task);
	static int CompareTasks(Task t1, Task t2);
};
