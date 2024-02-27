#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Index를 1부터 20까지 사용하기 위해서 21로 설정
#define STUDENT_NUM 21
#define ITEM_NUM 21 

struct students {
    int item[ITEM_NUM];         //아이템 선호도 배열
    int item_index[ITEM_NUM];   //아이템 인덱스 배열
    int current_item;           //현재 선택된 아이템
    int store_item;             //원래 가지고 있는 아이템
};

int Random_Algorithm(struct students a[]) //랜덤 알고리즘 (학생 구조체, 방문 기록)
{
    for (int i = 1; i < STUDENT_NUM; i++)
        a[i].current_item = -1; //모든 학생들의 현재 선택할 선물 초기화
    int total = 0; //만족도 총 합
    int visited[ITEM_NUM] = { 0, }; //선택된 아이템 기록
    // count는 선택된 학생 수, 1~20까지 총 20번 반복
    for (int count = 0; count < STUDENT_NUM - 1; count++)
    {
        int random_student; //랜덤하게 선택한 학생

        do //현재 아이템이 없는 학생을 선택할때까지 반복
        {
            random_student = (rand() % (STUDENT_NUM - 1)) + 1; // 1~20까지 랜덤하게 학생 선택
        } while (a[random_student].current_item != -1);

        //해당 학생 아이템을 선호도 큰 순서대로 선택 -> 선호도 순으로 정렬 되어 있으므로 앞에서부터 찾아주면 됨
        for (int i = 1; i < ITEM_NUM - 1; i++) 
        {
            int index = a[random_student].item_index[i]; //큰 순서대로 아이템 선택
            if (visited[index] == 0) //선택되지 않은 물건이라면
            {
                visited[index] = 1; //선택처리
                total += a[random_student].item[i]; //선호도 저장
                a[random_student].current_item = index; //현재 아이템에 저장
                break; //탈출
            }
        }
    }
    return total; //총합 반환
}

int main() {
    srand(time(NULL));                    //무작위로
    struct students student[STUDENT_NUM]; //구조체 배열 생성
    int max_score = 0;                    //최대값 선언
    clock_t time_to_run = clock();        //실행시간 선언
    int epoch;                            //에포크 선언

    for (int i = 1; i < STUDENT_NUM; i++)
    {
        for (int j = 1; j < ITEM_NUM; j++)
        {
            student[i].item[j] = 0;         //i번째 학생의 j번째 아이템 선호도 0으로 초기화
            student[i].item_index[j] = j;   // i번째 학생의 j번째 아이템 인덱스 j로 초기화
        }
    }

    FILE* fp;
    fp = fopen("satisfaction.txt", "r"); //파일 열기
    int id, item_num, satis;        //학번, 아이템 번호, 만족도
    char first_sentence[50];        //첫 줄 입력
    fgets(first_sentence, 50, fp);  //처음 한 줄 입력
    while (!feof(fp))//종료시까지
    {
        fscanf(fp, "%d %d %d", &id, &item_num, &satis); //입력
        student[id].item[item_num] = satis;             //해당 학생과 해당 물품의 만족도 저장
    };
    fclose(fp); //파일 닫기

    for (int i = 1; i < STUDENT_NUM; i++)
    {
        //선택정렬 이용하기
        for (int j = 1; j < ITEM_NUM-1; j++)
        {
            int max_index = j; //가장 큰 값 인덱스 찾기
            for (int k = j + 1; k < ITEM_NUM; k++)
            {
                //i번째 학생의 아이템 k가 아이템 j보다 선호도가 높은 경우
                if (student[i].item[k] > student[i].item[max_index])
                {
                    max_index = k; //선택 정렬 이용
                }
            }
            int tmp = student[i].item[j];
            student[i].item[j] = student[i].item[max_index];
            student[i].item[max_index] = tmp; //만족도 값 변경

            int tmp_index = student[i].item_index[j];
            student[i].item_index[j] = student[i].item_index[max_index];
            student[i].item_index[max_index] = tmp_index; //아이템 번호 변경
        }
    }

    for (epoch = 0; epoch < 5000; epoch++)  //에포크 5000번으로 설정
    {
        int score = Random_Algorithm(student); //랜덤 알고리즘 실행
        if (score > max_score) //기존의 최대값보다 크다면
        {
            max_score = score; //기존의 최대값 변경
            for (int i = 1; i < STUDENT_NUM; i++) 
            {
                student[i].store_item = student[i].current_item; //현재 선택된 아이템 저장
            }
        }
    }
    
    for (int i = 1; i < STUDENT_NUM; i++)
    {
        printf("Student id: %d, Select Item: %d\n", i, student[i].store_item);
    }
    printf("\nTotal Score: %d\n", max_score);

    clock_t end = clock();
    printf("소요시간: %lf\n", (double)(end - time_to_run) / CLOCKS_PER_SEC);
    return 0;
}