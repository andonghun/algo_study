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
        	//�ڽ� ��尡 �ΰ� �� ��
            if((N%2 == 0 && (i<N/2)) || (N%2 == 1 && i <= (N-1)/2)){
            	node[i] = b;
                cin >> temp1 >> temp2;
            }
            //�ڽ� ��尡 �ϳ��� �� - N�� Ȧ���̸� �ڽ� ��尡 �ϳ��� ���� ����
            else if(N%2 == 0 && i == N/2){
            	node[i] = b;
                cin >> temp3; // ��� ������ ��ġ�� Ʈ�������� �Ǿ������Ƿ� ���ʿ��� �Է�
            }
            //�ڽ� ��尡 ���� ��
            else node[i] = b;
        }
        
        cout << "#" << test_case << " ";
        inorder(1);
        cout << '\n';
	}
	return 0;
}