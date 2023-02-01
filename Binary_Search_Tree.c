#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc을 쓰기 위함

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
	printf("\n\n전위 순회 : ");
	CLR(head);
	printf("\n\n중위 순회 : ");
	LCR(head);
	printf("\n\n후위 순회 : ");
	LRC(head);
	printf("\n\n");
}
//--------------------------------------------------

void find_node(LINK head) { //중복 검사 및 삭제시 자식 노드의 수까지 체크
	if (head) {
		
		if (head->data == search) { //여긴 한 번만 들린다.
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
		printf("\n숫자를 입력해야 합니다.\n\n");
		rewind(stdin);
		return type_data();
	}
	else {
		search = num;
		match = 0;
		find_node(head);
		if (match == 1) {
			printf("중복된 값입니다. 다시 입력해주세요 : ");
			rewind(stdin);
			return type_data();
		}
	}
	cur = (LINK)malloc(sizeof(NODE));
	cur->data = num;
	cur->left = NULL;
	cur->right = NULL;
}
void input_data() { // 입력한 노드를 연결 but 기존의 수보다 크면 좌로 보내고 아니면 우로 보내야함
	LINK currentNode = head;
	LINK cur = NULL;

	if (head == NULL) { //헤드 생성
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


	printf("\n\n삭제할 데이터를 입력해주세요 :");
	scanf("%d", &search);
	find_node(head);
	find_previous(head);

	if (match == 1) {
		printf("일치하는 데이터가 존재합니다. (삭제)\n\n");//여기다가 조건별 삭제 함수 만들어서 넣으면 됨

		if (child == 0) {//루트 or 리프

			if (current == head) { //루트
				head = NULL;
				return free(current);
			}
			else { //리프
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
		else if (child == 1) { // 루트 or 중간

			if (current == head) { //루트
				if (head->left != NULL) {
					head = head->left;
					return free(current);
				}
				if (head->right != NULL) {
					head = head->right;
					return free(current);
				}
			}
			else { // 중간
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
					printf("에러 발생");
				}
			}
		}
		else if(child == 2) {  // 루트  or 중간
			LINK cur2 = head;
			if (current == head) {//루트
				cur2 = cur2->left;
				while (cur2->right != NULL) {
					cur2 = cur2->right;
				}
				head->data = cur2->data; //cur2가 옮길 위치
				find_previous2(cur2, head);
				if (head->right != previous->right) { //옮길 위치의 이전 위치가 헤드가 아니라면? -> 좌측 노드가 바로 옮길 노드가 아니라면?
						previous->right = cur2->left;
						return free(cur2);
				}
				else {// 옮길 위치의 이전 위치가 헤드라면
					previous->left = cur2->left;
					return free(cur2);
				}
			}
			else { //중간
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
					printf("에러 발생");
				}
			}
		}
		else {
			printf("오류 발생");
		}
	}
	else {
		printf("일치하는 데이터가 존재하지 않습니다.");
	}

}


//------------------------------------------------------------------
int main(void) {
	int i = 0; // while문에서만 사용할 변수

	while (i != 4) {
		current = NULL;
		previous = NULL;
		printf("-------------------------------\n");
		printf("| 1.입력 2.출력 3.삭제 4.종료 |\n");
		printf("-------------------------------\n");
		printf("실행할 번호를 입력하세요 :");

		if (scanf_s("%d", &i) == 0) {
			printf("\n숫자를 입력해야 합니다.\n\n");
			rewind(stdin);
			continue;
		}

		switch (i) {
		case 1:
			printf("\n입력\n\n");
			input_data();
			break;
		case 2:
			print_all();
			break;
		case 3:
			delete_data();
			break;
		case 4:
			printf("\n프로그램을 종료합니다.\n\n");
			break;
		default:
			printf("\n잘못된 값을 입력하셨습니다.\n\n");
			break;
		}
	}
	return 0;
}