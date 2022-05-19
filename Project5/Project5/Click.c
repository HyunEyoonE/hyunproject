#include <stdio.h>
#include<time.h>




	//��Ŭ ������ �ؼ� �������� ����!
	//6���� �ڽ��� �ִµ� �������� �ϸ� �������־��
	//������ Ŭ���ϸ� ���� ���Ѵ�ϴ�!
	//��Ŭ�ʼ�
	void initData();
	void printfclick();
	void Gclick(long elapsedTime);


	int level;
	int arrayclick[6];
	int* cursor;
	void Click_Main()
	{
		long startTime = 0;// ���� ���� �ð�
		long totalElapsedTime = 0;// �� ��� �ð�
		long prevElapsedTime = 0;// ���� ��� �ð� (�ֱٿ� ���� �� �ð�����)

		int num;
		initData();

		cursor = arrayclick; //cursor[0] .. cursor[1]
		// test
		startTime = clock();//���� �ð��� millsecond(1000���� 1��) ������ ��ȯ
		while (1)
		{
			printfclick();
			printf("�� �� �������� �����ðھ��?");
			scanf_s("%d", &num);

			//�Է°� üũ
			if (num < 1 || num > 6)
			{
				printf("\n�Է°��� �߸��Ǿ����ϴ�\n");
				continue;
			}
			//�� ��� �ð�
			totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
			printf("�� ��� �ð� : %ld ��\n", totalElapsedTime);

			//������ �������� ���� �ð� ���ķ� �帥 �ð�
			prevElapsedTime = totalElapsedTime - prevElapsedTime;
			printf("�ֱ� ��� �ð� : %ld �� \n", prevElapsedTime);

			//�ð��� ���� (����)
			Gclick(prevElapsedTime);

			//����ڰ� �Է��� ��ȣ�� �̴´�
			//1.������ �׾Ƹ��� 0�̵Ǹ� �ı�
			if (cursor[num - 1] <= 0)
			{
				printf("%d �� �׾Ƹ��� �μ������\n", num);
			}
			//2 �׾Ƹ��� 0�� �ƴ� ���? ��Ŭ ���� 100�� �����ʴ���üũ�ʼ�
			else if (cursor[num - 1] + 1 <= 100)
			{
				//�׾Ƹ��� ��Ŭ�Ѵ�
				printf("%d �׾Ƹ��� ��Ŭ�մϴ�\n\n", num);
				cursor[num - 1] += 1;//cursor[num - 1]= cursor[num - 1]+1
			}

			//�������� �� ���� Ȯ��(�������� 20�ʸ��� �ѹ��� ����)
			if (totalElapsedTime / 20 > level - 1)
			{
				//������
				level++;//level : 1 -> level : 2...
				printf("***�� ������! ���� %d �������� %d ������ ���׷��̵� �Ǿ����ϴ�!***\n\n", level - 1, level);

				//���� ���� :5
				if (level == 5)
				{
					printf("\n\n�����մϴ�, �ְ� ������ �޼��ϼ˽��ϴ� �������� ������!\n\n");
					exit(0);
				}
			}
			//�׾Ƹ��� �� ������?Ȯ��
			if (checkHangahri() == 0)
			{
				//�׾Ƹ� �� ����....
				printf("��� �׾Ƹ��� �� ����...\n");
				printf("�������� ȹ������ ���Ͽ����...\n");
				exit(0);
			}
			else
			{
				//�ּ� �Ѱ� �̻��� �׾Ƹ��� �ȱ���
				printf("�׾Ƹ��� ���� �ȱ�����?\n");
			}
			prevElapsedTime = totalElapsedTime;

			//10��->15�� (5�� : prevElapsedTime - >15��) ->25��(10��..?)
		}
		return 0;
	}

	void initData()
	{
		level = 1;
		for (int i = 0; i < 6; i++)
		{
			arrayclick[i] = 100;//�׾Ƹ� HP
		}
	}

	void printfclick()
	{
		printf(" %3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
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
			arrayclick[i] -= (level * 3 * (int)elapsedTime);//3�� ���̵� ������ ���� ��
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
				return 1; //�� true
		}
		return 0;
	}
