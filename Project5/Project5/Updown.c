#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Updown_Main()
{

    //1~100까지 기회를 주고 7번의 찬스,찬스는 쓸때마다 1씩 깍임 up&down만들기★

        srand(time(NULL));
        int num = rand() % 100 + 1;

        int answer = 0;
        int chance = 7;
        while (1)
        {
            printf("남은 기회 %d 번\n", chance--);
            printf("숫자를 맞혀보세요 1~100자리 숫자입니다: ");
            scanf_s("%d", &answer);

            if (answer > num)
            {
                printf("DOWN이에요! \n\n");
            }
            else if (answer < num)
            {
                printf("UP입니다! \n\n");
            }
            else if (answer == num)
            {
                printf("이걸 맞춰?! \n\n");
                break;
            }
            else
            {
                printf("@오류발생@\n\n");
            }

            if (chance == 0)//찬스가 0 일때
            {
                printf("실패...첨부터 다시해요.\n");
                break;
            }
        }

        return 0;

    }

