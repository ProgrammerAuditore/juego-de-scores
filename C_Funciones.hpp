#include <windows.h>
#include <conio.h>

#define ARRIBA 72
#define DERECHA 77
#define ABAJO 80
#define IZQUIERDA 75



/*************************************************************************************************
						CLASE PLAYER (GOOD)
**************************************************************************************************/

// Hacemos un objeto carro
class GOOD{
    int x,y,Score,Vidas;
public:
    // Constructor que tine como parametros las cooredenadas del carro
    GOOD(int _x,int _y);
    // Obtener las coordenadas(privadas) del Carro
    int X(){ return x; }
    int Y(){ return y; }
	
	int S(){ return Score; } // Obtener los puntos
	int V(){ return Vidas; } // Obtener Vidas
	
	void SC(int A){ Score = A;  } // Agregar Scores
	void VC(int B){ Vidas = B;  } // Agregar Vidas

    void borrar(); // Borrar el jugador
    void pintar(); // Pintar / Dibujar el jugador
	void COOL(); // Pintar / Dibujar Colision
	void NICO(); // Pintar / Dibujar a coordenadas especificas
	
    // Jugador
    void mover();

};

GOOD::GOOD(int _x,int _y){	
	x = _x;
	y = _y;
	Score=0;
	Vidas=10;
	pintar();
}

void GOOD::pintar(){
	int Carita=1;
	gotoxy(2,2); printf("               ");
	gotoxy(2,2); std::cout << "Vidas: " << Vidas << std::endl;
	gotoxy(90,2); std::cout << "Score: " << Score << std::endl;
	
	if(Vidas > 0){
		gotoxy(x+2,y); printf("0");
		gotoxy(x+1,y+1); printf("0%c0",Carita);
		gotoxy(x+2,y+2); printf("0");
	}
}

void GOOD::borrar(){	
	//Borrar Jugador
	gotoxy(x+2,y); printf(" ");
	gotoxy(x+1,y+1); printf("   ");
	gotoxy(x+2,y+2); printf(" ");
}

void GOOD::mover(){
	//gotoxy(22,2); printf("X=%d y Y=%d",x,y);
	if(kbhit()){
	char tecla = getch();
    if( tecla == ARRIBA && y > 4 ){ borrar(); y--; pintar();}
    if( tecla == ABAJO && y+2 < 32 ){ borrar(); y++; pintar();}
    if( tecla == DERECHA &&  x+2 < 95 ){ borrar(); x++; pintar();}
    if( tecla == IZQUIERDA && x > 3 ){ borrar(); x--; pintar();}
 }
}

void GOOD::COOL(){
	gotoxy(x+2,y); printf("*");
	gotoxy(x+1,y+1); printf("***");
	gotoxy(x+2,y+2); printf("*");
}

void GOOD::NICO(){
	x=4;
	y=4;
	pintar();
}


/**************************************************************************************************
						CLASE COMIDAS (APPLE)
***************************************************************************************************/


class APPLE{
    int x,y;
public:
    // Constructor que tine como parametros las cooredenadas del carro
    APPLE(int _x,int _y);
    // Obtener las coordenadas(privadas) del Carro
    int X(){ return x; }
    int Y(){ return y; }
	void COORD(int xX,int yY){ x=xX; y=yY;  }

    void borrar();
    void pintar();

    // Jugador
	void moverCPU(class GOOD &Max);

};
APPLE:: APPLE(int _x,int _y){
	x = _x;
	y = _y;
	pintar();
}

void APPLE::pintar(){
    gotoxy(x,y); printf("O");
}

void APPLE::borrar(){
    gotoxy(x,y); printf("  ");
}


void APPLE::moverCPU(class GOOD &Max){
	//gotoxy(12,2); printf("X=%d y Y=%d",x,y);
	
	int Puntos= Max.S();
	int _YY = Max.Y();
	int _XX = Max.X();
	int Sonido=7;
	
	if(  (x-2 == _XX && y == _YY) || (x-2 == _XX && y-2 == _YY) ){
		Puntos++;
		printf("%c",Sonido);
		Max.SC(Puntos);
		srand(time(NULL));
		//Max.COOL();
		//Max.borrar();
		//Max.NICO();
		x = rand()%89+ 4;
		y = rand()%29+ 4;
		
	}
	pintar();
	
}


/**************************************************************************************************
						CLASE ENEMIGOS (BAD)
***************************************************************************************************/

class BAD{
    int x,y,puntos;
	bool FULL;
public:
    // Constructor que tine como parametros las cooredenadas del carro
    BAD(int _x,int _y);
    // Obtener las coordenadas(privadas) del Carro
    int X(){ return x; }
    int Y(){ return y; }

    void borrar();
    void pintar();

    // Jugador
	void moverCPU(class GOOD &Max,class APPLE &Comida);

};
BAD:: BAD(int _x,int _y){
	x = _x;
	y = _y;
	pintar();
}

void BAD::pintar(){
    gotoxy(x,y); printf("%c%c",178,62);
	FULL = true;
}

void BAD::borrar(){
    gotoxy(x,y); printf("  ");
}


void BAD::moverCPU(class GOOD &Max,class APPLE &Comida){
	//gotoxy(4,4); printf("X=%d y Y=%d",x,y);
	// GOOD
	int VV  = Max.V(); // Obtener vidas 
	int _YY = Max.Y(); // Obtener coordenada x
	int _XX = Max.X(); // Obtener coordenada y
	// APPLE
	int _xX = rand()%89 + 4;
	int _yY = rand()%29 + 4;
	
	
	if(x == 94 && y == 33){
		borrar();
		y=4;
		x=4;
		pintar_escenario(); // pinta el escenario(limites) del juego
	}
	
	
	if( x <= 95 && FULL == true ){
		borrar(); x++; pintar();
		if( x >= 95){
		borrar();
		FULL = false;
		y++;
		}
	}

	if( x >= 4 && FULL == false){
		borrar(); x--; pintar();
		if( x >= 4){
		FULL = false;
		}
	}
	
	if( (x == _XX && y == _YY) || (x-2 == _XX && y-2 == _YY) ){
		VV--;
		Max.VC(VV);
		Max.COOL();
		Sleep(50);
		Max.borrar();
		Max.NICO();
		Comida.borrar();
		Comida.COORD(_xX,_yY);
		Comida.pintar();
		
	}
	
}




/**************************************************************************************************
						CLASE CPU (CPU)
***************************************************************************************************/

// Hacemos un objeto carro
class CPU{
    int x,y,Score,Vidas;
public:
    // Constructor que tine como parametros las cooredenadas del carro
    CPU(int _x,int _y);
    // Obtener las coordenadas(privadas) del Carro
    int X(){ return x; }
    int Y(){ return y; }
	
	int S(){ return Score; } // Obtener los puntos
	int V(){ return Vidas; } // Obtener Vidas
	
	void SC(int A){ Score = A;  } // Agregar Scores
	void VC(int B){ Vidas = B;  } // Agregar Vidas

    void borrar(); // Borrar el jugador
    void pintar(); // Pintar / Dibujar el jugador
	void COOL(); // Pintar / Dibujar Colision
	void NICO(); // Pintar / Dibujar a coordenadas especificas
	
    // Jugador
    void moverCPU(class APPLE &comida);

};

CPU::CPU(int _x,int _y){	
	x = _x;
	y = _y;
	Score=0;
	Vidas=10;
	pintar();
}

void CPU::pintar(){
	gotoxy(2,2); std::cout << "Vidas: " << Vidas << std::endl;
	gotoxy(90,2); std::cout << "Score: " << Score << std::endl;
	
	if(Vidas > 0){
		gotoxy(x+2,y); printf("0");
		gotoxy(x+1,y+1); printf("000");
		gotoxy(x+2,y+2); printf("0");
	}
}

void CPU::borrar(){
	//Pintar Score
	
	gotoxy(x+2,y); printf(" ");
	gotoxy(x+1,y+1); printf("   ");
	gotoxy(x+2,y+2); printf(" ");
}

void CPU::moverCPU(class APPLE &comida){
	//gotoxy(22,2); printf("X=%d  y Y=%d ",x,y);
	int _CxX = comida.X(); 
	int _CyY = comida.Y();
	
	int _xX = rand()%89 + 4;
	int _yY = rand()%29 + 4;
	


 	if( x+2 < _CxX  &&  x   > 3  ){ borrar(); x++; pintar(); } // IZQUIERDA
	if( y+2 > _CyY  &&  y   > 4  ){ borrar(); y--; pintar(); } // ARRIBA
	if( x+2 > _CxX  &&  x+2 < 95 ){ borrar(); x--; pintar(); } // DERECHA
	if( y+2 < _CyY  &&  y+2 < 32 ){ borrar(); y++; pintar(); } // ABAJO
	
	if( x+2 == _CxX){
		comida.borrar();
		comida.COORD(_xX,_yY);
		comida.pintar();	
	}
}

void CPU::COOL(){
	gotoxy(x+2,y); printf("*");
	gotoxy(x+1,y+1); printf("***");
	gotoxy(x+2,y+2); printf("*");
}

void CPU::NICO(){
	x=4;
	y=4;
	pintar();
}

/**************************************************************************************************
						FUNCIONES
***************************************************************************************************/
