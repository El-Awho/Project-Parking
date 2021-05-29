#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <msclr\marshal_cppstd.h>

namespace ProjectParking {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	
	
	class ConfigTXTERMAN {
	public:
		unsigned int CountOfParkPlaces;
		unsigned int Floors;
		unsigned int PriceForHour;
		unsigned int PriceForDay;
		ConfigTXTERMAN(unsigned int CountOfParkPlaces, unsigned int Floors, unsigned int PriceForHour, unsigned int PriceForDay) :
			CountOfParkPlaces(CountOfParkPlaces), Floors(Floors), PriceForHour(PriceForHour), PriceForDay(PriceForDay)
		{
		}
	};
	class ParkingPlacessMAN {
	public:
		std::string NumberPhone;
		std::string NumberOfAuto;
		int MinutesOfStoyannya;
		ParkingPlacessMAN() : NumberPhone("Empty"), MinutesOfStoyannya(0), NumberOfAuto("Empty") {
		}
		ParkingPlacessMAN(std::string NumberPhone, std::string NumberOfAuto, int MinutesOfStoyannya) : NumberPhone(NumberPhone),
			NumberOfAuto(NumberOfAuto), MinutesOfStoyannya(MinutesOfStoyannya)
		{
		}
	};
	
	

	/// <summary>
	/// Сводка для Manager
	/// </summary>
	public ref class Manager : public System::Windows::Forms::Form
	{
	public:
		Manager(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		
		ConfigTXTERMAN FormConfigTXT(unsigned int CountOfParkPlaces, unsigned int Floors, unsigned int PriceForHour, unsigned int PriceForDay) {
			std::ofstream outf("Config.txt");
			ConfigTXTERMAN buffer(CountOfParkPlaces, Floors, PriceForHour, PriceForDay);
			outf << "CountOfParkPlaces = " << CountOfParkPlaces << '\n';
			outf << "Floors = " << Floors << '\n';
			outf << "PriceForHour = " << PriceForHour << '\n';
			outf << "PriceForDay = " << PriceForDay << '\n';
			return buffer;
		}

		ConfigTXTERMAN ReadConfigTXT() {
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
			ConfigTXTERMAN Buffer(Number[0], Number[1], Number[2], Number[3]);
			return Buffer;
		};




		std::vector <ParkingPlacessMAN> FormParkingPlaces(int CountOfParkPlaces) {
			std::ofstream outf("ParkingPlaces.txt");
			std::vector <ParkingPlacessMAN> output;
			ParkingPlacessMAN buffer;
			for (int i = 0; i < CountOfParkPlaces; i++) {
				outf << i + 1 << ".) " << buffer.NumberPhone << " " << buffer.NumberOfAuto << " " << buffer.MinutesOfStoyannya << "\n";
				output.push_back(buffer);
			}
			return output;
		};

		std::vector <ParkingPlacessMAN> ReadParkingPlaces() {
			std::ifstream inf("ParkingPlaces.txt");
			std::vector <ParkingPlacessMAN> output;
			ParkingPlacessMAN buffer;
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
		
		int splatit;

		void WriteParkingPlaces(std::vector <ParkingPlacessMAN> work) {
			std::ofstream outf("ParkingPlaces.txt");
			for (int i = 0; i < work.size(); i++) {
				outf << i + 1 << ".) " << work[i].NumberPhone << " " << work[i].NumberOfAuto << " " << work[i].MinutesOfStoyannya << "\n";
			}
		}

		std::vector <ParkingPlacessMAN> ChangeOne(int Number, std::vector <ParkingPlacessMAN> work, std::string NumberPhone, std::string NumberOfAuto, int MinutesOfStoyannya) {
			ParkingPlacessMAN buffer(NumberPhone, NumberOfAuto, MinutesOfStoyannya);
			work[Number] = buffer;
			WriteParkingPlaces(work);
			return work;
		}

		void TimeMinus(std::vector <ParkingPlacessMAN>& work) {
			for (int i = 0; i < work.size(); i++) {
				if (work[i].NumberOfAuto != "Empty") {
					work[i].MinutesOfStoyannya--;
				}
			}
			WriteParkingPlaces(work);

		}

		bool AddNewClient(std::string NumberPhone, std::string NumberOfAuto, int MinutesOfStoyannya) {
		std::vector <ParkingPlacessMAN> Buffer = ReadParkingPlaces();
		for (int i = 0; i < ReadConfigTXT().CountOfParkPlaces; i++) {
			if (Buffer[i].MinutesOfStoyannya == 0 && Buffer[i].NumberOfAuto == "Empty" && Buffer[i].NumberPhone == "Empty") {
				Buffer[i].MinutesOfStoyannya = MinutesOfStoyannya;
				Buffer[i].NumberOfAuto = NumberOfAuto;
				Buffer[i].NumberPhone = NumberPhone;
				WriteParkingPlaces(Buffer);
				return true;
			}
		}
		return false;
		}
		
		
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Manager()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ textBox7;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::TextBox^ textBox8;
private: System::Windows::Forms::Button^ button3;


	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(26, 277);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(147, 79);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Новий клієнт";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Manager::button1_MouseClick);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Gainsboro;
			this->label2->Location = System::Drawing::Point(12, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(642, 362);
			this->label2->TabIndex = 17;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 60000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Manager::timer1_Tick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(240, 249);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 18;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(240, 334);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 19;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(230, 229);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 17);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Номер телефону";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(248, 313);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(120, 17);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Номер авто";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(455, 51);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(145, 67);
			this->button2->TabIndex = 22;
			this->button2->Text = L"Завершення аренди місця";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Manager::button2_MouseClick);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(443, 205);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(167, 17);
			this->label4->TabIndex = 24;
			this->label4->Text = L"Порядковий номер авто";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(476, 225);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 23;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(484, 303);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(85, 17);
			this->label5->TabIndex = 26;
			this->label5->Text = L"Номер авто";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(476, 323);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 25;
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::Color::LightGray;
			this->label6->Location = System::Drawing::Point(409, 19);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(235, 346);
			this->label6->TabIndex = 27;
			// 
			// label7
			// 
			this->label7->BackColor = System::Drawing::Color::LightGray;
			this->label7->Location = System::Drawing::Point(19, 223);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(383, 142);
			this->label7->TabIndex = 28;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(509, 264);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(33, 17);
			this->label8->TabIndex = 29;
			this->label8->Text = L"Або";
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::Color::LightGray;
			this->label9->Location = System::Drawing::Point(276, 19);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(368, 135);
			this->label9->TabIndex = 30;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::Gainsboro;
			this->richTextBox1->Location = System::Drawing::Point(295, 77);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(125, 41);
			this->richTextBox1->TabIndex = 31;
			this->richTextBox1->Text = L"";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(302, 51);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(111, 17);
			this->label10->TabIndex = 32;
			this->label10->Text = L"Сума до сплати";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(101, 64);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(80, 22);
			this->numericUpDown1->TabIndex = 33;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &Manager::numericUpDown1_ValueChanged);
			// 
			// label11
			// 
			this->label11->BackColor = System::Drawing::Color::LightGray;
			this->label11->Location = System::Drawing::Point(19, 19);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(251, 198);
			this->label11->TabIndex = 34;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(140, 101);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(120, 17);
			this->label12->TabIndex = 38;
			this->label12->Text = L"Номер телефону";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(42, 101);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(85, 17);
			this->label13->TabIndex = 37;
			this->label13->Text = L"Час аренди";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(150, 122);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 36;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(34, 121);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(100, 22);
			this->textBox6->TabIndex = 35;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(98, 155);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(85, 17);
			this->label15->TabIndex = 42;
			this->label15->Text = L"Номер авто";
			this->label15->Click += gcnew System::EventHandler(this, &Manager::label15_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(92, 175);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(100, 22);
			this->textBox7->TabIndex = 43;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(42, 229);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(109, 17);
			this->label14->TabIndex = 45;
			this->label14->Text = L"Оплачено(Грн)";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(45, 249);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 22);
			this->textBox8->TabIndex = 44;
			this->textBox8->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Manager::textBox8_KeyPress);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(481, 137);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(89, 53);
			this->button3->TabIndex = 46;
			this->button3->Text = L"Оплачено";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Manager::button3_MouseClick);
			// 
			// Manager
			// 
			this->textBox3->ReadOnly=false;

			this->numericUpDown1->Value = 1;
			this->textBox7->Text = gcnew String(ReadParkingPlaces()[Convert::ToInt32(this->numericUpDown1->Value) - 1].NumberOfAuto.c_str());
			this->textBox5->Text = gcnew String(ReadParkingPlaces()[Convert::ToInt32(this->numericUpDown1->Value) - 1].NumberPhone.c_str());
			this->textBox6->Text = Convert::ToString(ReadParkingPlaces()[Convert::ToInt32(this->numericUpDown1->Value) - 1].MinutesOfStoyannya);

			//
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(666, 380);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Manager";
			this->ShowIcon = false;
			this->Text = L"Manager";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &Manager::Manager_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Manager_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		TimeMinus(ReadParkingPlaces());
		this->textBox7->Text = gcnew String(ReadParkingPlaces()[Convert::ToInt32(this->numericUpDown1->Value) - 1].NumberOfAuto.c_str());
		this->textBox5->Text = gcnew String(ReadParkingPlaces()[Convert::ToInt32(this->numericUpDown1->Value) - 1].NumberPhone.c_str());
		this->textBox6->Text = Convert::ToString(ReadParkingPlaces()[Convert::ToInt32(this->numericUpDown1->Value) - 1].MinutesOfStoyannya);
	
	} 
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}



private: System::Void button2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	
	this->textBox4->Text;
	std::vector <ParkingPlacessMAN> j = ReadParkingPlaces();

	msclr::interop::marshal_context context;
	std::string NomerAuto = context.marshal_as<std::string>(this->textBox4->Text);
	std::string NomerPoryadok = context.marshal_as<std::string>(this->textBox3->Text);
	std::string Buffer;
	int NP;
	for (int i = 0; i < NomerPoryadok.size(); i++) {
		if (NomerPoryadok[i] <= 47 || NomerPoryadok[i] > 57) {
			NomerPoryadok.erase(i, 1);
			i--;
		}
	}
	if(NomerPoryadok.size()!=0)
	    NP = (std::stoi(NomerPoryadok))-1;

	// 0 0
	if (NomerPoryadok.size() == 0 && NomerAuto.size() == 0) {
		splatit = -1;
		this->richTextBox1->Text = "\0";
	}
	// 1 0
	// 1 1
	else if (NomerPoryadok.size() != 0 && NP <= j.size() && NP >= 0) {
		splatit = NP;
		Buffer += std::to_string(j[NP].MinutesOfStoyannya / 60 * ReadConfigTXT().PriceForHour);
		Buffer += " гривень\n";
		Buffer += j[NP].NumberOfAuto;
		this->richTextBox1->Text = gcnew String(Buffer.c_str());
	}
	// 0 1
	else if (NomerAuto.size() != 0) {
		for (int i = 0; i < j.size(); i++) {

			if (j[i].NumberOfAuto == NomerAuto) {
				splatit = i;
				Buffer += std::to_string(j[i].MinutesOfStoyannya / 60 * ReadConfigTXT().PriceForHour);
				Buffer += " гривень\n";
				Buffer += j[i].NumberOfAuto;
				this->richTextBox1->Text = gcnew String(Buffer.c_str());
				break;
			}
			else
				this->richTextBox1->Text = "\0";
		}
	}

}


private: System::Void button1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	msclr::interop::marshal_context context;
	msclr::interop::marshal_context cont;
	int Money;
	std::string Phone = context.marshal_as<std::string>(this->textBox1->Text); 
	std::string Car = cont.marshal_as<std::string>(this->textBox2->Text);
	if (Phone.size() == 0) {
		Phone = "Empty";
	}
	if (Car.size() == 0) {
		Car = "Empty";
	}
	std::string monyy = cont.marshal_as<std::string>(this->textBox8->Text);
	if(monyy.size() != 0)
		Money = Convert::ToInt32(this->textBox8->Text);
	else {
		Money = 0;
	}
	if(this->textBox1->Text != "Операція успішна." && this->textBox1->Text != "Операція невдалась" && (Phone != "Empty" || Car != "Empty"))
	if (AddNewClient(Phone, Car, 60*Money / ReadConfigTXT().PriceForHour) == true) {
		this->textBox1->Text = "\0";
		this->textBox2->Text = "\0";
		this->textBox8->Text = "\0";
	}
	else
		this->textBox1->Text = "Операція невдалась";
	else
		this->textBox1->Text = "Операція невдалась";
	this->textBox7->Text = gcnew String(ReadParkingPlaces()[Convert::ToInt32(this->numericUpDown1->Value) - 1].NumberOfAuto.c_str());
	this->textBox5->Text = gcnew String(ReadParkingPlaces()[Convert::ToInt32(this->numericUpDown1->Value) - 1].NumberPhone.c_str());
	this->textBox6->Text = Convert::ToString(ReadParkingPlaces()[Convert::ToInt32(this->numericUpDown1->Value) - 1].MinutesOfStoyannya);
}

	   
private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	
	if (Convert::ToInt32(this->numericUpDown1->Value) > ReadConfigTXT().CountOfParkPlaces) {
		this->numericUpDown1->Value = 1;
	}
	if (Convert::ToInt32(this->numericUpDown1->Value) == 0) {
		this->numericUpDown1->Value = ReadConfigTXT().CountOfParkPlaces;
	}
	this->textBox7->Text = gcnew String(ReadParkingPlaces()[Convert::ToInt32(this->numericUpDown1->Value)-1].NumberOfAuto.c_str());
	this->textBox5->Text = gcnew String(ReadParkingPlaces()[Convert::ToInt32(this->numericUpDown1->Value)-1].NumberPhone.c_str());
	this->textBox6->Text = Convert::ToString(ReadParkingPlaces()[Convert::ToInt32(this->numericUpDown1->Value)-1].MinutesOfStoyannya);
}
private: System::Void label15_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox8_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (((e->KeyChar <= 47 || e->KeyChar > 57) && e->KeyChar != '\b'))
		e->Handled = true;
}

private: System::Void button3_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	std::vector <ParkingPlacessMAN> buf = ReadParkingPlaces();
	if (splatit>=0 &&splatit < ReadConfigTXT().CountOfParkPlaces) {
		ChangeOne(splatit, buf, "Empty", "Empty", 0);
		splatit = -1;
	}
	this->richTextBox1->Text = "\0";
}
};
}
