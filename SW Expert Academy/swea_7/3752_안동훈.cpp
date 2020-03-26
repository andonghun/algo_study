#include<bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int score[100];
	int possible[10001];
	int test_case;
	int T, N;
	cin>>T;
	for (test_case = 1; test_case <= T; ++test_case) {
		memset(score, 0, sizeof(score));
		memset(possible, 0, sizeof(possible));
		possible[0] = 1;
		int cnt = 0;
		int max = 0;
		cin >> N;
		for (int i=0; i<N; i++) {
			cin >> score[i];
			max += score[i];
			for (int j = max; j>=0; j--) {
				if(possible[j] == 1) {
					possible[j+score[i]] = 1;
				}
			}
		}
		for (int i=0; i<=max; i++) {
			if(possible[i] == 1) cnt++;
		}
		cout << "#" << test_case << " " << cnt << '\n';
	}
	return 0;
}
