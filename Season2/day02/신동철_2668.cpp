//처음에 DFS완전탐색으로 시도하였는데 답은 맞지만 시간초과가 발생-  최악의 경우 100 C 50 경우가 나와서 시간초과가 발생한것으로 보임
//인터넷에서 사이클이란 힌트를 얻고  규칙을 찾아서 단순 for문을 이용해 성공.  -시뮬레이션문제
//최악의경우  N=100일때,반복횟수  100*100 = 10000   여기서 100은 어떤점이 사이클에 속해 있는지 아닌지 검사할때 최대로 반복되는 횟수
//핵심개념 
//시작점과 끝점이 일치하면 그것은 싸이클만족이므로 그 싸이클 안에 포함된 점들은 전부 출력인자가 된다.
//싸이클안에 있는 점들을 bool map 안에 넣어서 이미 확인된 점들은 계산하지 않는다.

#include <iostream>
#include <vector>
using namespace std;
int N;
int ary[101];//실질적사용 인덱스는 1~100 
bool map[101];//실질적 사용 인덱스는 1~100
void In() {
	cin >> N;
	for (int tp = 1; tp <= N; tp++)
		cin >> ary[tp];
}
void func() {


	int a;
	bool flag = false;
	vector<int> buf;

	for (int tp = 1; tp <= N; tp++) {

		if (map[tp] == false) {//싸이클로 판명 안난 경우만 진행


			if (flag == false)
				a = tp;
			//시작과 끝값이 같을 경우
			if (ary[a] == tp) {
				map[tp] = true;
				if ((int)buf.size() > 0) {
					vector<int>::iterator iter;
					for (iter = buf.begin(); iter != buf.end(); iter++)
						map[*iter] = true;
					buf.clear();//buf벡터 초기화
				}

				flag = false;
			}
			//시작과 끝값이 다를 경우-> 사이클 진행
			else {
				buf.push_back(ary[a]);
				//최대로 허용되는 사이클검사 횟수 N
				if (buf.size() == N) {
					buf.clear();
					flag = false;
					continue;
				}
				a = ary[a];
				flag = true;
				tp--;//tp복귀위한 설정
			}



		}
	}
}
int main() {
	In();
	func();
	//map값 중에서 true인것의 인덱스가  선택된 경우임
	
	//정답출력
	int cnt = 0;
	for (int tp = 1; tp <= N; tp++) {
		if (map[tp] == true)
			cnt++;
	}
	cout << cnt<<'\n';
	for (int tp = 1; tp <= N; tp++) {
		if (map[tp] == true)
			cout << tp << '\n';
	}
}