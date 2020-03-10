// SWEA 8771. 덧셈문제

#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	int T;
    cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		long long n, a, b;
		cin >> n >> a >> b;

		long long res = (b - a) * (n - 2) + 1;

		if (a > b || (a != b && n == 1))
			res = 0;
		cout << "#" << test_case << " " << res << "\n";
		// endl으로 하면 시간초과
	}
	return 0;
}							
