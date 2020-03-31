#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(const int a, const int b){
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    int cursor = people.size()-1;
    sort(people.begin(), people.end(), cmp);
    
    /*
    for(auto i : people){
        printf("%d ", i);
    }
    */
    
    for(int i = 0; i <= cursor; i++){
        if(i == cursor){
            answer++;
            break;
        }
        if(people[i] + people[cursor] <= limit){
            answer++;
            cursor--;
        }
        else{
            //printf("%d %d\n", i, cursor);
            //printf("%d %d\n", people[i], people[cursor]);
            answer++;
        }
    }
    return answer;
}