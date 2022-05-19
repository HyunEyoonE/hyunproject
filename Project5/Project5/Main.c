#include <stdio.h>

int main()
{
	int menuNum = 0;
	while (1)
	{
		printf("하고싶은 게임을 선택하세요. (1. up&down게임, 2. 광클 아이탬얻기 게임)\n");
		scanf_s("%d", &menuNum);

		if (menuNum == 1) 
		{
			Updown_Main();
		}
		else if (menuNum == 2) 
		{
			Click_Main();
		}
		else 
		{
			exit();
		}
	}
}