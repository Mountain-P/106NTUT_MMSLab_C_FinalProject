#include <stdio.h>
#include <stdlib.h>

void main()
{
	int a;
	FILE *user;
	char b;
	int choice, count = 0;
	char correct[] = "0913";
	char password[5];
	int function;
	typedef struct _new
	{
		char name[10];
		char account[10];
		char id[10];
	}new;
	new one[10];
	int people=0;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("1.create a new account 2.use admin account\nenter your choice:");
		scanf("%d", &a);
		if (a == 1)
		{
			user = fopen("C://Users/Andy/Desktop/final project/include/user.txt", "a");
			printf("enter your name:");
			scanf("%s", &one[people].name);
			printf("enter your account:");
			scanf("%s", &one[people].account);
			printf("enter your RFID:");
			scanf("%s", &one[people].id);
			fprintf(user,"%10s\t%10s\t%10s\n", one[people].name, one[people].account, one[people].id);
			fclose(user);
			people++;
		}
		if (a == 2)
		{
			printf("enter your password:");
			scanf("%s",password);
			if (password == correct)
			{
				scanf("%")
				function = getchar();
				switch (function)
				{
				case 1:
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
		}
		break;
		
	}
	for (int i = 0; i < people; i++)
	{
		printf("%5s %10s %10s", one[i].name, one[i].account, one[i].id);
	}
	
	system("pause");
	return 0;
}