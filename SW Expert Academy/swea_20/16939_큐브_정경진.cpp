// 백준 16939. 2*2*2 큐브
// 참고 : https://100100e.tistory.com/216
#include <iostream>

#define MAX 24
using namespace std;

int cube[MAX+1];
int cpy[MAX+1];

// 큐브가 다 맞춰졌는지 확인하는 함수
bool check() {
    for (int i = 1; i <= MAX; i+=4) {
        int begin = cpy[i];
        for (int j = i+1; j <= i+3; j++) {
            if (begin != cpy[j]) {
                return false;
            }
        }   
    }
    cout << 1;
    return true;
}

void one()
{
	int temp1 = cpy[21], temp2 = cpy[23];
	cpy[21] = cpy[4];
	cpy[23] = cpy[2];

	cpy[4] = cpy[8];
	cpy[2] = cpy[6];

	cpy[6] = cpy[10];
	cpy[8] = cpy[12];

	cpy[12] = temp1;
	cpy[10] = temp2;
}

void reone()
{
	one();
	one();
	one();
}

void two()
{
	int temp1 = cpy[22], temp2 = cpy[24];
	cpy[22] = cpy[3];
	cpy[24] = cpy[1];

	cpy[3] = cpy[7];
	cpy[1] = cpy[5];

	cpy[7] = cpy[11];
	cpy[5] = cpy[9];

	cpy[11] = temp1;
	cpy[9] = temp2;
}

void retwo()
{
	two();
	two();
	two();
}

void three()
{
	int temp1 = cpy[11], temp2 = cpy[12];
	cpy[11] = cpy[13];
	cpy[12] = cpy[15];

	cpy[13] = cpy[2];
	cpy[15] = cpy[1];

	cpy[2] = cpy[20];
	cpy[1] = cpy[18];

	cpy[20] = temp1;
	cpy[18] = temp2;
}

void rethree()
{
	three();
	three();
	three();
}

void four()
{
	int temp1 = cpy[9], temp2 = cpy[10];
	cpy[9] = cpy[14];
	cpy[10] = cpy[16];

	cpy[14] = cpy[4];
	cpy[16] = cpy[3];

	cpy[4] = cpy[19];
	cpy[3] = cpy[17];

	cpy[19] = temp1;
	cpy[17] = temp2;
}

void refour()
{
	four();
	four();
	four();
}

void five()
{
	int temp1 = cpy[19], temp2 = cpy[20];
	cpy[20] = cpy[24];
	cpy[19] = cpy[23];

	cpy[24] = cpy[16];
	cpy[23] = cpy[15];

	cpy[16] = cpy[8];
	cpy[15] = cpy[7];

	cpy[8] = temp2;
	cpy[7] = temp1;

}
void refive()
{
	five();
	five();
	five();
}

void six()
{
	int temp = cpy[18], temp2 = cpy[17];
	cpy[18] = cpy[22];
	cpy[17] = cpy[21];

	cpy[22] = cpy[14];
	cpy[21] = cpy[13];

	cpy[13] = cpy[5];
	cpy[14] = cpy[6];

	cpy[5] = temp2;
	cpy[6] = temp;
}

void resix()
{
	six();
	six();
	six();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    for (int i = 1; i <= MAX; i++)
        cin >> cube[i];
    
    for (int i = 1; i <= MAX; i++) cpy[i] = cube[i];
    one();
    if (check()) return 0;

    for (int i = 1; i <= MAX; i++) cpy[i] = cube[i];
    reone();
    if (check()) return 0;

    for (int i = 1; i <= MAX; i++) cpy[i] = cube[i];
    two();
    if (check()) return 0;

    for (int i = 1; i <= MAX; i++) cpy[i] = cube[i];
    retwo();
    if (check()) return 0;

    for (int i = 1; i <= MAX; i++) cpy[i] = cube[i];
    three();
    if (check()) return 0;

    for (int i = 1; i <= MAX; i++) cpy[i] = cube[i];
    rethree();
    if (check()) return 0;

    for (int i = 1; i <= MAX; i++) cpy[i] = cube[i];
    four();
    if (check()) return 0;

    for (int i = 1; i <= MAX; i++) cpy[i] = cube[i];
    refour();
    if (check()) return 0;

    for (int i = 1; i <= MAX; i++) cpy[i] = cube[i];
    five();
    if (check()) return 0;

    for (int i = 1; i <= MAX; i++) cpy[i] = cube[i];
    refive();
    if (check()) return 0;

    for (int i = 1; i <= MAX; i++) cpy[i] = cube[i];
    six();
    if (check()) return 0;

    for (int i = 1; i <= MAX; i++) cpy[i] = cube[i];
    resix();
    if (check()) return 0;

    cout << 0;
    return 0;
}
