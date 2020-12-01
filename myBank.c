#include <stdio.h>
#include "myBank.h"

#define ROWS 50
#define COLUMNS 2

#define OPEN 0
#define AMOUNT 1
#define MIN_ACC 901
#define MAX_ACC 950

double accounts[ROWS][COLUMNS] = {{0},{0}};

double print2Digits(double num)
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
					accounts[i][AMOUNT] = print2Digits(amount);

					printf("New account number is: %d \n", MIN_ACC + i);
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

void printBalanceInquiry(int account_index)
{
	printf("The balance of account number %d is: %0.2lf\n",
	 MIN_ACC + account_index, accounts[account_index][AMOUNT]);
}

void balanceInquiry()
{

	int account_number = 0;
	printf("Please enter account number: ");
	if (scanf("%d", &account_number) == 1)
	{

		if (account_number < MIN_ACC || account_number > MAX_ACC)
		{
			printf("Invalid account number\n");
		}
		else
		{
			account_number = account_number - MIN_ACC;
			if (accounts[account_number][OPEN] == 0)
			{
				printf("This account is closed\n");
			}
			else
			{
				printBalanceInquiry(account_number);
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
	int account_number = 0;
	printf("Please enter account number: ");
	if (scanf("%d", &account_number) == 1)
	{

		if (account_number < MIN_ACC || account_number > MAX_ACC)
		{
			printf("Invalid account number\n");
		}
		else
		{
			account_number = account_number - MIN_ACC;
			if (accounts[account_number][OPEN] == 0)
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
						accounts[account_number][AMOUNT] += print2Digits(amount);
						printf("The new balance is: %0.2lf\n", accounts[account_number][AMOUNT]);
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

	int account_number = 0;
	printf("Please enter account number: ");
	if (scanf("%d", &account_number) == 1)
	{

		if (account_number < MIN_ACC || account_number > MAX_ACC)
		{
			printf("Invalid account number\n");
		}
		else
		{
			account_number = account_number - MIN_ACC;
			if (accounts[account_number][OPEN] == 0)
			{
				printf("This account is closed\n");
			}
			else
			{
				double amount = 0;
				printf("Please enter the amount to withdraw: ");
				if (scanf("%lf", &amount) == 1)
				{
					amount = accounts[account_number][AMOUNT] - amount;
					if (amount >= 0)
					{
						accounts[account_number][AMOUNT] = print2Digits(amount);
						printf("The new balance is: %0.2lf\n", accounts[account_number][AMOUNT]);
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

void activateCloseAccount(int account_index)
{
	accounts[account_index][OPEN] = 0;
	accounts[account_index][AMOUNT] = 0;
}

void closeAccount()
{
	int account_number = 0;
	printf("Please enter account number: ");
	if (scanf("%d", &account_number) == 1)
	{

		if (account_number < MIN_ACC || account_number > MAX_ACC)
		{
			printf("Invalid account number\n");
		}
		else
		{
			int account_index = account_number - MIN_ACC;
			if (accounts[account_index][OPEN] == 0)
			{
				printf("This account is already closed\n");
			}
			else
			{
				activateCloseAccount(account_index);
				printf("Closed account number %d\n", account_number);
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
					accounts[i][AMOUNT] = print2Digits(accounts[i][AMOUNT]);
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
		activateCloseAccount(i);
	}
}
