#include <stdio.h>
#define SIZE 100

int main(void) {
	int size[SIZE] = { 0 }, num = 1, result = 1, cnt = 0, cnt2 = 0;

	printf("값 입력 :");
	scanf_s("%d", &num);
	int fac = num;
	if (num <= 50) {
		size[99] += 1; //배열 시작점 (뒤에서 시작)
		for (int i = 0; i < num; i++) { //이 반복문에 구현할 기능 -> 팩토리얼 모든 배열에 곱해주기 + 자릿수 넘어가면 다음 인덱스로 넘기기 
			size[99 - cnt];
			cnt++;

			for (int j = 0; j < SIZE; j++) { // 모든 배열에 곱해주기
				size[99 - j] *= fac;
			}
			fac--;
			for (int k = 0; k < SIZE; k++) { // 자릿수 검사 및 초과시 다음 인덱스로 넘기기
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
		for (int m = 0; m < SIZE; m++) { //앞의 0 개수 확인용 반복문
			if (size[m] == 0) {
				cnt2++;
			}
			else {
				break;
			}
		}
		printf("\n%d!의 값 '", num); //출력
		for (int m = cnt2; m < SIZE; m++) {
			printf("%d", size[m]);
		}
		printf("'");
	}
	else {
		printf("50이 넘는 값을 입력하셨습니다.");
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
//	for (int i = 0; i < SIZE;i++) { //배열 초기화 <- 초기화 안해주면 쓰레기값 나온다.
//		int zeros = 0;
//		size[i] = zeros;
//	}
//
//	printf("값 입력 : ");
//	scanf_s("%d", &number);
//
//	for (int result = factorial(number); result > 10; result /= 10) {
//		cnt++;
//	}
//	printf("자릿수 : %d\n", cnt);
//
//	printf("%d!의 값 : %d \n", number, factorial(number));
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
//	//	//cnt++; <- 자릿수 쓰려고 만든건데 일단은 주석처리 -> 필요한지 모르겠음.
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
//	printf("값을 입력하세요 : ");
//	scanf_s("%d", &num);
//
//	if (num <= 50) {
//
//		for (int j = 0; j < SIZE;j++) { //배열 초기화 <- 초기화 안해주면 쓰레기값 나온다.
//			int zeros = 0;
//			size[j] = zeros;
//		}
//		//--------------------------------
//		printf("입력하신 값은 [%d] 입니다. \n", num);
//		int fac = num;
//		for (int i = 0; i < num; i++) {
//			result *= fac;
//			fac--;
//			//printf("%d \n", result); 계산 확인
//			if (result > 1000) {
//				if (result % 10 == 0) { /*이렇게 하면 15!까지 가능함 근데 15! 넘어가면 0 제외한 수들로도 오버플로우가 뜬다.*/
//					result /= 10;
//					cnt++;
//				}
//				else;
//			}
//			else;
//		}
//		printf("\n %d의 값은 : '%d'입니다. 마지막에 제외한 0의 수는 [%d]입니다.\n", num, result, cnt);
//		for (int i = 0; i < SIZE; i++) {
//			printf("%d", size[i]);
//		} // 배열 출력
//	}
//	else
//		printf("1~50! 사이를 입력해주세요");
//
//	return 0;
//}
//-----------------------------------------------------------------------------
// 재귀 써서 해볼랬는데 자릿수 만드는 과정에서 좆같아서 다음으로.
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
// 가장 기초적인 기본 팩토리얼 출력기 but unsigned long long int를 써서 20!까지는 가능함.
/*int num;

printf("값을 입력하세요 : ");
scanf_s("%d", &num);
int fac1 = num;unsigned long long int result = 1;
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
	printf("\n50이 넘는 값을 입력하셨습니다.\n");*/
//-------------------------------------------------------------------------------
// 자릿수 구하려고 만든거임.
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
	//	printf("cnt값 %d", cnt);
	//	int fir_num = spaceNum;
	//	size[cnt]; //배열 사이즈 수정(자릿수에 맞게)
//---------------------------------------------------------------------------------
// 배열 초기화
	//size[0] = 100; //테스트용
	//size[1] = 200; //테스트용2
	//for (int j = 0; j < SIZE;j++) { //배열 초기화 block
	//	int zeros = 0;
	//	size[j] = zeros;
	//	printf("%d \n", size[j]);
	//} //일단 여기서 다 0으로 초기화 
//---------------------------------------------------------------------------------------
// 이거는 완~~전히 기본적인 팩토리얼 출력기
	//int num = 1;
	//printf("값을 입력하세요 : ");
	//scanf_s("%d", &num); 
	//int result = 1; int fac1 = num;
	//	
	//if (num <= 50) 
	//{
	//	printf("입력하신 값은 [%d] 입니다 \n", num);
	//	for (int i = 0; i < num; i++) {
	//		result *= fac1;
	//		/*printf("\n%d", result);*/ //중간 출력 확인용
	//		fac1--;
	//	}
	//	printf("\n %d!의 값은 : '%d'입니다.", num, result);
	//}
	//else
	//	printf("\n50이 넘는 값을 입력하셨습니다.\n");
//-------------------------------------------------------------------------------------------
































