#include <iostream>
#include <algorithm>

using namespace std;
int price[100001];

int cmp(const int a, const int b){
	return a > b;
}

int main()
{
	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++){
		int n = 0;
		cin >> n;

		for (int j = 1; j <= n; j++){
			cin >> price[j];
		}

		int sum = 0;
		sort(price + 1, price + n+1, cmp);

		for (int k = 1; k <= n; k++){
			if (k % 3 != 0){
				sum += price[k];
			}
		}

		printf("#%d %d\n", i + 1, sum);
	}
	return 0;
}
