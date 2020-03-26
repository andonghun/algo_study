// 제한시간 초과 ;; 이거 말고 다른 방식으로 어케 풀지 모르겠음
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	int T;
	int M, N, C1, C2;
	int x, y;
	cin>>T;
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> N >> M;
		cin >> C1 >> C2;
		int dist_x = abs(C2-C1);
		vector<int> h;
		vector<int> t;
		for (int i=0; i<N; i++) {
			cin >> x;
			h.push_back(x);
		}
		sort(h.begin(), h.end());
		t = h;
		int dist_y = 200000000;
		vector<int> ct;
		for (int i=0; i<M; i++) {
			cin >> y;
			h=t;
			h.push_back(y);
			sort(h.begin(), h.end());
			vector<int>::iterator it = find(h.begin(), h.end(), y);
			ct.push_back(abs(*(it-1) - y));
			ct.push_back(abs(*(it+1) - y));
			dist_y = min(abs(*(it-1) - y), min(abs(*(it+1) - y), dist_y));
		}
		int cnt = count(ct.begin(), ct.end() ,dist_y);
		cout << "#" << test_case << " " << dist_x + dist_y << " " << cnt << '\n';
	}
	return 0;
}
