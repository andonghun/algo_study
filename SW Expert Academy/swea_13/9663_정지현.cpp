#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[15];
int answer;
bool backtracking(int col) {
	for (int i = 0; i < col; i++) {
		if (arr[i] == arr[col] || col-i == abs(arr[col]-arr[i])) {
			return false;
		}
	}
	return true;
}
void nqueen(int col) {
	if (col == n) answer += 1;
	else {
		for (int i = 0; i < n; i++) {
			arr[col] = i;
			if (backtracking(col)) nqueen(col+1);
		}
	}
}
int main() {
	cin >> n;
	answer = 0;

	nqueen(0);

	cout << answer;

	return 0;
}