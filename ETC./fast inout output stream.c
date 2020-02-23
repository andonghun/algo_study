#include <stdio.h>
#define pc(x) putchar_unlocked(x)
#define gc() getchar_unlocked()
int readINT(){
    int N = gc(),ret = 0, flag = 1;
    for(;N<'0'||N>'9';N=gc())
        if(N=='-'){
            flag=-1;    N=gc(); break;
        }
    do{
        ret = (ret<<3) + (ret<<1) + N - '0';    N=gc();
    }while('0'<=N&&N<='9');
    return ret*flag;
}
inline void writeInt (int n)
{
    if (n == 0) { pc('0'); pc('\n'); return ;}
    if (n<0) { n = -n; pc('-');}
    int N = n, rev, count = 0;
    rev = N;
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}
int main(int argc, char** argv){
    register int k = readINT();
    writeInt(k);
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
