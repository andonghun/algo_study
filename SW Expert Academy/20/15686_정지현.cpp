#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int map[51][51];
int n,m;
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;
vector<pair<int,int>> v;
int answer;

void dfs(int idx, int cnt) {
	if (cnt == m) {
		int total = 0;

		for (int i = 0; i < house.size(); ++i) {
			int d = 987654321;
			for (int j = 0; j < v.size(); ++j) {
				int x = abs(house[i].first - v[j].first);
				int y = abs(house[i].second - v[j].second);
				d = min(d, x+y);
			}

			total += d;
		}

		answer = min(answer, total);
		return;
	}

	for (int i = idx; i < chicken.size(); ++i) {
		v.push_back(chicken[i]);
		dfs(i+1, cnt+1);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	answer = 987654321;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];

			if (map[i][j] == 1) {
				house.push_back({i,j});
			} else if (map[i][j] == 2) {
				chicken.push_back({i,j});
			}
		}
	}

	dfs(0,0);
	
	cout << answer;

	return 0;
}