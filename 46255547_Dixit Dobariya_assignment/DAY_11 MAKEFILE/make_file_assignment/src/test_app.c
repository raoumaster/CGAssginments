/* This is test application program which has a driver function by name main which
 * will call all other functions to test the functionalities.
 */
#include<stdio.h>
#include<stdlib.h>
#include "../inc/str01.h"
#include "../inc/str02.h"
#include "../inc/str03.h"
#include "../inc/str04.h"
#include "../inc/str05.h"
#include "../inc/str06.h"

int main(){
	int i;
	printf("1) Enter a string using fgets()\n2) Tokenise\n3) Longest word\n4) Substring\n5) Remove space \n6) String replacement\n7) EXIT\n");
	printf("Enter any number from 1 to 6: ");
	scanf("%d", &i);
	switch(i){
		case 1:
			first();
			break;

		case 2:
			second();
			break;

		case 3:
			third();
			break;

		case 4:
			fourth();
			break;

		case 5:
			five();
			break;

		case 6:
			six();
			break;

		case 7:
			exit(0);

		default:
			printf("INVALID CHOICE");
			break;
	}
	return 0;
}
