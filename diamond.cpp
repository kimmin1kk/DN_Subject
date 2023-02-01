/*	입력값은 곧 중앙의 별의 갯수
*   입력값은 홀수의 경우 줄의 값과 동일 짝수의 경우 -1
*   공백 1개당 별 2개를 차지함.
*/

#include <stdio.h>

int main(void)
{
	int input = 0, spacen = 0, star = 0;
	int x = 0;
	int counts = 0, skip = 1;
	printf("중앙 별의 갯수를 정해주세요 : ");
	scanf_s("%d", &input);
	printf("당신이 입력한 수는 %d입니다. \n\n", input);

	if (input % 2 != 0) //홀수
	{
		spacen = input / 2; // spacen은 공백을 위해 만듦
		star = 1;


		for (int z = 1; z <= input; z++) {

			if (star <= input) { // 위에서부터 중간까지
				if (x >= 0) {
					for (int x = spacen; x > 0; x--) { //줄어드는 공백
						printf(" ");
					}
					spacen--;
					if (spacen == 0)
						x = -1;
				}

				//늘어나는 별. 별이 마지막에 있어야 puts를 할 수가 있음 순서 중요함
				for (int c = 1; c <= star; c++) {
					printf("*");
				}
				star += 2;
				puts("");
				counts++;
			}

		}
		star = input - 2;
		for (int j = 0; j < input / 2;j++) {

			if (counts == (input / 2) + 1) { //중간 밑에서부터 끝까지
				spacen = input / 2;
				for (int i = 0; i < skip; i++) { //늘어나는 공백 1 2 3 4 ''' input / 2 까지 가야 함
					printf(" ");
				}
				if (skip != spacen + 1)
					skip++;
			}
			for (int k = 0; k < star; k++) { //줄어드는 별
				printf("*");
			}
			puts("");
			star -= 2;
		}


		//여기서 star = input += 2
	}
	else //짝수
	{
		spacen = input / 2 - 1; // spacen은 공백을 위해 만듦
		star = 1;

		for (int z = 1; z <= input; z++) {

			if (star <= input) { // 위에서부터 중간까지
				if (x >= 0) {
					for (int x = spacen; x > 0; x--) { //줄어드는 공백
						printf(" ");
					}
					spacen--;
					if (spacen == 0)
						x = -1;
				}

				//늘어나는 별. 별이 마지막에 있어야 puts를 할 수가 있음 순서 중요함
				for (int c = 0; c <= star; c++) {
					printf("*");
				}
				star += 2;
				puts("");
				counts++;
			}
		}
		star = input - 2;
		//늘어나는 공백에 쓰는 변수 skip, spacen
		for (int j = 0; j < input / 2;j++) {
			if (counts == input / 2) { //중간 밑에서부터 끝까지
				spacen = input / 2;
				for (int i = 0; i < skip; i++) { //늘어나는 공백 1 2 3 4 ''' input / 2 까지 가야 함 홀짝 동일
					printf(" ");
				}
				if (skip != spacen + 1)
					skip++;
			}
			for (int k = 0; k < star; k++) { //줄어드는 별
				printf("*");
			}
			puts("");
			star -= 2;
		}
	}
	return 0;
}