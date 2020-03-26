#include<bits/stdc++.h>
using namespace std;
int magnet[4][8];
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	int T, K;
	cin>>T;
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> K;
		for (int i=0; i<4; i++) {
			for (int j=0; j<8; j++) {
				cin >> magnet[i][j];
			}
		}
		for (int ii=0; ii<K; ii++) {
			int num, dri;
			cin >> num >> dri;
			int rotate[4] = {
				0,
			}
			;
			num--;
			rotate[num] = dri;
			for (int i = num; i<3; i++) {
				// 오른쪽부터 확인 
				if(magnet[i][2] != magnet[i+1][6]) {
					rotate[i+1] = rotate[i]*-1;
				} else break;
			}
			for (int i = num; i>0; i--) {
				// 오른쪽부터 확인 
				if(magnet[i][6] != magnet[i-1][2]) {
					rotate[i-1] = rotate[i]*-1;
				} else break;
			}
			for (int i=0; i<4; i++) {
				if(rotate[i] == 1) {
					int temp = magnet[i][7];
					for (int j=7; j>0; j--) {
						magnet[i][j] = magnet[i][j-1];
					}
					magnet[i][0] = temp;
				} else if(rotate[i] == -1) {
					int temp = magnet[i][0];
					for (int j=0; j<7; j++) {
						magnet[i][j] = magnet[i][j+1];
					}
					magnet[i][7] = temp;
				}
			}
		}
		cout << "#" << test_case << " " << magnet[0][0]*1 + magnet[1][0]*2 + magnet[2][0]*4 + magnet[3][0]*8 << '\n';
	}
	return 0;
}
