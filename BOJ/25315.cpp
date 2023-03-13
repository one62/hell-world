#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct Point {
	int x;
	int y;
};
struct Cut {
	Point s;
	Point e;
	int w;
};

int ccw(Point p1, Point p2, Point p3) {
	return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}

bool isCross(Cut c1, Cut c2) {
	if (ccw(c1.s, c1.e, c2.s) * ccw(c1.s, c1.e, c2.e) < 0
		&& ccw(c2.s, c2.e, c1.s) * ccw(c2.s, c2.e, c1.e) < 0)
		return true;
	else
		return false;
}

int main() {

}