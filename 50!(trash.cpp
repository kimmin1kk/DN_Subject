/*
50! = 30414093201713378043612608166064768844377641568960512000000000000
*/
#include <stdio.h>
#define SIZE
int main(void) {

	int num;

	printf("값을 입력하세요 : ");
	scanf_s("%d", &num);
	int fac1 = num;int fac2 = num - 1; unsigned long long int result = 1;
	if (num <= 50) {
		printf("입력하신 값은 [%d] 입니다", num);
		for (int i = 0; i < num; i++) {
			result *= fac1;
			printf("\n%llu", result);
			fac1--;
		}
		printf("\n %d!의 값은 : %'%llu%'입니다.", num, result);
	}
	else
		printf("\n50이 넘는 값을 입력하셨습니다.\n");
	return 0;
}



