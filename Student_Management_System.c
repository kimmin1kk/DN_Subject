#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc을 쓰기 위함
#define SIZE 100

typedef struct Student {
	int id;
	char name[12];
	int kScore;
	int mScore;
	int eScore;
	int sScore;
	int aScore;
}_Student;
_Student s[100];
_Student load[100];
_Student temp2[100];

int sumScore(int a, int b, int c) {
	int sum = a + b + c;
	return (sum);
}

int avgScore(int a, int b, int c) {
	int sum = a + b + c;
	int avg = sum / 3;
	return (avg);
}

int main(void) {
	int i = 0, num = 0, cnt = 0, load_Num = 0;
	_Student temp1;

	int search = 0;

	FILE* fpw;
	FILE* fpr;

	while (i != 7) {

		printf("****************************************************\n");
		printf("* 1.입력 2.출력 3.검색 4.삭제 5.저장 6.로드 7.종료 *\n");
		printf("****************************************************\n");
		printf("실행할 번호를 입력하세요 :");
		if (scanf_s("%d", &i) == 0) {
			printf("\n숫자를 입력해야 합니다.\n\n");
			rewind(stdin);
			continue;
		}

		switch (i) {

		case 1:
			/*s = (_Student*)malloc(sizeof(_Student) * num);*/
			;int cnt2 = 0, pass = 0;
			num++;

			while (num >= 1) {
				printf("\n학번을 입력하세요 :");
				scanf("%d", &s[num].id);
				for (int j = 1; j < num; j++) {
					if (s[num].id == s[j].id) {
						printf("\n중복된 학번입니다. 다시 입력해주세요 : ");
						scanf("%d", &s[num].id);
						j = 0;

					}
				}
				break;
			}
			printf("\n이름을 입력하세요 :");
			scanf("%s", s[num].name);

			printf("\n국어 점수를 입력하세요 :");
			scanf("%d", &s[num].kScore);

			while (s[num].kScore > 100) {
				printf("최대 점수는 100점입니다.\n");
				printf("\n국어 점수를 입력하세요 :");
				scanf("%d", &s[num].kScore);
			}
			printf("\n수학 점수를 입력하세요 :");
			scanf("%d", &s[num].mScore);
			while (s[num].mScore > 100) {
				printf("최대 점수는 100점입니다.\n");
				printf("\n수학 점수를 입력하세요 :");
				scanf("%d", &s[num].mScore);
			}
			printf("\n영어 점수를 입력하세요 :");
			scanf("%d", &s[num].eScore);
			while (s[num].eScore > 100) {
				printf("최대 점수는 100점입니다.\n");
				printf("\n영어 점수를 입력하세요 :");
				scanf("%d", &s[num].eScore);
			}
			s[num].sScore = sumScore(s[num].kScore, s[num].mScore, s[num].eScore);
			s[num].aScore = avgScore(s[num].kScore, s[num].mScore, s[num].eScore);
			break;
		case 2:
			temp1;
			int j = 0;
			for (int i = 1; i <= num; i++) {

				for ( j = 1; j <= num; j++) {
					if (s[j].sScore < s[j + 1].sScore) {
						temp1 = s[j];
						s[j] = s[j + 1];
						s[j + 1] = temp1;
					}
					else {
						continue;
					}
				} //버블 정렬 완료
			}
			puts("");
			for (int i = 1; i <= num; i++) {

				printf("학번 : %d | 이름 : %s | 국어 : %d | 수학 : %d | 영어 : %d | 총합 : %d | 평균 : %d\n",
					s[i].id, s[i].name, s[i].kScore, s[i].mScore, s[i].eScore, s[i].sScore, s[i].aScore);

				if (i == num) {
					puts("");
					break;
				}
			}
			break;

		case 3:
			search = 0;
			puts("");
			printf("검색할 학번을 입력해주세요 :");
			scanf("%d", &search);
			for (int i = 0; i <= num; i++) {
				if (search == s[i].id) {
					printf("\n학번 : %d | 이름 : %s | 국어 : %d | 수학 : %d | 영어 : %d | 총합 : %d | 평균 : %d\n",
						s[i].id, s[i].name, s[i].kScore, s[i].mScore, s[i].eScore, s[i].sScore, s[i].aScore);
					puts("");
					break;
				}
				if (i == num) {
					printf("\n찾으시는 정보를 찾을 수 없습니다.\n");
					break;
				}
			}
			break;
		case 4:
			puts("");
			int delete = 0;
			printf("삭제할 학생의 학번을 입력하세요 :");
			scanf("%d", &search);
			for (int i = 0; i <= num; i++) {
				delete++;
				if (search == s[i].id) {

					if (delete == num + 1) {
						delete++;
					}
					break;

				}
			} //delete ++ 해주기 위해서 만든 반복문 delete는 삭제할 배열의 인덱스
			//일치하는게 없다면 delete와 i가 동일해짐, 

			if (delete-1 != num) { //넘은 1부터 시작

				for (int i = delete; i <= num; i++) {
					s[i - 1].id = s[i].id;
					strcpy(s[i - 1].name, s[i].name);
					s[i - 1].kScore = s[i].kScore;
					s[i - 1].mScore = s[i].mScore;
					s[i - 1].eScore = s[i].eScore;
					s[i - 1].sScore = s[i].sScore;
					s[i - 1].aScore = s[i].aScore;
				}
				num--;
				if (num == 0) {
					
					for (int j = 1; j <= 99; j++) {
						s[j].id = temp2[j].id;
						strcpy(s[j].name, temp2[j].name);
						s[j].kScore = temp2[j].kScore;
						s[j].mScore = temp2[j].mScore;
						s[j].eScore = temp2[j].eScore;
						s[j].sScore = temp2[j].sScore;
						s[j].aScore = temp2[j].aScore;
					}
				}
				printf("\n삭제되었습니다.");
				puts("");
				break;
			}
			else {
				printf("\n유효하지 않은 학번입니다.\n");
				break;
			}
		case 5:
			fpw = fopen("students.txt", "w");
			for (int i = 1; i <= num; i++) {
				fprintf(fpw, "%d %s %d %d %d %d %d\n", s[i].id, s[i].name, s[i].kScore, s[i].mScore, s[i].eScore, s[i].sScore, s[i].aScore);
			};
			fclose(fpw);
			printf("\n 저장 되었습니다.y\n");
			break;
		case 6:
			fpr = fopen("students.txt", "rt");
			load_Num = 0; //load_Num은 로드한 배열만큼 덮어씌워야 하기 때문에 카운팅 하는 것
			num = 0; //num을 0로 둔 이유 -> 덮어 씌우기 위해 원래 배열 카운팅 초기화 

			for (int i = 1; i <= SIZE; i++) {
				load_Num++;

				fscanf(fpr, "%d %s %d %d %d %d %d\n", &(load[i].id), load[i].name, &(load[i].kScore), &(load[i].mScore), &(load[i].eScore), &(load[i].sScore), &(load[i].aScore));
				if ((load[i].id) == 0) {
					break;
				}

				//printf("%d %s %d %d %d %d %d\n", load[i].id, load[i].name, load[i].kScore, load[i].mScore, load[i].eScore, load[i].sScore, load[i].aScore);
			}
			for (int j = 1; j < load_Num;j++) {
				num++; //여기서 원래 배열의 카운팅이 아닌 덮어씌운만큼 카운팅
				s[j].id = load[j].id;
				strcpy(s[j].name, load[j].name);
				s[j].kScore = load[j].kScore;
				s[j].mScore = load[j].mScore;
				s[j].eScore = load[j].eScore;
				s[j].sScore = load[j].sScore;
				s[j].aScore = load[j].aScore;
				//printf("%d %s %d %d %d %d %d\n", s[j].id, s[j].name, s[j].kScore, s[j].mScore, s[j].eScore, s[j].sScore, s[j].aScore);
				//printf("%d %s %d %d %d %d %d\n", load[j].id, load[j].name, load[j].kScore, load[j].mScore, load[j].eScore, load[j].sScore, load[j].aScore);
			}
			fclose(fpr);
			printf("\n로드 되었습니다.\n");
			break;
		case 7:
			printf("\n시스템을 종료합니다.\n");
			break;
		default:
			printf("\n잘못된 값을 입력하셨습니다.\n");
			break;
		}
	}
	return 0;
}