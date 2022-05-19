#include <time.h>
#include <stdlib.h>

int RandomNum(int max)
{
	srand(time(NULL));
	int num = rand() % max + 1;

	printf("뽑힌 랜덤 값 %d\n", num);

	return num;
}

int CheckNum(int num) {

	if (num == 1) {
		printf("game1을 종료합니다.\n");
	}
	else if (num == 0) {
		printf("프로그램을 종료합니다.\n");
	}

	return num;
}