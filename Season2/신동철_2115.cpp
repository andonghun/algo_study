//성공
//시뮬레이션문제로 파악
//조합을 이용한 완전탐색으로 해결.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int T;//테스트케이스의 수
int N, M, C;//벌꿀크기, 벌꿀채취가능갯수 , 꿀을 채취할수있는 최대양
int ary[10][10];//벌꿀배열
int maxv = 0;
queue<int> qu;//테스트케이스별 정답
vector<int> vec;//조합에 이용될 벡터
void In()
{
	cin >> N >> M >> C;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> ary[i][j];
}
int combination(vector<int> *vect)
{
	vector<int>vecbuf;//조합을 위한 보조 벡터
	int len = (*vect).size();
	int max = 0;
	int sum = 0;
	int climit = 0;
	
	for (int tp1 = 1; tp1 <= M; tp1++) { //조합으로, vect에서 tp1개를 선택한 경우의수 반복 
		for (int tp3 = 1; tp3 <= len - tp1; tp3++)
			vecbuf.push_back(0);
		for(int tp2= 1; tp2<=tp1; tp2++)
			vecbuf.push_back(1);
		
		do {
			for (int tp2 = 0; tp2 < len; tp2++) {
				if (vecbuf[tp2] == 1) {
					if (climit + (*vect)[tp2] > C)
						break;
					climit += (*vect)[tp2];
					sum += (*vect)[tp2] * (*vect)[tp2];
				}
			}
			if (max < sum)//max에 sum갱신
				max = sum;
			//초기화
			sum = 0;
			climit = 0;
		} while (next_permutation(vecbuf.begin(),vecbuf.end()));
		vecbuf.clear();//초기화
	}
	return max;
}
int main(int argc, char** argv)
{
	cin >> T;
	int sum1 = 0, sum2 = 0, cnt1 = 0,cnt2 = 0;
	for (int tp = 1; tp <= T; tp++)//테스트case갯수 만큼 수행
	{
		//초기화
		In();
		sum1 = 0;
		sum2 = 0;
		cnt1 = M;
		cnt2 = M;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//첫번째 일꾼)열이 N범위를 초과하면 break;
				if ( (cnt1==M) && ((j + M) > N)) {
					break;
				}
				if (cnt1!=0) {
					vec.push_back(ary[i][j]);
						cnt1--;
				}
				if (cnt1 == 0)
				{
					sort(vec.begin(), vec.end());
					sum1= combination(&vec);//첫번째 일꾼이 선택한 M개 만큼의 꿀에서 나오는 최대치==sum1
					vec.clear();//초기화
					for (int i2 = i; i2 < N; i2++) {//두번째 일꾼이 선택할 수 있는 모든경우 반복.
						int j2 = 0;
						if (i2 == i)// 첫번재 일꾼이 M만큼 선택한 열의 다음열을 두번째 일꾼이 가르키기 위한 조건문
							j2 = j+1;
						for ( ; j2 < N; j2++) {
							//두번째 일꾼)열이 N범위를 초과하면 break;
							if ( (cnt2==M) && ((j2 + M) > N))
								break;
							if (cnt2 != 0) {
								vec.push_back(ary[i2][j2]);
								cnt2--;
							}
							if (cnt2 == 0)
							{
								sort(vec.begin(), vec.end());
								sum2 = combination(&vec);
								if (maxv < (sum1 + sum2)) { //첫번째 두번째 일꾼이 모은 꿀의 최대치 갱신
									maxv = sum1 + sum2;
								}

								//초기화
								vec.clear();
								cnt2 = M;
								sum2 = 0;
								j2 -= (M - 1);
							}

						}
					}
					cnt1 = M;
					sum1 = 0;
					j -= (M - 1);
				}
			}
		}
		qu.push(maxv);
		maxv = 0;
	}

	//정답출력
	int a = 1;
	while (!qu.empty())
	{
		cout <<'#'<<a<<' '<< qu.front();
		cout << '\n';
		qu.pop();
		a++;
	}
	return 0;
}