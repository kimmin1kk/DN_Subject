/*
50! = 30414093201713378043612608166064768844377641568960512000000000000
*/
#include <stdio.h>
#define SIZE
int main(void) {

	int num;

	printf("���� �Է��ϼ��� : ");
	scanf_s("%d", &num);
	int fac1 = num;int fac2 = num - 1; unsigned long long int result = 1;
	if (num <= 50) {
		printf("�Է��Ͻ� ���� [%d] �Դϴ�", num);
		for (int i = 0; i < num; i++) {
			result *= fac1;
			printf("\n%llu", result);
			fac1--;
		}
		printf("\n %d!�� ���� : %'%llu%'�Դϴ�.", num, result);
	}
	else
		printf("\n50�� �Ѵ� ���� �Է��ϼ̽��ϴ�.\n");
	return 0;
}



