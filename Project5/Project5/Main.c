#include <stdio.h>

int main()
{
	int menuNum = 0;
	while (1)
	{
		printf("�ϰ���� ������ �����ϼ���. (1. up&down����, 2. ��Ŭ �����ƾ�� ����)\n");
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