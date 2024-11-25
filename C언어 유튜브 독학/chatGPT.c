#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int level;
int arrayFish[6];
int *cursor;

void initData();
void printFishes();
void decreaseWater(long ElapsedTime);
int checkFishAlive();

int main() {
    long startTime = 0; // 게임 시작 시간
    long totalElapsedTime = 0; // 총 경과 시간
    long prevElapsedTime = 0; // 직전 경과 시간

    int num = 0; // 몇 번 어항에 물을 줄 것인지
    initData();

    cursor = arrayFish;

    startTime = clock(); // 현재 시간을 밀리세컨드 단위로 표현
    while (1) {
        printFishes();
        printf("몇 번 어항에 물을 주시겠어요?");
        scanf("%d", &num);

        // 입력값 체크
        if (num < 1 || num > 6) {
            printf("입력값이 잘못되었습니다\n");
            continue;
        }
        
        // 총 경과 시간
        totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
        printf("총 경과 시간: %ld 초\n", totalElapsedTime);

        // 직전 물 시간 이후 흐른 시간
        long currentElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("최근 경과 시간: %ld초\n", currentElapsedTime);
        
        decreaseWater(currentElapsedTime);

        // 사용자가 입력한 어항에 물을 준다
        // 1. 어항에 물이 0이면 물을 주지 않는다
        if (cursor[num - 1] <= 0) {
            printf("%d번 물고기는 이미 죽었습니다\n", num);
        }
        // 2. 어항에 물이 0이 아니면 물을 준다
        else if (cursor[num - 1] + 1 <= 100) {
            printf("%d번 어항에 물을 줍니다\n", num);
            cursor[num - 1] += 2;
        }

        // 시간이 경과되면 레벨업
        if (totalElapsedTime / 20 > level - 1) {
            level++;
            printf("난이도가 %d레벨로 올라갑니다\n", level);

            if (level == 5) {
                printf("축하합니다 최고 난이도를 달성하셨습니다\n");
                exit(0);
            }
        }
        // 모든 물고기가 죽었는지 확인
        if (checkFishAlive() == 0) {
            printf("모든 물고기가 죽었습니다. 게임 종료\n");
            exit(0);
        }
        prevElapsedTime = totalElapsedTime;
    }
    return 0;
}

void initData() {
    level = 1; // 게임 레벨 1~5
    for (int i = 0; i < 6; i++) {
        arrayFish[i] = 100; // 물높이 설정 100  
    }
}

void printFishes() {
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
    for (int i = 0; i < 6; i++) {
        printf(" %4d ", arrayFish[i]);
    }
    printf("\n\n");
}

void decreaseWater(long ElapsedTime) {
    for (int i = 0; i < 6; i++) {
        arrayFish[i] -= level * (int)ElapsedTime;
        if (arrayFish[i] < 0) {
            arrayFish[i] = 0;
        }
    }   
}

int checkFishAlive() {
    for (int i = 0; i < 6; i++) {
        if (arrayFish[i] > 0) {
            return 1;
        }
    }
    return 0;
}
