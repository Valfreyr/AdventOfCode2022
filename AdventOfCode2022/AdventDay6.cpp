#include "AdventDay6.h"
#include <unordered_map>
int AdventDay6::ProcessLine(string line)
{
	//part 1
	/*for (int i = 0; i < line.size(); i++) {
		if (i + 3 < line.size()) {
			if (!CompareChar(line[i], line[i + 1]) && !CompareChar(line[i], line[i + 2]) && !CompareChar(line[i], line[i + 3])
				&& !CompareChar(line[i + 1], line[i + 2]) && !CompareChar(line[i + 1], line[i + 3]) && !CompareChar(line[i + 2], line[i + 3])) {
				return i + 4;
			}
		}
	}*/

	//part 2

	return GetMessageMarker(line);
}

bool AdventDay6::CompareChar(char c1, char c2)
{
	return c1 == c2;
}

int AdventDay6::GetMessageMarker(string line)
{
	vector<char> letters;
	int i = 0;

	while (i < line.size()) {
		for (int j = i; j < line.size(); j++) {
			if (letters.size() == 14)
				return j;

			auto match = find(letters.begin(), letters.end(), line[j]);
			if (match == letters.end()) {
				letters.push_back(line[j]);
			}
			else {
				letters.clear();
				i++;
				break;
			}
		}
	}
	return 0;
}
