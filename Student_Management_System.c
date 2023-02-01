#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc�� ���� ����
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
		printf("* 1.�Է� 2.��� 3.�˻� 4.���� 5.���� 6.�ε� 7.���� *\n");
		printf("****************************************************\n");
		printf("������ ��ȣ�� �Է��ϼ��� :");
		if (scanf_s("%d", &i) == 0) {
			printf("\n���ڸ� �Է��ؾ� �մϴ�.\n\n");
			rewind(stdin);
			continue;
		}

		switch (i) {

		case 1:
			/*s = (_Student*)malloc(sizeof(_Student) * num);*/
			;int cnt2 = 0, pass = 0;
			num++;

			while (num >= 1) {
				printf("\n�й��� �Է��ϼ��� :");
				scanf("%d", &s[num].id);
				for (int j = 1; j < num; j++) {
					if (s[num].id == s[j].id) {
						printf("\n�ߺ��� �й��Դϴ�. �ٽ� �Է����ּ��� : ");
						scanf("%d", &s[num].id);
						j = 0;

					}
				}
				break;
			}
			printf("\n�̸��� �Է��ϼ��� :");
			scanf("%s", s[num].name);

			printf("\n���� ������ �Է��ϼ��� :");
			scanf("%d", &s[num].kScore);

			while (s[num].kScore > 100) {
				printf("�ִ� ������ 100���Դϴ�.\n");
				printf("\n���� ������ �Է��ϼ��� :");
				scanf("%d", &s[num].kScore);
			}
			printf("\n���� ������ �Է��ϼ��� :");
			scanf("%d", &s[num].mScore);
			while (s[num].mScore > 100) {
				printf("�ִ� ������ 100���Դϴ�.\n");
				printf("\n���� ������ �Է��ϼ��� :");
				scanf("%d", &s[num].mScore);
			}
			printf("\n���� ������ �Է��ϼ��� :");
			scanf("%d", &s[num].eScore);
			while (s[num].eScore > 100) {
				printf("�ִ� ������ 100���Դϴ�.\n");
				printf("\n���� ������ �Է��ϼ��� :");
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
				} //���� ���� �Ϸ�
			}
			puts("");
			for (int i = 1; i <= num; i++) {

				printf("�й� : %d | �̸� : %s | ���� : %d | ���� : %d | ���� : %d | ���� : %d | ��� : %d\n",
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
			printf("�˻��� �й��� �Է����ּ��� :");
			scanf("%d", &search);
			for (int i = 0; i <= num; i++) {
				if (search == s[i].id) {
					printf("\n�й� : %d | �̸� : %s | ���� : %d | ���� : %d | ���� : %d | ���� : %d | ��� : %d\n",
						s[i].id, s[i].name, s[i].kScore, s[i].mScore, s[i].eScore, s[i].sScore, s[i].aScore);
					puts("");
					break;
				}
				if (i == num) {
					printf("\nã���ô� ������ ã�� �� �����ϴ�.\n");
					break;
				}
			}
			break;
		case 4:
			puts("");
			int delete = 0;
			printf("������ �л��� �й��� �Է��ϼ��� :");
			scanf("%d", &search);
			for (int i = 0; i <= num; i++) {
				delete++;
				if (search == s[i].id) {

					if (delete == num + 1) {
						delete++;
					}
					break;

				}
			} //delete ++ ���ֱ� ���ؼ� ���� �ݺ��� delete�� ������ �迭�� �ε���
			//��ġ�ϴ°� ���ٸ� delete�� i�� ��������, 

			if (delete-1 != num) { //���� 1���� ����

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
				printf("\n�����Ǿ����ϴ�.");
				puts("");
				break;
			}
			else {
				printf("\n��ȿ���� ���� �й��Դϴ�.\n");
				break;
			}
		case 5:
			fpw = fopen("students.txt", "w");
			for (int i = 1; i <= num; i++) {
				fprintf(fpw, "%d %s %d %d %d %d %d\n", s[i].id, s[i].name, s[i].kScore, s[i].mScore, s[i].eScore, s[i].sScore, s[i].aScore);
			};
			fclose(fpw);
			printf("\n ���� �Ǿ����ϴ�.y\n");
			break;
		case 6:
			fpr = fopen("students.txt", "rt");
			load_Num = 0; //load_Num�� �ε��� �迭��ŭ ������� �ϱ� ������ ī���� �ϴ� ��
			num = 0; //num�� 0�� �� ���� -> ���� ����� ���� ���� �迭 ī���� �ʱ�ȭ 

			for (int i = 1; i <= SIZE; i++) {
				load_Num++;

				fscanf(fpr, "%d %s %d %d %d %d %d\n", &(load[i].id), load[i].name, &(load[i].kScore), &(load[i].mScore), &(load[i].eScore), &(load[i].sScore), &(load[i].aScore));
				if ((load[i].id) == 0) {
					break;
				}

				//printf("%d %s %d %d %d %d %d\n", load[i].id, load[i].name, load[i].kScore, load[i].mScore, load[i].eScore, load[i].sScore, load[i].aScore);
			}
			for (int j = 1; j < load_Num;j++) {
				num++; //���⼭ ���� �迭�� ī������ �ƴ� ����ŭ ī����
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
			printf("\n�ε� �Ǿ����ϴ�.\n");
			break;
		case 7:
			printf("\n�ý����� �����մϴ�.\n");
			break;
		default:
			printf("\n�߸��� ���� �Է��ϼ̽��ϴ�.\n");
			break;
		}
	}
	return 0;
}