#include<iostream>
#include <string>
#include <stack>


//		int number = atoi(str.c_str());

//		int one = number % 10;
//		int ten = (number / 10) % 10;
//		int quotier = (number / 10) / 10;

// 천+백, 백+십, 십+일의 자리수 아무거나 더해도 결과는 항상 일치함
		// 1000, 100번째 자리는 0이 나올수도 있으므로 십+일의 자리수로 계산
		// 1234		1234	1234
		// 334		127		154
		// 64		19		19	64
		// 10		10		10	10
		// 1		1		1	1


using namespace std;

char winner;

void go(string str, int cnt) {

//	int number = atoi(str.c_str());
	int size = str.size();
	stack<int> st;

	if (size == 1) {
		winner = 'B';
	}

	for (int i = 0; i < size; i++) {
		st.push(str[i] - '0'); // char를 int로 변환
	}

	while (st.size() != 1) {
		int n1 = st.top();
		st.pop();
		int n2 = st.top();
		st.pop();

		int sum = n1 + n2;

		if (sum >= 10) {
			st.push(sum / 10);
			st.push(sum % 10);
			cnt++;
		}
		else {
			st.push(sum);
			cnt++;
		}
	}
	
	if (cnt % 2 != 0) winner = 'A';
	else winner = 'B';

	return;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string str;
		cin >> str;
		go(str,0);

		cout << "#" << test_case << " " << winner << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


/* 런타임 오류
#include<iostream>
#include <string>
#include <string.h>

using namespace std;

char winner;

void go(string str, int cnt) {

	if (str.size() == 1) {
		if (cnt % 2 != 0)
			winner = 'A';
		else
			winner = 'B';
	}
	else {

		int number = atoi(str.c_str());

		int one = number % 10;
		int ten = (number / 10) % 10;
		int quotier = (number / 10) / 10;

		// 천+백, 백+십, 십+일의 자리수 아무거나 더해도 결과는 항상 일치함
		// 1000, 100번째 자리는 0이 나올수도 있으므로 십+일의 자리수로 계산
		// 1234		1234	1234
		// 334		127		154
		// 64		19		19	64
		// 10		10		10	10
		// 1		1		1	1

		string s = "";
		int tempnum = 0;

		if (quotier == 0) {
			tempnum = ten + one;
			s = to_string(tempnum);
			go(s, cnt + 1);
		}
		else {
			tempnum = ten + one;

			s += to_string(quotier);
			s += to_string(tempnum);
			go(s, cnt + 1);

		}

	}


	return;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string str;
		cin >> str;
		go(str,0);

		cout << "#" << test_case << " " << winner << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

*/
