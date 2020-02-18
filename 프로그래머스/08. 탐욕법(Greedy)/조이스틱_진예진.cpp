#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string name) {
    int answer = 0;
    int updown = 0;
    int leftright = 0;
    int temp = 0;
    int num_of_a = 0;
    int num_changed = 0;
    int len = name.length();
    int ridx, lidx;
    vector<bool> change_check(len, false);
    
    
    for(int cur_char = 0; cur_char < len; cur_char++){
        temp = (int)name[cur_char] - 'A';
        temp = temp > 13 ? -(temp - 26) : temp;
        // 나중을 위해 A 개수 세어놓기
        if(temp == 0) num_of_a++;
        updown += temp;
    }
    printf("updown: %d\n", updown);
    
    for(int pivot = 0; pivot < len; pivot++){
        for(int offset = 0; offset < len; offset++){
            // A만 남은 경우에 종료
            if(num_of_a == (name.length() - num_changed)){
                printf("%d %d", num_of_a, num_changed);
                return updown + leftright;
            }
            
            //오른쪽 방향 인덱스
            ridx = (pivot + offset) % len;
            
            // 왼쪽방향 탐색을 위한 인덱스계산
            lidx = pivot - offset;
            lidx = lidx < 0 ? len - abs(lidx) : lidx;
            
            
            if(change_check[ridx] == false && name[ridx] != 'A'){
                change_check[ridx] = true;
                num_changed++;
                leftright += offset;
                printf("1 char:%c pivot: %d offset: %d\n", name[ridx], pivot, offset);
                pivot = ridx - 1;
                break;
            }
            
            else if(change_check[lidx] == false && name[lidx] != 'A'){
                change_check[lidx] = true;
                num_changed++;
                leftright += offset;
                printf("2 char:%c pivot: %d offset: %d idx: %d\n",name[lidx], pivot, offset, lidx);
                pivot = lidx - 1;
                break;
            }
        }
    }
    answer = updown + leftright;
    return answer;
}