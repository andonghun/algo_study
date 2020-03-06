#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// N = 재료의 수, L = 제한 칼로리, max_socre = 최대 점수
int N, L, max_score;
vector<vector<int> > ingredient(21, vector<int>(21, 0));


int dfs(int idx, int kcal, int score) {
	if (kcal > L) return 0;

	max_score = max(max_score, score);

	for (int i = idx + 1; i <= N; i++){
		dfs(i, kcal + ingredient[idx][1], score + ingredient[idx][0]);

    }
}

int main(int argc, char** arg) {
	int T;
	
	// input.txt 로 input 받기
	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int test_case = 1; test_case <= T; T++) {
		max_score = 0;
		scanf("%d %d", &N, &L);
		
		// 0 = 점수, 1 = 칼로리
		for (int j = 0; j < N; j++)
			scanf("%d %d", &ingredient[j][0], &ingredient[j][1]);

		for (int j = 0; j < N; j++)
			dfs(j, 0, 0);
		
		printf("#%d %d\n", test_case, max_score);
	}

	return 0;
}
