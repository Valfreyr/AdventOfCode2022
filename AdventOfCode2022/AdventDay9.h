#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;


class AdventDay9
{
//public :
//	struct Point {
//		int x = 0;
//		int y = 0;
//
//		Point(int x, int y) {
//			this->x = x;
//			this->y = y;
//		}
//
//		/*Point(const Point&) = default;
//
//		Point& operator=(const Point& point) = default;*/
//
//		inline bool operator==(Point& point) const{
//			return x == point.x && y == point.y;
//		}
//
//
//	};

public:
	static int Solve(fstream& file);
	static void Move(tuple<int,int>& point, string direction);
	static void TailFollow(tuple<int, int>& tail, tuple<int, int> head, string direction);
	static bool CheckListElements(tuple<int, int> point);

	/*tuple<int, int> tail;
	tuple<int, int> head;*/
	
};


//namespace std {
//	template<> struct hash<AdventDay9::Point> {
//		size_t operator()(const AdventDay9::Point& point) const {
//			size_t xHash = hash<int>()(point.x);
//			size_t yHash = hash<int>()(point.y);
//
//			return xHash ^ yHash;
//		}
//	};
//}

