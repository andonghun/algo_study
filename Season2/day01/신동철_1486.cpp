//시뮬레이션문제로 판단 
//조합이용해서 완전탐색으로 해결.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int T, N, B;
vector<int> vec;//점원키모음
vector<int> vecbuf;//점원키조합위한 벡터
queue<int> qu;//테스트케이스별 정답
void In() {
	int a;
	cin >> N >> B;
	for (int tp = 0; tp < N; tp++) {
		cin >> a;
		vec.push_back(a);
	}
}
int combination(vector<int> *vect) {
	int len = (*vect).size();
	int min = 2147483647;
	int sum = 0;
	//점원이 한명인경우
	if (  len == 1)
		return (*vect)[0] - B; //점원키의 합은 B보다 크거가 같으므로 이렇게 쓸수 있음.
	
	//점원이 두명 이상인 경우
	for (int tp1 = 1; tp1 <= len; tp1++){ //조합. vect에서 tp1개를 고를 경우 
		for (int tp3 = 1; tp3 <= (len - tp1); tp3++)
			vecbuf.push_back(0);
		for(int tp2=1 ; tp2<=tp1 ; tp2++)
			vecbuf.push_back(1);

		do {
			for(int tp2=0; tp2<len ; tp2++){
				if (sum >= B)//중간탈출문
					break;
				if (vecbuf[tp2] == 1)
					sum+=(*vect)[tp2];
			}
			if ( (sum >= B) && (min > sum - B) )
				min = sum - B;
			sum = 0;//초기화
		} while (next_permutation(vecbuf.begin(),vecbuf.end()));
		vecbuf.clear();//초기화
	}
	return min;
}
int main()
{
	cin >> T;
	for (int tp1 = 0; tp1 < T; tp1++) { //테스트 케이스만큼 수행
		In();
		sort(vec.begin(), vec.end(), less<int>());
		qu.push(combination(&vec));//조합에서 얻은 최솟값을 큐에 저장
		
		vec.clear();//초기화
	}
	int num = 1;
	
	//정답출력
	while (!qu.empty())
	{
		cout << '#' << num << ' ' << qu.front()<<'\n';
		qu.pop();
		num++;
	}
}