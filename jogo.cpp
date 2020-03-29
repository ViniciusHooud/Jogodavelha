//jogo da velha de : Vinicius
#include<stdio.h>
#include<stdlib.h>
char mat[3][3];
void inicializamatriz(){
	for(int i=0; i<3; i++){
		for(int j=0;j<3;j++){
			mat[i][j]= ' ';
		}		
	}
}
void imprimematriz(){
	system("cls");
	printf ("\n\t\t\t%c Bem-Vindo",282);
    printf ("\n\t\t\t%c Jogo da velha",291);
    printf ("\n\t\t\t%c Bom Jogo",258);
	printf ("\n\n\n");
	printf("\t\t\t     0   1   2\n");
	printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,194,196,196,196,194,196,196,196,191);
	printf("\t\t\t 0 %c %c %c %c %c %c %c\n",179, mat[0][0],179,mat[0][1],179, mat[0][2],179);
	printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c\n",195,196,196,196,197,196,196,196,197,196,196,196,180);
	printf("\t\t\t 1 %c %c %c %c %c %c %c\n",179, mat[1][0],179,mat[1][1],179, mat[1][2],179);
	printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c\n",195,196,196,196,197,196,196,196,197,196,196,196,180);
	printf("\t\t\t 2 %c %c %c %c %c %c %c\n",179, mat[2][0],179,mat[2][1],179, mat[2][2],179);
	printf("\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,193,196,196,196,193,196,196,196,217);
}
 char testaganhador(){
	for (int i=0 ; i<3 ; i++){
		if (mat[i][0] != ' ' && mat[i][0] == mat[i][1] && mat[i][1] == mat [i][2]){     //linha
			return mat[i][0];
			printf ("jogador",' ',"ganhou");
		}
		else if (mat[0][i] != ' ' && mat[0][i] == mat[1][i] && mat[1][i] == mat [2][i]){     //coluna
			return mat[0][i];
        }
        else if (mat[0][0] != ' ' && mat[0][0] == mat[1][1] && mat[1][1] == mat [2][2]){     //diagonal-1
			return mat[0][0];
		}
	    else if (mat[0][2] != ' ' && mat[0][2] == mat[1][1] && mat[1][1] == mat [2][0]){     //diagonal-2
			return mat[0][0];
		}
	} 
     for (int i=0; i<3; i++){
     	for (int j=0;j<3;j++){        //se não houve ganhador nem há
     		if (mat[i][j] == ' '){ 	 //espaço em branco para jogar
     			return ' ';    	    //entao retorna 'e'
			 }
		 }
	 }
	 return 'e';
}
int main (){
	char jogador='X', ganhador=' ';
	int lin,col, cont1, cont=0, repeticao,vencedor;
	int flag;
	inicializamatriz();          //chamada da função
	while(ganhador== ' ' && cont<9){
		imprimematriz();
		flag = 0;
		printf("\n\t\t\t jogador: %c", jogador,cont1);
		printf("\n\t\t\t digite a linha a jogar: ");
		scanf("%d",&lin);
		printf("\n\t\t\t Digite a coluna a jogar: ");
		scanf ("%d",&col);
		system("pause");
		if (lin < 0  || lin > 2){
			printf("\n linha invalida\n\n");
			system("pause");
			flag = 1;
		}
		if (flag == 0){
			if (mat[lin][col] != ' '){
				printf ("\nErro, jogada ja realizada - Tente novamente!\n\n");
				system("pause");
				flag = 1;
			}
			if (flag == 0){
				mat[lin][col]= jogador;
			
				if (jogador=='X'){
					jogador = 'O';
				}
				else{ jogador= 'X';	
		    	}
		    }
		}
		ganhador = testaganhador();
		
		if (ganhador == 'X'){
			imprimematriz();	
			printf("\n\n\t\t\t Jogador %c ganhou ",88);
		}
		else if (ganhador == 'O'){
			imprimematriz();
			printf("\n\n\t\t\t Jogador %c ganhou ",79);
		}
		else if (ganhador == 'e'){
			imprimematriz();
			printf("\n\n\t\t\tOps,parece que deu velha!");
		}
		cont++;
	}
}
