//dfs로 풀이 참고

#include<bits/stdc++.h>

using namespace std;
int N, L, max_score;
int ing[21][2];

int dfs(int idx, int sum_cal, int score){
	if(sum_cal > L) return 0;
    max_score = max(max_score, score);
    
    for(int i=idx+1; i<=N; i++){
    	dfs(i, sum_cal + ing[idx][1], score + ing[idx][0]);
    }
}

int main(void)
{
	int test_case;
	int T;
  
    setbuf(stdout, NULL);
	scanf("%d", &T);

    for (test_case = 1; test_case <= T; ++test_case)
	{
		max_score = 0;
        cin >> N >> L;
        for(int i=0; i<N; i++){
        	cin >> ing[i][0] >> ing[i][1]; // 맛 만족도와 칼로리 저장
        }
        
        for(int i=0; i<N; i++){
        	dfs(i, 0, 0);
        }
        
        cout << "#" << test_case << " " << max_score  << "\n";
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}


/* 20개 중에 14개로 실패

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	if((float)(a.first)/(a.second) == (float)(b.first)/(b.second)){
		return a.second > b.second; 
	}
	
	else
		return (float)(a.first)/(a.second) > (float)(b.first)/(b.second);
}
//칼로리 대비 만족도가 높은 음식 순으로 정렬, 동일한 경우, 칼로리가 많은 순서로 정렬.


int main(int argc, char** argv)
{
	int test_case;
	int T, N, L;
    int score, cal;

    vector<pair<int, int>> v; // pair의 first: 재료 만족 점수 second: 칼로리 
	cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
	{
        int best = 0;
        int now_cal = 0;

        cin >> N >> L; // N개의 재료 , 총 L칼로리
		for(int i=0; i<N; i++){
            cin >> score >> cal;
        	v.push_back(make_pair(score, cal));
        }
	
        sort(v.begin(), v.end(), compare);
        
        for(int i=0; i<N; i++){
        	if(now_cal+v[i].second < L){
            	best += v[i].first;
				      now_cal += v[i].second;                
            }        
        }
		cout << "#" << test_case << " " << best << '\n';        
        v.clear();
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
*/
