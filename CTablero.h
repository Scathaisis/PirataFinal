#pragma once
#include <vector>
#include "CCelda.h"

using namespace std;

class CTablero
{
private:
	vector <vector<CCelda*>> arrCelda;
	int N, M;
	int ancho, largo;
	bool caminar;

public:
	CTablero(int x, int y, int ancho, int largo,int nivel);
	~CTablero();
	char Contenido[13][13];
	void Set_Nivel(int Nivel, int x, int y);
	void Dibujar(Graphics ^g, Bitmap ^imgCelda); //, Bitmap ^imgCamino1, Bitmap ^imgMarco1, Bitmap ^imgRoca1, Bitmap ^imgRocaRomper);
	bool Si_caminar(int x, int y);

};

CTablero::CTablero(int x, int y, int ancho, int largo,int nivel)
{
	this->ancho = ancho;
	this->largo = largo;

	Set_Nivel(nivel, x, y);
	
}
CTablero::~CTablero()
{}
void CTablero::Set_Nivel(int Nivel, int x, int y)
{
	//char *Archivo = new char[100];
	int mapita[13][13];
	int estado = -1;
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
	{ 0, 1, 2, 2, 1, 1, 1, 1, 2, 1, 1, 3,	0 },
	{ 0, 1, 2, 2,	1, 2, 2, 1,	2, 1, 2, 2,	0 },
	{ 0, 1, 1, 2, 1, 2, 2, 1, 1, 1, 2, 2,	0 },
	{ 0, 2, 1, 2,	1, 2, 2, 2,	2, 2, 1, 1,	0 },
	{ 0, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2,	0 },
	{ 0, 1, 2, 2,	1, 2, 1, 2,	2, 2, 1, 1,	0 },
	{ 0, 1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 1,	0 },
	{ 0, 1, 2, 2,	2, 2, 2, 2,	2, 2, 2, 1,	0 },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,	0 },
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
	 switch (Nivel)
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

	//FILE* pF = freopen(Archivo, "r", stdin);

	//scanf("%d %d", &N, &M); 
	 N = 13; M = 13;
	 arrCelda.resize(13);
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			estado = mapita[i][j];
			CCelda* objCelda = new CCelda(x + ancho*j, y + largo*i, ancho, largo, estado);
		    arrCelda[i].push_back(objCelda);
			/*objCelda->Get_Posicion(i,j)=estado;
			 if(objCelda->Get_Posicion(i,j)==1)
			  {
				  caminar=true;
			  }
			  else caminar=false; */
		}
	}

	//fclose(pF);	 
	
	
}
void CTablero::Dibujar(Graphics ^g,Bitmap ^imgCelda) //, Bitmap ^imgCamino1, Bitmap ^imgMarco1, Bitmap ^imgRoca1, Bitmap ^imgRocaRomper)
{
	for (int i = 0; i < arrCelda.size(); i++){
	for (int j = 0; j < arrCelda.size(); j++)
	{
		arrCelda[i][j]->Dibujar(g,imgCelda); //, imgCamino1, imgMarco1, imgRoca1, imgRocaRomper);
	}
	}
}
bool CTablero::Si_caminar(int x,int y)
{
		/*for (int i = 0; i < arrCelda.size(); i++)
		{
			for(int j=0;j<arrCelda.size;j++)
		      if(Contenido[i][j]==1)
			  {
				  caminar=true;
			  }
			  else caminar=false;
		}		*/   
		return caminar;		
}
