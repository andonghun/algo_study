#include<stdio.h>
#include<algorithm>

using namespace std;

int k;
int magnet[4][8];
int index, dir;

void rotate(int idx, int d) {
	if (d == 1) {
		int tmp = magnet[idx][7];
		for (int i = 7; i >= 1; i--) {
			magnet[idx][i] = magnet[idx][i-1];
		}
		magnet[idx][0] = tmp;

	} 
	else {
		int tmp = magnet[idx][0];
		for (int i = 0; i < 7; ++i) {
			magnet[idx][i] = magnet[idx][i+1];
		}
		magnet[idx][7] = tmp;

	}
}
void solve() {
	int i = index-1;
	int lp = magnet[i][6]; // 왼쪽 자성
	int rp = magnet[i][2]; // 오른쪽 자성

	rotate(i,dir);

	int d = dir;
	int l = i-1;
	int r = i+1;

	while(l >= 0) {
		if (magnet[l][2] == lp) break;
		else {
			d *= -1;
			lp = magnet[l][6];
			rotate(l,d);
			l--;
		} 
	
	}

	d = dir;
	while(r < 4) {
		if (magnet[r][6] == rp) break;
		else {
			d *= -1;
			rp = magnet[r][2];
			rotate(r,d);
			r++;		
		} 
	
	}

}

int main(int argc, const char * argv[]) {
	int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++){
        scanf("%d", &k);

        for (int i = 0; i < 4; ++i) {
        	for (int j = 0; j < 8; ++j) {
        		scanf("%d", &magnet[i][j]);
        	}
        }

        for (int i = 0; i < k; ++i) {	
        	scanf("%d %d", &index, &dir);
        	solve();
        }

 		int sum = 0;
        for (int i = 0; i < 4; ++i) {
        	if (magnet[i][0]) {
        		sum += pow(2,i);
        	}
        }
       
        printf("#%d %d\n", tc, sum);
        
    }
    
    return 0;
}