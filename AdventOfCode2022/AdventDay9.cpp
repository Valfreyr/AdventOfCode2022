#include "AdventDay9.h"

//unordered_set<AdventDay9::Point> visitedPoints;

vector<tuple<int, int>> visitedPoints;
int AdventDay9::Solve(fstream& file)
{
    string direction;
    string moveNumber;
    tuple<int, int> head{ 0,0 };
    tuple<int, int> tail{ 0,0 };


    while (file >> direction >> moveNumber) {
        int moves = stoi(moveNumber);
        for (int i = 0; i < moves; i++) {
            Move(head, direction);
            TailFollow(tail, head, direction);
        }
    }

    return 0;
}

void AdventDay9::Move(tuple<int, int>& point, string direction)
{
    if (direction == "R") {
        get<0>(point) += 1;
    }
    else if (direction == "L") {
        get<0>(point) -= 1;
    }
    else if (direction == "U") {
        get<1>(point) += 1;
    }
    else {
        get<1>(point) -= 1;
    }
}

void AdventDay9::TailFollow(tuple<int, int>& tail, tuple<int, int> head, string direction)
{
    if (CheckListElements(tail)) {
        visitedPoints.push_back(tail);
    }
    
    /*int diag = abs(tail.x - head.x);
    if (abs(tail.x - head.x) == 1 || abs(tail.y - head.y) == 1){
        return;
    }*/

    if (abs(get<0>(tail) - get<0>(head)) > 1 || abs(get<1>(tail) - get<1>(head)) > 1) {
        Move(tail, direction);
    }
}

bool AdventDay9::CheckListElements(tuple<int,int> point)
{
    for (int i = 0; i < visitedPoints.size(); i++) {
        tuple<int, int> insidePoint = visitedPoints[i];
        if (get<0>(insidePoint) == get<0>(point) && get<1>(insidePoint) == get<1>(point)) {
            return false;
        }
    }

    return true;
}

