#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ShowQuestion(int level, int num1, int num2);
int GetNumber(int level){
    return rand() % (level * 7) + 1;
}

int main() {
    srand(time(NULL));
    int count = 0; //맞춘 개수
    for (int i=1; i<=5; i++){ //i는 레벨
        int num1 = GetNumber(i);
        int num2 = GetNumber(i);
        ShowQuestion(i,num1,num2);
        int answer = 0;
        scanf("%d",&answer);
        if(answer == num1 * num2){
            printf("정답입니다");
            count ++;
        }
        else if(answer == -1){
            exit(0);
        }
        else{
            printf("오답입니다");

        }
    }
    printf("\n총 맞춘 개수는 %d개입니다.",count);
    return 0;
}

void ShowQuestion(int level, int num1, int num2){
    printf("##### %d번째 단계입니다. 비밀번호를 입력하세요 #####\n", level);
    printf("%d x %d = ?\n", num1, num2);
    printf("종료하고 싶으시다면 -1을 입력해주세요");
}