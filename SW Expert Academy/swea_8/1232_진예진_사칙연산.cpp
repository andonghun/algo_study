#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>

using namespace std;

struct Tree{
    /* data */
    int left;
    int right;
    float value;
    char oper;
};
struct Tree tree[1001];

float cal(float a, float b, char oper){
    switch(oper){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return 0;
}

void search(int idx){
    int left_idx = tree[idx].left;
    int right_idx = tree[idx].right;
    
    if(tree[left_idx].oper != -1){
        search(left_idx);
    }
    if(tree[right_idx].oper != -1){
        search(right_idx);
    }
    if(tree[idx].oper != -1){
        tree[idx].value = cal(tree[left_idx].value, tree[right_idx].value, tree[idx].oper);
    }
}

int main(void){
    bool is_number = true;
    int num_node, index, testcase = 1;
    int temp;
    char number[10];
    char operators[4] = {'+', '-', '*', '/'};
    
    FILE *stream;

    stream = freopen("SWEA\\8\\1232_input.txt", "r", stdin);

    if(!stream)
        printf("freopen\n");
    else
        printf("file open~~~~\n");

    while (scanf("%d", &num_node) != EOF){
        for(int i = 0; i < num_node; i++){
            tree[i].oper = -1;
            tree[i].left = -1;
            tree[i].right = -1;
            tree[i].value = -1;
        }
        for(int nodecase = 1; nodecase <= num_node; nodecase++){
            is_number = true;
            scanf("%d", &index);
            // 공백 뛰어넘기

            temp = getchar();
            if(temp = ' ') temp = getchar();
            
            for(int i = 0; i < 4; i++){
                //연산자인 경우
                if(temp == operators[i]){
                    scanf("%d %d", &tree[index].left, &tree[index].right);
                    tree[index].oper = temp;
                    is_number = false;
                    break;
                }
            }
            // 그냥 숫자일 때
            if(is_number == true){
                int j = 0;
                memset(number, 0, sizeof(number));
                while(temp != '\n'){
                    number[j] = temp;
                    temp = getchar();
                    j++;
                }
                tree[index].oper = -1;
                tree[index].value = atoi(number);
            }
        }

        // for(int i = 1; i <= num_node; i++){
        //     if(tree[i].oper != -1){
        //         printf("%c %d %d\n", tree[i].oper, tree[i].left, tree[i].right);
        //     }
        //     else{
        //         printf("%f\n", tree[i].value);
        //     }
        // }

        search(1);

        printf("#%d %.0f\n", testcase, tree[1].value);
        testcase++;
    }
    return 0;
}
