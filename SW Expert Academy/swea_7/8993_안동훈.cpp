#include<bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	long long T, N;
	cin>>T;
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> N;
		bool check	= true;
		while(N>1) {
			if(N%2 == 0) N = N/2; else {
				check = false;
				break;
			}
		}
		if(check) cout << "#" << test_case << " " << "YES" << '\n'; else cout << "#" << test_case << " " << "NO" << '\n';
	}
	return 0;
}

/* 25개만 패스함
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	int T, N;
	cin>>T;
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> N;
		bool flag = true;
		set<int> s;
		while(1) {
			if(N == 1) break;
			s.insert(N);
			N%2 == 0 ? N = N/2 : N = 3*N + 3;
			if(s.count(N) == 1) {
				flag = false;
				break;
			}
		}
		if(flag == true) cout << "#" << test_case << " " << "YES" << '\n'; else cout << "#" << test_case << " " << "NO" << '\n';
	}
	return 0;
}

*/
