#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[17][17];
int n;
int answer;
vector<int> a;

int getSynergy() {
	vector<int> b;
	int idx = 0;

	for (int i = 0; i < n; ++i) {
		if (i == a[idx]) {
			idx++;
		} else {
			b.push_back(i);
		}
	}
	
	int a_sum = 0, b_sum = 0;
	for (int i = 0; i < n/2; ++i) {
		for (int j = i+1; j < n/2; ++j) {
			a_sum += arr[a[i]][a[j]] + arr[a[j]][a[i]];
			b_sum += arr[b[i]][b[j]] + arr[b[j]][b[i]];
		}
	}

	return abs(a_sum-b_sum);
}
void dfs(int idx, int cnt) {
	if (cnt == n/2) {
		int synergy = getSynergy();
		if (answer > synergy) {
			answer = synergy;
		}
		return;
	}

	for (int i = idx; i < n; ++i) {
		a.push_back(i);
		dfs(i+1, cnt+1);
		a.pop_back();
	}
}
int main() {
	int T;
	cin>>T;
	
	for(int test_case = 1; test_case <= T; ++test_case) {
		answer = 987654321;
		cin >> n;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> arr[i][j];
			}
		}

		dfs(0,0);

		cout << "#" << test_case << " " << answer << "\n";

	}
	return 0;
}