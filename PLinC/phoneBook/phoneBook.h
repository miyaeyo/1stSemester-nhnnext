/*
* ���α׷��� ���� final project
* PHONE BOOK
* 151008 ���¹�
*
* - instructions-
* PHONE_BOOK.txt������ �̹� ���� �Ǿ� �������, ���Ͽ��� �̸��� ��ȭ��ȣ �����͸� �о���� �� �޴� ����
* 1. insert mode: �̸��� ��ȭ��ȣ ����. �ѹ��� �ϳ��� ���尡��
* 2. delete mode: �̸�, Ȥ�� ��ȭ��ȣ(��ü ��ȭ��ȣ Ȥ�� ��� ���ڸ�, �� ���ڸ��� �˻� ����)�� ���� item�� ã�Ƽ� ����
* 3. modify mode: �̸�, Ȥ�� ��ȭ��ȣ(��ü ��ȭ��ȣ Ȥ�� ��� ���ڸ�, �� ���ڸ��� �˻� ����)�� ������ item�� ã�Ƽ� ����
*                 �̸��� �����ϰ� ���� ��� �̸����� �˻� �ؾ��ϰ�, ��ȭ��ȣ�� �����ϰ� ���� ��� ��ȭ��ȣ�� �˻� �ؾ���
* 4. search mode: �̸�, Ȥ�� ��ȭ��ȣ(��ü ��ȭ��ȣ Ȥ�� ��� ���ڸ�, �� ���ڸ��� �˻� ����)�� �˻�
* 5. print mode: ��ü ��ȭ��ȣ�� ���
* 6. quit: ��ȭ��ȣ�� ���� �� ��ȭ��ȣ�� .txt���� ����(�����̸�: PHONE_BOOK.txt)
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


