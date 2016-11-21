#pragma once

#include "CTablero.h"
#include <math.h>
#include <fstream>
using namespace System;
using namespace System::Drawing;
#define COLENEMIGO 3
#define I 3000
class CPadreEnemigo
{
private:
	CTablero* objTablero;
	int x,y;
	int ancho,largo;
	int dx,dy;
	int indice;
	int cambio;
	enum  TypeMove { Estatico, Derecha, Izquierda, Arriba, Abajo };
	TypeMove Direccion;
	bool choco;
	int N_Enemigo;
	int XBomba, YBomba;
	bool Enemigo_PERDIO;
	int N,M;
	int X_Pirata,Y_Pirata;
	int x_Tesoro,Y_Tesoro;
	vector<vector<int>> vecMovBFS;
	vector<vector<int>> vecMovDFS;
	bool enemigo_Gano;
	int M_Visitas[13][13];
public:
	CPadreEnemigo(int x,int y,int ancho,int largo,int dx,int dy,int N_Enemigo);
	~CPadreEnemigo();
	void dibujar(Graphics^ g, Bitmap^ imgEnemigo1, Bitmap^ imgEnemigo2, Bitmap^ imgEnemigo3, Bitmap^ imgEnemigo4);
	void Mover(CTablero* objTableroF);
	void MoverEnemigo(CTablero* objTablero);
	void Set_Direccion(Keys Tecla);
	void Set_direccion_Char(char Tecla);
	void DFS(int X_Pirata,int Y_Pirata,int X_Tesoro,int Y_Tesoro,int i);
	void BFS(int nivel);
	double Distancia(int X_Pirata, int Y_Pirata, int X_Tesoro, int Y_Tesoro);//GREDDY
	char Dire(int X_Pirata, int Y_Pirata, int X_Tesoro, int Y_Tesoro,int nivel);
	bool Estado_Bomberman();
	void CargarMatriz(int nivel);
	int POSX_Tesoro();
	int POSY_Tesoro();
	int Get_indiceY();
	string Cadena_Camino(int X_Pirata, int Y_Pirata, int X_Tesoro, int Y_Tesoro);//GREDDY
	void greedy(int nivel);
	bool enemigo_Gana(int nivel);
	void PosiMov(int nivel);

	//************************DFS

	void DFS_Mel(int nivel);
};

CPadreEnemigo::CPadreEnemigo(int x,int y,int ancho,int largo,int dx,int dy,int N_Enemigo)
{
	this->x=x;
	this->y=y;
	this->ancho=ancho;
	this->largo=largo;
	this->dx= ancho / COLENEMIGO;
	this->dy = largo / COLENEMIGO;
	this->indice=0;
	this->N_Enemigo=N_Enemigo;
	this->X_Pirata=X_Pirata;
	this->Y_Pirata=Y_Pirata;
	this->x_Tesoro=x_Tesoro;
	this->Y_Tesoro=Y_Tesoro;
	this->cambio = cambio;
	this->Direccion= TypeMove::Estatico;
	enemigo_Gano=false;
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			M_Visitas[i][j]=0;
		}
	}
	
}
CPadreEnemigo::~CPadreEnemigo()
{
}
int CPadreEnemigo::Get_indiceY()
{
	int indiceY = 0;

	switch (Direccion)
	{
	case TypeMove::Arriba: indiceY = 0; break;
	case TypeMove::Izquierda: indiceY = 1; break;
	case TypeMove::Abajo: indiceY = 2; break;
	case TypeMove::Derecha: indiceY = 3; break;
	}
	return indiceY;
}
void CPadreEnemigo::dibujar(Graphics^ g, Bitmap^ imgEnemigo1,Bitmap^ imgEnemigo2, Bitmap^ imgEnemigo3, Bitmap^ imgEnemigo4)
{
	if (N_Enemigo == 1) {
		int anchoI = imgEnemigo1->Width / COLENEMIGO;
		int largoI = imgEnemigo1->Height / 4;
		Rectangle Origen = Rectangle(indice*anchoI, Get_indiceY()*largoI, anchoI, largoI);
		Rectangle Destino = Rectangle(x, y, ancho, largo);
		g->DrawImage(imgEnemigo1, Destino, Origen, GraphicsUnit::Pixel);
		
	}
	if (N_Enemigo == 2) {
		int anchoI = imgEnemigo2->Width / COLENEMIGO;
		int largoI = imgEnemigo2->Height / 4;
		Rectangle Origen = Rectangle(indice*anchoI, Get_indiceY()*largoI, anchoI, largoI);
		Rectangle Destino = Rectangle(x, y, ancho, largo);
		g->DrawImage(imgEnemigo2, Destino, Origen, GraphicsUnit::Pixel);
		
	}
	if (N_Enemigo == 3) {
		int anchoI = imgEnemigo3->Width / COLENEMIGO;
		int largoI = imgEnemigo3->Height / 4;
		Rectangle Origen = Rectangle(indice*anchoI, Get_indiceY()*largoI, anchoI, largoI);
		Rectangle Destino = Rectangle(x, y, ancho, largo);
		g->DrawImage(imgEnemigo3, Destino, Origen, GraphicsUnit::Pixel);
		
	}
	if (N_Enemigo == 4) {
		int anchoI = imgEnemigo4->Width / COLENEMIGO;
		int largoI = imgEnemigo4->Height / 4;
		Rectangle Origen = Rectangle(indice*anchoI, Get_indiceY()*largoI, anchoI, largoI);
		Rectangle Destino = Rectangle(x, y, ancho, largo);
		g->DrawImage(imgEnemigo4, Destino, Origen, GraphicsUnit::Pixel);

	}

	if (Direccion == TypeMove::Estatico)
		return;
	if (indice == COLENEMIGO) {
		indice = 0;
		Direccion = TypeMove::Estatico;
	}
	else {
		Mover(objTablero);
		indice++;
	}
	
}
void CPadreEnemigo::Mover(CTablero* objTablero)
{
	switch (Direccion)
	{
	case TypeMove::Arriba:
		
		y -= dy; break;
	case TypeMove::Derecha:
		
		x += dx; break;
	case TypeMove::Abajo:
		
		y += dy; break;
	case TypeMove::Izquierda:
		
		x -= dx; break;
	}
	
}
bool CPadreEnemigo::Estado_Bomberman()
{
	//if(condisión de pirarata llegoal tesoro)
	//{
		Enemigo_PERDIO=false;
	//}
	//else Enemigo_PERDIO=true;
	return Enemigo_PERDIO;
}
void CPadreEnemigo::MoverEnemigo(CTablero* objTablero)
{
	switch (Direccion)
	{
	case TypeMove::Arriba:
		
		y -= dy; break;
	case TypeMove::Derecha:
		
		x += dx; break;
	case TypeMove::Abajo:
	
		y += dy; break;
	case TypeMove::Izquierda:
		
		x -= dx; break;
	}
}
void CPadreEnemigo::Set_Direccion(Keys Tecla)
{
	if (Direccion != TypeMove::Estatico)
		return;

	switch (Tecla)
	{
	case Keys::W: Direccion = TypeMove::Arriba; break;
	case Keys::A: Direccion = TypeMove::Izquierda; break;
	case Keys::S: Direccion = TypeMove::Abajo; break;
	case Keys::D: Direccion = TypeMove::Derecha; break;
	}
}
void CPadreEnemigo::Set_direccion_Char(char Tecla)
{
	if (Direccion != TypeMove::Estatico)
		return;

	switch (Tecla)
	{
	case 'W': Direccion = TypeMove::Arriba; break;
	case 'A': Direccion = TypeMove::Izquierda; break;
	case 'S': Direccion = TypeMove::Abajo; break;
	case 'D': Direccion = TypeMove::Derecha; break;
	}
}

/*int CPadreEnemigo::POSX_Tesoro()
{
	int X_Tesoro;
	for (int i = 0; i < 13; i++){
		for (int j = 0; j < 13; j++){
			if(vecEstado[i][j]==3)
				{
					X_Tesoro=j;
			}
		}
	}
	return X_Tesoro;
}*/
/*int CPadreEnemigo::POSY_Tesoro()
{
	int Y_Tesoro;
	for (int i = 0; i < 13; i++){
		for (int j = 0; j < 13; j++){
			if(vecEstado[i][j]==3)
				{
					Y_Tesoro=i;
			}
		}
	}
	return Y_Tesoro;
}*/
//void CPadreEnemigo::DFS(int X_Pirata,int Y_Pirata,int X_Tesoro,int Y_Tesoro,int i)
//{
//	//X_Pirata y Y_Pirata lo pongo yo 
//	X_Tesoro=POSX_Tesoro();
//	Y_Tesoro=POSY_Tesoro();
//	//vecEstado[Y_Pirata][X_Pirata]=4;
//	vector < vector<char>> cadena;
//	if (i != 0) {
//		for (int t = 0; t < 13; t++) {
//			for (int j = 0; j < 13; j++) {
//				if (Dire(X_Pirata, Y_Pirata, X_Tesoro, Y_Tesoro) == 'A')
//				{
//					if (vecEstado[Y_Pirata][X_Pirata - 1] == 2) { 
//						DFS(X_Pirata-i, Y_Pirata, X_Tesoro, Y_Tesoro, 0); break;
//					}
//					else { X_Pirata = X_Pirata - 1; cadena[i].push_back('A');
//					}
//				}
//				if (Dire(X_Pirata, Y_Pirata, X_Tesoro, Y_Tesoro) == 'D')
//				{
//					if (vecEstado[Y_Pirata][X_Pirata + 1] == 2) {
//						DFS(X_Pirata+i, Y_Pirata, X_Tesoro, Y_Tesoro, 0); break;
//					}
//					else { X_Pirata = X_Pirata + 1; cadena[i].push_back('D');
//					}
//				}
//				if (Dire(X_Pirata, Y_Pirata, X_Tesoro, Y_Tesoro) == 'W')
//				{
//					if (vecEstado[Y_Pirata-1][X_Pirata ] == 2) { 
//						DFS(X_Pirata, Y_Pirata-i, X_Tesoro, Y_Tesoro, 0);  break;
//					}
//					else { Y_Pirata = Y_Pirata - 1; cadena[i].push_back('W');
//					}
//				}
//				if (Dire(X_Pirata, Y_Pirata, X_Tesoro, Y_Tesoro) == 'S')
//				{
//					if (vecEstado[Y_Pirata+1][X_Pirata] == 2) { 
//						DFS(X_Pirata, Y_Pirata+i, X_Tesoro, Y_Tesoro, 0);  break;
//					}
//					else { Y_Pirata = Y_Pirata + 1; cadena[i].push_back('S');
//					}
//				}
//
//			}
//		}
//		if (Distancia(X_Pirata, Y_Pirata, X_Tesoro, Y_Tesoro) == 0)i++;
//	}
//}
void CPadreEnemigo::BFS(int nivel)
{
	int mapita[13][13];
	int mapa_1[13][13]= { { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 2, 2, 2, 3, 2, 2, 1, 2, 2, 0 },
	{ 0, 2, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 0 },
	{ 0, 2, 1, 2, 1, 2, 1, 2, 2, 1, 2, 2, 0 },
	{ 0, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 0 },
	{ 0, 2, 2, 2, 1, 2, 1, 2, 1, 1, 1, 2, 0 },
	{ 0, 2, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 0 },
	{ 0, 2, 1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 0 },
	{ 0, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 0 },
	{ 0, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

	int mapa_2[13][13] = { { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 2, 1, 1, 1, 1, 2, 1, 1, 3, 0 },
	{ 0, 1, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 0 },
	{ 0, 1, 1, 2, 1, 2, 2, 1, 1, 1, 2, 2, 0 },
	{ 0, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 1, 0 },
	{ 0, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 0 },
	{ 0, 1, 2, 2, 1, 2, 1, 2, 2, 2, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 1, 0 },
	{ 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

	int mapa_3[13][13] = {{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, },
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
	{ 0, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 2, 0, },
	{ 0, 2, 2, 1, 2, 1, 2, 1, 2, 2, 2, 2, 0, },
	{ 0, 1, 1, 1, 2, 1, 2, 1, 1, 2, 2, 2, 0, },
	{ 0, 1, 2, 2, 2, 1, 2, 2, 1, 2, 1, 1, 0, },
	{ 0, 1, 2, 1, 2, 1, 3, 2, 1, 2, 2, 1, 0, },
	{ 0, 1, 2, 1, 2, 2, 2, 2, 1, 2, 1, 1, 0, },
	{ 0, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 0, },
	{ 0, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 0, },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 0, },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	int mapa_4[13][13] = { { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 0 },
	{ 0, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 0 },
	{ 0, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 0 },
	{ 0, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 0 },
	{ 0, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 0 },
	{ 0, 2, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 0 },
	{ 0, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 0 },
	{ 0, 1, 1, 1, 1, 2, 2, 1, 2, 1, 1, 1, 0 },
	{ 0, 3, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	switch (nivel)
	{
	case 1:

		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_1[i][j];
			}
		}break;
	case 2:
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_2[i][j];
			}
		}break;
	case 3:
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_3[i][j];
			}
		}break;
	case 4:
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_4[i][j];
			}
		}break;
	default:
		break;
	}

	
	if ((mapita[y/42- 1][x/42] == 1 || mapita[y/42 - 1][x/42] == 3)&&M_Visitas[y/42 - 1][x/42]==0)
		{
			int un=y/42,du=x/42;
			M_Visitas[y/42][x/42]=1;
			Direccion = TypeMove::Arriba; 
		}
	else if ((mapita[y/42 + 1][x/42] == 1 || mapita[y/42 + 1][x/42] == 3)&&M_Visitas[y/42 + 1][x/42]==0)
	{
			int un=y/42,du=x/42;
		M_Visitas[y/42][x/42]=1;
		Direccion = TypeMove::Abajo;
	}
	else if ((mapita[y/42][x/42 + 1] == 1 || mapita[y/42][x/42 + 1] == 3)&&M_Visitas[y/42][x/42 + 1] ==0)
	{
			int un=y/42,du=x/42;

		M_Visitas[y/42][x/42] =1;
		Direccion = TypeMove::Derecha;
	}
	else if((mapita[y/42][x/42-1] == 1 || mapita[y/42][x/42-1] == 3)&&M_Visitas[y/42][x/42-1]==0)
	{
			int un=y/42,du=x/42;

		M_Visitas[y/42][x/42]=1;
		Direccion = TypeMove::Izquierda;
	}
	else{
		if ((mapita[y/42- 1][x/42] == 1 || mapita[y/42 - 1][x/42] == 3)&&M_Visitas[y/42 - 1][x/42]==1)
		{
			M_Visitas[y/42 ][x/42]=2;
			Direccion = TypeMove::Arriba; 
		}
	else if ((mapita[y/42 + 1][x/42] == 1 || mapita[y/42 + 1][x/42] == 3)&&M_Visitas[y/42 + 1][x/42]==1)
	{
		M_Visitas[y/42 ][x/42]=2;
		Direccion = TypeMove::Abajo;
	}
	else if ((mapita[y/42][x/42 + 1] == 1 || mapita[y/42][x/42 + 1] == 3)&&M_Visitas[y/42][x/42 + 1] ==1)
	{
		M_Visitas[y/42][x/42 ] =2;
		Direccion = TypeMove::Derecha;
	}
	else if((mapita[y/42][x/42-1] == 1 || mapita[y/42][x/42-1] == 3)&&M_Visitas[y/42][x/42-1]==1)
	{
		M_Visitas[y/42][x/42]=2;
		Direccion = TypeMove::Izquierda;
	}
	}
}
double CPadreEnemigo::Distancia(int X_Pirata, int Y_Pirata, int X_Tesoro, int Y_Tesoro)
{
	int dist_x=X_Tesoro-X_Pirata;
	int dist_y=Y_Tesoro-Y_Pirata;
	return sqrt(dist_x*dist_x+dist_y*dist_y);
}
char CPadreEnemigo::Dire(int X_Pirata, int Y_Pirata, int X_Tesoro, int Y_Tesoro,int nivel)
{
	int mapita[13][13];
	int mapa_1[13][13]= { { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 2, 2, 2, 3, 2, 2, 1, 2, 2, 0 },
	{ 0, 2, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 0 },
	{ 0, 2, 1, 2, 1, 2, 1, 2, 2, 1, 2, 2, 0 },
	{ 0, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 0 },
	{ 0, 2, 2, 2, 1, 2, 1, 2, 1, 1, 1, 2, 0 },
	{ 0, 2, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 0 },
	{ 0, 2, 1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 0 },
	{ 0, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 0 },
	{ 0, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

	int mapa_2[13][13] = { { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 2, 1, 1, 1, 1, 2, 1, 1, 3, 0 },
	{ 0, 1, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 0 },
	{ 0, 1, 1, 2, 1, 2, 2, 1, 1, 1, 2, 2, 0 },
	{ 0, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 1, 0 },
	{ 0, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 0 },
	{ 0, 1, 2, 2, 1, 2, 1, 2, 2, 2, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 1, 0 },
	{ 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

	int mapa_3[13][13] = {{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, },
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
	{ 0, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 2, 0, },
	{ 0, 2, 2, 1, 2, 1, 2, 1, 2, 2, 2, 2, 0, },
	{ 0, 1, 1, 1, 2, 1, 2, 1, 1, 2, 2, 2, 0, },
	{ 0, 1, 2, 2, 2, 1, 2, 2, 1, 2, 1, 1, 0, },
	{ 0, 1, 2, 1, 2, 1, 3, 2, 1, 2, 2, 1, 0, },
	{ 0, 1, 2, 1, 2, 2, 2, 2, 1, 2, 1, 1, 0, },
	{ 0, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 0, },
	{ 0, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 0, },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 0, },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	int mapa_4[13][13] = { { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 0 },
	{ 0, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 0 },
	{ 0, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 0 },
	{ 0, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 0 },
	{ 0, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 0 },
	{ 0, 2, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 0 },
	{ 0, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 0 },
	{ 0, 1, 1, 1, 1, 2, 2, 1, 2, 1, 1, 1, 0 },
	{ 0, 3, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	switch (nivel)
	{
	case 1:

		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_1[i][j];
			}
		}break;
	case 2:
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_2[i][j];
			}
		}break;
	case 3:
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_3[i][j];
			}
		}break;
	case 4:
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_4[i][j];
			}
		}break;
	default:
		break;
	}
	char dir;
	double D_arriba = Distancia(X_Pirata, Y_Pirata-1, X_Tesoro, Y_Tesoro);
	double D_abajo = Distancia(X_Pirata, Y_Pirata+1, X_Tesoro, Y_Tesoro);
	double D_derecha = Distancia(X_Pirata+1, Y_Pirata, X_Tesoro, Y_Tesoro);
	double D_izquierda = Distancia(X_Pirata-1, Y_Pirata, X_Tesoro, Y_Tesoro);
	if (D_arriba<=D_abajo&&D_arriba <=D_derecha &&D_arriba <=D_izquierda)dir = 'W';
	else if (D_abajo <= D_arriba&&D_abajo <=D_derecha &&D_abajo <=D_izquierda)dir = 'S';
	else if (D_derecha <= D_arriba&&D_derecha <=D_abajo &&D_derecha <=D_izquierda)dir = 'D';
	else if (D_izquierda<=D_abajo&&D_izquierda <=D_derecha &&D_izquierda <=D_arriba) dir = 'A';
	return dir;
}
/*string CPadreEnemigo::Cadena_Camino(int X_Pirata, int Y_Pirata, int X_Tesoro, int Y_Tesoro)
{
	string s; char Letra;
	int dist = Distancia(X_Pirata, Y_Pirata, X_Tesoro, Y_Tesoro);
	while (dist != 0)
	{
		dist = Distancia(X_Pirata, Y_Pirata, X_Tesoro, Y_Tesoro);
		Letra=Dire(X_Pirata, Y_Pirata, X_Tesoro, Y_Tesoro);
		switch (Letra)
		{
		case 'W':Y_Pirata = Y_Pirata - 1; s = s + 'W'; break;
		case 'S':Y_Pirata = Y_Pirata + 1; s = s + 'S'; break;
		case 'A':X_Pirata = X_Pirata - 1; s = s + 'A'; break;
		case 'D':X_Pirata = X_Pirata + 1; s = s + 'D'; break;
		default:
			break;
		}
	}
	return s;
}*/
bool CPadreEnemigo::enemigo_Gana(int nivel)
{
	switch (nivel)
	{
	case 1:
		if(x/42==6&&y/42==3)enemigo_Gano=true;
		break;
	case 2:
		if(x/42==11&&y/42==3)enemigo_Gano=true;
		break;
	case 3:
		if(x/42==6&&y/42==7)enemigo_Gano=true;
		break;
	case 4:
		if(x/42==1&&y/42==11)enemigo_Gano=true;
		break;
	default:
		break;
	}
	return enemigo_Gano;
}
void CPadreEnemigo::DFS_Mel(int nivel){
	int Tesoro_X,Tesoro_Y;
	int vecEstado[13][13]={ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};
	int mapita[13][13];
	int mapa_1[13][13]= { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0 },
	{ 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0 },
	{ 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0 },
	{ 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

	int mapa_2[13][13] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0 },
	{ 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0 },
	{ 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0 },
	{ 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0 },
	{ 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0 },
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

	int mapa_3[13][13] = {{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
	{ 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, },
	{ 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, },
	{ 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, },
	{ 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, },
	{ 0, 1, 0, 1, 0, 1, 3, 0, 1, 0, 0, 1, 0, },
	{ 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, },
	{ 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, },
	{ 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	int mapa_4[13][13] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0 },
	{ 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0 },
	{ 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0 },
	{ 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0 },
	{ 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	switch (nivel)
	{
	case 1:
		Tesoro_X=6;Tesoro_Y=3;
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_1[i][j];
			}
		}
		break;
	case 2:
		Tesoro_X=11;Tesoro_Y=3;
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_2[i][j];
			}
		}
		break;
		/*
	case 3:
		Tesoro_X=6;Tesoro_Y=7;
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_3[i][j];
			}
		}
		break;
	case 4:
		Tesoro_X=1;Tesoro_Y=11;
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_4[i][j];
			}
		}
		break;*/
	default:
		break;
	}
	

}
void CPadreEnemigo::greedy(int nivel)
{
	int mapa_1[13][13]= { { I, I, I, I, I, I, I, I, I, I, I, I, I },
	{ I, I,  I,  I,  I,  I, I, I, I,  I, I, I, I },
	{ I, I,  I,  I,  I,  I, I, I, I,  I, I, I, I },
	{ I, 23, 22, I,  I,  I, 0, I, I,  15, I,  I, I },
	{ I, I,  21, I,  I,  I, 1, I, 15, 14, I,  I, I },
	{ I, I,  20, I,  18, I, 2, I, I,  13, I,  I, I },
	{ I, 20, 19, 18, 17, I, 3, I, 11, 12, 14, I, I },
	{ I, I,  I,  I,  16, I, 4, I, 10, 11, 13, I, I },
	{ I, I,  13, 14, 15, I, 5, I, 9,  I,  15, I, I },
	{ I, I,  12, I,  I,  I, 6, 7, 8,  I,  16, 17, I },
	{ I, I,  11, 10, 9,  8, 7, I, I,  I,  I,  18, I },
	{ I, I,  I,  I,  I,  I, I, I, 22, 21, 20,  9, I },
	{ I, I,  I,  I,  I,  I, I, I, I,  I,  I, I, I } };

	int mapa_2[13][13] = { { I, I, I, I, I, I, I, I, I, I, I, I, I },
	{ I, I, I, I, I, I, I, I, I, I, I, I, I },
	{ I, I, I, I, I, I, I, I, I, I, I, I, I },
	{ I, 28, I,  I,  11, 10, 9,  8,  I,  2,  1,  0, I },
	{ I, 27, I,  I,  12, I,  I,  7,  I,  3,  I,  I, I },
	{ I, 26, 25, I,  13, I,  I,  6,  5,  4,  I,  I, I },
	{ I, I,  24, I,  14, I,  I,  I,  I,  I,  38, 39, I },
	{ I, 22, 23, I,  15, I,  41, 40,  39,  38,  37, I, I },
	{ I, 21, I,  I,  16, I,  42, I,  I,  I,  36, 35, I },
	{ I, 20, 19, 18, 17, I,  43, 44,  45,  I,  I,  34, I },
	{ I, 21, I,  I,  I,  I,  I,  I,  I,  I,  I,  33, I },
	{ I, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, I },
	{ I, I, I, I, I, I, I, I, I, I, I, I, I } };

	int mapa_3[13][13] = {{ I, I, I, I, I, I, I, I, I, I, I, I, I, },
	{ I, I, I, I, I, I, I, I, I, I, I, I, I, },
	{ I, I, I, I, I, I, I, I, I, I, I, I, I, },
	{ I, 35, 34, 33, I,  5,  6,  7,  8,   9,  I,  I, I, },
	{ I, I,  I,  32, I,  4,  I,  8,  I,   I,  I,  I, I, },
	{ I, 29, 30, 31, I,  3,  I,  9,  10,  I,  I,  I, I, },
	{ I, 28, I,  I,  I,  2,  I,  I,  11,  I,  23, 22, I, },
	{ I, 27, I,  21, I,  1,  0,  I,  12,  I,  I,  21, I, },
	{ I, 26, I,  20, I,  I,  I,  I,  13,  I,  21, 22, I, },
	{ I, 25, I,  19, 18, 17, 16, 15, 14,  I,  19, 23, I, },
	{ I, 24, I,  I,  I,  I,  I,  I,  15,  17, 18, 24, I, },
	{ I, 23, 22, 21, 20, 19, 18, 17, 16,  I,  I,  25, I, },
	{ I, I, I, I, I, I, I, I, I, I, I, I, I } };
	int mapa_4[13][13] = { { I, I, I, I, I, I, I, I, I, I, I, I, I },
	{ I, I, I, I, I, I, I, I, I, I, I, I, I },
	{ I, I, I, I, I, I, I, I, I, I, I, I, I },
	{ I, 30, 29, 28, 27, 26, 25,  I,  19, 18, 17,  I, I },
	{ I, I,  I,  I,  I,  I,  25,  I,  20, I,  16,  I, I },
	{ I, I,  1,  1,  1,  I,  24,  22, 21, I,  15,  I, I },
	{ I, I,  1,  I,  1,  I,  I,   I,  I,  I,  14,  I, I },
	{ I, I,  1 , I,  7 , 8 , 9 ,  10, 11, 12, 13,  I, I },
	{ I, I,  1,  1,  6,  I,  I,   I,  I,  I,  14,  15, I },
	{ I, I,  I,  I,  5,  I,  I,   24, I,  I,  I,   16, I },
	{ I, 1,  2,  3,  4,  I,  I,   23, I,  21, 18,  17, I },
	{ I, 0,  I,  I,  I,  I,  I,   22, 21, 20, 19,  18, I },
	{ I, I,  I,  I,  I,  I,  I,   I,  I,  I,  I,   I, I } };
	int mapita[13][13];
	switch (nivel)
	{
	/*case 1:

		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_1[i][j];
			}
		}break;
	case 2:
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_2[i][j];
			}
		}break;*/
	case 3:
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_3[i][j];
			}
		}break;
	case 4:
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mapita[i][j] = mapa_4[i][j];
			}
		}break;
	default:
		break;
	}

	
	if (mapita[y/42- 1][x/42] < mapita[y/42][x/42] )
		{
			int un=y/42,du=x/42;
			//M_Visitas[y/42][x/42]=1;
			Direccion = TypeMove::Arriba; 
		}
	else if (mapita[y/42 + 1][x/42]< mapita[y/42][x/42])
	{
			int un=y/42,du=x/42;
		//M_Visitas[y/42][x/42]=1;
		Direccion = TypeMove::Abajo;
	}
	else if (mapita[y/42][x/42 + 1] < mapita[y/42][x/42])
	{
			int un=y/42,du=x/42;

		//M_Visitas[y/42][x/42] =1;
		Direccion = TypeMove::Derecha;
	}
	else if(mapita[y/42][x/42-1]< mapita[y/42][x/42])
	{
			int un=y/42,du=x/42;

		//M_Visitas[y/42][x/42]=1;
		Direccion = TypeMove::Izquierda;
	}
	
}
	void CPadreEnemigo::PosiMov(int nivel)
	{
		switch (nivel)
		{
		case 1:
			BFS(nivel);
			break;
		case 2:
			BFS(nivel);

			break;
		case 3:
			greedy(nivel);
			break;
		case 4:
			greedy(nivel);

			break;
		default:
			break;
		}
	}
