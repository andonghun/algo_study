#include<iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	for(int tc = 1; tc <= T; ++tc) {
		long long n;
		cin >> n;
		long long l,r;
        
		r = 2*(n*n) - 1;
		l = 2*(n-1)*(n-1) + 1;

		cout << "#" << tc << " " << l << " " << r << "\n";
	}

	return 0;
}