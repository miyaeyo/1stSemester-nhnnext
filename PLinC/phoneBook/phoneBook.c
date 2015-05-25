#include "phoneBook.h"
/*********************************************main******************************************************/
int main()
{
	Person** person;
	int count;
	person = (Person**)malloc(sizeof(Person*) * 200); // ��ȭ��ȣ�� �ִ� �뷮 200�� 
	if (person == NULL)
	{
		puts("Error\n");
		return -1;
	}
	
	count = getPhonebookData(person); // ����Ǿ� �ִ� ������ �ҷ�����
	puts("����������������������������������INSTRUCTIONS����������������������������������");
	puts("��PHONE_BOOK.txt������ ���� ���, �����͸� �о���� �� �޴� ����       ");
	puts("��1. insert: �̸��� ��ȭ��ȣ ����. �ѹ��� �ϳ��� ���尡��");
	puts("�����̸�, Ȥ�� ��ȭ��ȣ(��ü ��ȭ��ȣ �Ǵ� ��� ���ڸ�, �� ���ڸ�) �˻� ����");
	puts("��2. delete: ���� item�� ã�Ƽ� ����");
	puts("��3. modify: ������ item�� ã�Ƽ� ����");
	puts("��           �̸��� �����ϰ� ���� ��� �̸����� �˻�,");
	puts("��           ��ȭ��ȣ�� �����ϰ� ���� ��� ��ȭ��ȣ�� �˻�");
	puts("��4. search: �̸�, ��ȭ��ȣ �˻�");
	puts("��5. print: ��ü ��ȭ��ȣ�� ���");
	puts("��6. quit: ��ȭ��ȣ�� ���� �� ��ȭ��ȣ�� ���� ����(�����̸�: PHONE_BOOK.txt)");
	puts("��������������������������������������������������������������������������������");

	for (;;)
	{
		char menu[10];
		
		puts("\n******PHONE BOOK******");
		puts("1. INSERT");
		puts("2. DELETE");
		puts("3. MODIFY");
		puts("4. SEARCH");
		puts("5. PRINT");
		puts("6. QUIT");

		printf("Select menu: ");

		gets(menu);
		fflush(stdin);

		if (strcmp(menu, "6") == 0 || _stricmp(menu, "q") == 0 || _stricmp(menu,"quit")==0)
		{
			int i;
			writeTofile(person, count); // �������� ������ ���Ϸ� ����
			for (i = 0; i < count; i++)
			{
				if (person[i] != NULL)
					free(person[i]);
			}
			if (person != NULL)
				free(person);

			break;
		}
			
		else if (strcmp(menu, "1") == 0 || _stricmp(menu, "i") == 0 || _stricmp(menu, "insert") == 0)
		{
			if (count > 200)
			{
				system("cls");
				puts("Excess storage capacity!\n");
			}
			else
			{
				system("cls");
				person[count] = (Person*)malloc(sizeof(Person));
				if (person == NULL)
				{
					free(person);
					puts("Error\n");
					return -1;
				}
				insertMode(person, count);
				count++;	
			}
			
		}
		else if (strcmp(menu, "2") == 0 || _stricmp(menu, "d") == 0 || _stricmp(menu, "delete") == 0)
		{
			system("cls");
			if (count == 0)
				puts("Phone book is empty.");
			else
			{
				int* index = &count;
				deleteMode(person, index);
			}
			
		}
		else if (strcmp(menu, "3") == 0 || _stricmp(menu, "m") == 0 || _stricmp(menu, "modify") == 0)
		{
			system("cls");
			if (count == 0)
				puts("Phone book is empty.");
			else
				modifyMode(person, count);
		}
		else if (strcmp(menu, "4") == 0 || _stricmp(menu, "s") == 0 || _stricmp(menu, "search") == 0)
		{
			system("cls");
			if (count == 0)
				puts("Phone book is empty.");
			else
				searchMode(person, count);
		}
		else if (strcmp(menu, "5") == 0 || _stricmp(menu, "p") == 0 || _stricmp(menu, "print") == 0)
		{
			system("cls");
			printMode(person, count);
		}
		else
		{
			system("cls");
			puts("Please check the phone book menu.");
		}
	}
	return 0;
}
/*********************************************file open check function******************************************************/
int fopenCheck(FILE* fp)
{
	if (fp == NULL)
	{
		puts("file open error\n");
		return -1;
	}

}
/*********************************************get phone book data from PHONE_BOOK.txt file ******************************************************/
int getPhonebookData(Person** person)
{
	FILE* fileptr = NULL;
	
	fileptr = fopen("PHONE_BOOK.txt", "rt");
	
	if (fileptr == NULL)
		return 0;
	else
	{
		int i;
		char dump[50];
		char* token;
		char c;
		for (i = 0; i < 3; i++) // ������ �� 3�ٿ��� ��ȭ��ȣ�� ������ �����Ƿ� ���� �����͸� �ű�� ���� ����
		{
			fgets(dump, 50, fileptr);
		}		

		i = 0;
		while (!feof(fileptr))
		{
			fseek(fileptr, 7, SEEK_CUR); // ���� �����͸� �ű�
			c = fgetc(fileptr); // ���� ������ �ڸ��� - �̸� ��ȭ��ȣ�ΰ� ��������
			if (c == '-')
				break;
			else
			{
				fgets(dump, 50, fileptr); // ���پ� dump�� �ް� �̸��� ��ȭ��ȣ�� �и��ؼ� ����ü�� ����
				person[i] = (Person*)malloc(sizeof(Person));
				if (person == NULL)
				{
					free(person);
					puts("Error\n");
					return -1;
				}
				token = strtok(dump, " \t\n"); 
				strcpy(person[i]->name, token);
				token = strtok(NULL, " \t\n");
				strcpy(person[i]->phoneNum, token);
				i++;
			}
			
		}
		return i;
	}
}
/*********************************************write to file function******************************************************/
void writeTofile(Person** person, int count)
{
	FILE* fileptr;
	int i;
	
	fileptr = fopen("PHONE_BOOK.txt", "wt");
	fopenCheck(fileptr);
	fputs("������������������PHONE BOOK������������������\n", fileptr);
	fputs("�� No.	Name		Phone Number	    \n", fileptr);
	fputs("��------------------------------------------	\n", fileptr);
	
	for (i = 0; i < count; i++)
	{
		fprintf(fileptr, "�� %-5d%-12s	%s	    \n", i + 1, person[i]->name, person[i]->phoneNum);
	}
	fputs("��------------------------------------------	\n", fileptr);
	fputs("����������������������������������������������\n", fileptr);
	fclose(fileptr);
}

/*********************************************insert mode*****************************************************/
void insertMode(Person** person, int count)
{
	puts("\n[INSERT MODE]");

	printf("Name: ");
	gets(person[count]->name);
	fflush(stdin);
	printf("Phone number: ");
	gets(person[count]->phoneNum);
	fflush(stdin);
}
/*********************************************delete mode******************************************************/
void deleteMode(Person** person, int* count)
{
	char smenu[10];
	char sname[20];
	char sphoneNum[20];
	int mark;
	int i;

	for (;;)
	{
		puts("\n[DELETE MODE]");
		puts("Search by 1. NAME or 2. PHONE NUMBER");
		printf("Select menu: ");
		gets(smenu);
		fflush(stdin);
		if (strcmp(smenu, "1") == 0 || _stricmp(smenu, "n") == 0 || _stricmp(smenu, "name") == 0)
		{
			printf("Input name: ");
			gets(sname);
			fflush(stdin);
			mark = searchByName(person, *count, sname); // mark�� count�� �� index���� 
			if (mark == -1)
			{
				puts("It does not exist in this phone book.");
				return;
			}
			else
			{
				for (i = mark; i < *count - 1; i++) // ����� index �޺κ��� ��ĭ�� ������ ���� 
				{
					strcpy(person[i]->name, person[i + 1]->name);
					strcpy(person[i]->phoneNum, person[i + 1]->phoneNum);
				}
				free(person[*count - 1]); // �������� free
				puts("Successfully deleted");
				*count -= 1;
				return;
			}
		}
		else if (strcmp(smenu, "2") == 0 || _stricmp(smenu, "p") == 0 || _stricmp(smenu, "phone number") == 0 || _stricmp(smenu, "phone") == 0 || _stricmp(smenu, "number") == 0)
		{
			int phoneLen;
			printf("Input phone number: ");
			gets(sphoneNum);
			fflush(stdin);
			phoneLen = strlen(sphoneNum);

			if (phoneLen < 5) // ��ȭ��ȣ�� �Ϻκи� �Է��� ���, ��ȭ��ȣ �Է��� -�� �������� �߶� �� 
			{
				mark = searchByPartialPnum(person, *count, sphoneNum);
				if (mark == -1)
				{
					puts("It does not exist in this phone book.");
					return;
				}
				else
				{
					for (i = mark; i < *count - 1; i++)
					{
						strcpy(person[i]->name, person[i + 1]->name);
						strcpy(person[i]->phoneNum, person[i + 1]->phoneNum);
					}
					free(person[*count - 1]);
					puts("Successfully deleted");
					*count -= 1;
					return;
				}


			}
			else // ��ȭ��ȣ ��ü�� �˻��� ���
			{
				mark = searchByPnum(person, *count, sphoneNum);
				if (mark == -1)
				{
					puts("It does not exist in this phone book.");
					return;
				}
				else
				{
					for (i = mark; i < *count - 1; i++)
					{
						strcpy(person[i]->name, person[i + 1]->name);
						strcpy(person[i]->phoneNum, person[i + 1]->phoneNum);
					}
					free(person[*count - 1]);
					puts("Successfully deleted");
					*count -= 1;
					return;
				}
			}
		}
		else
		{
			system("cls");
			puts("Please check the menu.");
		}

	}
}
/*********************************************modify******************************************************/
void modifyMode(Person** person, int count)
{
	char smenu[10];
	char sname[20];
	char sphoneNum[20];
	int mark;

	for (;;)
	{
		puts("\n[MODIFY MODE]");
		puts("Modify the 1. NAME or 2. PHONE NUMBER"); // �̸��� �����ϰ� ������ �̸����ΰ˻�, ��ȭ��ȣ�� �����ϰ� ������ ��ȭ��ȣ�� �˻�
		printf("Select menu: ");
		gets(smenu);
		fflush(stdin);
		if (strcmp(smenu, "1") == 0 || _stricmp(smenu, "n") == 0 || _stricmp(smenu, "name") == 0)
		{
			printf("Input name: ");
			gets(sname);
			fflush(stdin);
			mark = searchByName(person, count, sname); // index �޾ƿ�
			if (mark == -1)
			{
				puts("It does not exist in this phone book.");
				return;
			}
			else
			{
				printf("Input modified name: ");
				gets(person[mark]->name);
				puts("Successfully modified");
				return;
			}
		}
		else if (strcmp(smenu, "2") == 0 || _stricmp(smenu, "p") == 0 || _stricmp(smenu, "phone number") == 0 || _stricmp(smenu, "phone") == 0 || _stricmp(smenu, "number") == 0)
		{
			int phoneLen;
			printf("Input phone number: ");
			gets(sphoneNum);
			fflush(stdin);
			phoneLen = strlen(sphoneNum);

			if (phoneLen < 5) // ��ȭ��ȣ�� �Ϻκи� �Է��� ���, ��ȭ��ȣ �Է��� -�� �������� �߶� �� 
			{
				mark = searchByPartialPnum(person, count, sphoneNum);
				if (mark == -1)
				{
					puts("It does not exist in this phone book.");
					return;
				}
				else
				{
					printf("Input modified phone number: ");
					gets(person[mark]->phoneNum);
					puts("Successfully modified");
					return;
				}
			}
			else // ��ȭ��ȣ ��ü�� �Է��� ���
			{
				mark = searchByPnum(person, count, sphoneNum);
				if (mark == -1)
				{
					puts("It does not exist in this phone book.");
					return;
				}
				else
				{
					printf("Input modified phone number: ");
					gets(person[mark]->phoneNum);
					puts("Successfully modified");
					return;
				}
			}
		}
		else
		{
			system("cls");
			puts("Please check the menu.");
		}
	}
}
/*********************************************search mode******************************************************/
void searchMode(Person** person, int count)
{
	char smenu[10];
	char sname[20];
	char sphoneNum[20];
	int mark;

	for (;;)
	{
		puts("\n[SEARCH MODE]");
		puts("Search by 1. NAME or 2. PHONE NUMBER"); 
		printf("Select menu: ");
		gets(smenu);
		fflush(stdin);
		if (strcmp(smenu, "1") == 0 || _stricmp(smenu, "n") == 0 || _stricmp(smenu, "name") == 0)
		{
			printf("Input name: ");
			gets(sname);
			fflush(stdin);
			mark = searchByName(person, count, sname);
			if (mark == -1)
				puts("It does not exist in this phone book.");
			return;
		}
		else if (strcmp(smenu, "2") == 0 || _stricmp(smenu, "p") == 0 || _stricmp(smenu, "phone number") == 0 || _stricmp(smenu, "phone") == 0 || _stricmp(smenu, "number") == 0)
		{
			int phoneLen;
			printf("Input phone number: ");
			gets(sphoneNum);
			fflush(stdin);
			phoneLen = strlen(sphoneNum);
			
			if (phoneLen < 5) // ��ȭ��ȣ�� �Ϻκи� �Է��� ���, ��ȭ��ȣ �Է��� -�� �������� �߶� �� 
			{
				mark = searchByPartialPnum(person, count, sphoneNum);
				if (mark == -1)
					puts("It does not exist in this phone book.");
				return;
				
			}
			else
			{
				mark = searchByPnum(person, count, sphoneNum);
				if (mark == -1)
					puts("It does not exist in this phone book.");
				return;
			}
		}
		else
		{
			system("cls");
			puts("Please check the menu.");
		}
	}
}
/*********************************************print mode******************************************************/
void printMode(Person** person, int count)
{
	int i;
	puts("������������������PHONE BOOK������������������");
	puts("�� No.	Name		Phone Number	    ");
	puts("��------------------------------------------	");

	for (i = 0; i < count; i++)
	{
		printf("�� %-5d%-12s	%s	    \n", i + 1, person[i]->name, person[i]->phoneNum);
	}
	puts("��------------------------------------------	");
	puts("����������������������������������������������");
}

/*********************************************3 way to search functions******************************************************/
int searchByName(Person** person, int count, char* sname)
{
	char YorN[4];
	int i;

	for (i = 0; i < count; i++)
	{
		if (strcmp(sname, person[i]->name) == 0)
		{
			printf("\n%s %s\n", person[i]->name, person[i]->phoneNum);
			printf("\nIs that the number looking for? (yes or no) ");
			gets(YorN);
			fflush(stdin);
			if (_stricmp(YorN, "y") == 0 || _stricmp(YorN, "yes") == 0)
				return i;
		}
	}
	return -1;
}
int searchByPartialPnum(Person** person, int count, char* sphoneNum) // ��ȭ��ȣ ��� ���ڸ� Ȥ�� �� ���ڸ��� ã��
{
	char YorN[4];
	int i;

	char* token[3];
	for (i = 0; i < count; i++)
	{
		char cpyNum[20];

		strcpy(cpyNum, person[i]->phoneNum);
		token[0] = strtok(cpyNum, " -.~\n");
		token[1] = strtok(NULL, " -.~\n");// ��ȭ��ȣ ��� ���ڸ�
		token[2] = strtok(NULL, " -.~\n");// ��ȭ��ȣ �� ���ڸ�
		if (strncmp(sphoneNum, token[1], 4) == 0 || strncmp(sphoneNum, token[2], 4) == 0)
		{
			printf("\n%s %s\n", person[i]->name, person[i]->phoneNum);
			printf("\nIs that the number looking for? (yes or no) ");
			gets(YorN);
			fflush(stdin);
			if (_stricmp(YorN, "y") == 0 || _stricmp(YorN, "yes") == 0)
				return i;
		}
	}
	return -1;

}
int searchByPnum(Person** person, int count, char* sphoneNum)
{
	char YorN[4];
	int i;

	for (i = 0; i < count; i++)
	{
		if (strcmp(sphoneNum, person[i]->phoneNum) == 0)
		{
			printf("\n%s %s\n", person[i]->name, person[i]->phoneNum);
			printf("\nIs that the number looking for? (yes or no) ");
			gets(YorN);
			fflush(stdin);
			if (_stricmp(YorN, "y") == 0 || _stricmp(YorN, "yes") == 0)
				return i;
		}
	}
	return -1;
}

