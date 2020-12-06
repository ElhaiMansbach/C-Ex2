#include <stdio.h>
#include "myBank.h"	


int main(){

	char options = ' ';
	int exit = 0;
		
	while(!exit){
		printf("\nPlease choose a transaction type:\n");
		printf("O-Open Account\n");
		printf("B-Balance Inquiry\n");
		printf("D-Deposit\n");
		printf("W-Withdrawal\n");
		printf("C-Close Account\n");
		printf("I-Interest\n");
		printf("P-Print\n");
		printf("E-Exit\n");
		if(scanf(" %c", &options) != 1){
			printf("Failed to read the transaction type\n");
		}
		else{

			switch (options) {

			case 'O':
				openAccount();
				break;

			case 'B':
				balanceInquiry();
				break;

			case 'D':
				deposit();
				break;

			case 'W':
				withdrawal();
				break;

			case 'C':
				closeAccount();
				break;

			case 'I':
				interest();
				break;

			case 'P':
				print();
				break;

			case 'E':
				exitAndClose();
				exit = 1;
				break;

			default:
				printf("Invalid transaction type\n");
			}
		}
	}
    
	return 0;
}       