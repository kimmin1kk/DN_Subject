#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc�� ���� ����

struct NODE {
	int data;
	struct NODE* left;
	struct NODE* right;
};
typedef struct NODE NODE;
typedef struct NODE* LINK;

LINK head = NULL;
LINK current = NULL;
LINK previous = NULL;


int search = 0;
int match = 0;
int child = 0;
//--------------------------------------------------

void CLR(LINK head) {
	if (head) {
		printf("%d ", head->data);
		CLR(head->left);
		CLR(head->right);
	}
}
void LCR(LINK head) {
	if (head) {
		LCR(head->left);
		printf("%d ", head->data);
		LCR(head->right);
	}
}

void LRC(LINK head) {
	if (head) {
		LRC(head->left);
		LRC(head->right);
		printf("%d ", head->data);
	}
}

void print_all() {
	printf("\n\n���� ��ȸ : ");
	CLR(head);
	printf("\n\n���� ��ȸ : ");
	LCR(head);
	printf("\n\n���� ��ȸ : ");
	LRC(head);
	printf("\n\n");
}
//--------------------------------------------------

void find_node(LINK head) { //�ߺ� �˻� �� ������ �ڽ� ����� ������ üũ
	if (head) {
		
		if (head->data == search) { //���� �� ���� �鸰��.
			current = head;
			match = 1;
			if (head->left != NULL && head->right != NULL) {
				child = 2;
			}
			else if (head->right != NULL && head->left == NULL || head->left && head->right == NULL) {
				child = 1;
			}
			else {
				child = 0;
			}
		}
		find_node(head->left);
		find_node(head->right);
	}
}



LINK type_data() {

	LINK cur = NULL;
	int num = 0;
	
	if (scanf_s("%d", &num) == 0) {
		printf("\n���ڸ� �Է��ؾ� �մϴ�.\n\n");
		rewind(stdin);
		return type_data();
	}
	else {
		search = num;
		match = 0;
		find_node(head);
		if (match == 1) {
			printf("�ߺ��� ���Դϴ�. �ٽ� �Է����ּ��� : ");
			rewind(stdin);
			return type_data();
		}
	}
	cur = (LINK)malloc(sizeof(NODE));
	cur->data = num;
	cur->left = NULL;
	cur->right = NULL;
}
void input_data() { // �Է��� ��带 ���� but ������ ������ ũ�� �·� ������ �ƴϸ� ��� ��������
	LINK currentNode = head;
	LINK cur = NULL;

	if (head == NULL) { //��� ����
		head = type_data();
		return;
	}

	cur = type_data();
	int stop = 0;
	while (stop != 1) {
		if (cur->data < currentNode->data) {

			if (currentNode->left == NULL) {
				currentNode->left = cur;
				return;
			}
			else {
				currentNode = currentNode->left;
			}

		}

		if (cur->data > currentNode->data) {

			if (currentNode->right == NULL) {
				currentNode->right = cur;
				return;
			}
			else {
				currentNode = currentNode->right;
			}
		}
	}
}
//------------------------------------------------------------------

void find_previous(LINK head) {
	if (head) {
		if (head->left == current || head->right == current) {
			return previous = head;
		}
		find_previous(head->left);
		find_previous(head->right);
	}
}

void find_previous2(LINK a,LINK head) {
	if (head) {
		if (head->left == a || head->right == a) {
			return previous = head;
		}
		find_previous2(a, head->left);
		find_previous2(a, head->right);

	}
}


void delete_data() {
	match = 0;
	search = 0;
	child = 0;


	printf("\n\n������ �����͸� �Է����ּ��� :");
	scanf("%d", &search);
	find_node(head);
	find_previous(head);

	if (match == 1) {
		printf("��ġ�ϴ� �����Ͱ� �����մϴ�. (����)\n\n");//����ٰ� ���Ǻ� ���� �Լ� ���� ������ ��

		if (child == 0) {//��Ʈ or ����

			if (current == head) { //��Ʈ
				head = NULL;
				return free(current);
			}
			else { //����
				if (previous->left == current) {
					previous->left = NULL;
					return free(current);
				}
				else if (previous->right == current) {
					previous->right = NULL;
					return free(current);
				}
			}
		}
		else if (child == 1) { // ��Ʈ or �߰�

			if (current == head) { //��Ʈ
				if (head->left != NULL) {
					head = head->left;
					return free(current);
				}
				if (head->right != NULL) {
					head = head->right;
					return free(current);
				}
			}
			else { // �߰�
				if (previous->left == current) {

					if (current->left != NULL) {
						previous->left = current->left;
						return free(current);

					}
					if (current->right != NULL) {
						previous->left = current->right;
						return free(current);
					}
				}
				else if (previous->right == current) {
					if (current->left != NULL) {
						previous->right = current->left;
						return free(current);

					}
					if (current->right != NULL) {
						previous->right = current->right;
						return free(current);
					}
				}
				else {
					printf("���� �߻�");
				}
			}
		}
		else if(child == 2) {  // ��Ʈ  or �߰�
			LINK cur2 = head;
			if (current == head) {//��Ʈ
				cur2 = cur2->left;
				while (cur2->right != NULL) {
					cur2 = cur2->right;
				}
				head->data = cur2->data; //cur2�� �ű� ��ġ
				find_previous2(cur2, head);
				if (head->right != previous->right) { //�ű� ��ġ�� ���� ��ġ�� ��尡 �ƴ϶��? -> ���� ��尡 �ٷ� �ű� ��尡 �ƴ϶��?
						previous->right = cur2->left;
						return free(cur2);
				}
				else {// �ű� ��ġ�� ���� ��ġ�� �����
					previous->left = cur2->left;
					return free(cur2);
				}
			}
			else { //�߰�
				LINK cur2 = current;
				if (previous->left == current) {
					current = current->left;
					while (current->right != NULL) {
						current = current->right;
					}
					previous->left = current;
					previous->left->right = cur2->right;
					free(cur2);

				}
				else if (previous->right == current) {
					current = current->left;
					while (current->right != NULL) {
						current = current->right;
					}
					previous->right = current;
					previous->right->left = current->left;
					if (cur2->right != NULL) {
						previous->right->right = cur2->right;
					}
					free(cur2);
				}
				else {
					printf("���� �߻�");
				}
			}
		}
		else {
			printf("���� �߻�");
		}
	}
	else {
		printf("��ġ�ϴ� �����Ͱ� �������� �ʽ��ϴ�.");
	}

}


//------------------------------------------------------------------
int main(void) {
	int i = 0; // while�������� ����� ����

	while (i != 4) {
		current = NULL;
		previous = NULL;
		printf("-------------------------------\n");
		printf("| 1.�Է� 2.��� 3.���� 4.���� |\n");
		printf("-------------------------------\n");
		printf("������ ��ȣ�� �Է��ϼ��� :");

		if (scanf_s("%d", &i) == 0) {
			printf("\n���ڸ� �Է��ؾ� �մϴ�.\n\n");
			rewind(stdin);
			continue;
		}

		switch (i) {
		case 1:
			printf("\n�Է�\n\n");
			input_data();
			break;
		case 2:
			print_all();
			break;
		case 3:
			delete_data();
			break;
		case 4:
			printf("\n���α׷��� �����մϴ�.\n\n");
			break;
		default:
			printf("\n�߸��� ���� �Է��ϼ̽��ϴ�.\n\n");
			break;
		}
	}
	return 0;
}