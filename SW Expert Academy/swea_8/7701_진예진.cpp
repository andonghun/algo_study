#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

bool cmp(char *a, char *b){
    if(strlen(a) != strlen(b)){
        return strlen(a) < strlen(b);
    }
    else{
        // 두 문자열이 같으면 0, a가 크면 1, b가 크면 -1, 리눅스는 아스키 차이값 리턴
        int ret = strcmp(a, b);
        if(ret > 0) return false;
        else if(ret < 0) return true;
    }
    return true;
}

int main(void){
    int testcase, T, str_len;
    char *str = (char*)malloc(50), *temp;
    vector<char*> str_vec(20000);
    FILE *stream;

    stream = freopen("SWEA\\8\\7701_input.txt", "r", stdin);

    if(!stream)
        printf("freopen");
    else
        printf("file open\n");
    
    scanf("%d", &T);
    
    for(int testcase = 1; testcase <= T; testcase++){
        str_vec.clear();
        scanf("%d", &str_len);
        for(int i = 0;i < str_len; i++){
            scanf("%s", str);
            temp = (char*)malloc(strlen(str));
            strcpy(temp, str);
            str_vec.push_back(temp);
        }

        sort(str_vec.begin(), str_vec.end(), cmp);
        // unique: 중복인 요소를 맨 뒤로 보내고, 마지막 원소의 iterator를 반환
        // 포인터 값이라 erase가 적용되지 않는 듯함
        // str_vec.erase(unique(str_vec.begin(), str_vec.end()), str_vec.end());

        
        bool duplicated = false;
        
        printf("#%d\n", testcase);

        for(int i = 0; i < str_vec.size(); i++){
            if(i == str_vec.size() - 1){
                if(duplicated == false) printf("%s\n", str_vec[i]);
                break;
            }
            if(duplicated == false){
                printf("%s\n", str_vec[i]);
                if(strcmp(str_vec[i], str_vec[i+1]) == 0){
                    duplicated = true;
                }
            }
            else{
                if(strcmp(str_vec[i], str_vec[i+1]) != 0){
                    duplicated = false;
                }
            }
        }
    }

    return 0;
}
