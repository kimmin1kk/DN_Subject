/*	�Է°��� �� �߾��� ���� ����
*   �Է°��� Ȧ���� ��� ���� ���� ���� ¦���� ��� -1
*   ���� 1���� �� 2���� ������.
*/

#include <stdio.h>

int main(void)
{
	int input = 0, spacen = 0, star = 0;
	int x = 0;
	int counts = 0, skip = 1;
	printf("�߾� ���� ������ �����ּ��� : ");
	scanf_s("%d", &input);
	printf("����� �Է��� ���� %d�Դϴ�. \n\n", input);

	if (input % 2 != 0) //Ȧ��
	{
		spacen = input / 2; // spacen�� ������ ���� ����
		star = 1;


		for (int z = 1; z <= input; z++) {

			if (star <= input) { // ���������� �߰�����
				if (x >= 0) {
					for (int x = spacen; x > 0; x--) { //�پ��� ����
						printf(" ");
					}
					spacen--;
					if (spacen == 0)
						x = -1;
				}

				//�þ�� ��. ���� �������� �־�� puts�� �� ���� ���� ���� �߿���
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

			if (counts == (input / 2) + 1) { //�߰� �ؿ������� ������
				spacen = input / 2;
				for (int i = 0; i < skip; i++) { //�þ�� ���� 1 2 3 4 ''' input / 2 ���� ���� ��
					printf(" ");
				}
				if (skip != spacen + 1)
					skip++;
			}
			for (int k = 0; k < star; k++) { //�پ��� ��
				printf("*");
			}
			puts("");
			star -= 2;
		}


		//���⼭ star = input += 2
	}
	else //¦��
	{
		spacen = input / 2 - 1; // spacen�� ������ ���� ����
		star = 1;

		for (int z = 1; z <= input; z++) {

			if (star <= input) { // ���������� �߰�����
				if (x >= 0) {
					for (int x = spacen; x > 0; x--) { //�پ��� ����
						printf(" ");
					}
					spacen--;
					if (spacen == 0)
						x = -1;
				}

				//�þ�� ��. ���� �������� �־�� puts�� �� ���� ���� ���� �߿���
				for (int c = 0; c <= star; c++) {
					printf("*");
				}
				star += 2;
				puts("");
				counts++;
			}
		}
		star = input - 2;
		//�þ�� ���鿡 ���� ���� skip, spacen
		for (int j = 0; j < input / 2;j++) {
			if (counts == input / 2) { //�߰� �ؿ������� ������
				spacen = input / 2;
				for (int i = 0; i < skip; i++) { //�þ�� ���� 1 2 3 4 ''' input / 2 ���� ���� �� Ȧ¦ ����
					printf(" ");
				}
				if (skip != spacen + 1)
					skip++;
			}
			for (int k = 0; k < star; k++) { //�پ��� ��
				printf("*");
			}
			puts("");
			star -= 2;
		}
	}
	return 0;
}