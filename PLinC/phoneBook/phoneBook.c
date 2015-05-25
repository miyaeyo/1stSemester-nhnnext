#include "phoneBook.h"
/*********************************************main******************************************************/
int main()
{
	Person** person;
	int count;
	person = (Person**)malloc(sizeof(Person*) * 200); // 전화번호부 최대 용량 200명 
	if (person == NULL)
	{
		puts("Error\n");
		return -1;
	}
	
	count = getPhonebookData(person); // 저장되어 있는 데이터 불러들임
	puts("┏━━━━━━━━━━━━━━━━INSTRUCTIONS━━━━━━━━━━━━━━━━┓");
	puts("┃PHONE_BOOK.txt파일이 있을 경우, 데이터를 읽어들인 후 메뉴 실행       ");
	puts("┃1. insert: 이름과 전화번호 저장. 한번에 하나씩 저장가능");
	puts("┃※이름, 혹은 전화번호(전체 전화번호 또는 가운데 네자리, 끝 네자리) 검색 가능");
	puts("┃2. delete: 지울 item을 찾아서 지움");
	puts("┃3. modify: 수정할 item을 찾아서 수정");
	puts("┃           이름을 수정하고 싶을 경우 이름으로 검색,");
	puts("┃           전화번호를 수정하고 싶을 경우 전화번호로 검색");
	puts("┃4. search: 이름, 전화번호 검색");
	puts("┃5. print: 전체 전화번호부 출력");
	puts("┃6. quit: 전화번호부 종료 및 전화번호부 파일 생성(파일이름: PHONE_BOOK.txt)");
	puts("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

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
			writeTofile(person, count); // 끝내기전 데이터 파일로 저장
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
		for (i = 0; i < 3; i++) // 파일의 위 3줄에는 전화번호부 정보가 없으므로 파일 포인터를 옮기기 위해 수행
		{
			fgets(dump, 50, fileptr);
		}		

		i = 0;
		while (!feof(fileptr))
		{
			fseek(fileptr, 7, SEEK_CUR); // 파일 포인터를 옮김
			c = fgetc(fileptr); // 파일 포인터 자리가 - 이면 전화번호부가 끝난것임
			if (c == '-')
				break;
			else
			{
				fgets(dump, 50, fileptr); // 한줄씩 dump에 받고 이름과 전화번호로 분리해서 구조체에 저장
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
	fputs("┏━━━━━━━━PHONE BOOK━━━━━━━━┓\n", fileptr);
	fputs("┃ No.	Name		Phone Number	    \n", fileptr);
	fputs("┃------------------------------------------	\n", fileptr);
	
	for (i = 0; i < count; i++)
	{
		fprintf(fileptr, "┃ %-5d%-12s	%s	    \n", i + 1, person[i]->name, person[i]->phoneNum);
	}
	fputs("┃------------------------------------------	\n", fileptr);
	fputs("┗━━━━━━━━━━━━━━━━━━━━━┛\n", fileptr);
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
			mark = searchByName(person, *count, sname); // mark는 count값 즉 index값임 
			if (mark == -1)
			{
				puts("It does not exist in this phone book.");
				return;
			}
			else
			{
				for (i = mark; i < *count - 1; i++) // 지우는 index 뒷부분을 한칸씩 앞으로 보냄 
				{
					strcpy(person[i]->name, person[i + 1]->name);
					strcpy(person[i]->phoneNum, person[i + 1]->phoneNum);
				}
				free(person[*count - 1]); // 마지막은 free
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

			if (phoneLen < 5) // 전화번호의 일부분만 입력한 경우, 전화번호 입력의 -를 기준으로 잘라서 비교 
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
			else // 전화번호 전체로 검색한 경우
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
		puts("Modify the 1. NAME or 2. PHONE NUMBER"); // 이름을 수정하고 싶으면 이름으로검색, 전화번호를 수정하고 싶으면 전화번호로 검색
		printf("Select menu: ");
		gets(smenu);
		fflush(stdin);
		if (strcmp(smenu, "1") == 0 || _stricmp(smenu, "n") == 0 || _stricmp(smenu, "name") == 0)
		{
			printf("Input name: ");
			gets(sname);
			fflush(stdin);
			mark = searchByName(person, count, sname); // index 받아옴
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

			if (phoneLen < 5) // 전화번호의 일부분만 입력한 경우, 전화번호 입력의 -를 기준으로 잘라서 비교 
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
			else // 전화번호 전체를 입력한 경우
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
			
			if (phoneLen < 5) // 전화번호의 일부분만 입력한 경우, 전화번호 입력의 -를 기준으로 잘라서 비교 
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
	puts("┏━━━━━━━━PHONE BOOK━━━━━━━━┓");
	puts("┃ No.	Name		Phone Number	    ");
	puts("┃------------------------------------------	");

	for (i = 0; i < count; i++)
	{
		printf("┃ %-5d%-12s	%s	    \n", i + 1, person[i]->name, person[i]->phoneNum);
	}
	puts("┃------------------------------------------	");
	puts("┗━━━━━━━━━━━━━━━━━━━━━┛");
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
int searchByPartialPnum(Person** person, int count, char* sphoneNum) // 전화번호 가운데 네자리 혹은 끝 네자리로 찾기
{
	char YorN[4];
	int i;

	char* token[3];
	for (i = 0; i < count; i++)
	{
		char cpyNum[20];

		strcpy(cpyNum, person[i]->phoneNum);
		token[0] = strtok(cpyNum, " -.~\n");
		token[1] = strtok(NULL, " -.~\n");// 전화번호 가운데 네자리
		token[2] = strtok(NULL, " -.~\n");// 전화번호 끝 네자리
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

