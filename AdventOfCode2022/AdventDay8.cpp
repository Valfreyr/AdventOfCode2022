#include "AdventDay8.h"

static vector<vector<int>> forest;
int AdventDay8::Solve(fstream& file)
{
	string line;
	while (getline(file, line)) {
		vector<int> temp;
		for (char c : line) {
			temp.push_back(c - '0');
		}
		forest.push_back(temp);
	}
	
	int visibleTreesNumber = CountVisibleTrees();

	return visibleTreesNumber;
}

int AdventDay8::CountVisibleTrees()
{
	int treeNumber = 0;

	int maxSize = forest[0].size();
	int edgeSize = maxSize - 1;

	int right = 0;
	int left = 0;
	int up = 0;
	int down = 0;

	int bestView = 0;
	
	for (int i = 1; i < edgeSize; i++) {
		vector<int> line = forest[i];

		for (int j = 1; j < edgeSize; j++) {
			int tree = forest[i][j];

			//part 1
			/*if (CheckRight(i, j + 1, maxSize, tree) ||
				CheckLeft(i, j - 1, maxSize, tree) ||
				CheckUp(j, i -1, maxSize, tree) ||
				CheckDown(j, i + 1, maxSize, tree)){
				treeNumber++;
			}*/

			right = get<1>(CheckRight(i, j + 1, maxSize, tree));
			left = get<1>(CheckLeft(i, j - 1, maxSize, tree));
			up = get<1>(CheckUp(j, i - 1, maxSize, tree));
			down = get<1>(CheckDown(j, i + 1, maxSize, tree));

			int score = right * left * up * down;
			if (score > bestView) {
				bestView = score;
			}
		}
	}

	// part 1
	//return treeNumber + edgeSize * 4;
	return bestView;
}

tuple<bool, int> AdventDay8::CheckRight(int column,int start, int maxSize, int treeHeight)
{
	int treeCount = 0;
	for (int i = start; i < maxSize; i++) {
		int tree = forest[column][i];
		treeCount++;

		if (tree >= treeHeight)
			return tuple<bool,int>(false, treeCount);
	}
	return tuple<bool, int>(true, treeCount);
}

tuple<bool, int> AdventDay8::CheckLeft(int column, int start, int maxSize, int treeHeight)
{
	int treeCount = 0;
	for (int i = start; i >= 0; i--) {
		int tree = forest[column][i];
		treeCount++;

		if (tree >= treeHeight)
			return tuple<bool, int>(false, treeCount);
	}
	return tuple<bool, int>(true, treeCount);
}

tuple<bool, int> AdventDay8::CheckUp(int row, int start, int maxSize, int treeHeight)
{
	int treeCount = 0;
	for (int i = start; i >= 0; i--) {
		int tree = forest[i][row];
		treeCount++;

		if (tree >= treeHeight)
			return tuple<bool, int>(false, treeCount);
	}
	return tuple<bool, int>(true, treeCount);
}

tuple<bool, int> AdventDay8::CheckDown(int row, int start, int maxSize, int treeHeight)
{
	int treeCount = 0;
	for (int i = start; i < maxSize; i++) {
		int tree = forest[i][row];
		treeCount++;

		if (tree >= treeHeight)
			return tuple<bool, int>(false, treeCount);
	}
	return tuple<bool, int>(true, treeCount);
}
