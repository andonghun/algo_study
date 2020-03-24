// 1231. [S/W 문제해결 기본] 9일차 - 중위순회
#include<iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> inorder;
int n;


typedef struct Tree {
	char ch ;
	int left = -1;
	int right = -1;
}Tree;

Tree *trees;

void printTree(int idx) {

	if (idx > n ) return;
	printTree(idx * 2);
	cout << trees[idx].ch;
	printTree(idx * 2 +1);
}

int main(int argc, char** argv)
{
	int test_case;
		
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> n;
		trees = (Tree*)malloc(sizeof(Tree)*101); // 구조체배열 사용법, 101대신 n을쓰면 런타임에러

		int tempchar, tempint;

		for (int i = 1; i <= n; i++) {
			cin >> tempint;
			cin >> trees[i].ch;

			if (n % 2 == 0 && n / 2 > i || n % 2 == 1 && n / 2 >= i) {//자식 2개
				cin >> trees[i].left ;
				cin >> trees[i].right;

			}
			else if (n % 2 == 0 && n / 2 == i) {//자식 1개
				cin >> trees[i].left;
			}
		
		}

		cout << "#" << test_case  << " ";
		printTree(1);
		cout << "\n";

		free(trees);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
