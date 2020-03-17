// 7466. 팩토리얼과 최대공약수
#include<iostream>
#include <vector>
#include <queue>

using namespace std;

long long gcd(long long n, long long k) {

	queue<long long> qu;
	long long answer = 1;
	long long count = 1;
	qu.push(1);

	/*
	if (n >= 2) {
		for (long long i = 2; i <= n; i++) {
			qu.push(i);
		}
	}
	*/

	if (n == k) return n; // pass!!!!!!!!!!!!

	while (!qu.empty()) {

		// k가 qu의 값보다 작으면 이미 나눌수 있는 수는 다 나누었기 때문
		// 15!			81 
		// 1......9까지 pop() , vector -> 3, 9가 들어가있음 
		// 10(front)	3
		if (qu.front() > k || count > n) break;

		if (k % qu.front() == 0) { // k를 나눌수 있으면 
			answer *= qu.front();
			k = k / qu.front();
			qu.push(++count);
			qu.pop();
		}
		else {
			qu.push(++count);
			qu.pop();
		}
	}

	return answer;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int test_case;
	int T;


	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		long long N, K;
		cin >> N >> K;

		long long ans = gcd(N, K);

		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
