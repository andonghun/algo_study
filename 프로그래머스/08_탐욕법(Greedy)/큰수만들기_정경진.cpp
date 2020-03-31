// https://chaibin0.tistory.com/entry/%ED%81%B0-%EC%88%98-%EB%A7%8C%EB%93%A4%EA%B8%B0
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
string solution(string number, int k) {
	string answer = "";
	int need = number.length() - k;
	int cmax = 0;
	int ccount = 0;
	int j;
	vector<int> temp;
	for (int i = need; i>0; i--) {
		cmax = 0;
		ccount = 0;
		for (j = 0; j<number.length() - i+1; j++) {
			if (cmax<number[j]) {
				cmax = number[j];
				ccount = j;
			}
		}
		number.replace(0,ccount+1," ");
		
		temp.push_back(cmax);
	}
	for (int i = 0; i<temp.size(); i++)
		answer += temp[i];
	return answer;
}
*/

string solution(string number, int k) {
    string answer = "";
    int size = number.size();
    
    // 최종 answer에 들어가는 숫자의 개수 : number.size() - k
    // 현재 max 후보에서 제외되는 숫자의 개수 : size - k - 1 - i
    // 현재 max 후보가 되는 숫자의 개수 : number.size() - (size - k - 1 - i)
    for (int i = 0; i < size - k; i++) {
        string max = "0";
        int max_index = 0;
        
        // answer에 들어갈 후보 중에서 max 선택하기
        for (int j = 0; j < number.size()-size+k+i+1; j++) {
            if (max < number.substr(j, 1)) {
                max = number.substr(j, 1);
                max_index = j;
            }
        }
        
        // answer에 max 덧붙이기
        answer += max;
        // number 조정하기
        number = number.substr(max_index + 1);
    }
    
    return answer;
}
