#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc을 쓰기 위함

struct NODE {
	int data;
	struct NODE* link;
};
typedef struct NODE NODE;
typedef struct NODE* LINK;

LINK head = NULL;
int cnt = 0; // cnt는 공백인지 아닌지 확인할 때만 씀
int location = 0; // 삭제할 때 쓰려고




//--------------------------------------------------------------
LINK type_data() { // 입력
	LINK cur = NULL;
	int num = 0;

	scanf("%d", &num);


	if (search_data(num) == 1) {
		printf("\n중복된 데이터입니다 다른 값을 입력해주세요.\n");
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
void input_data() { // 입력한 노드를 연결
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
void print_data() { // 리스트 출력

	LINK printNode = head;

	if (cnt == 0) {
		printf("\n현재 입력된 데이터가 없습니다.\n\n");
	}
	else {
		printf("\n현재 입력된 데이터는' ");
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
int search_data(int a) { //검색 but 삭제에도 이용할 것 중복 검사에도 씀.
	int match = 0;
	location = 0; //삭제용
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

	int i = 0; // while문에서만 사용할 변수
	int searchNum = 0;


	while (i != 5) {

		printf("--------------------------------------\n");
		printf("| 1.입력 2.출력 3.검색 4.삭제 5.종료 |\n");
		printf("--------------------------------------\n");
		printf("실행할 번호를 입력하세요 :");

		if (scanf_s("%d", &i) == 0) {
			printf("\n숫자를 입력해야 합니다.\n\n");
			rewind(stdin);
			continue;
		}

		switch (i) {
		case 1: //입력
			printf("데이터를 입력하세요 : ");
			input_data();
			break;

		case 2:
			print_data();
			printf("'입니다.\n\n");
			break;

		case 3:

			printf("\n검색할 데이터를 입력해주세요 :");
			scanf("%d", &searchNum);

			if (search_data(searchNum) == 1) {
				printf("\n검색하신 데이터는 존재합니다.\n");
			}
			else {
				printf("\n검색하신 데이터는 존재하지 않습니다.\n");
			}
			break;

		case 4:
			printf("\n삭제할 데이터를 입력해주세요 : \n");
			scanf("%d", &searchNum);

			if (search_data(searchNum) == 1) {

				if (location == 0) { //처음
					delete_first(searchNum);
				}
				else if (location == cnt) { //끝

					if (location == 1) {
						delete_first(searchNum);
						break;
					}
					delete_end(searchNum);
				}
				else { //중간
					delete_middle(searchNum);
				}

				printf("\n 데이터를 삭제했습니다 \n");
			}
			else {
				printf("\n삭제할 데이터가 존재하지 않습니다.\n");
			}


			break;

		case 5:
			printf("\n프로그램을 종료합니다.\n");
			break;

		default:
			printf("\n잘못된 값을 입력하셨습니다.\n");
			break;

		}
	}
	return 0;
}