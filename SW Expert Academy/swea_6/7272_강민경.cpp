// 7272. 안경이없어
#include<iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test_case;
	int T;
	
	map<char, int> alpabet; // 알파벳키, 키값

	// CEFGHIJKLMNSTUVWXYZ // 1로 설정
	// ADOPQR // 0으로 설정
	// B // 2로 설정
	for (int i = 0; i < 26; i++) {
		if(i == 1)
			alpabet.insert(make_pair(65+i, 2));
		else if (i == 2 || i >= 4 && i <= 13 || i>=18) 
			alpabet.insert(make_pair(65+ i, 1));
		else
			alpabet.insert(make_pair(65 + i, 0));
	}

	cin >> T;
	string s1, s2;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string isSame = "SAME";

		cin >> s1 >> s2;

		cout << "#" << test_case << " ";

		if (s1.size() != s2.size()) {
			isSame = "DIFF";
		}
		else {
			for (int j = 0; j < s1.size(); j++) {
				if (alpabet[s1[j]] != alpabet[s2[j]]) {
					isSame = "DIFF";
					break;
				}
			}
		}
		cout << isSame << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


/*	char ch[27];
	for (int i = 0; i < 26; i++) {
		ch[i] = 65 + i;
	//	cout << alpabet[65 + i] << " ";
		cout << ch[i] << " ";
	}
	*/
