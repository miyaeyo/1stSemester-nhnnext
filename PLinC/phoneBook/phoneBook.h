/*
* 프로그래밍 연습 final project
* PHONE BOOK
* 151008 정승미
*
* - instructions-
* PHONE_BOOK.txt파일이 이미 생성 되어 있을경우, 파일에서 이름과 전화번호 데이터를 읽어들인 후 메뉴 실행
* 1. insert mode: 이름과 전화번호 저장. 한번에 하나씩 저장가능
* 2. delete mode: 이름, 혹은 전화번호(전체 전화번호 혹은 가운데 네자리, 끝 네자리로 검색 가능)로 지울 item을 찾아서 지움
* 3. modify mode: 이름, 혹은 전화번호(전체 전화번호 혹은 가운데 네자리, 끝 네자리로 검색 가능)로 수정할 item을 찾아서 수정
*                 이름을 수정하고 싶을 경우 이름으로 검색 해야하고, 전화번호를 수정하고 싶을 경우 전화번호로 검색 해야함
* 4. search mode: 이름, 혹은 전화번호(전체 전화번호 혹은 가운데 네자리, 끝 네자리로 검색 가능)로 검색
* 5. print mode: 전체 전화번호부 출력
* 6. quit: 전화번호부 종료 및 전화번호부 .txt파일 생성(파일이름: PHONE_BOOK.txt)
*
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person
{
	char name[20];
	char phoneNum[20];
}Person;

void insertMode(Person**, int); 
void deleteMode(Person**, int*);
void modifyMode(Person**, int);
void searchMode(Person**, int);
void printMode(Person**, int);
void writeTofile(Person**,int);
int fopenCheck(FILE*);
int getPhonebookData(Person**);
int searchByName(Person**, int, char*);
int searchByPartialPnum(Person**, int, char*); 
int searchByPnum(Person**, int, char*);


