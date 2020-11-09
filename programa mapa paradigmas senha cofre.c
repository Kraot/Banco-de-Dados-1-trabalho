#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(){
	int RA[5] = {2,4,6,6,5};
	int v[5];
	int senha;
	int i;
	bool T = false;

	do{
		printf("Digite a senha: ");
		scanf("%d",&senha);
		if (countDigits(senha) == 5){
			for (i = 4; i >= 0; i--) {
				v[i] = senha % 10;
				senha /= 10;
			}
			for (i = 0 ; i < 5; i++){
				if (v[i]!=RA[i]){
					break;
				}
				else if(i == 4){
					printf(" Porta aberta.\n");
					T = true;
				}	
			}
		}
		if (T == false){
			printf("Sequencia incorreta.\n \n");
		}	
	}while(T == false);

return 0;
}

int countDigits( int value )
{
    int result = 0;
    while( value != 0 ) {
       value /= 10;
       result++;
    }
    return result;
}
