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


	//입력 
	if (fopen_s(&f, fname, "wb") != 0)
	{
		printf("파일이 열리지 x ");
		exit(1);
	};

	char line[80];
	int cnt = 0;
	pscore score;
	printf("이름과 성적(중간, 기말, 퀴즈) 입력해라");
	
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









	//// malloc 사용법
	//int Value = 1;

	//scanf("%d", &Value);

	//int *numPtr = malloc(sizeof(int) * Value);
	//// (int 크기 * 입력받은 크기)만큼 동적 메모리 할당

	//for (int i = 0; i < Value; i++) {
	//	numPtr[i] = i;
	//}
	//for (int i = 0; i < Value; i++) {
	//	printf("%d\n", numPtr[i]);
	//}

	//free(numPtr); //동적할당 메모리 해제







	return 0;
}