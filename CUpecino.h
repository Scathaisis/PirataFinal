#pragma once
#include <fstream>
#include "CTablero.h"
using namespace System::Drawing;
using namespace System::Windows::Forms;

#define COL 3

class CUpecino
{
private:
	int x, y;
	int dx, dy;
	int ancho, largo;
	int indice;
	int cambio;
	enum  TypeMove{ Estatico, Derecha, Izquierda, Arriba, Abajo };
	TypeMove Direccion;
	//int x_J, y_J;
	vector<int> pos_1_x;
	vector<int> pos_1_y;
	CTablero* objTablero;
	int nivel;
	bool Bomberma_PERDIO;
	bool Bomberma_Gano;
public:
	CUpecino(int x, int y, int ancho, int largo, int cambio, int nivel);
	~CUpecino();

	int Get_indiceY();

	void Dibujar(Graphics ^g, Bitmap ^imgBlanco, Bitmap ^imgNegro, Bitmap ^imgDorado);
	void Mover(CTablero* ObjTablero);
	void Set_Direccion(Keys Tecla,int nivel);
	bool Caminar();
	bool Estado_Bomberman();
	bool bomberman_Gana(int nivel);
};

CUpecino::CUpecino(int x, int y, int ancho, int largo, int cambio, int nivel)
{
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->largo = largo;
	this->dx = ancho / COL;
	this->dy = largo / COL;
	this->indice = 0;
	this->Direccion = TypeMove::Estatico;
	this->cambio = cambio;
	this->Bomberma_PERDIO=false;
	this->Bomberma_Gano=false;
	//this->x_J = 1;
	//this->y_J = 3;
	this->nivel = nivel;
	
}
CUpecino::~CUpecino()
{}
int CUpecino::Get_indiceY()
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
void CUpecino::Dibujar(Graphics ^g, Bitmap ^imgBlanco, Bitmap ^imgNegro, Bitmap ^imgDorado)
{
	if (cambio == 1){
		int anchoI = imgBlanco->Width / COL;
		int largoI = imgBlanco->Height / 4;
		Rectangle Origen = Rectangle(indice*anchoI, Get_indiceY()*largoI, anchoI, largoI);
		Rectangle Destino = Rectangle(x, y, ancho, largo);
		g->DrawImage(imgBlanco, Destino, Origen, GraphicsUnit::Pixel);
		
	}
	if (cambio == 2){
		int anchoI = imgNegro->Width / COL;
		int largoI = imgNegro->Height / 4;
		Rectangle Origen = Rectangle(indice*anchoI, Get_indiceY()*largoI, anchoI, largoI);
		Rectangle Destino = Rectangle(x, y, ancho, largo);
		g->DrawImage(imgNegro, Destino, Origen, GraphicsUnit::Pixel);
	
	}
	if (cambio == 3){
		int anchoI = imgDorado->Width / COL;
		int largoI = imgDorado->Height / 4;
		Rectangle Origen = Rectangle(indice*anchoI, Get_indiceY()*largoI, anchoI, largoI);
		Rectangle Destino = Rectangle(x, y, ancho, largo);
		g->DrawImage(imgDorado, Destino, Origen, GraphicsUnit::Pixel);
		
	}
	
	if (Direccion == TypeMove::Estatico)
		return;
	if (indice == COL){
		indice = 0;
		Direccion = TypeMove::Estatico;
	}
	else{
		Mover(objTablero);
		indice++;
	}
}
void CUpecino::Mover(CTablero* objTablero)
{
	
	switch (Direccion)
	{
	case TypeMove::Arriba:
		
	    y -= dy; break;
	case TypeMove::Derecha:
	//if (x + dx - ancho < 0 )

		//if(objTablero->Si_caminar(x+dx,y)==true)
		x += dx; break;
	case TypeMove::Abajo:
		//if (y + dy + largo < 160 )
		//if(objTablero->Si_caminar(x,y+dy)==true)
		y += dy; break;
	case TypeMove::Izquierda:
	//if (x + dx - ancho < 0 || x + dx + 2 * ancho>560)

		//if(objTablero->Si_caminar(x-dx,y)==true)
		x -= dx; break;
	}
}
void CUpecino::Set_Direccion(Keys Tecla,int nivel)
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
	switch (Tecla)
	{
	case Keys::Up:
		if (mapita[y/42- 1][x/42] == 1 || mapita[y/42 - 1][x/42] == 3)
		{
		
			Direccion = TypeMove::Arriba; 
		}
		break;
	case Keys::Right:
		if (mapita[y/42][x/42 + 1] == 1 || mapita[y/42][x/42 + 1] == 3)
		{
			
			Direccion = TypeMove::Derecha;

		}
		break;
	case Keys::Down:
		if (mapita[y/42 + 1][x/42] == 1 || mapita[y/42 + 1][x/42] == 3)
		{
			

			Direccion = TypeMove::Abajo;
		}
		break;
	case Keys::Left:
		if (mapita[y/42][x/42-1] == 1 || mapita[y/42][x/42-1] == 3)
		{
		

			Direccion = TypeMove::Izquierda;

		}
		break;
	}
	if (Direccion != TypeMove::Estatico)
		return;

}
bool CUpecino::Caminar()
{	ifstream celda;
    pos_1_x.clear();
	pos_1_y.clear();
	// matriz = new int*[13];
	return true;
}
bool CUpecino::Estado_Bomberman()
{
	//if(objVecBomba->HayColision(x+dx,y+dy)==true||objVecBombasEnemigo->HayColisionBomberman(x+dx,y+dy)==true)
	//{
		//Bomberma_PERDIO=true;
	//}
	//else 
		Bomberma_PERDIO=false;
	return Bomberma_PERDIO;
}

bool CUpecino::bomberman_Gana(int nivel)
{
	switch (nivel)
	{
	case 1:
		if(x/42==6&&y/42==3)Bomberma_Gano=true;
		break;
	case 2:
		if(x/42==11&&y/42==3)Bomberma_Gano=true;
		break;
	case 3:
		if(x/42==6&&y/42==7)Bomberma_Gano=true;
		break;
	case 4:
		if(x/42==1&&y/42==11)Bomberma_Gano=true;
		break;
	default:
		break;
	}
	return Bomberma_Gano;
}