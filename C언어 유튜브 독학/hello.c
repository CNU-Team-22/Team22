#include <stdio.h>

int main(void)
{
    char name[256];
    printf("이름이 뭐예요?");
    scanf("%s",name);
    printf("%s님, 반가워요!\n", name);
    return 0;

    
}