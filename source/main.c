#include <stdio.h>
#include <stdlib.h>
int flag = 0;
int a;
char c;
FILE *user;
char b;
int filelinecount = 0;
int choice, count = 0;
char correct[20] = "0913";
char inputpassword[20];
int function;
char lf;
void refreshthefile();
typedef struct _new
{
	int usersn;
	char username[10];
	char userpw[10];
	char doorlockpw[10];
	char accountrfidnum[10];

}new;
new one[100];
void main()
{
	

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
	int people = filelinecount;
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
			one[people].usersn = people+1;
			fprintf(user, "%d", one[people].usersn);
			printf("Enter Your UserName:");
			scanf("%s", &one[people].username);
			printf("Enter Your Password:");
			scanf("%s", &one[people].userpw);
			printf("Enter your DoorLock Password:");
			scanf("%s", &one[people].doorlockpw);
			printf("Enter your RFID card Number:");
			scanf("%s", &one[people].accountrfidnum);
			fprintf(user, "\t%s\t%s\t%s\t%s\n", one[people].username, one[people].userpw, one[people].doorlockpw, &one[people].accountrfidnum);
			fclose(user);
		}
		if (a == 2){
			printf("===============================\nUser Login\n===============================\nPlease Enter Your UserName:");
			char tempusername[10];
			char temppassword[10];
			int unstatus=1,pwstatus=0;
			int f = 0;
			//while (unstatus){
				scanf("%s", tempusername);
				char findusername[10];
				
				//while (strcmp(tempusername, &one[f].username)){
				while(strcmp(tempusername, &one[f].username))
				{
					f++;
					if (f > filelinecount){
						printf("User Not Found!!");
						printf("Please try again!\nYour UserName:");
						//tempusername[10] = '\0';
						scanf("%s", tempusername);
						f = 0;
					}
				}
				
				//}
			//}
			

			printf("Please Enter Your Password:");
			scanf("%s", temppassword);
			while (strcmp(temppassword, &one[f].userpw)){
				printf("password is wrong\tplease enter again :");
				scanf("%s", temppassword);
			}
			if (!strcmp(temppassword, &one[f].userpw)){
				printf("===============================\nAccount Infomation\n===============================\n");
				printf("Account Name:%s\nAccount Password:%s\nAccount Door Lock Passowrd:%s\nAccount RFID Card Number:%s\n", &one[f].username, &one[f].userpw, &one[f].doorlockpw, &one[people].accountrfidnum);
				printf("===============================\nWhat do you want do,%s?\n", &one[f].username);
				printf("1.Change Your Account Password\n2.Change your Door Lock Password\n3.Change Your RFID Card Number\n4.Logout\nYour choice:");
				int choice2;
				scanf("%d", &choice2);
				switch (choice2){
				case 1:
					printf("Enter the Name that you want to change:");
					char changename[10];
					scanf("%s", changename);
					strcpy(one[f].username, changename);
					printf("%s",one[f].username);
					refreshthefile();
					break;
				default:
					break;
						
				}
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
			while (strcmp(inputpassword, correct)){
				printf("\a\npassword is wrong\tplease enter again:");
				inputpassword[20]= '/0';
				flag = 0;
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
			}
			
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
	system("pause");
	return 0;
}
void refreshthefile(){
	printf("%d", filelinecount);
	user = fopen("C://Users/Andy/Desktop/final project/include/user.txt", "w+");
	for (int w = 0; w < filelinecount; w++)
		fprintf(user, "%d\t%s\t%s\t%s\t%s\n", one[w].usersn, one[w].username, one[w].userpw, one[w].doorlockpw, &one[w].accountrfidnum);
	fclose(user);
		
	
}