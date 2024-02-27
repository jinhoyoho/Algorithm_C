#include <stdio.h>
#include <stdlib.h>

int count = 0, queen[20], check;


void search(int num) {
    if (num == 11)
    {
        for (int i = 1; i < 11; i++)
            printf("%d", queen[i]-1);
        printf("\n");
        count++;
        return;
    }

    for (int i = 1; i <= 10; i++) 
    {
        queen[num] = i; //수 저장
        check = 1; //확인
        for (int j = 1; j < num; j++) 
            if (i == queen[j] || abs(i - queen[j]) == num - j) 
                check = 0;
        
        if (check) 
            search(num + 1);
    }
}

int main() {
    search(1);
    printf("%d", count);
    return 0;
}