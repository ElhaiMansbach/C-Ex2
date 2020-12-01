#include <stdio.h>
#include "myBank.h"

#define ROWS 50
#define COLUMNS 2

#define OPEN 0
#define AMOUNT 1
#define MIN_ACCOUNT 901
#define MAX_ACCOUNT 950

double accounts[ROWS][COLUMNS] = {{0},{0}};

double set2Digits(double num)
{
	num = (int)(num * 100) / 100.;
	return num;
}

void openAccount()
{

	double amount = 0;
	int i;
	for (i = 0; i < ROWS; i++)
	{
		if (accounts[i][OPEN] == 0)
		{
			printf("Please enter amount for deposit: ");
			if (scanf("%lf", &amount) == 1)
			{

				if (amount < 0)
				{
					printf("Invalid Amount\n");
				}
				else
				{
					accounts[i][OPEN] = 1;
					accounts[i][AMOUNT] = set2Digits(amount);

					printf("New account number is: %d \n", MIN_ACCOUNT + i);
				}
			}
			else
			{
				printf("Failed to read the amount\n");
			}
			break;
		}
	}
	if (i == ROWS)
	{
		printf("Sorry, there is no room for more accounts\n");
	}
}

void printBalanceInquiry(int acc_index)
{
	printf("The balance of account number %d is: %0.2lf\n",
	 MIN_ACCOUNT + acc_index, accounts[acc_index][AMOUNT]);
}

void balanceInquiry()
{
	int acc_num = 0;
	printf("Please enter account number: ");
	if (scanf("%d", &acc_num) == 1)
	{
		if (acc_num < MIN_ACCOUNT || acc_num > MAX_ACCOUNT)
		{
			printf("Invalid account number\n");
		}
		else
		{
			acc_num -= MIN_ACCOUNT;
			if (accounts[acc_num][OPEN] == 0)
			{
				printf("This account is closed\n");
			}
			else
			{
				printBalanceInquiry(acc_num);
			}
		}
	}
	else
	{
		printf("Failed to read the account number\n");
	}
}

void deposit()
{
	int acc_num = 0;
	printf("Please enter account number: ");
	if (scanf("%d", &acc_num) == 1)
	{

		if (acc_num > MAX_ACCOUNT || acc_num < MIN_ACCOUNT)
		{
			printf("Invalid account number\n");
		}
		else
		{
			acc_num -= MIN_ACCOUNT;
			if (accounts[acc_num][OPEN] == 0)
			{
				printf("This account is closed\n");
			}
			else
			{
				double amount = 0;
				printf("Please enter the amount to deposit: ");
				if (scanf("%lf", &amount) == 1)
				{
					if (amount > 0)
					{
						accounts[acc_num][AMOUNT] += set2Digits(amount);
						printf("The new balance is: %0.2lf\n", accounts[acc_num][AMOUNT]);
					}
					else
					{
						printf("Cannot deposit a negative amount\n");
					}
				}
				else
				{
					printf("Failed to read the amount\n");
				}
			}
		}
	}
	else
	{
		printf("Failed to read the account number\n");
	}
}

void withdrawal()
{

	int acc_num = 0;
	printf("Please enter account number: ");
	if (scanf("%d", &acc_num) == 1)
	{

		if (acc_num > MAX_ACCOUNT || acc_num < MIN_ACCOUNT)
		{
			printf("Invalid account number\n");
		}
		else
		{
			acc_num -= MIN_ACCOUNT;
			if (accounts[acc_num][OPEN] == 0)
			{
				printf("This account is closed\n");
			}
			else
			{
				double amount = 0;
				printf("Please enter the amount to withdraw: ");
				if (scanf("%lf", &amount) == 1)
				{
					amount = accounts[acc_num][AMOUNT] - amount;
					if (amount >= 0)
					{
						accounts[acc_num][AMOUNT] = set2Digits(amount);
						printf("The new balance is: %0.2lf\n", accounts[acc_num][AMOUNT]);
					}
					else
					{
						printf("Cannot withdraw more than the balance\n");
					}
				}
				else
				{
					printf("Failed to read the amount\n");
				}
			}
		}
	}
	else
	{
		printf("Failed to read the account number\n");
	}
}

void doCloseAccount(int acc_index)
{
	accounts[acc_index][OPEN] = 0;
	accounts[acc_index][AMOUNT] = 0;
}

void closeAccount()
{
	int acc_num = 0;
	printf("Please enter account number: ");
	if (scanf("%d", &acc_num) == 1)
	{

		if (acc_num > MAX_ACCOUNT || acc_num < MIN_ACCOUNT)
		{
			printf("Invalid account number\n");
		}
		else
		{
			int acc_index = acc_num - MIN_ACCOUNT;
			if (accounts[acc_index][OPEN] == 0)
			{
				printf("This account is already closed\n");
			}
			else
			{
				doCloseAccount(acc_index);
				printf("Closed account number %d\n", acc_num);
			}
		}
	}
	else
	{
		printf("Failed to read the account number\n");
	}
}

void interest()
{
	int interest_rate = 0;
	printf("Please enter interest rate: ");
	if (scanf("%d", &interest_rate) == 1)
	{

		if (interest_rate < 0)
		{
			printf("Invalid interest rate\n");
		}
		else
		{
			for (int i = 0; i < ROWS; i++)
			{
				if (accounts[i][OPEN] == 1)
				{
					accounts[i][AMOUNT] *= 1 + (interest_rate / 100.);
					accounts[i][AMOUNT] = set2Digits(accounts[i][AMOUNT]);
				}
			}
		}
	}
	else
	{
		printf("Failed to read the interest rate\n");
	}
}

void print()
{
	for (int i = 0; i < ROWS; i++)
	{
		if (accounts[i][OPEN] == 1)
		{
			printBalanceInquiry(i);
		}
	}
}

void exitAndClose()
{
	for (int i = 0; i < ROWS; i++)
	{
		doCloseAccount(i);
	}
}
