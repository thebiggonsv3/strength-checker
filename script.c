#include <stdio.h>
#include <string.h>

int main()
{
	char password[100];

	printf("thebiggonsv3's Password Strength Schecker\n");
	printf("------------------------------------------\n");
	printf("Welcome! To get started, please enter a \npassword you would like to test.\n");

	scanf("%s", password);
	printf("------------------------------------------\n");

	int strength = 0;
	int upper = 0;
	int lower = 0;
	int num = 0;
	int other = 0;

	size_t size = strlen(password);
	
	if (size > 6)
	{
		strength ++;
	}
	if (size > 15)
	{
		strength ++;
	}

	for (i = 0, i < size, i++)
	{
		if (islower(i)) 
		{
        		lower ++;
    		} 		
		else if (isupper(i)) 
		{
       			upper ++;
    		} 		
		else if (isdigit(i)) 
		{ 
        		num ++;
    		} 		
		else
		{
			other ++;
		}

	return 0;
}
