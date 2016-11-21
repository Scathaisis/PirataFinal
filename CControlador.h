#pragma once
#include "CMenu.h"
#include "CTablero.h"
#include "CCelda.h"
#include "CUpecino.h"

#include "CPadreEnemigo.h"
using namespace System::Drawing;
using namespace System::Windows::Forms;
class CControlador
{
private:
	int SeleccionPJ;
	int SeleccionMapa;
	int Opcion;
	int NBombas;
	CMenu *objMenu;
	CTablero *objTablero;
	CUpecino *objUpecino;
	CPadreEnemigo *objPAcdreEnemigo;

public:
	CControlador(int Opcion, int SeleccionPJ, int SeleccionMapa);
	~CControlador();

	void Dibujar_Todo(Graphics ^g, Bitmap ^imgMenu1, 
		Bitmap ^imgMenu2, Bitmap ^imgInstrucciones,Bitmap^ imgCElDANivel_N1, Bitmap^ imgCElDANivel_N2, Bitmap^ imgCElDANivel_N3, Bitmap^ imgCElDANivel_N4,
		Bitmap ^imgUpecinoBlanco, 
		Bitmap ^imgUpecinoNegro, Bitmap ^imgUpecinoDorado,Bitmap^ imgBomba,Bitmap ^imgEnemigo1, Bitmap ^imgEnemigo2,
        Bitmap ^imgEnemigo3,Bitmap ^imgEnemigo4,Bitmap^ imgGanaste,Bitmap^ imgGameOver,int anchoF,int largoF);
	void Controles(Keys Tecla);
	void PCT_VISIBLE_false(int Opcion, int SeleccionMapa,PictureBox^PB_BotonIniciar,PictureBox^PB_BotonInstrucciones,
		PictureBox^PB_BotonSalir,PictureBox^ PB_BarraEstado,PictureBox^PB_PBRetratoBlanco,PictureBox^PB_RetratoNegro,
		PictureBox^PB_RetratoDorado,PictureBox^PB_Minimapa_N1,PictureBox^PB_Minimapa_N2,PictureBox^PB_Minimapa_N3,
		PictureBox^PB_Minimapa_N4,Label^ lblMinutos,Label^ lblSegundos);
};

CControlador::CControlador(int Opcion, int SeleccionPJ, int SeleccionMapa)
{
	this->Opcion = Opcion;
	this->SeleccionPJ = SeleccionPJ;
	this->SeleccionMapa = SeleccionMapa;

	objMenu = new CMenu(0, 0, 354, 325, 0);
	objTablero = new CTablero(0, 0, 42, 42,1);
	NBombas=5;
	if (SeleccionPJ == 1)
		objUpecino = new CUpecino(0, 0, 42, 42, 1,NBombas);
	if (SeleccionPJ == 2)
		objUpecino = new CUpecino(0, 0, 42, 42, 2,NBombas);
	if (SeleccionPJ == 3)
		objUpecino = new CUpecino(0, 0, 42, 42, 3,NBombas);

}
CControlador::~CControlador()
{}
void CControlador::Dibujar_Todo(Graphics ^g, Bitmap ^imgMenu1, Bitmap ^imgInstrucciones, 
        Bitmap ^imgMenu2, Bitmap^ imgCElDANivel_N1, Bitmap^ imgCElDANivel_N2, Bitmap^ imgCElDANivel_N3, Bitmap^ imgCElDANivel_N4,Bitmap ^imgUpecinoBlanco, Bitmap ^imgUpecinoNegro,
        Bitmap ^imgUpecinoDorado,Bitmap^ imgBomba,Bitmap ^imgEnemigo1, Bitmap ^imgEnemigo2,
        Bitmap ^imgEnemigo3,Bitmap ^imgEnemigo4,Bitmap^ imgGanaste,Bitmap^ imgGameOver,int anchoF,int largoF)
{
	if (Opcion == 0){
		objMenu->Dibujar(g, imgMenu1, imgMenu2,imgInstrucciones,imgGanaste, imgGameOver);
		
	}
	if (Opcion == 1){
		objMenu->Dibujar(g, imgMenu1, imgMenu2,imgInstrucciones,imgGanaste, imgGameOver);
	}
	if (Opcion == 9){
		objMenu->Dibujar(g, imgMenu1, imgMenu2,imgInstrucciones,imgGanaste, imgGameOver);
	}
	if (SeleccionMapa == 1){
		objTablero->Set_Nivel(1, 0, 0);
		objTablero->Dibujar(g,imgCElDANivel_N1);
		objUpecino->Dibujar(g, imgUpecinoBlanco, imgUpecinoNegro, imgUpecinoDorado);
		objPAcdreEnemigo->dibujar(g,imgEnemigo1, imgEnemigo2, imgEnemigo3, imgEnemigo4) ;
		objPAcdreEnemigo->Mover(objTablero);
	}
	if (SeleccionMapa == 2){
		objTablero->Set_Nivel(2, 0, 0);
		objTablero->Dibujar(g,imgCElDANivel_N2);
		objUpecino->Dibujar(g, imgUpecinoBlanco, imgUpecinoNegro, imgUpecinoDorado);
		objPAcdreEnemigo->dibujar(g,imgEnemigo1, imgEnemigo2, imgEnemigo3, imgEnemigo4) ;
		objPAcdreEnemigo->Mover(objTablero);
	}
	if (SeleccionMapa == 3){
		objTablero->Set_Nivel(3, 0, 0);
		objTablero->Dibujar(g,imgCElDANivel_N3);
		objUpecino->Dibujar(g, imgUpecinoBlanco, imgUpecinoNegro, imgUpecinoDorado);
		objPAcdreEnemigo->dibujar(g, imgEnemigo1, imgEnemigo2, imgEnemigo3, imgEnemigo4) ;
		objPAcdreEnemigo->Mover(objTablero);
	}
	if (SeleccionMapa == 4){
		objTablero->Set_Nivel(4, 0, 0);
		objTablero->Dibujar(g,imgCElDANivel_N4);
		objUpecino->Dibujar(g, imgUpecinoBlanco, imgUpecinoNegro, imgUpecinoDorado);
		objPAcdreEnemigo->dibujar(g, imgEnemigo1, imgEnemigo2, imgEnemigo3, imgEnemigo4) ;
		objPAcdreEnemigo->Mover(objTablero);
	}
}
/*void CControlador::Controles(Keys Tecla)
{
	objUpecino->Set_Direccion(Tecla);
}*/
void CControlador::PCT_VISIBLE_false(int Opcion, int SeleccionMapa,PictureBox^PB_BotonIniciar,PictureBox^PB_BotonInstrucciones,
		PictureBox^PB_BotonSalir,PictureBox^ PB_BarraEstado,PictureBox^PB_PBRetratoBlanco,PictureBox^PB_RetratoNegro,
		PictureBox^PB_RetratoDorado,PictureBox^PB_Minimapa_N1,PictureBox^PB_Minimapa_N2,PictureBox^PB_Minimapa_N3,
		PictureBox^PB_Minimapa_N4,Label^ lblMinutos,Label^ lblSegundos)
{
	if (Opcion == 0){
				 PB_BotonIniciar->Visible = true;
				 PB_BotonInstrucciones->Visible = true;
				 PB_BotonSalir->Visible = true;
				PB_BarraEstado->Visible =false;			

				// lblN_Bombas->Visible = false;
				 lblMinutos->Visible = false;
				 lblSegundos->Visible = false;
			 }
			 else if (Opcion == 1){
				 PB_BotonIniciar->Visible = false;
				 PB_BotonInstrucciones->Visible = false;
				 PB_BotonSalir->Visible = false;
				 PB_PBRetratoBlanco->Visible = true;
				 PB_RetratoNegro->Visible = true;
				 PB_RetratoDorado->Visible = true;
				 PB_Minimapa_N1->Visible = true;
				 PB_Minimapa_N2->Visible = true;
				 PB_Minimapa_N3->Visible = true;
				 PB_Minimapa_N4->Visible = true;
				PB_BarraEstado->Visible =false;			

				// lblN_Bombas->Visible = false;
				 lblMinutos->Visible = false;
				 lblSegundos->Visible = false;
			 }
			 else if (Opcion == 9){
				 PB_BotonIniciar->Visible = false;
				 PB_BotonInstrucciones->Visible = false;
				 PB_BotonSalir->Visible = false;
				 PB_PBRetratoBlanco->Visible = false;
				 PB_RetratoNegro->Visible = false;
				 PB_RetratoDorado->Visible =  false;
				 PB_Minimapa_N1->Visible =  false;
				 PB_Minimapa_N2->Visible =  false;
				 PB_Minimapa_N3->Visible =  false;
				 PB_Minimapa_N4->Visible =  false;
				PB_BarraEstado->Visible =false;			
				 //lblN_Bombas->Visible = false;
				 lblMinutos->Visible = false;
				 lblSegundos->Visible = false;
			 }
			 else if (SeleccionMapa == 1 || SeleccionMapa == 2 || SeleccionMapa == 3 || SeleccionMapa == 4){
				 PB_PBRetratoBlanco->Visible = false;
				 PB_RetratoNegro->Visible = false;
				 PB_RetratoDorado->Visible = false;
				 PB_Minimapa_N1->Visible = false;
				 PB_Minimapa_N2->Visible = false;
				 PB_Minimapa_N3->Visible = false;
				 PB_Minimapa_N4->Visible = false;
				 PB_BarraEstado->Visible = true;

				// lblN_Bombas->Visible = true;
				 lblMinutos->Visible = true;
				 lblSegundos->Visible = true;
			 }
}