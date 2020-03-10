#include <stdio.h>
 
int main()
{
    int T;
    // freopen("input.txt", "r", stdin);
    // setbuf(stdout, NULL);
    scanf("%d", &T);
 
    for(int testcase=1; testcase<=T; testcase++) {
        int numOfStudent, time=0;
        int room[201]={0}; // 복도만 표시
        scanf("%d", &numOfStudent);
 
        while(numOfStudent--) {
            int in, out;
            scanf("%d%d", &in, &out);
            if(in > out) { int t=in; in=out; out=t; }
            
            if(in&1) in++;
            in/=2; 
 
            if(out&1) out++;
            out/=2; 
 
            for(int i=in; i<=out; i++)
                room[i]++;
        }
        
        for(int i=1; i<=200; i++)
            if(time < room[i])
                time = room[i];
        printf("#%d %d\n", testcase, time);
    }
     
    return 0;
}
