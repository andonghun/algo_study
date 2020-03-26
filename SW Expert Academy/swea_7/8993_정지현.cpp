#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	for(int tc = 1; tc <= T; ++tc) {
		long long n;
		cin >> n;
		bool flag = true;

		while (n > 1) {
	    	if (n % 2 == 0) n /= 2;
			else { 
				flag = false;
				break;
			}
		}

		if(flag) cout << "#" << tc << " " << "YES" << "\n";
		else cout << "#" << tc << " " << "NO" << "\n";
	}
	return 0;

/* 수정하기 전 
/*
#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	for(int tc = 1; tc <= T; ++tc) {
		long long n;
		cin >> n;
		bool flag = true;

		while (n > 1) {
			if (n % 2 == 0) n /= 2;
	    	else n = 3 * n + 3;

			if (n % 3 == 0) {
				flag = false;
				break;
			} 
		}

		if(flag) cout << "#" << tc << " " << "YES" << "\n";
		else cout << "#" << tc << " " << "NO" << "\n";
	}
	return 0;
}
*/