#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// htpasswd -b .htpasswd admin 12345Zxcvb///

void main(void)
{
	char system_mes[200] = "";
	char login[30] = "";
	char pas[30] = "";
	char ans[2] = {'\0', '\0'};
	char errCode;
	char *alp_z = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *alp_nz = "abcdefghijklmnopqrstuvwxyz";
	char *alp_n = "0123456789";
	char *alp_s = "!@#$%^&*()_-+=~`.,/?><;:{}[]|";

enter_login:
	printf("Enter login: ");
	scanf("%30s%*[^\n]%*c", login);
	if (strlen(login) == 0)
	{
		printf("Re-Enter login!\n");
		goto enter_login;
	}
	for (int i = 0; i < strlen(login); i++)
	{
		if (strchr(alp_s, login[i]) != NULL)
		{
			printf("Re-Enter login!\n");
			goto enter_login;
		}
	}
	printf("Login is: %s\n", login);

	int is_right = 0;
enter_password:
	printf("Enter password: ");
	scanf("%30s%*[^\n]%*c", pas);
	if (strlen(pas) < 10)
	{
		printf("Re-Enter password (low size, min 10 letters)!\n");
		goto enter_password;
	}
	for (int i = 0; i < strlen(pas); i++)
	{
		if (strchr(alp_s, pas[i]) != NULL)
		{
			is_right = 1;
			break;
		}
	}
	if (!is_right)
	{
		printf("Re-Enter password (no special letters)!\n");
		goto enter_password;
	}
	is_right = 0;

	for (int i = 0; i < strlen(pas); i++)
	{
		if (strchr(alp_n, pas[i]) == NULL)
		{
			is_right = 1;
			break;
		}
	}
	if (!is_right)
	{
		printf("Re-Enter password (no numbers)!\n");
		goto enter_password;
	}
	is_right = 0;

	for (int i = 0; i < strlen(pas); i++)
	{
		if (strchr(alp_nz, pas[i]) == NULL)
		{
			is_right = 1;
			break;
		}
	}
	if (!is_right)
	{
		printf("Re-Enter password (no noncapital letters)!\n");
		goto enter_password;
	}
	is_right = 0;

	for (int i = 0; i < strlen(pas); i++)
	{
		if (strchr(alp_z, pas[i]) == NULL)
		{
			is_right = 1;
			break;
		}
	}
	if (!is_right)
	{
		printf("Re-Enter password (no capital letters)!\n");
		goto enter_password;
	}
	is_right = 0;
	printf("Password is: %s\n", pas);

check_right:
	ans[0] = '\0';
	ans[1] = '\0';
	printf("All is right? (y/n): ");
	scanf("%2s%*[^\n]%*c", ans);
	if (ans[1] == '\0')
	{
		if (ans[0] == 'y' || ans[0] == 'Y')
		{
		}
		else if (ans[0] == 'n' || ans[0] == 'N')
		{
			goto enter_login;
		}
		else
		{
			printf("Error, type again.\n");
			goto check_right;
		}
	}
	else
	{
		printf("Error, type again.\n");
		goto check_right;
	}

	snprintf(system_mes, 200, "htpasswd -b /root/My\\ tests\\ with\\ valgrind/oib_lab_13/.htpasswd %s %s", login, pas);
	// printf("%s\n", system_mes);
	system(system_mes);
}
