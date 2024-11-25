#include <stdio.h>
#include <time.h>

int main(void) {
	long startTime = 0;
    long elapsedTime = 0;
    int num = 0;
    startTime = clock();
    
    scanf("아무거나 치세요 %d", &num);
    if(num == 0){elapsedTime = ((clock() - startTime) / CLOCKS_PER_SEC) * 1000;
    
    printf("경과 시간 : %ld초\n", elapsedTime);}
    

	return 0;
}