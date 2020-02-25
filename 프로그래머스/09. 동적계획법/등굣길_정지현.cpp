#include <string>
#include <vector>
#include <iostream>

using namespace std;

int path[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {    
    for (int i = 0; i < puddles.size(); i++) {
    	path[puddles[i][1]][puddles[i][0]] = -1;
    }

    path[0][1] = 1;

    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		if (path[i][j] == -1) {
                path[i][j] = 0;
            }
    		else {
                path[i][j] = (path[i-1][j] + path[i][j-1]) % 1000000007;
            }
    	}
    }

    return path[n][m];
}