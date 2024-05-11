#pragma once
#include "User.h"

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for Budget_Setter
	/// </summary>
	public ref class Budget_Setter : public System::Windows::Forms::Form
	{
	public:
		int income;
		Budget_Setter(USER^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->name_label->Text = user->username;
			this->income = user->income;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Budget_Setter()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label7;




	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ panel4;




	private: System::Windows::Forms::TextBox^ textBox2;

	private: System::Windows::Forms::Label^ label4;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TabControl^ abc;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ name_label;




























	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->abc = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->abc->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1078, 90);
			this->panel1->TabIndex = 6;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Budget_Setter::panel1_Paint);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label7);
			this->panel2->Location = System::Drawing::Point(-1, -1);
			this->panel2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(250, 90);
			this->panel2->TabIndex = 3;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Budget_Setter::panel2_Paint);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe Script", 26, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label7->ForeColor = System::Drawing::Color::Navy;
			this->label7->Location = System::Drawing::Point(-5, 18);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(254, 57);
			this->label7->TabIndex = 1;
			this->label7->Text = L"CoinControl";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel5->Controls->Add(this->label6);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel5->Location = System::Drawing::Point(0, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(648, 60);
			this->panel5->TabIndex = 16;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(20, 21);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(270, 25);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Budget/Goal Setup Form";
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button4->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button4->Location = System::Drawing::Point(542, 298);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(94, 31);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Submit";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Budget_Setter::button4_Click);
			// 
			// panel4
			// 
			this->panel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->panel4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel4->Controls->Add(this->abc);
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Controls->Add(this->button4);
			this->panel4->Controls->Add(this->textBox2);
			this->panel4->Controls->Add(this->label4);
			this->panel4->Controls->Add(this->label1);
			this->panel4->Location = System::Drawing::Point(354, 206);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(648, 338);
			this->panel4->TabIndex = 8;
			// 
			// abc
			// 
			this->abc->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->abc->Controls->Add(this->tabPage1);
			this->abc->Controls->Add(this->tabPage2);
			this->abc->Controls->Add(this->tabPage3);
			this->abc->Controls->Add(this->tabPage4);
			this->abc->Location = System::Drawing::Point(182, 91);
			this->abc->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->abc->Name = L"abc";
			this->abc->SelectedIndex = 0;
			this->abc->Size = System::Drawing::Size(399, 79);
			this->abc->TabIndex = 7;
			// 
			// tabPage1
			// 
			this->tabPage1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tabPage1->Controls->Add(this->textBox6);
			this->tabPage1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage1->Size = System::Drawing::Size(391, 53);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Utilities";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &Budget_Setter::tabPage1_Click);
			// 
			// textBox6
			// 
			this->textBox6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox6->Location = System::Drawing::Point(37, 15);
			this->textBox6->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(315, 20);
			this->textBox6->TabIndex = 13;
			// 
			// tabPage2
			// 
			this->tabPage2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tabPage2->Controls->Add(this->textBox5);
			this->tabPage2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage2->Size = System::Drawing::Size(391, 53);
			this->tabPage2->TabIndex = 4;
			this->tabPage2->Text = L"Entertainment";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// textBox5
			// 
			this->textBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox5->Location = System::Drawing::Point(37, 15);
			this->textBox5->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(250, 20);
			this->textBox5->TabIndex = 13;
			// 
			// tabPage3
			// 
			this->tabPage3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tabPage3->Controls->Add(this->textBox4);
			this->tabPage3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage3->Size = System::Drawing::Size(391, 53);
			this->tabPage3->TabIndex = 5;
			this->tabPage3->Text = L"Healthcare";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// textBox4
			// 
			this->textBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox4->Location = System::Drawing::Point(37, 15);
			this->textBox4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(250, 20);
			this->textBox4->TabIndex = 13;
			// 
			// tabPage4
			// 
			this->tabPage4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tabPage4->Controls->Add(this->textBox7);
			this->tabPage4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage4->Size = System::Drawing::Size(391, 53);
			this->tabPage4->TabIndex = 6;
			this->tabPage4->Text = L"Food";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// textBox7
			// 
			this->textBox7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox7->Location = System::Drawing::Point(38, 16);
			this->textBox7->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(250, 20);
			this->textBox7->TabIndex = 12;
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Location = System::Drawing::Point(182, 199);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(399, 20);
			this->textBox2->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(54, 197);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(128, 24);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Income Goal";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(54, 91);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(131, 24);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Budget Goal ";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::SteelBlue;
			this->panel3->Controls->Add(this->name_label);
			this->panel3->Controls->Add(this->button3);
			this->panel3->Controls->Add(this->button2);
			this->panel3->Controls->Add(this->button1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel3->Location = System::Drawing::Point(0, 90);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(250, 543);
			this->panel3->TabIndex = 4;
			// 
			// name_label
			// 
			this->name_label->AutoSize = true;
			this->name_label->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name_label->ForeColor = System::Drawing::Color::SteelBlue;
			this->name_label->Location = System::Drawing::Point(45, 335);
			this->name_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->name_label->Name = L"name_label";
			this->name_label->Size = System::Drawing::Size(109, 37);
			this->name_label->TabIndex = 9;
			this->name_label->Text = L"label2";
			this->name_label->Click += gcnew System::EventHandler(this, &Budget_Setter::label2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::SteelBlue;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button3->Location = System::Drawing::Point(0, 205);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(250, 47);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Budget/Goal Setup Form";
			this->button3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(0, 152);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(250, 47);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Transaction Log";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Budget_Setter::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SteelBlue;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(0, 99);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(250, 47);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Dashboard";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Budget_Setter::button1_Click);
			// 
			// Budget_Setter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->ClientSize = System::Drawing::Size(1078, 633);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel4);
			this->Name = L"Budget_Setter";
			this->Text = L"Budget_Setter";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Budget_Setter::Budget_Setter_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->abc->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	public: bool switch_to_dashboard = false;
	public: bool switch_to_transaction = false;

	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switch_to_dashboard = true;
		this->Close();
	}


	private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ utility_budget = this->textBox6->Text;
		String^ ent_budget = this->textBox5->Text;
		String^ health_budget = this->textBox4->Text;
		String^ food_budget = this->textBox7->Text;
		String^ income_goal = this->textBox2->Text;

		int utility, food, ent, health;

		if (utility_budget != "") {
			utility = Convert::ToInt32(utility_budget);
		}
		else {
			utility = 0;
		}

		if (food_budget != "") {
			food = Convert::ToInt32(food_budget);
		}
		else {
			food = 0;
		}
		if (ent_budget != "") {
			ent = Convert::ToInt32(ent_budget);
		}
		else {
			ent = 0;
		}

		if (health_budget != "") {
			health = Convert::ToInt32(health_budget);
		}
		else {
			health = 0;
		}

		int total_budget = utility + ent + health + food;

		try {

			String^ conn_str = "Data Source=MIANZAIN\\SQLEXPRESS;Initial Catalog=APP;Integrated Security=True";
			SqlConnection sqlConn(conn_str);

			sqlConn.Open();

			String^ tmpQuery = "SELECT * FROM Budget WHERE Username = @user";

			SqlCommand^ command = gcnew SqlCommand(tmpQuery, % sqlConn);
			command->Parameters->AddWithValue("@user", this->name_label->Text);
			SqlDataReader^ reader = command->ExecuteReader();

			if (reader->Read()) {

				reader->Close();
				if (total_budget <= this->income)
				{
					if (utility_budget != "") {
						String^ sqlQuery = "UPDATE Budget SET Budget = @budget WHERE Username = @user AND Category = @cat";

						SqlCommand^ command = gcnew SqlCommand(sqlQuery, % sqlConn);
						command->Parameters->AddWithValue("@user", this->name_label->Text);
						command->Parameters->AddWithValue("@cat", "Utility");
						command->Parameters->AddWithValue("@budget", utility);

						command->ExecuteNonQuery();
					}

					if (ent_budget != "") {
						String^ sqlQuery = "UPDATE Budget SET Budget = @budget WHERE Username = @user AND Category = @cat";

						SqlCommand^ command = gcnew SqlCommand(sqlQuery, % sqlConn);
						command->Parameters->AddWithValue("@user", this->name_label->Text);
						command->Parameters->AddWithValue("@cat", "Entertainment");
						command->Parameters->AddWithValue("@budget", ent);

						command->ExecuteNonQuery();
					}

					if (health_budget != "") {
						String^ sqlQuery = "UPDATE Budget SET Budget = @budget WHERE Username = @user AND Category = @cat";

						SqlCommand^ command = gcnew SqlCommand(sqlQuery, % sqlConn);
						command->Parameters->AddWithValue("@user", this->name_label->Text);
						command->Parameters->AddWithValue("@cat", "Healthcare");
						command->Parameters->AddWithValue("@budget", health);

						command->ExecuteNonQuery();
					}

					if (food_budget != "") {
						String^ sqlQuery = "UPDATE Budget SET Budget = @budget WHERE Username = @user AND Category = @cat";

						SqlCommand^ command = gcnew SqlCommand(sqlQuery, % sqlConn);
						command->Parameters->AddWithValue("@user", this->name_label->Text);
						command->Parameters->AddWithValue("@cat", "Food");
						command->Parameters->AddWithValue("@budget", food);

						command->ExecuteNonQuery();
					}

					if (income_goal != "") {
						String^ sqlQuery = "UPDATE Income_goal SET income_goal = @goal WHERE Username = @user";

						SqlCommand^ command = gcnew SqlCommand(sqlQuery, % sqlConn);
						command->Parameters->AddWithValue("@user", this->name_label->Text);
						command->Parameters->AddWithValue("@goal", income);

						command->ExecuteNonQuery();
					}

					MessageBox::Show("Your Budget is Updated Successfully", "Success", MessageBoxButtons::OK);
				}
				else {
					MessageBox::Show("Budget Exceeded Income for Updation", "Budget Setting Failed", MessageBoxButtons::OK);
				}
			}

			else {
				reader->Close();
				if (total_budget <= this->income)
				{
					if (utility_budget != "") {
						String^ sqlQuery = "INSERT INTO Budget (Username , Category , Budget) VALUES (@user  , @cat , @budget)";

						SqlCommand^ command = gcnew SqlCommand(sqlQuery, % sqlConn);
						command->Parameters->AddWithValue("@user", this->name_label->Text);
						command->Parameters->AddWithValue("@cat", "Utility");
						command->Parameters->AddWithValue("@budget", utility);

						command->ExecuteNonQuery();
					}

					if (ent_budget != "") {
						String^ sqlQuery = "INSERT INTO Budget (Username , Category , Budget) VALUES (@user  , @cat , @budget)";

						SqlCommand^ command = gcnew SqlCommand(sqlQuery, % sqlConn);
						command->Parameters->AddWithValue("@user", this->name_label->Text);
						command->Parameters->AddWithValue("@cat", "Entertainment");
						command->Parameters->AddWithValue("@budget", ent);

						command->ExecuteNonQuery();
					}

					if (health_budget != "") {
						String^ sqlQuery = "INSERT INTO Budget (Username , Category , Budget) VALUES (@user  , @cat , @budget)";

						SqlCommand^ command = gcnew SqlCommand(sqlQuery, % sqlConn);
						command->Parameters->AddWithValue("@user", this->name_label->Text);
						command->Parameters->AddWithValue("@cat", "Healthcare");
						command->Parameters->AddWithValue("@budget", health);

						command->ExecuteNonQuery();
					}

					if (food_budget != "") {
						String^ sqlQuery = "INSERT INTO Budget (Username , Category , Budget) VALUES (@user  , @cat , @budget)";

						SqlCommand^ command = gcnew SqlCommand(sqlQuery, % sqlConn);
						command->Parameters->AddWithValue("@user", this->name_label->Text);
						command->Parameters->AddWithValue("@cat", "Food");
						command->Parameters->AddWithValue("@budget", food);

						command->ExecuteNonQuery();
					}

					if (income_goal != "") {
						String^ sqlQuery = "INSERT INTO Income_goal (Username , income_goal) VALUES (@user  , @goal)";

						SqlCommand^ command = gcnew SqlCommand(sqlQuery, % sqlConn);
						command->Parameters->AddWithValue("@user", this->name_label->Text);
						command->Parameters->AddWithValue("@goal", income);

						command->ExecuteNonQuery();
					}

					MessageBox::Show("Your Budget is set Successfully", "Success", MessageBoxButtons::OK);
				}
				else {
					MessageBox::Show("Budget Exceeded Income", "Budget Setting Failed", MessageBoxButtons::OK);
				}
			}
		}

		catch (Exception^ e) {
			MessageBox::Show("Failed to Add Budget" + e->Message, "Budget Setting Failed", MessageBoxButtons::OK);
		}
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switch_to_transaction = true;
		this->Close();
	}
	private: System::Void Budget_Setter_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}