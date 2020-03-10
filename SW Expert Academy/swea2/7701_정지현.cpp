#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	} 

	return a.length() < b.length();
	
}
int main(void) {
	// 속도 개선
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int test_case;
	int T;
	
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case) {
		int n;
		vector<string> v;

		cin >> n;

		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			v.push_back(s);
		}

		// 길이, 알파벳 순으로 정렬
		sort(v.begin(), v.end(), cmp);

		cout << '#' << test_case << '\n';
		cout << v[0] << '\n';


		for (int i = 1; i < v.size(); i++) {
			if (v[i] == v[i-1]) continue;
			cout << v[i] << '\n';
		}

	}
	return 0;
}