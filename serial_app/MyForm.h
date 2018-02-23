#pragma once
#include "commands.h"

namespace serial_app {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;
	using namespace System::Windows::Input;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: commands^ Comm;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  PortName;

	private: System::Windows::Forms::Label^  label1;
	private: System::IO::Ports::SerialPort^  serial;
	private: System::Windows::Forms::ComboBox^  BaudRate;

	private: System::Windows::Forms::Label^  label2;
	protected:

	protected:
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->PortName = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->BaudRate = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(135, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Conectar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// PortName
			// 
			this->PortName->FormattingEnabled = true;
			this->PortName->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"COM1", L"COM2", L"COM3", L"COM4", L"COM5", L"COM6",
					L"COM7", L"COM8"
			});
			this->PortName->Location = System::Drawing::Point(12, 25);
			this->PortName->Name = L"PortName";
			this->PortName->Size = System::Drawing::Size(53, 21);
			this->PortName->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"COM Port";
			// 
			// BaudRate
			// 
			this->BaudRate->FormattingEnabled = true;
			this->BaudRate->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"300", L"600", L"1200", L"2400", L"4800", L"9600",
					L"14400", L"19200", L"28800", L"38400", L"57600", L"115200"
			});
			this->BaudRate->Location = System::Drawing::Point(71, 25);
			this->BaudRate->Name = L"BaudRate";
			this->BaudRate->Size = System::Drawing::Size(58, 21);
			this->BaudRate->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(71, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Baud Rate";
			// 
			// MyForm
			// 
			this->AcceptButton = this->button1;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(164, 41);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->BaudRate);
			this->Controls->Add(this->PortName);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			Comm = gcnew commands(PortName->Text, Convert::ToInt32(BaudRate->Text));
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message);
			return;
		}
			this->Hide();
			Comm->ShowDialog();
			this->Show();
			return;
	}
			 
};
}
