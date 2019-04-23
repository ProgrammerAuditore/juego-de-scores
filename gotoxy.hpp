#include <windows.h>
#include <cstdio>

 // gotoxy es para obtener/poner coordenadas
void gotoxy(int x, int y){
	HANDLE EyV;
	EyV = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwCoor;
	dwCoor.X = x;
	dwCoor.Y = y;

	SetConsoleCursorPosition(EyV, dwCoor);
}
// OC es para ocultar el cursor
void OcultarCursor(bool HABI = false){
	HANDLE EyV;
	EyV = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = HABI;

	SetConsoleCursorInfo(EyV, &cci);
}
// pintar_escenario es para dibujar las dimenciones del juego o el escenario del juego
void pintar_escenario(){
	for (int i=2 ; i<98; i++){
		gotoxy(i,3); printf("%c",205);  // lineas horizontales de arriba
		gotoxy(i,33); printf("%c",205);  // lineas horizontales de abajo
	}

	for (int i=4 ; i<33; i++){
		gotoxy(2,i); printf("%c",186);  // lineas verticales de izquierda
		gotoxy(97,i); printf("%c",186);  // lineas verticales de derecha
	}

	gotoxy(2,3); printf("%c",201); // arriba superior izquierda
	gotoxy(2,33); printf("%c",200);  // abajo superior izquierda
	gotoxy(97,3); printf("%c",187);  // arriba superior derecha
	gotoxy(97,33); printf("%c",188);   // abajo superior derecha
}

