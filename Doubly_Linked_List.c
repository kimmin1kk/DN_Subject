#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc�� ���� ����

struct NODE {
	int data;
	struct NODE* lLink;
	struct NODE* rLink;

};
typedef struct NODE NODE;
typedef struct NODE* LINK;

LINK head = NULL;
int cnt = 0; // cnt�� �������� �ƴ��� Ȯ���� ���� ��
int location = 0; // ������ �� ������

//--------------------------------------------------------------
LINK type_data() { // �Է�
	LINK cur = NULL;
	int num = 0;
	scanf("%d", &num);

	if (search_data(num) == 1) {
		printf("\n�ߺ��� �������Դϴ� �ٸ� ���� �Է����ּ��� : ");
		return type_data();
	}
	else {
		cur = (LINK)malloc(sizeof(NODE));
		cur->data = num;
		cur->lLink = NULL;
		cur->rLink = NULL;
		cnt++;
		return cur;
	}


}
void input_data() { // �Է��� ��带 ����
	LINK currentNode = head;
	LINK pastNode = head;

	if (head == NULL) {
		head = type_data();
		return;
	}

	while (currentNode->rLink != NULL) {
		currentNode = currentNode->rLink;
		currentNode->lLink = pastNode;
		pastNode = pastNode->rLink;
	}
	currentNode->rLink = type_data();
	currentNode = currentNode->rLink;
	//pastNode = pastNode->rLink;



	if (currentNode->rLink == NULL) {
		currentNode->lLink = pastNode;
	}

	
}

//-------------------------------------------------------------- 
void print_data() { // ����Ʈ ���

	LINK printNode = head;

	if (cnt == 0) {
		printf("\n���� �Էµ� �����Ͱ� �����ϴ�.\n\n");
	}
	else {
		printf("\n���� �Էµ� �����ʹ�' ");
		while (printNode->rLink != NULL) {
			printf("%d ", printNode->data);
			printNode = printNode->rLink;
		}
		printf("%d ", printNode->data);
		printf("'�Դϴ�. (rLink����)\n\n");

		printf("\n���� �Էµ� �����ʹ�' ");
		while (printNode->lLink != NULL) {
			printf("%d ", printNode->data);
			printNode = printNode->lLink;
		}
		printf("%d ", printNode->data);
		printf("'�Դϴ�. (lLink����)\n\n");
	}
}
//--------------------------------------------------------------
int search_data(int a) { //�˻� but �������� �̿��� �� �ߺ� �˻翡�� ��.
	int match = 0;
	location = 0; //������
	LINK searchNode = head;

	if (cnt == 0) {

	}
	else {
		while (searchNode->rLink != NULL) {

			if (searchNode->data == a) {
				return match = 1;
			}
			else {
				searchNode = searchNode->rLink;
				location++;
			}
		}

		if (searchNode->data == a) {
			location++;
			return match = 1;
		}
	}
	return match;
}
//--------------------------------------------------------------

void delete_first(int a) {// 
	LINK data1 = head;
	if (cnt != 1) {
	data1->rLink->lLink = NULL;
	}

	head = data1->rLink;	
	//data1->rLink = data1->rLink->rLink;
	cnt--;
	free(data1);
	if (cnt == 0) {
		head = NULL;
	}

}
void delete_middle(int a) { //
	LINK data1 = head;
	LINK data2;
	for (int i = 1; i < location; i++) {
		data1 = data1->rLink;
	}
	data2 = data1->rLink;
	data1->rLink = data1->rLink->rLink;
	data1->rLink->lLink = data1;
	cnt--;
	free(data2);
}
void delete_end(int a) { //
	LINK data1 = head;
	LINK data2;
	while (data1->rLink->rLink != NULL) {
		data1 = data1->rLink;
	}
	data2 = data1->rLink;
	data1->rLink = NULL;
	cnt--;
	free(data2);
}

int main(void) {

	int i = 0; // while�������� ����� ����
	int searchNum = 0;


	while (i != 5) {

		printf("--------------------------------------\n");
		printf("| 1.�Է� 2.��� 3.�˻� 4.���� 5.���� |\n");
		printf("--------------------------------------\n");
		printf("������ ��ȣ�� �Է��ϼ��� :");

		if (scanf_s("%d", &i) == 0) {
			printf("\n���ڸ� �Է��ؾ� �մϴ�.\n\n");
			rewind(stdin);
			continue;
		}

		switch (i) {
		case 1: //�Է�
			printf("�����͸� �Է��ϼ��� : ");
			input_data();
			break;

		case 2:
			print_data();
			break;

		case 3:

			printf("\n�˻��� �����͸� �Է����ּ��� :");
			scanf("%d", &searchNum);

			if (search_data(searchNum) == 1) {
				printf("\n�˻��Ͻ� �����ʹ� �����մϴ�.\n");
			}
			else {
				printf("\n�˻��Ͻ� �����ʹ� �������� �ʽ��ϴ�.\n");
			}
			break;

		case 4:
			printf("\n������ �����͸� �Է����ּ��� : \n");
			scanf("%d", &searchNum);

			if (search_data(searchNum) == 1) {

				if (location == 0) { //ó��
					delete_first(searchNum);
				}
				else if (location == cnt) { //��

					if (location == 1) {
						delete_first(searchNum);
						break;
					}
					delete_end(searchNum);
				}
				else { //�߰�
					delete_middle(searchNum);
				}

				printf("\n �����͸� �����߽��ϴ� \n");
			}
			else {
				printf("\n������ �����Ͱ� �������� �ʽ��ϴ�.\n");
			}

			break;

		case 5:
			printf("\n���α׷��� �����մϴ�.\n");
			break;

		default:
			printf("\n�߸��� ���� �Է��ϼ̽��ϴ�.\n");
			break;

		}
	}
	return 0;
}