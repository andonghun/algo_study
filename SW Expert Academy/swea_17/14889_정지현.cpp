#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[20][20];
int answer;
vector<int> start;
int n;
int getPower() {
	vector<int> link;
	int idx = 0;

	for (int i = 0; i < n; ++i) {
		if (i == start[idx]) {
			idx++;
		} else {
			link.push_back(i);
		}
	}
	
	int s = 0, l = 0;
	for (int i = 0; i < n/2; ++i) {
		for (int j = i+1; j < n/2; ++j) {
			s += arr[start[i]][start[j]] + arr[start[j]][start[i]];
			l += arr[link[i]][link[j]] + arr[link[j]][link[i]];
		}
	}

	return abs(s-l);
}
void dfs(int idx, int cnt) {
	if (cnt == n/2) {
		int power = getPower();
		if (answer > power) {
			answer = power;
		}
		return;
	}
	for (int i = idx; i < n; ++i) {
		start.push_back(i);
		dfs(i+1, cnt+1);
		start.pop_back();
	}
}
int main() {
	cin >> n;
	answer = 987654321;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}
	
	dfs(0,0);

	cout << answer;
	return 0;
}