#include <stdio.h>

/* 메모용
일단 4096은 8^4
반복문을 총 4번 씀(1-8로 가는)
좌측상단 끝 1 / 우측하단 끝 4096
for (int i = 0; i < 6; i = i + 5)
V3 망한 이유: 쓰잘데기 없는 변수가 너무 많았다.
			printf("z = %d\t num = %d\t fnum = %d", z, num, fnum);
			puts(""); <-- 오류 보려고 만듬
*/

int main(void)
{
	int num = 1, fnum = 8; // 한 줄에서 시작과 끝 수
	int z = 0;

	for (int v = 1; v <= 8; v++)
	{
		for (int c = 1; c <= 8; c++)
		{
			for (int x = 1; x <= 8; x++)
			{
				for (z = num; z <= fnum; z++)
				{
					printf("%4d\t", z);
				}
				printf("\t\t");
				num += 64; fnum += 64;

			}
			num -= 504; fnum -= 504;
			puts("");
		}
		puts("");
		num += 448, fnum += 448;
	}
	return 0;
}