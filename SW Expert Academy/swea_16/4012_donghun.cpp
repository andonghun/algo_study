#include<bits/stdc++.h>

using namespace std;

int result;
int N;
vector<int> choice;
int S[17][17];

void init() {
	memset(S, 0, sizeof(S));
	choice.clear();
	result = 987654321;
	N = 0;
}

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		choice.push_back(i);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S[i][j];
		}
	}
	
}

int solve() {
	vector<int> ind;

	for (int i = 0; i < N / 2; i++) {
		ind.push_back(0);
		ind.push_back(1);
	}

	sort(ind.begin(), ind.end());

	do {
		vector<int> A, B;
		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {
				A.push_back(choice[i]);
			}
			else if (ind[i] == 0) {
				B.push_back(choice[i]);
			}
		}
		// N개 중에 N/2개 선택 완료
		int sum_a = 0;
		int sum_b = 0;
		int dif;

		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A.size(); j++) {
				if (i == j) continue;
				else {
					sum_a += S[A[i]][A[j]];
					sum_b += S[B[i]][B[j]];
				}
			}
		}

		dif = abs(sum_a - sum_b);
		result = min(result, dif);

		A.clear();
		B.clear();
	} while (next_permutation(ind.begin(), ind.end()));

	return result;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		init();
		input();
		cout << "#" << test_case << " " << solve() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
