#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct personscore
{
	int number;
	char name[40];
	int mid;
	int final;
	int quiz;
};
typedef struct personscore pscore;

int main() {
	char fname[] = "score.bin";
	FILE* f;


	//�Է� 
	if (fopen_s(&f, fname, "wb") != 0)
	{
		printf("������ ������ x ");
		exit(1);
	};

	char line[80];
	int cnt = 0;
	pscore score;
	printf("�̸��� ����(�߰�, �⸻, ����) �Է��ض�");
	
	fgets(line, 80, stdin);
	while (!feof(stdin))
	{
		sscanf_s(line, "%s %d %d %d", score.name, 40,
			&score.mid, &score.final, &score.quiz);
		score.number = cnt++;
		fwrite(&score, sizeof(pscore), 1, f);
		fgets(line, 80, stdin);
	}
	fclose(f);









	//// malloc ����
	//int Value = 1;

	//scanf("%d", &Value);

	//int *numPtr = malloc(sizeof(int) * Value);
	//// (int ũ�� * �Է¹��� ũ��)��ŭ ���� �޸� �Ҵ�

	//for (int i = 0; i < Value; i++) {
	//	numPtr[i] = i;
	//}
	//for (int i = 0; i < Value; i++) {
	//	printf("%d\n", numPtr[i]);
	//}

	//free(numPtr); //�����Ҵ� �޸� ����







	return 0;
}