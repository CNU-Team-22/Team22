#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char name[256];
    printf("이름이 뭐예요?");
    scanf("%s", name);

    int age;
    printf("나이가 몇 살이에요?");
    scanf("%d", &age);

    float weight;
    printf("몸무게가 얼마에요?");
    scanf("%f", &weight);

    double height;
    printf("키가 얼마에요?");
    scanf("%lf", &height);

    char what[256];
    printf("무슨 범죄를 저질렀어요?");
    scanf("%s", what);

    printf("\n범죄자 정보\n");
    printf("이름: %s 나이: %d 몸무게: %.2f 키: %.2lf 범죄명: %s", name, age, weight, height, what);
    

    return 0;
}