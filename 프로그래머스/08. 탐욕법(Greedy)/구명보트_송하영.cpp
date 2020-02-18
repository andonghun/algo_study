#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    register int answer = 1;
    sort(people.begin(),people.end());
    register vector<int>::iterator back_it = people.end()-1, front_it = people.begin();
    while(front_it!=back_it){
        if(*back_it-- + *front_it<=limit){
            if(back_it==front_it)
                return answer;
            ++front_it;
        }
        ++answer;
    }
    return answer;
}
