#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Index�� 1���� 20���� ����ϱ� ���ؼ� 21�� ����
#define STUDENT_NUM 21
#define ITEM_NUM 21 

struct students {
    int item[ITEM_NUM];         //������ ��ȣ�� �迭
    int item_index[ITEM_NUM];   //������ �ε��� �迭
    int current_item;           //���� ���õ� ������
    int store_item;             //���� ������ �ִ� ������
};

int Random_Algorithm(struct students a[]) //���� �˰��� (�л� ����ü, �湮 ���)
{
    for (int i = 1; i < STUDENT_NUM; i++)
        a[i].current_item = -1; //��� �л����� ���� ������ ���� �ʱ�ȭ
    int total = 0; //������ �� ��
    int visited[ITEM_NUM] = { 0, }; //���õ� ������ ���
    // count�� ���õ� �л� ��, 1~20���� �� 20�� �ݺ�
    for (int count = 0; count < STUDENT_NUM - 1; count++)
    {
        int random_student; //�����ϰ� ������ �л�

        do //���� �������� ���� �л��� �����Ҷ����� �ݺ�
        {
            random_student = (rand() % (STUDENT_NUM - 1)) + 1; // 1~20���� �����ϰ� �л� ����
        } while (a[random_student].current_item != -1);

        //�ش� �л� �������� ��ȣ�� ū ������� ���� -> ��ȣ�� ������ ���� �Ǿ� �����Ƿ� �տ������� ã���ָ� ��
        for (int i = 1; i < ITEM_NUM - 1; i++) 
        {
            int index = a[random_student].item_index[i]; //ū ������� ������ ����
            if (visited[index] == 0) //���õ��� ���� �����̶��
            {
                visited[index] = 1; //����ó��
                total += a[random_student].item[i]; //��ȣ�� ����
                a[random_student].current_item = index; //���� �����ۿ� ����
                break; //Ż��
            }
        }
    }
    return total; //���� ��ȯ
}

int main() {
    srand(time(NULL));                    //��������
    struct students student[STUDENT_NUM]; //����ü �迭 ����
    int max_score = 0;                    //�ִ밪 ����
    clock_t time_to_run = clock();        //����ð� ����
    int epoch;                            //����ũ ����

    for (int i = 1; i < STUDENT_NUM; i++)
    {
        for (int j = 1; j < ITEM_NUM; j++)
        {
            student[i].item[j] = 0;         //i��° �л��� j��° ������ ��ȣ�� 0���� �ʱ�ȭ
            student[i].item_index[j] = j;   // i��° �л��� j��° ������ �ε��� j�� �ʱ�ȭ
        }
    }

    FILE* fp;
    fp = fopen("satisfaction.txt", "r"); //���� ����
    int id, item_num, satis;        //�й�, ������ ��ȣ, ������
    char first_sentence[50];        //ù �� �Է�
    fgets(first_sentence, 50, fp);  //ó�� �� �� �Է�
    while (!feof(fp))//����ñ���
    {
        fscanf(fp, "%d %d %d", &id, &item_num, &satis); //�Է�
        student[id].item[item_num] = satis;             //�ش� �л��� �ش� ��ǰ�� ������ ����
    };
    fclose(fp); //���� �ݱ�

    for (int i = 1; i < STUDENT_NUM; i++)
    {
        //�������� �̿��ϱ�
        for (int j = 1; j < ITEM_NUM-1; j++)
        {
            int max_index = j; //���� ū �� �ε��� ã��
            for (int k = j + 1; k < ITEM_NUM; k++)
            {
                //i��° �л��� ������ k�� ������ j���� ��ȣ���� ���� ���
                if (student[i].item[k] > student[i].item[max_index])
                {
                    max_index = k; //���� ���� �̿�
                }
            }
            int tmp = student[i].item[j];
            student[i].item[j] = student[i].item[max_index];
            student[i].item[max_index] = tmp; //������ �� ����

            int tmp_index = student[i].item_index[j];
            student[i].item_index[j] = student[i].item_index[max_index];
            student[i].item_index[max_index] = tmp_index; //������ ��ȣ ����
        }
    }

    for (epoch = 0; epoch < 5000; epoch++)  //����ũ 5000������ ����
    {
        int score = Random_Algorithm(student); //���� �˰��� ����
        if (score > max_score) //������ �ִ밪���� ũ�ٸ�
        {
            max_score = score; //������ �ִ밪 ����
            for (int i = 1; i < STUDENT_NUM; i++) 
            {
                student[i].store_item = student[i].current_item; //���� ���õ� ������ ����
            }
        }
    }
    
    for (int i = 1; i < STUDENT_NUM; i++)
    {
        printf("Student id: %d, Select Item: %d\n", i, student[i].store_item);
    }
    printf("\nTotal Score: %d\n", max_score);

    clock_t end = clock();
    printf("�ҿ�ð�: %lf\n", (double)(end - time_to_run) / CLOCKS_PER_SEC);
    return 0;
}