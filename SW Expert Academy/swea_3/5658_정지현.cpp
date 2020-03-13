#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {
    int test_case;
    int T;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case) {
        int n,k;
        string s;
        vector<int> number;

        cin >> n >> k;
        cin >> s;

        int size = n/4; 

        for (int i = 0; i < size-1; i++) {
            s += s[i];
        }

        for (int i = 0; i < n; i++) {
            string tmp = s.substr(i,size);
            int num = stoi(tmp, nullptr, 16);
            number.push_back(num);
        }

        sort(number.begin(), number.end(), greater<int>());

        int cnt = 0;
        int tmp = 0;
        for (int i = 0; i < number.size(); i++) {
            if (tmp != number[i]) {
                cnt++;
                tmp = number[i];
            }

            if (cnt == k) {
                printf("#%d %d\n", test_case, number[i]);
                break;
            }
        }        

    }
    return 0;
}