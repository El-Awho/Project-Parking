#include <iostream>
#include <string>
#include <fstream>
#include <vector>


namespace ProjectParking {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	class ConfigTXTER {
	public:
		unsigned int CountOfParkPlaces;
		unsigned int Floors;
		unsigned int PriceForHour;
		unsigned int PriceForDay;
		ConfigTXTER(unsigned int CountOfParkPlaces, unsigned int Floors, unsigned int PriceForHour, unsigned int PriceForDay) :
			CountOfParkPlaces(CountOfParkPlaces), Floors(Floors), PriceForHour(PriceForHour), PriceForDay(PriceForDay)
		{
		}
	};
	class ParkingPlacess {
	public:
		std::string NumberPhone;
		std::string NumberOfAuto;
		int MinutesOfStoyannya;
		ParkingPlacess() : NumberPhone("Empty"), MinutesOfStoyannya(0), NumberOfAuto("Empty") {
		}
		ParkingPlacess(std::string NumberPhone, std::string NumberOfAuto, int MinutesOfStoyannya) : NumberPhone(NumberPhone),
			NumberOfAuto(NumberOfAuto), MinutesOfStoyannya(MinutesOfStoyannya)
		{
		}
	};
	

	


	/// <summary>
	/// Сводка для Administrator
	/// </summary>
	public ref class Administrator : public System::Windows::Forms::Form
	{
	public:
		Administrator(void)
		{
			InitializeComponent();

			//TODO: добавьте код конструктора
			//
		}
		
		ConfigTXTER FormConfigTXT(unsigned int CountOfParkPlaces, unsigned int Floors, unsigned int PriceForHour, unsigned int PriceForDay) {
			std::ofstream outf("Config.txt");
			ConfigTXTER buffer(CountOfParkPlaces, Floors, PriceForHour, PriceForDay);
			outf << "CountOfParkPlaces = " << CountOfParkPlaces << '\n';
			outf << "Floors = " << Floors << '\n';
			outf << "PriceForHour = " << PriceForHour << '\n';
			outf << "PriceForDay = " << PriceForDay << '\n';
			return buffer;
		}
		
		ConfigTXTER ReadConfigTXT() {
			std::ifstream inf("Config.txt");
			unsigned int Number[4], i = 0;
			std::string str;
			while (getline(inf, str)) {
				while (str[0] < '0' || str[0] > '9') {
					str.erase(0, 1);
				}
				Number[i] = atoi(str.c_str());
				i++;
			}
			ConfigTXTER Buffer(Number[0], Number[1], Number[2], Number[3]);
			return Buffer;
		};


		

		std::vector <ParkingPlacess> FormParkingPlaces(int CountOfParkPlaces) {
			std::ofstream outf("ParkingPlaces.txt");
			std::vector <ParkingPlacess> output;
			ParkingPlacess buffer;
			for (int i = 0; i < CountOfParkPlaces; i++) {
				outf << i + 1 << ".) " << buffer.NumberPhone << " " << buffer.NumberOfAuto << " " << buffer.MinutesOfStoyannya << "\n";
				output.push_back(buffer);
			}
			return output;
		};

		std::vector <ParkingPlacess> ReadParkingPlaces() {
			std::ifstream inf("ParkingPlaces.txt");
			std::vector <ParkingPlacess> output;
			ParkingPlacess buffer;
			std::string StringBuffer;
			std::string BufferInput;

			while (getline(inf, StringBuffer)) {
				do {
					StringBuffer.erase(0, 1);

				} while (StringBuffer[0] != ' ');

				while (StringBuffer[0] == ' ') {
					StringBuffer.erase(0, 1);
				}

				while (StringBuffer[0] != ' ') {
					BufferInput.push_back(StringBuffer[0]);
					StringBuffer.erase(0, 1);
				}
				buffer.NumberPhone = BufferInput;
				BufferInput.clear();

				while (StringBuffer[0] == ' ') {
					StringBuffer.erase(0, 1);
				}
				while (StringBuffer[0] != ' ') {
					BufferInput.push_back(StringBuffer[0]);
					StringBuffer.erase(0, 1);
				}
				buffer.NumberOfAuto = BufferInput;
				BufferInput.clear();


				while (StringBuffer[0] == ' ') {
					StringBuffer.erase(0, 1);
				}
				while (StringBuffer[0] != '\n' && StringBuffer.size() != 0) {
					BufferInput.push_back(StringBuffer[0]);
					StringBuffer.erase(0, 1);
				}
				buffer.MinutesOfStoyannya = atoi(BufferInput.c_str());
				BufferInput.clear();


				output.push_back(buffer);
			}
			return output;
		};

		void WriteParkingPlaces(std::vector <ParkingPlacess> work) {
			std::ofstream outf("ParkingPlaces.txt");
			for (int i = 0; i < work.size(); i++) {
				outf << i + 1 << ".) " << work[i].NumberPhone << " " << work[i].NumberOfAuto << " " << work[i].MinutesOfStoyannya << "\n";
			}
		}

		std::vector <ParkingPlacess> ChangeOne(int Number, std::vector <ParkingPlacess> work, std::string NumberPhone, std::string NumberOfAuto, int MinutesOfStoyannya) {
			ParkingPlacess buffer(NumberPhone, NumberOfAuto, MinutesOfStoyannya);
			work[Number] = buffer;
			WriteParkingPlaces(work);
			return work;
		}
		
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Administrator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::Label^ label11;

private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::Label^ label14;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(62, 251);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(185, 90);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Внести зміни";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Administrator::button1_MouseClick);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Info;
			this->textBox1->Location = System::Drawing::Point(431, 64);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Administrator::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Info;
			this->textBox2->Location = System::Drawing::Point(431, 143);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 2;
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Administrator::textBox2_KeyPress);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Info;
			this->textBox3->Location = System::Drawing::Point(431, 231);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 3;
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Administrator::textBox3_KeyPress);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::Info;
			this->textBox4->Location = System::Drawing::Point(431, 308);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 4;
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Administrator::textBox4_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(382, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(192, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Кількість парковочних місць";
			this->label1->Click += gcnew System::EventHandler(this, &Administrator::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(422, 124);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(120, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Поверхи(Якщо є)";
			this->label2->Click += gcnew System::EventHandler(this, &Administrator::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(423, 211);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(117, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Ціна (За годину)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(432, 288);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(104, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Ціна (За день)";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(62, 56);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 65);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Видалити клієнта";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Administrator::button2_MouseClick);
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::Bisque;
			this->textBox5->Location = System::Drawing::Point(234, 88);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 10;
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Administrator::textBox5_KeyPress);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(231, 68);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(103, 17);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Номер клієнта";
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label6->Location = System::Drawing::Point(22, 218);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(586, 159);
			this->label6->TabIndex = 12;
			// 
			// label7
			// 
			this->label7->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label7->Location = System::Drawing::Point(22, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(586, 159);
			this->label7->TabIndex = 13;
			// 
			// label8
			// 
			this->label8->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label8->Location = System::Drawing::Point(369, 137);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(239, 136);
			this->label8->TabIndex = 14;
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::Color::Silver;
			this->label9->Location = System::Drawing::Point(36, 26);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(554, 126);
			this->label9->TabIndex = 15;
			// 
			// label10
			// 
			this->label10->BackColor = System::Drawing::Color::Silver;
			this->label10->Location = System::Drawing::Point(382, 141);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(208, 217);
			this->label10->TabIndex = 16;
			// 
			// label11
			// 
			this->label11->BackColor = System::Drawing::Color::Silver;
			this->label11->Location = System::Drawing::Point(36, 233);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(370, 125);
			this->label11->TabIndex = 17;
			// 
			// label13
			// 
			this->label13->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label13->Location = System::Drawing::Point(22, 124);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(49, 159);
			this->label13->TabIndex = 19;
			// 
			// label14
			// 
			this->label14->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label14->Location = System::Drawing::Point(359, 14);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(17, 151);
			this->label14->TabIndex = 20;
			// 
			// Administrator
			// 
			this->textBox1->Text = Convert::ToString(ReadConfigTXT().CountOfParkPlaces);
			this->textBox2->Text = Convert::ToString(ReadConfigTXT().Floors);
			this->textBox3->Text = Convert::ToString(ReadConfigTXT().PriceForHour);
			this->textBox4->Text = Convert::ToString(ReadConfigTXT().PriceForDay);
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(632, 398);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label13);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Administrator";
			this->ShowIcon = false;
			this->Text = L"Administrator";
			this->Load += gcnew System::EventHandler(this, &Administrator::Administrator_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: System::Void Administrator_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
// Це є кнопка "Змінити" 
private: System::Void button1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	 
	this->FormConfigTXT(Convert::ToInt32(this->textBox1->Text), Convert::ToInt32(this->textBox2->Text), Convert::ToInt32(this->textBox3->Text), Convert::ToInt32(this->textBox4->Text));
	this->FormParkingPlaces(Convert::ToInt32(this->textBox1->Text)); 
}	
private: System::Void button2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	int buffer = Convert::ToInt32(this->textBox5->Text);
	std::vector <ParkingPlacess> buf = ReadParkingPlaces();
	if (buffer < ReadConfigTXT().CountOfParkPlaces) {
		ChangeOne(buffer, buf , "Empty", "Empty", 0);
		
	}

	
}
private: System::Void textBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if ((( e->KeyChar <= 47 || e->KeyChar > 57) && e->KeyChar != '\b'))
		e->Handled = true;
}
private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (((e->KeyChar <= 47 || e->KeyChar > 57) && e->KeyChar != '\b'))
		e->Handled = true;
}
private: System::Void textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (((e->KeyChar <= 47 || e->KeyChar > 57) && e->KeyChar != '\b'))
		e->Handled = true;
}
private: System::Void textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (((e->KeyChar <= 47 || e->KeyChar > 57) && e->KeyChar != '\b'))
		e->Handled = true;
}
private: System::Void textBox4_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (((e->KeyChar <= 47 || e->KeyChar > 57) && e->KeyChar != '\b'))
		e->Handled = true;
}
};
}


