#include <stdio.h>

/* �޸��
�ϴ� 4096�� 8^4
�ݺ����� �� 4�� ��(1-8�� ����)
������� �� 1 / �����ϴ� �� 4096
for (int i = 0; i < 6; i = i + 5)
V3 ���� ����: ���ߵ��� ���� ������ �ʹ� ���Ҵ�.
			printf("z = %d\t num = %d\t fnum = %d", z, num, fnum);
			puts(""); <-- ���� ������ ����
*/

int main(void)
{
	int num = 1, fnum = 8; // �� �ٿ��� ���۰� �� ��
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