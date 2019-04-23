#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include "gotoxy.hpp"
#include "C_Funciones.hpp"

using namespace std;

int main()
{
	int xX,yY;
	srand(time(NULL));
	int Velocity=12;
	
	xX = 3+rand()%89 + 2;
	yY = 3+rand()%29 + 2;
	
	
	BAD AA(xX,yY), 	AB(xX,yY), 	AC(xX,yY),	AD(xX,yY),	AE(xX,yY);
	BAD BA(xX,yY), 	BB(xX,yY), 	BC(xX,yY),	BD(xX,yY),	BE(xX,yY);
	BAD CA(xX,yY), 	CB(xX,yY), 	CC(xX,yY),	CD(xX,yY),	CE(xX,yY);
	
	
	system("cls");
	
	string MSG;
	bool GAME_OVER = false;
    OcultarCursor();
    pintar_escenario(); // pinta el escenario(limites) del juego


	
	APPLE Comida(xX,yY);
	Comida.pintar();
	
	//CPU Cpu(66,12);
	GOOD Max(15,15);

	
	while(!GAME_OVER)
{
	if(Max.V() < 1)
	{
		Max.borrar();
		GAME_OVER=true;
	}
	Comida.moverCPU(Max);
	
	
	if(Max.S() >= 0 ) AA.moverCPU(Max,Comida);
	if(Max.S() >= 1 ) AB.moverCPU(Max,Comida);
	if(Max.S() >= 2 ) AC.moverCPU(Max,Comida);	
	if(Max.S() >= 3 ) AD.moverCPU(Max,Comida);
	if(Max.S() >= 4 ) AE.moverCPU(Max,Comida);
	
	if(Max.S() >= 4 ) BA.moverCPU(Max,Comida);	
	if(Max.S() >= 5 ) BB.moverCPU(Max,Comida);
	if(Max.S() >= 6 ) BC.moverCPU(Max,Comida);	
	if(Max.S() >= 7 ) BD.moverCPU(Max,Comida);
	if(Max.S() >= 8 ) BE.moverCPU(Max,Comida);
	
	if(Max.S() >= 8 ) CA.moverCPU(Max,Comida);	
	if(Max.S() >= 9 ) CB.moverCPU(Max,Comida);
	if(Max.S() >= 10) CC.moverCPU(Max,Comida);
	if(Max.S() >= 11) CD.moverCPU(Max,Comida);
	if(Max.S() >= 12) CE.moverCPU(Max,Comida);
	
	
	Max.mover();
	//Cpu.moverCPU(Comida);
	
	Sleep(Velocity);
}
	

	system("cls");
	pintar_escenario(); // pinta el escenario(limites) del juego
	OcultarCursor(true);
	gotoxy(45,14); std::cout << "GAME OVER" << std::endl;
	gotoxy(30,15); std::cout << "Total de score: " << Max.S() <<"; Escribe tu ultima palabra" << std::endl;
	gotoxy(30,16); std::cin >> MSG;
    gotoxy(30,17); system("pause");
    return 0;
}
