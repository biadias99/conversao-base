// Tamanho máximo do binário -> 50 caracteres

#include<stdio.h>
#include<windows.h>
void sair();
void hideCursor();
void showCursor();
void gotoxy(int x, int y);
void converteDecimal();
void decimalParaBinario(int decimal);
void decimalParaOctal(int decimal);
void decimalParaHexa(int decimal);
void menu();
void ajuda();
void sobre();
void menuBoasVindas();

void sair(){
	system("cls");
	gotoxy(30,3);printf("Obrigada por utilizar o sistema BitABit!\n\n");
	exit(0); // força o fechamento do programa;
}

void hideCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void showCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(int x,int y){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y}); //posiciona cursor na tela
}

void converteDecimal(){
	char tecla;
	system("cls");
	showCursor();
	int dec;
	gotoxy(35,3);printf("CONVERSOR DE BASES - DECIMAL");
	gotoxy(10,6);printf("Digite o numero a ser convertido: ");
	scanf("%d",&dec);
	decimalParaBinario(dec);
	decimalParaOctal(dec);
	decimalParaHexa(dec);
	hideCursor();
	gotoxy(10,20);printf("<ESC> Voltar ao menu principal");
	tecla = getch();
	while(tecla!=27){
		tecla = getch();
	}
	if(tecla == 27)
		menu();
}

void decimalParaBinario(int decimal){
	char bin[50];
	int a = 0;
	int resto;
	
	strcpy(bin, " ");
	
	while(decimal != 0){
		resto = decimal % 2;
		decimal = abs(decimal/2);
		if(resto == 0){
			strcat(bin, "0");
		}else if(resto == 1){
			strcat(bin, "1");	
		}
		a++;
	}
	gotoxy(10,10);printf("Binario: %s",strrev(bin));
}

void decimalParaOctal(int decimal){
	char oct[50];
	int a = 0;
	int resto;
	
	strcpy(oct, " ");
	
	while(decimal != 0){
		resto = decimal % 8;
		decimal = abs(decimal/8);
		switch(resto){
			case 0:
				strcat(oct,"0");
				break;
			case 1:
				strcat(oct,"1");
				break;
			case 2:
				strcat(oct,"2");
				break;
			case 3:
				strcat(oct,"3");
				break;
			case 4:
				strcat(oct,"4");
				break;
			case 5:
				strcat(oct,"5");
				break;
			case 6:
				strcat(oct,"6");
				break;
			case 7:
				strcat(oct,"7");
				break;
		}
		a++;
	}
	gotoxy(10,12);printf("Octal: %s",strrev(oct));
}

void decimalParaHexa(int decimal){
	char hex[50];
	int a = 0;
	int resto;
	
	strcpy(hex, " ");
	
	while(decimal != 0){
		resto = decimal % 16;
		decimal = abs(decimal/16);
		switch(resto){
			case 0:
				strcat(hex,"0");
				break;
			case 1:
				strcat(hex,"1");
				break;
			case 2:
				strcat(hex,"2");
				break;
			case 3:
				strcat(hex,"3");
				break;
			case 4:
				strcat(hex,"4");
				break;
			case 5:
				strcat(hex,"5");
				break;
			case 6:
				strcat(hex,"6");
				break;
			case 7:
				strcat(hex,"7");
				break;
			case 8:
				strcat(hex,"8");
				break;
			case 9:
				strcat(hex,"9");
				break;
			case 10:
				strcat(hex,"A");
				break;
			case 11:
				strcat(hex,"B");
				break;
			case 12:
				strcat(hex,"C");
				break;
			case 13:
				strcat(hex,"D");
				break;
			case 14:
				strcat(hex,"E");
				break;
			case 15:
				strcat(hex,"F");
				break;
		}
		a++;
	}
	gotoxy(10,14);printf("Hexadecimal: %s",strrev(hex));
}

void menu(){
	system("cls");
	int tecla;
	int cont = 2;
	hideCursor();
	gotoxy(40,3);printf("CONVERSOR DE BASES");
	gotoxy(7,6);printf("->");
	gotoxy(10,6);printf("Binario para as demais bases");
	gotoxy(10,8);printf("Decimal para as demais bases");
	gotoxy(10,10);printf("Octal para as demais bases");
	gotoxy(10,12);printf("Hexadecimal para as demais bases");
	gotoxy(10,14);printf("Sobre");
	gotoxy(10,18);printf("<ESC> Sair");
	gotoxy(10,20);printf("<SPACE> Ajuda");

   	while(tecla!=27){
   		gotoxy(10,14);tecla = getch();

   		if(tecla == 80 && cont<=8){ // para baixo
   			gotoxy(7,4+cont);printf("  ");
   			cont+=2;
			gotoxy(7,4+cont);printf("->");
		}

		if(tecla == 72 && cont>2){ // para cima
   			gotoxy(7,4+cont);printf("  ");
   			cont-=2;
			gotoxy(7,4+cont);printf("->");
		}

		if(tecla == 13){
			switch(cont){
				case 2:
					//converteBinario();
					break;
				case 4:
					converteDecimal();
					break;
				case 6:
					//matrizTransposta(matriz);
					break;
				case 8:
					//menuSistemaLinear(matriz);
					break;
				case 10:
					sobre();
					break;
			}
		}

		if(tecla==32){
			ajuda();
		}
	}

	sair();

}

void ajuda(){
	gotoxy(45,22);printf("AJUDA");
	gotoxy(10,24);printf("Utilize as setas do seu teclado para mover a setinha para cima ou para baixo.");
	gotoxy(10,26);printf("Para escolher uma opcao, aperte ENTER.");
	gotoxy(10,28);printf("Para finalizar o programa, aperte ESC");
	gotoxy(10,30);printf("Divirta-se!");
}

void sobre(){
	int tecla = 32;
	system("cls");
	gotoxy(30,3);printf("SOBRE - CONVERSAO DE BASES");
	printf("\n\n\n\n\tTrabalho de conversao de bases\n\t");
	printf("\n\n\tDisciplina: Fundamentos da computacao\n\t");
	printf("\n\n\tProfessora: Juliana Feitosa");
	gotoxy(35,16);printf("BSI - 2018");
	printf("\n\n\n\n\n\t<ESC> Voltar ao menu principal.");

	tecla = getch();

	while(tecla!=27){
		tecla = getch();
	}

	if(tecla == 27)
		menu();
}

void menuBoasVindas(){
	char tecla;
	int aux = 1;
	int tent = 1;
	gotoxy(30,13);printf("Bem-vindo ao conversor de bases BitABit");
	gotoxy(29,16);printf("Pressione qualquer tecla para continuar...");
	hideCursor();

	if(tecla = getch()){
		menu();
	}
}

int main(){
	system("color 0E");
	system("mode con:cols=95 lines=35");
	menuBoasVindas();
}
