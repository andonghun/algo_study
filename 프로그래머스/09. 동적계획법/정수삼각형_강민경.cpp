#include <string>
#include <vector>
#include <algorithm>

// 참고 
// https://dvpzeekke.tistory.com/m/26

using namespace std;

 

int solution(vector<vector<int>> triangle) {

    int answer = 0;

    vector<vector<int>> v(triangle.size(), vector<int> (triangle.size()));


    v[0][0] = triangle[0][0];


    for (int i = 1; i < triangle.size(); i++) {

        for (int j = 0; j <= i; j++) {

            if (j == 0) {

                v[i][j] = v[i - 1][j] + triangle[i][j];

            }

            else if (j == i) {

                v[i][j] = v[i - 1][j - 1] + triangle[i][j];

            }

            else {

                v[i][j] = max(v[i-1][j] + triangle[i][j], v[i-1][j-1] + triangle[i][j]);

            }

            

            if (i == triangle.size() - 1) {

                answer = max(answer, v[i][j]);

            }

        }

    }

    

    return answer;

}


