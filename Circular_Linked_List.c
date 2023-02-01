#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc�� ���� ����

struct NODE {
	int data;
	struct NODE* link;
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
		printf("\n�ߺ��� �������Դϴ� �ٸ� ���� �Է����ּ���.\n");
		return 0;
	}
	else {
		cur = (LINK)malloc(sizeof(NODE));
		cur->data = num;
		cur->link = NULL;
		cnt++;
		return cur;
	}


}
void input_data() { // �Է��� ��带 ����
	LINK currentNode = head;

	if (head == NULL) {
		head = type_data();
		head->link = head;
		return;
	}
	else {
	while (currentNode->link != head) {
			currentNode = currentNode->link;
		}
		currentNode->link = type_data();
		currentNode->link->link = head;
		return;


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
		while (printNode->link != head) {
			printf("%d ", printNode->data);
			printNode = printNode->link;
			if (printNode->data == head->data) {
				return;
			}
		}
		printf("%d ", printNode->data);
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
		while (searchNode->link != head) {

			if (searchNode->data == a) {
				return match = 1;
			}
			else {
				searchNode = searchNode->link;
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

void delete_first(int a) {
	LINK data1 = head;
	LINK data2 = head;

	while (data2->link != head) {
		data2 = data2->link;
	}


	head = data1->link;
	data2->link = head;

	cnt--;

	if (cnt == 0) {
		head = NULL;
	}
	free(data1);
}
void delete_middle(int a) { 
	LINK data1 = head;
	LINK data2;
	for (int i = 1; i < location; i++) {
		data1 = data1->link;
	}
	data2 = data1->link;
	data1->link = data1->link->link;
	cnt--;

	if (cnt == 0) {
		head = NULL;
	}
	free(data2);
}
void delete_end(int a) { 
	LINK data1 = head;
	LINK data2;
	while (data1->link->link != head) {
		data1 = data1->link;
	}
	data2 = data1->link;
	data1->link = head;
	cnt--;

	if (cnt == 0) {
		head = NULL;
	}
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
			printf("'�Դϴ�.\n\n");
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