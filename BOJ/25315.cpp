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
int n;
Cut cut[2500];
vector<vector<int>> vec(2500);
vector<pair<int, int>> pw(2500);

int ccw(Point p1, Point p2, Point p3) {
	return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}

bool isCross(int c1, int c2) {
	if (ccw(cut[c1].s, cut[c1].e, cut[c2].s) * ccw(cut[c1].s, cut[c1].e, cut[c2].e) < 0
		&& ccw(cut[c2].s, cut[c2].e, cut[c1].s) * ccw(cut[c2].s, cut[c2].e, cut[c1].e) < 0)
		return true;
	else
		return false;
}

bool compare(pair<int,int> i1, pair<int,int> i2) {
	return vec[i1.second].size() < vec[i2.second].size();
}

int main() {
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cut[i].s.x >> cut[i].s.y >> cut[i].e.x >> cut[i].e.y >> cut[i].w;
		pw[i].first = cut[i].w;
		pw[i].second = i;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			if (isCross(i, j)) {
				vec[i].push_back(j);
				vec[j].push_back(i);
			}
		}
	}
	//서로 교차하면 가중치가 작은 것부터
	sort(pw.begin(), pw.begin() + n);//가중치 순으로 정렬
	for (int i = 0, j = 0; i < n; )
	{
		if (pw[i].first == pw[i + 1].first) {
			j = i;
			while (pw[i].first == pw[i + 1].first && i + 1 < n) i++;
		}
		sort(pw[j], pw[i], compare);
		while (j < i)
		{
			int num = pw[j].second;
			for (int k = 0; k < vec[num].size(); )
			{
				ans += cut[num].w * (vec[num].size() + 1);
				vec[vec[num][k]].erase(find(vec[vec[num][k]].begin(), vec[vec[num][k]].end(), num));
				vec[num].erase(vec[num].begin());
			}
			j++;
		}
	}
	cout << ans;
}