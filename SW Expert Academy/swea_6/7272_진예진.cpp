#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

// int table[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0,
//                  0, 0, 0, 0, 1, 1, 1, 1, 0, 0,
//                  0, 0, 0, 0, 0, 0,};

int table[26]={0,};

int main(int argc, char** argv){
    // cin.tie(NULL);
    // ios::sync_with_stdio(false);

    int testcase, T;
    int length;
    int i;
    FILE* stream;

    table['B'-'A']=2;
    table['A'-'A']=1;
    table['D'-'A']=1;
    table['O'-'A']=1;
    table['P'-'A']=1;
    table['Q'-'A']=1;
    table['R'-'A']=1;


    stream = freopen("SWEA\\6\\7272_input.txt", "r", stdin);

    if(!stream)
        printf("fopen");

    scanf("%d", &T);

    for(testcase = 1; testcase <= T; testcase++){
        string first, second;

        cin >> first;
        cin >> second;

        // cout << first << " " << second << "\n";

        length = first.size();

        if(length != second.size()){
            printf("#%d DIFF\n", testcase);
            break;
        }
        else{
            for(i = 0; i < length; i++){
                if(table[first[i]-65] != table[second[i]-65]){
                printf("#%d DIFF\n", testcase, i);
                break;
                }
            }
            if(i == length) printf("#%d SAME\n", testcase);
        }

    }
    return 0;
}
