#include<iostream>

using namespace std;

int main(int argc, char** argv) {
	int T;
	cin>>T;

	for(int tc = 1; tc <= T; ++tc) {
		string s;
		cin >> s;

		int answer = 0;
		int people = s[0] - '0';
		for (int i = 1; i < s.length(); ++i) {
			if (s[i] == '0') continue;

			int p = s[i] - '0';
			if (people < i) {
				answer += i - people;
				people += i - people + p;
			} else {
				people += p;
			}				
		}
		cout << "#" << tc << " " << answer << "\n";
	}
	return 0;
}