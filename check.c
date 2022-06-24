#include <stdio.h>
#include <string.h>
// Ymx1ZQ== blue
// dHJ1ZQ== true
// cGVyaw== perk
// YTdfRA== a7_D
const char Base64Table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_=";
int BrutForce(char *cipher)
{
	int brut_res = 0;
	char code64[7], brut[5];
	char cipher_int[9];

	brut[4] = '\0';
	code64[6] = '\0';
	cipher_int[6] = '=';
	cipher_int[7] = '=';
	cipher_int[8] = '\0';
	for (int i = 0; i < 64; i++)
		for (int j = 0; j < 64; j++)
			for (int k = 0; k < 64; k++)
				for (int l = 0; l < 64; l++)
				{
					brut[0] = Base64Table[i];
					brut[1] = Base64Table[j];
					brut[2] = Base64Table[k];
					brut[3] = Base64Table[l];

					code64[0] = brut[0] >> 2;
					code64[1] = ((brut[0] & 3) << 4) | (brut[1] >> 4);
					code64[2] = ((brut[1] & 0x0F) << 2) | (brut[2] >> 6);
					code64[3] = brut[2] & 0x3F;
					code64[4] = brut[3] >> 2;
					code64[5] = (brut[3] & 3) << 4;

					for (int i = 0; i < 6; i++)
					{
						cipher_int[i] = Base64Table[code64[i]];
					}
					if (!strcmp(cipher, cipher_int))
					{
						printf("%s\n", brut);
						brut_res = 1;
						goto end;
					}
				}
end:
	return brut_res;
}

int main()
{
	char cipher[9];
	cipher[8] = '\0';
	for (int i = 0; i < 8; i++)
	{
		scanf("%c", &cipher[i]);
	}
	if (!BrutForce(cipher))
		printf("Brutforce was failed\n");
}