#pragma once
#include <iostream>
namespace ProjectParking {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ InputAdminPassword
	/// </summary>
	public ref class InputAdminPassword : public System::Windows::Forms::Form
	{
	public:
		bool AdminPassword = false;
		InputAdminPassword(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~InputAdminPassword()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(139, 177);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(194, 58);
			this->button1->TabIndex = 0;
			this->button1->Text = L"¬вести пароль";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &InputAdminPassword::button1_MouseClick);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(139, 115);
			this->textBox1->Name = L"textBox1";
			this->textBox1->PasswordChar = '*';
			this->textBox1->Size = System::Drawing::Size(194, 34);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &InputAdminPassword::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Gainsboro;
			this->label2->Location = System::Drawing::Point(12, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(443, 252);
			this->label2->TabIndex = 16;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::LightGray;
			this->label1->Location = System::Drawing::Point(118, 89);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(233, 160);
			this->label1->TabIndex = 17;
			// 
			// InputAdminPassword
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(467, 270);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"InputAdminPassword";
			this->ShowIcon = false;
			this->Text = L"InputAdminPassword";
			this->Load += gcnew System::EventHandler(this, &InputAdminPassword::InputAdminPassword_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void InputAdminPassword_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (this->textBox1->Text == "el awho") {
			this->AdminPassword = true;
			this->Close();
		}
	}
	};
}
