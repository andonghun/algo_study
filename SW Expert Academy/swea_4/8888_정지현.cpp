#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int point[2001]; // 문제 점수
int arr[2001][2001];

struct Node {
	int num; // 번호
    int score; // 점수
    int solve; // 맞춘 문제 수
};

bool cmp(Node a, Node b) {
	if (a.score == b.score) {
		if (a.solve == b.solve) {
			return a.num < b.num;
		}

		return a.solve > b.solve;
	}

	return a.score > b.score;
}
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int tc;
	int T;
	cin>>T;
	
	for(tc = 1; tc <= T; ++tc) {
		int n, t, p;
		cin >> n >> t >> p;

		memset(point, 0, sizeof(point));
		memset(arr, 0, sizeof(arr));
		vector<Node> person(n);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < t; ++j) {
				cin >> arr[i][j];
				if (arr[i][j] == 0) point[j]++;
			}
		}

		for (int i = 0; i < n; ++i) {
			person[i].num = i+1;
			for (int j = 0; j < t; ++j) {
				if (arr[i][j] == 1) {
					person[i].score += point[j];
					person[i].solve++;
				}
			}
		}

		sort(person.begin(), person.end(), cmp);

		for (int i = 0; i < n; ++i) {
			if (person[i].num == p) {
				cout << "#" << tc << " " << person[i].score << " " << i+1 << "\n";
			}	
		}	

	}

	return 0;
}