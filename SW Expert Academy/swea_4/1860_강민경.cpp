// 
#include<iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int n, m, k, data;
vector<int> customer;

int main(int argc, char** argv)
{
//	ios::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);

	int test_case;
	int T;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case) {

        customer.clear();
        string result = "Possible";

		int stock = 0;
		int idx = 0;
		scanf("%d %d %d", &n, &m, &k);

		for (int i = 0; i < n; i++) {
			scanf("%d", &data);
			customer.push_back(data);
		}

		sort(customer.begin(), customer.end());
		int time = 0; // 시간

		while (idx < n) {
			if (time != 0 && time % m == 0) {
				stock += k; // 정해진 시간에 재고수량을 k만큼 더해줌
			}
			if(idx == n) break;
            
            if(time == customer[idx]){
                stock -= 1;
                
                if(stock <0){
                	result = "Impossible";
                    break;
                }else{
                	idx++;
                }
            }
            time++;
		}
        
       	printf("# %d %s\n", test_case, result.c_str());
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
