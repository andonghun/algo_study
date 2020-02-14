#include <vector>
using namespace std;
int solution(vector<int> priorities, int location) {
    int p[100], INFO[10] = {0,};
    int index = 0, _P = 0, answer = 1, L = location;
    int P = priorities[location], SIZE = priorities.size();
    for(int i=0;i<SIZE;i++) {
        if (priorities[i] >= P) {
            ++INFO[priorities[i]];
            p[index++] = priorities[i];
            _P = priorities[i] > _P ? priorities[i] : _P;
        } else if (i < location)
            --L;
    }
    SIZE = index;
    index = 0;
    while(_P!=P){
        index = index - 1 == -1 ? SIZE-1 : index -1;
        if(p[index]==_P){
            answer += INFO[_P];
            do{
                --_P;
            }while(INFO[_P]==0);
        }
    }
    while(index!=L){
        if(p[index]==P)
            ++answer;
        index = (index+1)%SIZE;
    }
    return answer;
}
/* //재귀
#include <vector>
using namespace std;
int answer = 1;
int INFO[10];
int SIZE, P, L;
void DFS(vector<int> &priorities, int _P,int start){
    if(_P==P){
        while(start!=L){
            if(priorities[start]==P)
                ++answer;
            start = (start+1)%SIZE;
        }
        return ;
    }
    if(INFO[_P]==0){
        DFS(priorities,_P-1,start);
        return ;
    }
    answer += INFO[_P];
    for(int i=0;i<SIZE;i++){
        start = start - 1 == -1 ? SIZE-1 : start -1;
        if(priorities[start]==_P) {
            DFS(priorities,_P-1,start);
            break;
        }
    }
}

int solution(vector<int> priorities, int location) {
    SIZE = priorities.size();
    P = priorities[location];
    L = location;
    vector<int> p(100);
    int index = 0;
    for(int i=0;i<SIZE;i++)
        if(priorities[i]>=P) {
            ++INFO[priorities[i]];
            p[index++] = priorities[i];
        }
        else if(i<location)
            --L;
    SIZE = p.size();
    DFS(p,9,0);
    return answer;
}
*/
