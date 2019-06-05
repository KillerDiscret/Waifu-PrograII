//librería MyForm.H
#pragma once
#include "Jugador.h"

namespace Waifu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		CJugador*objJugador;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
			 Bitmap^bmpJugador;
	public:
		MyForm(void)
		{
			InitializeComponent();
			objJugador = new CJugador(50, 50);
			bmpJugador = gcnew Bitmap("waifu.png");
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 50;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(530, 426);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		switch (e->KeyCode)
		{

		default:
			objJugador->setdireccion(Ninguna);
			break;
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		switch (e->KeyCode)
		{
		case Keys::Up://arriba
			objJugador->setdireccion(Arriba);
			break;

		case Keys::Left://Izquierda
			objJugador->setdireccion(Izquierda);
			break;
		case Keys::Right://derecha
			objJugador->setdireccion(Derecha);
			break;

		case Keys::Down://abajo
			objJugador->setdireccion(Abajo);
			break;
		case Keys::A://Letra A
			objJugador->setdireccion(LetraA);
			break;
		case Keys::S://Letra S
			objJugador->setdireccion(LetraS);
			break;
		default:
			break;
		}
	}

	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espacio->Allocate(g, this->ClientRectangle);
		objJugador->moverJugador(buffer->Graphics, bmpJugador);
		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	}
	};
}
