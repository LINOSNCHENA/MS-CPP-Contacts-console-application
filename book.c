#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//global variables
int optionAns; //options function
char fname[30];
char lname[30];
char country[50];
char emailAddress[50];
int phoneNumber;
int zipCode;
int ansEdit, editItem_no;
int choice_login;
char loginEmail[50];
int loginPhone;
int system_close = 0;
int account_created = 0;

//global functions
void intro();
void options();
void logs();
void createAccount();
void display_info();
void loginAccount();

int main()
{
	intro();
	options();
	/*
	 * choose whether to create account , login or exit the system.
	 */
	//after creating account
	if (system_close == 0 && account_created == 1)
	{
		printf("Do you wish to edit anything?\n\t1:Yes \t 2:No \n CHOOSE > ");
		scanf("%d", &ansEdit);
		if (ansEdit == 1)
		{
			printf("Select the number of the item: ");
			scanf("%d", &editItem_no);

			switch (editItem_no)
			{
			case (1):
				printf("\n\tFIRST_NAME > ");
				scanf("%d", fname);
				break;
			case (2):
				printf("\n\tSECOND_NAME > ");
				scanf("%d", fname);
				break;
			case (3):
				printf("\n\tCOUNTRY > ");
				scanf("%d", fname);
				break;
			case (4):
				printf("\n\tEMAIL > ");
				scanf("%d", fname);
				break;
			}
		}
		else if (ansEdit == 2)
		{
			printf("Menu \n\n 1: Login \n 2: Exit \n CHOOSE > ");
			scanf("%d, &choice_login");
			if (choice_login == 1)
			{
				//Login to the dashboard...
				//create password afterwards..
				loginAccount();

			}
			else if (choice_login == 2)
			{
				//create exit procedure
				//call logs
				printf("System will EXIt");
				logs();
				sleep(2);
				printf("Bye...");
				system("exit");
			}
		}
	}
	else if (system_close == 1)
	{
		printf("Bye");
		system("exit");
	}

	return 0;
}
void options()
{
	printf("1. Create account \n");
	printf("2. Login to account \n");
	printf("3. Exit \n");

	scanf("%d", &optionAns);
	if (optionAns == 1)
	{
		createAccount();
	}
	else if (optionAns == 2)
	{
		loginAccount();
	}
	else
	{
		logs();
		system("clear");
		system("exit");
	}
}
void intro()
{
	char z[120930] = "-------------------------------------------------------------\n"
					 "       WELCOME TO PHONEBOOK APPLICATION  v3             \n"
					 " Select one action below and then type its command below\n"
					 "=============================================================\n"

					 "HELP   - to lists all available valid commands on this application \n\n"

					 "ADD    - to insert a new contact entry into the phone book\n"
					 "LIST   - to lists all saved contacts sorted by date of entry\n"
					 "DELETE - to erase a specified contact from the phone book\n"

					 "NAME   - to search for a contact by the contact name\n"
					 "NUMBER   - to search for a contact by the contact ID-number\n"
					 "UPDATE - to edit the contact details of an existing contact\n\n"

					 "RESET   - Deletes all database records and restores factory defaults\n"
					 "LOGS   - To view details of all log data manipulations recordss\n"
					 "EXIT   - End the usage of this contacts book application console\n"

					 "--------------------------------------------------------------\n\n"
					 " To continue, please enter an action command here >>>  \n\n";

	printf(z);
}

void loginAccount()
{
	system("clear");
	intro();

	printf("Login to your Account...");
	printf("EMAIL > ");
	scanf("%s", loginEmail);
	printf("PHONE > ");
	scanf("%d", loginPhone);
}

void logs()
{
	system("clear");
	intro();
	sleep(1);
	printf("Clossing services...\n");
	sleep(1);
	printf("Logging you out of the server....\n");
	sleep(1);
	printf("UPdating cache memory....\n");
	sleep(1);
	printf("Shutting down secondary operations.....\n");
	sleep(1);
}

void createAccount()
{
	system("clear");
	intro();

	printf("#---------------------------------------------------------------#\n");
	//printf("#\t\t\t\t\t\t\t\t#\n");
	printf("#\t (1) First Name: \t\t\t\t\t#\n");
	printf("#---------------------------------------------------------------#\n");
	printf("#\t (2) Last Name: \t\t\t\t\t#\n");
	printf("#---------------------------------------------------------------#\n");
	printf("#\t (3) Country: \t\t\t\t\t#\n");
	printf("#---------------------------------------------------------------#\n");
	printf("#\t (5) Email: \t\t\t\t\t\t#\n");
	printf("#---------------------------------------------------------------#\n");
	account_created = 1;
	printf("1. ");
	scanf("%s", fname);
	printf("2. ");
	scanf("%s", lname);
	printf("3. ");
	scanf("%s", country);
	printf("5. ");
	scanf("%s", emailAddress);
}
