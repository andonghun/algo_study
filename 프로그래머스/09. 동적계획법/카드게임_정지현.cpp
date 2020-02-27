#include <string>
#include <vector>

using namespace std;

int dp[2000][2000];
vector<int> left_card;
vector<int> right_card;
int n;

int score(int i, int j) {
	if (i == n || j == n) return 0;

	if (dp[i][j] != 0) return dp[i][j];
	
	if (left_card[i] > right_card[j]) {
		int res = score(i, j+1) + right_card[j];
		dp[i][j] = res;
		return res;
	} else {
		int res = max(score(i+1,j+1), score(i+1,j));
		dp[i][j] = res;
		return res;
	}

}
int solution(vector<int> left, vector<int> right) {
    left_card = left;
    right_card = right;
    n = left.size();

    int answer = score(0,0);

    return answer;
}