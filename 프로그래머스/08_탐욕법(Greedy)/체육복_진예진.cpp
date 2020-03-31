#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int cur;
    vector<bool> new_reserve(n, false);
    vector<int> new_lost;
    
    
    for(int i = 0; i < reserve.size(); i++){
        new_reserve[reserve[i]-1] = true;
    }
    
    //printf("\n");
    
    // 자기도 잃어버려서 못 빌려주는 경우 빼고 새로 만듬
    for(int i = 0; i < lost.size(); i++){
    	cur = lost[i]-1;
        if (new_reserve[cur] == true){
            new_reserve[cur] = false;
            //printf("제외되는 값: %d\n", cur+1);
        }
        else{
            new_lost.push_back(cur+1);
        }
    }

    for(int i = new_lost.size()-1; i >= 0; i--){
        cur = new_lost[i] -1;
        //오른쪽
        if (cur + 1 < new_reserve.size() && new_reserve[cur+1] == true){
            new_reserve[cur+1] = false;
            new_lost.pop_back();
        }
        //왼쪽
        else if(cur - 1 >= 0 && new_reserve[cur-1] == true){
            new_reserve[cur-1] = false;
            new_lost.pop_back();
        }
    }
    
    /*
    for(auto i:new_lost){
        printf("%d ", i);
    }
    */
    
    answer = n - new_lost.size();
    return answer;
}