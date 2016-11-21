#pragma once
using namespace System::Drawing;

class CCelda
{
private:
	int X, Y;
	int Ancho, Largo;
	int bloque;
	bool caminar;

public:
	CCelda(int x, int y, int ancho, int largo, int bloque);
	~CCelda();

	void Dibujar(Graphics ^g,Bitmap^ imgCelda); //, Bitmap ^imgCamino1, Bitmap ^imgMarco1, Bitmap ^imgRoca1, Bitmap ^imgRocaRomper);
	bool Caminando();
	int Get_Posicion(int x,int y);
};

CCelda::CCelda(int X, int Y, int Ancho, int Largo, int bloque)
{
	this->X = X;
	this->Y = Y;
	this->Ancho = Ancho;
	this->Largo = Largo;
	this->bloque = bloque;
}
CCelda::~CCelda()
{}
bool CCelda:: Caminando()
{
	
	return this->caminar;
}

void CCelda::Dibujar(Graphics^ g,Bitmap^ imgCelda)
{
	int AnchoI = imgCelda->Width / 4;
	int LargoI = imgCelda->Height;

	if (bloque == 0)
	{	caminar=false;
		Rectangle Origen = Rectangle(AnchoI, 0, AnchoI, LargoI);
		Rectangle Destino = Rectangle(X, Y, Ancho, Largo);
		g->DrawImage(imgCelda, Destino, Origen, GraphicsUnit::Pixel);
	}
	else 
    	if (bloque == 1)
    	{
			caminar=true;
    		Rectangle Origen = Rectangle(0, 0, AnchoI, LargoI);
    		Rectangle Destino = Rectangle(X, Y, Ancho, Largo);
    		g->DrawImage(imgCelda, Destino, Origen, GraphicsUnit::Pixel);
    	}
	else
		if (bloque == 2)
		{	caminar=false;
			Rectangle Origen = Rectangle(AnchoI*2, 0, AnchoI, LargoI);
			Rectangle Destino = Rectangle(X, Y, Ancho, Largo);
			g->DrawImage(imgCelda, Destino, Origen, GraphicsUnit::Pixel);
		}
	else
		if (bloque == 3)
		{	caminar=false;
			Rectangle Origen = Rectangle(AnchoI*3, 0, AnchoI, LargoI);
			Rectangle Destino = Rectangle(X, Y, Ancho, Largo);
			g->DrawImage(imgCelda, Destino, Origen, GraphicsUnit::Pixel);
		}
	else
		if (bloque == 5)
		{	caminar=false;
			g->FillRectangle(Brushes::LightGray, X, Y, Ancho, Largo);

		}
}
int CCelda::Get_Posicion(int x,int y)
{
	return this->bloque;
}