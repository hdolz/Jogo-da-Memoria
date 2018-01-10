/*
	Algorítmo e técnicas de programação;
	Jogo da memória simples em C/C++;
	Instituto federal de educação, ciência e tecnologia do Amazonas - IFAM;
	Curso: Tecnologia em análise e desenvolvimento de sistemas;
	Desenvolvido por Henrique Dolzane Mota;
	Maio/2016;
*/

#include <iostream>
#include <conio.c>
#include <time.h>
#include <windows.h>

using namespace std;

//variáveis
char tecla;
char imagens[3][4] = {'3','6','2','4','1','5','2','4','3','1','5','6'}; // componentes da matriz do jogo
char jogo[3][4]; //matriz principal
int troca [12];//acumula troca de posições para randomizar os valores da matriz
int l, c;
int x1, x2, x3, x4; //valores para randomizar posicionamento
int x = 34, y = 7;
int n, t;
int px[4] = {34,37,40,43}, py[3] = {7,10,13};
int x1c, y1c, x2c, y2c;
char comp[2];//armazena valores dos locais selecionados pelo usuário
int k=0, v=0;
int pontuador = 0;

//funções

void intro () { // animação de introdução
	int col=31,lin;
   	system("color f");
   	for(lin=20;lin>=4;lin--) {
      gotoxy(col,lin);
      cout << "Jogo da mem"<<char(162)<<"ria";
      system("cls");
   	}
   	gotoxy(31,4);   
   	cout << "Jogo da mem"<<char(162)<<"ria";
      	system("color 0");Sleep (10);
		system("color 1");Sleep (10);
		system("color 2");Sleep (10);
		system("color 3");Sleep (10);
		system("color 4");Sleep (10);
		system("color 5");Sleep (10);
		system("color 6");Sleep (10);
		system("color 7");Sleep (10);
		system("color 8");Sleep (10);
		system("color 9");Sleep (10);
		system("color a");Sleep (10);
		system("color b");Sleep (10);
		system("color c");Sleep (10);
		system("color d");Sleep (10);
		system("color e");Sleep (10);
		system("color f");Sleep (10);
		cout << "\n\n";
   	system("cls");
}

void quadro () { //bordas principais do programa
	//linhas horizontais
	for (int i = 2; i < 78; i ++) {
		gotoxy(i,3); cout << char(205); //superior
		gotoxy(i,23); cout << char(205);//inferior
	}
	//linhas verticais
	for (int i = 4; i < 23; i ++) {
		gotoxy(2, i); cout << char(186); //esquerda
		gotoxy(77,i); cout << char(186); //direita
	}
	//vertices
	gotoxy(2, 3); cout << char(201); //superior esquerdo
	gotoxy(2, 23); cout << char(200);//inferior esquerdo
	gotoxy(77, 3); cout << char(187);//superior direito
	gotoxy(77, 23); cout << char(188);//inferior direito

}

void quadroMenor() { // bordas da matriz do jogo
	//linhas horizontais
	for (int i = 32; i < 46; i ++) {
		gotoxy(i,5); cout << char(205); //superior
		gotoxy(i,15); cout << char(205);//inferior
	}
	//linhas verticais
	for (int i = 5; i < 16; i ++) {
		gotoxy(32, i); cout << char(186); //esquerda
		gotoxy(45,i); cout << char(186); //direita
	}
	//vertices
	gotoxy(32,5); cout << char(201); //superior esquerdo
	gotoxy(32,15); cout << char(200);//inferior esquerdo
	gotoxy(45,5); cout << char(187);//superior direito
	gotoxy(45,15); cout << char(188);//inferior direito
}

void desenho () { // desenho ao vencer
	gotoxy(54,9); cout << char(178);
	gotoxy(58,9); cout << char(178);
	gotoxy(52,11); cout << char(178);
	gotoxy(53,12); cout << char(178);
	gotoxy(54,12); cout << char(178);
	gotoxy(55,12); cout << char(178);
	gotoxy(56,12); cout << char(178);
	gotoxy(57,12); cout << char(178);
	gotoxy(58,12); cout << char(178);
	gotoxy(59,11); cout << char(178);
}

void randomizar () { //randomizar matriz ao reiniciar
	srand(time(NULL));
	for (int n=0;n<12;n++) {
		x1=rand()%3;
		x2=rand()%3;
		x3=rand()%4;
		x4=rand()%4;
		
		troca[n] = imagens [x1][x3];
		imagens [x1][x3] = imagens [x2][x4];
		imagens [x2][x4] = troca[n];
	}
}

void escreverMatriz () { //escreve matriz com valores aleatorios
	for (l=0; l<3; l++) {
		for (c=0; c<4; c++) {
			gotoxy(px[c],py[l]); cout << imagens [l][c];
		}
	}
}

void matrizJogo () { //escreve matriz com valores ocultados
	for (l=0;l<3;l++) {
		for (c=0;c<4;c++) {
			jogo[l][c] = char (176);
		}
	}
}

void escreverJogo () { // escreve a matriz principal do jogo
	for (l=0; l<3; l++) {
		for (c=0; c<4; c++) {
			gotoxy(px[c],py[l]); cout << jogo[l][c];
		}
	}
}

void mudar () {
	if (x==34 && y==7) jogo[0][0] = imagens[0][0];
	if (x==37 && y==7) jogo[0][1] = imagens[0][1];
	if (x==40 && y==7) jogo[0][2] = imagens[0][2];
	if (x==43 && y==7) jogo[0][3] = imagens[0][3];
	if (x==34 && y==10) jogo[1][0] = imagens[1][0];
	if (x==37 && y==10) jogo[1][1] = imagens[1][1];
	if (x==40 && y==10) jogo[1][2] = imagens[1][2];
	if (x==43 && y==10) jogo[1][3] = imagens[1][3];
	if (x==34 && y==13) jogo[2][0] = imagens[2][0];
	if (x==37 && y==13) jogo[2][1] = imagens[2][1];
	if (x==40 && y==13) jogo[2][2] = imagens[2][2];
	if (x==43 && y==13) jogo[2][3] = imagens[2][3];
}

void armazenador () { //armazena na matriz comp[] valores dos pares selecionados, referentes ao posicionamento de tela selecionado
	if (k==0) { //primeiro valor do par
		if (x==34 && y==7) comp[v] = imagens[0][0];
		if (x==37 && y==7) comp[v] = imagens[0][1];
		if (x==40 && y==7) comp[v] = imagens[0][2];
		if (x==43 && y==7) comp[v] = imagens[0][3];
		if (x==34 && y==10) comp[v] = imagens[1][0];
		if (x==37 && y==10) comp[v] = imagens[1][1];
		if (x==40 && y==10) comp[v] = imagens[1][2];
		if (x==43 && y==10) comp[v] = imagens[1][3];
		if (x==34 && y==13) comp[v] = imagens[2][0];
		if (x==37 && y==13) comp[v] = imagens[2][1];
		if (x==40 && y==13) comp[v] = imagens[2][2];
		if (x==43 && y==13) comp[v] = imagens[2][3];
		x1c = x;
		y1c = y;
	}
	else { //segundo valor
		if (x==34 && y==7) comp[v] = imagens[0][0];
		if (x==37 && y==7) comp[v] = imagens[0][1];
		if (x==40 && y==7) comp[v] = imagens[0][2];
		if (x==43 && y==7) comp[v] = imagens[0][3];
		if (x==34 && y==10) comp[v] = imagens[1][0];
		if (x==37 && y==10) comp[v] = imagens[1][1];
		if (x==40 && y==10) comp[v] = imagens[1][2];
		if (x==43 && y==10) comp[v] = imagens[1][3];
		if (x==34 && y==13) comp[v] = imagens[2][0];
		if (x==37 && y==13) comp[v] = imagens[2][1];
		if (x==40 && y==13) comp[v] = imagens[2][2];
		if (x==43 && y==13) comp[v] = imagens[2][3];
		x2c = x;
		y2c = y;
	}
	v++; k++;
}

int voltar(int x, int y) { // retomar valores ocultos, em caso de erro, com base no posicionamento da tela
	if (x==34 && y==7) jogo[0][0] = char(176);
	if (x==37 && y==7) jogo[0][1] = char(176);
	if (x==40 && y==7) jogo[0][2] = char(176);
	if (x==43 && y==7) jogo[0][3] = char(176);
	if (x==34 && y==10) jogo[1][0] = char(176);
	if (x==37 && y==10) jogo[1][1] = char(176);
	if (x==40 && y==10) jogo[1][2] = char(176);
	if (x==43 && y==10) jogo[1][3] = char(176);
	if (x==34 && y==13) jogo[2][0] = char(176);
	if (x==37 && y==13) jogo[2][1] = char(176);
	if (x==40 && y==13) jogo[2][2] = char(176);
	if (x==43 && y==13) jogo[2][3] = char(176);
}

void comparador () { // comparar pares selecionados
	if (k == 2) { // k =2 indica que foram selecionados 2 valores para comparação
		if (comp[0] == comp[1]) {
			if (x1c != x2c || y1c != y2c) { //se iguais, pontuação incrementa
				pontuador++; 
				k=0;
				v=0;
			}
			else {
				voltar(x1c, y1c); // caso contrário, posições selecionadas retomam seus valores ocultos
				voltar(x2c, y2c);
				k=0;
				v=0;
			}
		}
		else {
			voltar(x1c, y1c);
			voltar(x2c, y2c);
			k=0;
			v=0;
		}
	}
}

void teclar () { //seleção do que é digitado pelo usuário
	gotoxy(x,y); cout << "";
	
	tecla = getch();
	switch (tecla) {
		case 'w': if(y>7) y-=3; break;
		case 's': if(y<13) y+=3; break;
		case 'd': if(x<43) x+=3; break;
		case 'a': if(x>34) x-=3; break;
		case 13: mudar(); armazenador (); break;
		}
}

void instrucoes() { //instruções básicas de como jogar
	gotoxy(33,17); cout << "Instru"<<char(135)<<char(228)<<"es";
	gotoxy(26,18); cout << "Mova o cursor com as teclas";
	gotoxy(26,19); cout << "W, S, A e D.";
	gotoxy(26,20); cout << "Aperte ENTER para selecionar";
	gotoxy(26,21); cout << "Pressione 0 para sair";
	gotoxy(26,22); cout << "Pressione R para reiniciar";
}

void pontuacao () { 
	gotoxy(13,7); cout << "Pontua"<<char(135)<<char(198)<<"o: "<<pontuador;
}

void vencer () { //mensagem em caso de vitória
	if (pontuador == 6) {
		textcolor(YELLOW);
		gotoxy(11,11); cout << "PARAB"<<char(144)<<"NS!!!";
		gotoxy(11,12); cout << "VOC"<<char(210)<<" VENCEU!!!";
		desenho ();
		textcolor(WHITE);
	}
}

void tempoInicio () { //tempo para mostrar valores iniciais da matriz revelados
	gotoxy(50,6); cout << "Pronto?";
	for (t=3;t>0;t--) {
		gotoxy(53,7); cout << t;
		Sleep(950);
	}
	system("cls");
}

int main (void) {
	system("title Jogo da memória / por: Henrique Dolzane");
	system("color 0f");
	intro ();
	inicio:
	gotoxy(31,4); cout << "Jogo da mem"<<char(162)<<"ria";
	quadro ();
	quadroMenor ();
	randomizar ();
	pontuacao ();
	instrucoes ();
	matrizJogo ();
	escreverMatriz ();
	tempoInicio ();
	gotoxy(31,4); cout << "Jogo da mem"<<char(162)<<"ria";
	quadro ();
	quadroMenor ();
	pontuacao ();
	instrucoes ();
	matrizJogo ();
	escreverMatriz ();
	do {
		vencer ();
		pontuacao ();
		escreverJogo ();
		teclar ();
		escreverJogo ();
		if (k==2) Sleep(200);
		comparador ();
		if (tecla == 'r') {
			k=0; pontuador=0;
			system("cls");
			goto inicio;
		}
	}
	while (tecla != '0');
	system("cls");
	cout << "Desenvolvido por Henrique Dolzane Mota - maio/2016\n";
}
