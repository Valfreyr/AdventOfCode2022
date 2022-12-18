#include "AdventDay5.h"


vector<stack<char>> stacks;
vector<char> boxes;
regex textRegex("move (\\d+) from (\\d+) to (\\d+)");
bool stacksInitialised;
bool finilize;
static tuple<int, int, int> commands;

int AdventDay5::ProcessLine(string line)
{
	string processedLine;
	if (line[0] == '[') {
		processedLine = AdventDay5::RemoveBrackets(line);
		AdventDay5::CreateStack(processedLine);
	}
	else if (line[0] == 'm') {
		if (!stacksInitialised) {
			AdventDay5::ReverseStack();
			stacksInitialised = true;
		}
		commands = AdventDay5::GetCommands(line);

		Final();
	}

	return 0;
}

void AdventDay5::Final() {
	//part 1
	/*for (int i = 0; i < get<0>(commands); i++) {
		char box = stacks[get<1>(commands) - 1].top();
		stacks[get<1>(commands) - 1].pop();

		stacks[get<2>(commands) - 1].push(box);
	}

	for (stack<char> stack : stacks) {
		if(!stack.empty())
			cout << stack.top();
	}
	cout << endl;*/

	//part 2

	stack<char> temp;
	for (int i = 0; i < get<0>(commands); i++) {
		char box = stacks[get<1>(commands) - 1].top();
		stacks[get<1>(commands) - 1].pop();
		temp.push(box);
	}

	for (int i = 0; i < get<0>(commands); i++) {
		char box = temp.top();
		temp.pop();
		stacks[get<2>(commands) - 1].push(box);
	}

	for (stack<char> stack : stacks) {
		if(!stack.empty())
			cout << stack.top();
	}
	cout << endl;

}

tuple<int,int,int> AdventDay5::GetCommands(string line)
{
	smatch baseMatch;
	if (regex_match(line, baseMatch, textRegex)) {
		if (baseMatch.size() == 4) {
			string test = baseMatch[1].str();
			auto integer = stoi(test);

			string test1 = baseMatch[2].str();
			auto integer1 = stoi(test1);

			string test2 = baseMatch[3].str();
			auto integer2 = stoi(test2);
			tuple<int, int, int> tuple{ integer, integer1, integer2 };
			return tuple;
		}
	}
}

void AdventDay5::ReverseStack()
{
	stack<char> reversedStack;
	for (int i = 0; i < stacks.size(); i++) {
		stack<char> stack = stacks[i];

		while (!stack.empty()) {
			reversedStack.push(std::move(stack.top()));
			stack.pop();
		}

		stacks[i] = move(reversedStack);
	}
}

string AdventDay5::RemoveBrackets(string line)
{
	string newstring = "";
	for (int i = 1; i < line.size(); i+=4) {
		newstring.push_back(line[i]);
	}

	return newstring;
}

void AdventDay5::CreateStack(string line)
{
	for (int i = 0; i < line.size(); i++) {
		if (stacks.size() <= i) {
				stack<char> stack;
				if (line[i] != 32) {
					stack.push(line[i]);
				}
				stacks.push_back(stack);
		}
		else {
			if(line[i] != 32)
				stacks[i].push(line[i]);
		}
	}
}




