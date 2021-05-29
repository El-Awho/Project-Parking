#pragma once
#include "InputAdminPassword.h"
#include <iostream>

namespace ProjectParking {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Silver;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label1->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Location = System::Drawing::Point(152, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(375, 34);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Програма автоматизації роботи контролера паркінгу.";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(397, 154);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(189, 90);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Я контролер роботи паркінгу.";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::button1_MouseClick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(84, 154);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(191, 90);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Я системний адміністратор.";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::button2_MouseClick);
			// 
			// label7
			// 
			this->label7->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label7->Location = System::Drawing::Point(12, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(658, 285);
			this->label7->TabIndex = 14;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Gainsboro;
			this->label2->Location = System::Drawing::Point(29, 119);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(620, 160);
			this->label2->TabIndex = 15;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Gainsboro;
			this->label3->Location = System::Drawing::Point(143, 22);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(393, 144);
			this->label3->TabIndex = 16;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkGray;
			this->ClientSize = System::Drawing::Size(682, 303);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label7);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->Text = L"Project Parking";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	private: System::Void button1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		
		std::ifstream outf("ParkingPlaces.txt");
		if (outf) {
			outf.close();
			pressed = 1;
			this->Close();
		}
		outf.close();
	}
private: System::Void button2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	ProjectParking::InputAdminPassword formach;
	formach.ShowDialog();
	if (formach.AdminPassword) {
		pressed = 2;
		this->Close();
	}
}
};
}
