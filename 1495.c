#include <stdio.h>
int main()
{
    int mtch, goal;
    while(scanf("%d%d", &mtch, &goal)==2)
    {
        int i,j,l,m,lost[105],mtm,otm,rslt=0;
        for(i=0; i<105; i++) lost[i]=0;
        for(i=1,j=0; i<=mtch; i++)
        {
            scanf("%d%d", &mtm, &otm);
            if(mtm>otm)
                rslt+=3;
            else if(mtm==otm){
                if(goal>0){
                    rslt+=3;
                    goal--;
                }
                else rslt++;
            }
            else lost[otm-mtm]++;
        }
        if(goal>0){
            for(i=1; i<102; i++){
                while(goal>=i && lost[i]>0){
                    if(goal>i){
                        rslt+=3;
                        goal-=i+1;
                    }
                    else{
                        rslt++;
                        goal-=i;
                    }
                    lost[i]--;
                }
            }
        }
        printf("%d\n", rslt);
    }
    return 0;
}
