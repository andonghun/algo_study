#include<bits/stdc++.h>

using namespace std;

int N;
int a;
char b;
char node[222];
void inorder(int start){
if(node[start] == 0) return;
    
    inorder(start*2);
    cout << node[start];
    inorder(start*2+1);
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(node, 0, sizeof(node));
        int temp1, temp2, temp3;
		cin >> N;
        
        for(int i=1; i<=N; i++){
            cin >> a >> b;
        	//자식 노드가 두개 일 때
            if((N%2 == 0 && (i<N/2)) || (N%2 == 1 && i <= (N-1)/2)){
            	node[i] = b;
                cin >> temp1 >> temp2;
            }
            //자식 노드가 하나일 때 - N이 홀수이면 자식 노드가 하나인 경우는 없음
            else if(N%2 == 0 && i == N/2){
            	node[i] = b;
                cin >> temp3; // 모든 정점의 위치가 트리구조로 되어있으므로 불필요한 입력
            }
            //자식 노드가 없을 때
            else node[i] = b;
        }
        
        cout << "#" << test_case << " ";
        inorder(1);
        cout << '\n';
	}
	return 0;
}