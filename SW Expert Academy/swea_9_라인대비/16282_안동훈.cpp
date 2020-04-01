//고리 1개 2 1 4 
//고리 2개 3 1 6 1 12 
//고리 3개 4 1 8 1 16 1 32 
//고리 4개 5 1 10 1 20 1 40 1 80 
//고리 cnt개 (cnt+1)*num1 1 (cnt+2)*num2... num은 cnt+1개까지
#include<bits/stdc++.h>

using namespace std;

long long N, cnt;
long long max_num = 0;
long long temp = 1;

int cal(int num) {

	for (int i = 0; i < num + 1; i++) {
		max_num += (num + 1) * temp;
		temp *= 2;
	}

	return max_num + num;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cnt = 1;

	cin >> N;
	while (1) {
		if (N <= cal(cnt)) break;
		cnt++;
	}

	cout << cnt;

	return 0;
}
