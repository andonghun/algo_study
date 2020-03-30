#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int dia[1001];
int dp[10001];
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;

	for(int tc = 1; tc <= T; ++tc) {
		int n,k;
		cin >> n >> k;
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < n; ++i) {
			cin >> dia[i];
			dp[dia[i]]++;
		}

		sort(dia, dia+n);

		int answer = 0;
		for (int i = 0; i < n; i++) {
			int cnt = dp[dia[i]];
			for (int j = i+cnt; j < n; j++) {
				if (dia[j] - dia[i] <= k) cnt++;
			}
			
			answer = cnt > answer ? cnt : answer;	
		}

		cout << "#" << tc << " " << answer << "\n";

	}
	return 0;
}