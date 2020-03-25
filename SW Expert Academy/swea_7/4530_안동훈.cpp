#include<bits/stdc++.h>
using namespace std;
int NP_A = -1; // 음수면 -1 양수면 1
int NP_B = -1;
long long NA, NB;
void cal(long long A, long long B) {
	NA = 0;
	NB = 0;
	long long temp = 1;
	int r;
	A = abs(A);
	B = abs(B);
	while(A>0) {
		r = A%10;
		if(r>=4) r--;
		NA += r*temp;
		temp *= 9;
		A /= 10;
	}
	temp = 1;
	while(B>0) {
		r = B%10;
		if(r>=4) r--;
		NB += r*temp;
		temp *= 9;
		B /= 10;
	}
	return;
}
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case, T;
	long long A, B;
	cin>>T;
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> A >> B;
		NP_A = 1;
		// 음수면 -1 양수면 1
		NP_B = 1;
		if(A<0) NP_A = -1;
		if(B<0) NP_B = -1;
		cal(A,B);
		if(NP_A*NP_B == -1)
			        cout << "#" << test_case << " " << NB+NA-1 << '\n'; else
		            cout << "#" << test_case << " " << abs(NB-NA)<< '\n';
	}
	return 0;
}
