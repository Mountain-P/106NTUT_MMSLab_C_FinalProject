#include <stdio.h>
#include <stdlib.h>
void main()
{
	int flag = 0;
	int a;
	char c;
	FILE *user;
	char b;
	int filelinecount=0;
	int choice, count = 0;
	char correct[20] = "0913";
	char inputpassword[20];
	int function;
	char lf;
	typedef struct _new
	{
		int usersn;
		char username[10];
		char userpw[10];
		char doorlockpw[10];
		char accountrfidnum[10];

	}new;
	new one[100];

	printf("Reading the account information.\nPlease wait....");
	user = fopen("C://Users/Andy/Desktop/final project/include/user.txt", "r");
	if (user == NULL)
		printf("\nAccount File not Found!!\n");
	else
		printf("Sucssced!\n");
	while ((c = fgetc(user)) != EOF) {
		if (c == '\n')
			filelinecount++;
	}
	fclose(user);
	user = fopen("C://Users/Andy/Desktop/final project/include/user.txt", "r");
	printf("%d", filelinecount);
	for (int i = 0; i < 100; i++){		
		fscanf(user, "%d", &one[i].usersn);
		fscanf(user, "%s", one[i].username);
		fscanf(user, "%s", one[i].userpw);
		fscanf(user, "%s", one[i].doorlockpw);
		fscanf(user, "%s", one[i].accountrfidnum);
	}
	//int i = 1;
	//printf("%d%s%s%s%s\n", one[i].usersn, one[i].username, one[i].userpw, one[i].doorlockpw, one[i].accountrfidnum);
	fclose(user);
	int people=2;
	printf("===============================\n");
	printf("==Press 1 to continue\n");
	printf("==Your Choice:");
	scanf("%d", &choice);
	printf("===============================\n");
	switch (choice)
	{
	case 1:
		printf("");
		printf("1.Create New Account\n2.User Login\n3.Use Admin Account\n===============================\nEnter your choice:");
		scanf("%d", &a);
		if (a == 1)
		{
			user = fopen("C://Users/Andy/Desktop/final project/include/user.txt", "a");
			printf("Enter Your UserSN:");
			scanf("%d", &people);
			one[people].usersn = people;
			printf("Enter Your UserName:");
			scanf("%s", &one[people].username);
			printf("Enter Your Password:");
			scanf("%s", &one[people].userpw);
			printf("Enter your DoorLock Password:");
			scanf("%s", &one[people].doorlockpw);
			printf("Enter your RFID card Number:");
			scanf("%s", &one[people].doorlockpw);
			fprintf(user, "%d\t%s\t%s\t%s\t%s\n", one[people].usersn, one[people].username, one[people].userpw, one[people].doorlockpw, &one[people].doorlockpw);
			fclose(user);
			people++;
		}
		if (a == 2){
			printf("===============================\nUser Login\n===============================\nPlease Enter Your UserName:");
			char tempusername[10];
			char temppassword[10];
			scanf("%s", tempusername);
			char findusername[10];
			int f = 0;
			while (strcmp(tempusername, &one[f].username)){
				f++;
				if (f > filelinecount){
					printf("User Not Found!!");
					printf("Exiting.....");
					system("pause");
					return 0;
				}
				
			}

			printf("Please Enter Your Password:");\
			scanf("%s", temppassword);
			if (!strcmp(temppassword, &one[f].userpw)){
				printf("===============================\nAccount Infomation\n===============================\n");
				printf("Account Name:%s\nAccount Password:%s\nAccount Door Lock Passowrd:%s\n", &one[f].username, &one[f].userpw,&one[f].doorlockpw);
			}
			else{
				printf("Password Incorrect!!!\nExiting....");
				system("pause");
				return 0;
			}



		}
		if (a == 3)
		{
			printf("===============================\nUse admin account need admin password.\n");
			printf("Please enter your password:");
			//scanf("%s",inputpassword);
			for (int j = 0; j<10; j++)
			{
				inputpassword[j] = getch();
				if (inputpassword[j] != 13)      //在知識+查到在getch裡按enter會回傳一個13 
					flag++;
				else
					break;
				printf("*");
			}
			inputpassword[flag] = 0;
			//printf("\n%s",inputpassword);
			printf("\n===============================\n");
			if (!strcmp(inputpassword,correct))
			{
				printf("Administrator Function\n");
				printf("===============================\n");
				printf("1.print all ID information\n2.\n");
				printf("===============================\n");
				printf("Your Choice:");
				scanf("%d", &function);
				
				switch (function)
				{
				case 1:
					printf("===================================================\n");
					printf("     Name       Password        RFID Number\n");
					printf("===================================================\n");
					user = fopen("C://Users/Andy/Desktop/final project/include/user.txt","r");
					while ((b = getc(user)) != EOF)
					{
						printf("%c",b);
						count++;
					}
					fclose(user);
					break;
				}
			}
			else
			{
				printf("passowrd wrong");
			}
		}
		break;
		
	}
	/*for (int i = 0; i < people; i++)
	{
		printf("%5s %10s %10s", one[i].username, one[i].userpw, one[i].doorlockpw);
	}*/
	
	system("pause");
	return 0;
}