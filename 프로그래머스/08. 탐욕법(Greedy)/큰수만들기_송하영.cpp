#include <iostream>
using namespace std;

string solution(string number, int k) {
    int need = number.length()-k,start = 0, len = number.length();
    char max_num;
    string answer = "";
    while(need){
        max_num = number[start];
        for(int i=start+1;i<=len-need;i++){
            if(max_num<number[i]){
                max_num = number[i];
                start = i;
            }
        }
        answer += max_num;
        --need;
        ++start;
    }
    return answer;
}
