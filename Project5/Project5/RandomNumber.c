#include <time.h>
#include <stdlib.h>

int RandomNum(int max)
{
	srand(time(NULL));
	int num = rand() % max + 1;

	printf("���� ���� �� %d\n", num);

	return num;
}

int CheckNum(int num) {

	if (num == 1) {
		printf("game1�� �����մϴ�.\n");
	}
	else if (num == 0) {
		printf("���α׷��� �����մϴ�.\n");
	}

	return num;
}