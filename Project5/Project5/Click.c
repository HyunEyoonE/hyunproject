#include <stdio.h>
#include<time.h>




	//광클 게임을 해서 아이탬을 얻어보자!
	//6개의 박스가 있는데 레벨업을 하면 얻을수있어요
	//느리게 클릭하면 얻지 못한답니다!
	//광클필수
	void initData();
	void printfclick();
	void Gclick(long elapsedTime);


	int level;
	int arrayclick[6];
	int* cursor;
	void Click_Main()
	{
		long startTime = 0;// 게임 시작 시간
		long totalElapsedTime = 0;// 총 경과 시간
		long prevElapsedTime = 0;// 직전 경과 시간 (최근에 물을 준 시간간격)

		int num;
		initData();

		cursor = arrayclick; //cursor[0] .. cursor[1]
		// test
		startTime = clock();//현재 시간으 millsecond(1000분의 1초) 단위로 반환
		while (1)
		{
			printfclick();
			printf("몇 번 아이탬을 뽑으시겠어요?");
			scanf_s("%d", &num);

			//입력값 체크
			if (num < 1 || num > 6)
			{
				printf("\n입력값이 잘못되었습니다\n");
				continue;
			}
			//총 경과 시간
			totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
			printf("총 경과 시간 : %ld 초\n", totalElapsedTime);

			//직전에 아이탬을 뽑은 시간 이후로 흐른 시간
			prevElapsedTime = totalElapsedTime - prevElapsedTime;
			printf("최근 경과 시간 : %ld 초 \n", prevElapsedTime);

			//시간초 감소 (증발)
			Gclick(prevElapsedTime);

			//사용자가 입력한 번호를 뽑는다
			//1.아이탬 항아리가 0이되면 파괴
			if (cursor[num - 1] <= 0)
			{
				printf("%d 번 항아리가 부셔졌어요\n", num);
			}
			//2 항아리가 0이 아닌 경우? 광클 ㄱㄱ 100을 넘지않는지체크필수
			else if (cursor[num - 1] + 1 <= 100)
			{
				//항아리를 광클한다
				printf("%d 항아리를 광클합니다\n\n", num);
				cursor[num - 1] += 1;//cursor[num - 1]= cursor[num - 1]+1
			}

			//레벨업을 할 건지 확인(레벨업은 20초마다 한번씩 수행)
			if (totalElapsedTime / 20 > level - 1)
			{
				//레벨업
				level++;//level : 1 -> level : 2...
				printf("***축 레벨업! 기존 %d 레벨에서 %d 레벨로 업그레이드 되었습니다!***\n\n", level - 1, level);

				//최종 레벨 :5
				if (level == 5)
				{
					printf("\n\n축하합니다, 최고 레벨을 달성하셧습니다 아이탬을 얻었어요!\n\n");
					exit(0);
				}
			}
			//항아리가 다 깨졋는?확인
			if (checkHangahri() == 0)
			{
				//항아리 다 깨짐....
				printf("모든 항아리가 다 터짐...\n");
				printf("아이탬을 획득하지 못하였어요...\n");
				exit(0);
			}
			else
			{
				//최소 한개 이상의 항아리가 안깨짐
				printf("항아리가 아직 안깨졋어?\n");
			}
			prevElapsedTime = totalElapsedTime;

			//10초->15초 (5초 : prevElapsedTime - >15초) ->25초(10초..?)
		}
		return 0;
	}

	void initData()
	{
		level = 1;
		for (int i = 0; i < 6; i++)
		{
			arrayclick[i] = 100;//항아리 HP
		}
	}

	void printfclick()
	{
		printf(" %3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
		for (int i = 0; i < 6; i++)
		{
			printf("  %4d", arrayclick[i]);
		}
		printf("\n\n");
	}

	void Gclick(long elapsedTime)
	{
		for (int i = 0; i < 6; i++)
		{
			arrayclick[i] -= (level * 3 * (int)elapsedTime);//3은 난이도 조절을 위한 값
			if (arrayclick[i] < 0)
			{
				arrayclick[i] = 0;
			}
		}
	}

	int checkHangahri()
	{
		for (int i = 0; i < 6; i++)
		{
			if (arrayclick[i] > 0)
				return 1; //참 true
		}
		return 0;
	}
