#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    //문자열로 받아오면 편할 것 같아서 int to string을 사용하자
    //123~987까지 비교
    string number = "";
    string input_num = "";
    int strike = 0;
    int ball = 0;
    int count = 0;
    
    for(int i=123; i<=987; i++){
        number = to_string(i);
        if (number[0] == number[1] || number[0] == number[2] || number[1] == number[2]) 
            continue; // 숫자 둘 중 하나라도 같은 경우 제하기
        else if (number[0] == '0' || number[1] == '0' || number[2] == '0')
            continue; // 숫자에 0이 들어가는 경우 제하기
        count = 0;
        
        for (int j=0; j<baseball.size(); j++){
            strike = 0;
            ball = 0;

            for (int k1=0; k1<3; k1++){
                for (int k2=0; k2<3; k2++){
                    input_num = to_string(baseball[j][0]);
                    //strike의 경우 k1과 k2가 같음 -> 같은 자리수
                    if (k1 == k2 & number[k1]==input_num[k2]){
                        strike++;
                        continue;
                    }
                    //ball의 경우 자릿수(k1/k2)가 다르고, 같은 수일때
                    if (k1 != k2 & number[k1]==input_num[k2]){
                        ball++;
                        continue;
                    }
                }
            }
            
            if (strike != baseball[j][1] || ball != baseball[j][2]){
                count = 2;
                break;
            }
            
        }
        if (count == 0){
                answer++;
            }
    }
    
    return answer;
}