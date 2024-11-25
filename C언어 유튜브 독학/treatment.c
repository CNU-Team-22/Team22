#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    
    int treatment = rand() % 4; //정답 정해주기
    int CurNum = 0;
    int PreNum = 0;
    int answer = 0; 
    for(int i=0; i<3; i++){
        int bottle[4] = {0,0,0,0}; 
        if(CurNum == PreNum){   //이번에 몇 병 고를지 정하기
            CurNum = rand() % 2 + 2;
            }
        PreNum = CurNum;
        for(int j=0;j<CurNum;j++){
            int pick = rand() % 4;
            if(bottle[pick] == 0){
                bottle[pick] = 1;
            }
            else{
                j--;
            }
        }
        for(int j=0; j<4; j++){
            if(bottle[j] == 1){
                printf("%d번째, ",j+1);
            }
        }
        printf("병을 부었습니다.\n");
        if(bottle[treatment] == 1){
            printf("발모제가 있었습니다\n");
        }
        else{
            printf("발모제가 없었습니다.\n");
        }
        getchar();
    }
    printf("발모제는 몇 번째 병인가요?\n");
    scanf("%d",&answer);
    if(answer == treatment + 1){
        printf("정답입니다.\n");
    }
    else{
        printf("오답입니다. 정답은 %d 번째 병입니다.",treatment+1);
    }
}