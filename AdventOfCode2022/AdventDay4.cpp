#include "AdventDay4.h"

int AdventDay4::ProcessLine(string line){

	vector<string> tasks = AdventDay4::Split(line, ',');
	Task task1 = CreateTask(tasks[0]);
	Task task2 = CreateTask(tasks[1]);

	return CompareTasks(task1, task2);
}

vector<string> AdventDay4::Split(string text, char delim)
{
	vector<string> strings;
	stringstream test(text);
	string segment;

	while (getline(test, segment, delim)) {
		strings.push_back(segment);
	}
	return strings;
}

Task AdventDay4::CreateTask(string task)
{
	vector<string> ranges = Split(task, '-');

	return Task(stoi(ranges[0]), stoi(ranges[1]));
}

int AdventDay4::CompareTasks(Task t1, Task t2)
{
	//part 1
	/*if (t1.LowerRange <= t2.LowerRange && t1.UpperRange >= t2.UpperRange)
		return 1;

	if (t2.LowerRange <= t1.LowerRange && t2.UpperRange >= t1.UpperRange)
		return 1;*/

	if (t1.UpperRange >= t2.LowerRange && t1.LowerRange <= t2.LowerRange)
		return 1;

	if (t2.UpperRange >= t1.LowerRange && t2.LowerRange <= t1.LowerRange)
		return 1;

	return 0;
}
