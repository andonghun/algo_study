#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

struct BC {
	int x,y,c,p;
};

BC battery[9];
int dx[] = {0,-1,0,1,0};
int dy[] = {0,0,1,0,-1};
int a[101];
int b[101];

int main() {
	int T;
	cin>>T;

	for(int test_case = 1; test_case <= T; ++test_case) {
		int M,A;
		cin >> M >> A;

		for (int i = 0; i < M; ++i) {
			cin >> a[i];
		}

		for (int i = 0; i < M; ++i) {
			cin >> b[i];
		}

		for (int i = 0; i < A; ++i) {
			BC bc;
			cin >> bc.y >> bc.x >> bc.c >> bc.p;
			battery[i] = bc; 
		}

		int ax = 1, ay = 1, ac = 0;
		int bx = 10, by = 10, bc = 0;

		for (int i = 0; i <= M; ++i) {
			vector<int> fa;
			vector<int> fb;
			
			for (int j = 0; j < A; ++j) {
				if (abs(ax-battery[j].x) + abs(ay-battery[j].y) <= battery[j].c) {
					fa.push_back(j);
				}

				if (abs(bx-battery[j].x) + abs(by-battery[j].y) <= battery[j].c) {
					fb.push_back(j);
				}
			}

			int max_a = 0;
			int max_b = 0;

			if (fa.size() >= 1 && fb.size() == 0) {
				for (int j = 0; j < fa.size(); ++j) {
					if (max_a < battery[fa[j]].p) {
						max_a = battery[fa[j]].p;
					}
				}
			} else if (fb.size() >= 1 && fa.size() == 0) {
				for (int j = 0; j < fb.size(); ++j) {
					if (max_b < battery[fb[j]].p) {
						max_b = battery[fb[j]].p;
					}
				}
			} else {
				int total = 0;
				for (int j = 0; j < fa.size(); ++j) {
					for (int k = 0; k < fb.size(); ++k) {
						int tmp_a = battery[fa[j]].p;
						int tmp_b = battery[fb[k]].p;

						if (fa[j] == fb[k]) {
							tmp_a /= 2;
							tmp_b /= 2;
						} 

						if (total < tmp_a+tmp_b) {
							max_a = tmp_a;
							max_b = tmp_b;
							total = tmp_a+tmp_b;
						}

					}
				}
			}

			ac += max_a;
			bc += max_b;

			ax += dx[a[i]];
			ay += dy[a[i]];

			bx += dx[b[i]];
			by += dy[b[i]];

		}

		cout << "#" << test_case << " " << ac + bc << endl;
	}

	return 0;
}