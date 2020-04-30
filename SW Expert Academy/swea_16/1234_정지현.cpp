#include<iostream>
#include<vector>

using namespace std;

int main() {
	for(int test_case = 1; test_case <= 10; ++test_case) {
		int n;
		string num;

		cin >> n >> num;

		vector<char> v;

		for (int i = 0; i < n; ++i) {
			if (v.size() > 0 && num[i] == v[v.size()-1]) {
				v.pop_back();
				continue;
			}

			v.push_back(num[i]);
		}

		cout << "#" << test_case << " ";

		for (int i = 0; i < v.size(); ++i) {
			cout << v[i];
		}
		
		cout << "\n";
	}
	return 0;
}