#pragma once
using namespace System::Drawing;

class CMenu
{
private:
	int x, y;
	int ancho, largo;
	int cambio;

public:
	CMenu(int x, int y, int ancho, int largo,int cambio);
	~CMenu();

	void Dibujar(Graphics ^g, Bitmap ^Menu1, Bitmap ^Menu2,Bitmap^ imgInstrucciones,Bitmap^ imgGanaste,Bitmap^ imgGameOver); //, Bitmap ^BarraEstado);
};

CMenu::CMenu(int x, int y, int ancho, int largo, int cambio)
{
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->largo = largo;
	this->cambio = cambio;
}
CMenu::~CMenu()
{}
void CMenu::Dibujar(Graphics ^g, Bitmap ^Menu1, Bitmap ^Menu2,Bitmap^ imgInstrucciones,Bitmap^ imgGanaste,Bitmap^ imgGameOver) //, Bitmap ^BarraEstado)
{
	if (cambio == 0){
		Rectangle recFondo = Rectangle(0, 0, Menu1->Width, Menu1->Height);
		g->DrawImage(Menu1, g->VisibleClipBounds, recFondo, GraphicsUnit::Pixel);
	}
	if (cambio == 1){
		Rectangle recFondo = Rectangle(0, 0, Menu2->Width, Menu2->Height);
		g->DrawImage(Menu2, g->VisibleClipBounds, recFondo, GraphicsUnit::Pixel);
	}
	if (cambio == 9){
		Rectangle recFondo = Rectangle(0, 0, imgInstrucciones->Width, imgInstrucciones->Height);
		g->DrawImage(imgInstrucciones, g->VisibleClipBounds, recFondo, GraphicsUnit::Pixel);
	}
	if (cambio == 3){
		Rectangle recFondo = Rectangle(0, 0, imgGanaste->Width, imgGanaste->Height);
		g->DrawImage(imgGanaste, g->VisibleClipBounds, recFondo, GraphicsUnit::Pixel);
	}
	if (cambio == 5){
		Rectangle recFondo = Rectangle(0, 0, imgGameOver->Width, imgGameOver->Height);
		g->DrawImage(imgGameOver, g->VisibleClipBounds, recFondo, GraphicsUnit::Pixel);
	}
	/*if (cambio == 2){
		Rectangle recFondo = Rectangle(0, 0, BarraEstado->Width, BarraEstado->Height);
		g->DrawImage(BarraEstado, g->VisibleClipBounds, recFondo, GraphicsUnit::Pixel);
	}*/
}