// 1249. [S/W 문제해결 응용] 4일차 - 보급로
// 제한시간초과

#include<iostream>
#include<string.h>
#include <stdio.h>
using namespace std;

int arr[101][101]; 
int countmap[101][101];

int t, n;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void map(int x, int y, int sum) {
	    
    countmap[x][y] = sum;
    
	for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
		if(next_x >=0 && next_x <n && next_y >=0 && next_y < n){
            int tempcount = arr[next_x][next_y] + sum;
            
            if(countmap[next_x][next_y] > tempcount || countmap[next_x][next_y] == -1){
                map(next_x, next_y, tempcount);
            }
        }
	}
	return;
}

int main(int argc, char** argv)
{
	int test_case;
	scanf(&quot;%d&quot;, &t);
	
	for (test_case = 1; test_case <= t; ++test_case)
	{
		scanf(&quot;%d&quot;, &n);
		memset(arr, 0, sizeof(arr));
		memset(countmap, -1, sizeof(countmap));

		// 입력
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf(&quot;%1d&quot;, &arr[i][j]);
			}
		}
		map(0,0,0);
		printf(&quot;%d %d\n&quot;, t, countmap[n - 1][n - 1]);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
    //	char ch = getchar();
	//	int a = ch - &apos;0&apos;;
