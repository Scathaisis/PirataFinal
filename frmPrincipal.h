#pragma once
#include "CMenu.h"
#include "CTablero.h"
#include "CUpecino.h"
#include "CControlador.h"
namespace PirataFinalV12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de frmPrincipal
	/// </summary>
	public ref class frmPrincipal : public System::Windows::Forms::Form
	{
		private:
		int SeleccionPJ;
		int SeleccionMapa;
		int Opcion;

		int Minutos;
		int Segundos;
		int NBombas;
		int nivel;
	    int N_Enemigo;
		int anchoF;
		int largoF;
		int X_Pirata;
		int Y_Pirata;
		int X_Tesoro;
		int Y_Tesoro;
		int X_J;
		int Y_J;
		SoundPlayer^ SonidoMenu ;
		SoundPlayer^ SonidoJuego;
		CControlador* ObjControlador;
		CMenu *objMenu;
		CTablero *objTablero;
		CUpecino *objUpecino;
		CPadreEnemigo* objPAdreEnemigo;
		Graphics ^g;
		Bitmap ^imgMenu1;
		Bitmap ^imgMenu2;
		Bitmap ^imgInstrucciones;
		Bitmap ^imgGanaste;
		Bitmap ^imgGameOver;
		Bitmap ^imgUpecinoBlanco;
		Bitmap ^imgUpecinoNegro;
		Bitmap ^imgUpecinoDorado;
		Bitmap ^imgNivel_UNO;
		Bitmap ^imgNivel_CUATRO;
		Bitmap ^imgNivel_DOS;
		Bitmap ^imgNivel_TRES;
		Bitmap ^imgBomba;
		Bitmap ^imgBombasEnemigas;
		Bitmap ^imgBarraEstado;
		Bitmap ^imgEnemigoIzquierda;
		Bitmap ^imgEnemigoAbajo;
		Bitmap ^imgEnemigoEzquina;
		Bitmap ^imgEnemigoSuper;
		BufferedGraphics ^buffer;
		int distancia;
	public:
		frmPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~frmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  PB_BotonBack;
	protected: 
	private: System::Windows::Forms::PictureBox^  PBGameOver;
	private: System::Windows::Forms::PictureBox^  PBInstrucciones;
	private: System::Windows::Forms::Timer^  Reloj;
	private: System::Windows::Forms::Label^  lblSegundos;
	private: System::Windows::Forms::Label^  lblMinuto;
	private: System::Windows::Forms::PictureBox^  PBGanaste;
	private: System::Windows::Forms::PictureBox^  PBEnemigo_Super;
	private: System::Windows::Forms::PictureBox^  PBEnemigo_Ezquina;
	private: System::Windows::Forms::PictureBox^  PBEnemigo_Abajo;
	private: System::Windows::Forms::PictureBox^  PBEnemigo_Izquierdo;
	private: System::Windows::Forms::PictureBox^  IMGBarraEstado;
	private: System::Windows::Forms::PictureBox^  pct_Piedras_Nivel4;
	private: System::Windows::Forms::PictureBox^  pct_Piedras_Nivel3;
	private: System::Windows::Forms::PictureBox^  pct_Piedras_Nivel2;
	private: System::Windows::Forms::PictureBox^  pct_Piedras_Nivel1;
	private: System::Windows::Forms::PictureBox^  PbMapa4;
	private: System::Windows::Forms::PictureBox^  PbMapa3;
	private: System::Windows::Forms::PictureBox^  PbMapa2;
	private: System::Windows::Forms::PictureBox^  PbMapa1;
	private: System::Windows::Forms::PictureBox^  PbRetratoDorado;
	private: System::Windows::Forms::PictureBox^  PbRetratoNegro;
	private: System::Windows::Forms::PictureBox^  PbBombermanDorado;
	private: System::Windows::Forms::PictureBox^  PbBombermanNegro;
	private: System::Windows::Forms::PictureBox^  PbRetratoBlanco;
	private: System::Windows::Forms::PictureBox^  PbBotonSalir;
	private: System::Windows::Forms::PictureBox^  PbBotonInstruccion;
	private: System::Windows::Forms::PictureBox^  PbBotonIniciar;
	private: System::Windows::Forms::PictureBox^  PbMenu2;
	private: System::Windows::Forms::PictureBox^  PbMenu1;
	private: System::Windows::Forms::PictureBox^  PbBombermanBlanco;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmPrincipal::typeid));
			this->PB_BotonBack = (gcnew System::Windows::Forms::PictureBox());
			this->PBGameOver = (gcnew System::Windows::Forms::PictureBox());
			this->PBInstrucciones = (gcnew System::Windows::Forms::PictureBox());
			this->Reloj = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblSegundos = (gcnew System::Windows::Forms::Label());
			this->lblMinuto = (gcnew System::Windows::Forms::Label());
			this->PBGanaste = (gcnew System::Windows::Forms::PictureBox());
			this->PBEnemigo_Super = (gcnew System::Windows::Forms::PictureBox());
			this->PBEnemigo_Ezquina = (gcnew System::Windows::Forms::PictureBox());
			this->PBEnemigo_Abajo = (gcnew System::Windows::Forms::PictureBox());
			this->PBEnemigo_Izquierdo = (gcnew System::Windows::Forms::PictureBox());
			this->IMGBarraEstado = (gcnew System::Windows::Forms::PictureBox());
			this->pct_Piedras_Nivel4 = (gcnew System::Windows::Forms::PictureBox());
			this->pct_Piedras_Nivel3 = (gcnew System::Windows::Forms::PictureBox());
			this->pct_Piedras_Nivel2 = (gcnew System::Windows::Forms::PictureBox());
			this->pct_Piedras_Nivel1 = (gcnew System::Windows::Forms::PictureBox());
			this->PbMapa4 = (gcnew System::Windows::Forms::PictureBox());
			this->PbMapa3 = (gcnew System::Windows::Forms::PictureBox());
			this->PbMapa2 = (gcnew System::Windows::Forms::PictureBox());
			this->PbMapa1 = (gcnew System::Windows::Forms::PictureBox());
			this->PbRetratoDorado = (gcnew System::Windows::Forms::PictureBox());
			this->PbRetratoNegro = (gcnew System::Windows::Forms::PictureBox());
			this->PbBombermanDorado = (gcnew System::Windows::Forms::PictureBox());
			this->PbBombermanNegro = (gcnew System::Windows::Forms::PictureBox());
			this->PbRetratoBlanco = (gcnew System::Windows::Forms::PictureBox());
			this->PbBotonSalir = (gcnew System::Windows::Forms::PictureBox());
			this->PbBotonInstruccion = (gcnew System::Windows::Forms::PictureBox());
			this->PbBotonIniciar = (gcnew System::Windows::Forms::PictureBox());
			this->PbMenu2 = (gcnew System::Windows::Forms::PictureBox());
			this->PbMenu1 = (gcnew System::Windows::Forms::PictureBox());
			this->PbBombermanBlanco = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PB_BotonBack))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PBGameOver))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PBInstrucciones))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PBGanaste))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PBEnemigo_Super))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PBEnemigo_Ezquina))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PBEnemigo_Abajo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PBEnemigo_Izquierdo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->IMGBarraEstado))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pct_Piedras_Nivel4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pct_Piedras_Nivel3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pct_Piedras_Nivel2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pct_Piedras_Nivel1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbMapa4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbMapa3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbMapa2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbMapa1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbRetratoDorado))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbRetratoNegro))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbBombermanDorado))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbBombermanNegro))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbRetratoBlanco))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbBotonSalir))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbBotonInstruccion))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbBotonIniciar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbMenu2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbMenu1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbBombermanBlanco))->BeginInit();
			this->SuspendLayout();
			// 
			// PB_BotonBack
			// 
			this->PB_BotonBack->Cursor = System::Windows::Forms::Cursors::Hand;
			this->PB_BotonBack->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PB_BotonBack.Image")));
			this->PB_BotonBack->Location = System::Drawing::Point(-2, 509);
			this->PB_BotonBack->Name = L"PB_BotonBack";
			this->PB_BotonBack->Size = System::Drawing::Size(52, 26);
			this->PB_BotonBack->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PB_BotonBack->TabIndex = 77;
			this->PB_BotonBack->TabStop = false;
			this->PB_BotonBack->Visible = false;
			this->PB_BotonBack->Click += gcnew System::EventHandler(this, &frmPrincipal::PB_BotonBack_Click);
			// 
			// PBGameOver
			// 
			this->PBGameOver->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PBGameOver.Image")));
			this->PBGameOver->Location = System::Drawing::Point(70, 363);
			this->PBGameOver->Name = L"PBGameOver";
			this->PBGameOver->Size = System::Drawing::Size(50, 27);
			this->PBGameOver->TabIndex = 76;
			this->PBGameOver->TabStop = false;
			this->PBGameOver->Visible = false;
			// 
			// PBInstrucciones
			// 
			this->PBInstrucciones->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PBInstrucciones.Image")));
			this->PBInstrucciones->Location = System::Drawing::Point(70, 329);
			this->PBInstrucciones->Name = L"PBInstrucciones";
			this->PBInstrucciones->Size = System::Drawing::Size(50, 27);
			this->PBInstrucciones->TabIndex = 74;
			this->PBInstrucciones->TabStop = false;
			this->PBInstrucciones->Visible = false;
			// 
			// Reloj
			// 
			this->Reloj->Interval = 400;
			this->Reloj->Tick += gcnew System::EventHandler(this, &frmPrincipal::Reloj_Tick);
			// 
			// lblSegundos
			// 
			this->lblSegundos->AutoSize = true;
			this->lblSegundos->Location = System::Drawing::Point(226, 42);
			this->lblSegundos->Name = L"lblSegundos";
			this->lblSegundos->Size = System::Drawing::Size(19, 13);
			this->lblSegundos->TabIndex = 73;
			this->lblSegundos->Text = L"00";
			// 
			// lblMinuto
			// 
			this->lblMinuto->AutoSize = true;
			this->lblMinuto->Location = System::Drawing::Point(195, 42);
			this->lblMinuto->Name = L"lblMinuto";
			this->lblMinuto->Size = System::Drawing::Size(25, 13);
			this->lblMinuto->TabIndex = 72;
			this->lblMinuto->Text = L"00 :";
			// 
			// PBGanaste
			// 
			this->PBGanaste->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PBGanaste.Image")));
			this->PBGanaste->Location = System::Drawing::Point(13, 363);
			this->PBGanaste->Name = L"PBGanaste";
			this->PBGanaste->Size = System::Drawing::Size(50, 27);
			this->PBGanaste->TabIndex = 75;
			this->PBGanaste->TabStop = false;
			this->PBGanaste->Visible = false;
			// 
			// PBEnemigo_Super
			// 
			this->PBEnemigo_Super->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PBEnemigo_Super.Image")));
			this->PBEnemigo_Super->Location = System::Drawing::Point(50, 228);
			this->PBEnemigo_Super->Name = L"PBEnemigo_Super";
			this->PBEnemigo_Super->Size = System::Drawing::Size(30, 27);
			this->PBEnemigo_Super->TabIndex = 71;
			this->PBEnemigo_Super->TabStop = false;
			this->PBEnemigo_Super->Visible = false;
			// 
			// PBEnemigo_Ezquina
			// 
			this->PBEnemigo_Ezquina->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PBEnemigo_Ezquina.Image")));
			this->PBEnemigo_Ezquina->Location = System::Drawing::Point(50, 195);
			this->PBEnemigo_Ezquina->Name = L"PBEnemigo_Ezquina";
			this->PBEnemigo_Ezquina->Size = System::Drawing::Size(30, 25);
			this->PBEnemigo_Ezquina->TabIndex = 70;
			this->PBEnemigo_Ezquina->TabStop = false;
			this->PBEnemigo_Ezquina->Visible = false;
			// 
			// PBEnemigo_Abajo
			// 
			this->PBEnemigo_Abajo->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PBEnemigo_Abajo.Image")));
			this->PBEnemigo_Abajo->Location = System::Drawing::Point(50, 160);
			this->PBEnemigo_Abajo->Name = L"PBEnemigo_Abajo";
			this->PBEnemigo_Abajo->Size = System::Drawing::Size(30, 25);
			this->PBEnemigo_Abajo->TabIndex = 69;
			this->PBEnemigo_Abajo->TabStop = false;
			this->PBEnemigo_Abajo->Visible = false;
			// 
			// PBEnemigo_Izquierdo
			// 
			this->PBEnemigo_Izquierdo->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PBEnemigo_Izquierdo.Image")));
			this->PBEnemigo_Izquierdo->Location = System::Drawing::Point(50, 129);
			this->PBEnemigo_Izquierdo->Name = L"PBEnemigo_Izquierdo";
			this->PBEnemigo_Izquierdo->Size = System::Drawing::Size(30, 25);
			this->PBEnemigo_Izquierdo->TabIndex = 68;
			this->PBEnemigo_Izquierdo->TabStop = false;
			this->PBEnemigo_Izquierdo->Visible = false;
			// 
			// IMGBarraEstado
			// 
			this->IMGBarraEstado->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->IMGBarraEstado->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"IMGBarraEstado.Image")));
			this->IMGBarraEstado->Location = System::Drawing::Point(-2, 6);
			this->IMGBarraEstado->Name = L"IMGBarraEstado";
			this->IMGBarraEstado->Size = System::Drawing::Size(549, 81);
			this->IMGBarraEstado->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->IMGBarraEstado->TabIndex = 67;
			this->IMGBarraEstado->TabStop = false;
			this->IMGBarraEstado->Visible = false;
			// 
			// pct_Piedras_Nivel4
			// 
			this->pct_Piedras_Nivel4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pct_Piedras_Nivel4.Image")));
			this->pct_Piedras_Nivel4->Location = System::Drawing::Point(499, 329);
			this->pct_Piedras_Nivel4->Name = L"pct_Piedras_Nivel4";
			this->pct_Piedras_Nivel4->Size = System::Drawing::Size(34, 28);
			this->pct_Piedras_Nivel4->TabIndex = 66;
			this->pct_Piedras_Nivel4->TabStop = false;
			this->pct_Piedras_Nivel4->Visible = false;
			// 
			// pct_Piedras_Nivel3
			// 
			this->pct_Piedras_Nivel3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pct_Piedras_Nivel3.Image")));
			this->pct_Piedras_Nivel3->Location = System::Drawing::Point(499, 295);
			this->pct_Piedras_Nivel3->Name = L"pct_Piedras_Nivel3";
			this->pct_Piedras_Nivel3->Size = System::Drawing::Size(34, 28);
			this->pct_Piedras_Nivel3->TabIndex = 65;
			this->pct_Piedras_Nivel3->TabStop = false;
			this->pct_Piedras_Nivel3->Visible = false;
			// 
			// pct_Piedras_Nivel2
			// 
			this->pct_Piedras_Nivel2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pct_Piedras_Nivel2.Image")));
			this->pct_Piedras_Nivel2->Location = System::Drawing::Point(499, 261);
			this->pct_Piedras_Nivel2->Name = L"pct_Piedras_Nivel2";
			this->pct_Piedras_Nivel2->Size = System::Drawing::Size(34, 28);
			this->pct_Piedras_Nivel2->TabIndex = 64;
			this->pct_Piedras_Nivel2->TabStop = false;
			this->pct_Piedras_Nivel2->Visible = false;
			// 
			// pct_Piedras_Nivel1
			// 
			this->pct_Piedras_Nivel1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pct_Piedras_Nivel1.Image")));
			this->pct_Piedras_Nivel1->Location = System::Drawing::Point(499, 227);
			this->pct_Piedras_Nivel1->Name = L"pct_Piedras_Nivel1";
			this->pct_Piedras_Nivel1->Size = System::Drawing::Size(34, 28);
			this->pct_Piedras_Nivel1->TabIndex = 63;
			this->pct_Piedras_Nivel1->TabStop = false;
			this->pct_Piedras_Nivel1->Visible = false;
			// 
			// PbMapa4
			// 
			this->PbMapa4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->PbMapa4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PbMapa4.Image")));
			this->PbMapa4->Location = System::Drawing::Point(433, 420);
			this->PbMapa4->Name = L"PbMapa4";
			this->PbMapa4->Size = System::Drawing::Size(100, 100);
			this->PbMapa4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PbMapa4->TabIndex = 62;
			this->PbMapa4->TabStop = false;
			this->PbMapa4->Visible = false;
			this->PbMapa4->Click += gcnew System::EventHandler(this, &frmPrincipal::PbMapa4_Click);
			// 
			// PbMapa3
			// 
			this->PbMapa3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->PbMapa3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PbMapa3.Image")));
			this->PbMapa3->Location = System::Drawing::Point(295, 420);
			this->PbMapa3->Name = L"PbMapa3";
			this->PbMapa3->Size = System::Drawing::Size(100, 100);
			this->PbMapa3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PbMapa3->TabIndex = 61;
			this->PbMapa3->TabStop = false;
			this->PbMapa3->Visible = false;
			this->PbMapa3->Click += gcnew System::EventHandler(this, &frmPrincipal::PbMapa3_Click);
			// 
			// PbMapa2
			// 
			this->PbMapa2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->PbMapa2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PbMapa2.Image")));
			this->PbMapa2->Location = System::Drawing::Point(160, 420);
			this->PbMapa2->Name = L"PbMapa2";
			this->PbMapa2->Size = System::Drawing::Size(100, 100);
			this->PbMapa2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PbMapa2->TabIndex = 60;
			this->PbMapa2->TabStop = false;
			this->PbMapa2->Visible = false;
			this->PbMapa2->Click += gcnew System::EventHandler(this, &frmPrincipal::PbMapa2_Click);
			// 
			// PbMapa1
			// 
			this->PbMapa1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->PbMapa1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PbMapa1.Image")));
			this->PbMapa1->Location = System::Drawing::Point(20, 420);
			this->PbMapa1->Name = L"PbMapa1";
			this->PbMapa1->Size = System::Drawing::Size(100, 100);
			this->PbMapa1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PbMapa1->TabIndex = 59;
			this->PbMapa1->TabStop = false;
			this->PbMapa1->Visible = false;
			this->PbMapa1->Click += gcnew System::EventHandler(this, &frmPrincipal::PbMapa1_Click);
			// 
			// PbRetratoDorado
			// 
			this->PbRetratoDorado->Cursor = System::Windows::Forms::Cursors::Hand;
			this->PbRetratoDorado->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PbRetratoDorado.Image")));
			this->PbRetratoDorado->Location = System::Drawing::Point(357, 227);
			this->PbRetratoDorado->Name = L"PbRetratoDorado";
			this->PbRetratoDorado->Size = System::Drawing::Size(33, 34);
			this->PbRetratoDorado->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PbRetratoDorado->TabIndex = 58;
			this->PbRetratoDorado->TabStop = false;
			this->PbRetratoDorado->Visible = false;
			this->PbRetratoDorado->Click += gcnew System::EventHandler(this, &frmPrincipal::PbRetratoDorado_Click);
			// 
			// PbRetratoNegro
			// 
			this->PbRetratoNegro->Cursor = System::Windows::Forms::Cursors::Hand;
			this->PbRetratoNegro->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PbRetratoNegro.Image")));
			this->PbRetratoNegro->Location = System::Drawing::Point(263, 227);
			this->PbRetratoNegro->Name = L"PbRetratoNegro";
			this->PbRetratoNegro->Size = System::Drawing::Size(32, 33);
			this->PbRetratoNegro->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PbRetratoNegro->TabIndex = 57;
			this->PbRetratoNegro->TabStop = false;
			this->PbRetratoNegro->Visible = false;
			this->PbRetratoNegro->Click += gcnew System::EventHandler(this, &frmPrincipal::PbRetratoNegro_Click);
			// 
			// PbBombermanDorado
			// 
			this->PbBombermanDorado->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PbBombermanDorado.Image")));
			this->PbBombermanDorado->Location = System::Drawing::Point(13, 226);
			this->PbBombermanDorado->Name = L"PbBombermanDorado";
			this->PbBombermanDorado->Size = System::Drawing::Size(31, 50);
			this->PbBombermanDorado->TabIndex = 56;
			this->PbBombermanDorado->TabStop = false;
			this->PbBombermanDorado->Visible = false;
			// 
			// PbBombermanNegro
			// 
			this->PbBombermanNegro->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PbBombermanNegro.Image")));
			this->PbBombermanNegro->Location = System::Drawing::Point(13, 170);
			this->PbBombermanNegro->Name = L"PbBombermanNegro";
			this->PbBombermanNegro->Size = System::Drawing::Size(31, 50);
			this->PbBombermanNegro->TabIndex = 55;
			this->PbBombermanNegro->TabStop = false;
			this->PbBombermanNegro->Visible = false;
			// 
			// PbRetratoBlanco
			// 
			this->PbRetratoBlanco->Cursor = System::Windows::Forms::Cursors::Hand;
			this->PbRetratoBlanco->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PbRetratoBlanco.Image")));
			this->PbRetratoBlanco->Location = System::Drawing::Point(187, 227);
			this->PbRetratoBlanco->Name = L"PbRetratoBlanco";
			this->PbRetratoBlanco->Size = System::Drawing::Size(31, 33);
			this->PbRetratoBlanco->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PbRetratoBlanco->TabIndex = 54;
			this->PbRetratoBlanco->TabStop = false;
			this->PbRetratoBlanco->Visible = false;
			this->PbRetratoBlanco->Click += gcnew System::EventHandler(this, &frmPrincipal::PbRetratoBlanco_Click);
			// 
			// PbBotonSalir
			// 
			this->PbBotonSalir->Cursor = System::Windows::Forms::Cursors::Hand;
			this->PbBotonSalir->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PbBotonSalir.Image")));
			this->PbBotonSalir->Location = System::Drawing::Point(148, 277);
			this->PbBotonSalir->Name = L"PbBotonSalir";
			this->PbBotonSalir->Size = System::Drawing::Size(72, 35);
			this->PbBotonSalir->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PbBotonSalir->TabIndex = 53;
			this->PbBotonSalir->TabStop = false;
			this->PbBotonSalir->Visible = false;
			this->PbBotonSalir->Click += gcnew System::EventHandler(this, &frmPrincipal::PbBotonSalir_Click);
			// 
			// PbBotonInstruccion
			// 
			this->PbBotonInstruccion->Cursor = System::Windows::Forms::Cursors::Hand;
			this->PbBotonInstruccion->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PbBotonInstruccion.Image")));
			this->PbBotonInstruccion->Location = System::Drawing::Point(102, 194);
			this->PbBotonInstruccion->Name = L"PbBotonInstruccion";
			this->PbBotonInstruccion->Size = System::Drawing::Size(169, 36);
			this->PbBotonInstruccion->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PbBotonInstruccion->TabIndex = 52;
			this->PbBotonInstruccion->TabStop = false;
			this->PbBotonInstruccion->Visible = false;
			this->PbBotonInstruccion->Click += gcnew System::EventHandler(this, &frmPrincipal::PbBotonInstruccion_Click);
			// 
			// PbBotonIniciar
			// 
			this->PbBotonIniciar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->PbBotonIniciar->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PbBotonIniciar.Image")));
			this->PbBotonIniciar->Location = System::Drawing::Point(134, 113);
			this->PbBotonIniciar->Name = L"PbBotonIniciar";
			this->PbBotonIniciar->Size = System::Drawing::Size(90, 38);
			this->PbBotonIniciar->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PbBotonIniciar->TabIndex = 51;
			this->PbBotonIniciar->TabStop = false;
			this->PbBotonIniciar->Visible = false;
			this->PbBotonIniciar->Click += gcnew System::EventHandler(this, &frmPrincipal::PbBotonIniciar_Click);
			// 
			// PbMenu2
			// 
			this->PbMenu2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PbMenu2.Image")));
			this->PbMenu2->Location = System::Drawing::Point(499, 362);
			this->PbMenu2->Name = L"PbMenu2";
			this->PbMenu2->Size = System::Drawing::Size(34, 28);
			this->PbMenu2->TabIndex = 50;
			this->PbMenu2->TabStop = false;
			this->PbMenu2->Visible = false;
			// 
			// PbMenu1
			// 
			this->PbMenu1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PbMenu1.Image")));
			this->PbMenu1->Location = System::Drawing::Point(13, 329);
			this->PbMenu1->Name = L"PbMenu1";
			this->PbMenu1->Size = System::Drawing::Size(50, 27);
			this->PbMenu1->TabIndex = 49;
			this->PbMenu1->TabStop = false;
			this->PbMenu1->Visible = false;
			// 
			// PbBombermanBlanco
			// 
			this->PbBombermanBlanco->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PbBombermanBlanco.Image")));
			this->PbBombermanBlanco->Location = System::Drawing::Point(13, 114);
			this->PbBombermanBlanco->Name = L"PbBombermanBlanco";
			this->PbBombermanBlanco->Size = System::Drawing::Size(31, 50);
			this->PbBombermanBlanco->TabIndex = 48;
			this->PbBombermanBlanco->TabStop = false;
			this->PbBombermanBlanco->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &frmPrincipal::timer1_Tick);
			// 
			// frmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(544, 541);
			this->Controls->Add(this->PB_BotonBack);
			this->Controls->Add(this->PBGameOver);
			this->Controls->Add(this->PBInstrucciones);
			this->Controls->Add(this->lblSegundos);
			this->Controls->Add(this->lblMinuto);
			this->Controls->Add(this->PBGanaste);
			this->Controls->Add(this->PBEnemigo_Super);
			this->Controls->Add(this->PBEnemigo_Ezquina);
			this->Controls->Add(this->PBEnemigo_Abajo);
			this->Controls->Add(this->PBEnemigo_Izquierdo);
			this->Controls->Add(this->IMGBarraEstado);
			this->Controls->Add(this->pct_Piedras_Nivel4);
			this->Controls->Add(this->pct_Piedras_Nivel3);
			this->Controls->Add(this->pct_Piedras_Nivel2);
			this->Controls->Add(this->pct_Piedras_Nivel1);
			this->Controls->Add(this->PbMapa4);
			this->Controls->Add(this->PbMapa3);
			this->Controls->Add(this->PbMapa2);
			this->Controls->Add(this->PbMapa1);
			this->Controls->Add(this->PbRetratoDorado);
			this->Controls->Add(this->PbRetratoNegro);
			this->Controls->Add(this->PbBombermanDorado);
			this->Controls->Add(this->PbBombermanNegro);
			this->Controls->Add(this->PbRetratoBlanco);
			this->Controls->Add(this->PbBotonSalir);
			this->Controls->Add(this->PbBotonInstruccion);
			this->Controls->Add(this->PbBotonIniciar);
			this->Controls->Add(this->PbMenu2);
			this->Controls->Add(this->PbMenu1);
			this->Controls->Add(this->PbBombermanBlanco);
			this->Name = L"frmPrincipal";
			this->Text = L"frmPrincipal";
			this->Load += gcnew System::EventHandler(this, &frmPrincipal::frmPrincipal_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmPrincipal::frmPrincipal_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PB_BotonBack))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PBGameOver))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PBInstrucciones))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PBGanaste))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PBEnemigo_Super))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PBEnemigo_Ezquina))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PBEnemigo_Abajo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PBEnemigo_Izquierdo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->IMGBarraEstado))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pct_Piedras_Nivel4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pct_Piedras_Nivel3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pct_Piedras_Nivel2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pct_Piedras_Nivel1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbMapa4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbMapa3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbMapa2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbMapa1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbRetratoDorado))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbRetratoNegro))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbBombermanDorado))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbBombermanNegro))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbRetratoBlanco))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbBotonSalir))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbBotonInstruccion))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbBotonIniciar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbMenu2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbMenu1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PbBombermanBlanco))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void PbBotonIniciar_Click(System::Object^  sender, System::EventArgs^  e) {
				 Opcion = 1;
	objMenu = new CMenu(0, 0, 354, 325, 1);
	OcultarMenus(SeleccionMapa, Opcion);

			 }
private: System::Void frmPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
	Opcion = 0;
	NBombas = 5;
	N_Enemigo=0;
	Minutos = 0;
	Segundos = 0;
	distancia = objPAdreEnemigo->Distancia(42, 126, 252, 126);
	SonidoMenu = gcnew SoundPlayer("Menu.wav");
	SonidoJuego = gcnew SoundPlayer("Juego.wav");
	g = this->CreateGraphics();
	anchoF = (int)g->VisibleClipBounds.Width;
	largoF = (int)g->VisibleClipBounds.Height;
	SonidoMenu->PlayLooping();
	//ESTO ES PARA MOVER AL PERSONAJE
	X_Pirata = 42;
	Y_Pirata = 126;
	//MENU
	imgMenu1 = gcnew Bitmap(PbMenu1->Image);
	imgMenu2 = gcnew Bitmap(PbMenu2->Image);
	imgInstrucciones=gcnew Bitmap(PBInstrucciones->Image);
	imgGanaste=gcnew Bitmap(PBGanaste->Image);
	imgGameOver=gcnew Bitmap(PBGameOver->Image);
	//PERSONAJE
	imgUpecinoBlanco = gcnew Bitmap(PbBombermanBlanco->Image);
	imgUpecinoBlanco->MakeTransparent(imgUpecinoBlanco->GetPixel(0, 0));

	imgUpecinoNegro = gcnew Bitmap(PbBombermanNegro->Image);
	imgUpecinoNegro->MakeTransparent(imgUpecinoNegro->GetPixel(1, 1));

	imgUpecinoDorado = gcnew Bitmap(PbBombermanDorado->Image);
	imgUpecinoDorado->MakeTransparent(imgUpecinoDorado->GetPixel(1, 1));

	imgNivel_UNO= gcnew Bitmap(pct_Piedras_Nivel1->Image);
	imgNivel_DOS= gcnew Bitmap(pct_Piedras_Nivel2->Image);
	imgNivel_TRES= gcnew Bitmap(pct_Piedras_Nivel3->Image);
	imgNivel_CUATRO= gcnew Bitmap(pct_Piedras_Nivel4->Image);


	//BARRA DE ESTADO
	//imgBarraEstado = gcnew Bitmap(pictureBox_Bomba->Image);
	//ENEMIGOS
	imgEnemigoIzquierda= gcnew Bitmap(PBEnemigo_Izquierdo->Image);
	imgEnemigoIzquierda->MakeTransparent(imgEnemigoIzquierda->GetPixel(1, 1));

	imgEnemigoAbajo= gcnew Bitmap(PBEnemigo_Abajo->Image);
	imgEnemigoAbajo->MakeTransparent(imgEnemigoAbajo->GetPixel(1, 1));

	imgEnemigoEzquina= gcnew Bitmap(PBEnemigo_Ezquina->Image);
	imgEnemigoEzquina->MakeTransparent(imgEnemigoEzquina->GetPixel(1, 1));

	imgEnemigoSuper= gcnew Bitmap(PBEnemigo_Super->Image);
	imgEnemigoSuper->MakeTransparent(imgEnemigoSuper->GetPixel(1, 1));

	//BUFFER
	BufferedGraphicsContext ^context = BufferedGraphicsManager::Current;
	buffer = context->Allocate(g, this->ClientRectangle);
	delete context;
	//SELECCION MAPA Y PERSONAJE
	nivel = 1;

	objUpecino = new CUpecino(468, 468, 42, 42, 1, nivel);
	// Posicion del jugador
	X_J = 1;
	Y_J = 3;
	objMenu = new CMenu(0, 0, 354, 325, 0);
	
	ObjControlador=new CControlador(0,0,0);
		 }
private: System::Void PbBotonInstruccion_Click(System::Object^  sender, System::EventArgs^  e) {
			 Opcion = 9;
	objMenu = new CMenu(0, 0, 354, 325, 9);
	OcultarMenus(SeleccionMapa, Opcion);
	 PB_BotonBack->Visible=true;
		 }
private: System::Void PbBotonSalir_Click(System::Object^  sender, System::EventArgs^  e) {
	Close();

		 }
private: System::Void PbRetratoBlanco_Click(System::Object^  sender, System::EventArgs^  e) {
	objUpecino = new CUpecino(468, 468, 42, 42, 1, nivel);

		 }
private: System::Void PbRetratoNegro_Click(System::Object^  sender, System::EventArgs^  e) {
			 objUpecino = new CUpecino(468, 468, 42, 42, 2, nivel);
		 }
private: System::Void PbRetratoDorado_Click(System::Object^  sender, System::EventArgs^  e) {
			 objUpecino = new CUpecino(468, 468, 42, 42, 3, nivel);
		 }
private: System::Void PbMapa1_Click(System::Object^  sender, System::EventArgs^  e) {
			 SeleccionMapa = 1;
	Opcion = 2;
	//objPAdreEnemigo = new CPadreEnemigo(468, 468, 42, 42, 5, 5, 1);
	objPAdreEnemigo = new CPadreEnemigo(42, 126, 42, 42, 5, 5, 1);
	OcultarMenus(SeleccionMapa, Opcion);
	PB_BotonBack->Visible=false;
	
	Reloj->Enabled=false;
	nivel = 1;
		 }
private: System::Void PbMapa2_Click(System::Object^  sender, System::EventArgs^  e) {
			 SeleccionMapa = 2;
	Opcion = 2;
	objPAdreEnemigo = new CPadreEnemigo(42, 126, 42, 42, 5, 5, 2);
	OcultarMenus(SeleccionMapa, Opcion);
	PB_BotonBack->Visible=false;
	Reloj->Enabled=true;
	nivel = 2;
		 }
private: System::Void PbMapa3_Click(System::Object^  sender, System::EventArgs^  e) {
			 SeleccionMapa = 3;
	Opcion = 2;
	objPAdreEnemigo = new CPadreEnemigo(42, 126, 42, 42, 5, 5, 3);
	OcultarMenus(SeleccionMapa, Opcion);
	PB_BotonBack->Visible=false;

	Reloj->Enabled=true;
	nivel = 3;
		 }
private: System::Void PbMapa4_Click(System::Object^  sender, System::EventArgs^  e) {
			 SeleccionMapa = 4;
	Opcion = 2;
	objPAdreEnemigo = new CPadreEnemigo(42, 126, 42, 42, 5, 5, 4);
	OcultarMenus(SeleccionMapa, Opcion);
	PB_BotonBack->Visible=false;

	Reloj->Enabled=true;
	nivel = 4;
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if (Opcion == 0){
		buffer->Graphics->Clear(BackColor);
		objMenu->Dibujar(buffer->Graphics, imgMenu1, imgMenu2,imgInstrucciones,imgGanaste,imgGameOver); //, imgBarraEstado);
		OcultarMenus(SeleccionMapa, Opcion);
	    PB_BotonBack->Visible=false;

		buffer->Render(g);
	}
	if (Opcion == 1){
		buffer->Graphics->Clear(BackColor);
		objMenu->Dibujar(buffer->Graphics, imgMenu1, imgMenu2,imgInstrucciones,imgGanaste,imgGameOver); // , imgBarraEstado);
		OcultarMenus(SeleccionMapa, Opcion);
	    PB_BotonBack->Visible=false;

		buffer->Render(g);
	}
	if (Opcion == 9){

		buffer->Graphics->Clear(BackColor);
		objMenu->Dibujar(buffer->Graphics, imgMenu1, imgMenu2,imgInstrucciones,imgGanaste,imgGameOver); // , imgBarraEstado);
		OcultarMenus(SeleccionMapa, Opcion);
	    PB_BotonBack->Visible=true;

		buffer->Render(g);
	}
	if (Opcion == 3){
		buffer->Graphics->Clear(BackColor);
		objMenu->Dibujar(buffer->Graphics, imgMenu1, imgMenu2,imgInstrucciones,imgGanaste,imgGameOver); //, imgBarraEstado);
		OcultarMenus(SeleccionMapa, Opcion);
		buffer->Render(g);
	}
	if (Opcion == 5){
		
		buffer->Graphics->Clear(BackColor);
		objMenu->Dibujar(buffer->Graphics, imgMenu1, imgMenu2,imgInstrucciones,imgGanaste,imgGameOver); //, imgBarraEstado);
		OcultarMenus(SeleccionMapa, Opcion);
	    PB_BotonBack->Visible=false;

		buffer->Render(g);
	}
	if (SeleccionMapa == 1){
		buffer->Graphics->Clear(BackColor);
		//MAPA
		objTablero = new CTablero(0, 0, 42, 42, 1);
		objTablero->Set_Nivel(1, 0, 0);
		objTablero->Dibujar(buffer->Graphics,imgNivel_UNO);
		//PERSONAJE
		objUpecino->Dibujar(buffer->Graphics, imgUpecinoBlanco, imgUpecinoNegro, imgUpecinoDorado);
		//ENEMIGO
		
		
		
			objPAdreEnemigo->dibujar(buffer->Graphics, imgEnemigoIzquierda, imgEnemigoAbajo, imgEnemigoEzquina, imgEnemigoSuper);
			//objPAdreEnemigo->Mover(objTablero);
		
		//objPAdreEnemigo->Mover(objTablero);
		Reloj->Enabled=true;
		//AQUI PARA MOSTRAR GAME OVER
		if(objUpecino->bomberman_Gana(SeleccionMapa)==true)
		{
			Opcion=3;
			IMGBarraEstado->Visible=false;
			timer1->Enabled=false;
		    Reloj->Enabled=false;
			PBGanaste->Location = System::Drawing::Point(0, 0);
		    PBGanaste->Size = System::Drawing::Size(560, 580);
			PBGanaste->Visible=true;
			lblMinuto->Location = System::Drawing::Point(200,270);
			lblSegundos->Location = System::Drawing::Point(220,270);
			lblMinuto->Visible=true;
			lblSegundos->Visible=true;
			

		}
		if(objUpecino->Estado_Bomberman()==true)
		{	timer1->Enabled=false;
		    Reloj->Enabled=false;
		    PBGameOver->Location = System::Drawing::Point(0, 0);
		    PBGameOver->Size = System::Drawing::Size(560, 580);
			PBGameOver->Visible=true;
			
		} 
		if(objPAdreEnemigo->enemigo_Gana(SeleccionMapa)==true)
		{
			Opcion=9;

			timer1->Enabled=false;
		    Reloj->Enabled=false;
			PBGameOver->Location = System::Drawing::Point(0, 0);
		    PBGameOver->Size = System::Drawing::Size(560, 580);
			PBGameOver->Visible=true;
			lblMinuto->Location = System::Drawing::Point(200,270);
			lblSegundos->Location = System::Drawing::Point(220,270);
			lblMinuto->Visible=true;
			lblSegundos->Visible=true;
			

		}
		
		buffer->Render(g);
	}
	if (SeleccionMapa == 2){
		buffer->Graphics->Clear(BackColor);
		//MAPA
		objTablero = new CTablero(0, 0, 42, 42, 2);
		objTablero->Set_Nivel(2, 0, 0);
		objTablero->Dibujar(buffer->Graphics,imgNivel_DOS);
		//PERSONAJE
		objUpecino->Dibujar(buffer->Graphics, imgUpecinoBlanco, imgUpecinoNegro, imgUpecinoDorado);
		//ENEMIGO
		objPAdreEnemigo->dibujar(buffer->Graphics, imgEnemigoIzquierda, imgEnemigoAbajo, imgEnemigoEzquina, imgEnemigoSuper);
		objPAdreEnemigo->Mover(objTablero);
		Reloj->Enabled=true;
		if(objUpecino->bomberman_Gana(SeleccionMapa)==true)
		{
			Opcion=3;
			IMGBarraEstado->Visible=false;
			timer1->Enabled=false;
		    Reloj->Enabled=false;
			PBGanaste->Location = System::Drawing::Point(0, 0);
		    PBGanaste->Size = System::Drawing::Size(560, 580);
			PBGanaste->Visible=true;
			lblMinuto->Location = System::Drawing::Point(200,270);
			lblSegundos->Location = System::Drawing::Point(220,270);
			lblMinuto->Visible=true;
			lblSegundos->Visible=true;
			

		}
		if(objUpecino->Estado_Bomberman()==true)
		{	timer1->Enabled=false;
		    Reloj->Enabled=false;
		    PBGameOver->Location = System::Drawing::Point(0, 0);
		    PBGameOver->Size = System::Drawing::Size(560, 580);
			PBGameOver->Visible=true;
			 
		} 
		if(objPAdreEnemigo->enemigo_Gana(SeleccionMapa)==true)
		{
			Opcion=5;

			timer1->Enabled=false;
		    Reloj->Enabled=false;
			PBGameOver->Location = System::Drawing::Point(0, 0);
		    PBGameOver->Size = System::Drawing::Size(560, 580);
			PBGameOver->Visible=true;
			lblMinuto->Location = System::Drawing::Point(200,270);
			lblSegundos->Location = System::Drawing::Point(220,270);
			lblMinuto->Visible=true;
			lblSegundos->Visible=true;
			
		}
		
		buffer->Render(g);
	}
	if (SeleccionMapa == 3){
		buffer->Graphics->Clear(BackColor);
		//MAPA
		objTablero = new CTablero(0, 0, 42, 42, 3);
		objTablero->Set_Nivel(3, 0, 0);
		objTablero->Dibujar(buffer->Graphics,imgNivel_TRES);
		//PERSONAJE
		objUpecino->Dibujar(buffer->Graphics, imgUpecinoBlanco, imgUpecinoNegro, imgUpecinoDorado);
		//ENEMIGO
		objPAdreEnemigo->dibujar(buffer->Graphics, imgEnemigoIzquierda, imgEnemigoAbajo, imgEnemigoEzquina, imgEnemigoSuper);
		objPAdreEnemigo->Mover(objTablero);
		//BOMBAS
		Reloj->Enabled=true;
		if(objUpecino->bomberman_Gana(SeleccionMapa)==true)
		{
			Opcion=3;
			IMGBarraEstado->Visible=false;
			timer1->Enabled=false;
		    Reloj->Enabled=false;
			PBGameOver->Location = System::Drawing::Point(0, 0);
		    PBGameOver->Size = System::Drawing::Size(560, 580);
			PBGameOver->Visible=true;
			lblMinuto->Location = System::Drawing::Point(200,270);
			lblSegundos->Location = System::Drawing::Point(220,270);
			lblMinuto->Visible=true;
			lblSegundos->Visible=true;
			

		}
		if(objUpecino->Estado_Bomberman()==true)
		{	timer1->Enabled=false;
		    Reloj->Enabled=false;
		    PBGameOver->Location = System::Drawing::Point(0, 0);
		    PBGameOver->Size = System::Drawing::Size(560, 580);
			PBGameOver->Visible=true;
			

		} 
		if(objPAdreEnemigo->enemigo_Gana(SeleccionMapa)==true)
		{
			Opcion=5;

			timer1->Enabled=false;
		    Reloj->Enabled=false;
			PBGameOver->Location = System::Drawing::Point(0, 0);
		    PBGameOver->Size = System::Drawing::Size(560, 580);
			PBGameOver->Visible=true;
			lblMinuto->Location = System::Drawing::Point(200,270);
			lblSegundos->Location = System::Drawing::Point(220,270);
			lblMinuto->Visible=true;
			lblSegundos->Visible=true;
			
		}
		//MostrarBombas(NBombas);
		buffer->Render(g);
	}
	if (SeleccionMapa == 4){
		buffer->Graphics->Clear(BackColor);
		//MAPA
		objTablero = new CTablero(0, 0, 42, 42, 4);
		objTablero->Set_Nivel(4, 0, 0);
		objTablero->Dibujar(buffer->Graphics,imgNivel_CUATRO);
		//PERSONAJE
		objUpecino->Dibujar(buffer->Graphics, imgUpecinoBlanco, imgUpecinoNegro, imgUpecinoDorado);
		//ENEMIGO
		objPAdreEnemigo->dibujar(buffer->Graphics, imgEnemigoIzquierda, imgEnemigoAbajo, imgEnemigoEzquina, imgEnemigoSuper);
		objPAdreEnemigo->Mover(objTablero);
		Reloj->Enabled=true;
		if(objUpecino->bomberman_Gana(SeleccionMapa)==true)
		{
			Opcion=3;
			IMGBarraEstado->Visible=false;
			timer1->Enabled=false;
		    Reloj->Enabled=false;
			PBGanaste->Location = System::Drawing::Point(0, 0);
		    PBGanaste->Size = System::Drawing::Size(560, 580);
			PBGanaste->Visible=true;
			lblMinuto->Location = System::Drawing::Point(200,270);
			lblSegundos->Location = System::Drawing::Point(220,270);
			lblMinuto->Visible=true;
			lblSegundos->Visible=true;
			

		}
		if(objUpecino->Estado_Bomberman()==true)
		{	timer1->Enabled=false;
		    Reloj->Enabled=false;
		    PBGameOver->Location = System::Drawing::Point(0, 0);
		    PBGameOver->Size = System::Drawing::Size(560, 580);
			PBGameOver->Visible=true;
			

		}
		if(objPAdreEnemigo->enemigo_Gana(SeleccionMapa)==true)
		{
			Opcion=5;
			timer1->Enabled=false;
		    Reloj->Enabled=false;
			PBGameOver->Location = System::Drawing::Point(0, 0);
		    PBGameOver->Size = System::Drawing::Size(560, 580);
			PBGameOver->Visible=true;
			lblMinuto->Location = System::Drawing::Point(200,270);
			lblSegundos->Location = System::Drawing::Point(220,270);
			lblMinuto->Visible=true;
			lblSegundos->Visible=true;
			 
		}
		
		buffer->Render(g);
	}
		 }
private: System::Void frmPrincipal_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 objUpecino->Set_Direccion(e->KeyData,SeleccionMapa);
	//objPAdreEnemigo->Set_Direccion(e->KeyData);
	if (e->KeyData == Keys::Space){
		NBombas--;
	}
	if (e->KeyData == Keys::Q){
		NBombas++;
	}
	
	if (e->KeyData == Keys::Z){
		timer1->Stop();
		Reloj->Stop();
	}
	if (e->KeyData == Keys::X){
		timer1->Start();
		Reloj->Start();
	}
	if (e->KeyData == Keys::Escape){
		Close();
	}
		 }
private: System::Void Reloj_Tick(System::Object^  sender, System::EventArgs^  e) {
			 	Segundos++;
	if (Segundos > 59){
		Segundos = 0;
		Minutos++;
		lblMinuto->Text = Minutos.ToString() + " :";
	}
	else{
		lblSegundos->Text = Segundos.ToString();
	}
	/*if (distancia > 0)
	{
		char dir = objPAdreEnemigo->Dire(X_Pirata, Y_Pirata, 252, 126,1);
		objPAdreEnemigo->Set_direccion_Char(dir);

		if (dir == 'W') { Y_Pirata = Y_Pirata - 42; }
		else if (dir == 'S') { Y_Pirata = Y_Pirata + 42; }
		else if (dir == 'A') { X_Pirata = X_Pirata - 42; }
		else if (dir == 'D') { X_Pirata = X_Pirata + 42; }
 		distancia = objPAdreEnemigo->Distancia(X_Pirata, Y_Pirata, 252, 126);


	}*/
	if(objPAdreEnemigo->enemigo_Gana(SeleccionMapa)==false)
	{
		//objPAdreEnemigo->BFS(SeleccionMapa);
		//objPAdreEnemigo->greedy(SeleccionMapa);
		objPAdreEnemigo->PosiMov(SeleccionMapa);

	}
		 }
		  void OcultarMenus(int SeleccionMapa,int Opcion)
		 {
			 if (Opcion == 0){
				 ObjControlador->PCT_VISIBLE_false( Opcion,SeleccionMapa,PbBotonIniciar,PbBotonInstruccion,
				 PbBotonSalir, IMGBarraEstado,PbRetratoBlanco,PbRetratoNegro,
		         PbRetratoDorado,PbMapa1,PbMapa2,PbMapa3,
		         PbMapa4, lblMinuto,lblSegundos);
		
			 }
			 else if (Opcion == 1){
				  ObjControlador->PCT_VISIBLE_false( Opcion,SeleccionMapa,PbBotonIniciar,PbBotonInstruccion,
				 PbBotonSalir, IMGBarraEstado,PbRetratoBlanco,PbRetratoNegro,
		         PbRetratoDorado,PbMapa1,PbMapa2,PbMapa3,
		         PbMapa4, lblMinuto,lblSegundos);
		
			 }
			 else if (Opcion == 9){
				  ObjControlador->PCT_VISIBLE_false( Opcion,SeleccionMapa,PbBotonIniciar,PbBotonInstruccion,
				 PbBotonSalir, IMGBarraEstado,PbRetratoBlanco,PbRetratoNegro,
		         PbRetratoDorado,PbMapa1,PbMapa2,PbMapa3,
		         PbMapa4, lblMinuto,lblSegundos);
		
			 }
			 else if (Opcion == 3){
				  ObjControlador->PCT_VISIBLE_false( Opcion,SeleccionMapa,PbBotonIniciar,PbBotonInstruccion,
				 PbBotonSalir, IMGBarraEstado,PbRetratoBlanco,PbRetratoNegro,
		         PbRetratoDorado,PbMapa1,PbMapa2,PbMapa3,
		         PbMapa4, lblMinuto,lblSegundos);
		
			 }
			 else if (Opcion == 5){
				 
				  ObjControlador->PCT_VISIBLE_false( Opcion,SeleccionMapa,PbBotonIniciar,PbBotonInstruccion,
				 PbBotonSalir, IMGBarraEstado,PbRetratoBlanco,PbRetratoNegro,
		         PbRetratoDorado,PbMapa1,PbMapa2,PbMapa3,
		         PbMapa4, lblMinuto,lblSegundos);
		
			 }
			 else if (SeleccionMapa == 1 || SeleccionMapa == 2 || SeleccionMapa == 3 || SeleccionMapa == 4){
				  ObjControlador->PCT_VISIBLE_false( Opcion,SeleccionMapa,PbBotonIniciar,PbBotonInstruccion,
				 PbBotonSalir, IMGBarraEstado,PbRetratoBlanco,PbRetratoNegro,
		         PbRetratoDorado,PbMapa1,PbMapa2,PbMapa3,
		         PbMapa4, lblMinuto,lblSegundos);
				  
				  SonidoMenu->Stop();
				 SonidoJuego->PlayLooping();
			 }
		 }

private: System::Void PB_BotonBack_Click(System::Object^  sender, System::EventArgs^  e) {
			 Opcion=0;
			 SeleccionMapa=0;
			 SeleccionPJ=0;
	         objMenu = new CMenu(0, 0, 354, 325,0);
		 }
};
}
