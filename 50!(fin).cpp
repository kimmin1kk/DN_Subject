#include <stdio.h>
#define SIZE 100

int main(void) {
	int size[SIZE] = { 0 }, num = 1, result = 1, cnt = 0, cnt2 = 0;

	printf("�� �Է� :");
	scanf_s("%d", &num);
	int fac = num;
	if (num <= 50) {
		size[99] += 1; //�迭 ������ (�ڿ��� ����)
		for (int i = 0; i < num; i++) { //�� �ݺ����� ������ ��� -> ���丮�� ��� �迭�� �����ֱ� + �ڸ��� �Ѿ�� ���� �ε����� �ѱ�� 
			size[99 - cnt];
			cnt++;

			for (int j = 0; j < SIZE; j++) { // ��� �迭�� �����ֱ�
				size[99 - j] *= fac;
			}
			fac--;
			for (int k = 0; k < SIZE; k++) { // �ڸ��� �˻� �� �ʰ��� ���� �ε����� �ѱ��
				while (size[99 - k] >= 10) {
					if ((size[99 - k] % 10) == 0) {
						size[98 - k] += (size[99 - k] / 10);
						size[99 - k] = 0;
					}
					else {
						size[98 - k] += (size[99 - k] / 10);
						size[99 - k] %= 10;
					}
					if (size[99 - k] < 10) {
						continue;
					}
				}
			}

		}
		for (int m = 0; m < SIZE; m++) { //���� 0 ���� Ȯ�ο� �ݺ���
			if (size[m] == 0) {
				cnt2++;
			}
			else {
				break;
			}
		}
		printf("\n%d!�� �� '", num); //���
		for (int m = cnt2; m < SIZE; m++) {
			printf("%d", size[m]);
		}
		printf("'");
	}
	else {
		printf("50�� �Ѵ� ���� �Է��ϼ̽��ϴ�.");
	}
	return 0;
}

















//#include <stdio.h>
//#define SIZE 100
//
//int number = 0, cnt = 1;
//
//int main(void) {
//
//	int size[SIZE], factorial(int);
//
//	for (int i = 0; i < SIZE;i++) { //�迭 �ʱ�ȭ <- �ʱ�ȭ �����ָ� �����Ⱚ ���´�.
//		int zeros = 0;
//		size[i] = zeros;
//	}
//
//	printf("�� �Է� : ");
//	scanf_s("%d", &number);
//
//	for (int result = factorial(number); result > 10; result /= 10) {
//		cnt++;
//	}
//	printf("�ڸ��� : %d\n", cnt);
//
//	printf("%d!�� �� : %d \n", number, factorial(number));
//	for (int i = 0; i < SIZE; i++) {
//		printf("%d", size[i]);
//	}
//
//	return 0;
//}
//
//
//
//int factorial(int number) {
//	//if (number > 100000) {
//	//	//number = number / 10;
//	//	//cnt++; <- �ڸ��� ������ ����ǵ� �ϴ��� �ּ�ó�� -> �ʿ����� �𸣰���.
//	//}
//	//else {
//		if (number < 1)
//			return 1;
//		else {
//			return (number * factorial(number - 1)) ;
//	}
//}






//#include <stdio.h>
//#define SIZE 100
//
//int main(void) {
//
//	int size[SIZE], num = 1, result = 1, cnt = 0; int j = 0;
//
//
//	printf("���� �Է��ϼ��� : ");
//	scanf_s("%d", &num);
//
//	if (num <= 50) {
//
//		for (int j = 0; j < SIZE;j++) { //�迭 �ʱ�ȭ <- �ʱ�ȭ �����ָ� �����Ⱚ ���´�.
//			int zeros = 0;
//			size[j] = zeros;
//		}
//		//--------------------------------
//		printf("�Է��Ͻ� ���� [%d] �Դϴ�. \n", num);
//		int fac = num;
//		for (int i = 0; i < num; i++) {
//			result *= fac;
//			fac--;
//			//printf("%d \n", result); ��� Ȯ��
//			if (result > 1000) {
//				if (result % 10 == 0) { /*�̷��� �ϸ� 15!���� ������ �ٵ� 15! �Ѿ�� 0 ������ ����ε� �����÷ο찡 ���.*/
//					result /= 10;
//					cnt++;
//				}
//				else;
//			}
//			else;
//		}
//		printf("\n %d�� ���� : '%d'�Դϴ�. �������� ������ 0�� ���� [%d]�Դϴ�.\n", num, result, cnt);
//		for (int i = 0; i < SIZE; i++) {
//			printf("%d", size[i]);
//		} // �迭 ���
//	}
//	else
//		printf("1~50! ���̸� �Է����ּ���");
//
//	return 0;
//}
//-----------------------------------------------------------------------------
// ��� �Ἥ �غ����µ� �ڸ��� ����� �������� �����Ƽ� ��������.
//#include <stdio.h>
//#define SIZE 100
//
//int number = 0, cnt = 0;
//
//int main(void) {
//
//	int size[SIZE], factorial(int), counter(int);
//	
//	
//	scanf_s("%d", &number);
//
//	printf("%d", factorial(number));
//	printf("\n%d", cnt);
//	return 0;
//}
//
//int factorial(int number) {
//	if (number > 100000) {
//		number = number / 10;
//		cnt++;
//	}
//	else {
//		if (number < 1)
//			return 1;
//		else {
//			return (number * factorial(number - 1)) ;
//		}
//	}
//}

//--------------------------------------------------------------------------
// ���� �������� �⺻ ���丮�� ��±� but unsigned long long int�� �Ἥ 20!������ ������.
/*int num;

printf("���� �Է��ϼ��� : ");
scanf_s("%d", &num);
int fac1 = num;unsigned long long int result = 1;
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
	printf("\n50�� �Ѵ� ���� �Է��ϼ̽��ϴ�.\n");*/
//-------------------------------------------------------------------------------
// �ڸ��� ���Ϸ��� �������.
	//	cnt = 0;
	//	int spaceNum = result;
	//	while (spaceNum > 10) {
	//		spaceNum = spaceNum / 10;
	//		cnt++;
	//		
	//		if (spaceNum < 10)
	//			break;
	//	}
	//	cnt++;
	//	printf("cnt�� %d", cnt);
	//	int fir_num = spaceNum;
	//	size[cnt]; //�迭 ������ ����(�ڸ����� �°�)
//---------------------------------------------------------------------------------
// �迭 �ʱ�ȭ
	//size[0] = 100; //�׽�Ʈ��
	//size[1] = 200; //�׽�Ʈ��2
	//for (int j = 0; j < SIZE;j++) { //�迭 �ʱ�ȭ block
	//	int zeros = 0;
	//	size[j] = zeros;
	//	printf("%d \n", size[j]);
	//} //�ϴ� ���⼭ �� 0���� �ʱ�ȭ 
//---------------------------------------------------------------------------------------
// �̰Ŵ� ��~~���� �⺻���� ���丮�� ��±�
	//int num = 1;
	//printf("���� �Է��ϼ��� : ");
	//scanf_s("%d", &num); 
	//int result = 1; int fac1 = num;
	//	
	//if (num <= 50) 
	//{
	//	printf("�Է��Ͻ� ���� [%d] �Դϴ� \n", num);
	//	for (int i = 0; i < num; i++) {
	//		result *= fac1;
	//		/*printf("\n%d", result);*/ //�߰� ��� Ȯ�ο�
	//		fac1--;
	//	}
	//	printf("\n %d!�� ���� : '%d'�Դϴ�.", num, result);
	//}
	//else
	//	printf("\n50�� �Ѵ� ���� �Է��ϼ̽��ϴ�.\n");
//-------------------------------------------------------------------------------------------
































