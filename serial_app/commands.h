#pragma once
#include "SDLWindow.h"
//https://github.com/wjwwood/serial biblioteca crossplatform para Comunicação Serial

namespace serial_app {
	using namespace Windows;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Summary for commands
	/// </summary>
	public ref class commands : public System::Windows::Forms::Form
	{
	public:
		
		commands(System::String^ Port, System::Int32 Baud);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~commands();

		///<summary>
		///user created variables.
		///</summary>
	private: int **correctionmotor;
	private: bool serialbusy = false;
	private: bool Directionalcontroll = false;
	private: String^ tmpstr;
			 ///<summary>
			 ///app created objects.
			 ///</summary>
	private: int **LastAxVal;
	private: SDLWindow *SDLWin;
	private: System::IO::Ports::SerialPort^  serial;
	private: System::Windows::Forms::CheckBox^  DirEn;
	private: System::Windows::Forms::Timer^  CmdTimer;
	private: System::Windows::Forms::GroupBox^  CommandsBox;
	private: System::Windows::Forms::TextBox^  CmdRIGHT;
	private: System::Windows::Forms::TextBox^  CmdDOWN;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  CmdLEFT;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  CmdUP;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::RichTextBox^  Historico;
	private: System::Windows::Forms::GroupBox^  SerialTimerBox;
	private: System::Windows::Forms::NumericUpDown^  TimerMilis;
	private: System::Windows::Forms::TextBox^  TimerCmd;
	private: System::Windows::Forms::CheckBox^  TimerEnable;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  Console;
	private: System::Windows::Forms::Timer^  SerialTimer;
	private: System::Windows::Forms::Label^  Bufferlbl;
	private: System::Windows::Forms::ComboBox^  J0Lst;

	private: System::Windows::Forms::Button^  J0Conn;
	private: System::Windows::Forms::Button^  J0Disconn;
	private: System::Windows::Forms::Label^  J0A1Lbl;
	private: System::Windows::Forms::Label^  J0A3Lbl;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::NumericUpDown^  R0M0Corr;
	private: System::Windows::Forms::NumericUpDown^  R0M1Corr;
	private: System::Windows::Forms::Label^  J0A1Val;
	private: System::Windows::Forms::Label^  J0A3Val;
	private: System::Windows::Forms::GroupBox^  Joystick0box;
	private: System::Windows::Forms::ComboBox^  J1Lst;

	private: System::Windows::Forms::Button^  J1Conn;
	private: System::Windows::Forms::Button^  J1Disconn;
	private: System::Windows::Forms::Label^  J1A1Lbl;
	private: System::Windows::Forms::Label^  J1A3Lbl;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::NumericUpDown^  R1M0Corr;
	private: System::Windows::Forms::NumericUpDown^  R1M1Corr;
	private: System::Windows::Forms::Label^  J1A1Val;
	private: System::Windows::Forms::Label^  J1A3Val;
	private: System::Windows::Forms::GroupBox^  Joystick1box;
	private: System::Windows::Forms::Button^  button1;






	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->serial = (gcnew System::IO::Ports::SerialPort(this->components));
			this->DirEn = (gcnew System::Windows::Forms::CheckBox());
			this->CmdTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->CommandsBox = (gcnew System::Windows::Forms::GroupBox());
			this->CmdRIGHT = (gcnew System::Windows::Forms::TextBox());
			this->CmdDOWN = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->CmdLEFT = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->CmdUP = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Historico = (gcnew System::Windows::Forms::RichTextBox());
			this->SerialTimerBox = (gcnew System::Windows::Forms::GroupBox());
			this->TimerMilis = (gcnew System::Windows::Forms::NumericUpDown());
			this->TimerCmd = (gcnew System::Windows::Forms::TextBox());
			this->TimerEnable = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Console = (gcnew System::Windows::Forms::TextBox());
			this->SerialTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->Bufferlbl = (gcnew System::Windows::Forms::Label());
			this->J0Lst = (gcnew System::Windows::Forms::ComboBox());
			this->J0Conn = (gcnew System::Windows::Forms::Button());
			this->J0Disconn = (gcnew System::Windows::Forms::Button());
			this->J0A1Lbl = (gcnew System::Windows::Forms::Label());
			this->J0A3Lbl = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->R0M0Corr = (gcnew System::Windows::Forms::NumericUpDown());
			this->R0M1Corr = (gcnew System::Windows::Forms::NumericUpDown());
			this->J0A1Val = (gcnew System::Windows::Forms::Label());
			this->J0A3Val = (gcnew System::Windows::Forms::Label());
			this->Joystick0box = (gcnew System::Windows::Forms::GroupBox());
			this->J1Lst = (gcnew System::Windows::Forms::ComboBox());
			this->J1Conn = (gcnew System::Windows::Forms::Button());
			this->J1Disconn = (gcnew System::Windows::Forms::Button());
			this->J1A1Lbl = (gcnew System::Windows::Forms::Label());
			this->J1A3Lbl = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->R1M0Corr = (gcnew System::Windows::Forms::NumericUpDown());
			this->R1M1Corr = (gcnew System::Windows::Forms::NumericUpDown());
			this->J1A1Val = (gcnew System::Windows::Forms::Label());
			this->J1A3Val = (gcnew System::Windows::Forms::Label());
			this->Joystick1box = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->CommandsBox->SuspendLayout();
			this->SerialTimerBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimerMilis))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R0M0Corr))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R0M1Corr))->BeginInit();
			this->Joystick0box->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R1M0Corr))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R1M1Corr))->BeginInit();
			this->Joystick1box->SuspendLayout();
			this->SuspendLayout();
			// 
			// serial
			// 
			this->serial->RtsEnable = true;
			// 
			// DirEn
			// 
			this->DirEn->AutoSize = true;
			this->DirEn->Location = System::Drawing::Point(12, 14);
			this->DirEn->Name = L"DirEn";
			this->DirEn->Size = System::Drawing::Size(103, 17);
			this->DirEn->TabIndex = 4;
			this->DirEn->Text = L"TextBox Controll";
			this->DirEn->UseVisualStyleBackColor = true;
			// 
			// CmdTimer
			// 
			this->CmdTimer->Tick += gcnew System::EventHandler(this, &commands::timer1_Tick);
			// 
			// CommandsBox
			// 
			this->CommandsBox->Controls->Add(this->CmdRIGHT);
			this->CommandsBox->Controls->Add(this->CmdDOWN);
			this->CommandsBox->Controls->Add(this->label6);
			this->CommandsBox->Controls->Add(this->label4);
			this->CommandsBox->Controls->Add(this->CmdLEFT);
			this->CommandsBox->Controls->Add(this->label5);
			this->CommandsBox->Controls->Add(this->CmdUP);
			this->CommandsBox->Controls->Add(this->label3);
			this->CommandsBox->Location = System::Drawing::Point(12, 137);
			this->CommandsBox->Name = L"CommandsBox";
			this->CommandsBox->Size = System::Drawing::Size(200, 124);
			this->CommandsBox->TabIndex = 3;
			this->CommandsBox->TabStop = false;
			this->CommandsBox->Text = L"Commands:";
			// 
			// CmdRIGHT
			// 
			this->CmdRIGHT->Location = System::Drawing::Point(48, 95);
			this->CmdRIGHT->Name = L"CmdRIGHT";
			this->CmdRIGHT->Size = System::Drawing::Size(100, 20);
			this->CmdRIGHT->TabIndex = 3;
			// 
			// CmdDOWN
			// 
			this->CmdDOWN->Location = System::Drawing::Point(48, 43);
			this->CmdDOWN->Name = L"CmdDOWN";
			this->CmdDOWN->Size = System::Drawing::Size(100, 20);
			this->CmdDOWN->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(7, 98);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"RIGHT";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 46);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"DOWN";
			// 
			// CmdLEFT
			// 
			this->CmdLEFT->Location = System::Drawing::Point(48, 69);
			this->CmdLEFT->Name = L"CmdLEFT";
			this->CmdLEFT->Size = System::Drawing::Size(100, 20);
			this->CmdLEFT->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(7, 72);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(33, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"LEFT";
			// 
			// CmdUP
			// 
			this->CmdUP->Location = System::Drawing::Point(48, 17);
			this->CmdUP->Name = L"CmdUP";
			this->CmdUP->Size = System::Drawing::Size(100, 20);
			this->CmdUP->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(22, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"UP";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(9, 43);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(150, 13);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Keep TextBox active to send :";
			// 
			// Historico
			// 
			this->Historico->Location = System::Drawing::Point(239, 12);
			this->Historico->Name = L"Historico";
			this->Historico->Size = System::Drawing::Size(276, 231);
			this->Historico->TabIndex = 7;
			this->Historico->Text = L"";
			this->Historico->TextChanged += gcnew System::EventHandler(this, &commands::Historico_TextChanged);
			// 
			// SerialTimerBox
			// 
			this->SerialTimerBox->Controls->Add(this->TimerMilis);
			this->SerialTimerBox->Controls->Add(this->TimerCmd);
			this->SerialTimerBox->Controls->Add(this->TimerEnable);
			this->SerialTimerBox->Controls->Add(this->label2);
			this->SerialTimerBox->Controls->Add(this->label1);
			this->SerialTimerBox->Location = System::Drawing::Point(11, 66);
			this->SerialTimerBox->Name = L"SerialTimerBox";
			this->SerialTimerBox->Size = System::Drawing::Size(200, 65);
			this->SerialTimerBox->TabIndex = 8;
			this->SerialTimerBox->TabStop = false;
			this->SerialTimerBox->Text = L"Timer";
			// 
			// TimerMilis
			// 
			this->TimerMilis->Location = System::Drawing::Point(7, 39);
			this->TimerMilis->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->TimerMilis->Name = L"TimerMilis";
			this->TimerMilis->Size = System::Drawing::Size(65, 20);
			this->TimerMilis->TabIndex = 6;
			this->TimerMilis->ValueChanged += gcnew System::EventHandler(this, &commands::TimerMilis_ValueChanged);
			// 
			// TimerCmd
			// 
			this->TimerCmd->Location = System::Drawing::Point(78, 38);
			this->TimerCmd->Name = L"TimerCmd";
			this->TimerCmd->Size = System::Drawing::Size(95, 20);
			this->TimerCmd->TabIndex = 5;
			// 
			// TimerEnable
			// 
			this->TimerEnable->AutoSize = true;
			this->TimerEnable->Location = System::Drawing::Point(179, 41);
			this->TimerEnable->Name = L"TimerEnable";
			this->TimerEnable->Size = System::Drawing::Size(15, 14);
			this->TimerEnable->TabIndex = 4;
			this->TimerEnable->UseVisualStyleBackColor = true;
			this->TimerEnable->CheckedChanged += gcnew System::EventHandler(this, &commands::checkBox1_CheckedChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(92, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Command:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Milis:";
			// 
			// Console
			// 
			this->Console->Location = System::Drawing::Point(167, 40);
			this->Console->Name = L"Console";
			this->Console->Size = System::Drawing::Size(65, 20);
			this->Console->TabIndex = 5;
			this->Console->TextChanged += gcnew System::EventHandler(this, &commands::Console_TextChanged);
			this->Console->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &commands::Console_KeyDown);
			// 
			// SerialTimer
			// 
			this->SerialTimer->Interval = 1;
			this->SerialTimer->Tick += gcnew System::EventHandler(this, &commands::SerialTimer_Tick);
			// 
			// Bufferlbl
			// 
			this->Bufferlbl->AutoSize = true;
			this->Bufferlbl->Location = System::Drawing::Point(480, 255);
			this->Bufferlbl->Name = L"Bufferlbl";
			this->Bufferlbl->Size = System::Drawing::Size(35, 13);
			this->Bufferlbl->TabIndex = 1;
			this->Bufferlbl->Text = L"Buffer";
			// 
			// J0Lst
			// 
			this->J0Lst->FormattingEnabled = true;
			this->J0Lst->Location = System::Drawing::Point(10, 16);
			this->J0Lst->Name = L"J0Lst";
			this->J0Lst->Size = System::Drawing::Size(31, 21);
			this->J0Lst->TabIndex = 1;
			// 
			// J0Conn
			// 
			this->J0Conn->Location = System::Drawing::Point(54, 15);
			this->J0Conn->Name = L"J0Conn";
			this->J0Conn->Size = System::Drawing::Size(56, 23);
			this->J0Conn->TabIndex = 2;
			this->J0Conn->Text = L"Connect";
			this->J0Conn->UseVisualStyleBackColor = true;
			this->J0Conn->Click += gcnew System::EventHandler(this, &commands::J0Conn_Click);
			// 
			// J0Disconn
			// 
			this->J0Disconn->Location = System::Drawing::Point(123, 15);
			this->J0Disconn->Name = L"J0Disconn";
			this->J0Disconn->Size = System::Drawing::Size(70, 23);
			this->J0Disconn->TabIndex = 3;
			this->J0Disconn->Text = L"Disconnect";
			this->J0Disconn->UseVisualStyleBackColor = true;
			this->J0Disconn->Click += gcnew System::EventHandler(this, &commands::J0Disconn_Click);
			// 
			// J0A1Lbl
			// 
			this->J0A1Lbl->AutoSize = true;
			this->J0A1Lbl->Location = System::Drawing::Point(6, 80);
			this->J0A1Lbl->Name = L"J0A1Lbl";
			this->J0A1Lbl->Size = System::Drawing::Size(35, 13);
			this->J0A1Lbl->TabIndex = 4;
			this->J0A1Lbl->Text = L"Axis1:";
			// 
			// J0A3Lbl
			// 
			this->J0A3Lbl->AutoSize = true;
			this->J0A3Lbl->Location = System::Drawing::Point(99, 81);
			this->J0A3Lbl->Name = L"J0A3Lbl";
			this->J0A3Lbl->Size = System::Drawing::Size(35, 13);
			this->J0A3Lbl->TabIndex = 4;
			this->J0A3Lbl->Text = L"Axis3:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(7, 56);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(58, 13);
			this->label9->TabIndex = 5;
			this->label9->Text = L"Correction:";
			// 
			// R0M0Corr
			// 
			this->R0M0Corr->Location = System::Drawing::Point(72, 52);
			this->R0M0Corr->Name = L"R0M0Corr";
			this->R0M0Corr->Size = System::Drawing::Size(57, 20);
			this->R0M0Corr->TabIndex = 6;
			this->R0M0Corr->ValueChanged += gcnew System::EventHandler(this, &commands::CorrectionChanged);
			// 
			// R0M1Corr
			// 
			this->R0M1Corr->Location = System::Drawing::Point(136, 52);
			this->R0M1Corr->Name = L"R0M1Corr";
			this->R0M1Corr->Size = System::Drawing::Size(57, 20);
			this->R0M1Corr->TabIndex = 6;
			this->R0M1Corr->ValueChanged += gcnew System::EventHandler(this, &commands::CorrectionChanged);
			// 
			// J0A1Val
			// 
			this->J0A1Val->AutoSize = true;
			this->J0A1Val->Location = System::Drawing::Point(59, 81);
			this->J0A1Val->Name = L"J0A1Val";
			this->J0A1Val->Size = System::Drawing::Size(22, 13);
			this->J0A1Val->TabIndex = 7;
			this->J0A1Val->Text = L"Val";
			// 
			// J0A3Val
			// 
			this->J0A3Val->AutoSize = true;
			this->J0A3Val->Location = System::Drawing::Point(152, 81);
			this->J0A3Val->Name = L"J0A3Val";
			this->J0A3Val->Size = System::Drawing::Size(22, 13);
			this->J0A3Val->TabIndex = 7;
			this->J0A3Val->Text = L"Val";
			// 
			// Joystick0box
			// 
			this->Joystick0box->Controls->Add(this->J0A3Val);
			this->Joystick0box->Controls->Add(this->J0A1Val);
			this->Joystick0box->Controls->Add(this->R0M1Corr);
			this->Joystick0box->Controls->Add(this->R0M0Corr);
			this->Joystick0box->Controls->Add(this->label9);
			this->Joystick0box->Controls->Add(this->J0A3Lbl);
			this->Joystick0box->Controls->Add(this->J0A1Lbl);
			this->Joystick0box->Controls->Add(this->J0Disconn);
			this->Joystick0box->Controls->Add(this->J0Conn);
			this->Joystick0box->Controls->Add(this->J0Lst);
			this->Joystick0box->Location = System::Drawing::Point(520, 12);
			this->Joystick0box->Name = L"Joystick0box";
			this->Joystick0box->Size = System::Drawing::Size(200, 101);
			this->Joystick0box->TabIndex = 13;
			this->Joystick0box->TabStop = false;
			this->Joystick0box->Text = L"Joystick 0";
			// 
			// J1Lst
			// 
			this->J1Lst->FormattingEnabled = true;
			this->J1Lst->Location = System::Drawing::Point(10, 16);
			this->J1Lst->Name = L"J1Lst";
			this->J1Lst->Size = System::Drawing::Size(31, 21);
			this->J1Lst->TabIndex = 1;
			// 
			// J1Conn
			// 
			this->J1Conn->Location = System::Drawing::Point(54, 15);
			this->J1Conn->Name = L"J1Conn";
			this->J1Conn->Size = System::Drawing::Size(56, 23);
			this->J1Conn->TabIndex = 2;
			this->J1Conn->Text = L"Connect";
			this->J1Conn->UseVisualStyleBackColor = true;
			this->J1Conn->Click += gcnew System::EventHandler(this, &commands::J1Conn_Click);
			// 
			// J1Disconn
			// 
			this->J1Disconn->Location = System::Drawing::Point(123, 15);
			this->J1Disconn->Name = L"J1Disconn";
			this->J1Disconn->Size = System::Drawing::Size(70, 23);
			this->J1Disconn->TabIndex = 3;
			this->J1Disconn->Text = L"Disconnect";
			this->J1Disconn->UseVisualStyleBackColor = true;
			this->J1Disconn->Click += gcnew System::EventHandler(this, &commands::J1Disconn_Click);
			// 
			// J1A1Lbl
			// 
			this->J1A1Lbl->AutoSize = true;
			this->J1A1Lbl->Location = System::Drawing::Point(6, 80);
			this->J1A1Lbl->Name = L"J1A1Lbl";
			this->J1A1Lbl->Size = System::Drawing::Size(35, 13);
			this->J1A1Lbl->TabIndex = 4;
			this->J1A1Lbl->Text = L"Axis1:";
			// 
			// J1A3Lbl
			// 
			this->J1A3Lbl->AutoSize = true;
			this->J1A3Lbl->Location = System::Drawing::Point(99, 81);
			this->J1A3Lbl->Name = L"J1A3Lbl";
			this->J1A3Lbl->Size = System::Drawing::Size(35, 13);
			this->J1A3Lbl->TabIndex = 4;
			this->J1A3Lbl->Text = L"Axis3:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(7, 56);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(58, 13);
			this->label11->TabIndex = 5;
			this->label11->Text = L"Correction:";
			// 
			// R1M0Corr
			// 
			this->R1M0Corr->Location = System::Drawing::Point(72, 52);
			this->R1M0Corr->Name = L"R1M0Corr";
			this->R1M0Corr->Size = System::Drawing::Size(57, 20);
			this->R1M0Corr->TabIndex = 6;
			this->R1M0Corr->ValueChanged += gcnew System::EventHandler(this, &commands::CorrectionChanged);
			// 
			// R1M1Corr
			// 
			this->R1M1Corr->Location = System::Drawing::Point(136, 52);
			this->R1M1Corr->Name = L"R1M1Corr";
			this->R1M1Corr->Size = System::Drawing::Size(57, 20);
			this->R1M1Corr->TabIndex = 6;
			this->R1M1Corr->ValueChanged += gcnew System::EventHandler(this, &commands::CorrectionChanged);
			// 
			// J1A1Val
			// 
			this->J1A1Val->AutoSize = true;
			this->J1A1Val->Location = System::Drawing::Point(59, 81);
			this->J1A1Val->Name = L"J1A1Val";
			this->J1A1Val->Size = System::Drawing::Size(22, 13);
			this->J1A1Val->TabIndex = 7;
			this->J1A1Val->Text = L"Val";
			// 
			// J1A3Val
			// 
			this->J1A3Val->AutoSize = true;
			this->J1A3Val->Location = System::Drawing::Point(152, 81);
			this->J1A3Val->Name = L"J1A3Val";
			this->J1A3Val->Size = System::Drawing::Size(22, 13);
			this->J1A3Val->TabIndex = 7;
			this->J1A3Val->Text = L"Val";
			// 
			// Joystick1box
			// 
			this->Joystick1box->Controls->Add(this->J1A3Val);
			this->Joystick1box->Controls->Add(this->J1A1Val);
			this->Joystick1box->Controls->Add(this->R1M1Corr);
			this->Joystick1box->Controls->Add(this->R1M0Corr);
			this->Joystick1box->Controls->Add(this->label11);
			this->Joystick1box->Controls->Add(this->J1A3Lbl);
			this->Joystick1box->Controls->Add(this->J1A1Lbl);
			this->Joystick1box->Controls->Add(this->J1Disconn);
			this->Joystick1box->Controls->Add(this->J1Conn);
			this->Joystick1box->Controls->Add(this->J1Lst);
			this->Joystick1box->Location = System::Drawing::Point(520, 121);
			this->Joystick1box->Name = L"Joystick1box";
			this->Joystick1box->Size = System::Drawing::Size(200, 101);
			this->Joystick1box->TabIndex = 13;
			this->Joystick1box->TabStop = false;
			this->Joystick1box->Text = L"Joystick 1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(571, 225);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 23);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Refresh Joysticks";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// commands
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(728, 274);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Joystick1box);
			this->Controls->Add(this->Joystick0box);
			this->Controls->Add(this->SerialTimerBox);
			this->Controls->Add(this->Historico);
			this->Controls->Add(this->CommandsBox);
			this->Controls->Add(this->Bufferlbl);
			this->Controls->Add(this->Console);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->DirEn);
			this->Name = L"commands";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L".";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &commands::commands_FormClosing);
			this->Load += gcnew System::EventHandler(this, &commands::commands_Load);
			this->CommandsBox->ResumeLayout(false);
			this->CommandsBox->PerformLayout();
			this->SerialTimerBox->ResumeLayout(false);
			this->SerialTimerBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimerMilis))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R0M0Corr))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R0M1Corr))->EndInit();
			this->Joystick0box->ResumeLayout(false);
			this->Joystick0box->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R1M0Corr))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R1M1Corr))->EndInit();
			this->Joystick1box->ResumeLayout(false);
			this->Joystick1box->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: void listJoys();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	public: System::Void commands_Load(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void Console_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void commands_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void Historico_TextChanged(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void Console_TextChanged(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void TimerMilis_ValueChanged(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void SerialTimer_Tick(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: System::Void RefreshJoys_Click(System::Object^  sender, System::EventArgs^  e);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: int JoyToHB(int, int);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: void JoystickWatch();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: bool SendSerial(String^); //master
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: System::Void CorrectionChanged(System::Object^  sender, System::EventArgs^  e);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private: bool SetMotors(int, int, int);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: System::Void J0Conn_Click(System::Object^  sender, System::EventArgs^  e);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: System::Void J1Conn_Click(System::Object^  sender, System::EventArgs^  e);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: System::Void J0Disconn_Click(System::Object^  sender, System::EventArgs^  e);
		 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: System::Void J1Disconn_Click(System::Object^  sender, System::EventArgs^  e);
		 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
};
}