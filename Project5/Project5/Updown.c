#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Updown_Main()
{

    //1~100���� ��ȸ�� �ְ� 7���� ����,������ �������� 1�� ���� up&down������

        srand(time(NULL));
        int num = rand() % 100 + 1;

        int answer = 0;
        int chance = 7;
        while (1)
        {
            printf("���� ��ȸ %d ��\n", chance--);
            printf("���ڸ� ���������� 1~100�ڸ� �����Դϴ�: ");
            scanf_s("%d", &answer);

            if (answer > num)
            {
                printf("DOWN�̿���! \n\n");
            }
            else if (answer < num)
            {
                printf("UP�Դϴ�! \n\n");
            }
            else if (answer == num)
            {
                printf("�̰� ����?! \n\n");
                break;
            }
            else
            {
                printf("@�����߻�@\n\n");
            }

            if (chance == 0)//������ 0 �϶�
            {
                printf("����...÷���� �ٽ��ؿ�.\n");
                break;
            }
        }

        return 0;

    }

