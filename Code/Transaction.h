#pragma once
#include"User.h"
namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for frontEndii
	/// </summary>
	public ref class Transaction : public System::Windows::Forms::Form
	{
	public:
		int utility_budget, healthcare_budget, ent_budget, food_budget, balance, utility_spent, health_spent, ent_spent, food_spent;
		Transaction(USER^ user)
		{
			InitializeComponent(); // Move this line to the top

			if (user == nullptr)
			{
				MessageBox::Show("User not found", "Error", MessageBoxButtons::OK);
				this->Close();
			}
			else
			{
				// Ensure that name_label is not null before trying to access its Text property
				if (this->name_label != nullptr)
				{
					this->name_label->Text = user->username;

					try {
						String^ conn_str = "Data Source=MIANZAIN\\SQLEXPRESS;Initial Catalog=APP;Integrated Security=True";
						SqlConnection sqlConn(conn_str);
						sqlConn.Open();
						String^ sqlQuery1 = "select Balance , Budget from Credentials JOIN Budget On Credentials.Username = Budget.Username Where Credentials.Username = @user AND Category = @cat";
						SqlCommand^ command1 = gcnew SqlCommand(sqlQuery1, % sqlConn);
						command1->Parameters->AddWithValue("@user", user->username);
						command1->Parameters->AddWithValue("@cat", "Utility");
						SqlDataReader^ reader1 = command1->ExecuteReader();

						if (reader1->Read()) {
							balance = reader1->GetInt64(0);
							utility_budget = reader1->GetInt64(1);
						}
						reader1->Close();
					}

					catch (Exception^ ex) {

					}

					try {
						String^ conn_str = "Data Source=MIANZAIN\\SQLEXPRESS;Initial Catalog=APP;Integrated Security=True";
						SqlConnection sqlConn(conn_str);
						sqlConn.Open();
						String^ sqlQuery1 = "select Budget from Credentials JOIN Budget On Credentials.Username = Budget.Username Where Credentials.Username = @user AND Category = @cat";
						SqlCommand^ command1 = gcnew SqlCommand(sqlQuery1, % sqlConn);
						command1->Parameters->AddWithValue("@user", user->username);
						command1->Parameters->AddWithValue("@cat", "Entertainment");
						SqlDataReader^ reader1 = command1->ExecuteReader();

						if (reader1->Read()) {
							ent_budget = reader1->GetInt64(0);
						}
						reader1->Close();
					}

					catch (Exception^ ex) {

					}
					try {
						String^ conn_str = "Data Source=MIANZAIN\\SQLEXPRESS;Initial Catalog=APP;Integrated Security=True";
						SqlConnection sqlConn(conn_str);
						sqlConn.Open();
						String^ sqlQuery1 = "select  Budget from Credentials JOIN Budget On Credentials.Username = Budget.Username Where Credentials.Username = @user AND Category = @cat";
						SqlCommand^ command1 = gcnew SqlCommand(sqlQuery1, % sqlConn);
						command1->Parameters->AddWithValue("@user", user->username);
						command1->Parameters->AddWithValue("@cat", "Healthcare");
						SqlDataReader^ reader1 = command1->ExecuteReader();

						if (reader1->Read()) {

							healthcare_budget = reader1->GetInt64(0);
						}
						reader1->Close();
					}

					catch (Exception^ ex) {

					}
					try {
						String^ conn_str = "Data Source=MIANZAIN\\SQLEXPRESS;Initial Catalog=APP;Integrated Security=True";
						SqlConnection sqlConn(conn_str);
						sqlConn.Open();
						String^ sqlQuery1 = "select Budget from Credentials JOIN Budget On Credentials.Username = Budget.Username Where Credentials.Username = @user AND Category = @cat";
						SqlCommand^ command1 = gcnew SqlCommand(sqlQuery1, % sqlConn);
						command1->Parameters->AddWithValue("@user", user->username);
						command1->Parameters->AddWithValue("@cat", "Food");
						SqlDataReader^ reader1 = command1->ExecuteReader();

						if (reader1->Read()) {

							food_budget = reader1->GetInt64(0);
						}
						reader1->Close();
					}

					catch (Exception^ ex) {

					}

					// transactions sum for the category

					try {
						String^ conn_str = "Data Source=MIANZAIN\\SQLEXPRESS;Initial Catalog=APP;Integrated Security=True";
						SqlConnection sqlConn(conn_str);

						sqlConn.Open();

						String^ tmpQuery = "select COALESCE(SUM(Amount), 0), COALESCE(MAX(Budget), 0) from Budget as b JOIN Transactions as t on  b.Category = t.Category AND b.Username = t.Username WHERE  b.Username = @user AND b.Category = @cat";

						SqlCommand^ command = gcnew SqlCommand(tmpQuery, % sqlConn);
						command->Parameters->AddWithValue("@user", user->username);
						command->Parameters->AddWithValue("@cat", "Utility");
						SqlDataReader^ reader = command->ExecuteReader();

						if (reader->Read()) {
							utility_spent = reader->GetInt64(0);
						}
						else {
							utility_spent = 0;
						}

						reader->Close();
					}

					catch (Exception^ e) {
						MessageBox::Show(e->Message);
						//label2->Text = e->Message;
					}

					try {
						String^ conn_str = "Data Source=MIANZAIN\\SQLEXPRESS;Initial Catalog=APP;Integrated Security=True";
						SqlConnection sqlConn(conn_str);

						sqlConn.Open();

						String^ tmpQuery = "select COALESCE(SUM(Amount), 0), COALESCE(MAX(Budget), 0) from Budget as b JOIN Transactions as t on  b.Category = t.Category AND b.Username = t.Username WHERE  b.Username = @user AND b.Category = @cat";

						SqlCommand^ command = gcnew SqlCommand(tmpQuery, % sqlConn);
						command->Parameters->AddWithValue("@user", user->username);
						command->Parameters->AddWithValue("@cat", "Food");
						SqlDataReader^ reader = command->ExecuteReader();

						if (reader->Read()) {
							food_spent = reader->GetInt64(0);
						}
						else {
							food_spent = 0;
						}
						reader->Close();
					}

					catch (Exception^ e) {
						MessageBox::Show(e->Message);
						//label2->Text = e->Message;
					}

					try {
						String^ conn_str = "Data Source=MIANZAIN\\SQLEXPRESS;Initial Catalog=APP;Integrated Security=True";
						SqlConnection sqlConn(conn_str);

						sqlConn.Open();

						String^ tmpQuery = "select COALESCE(SUM(Amount), 0), COALESCE(MAX(Budget), 0) from Budget as b JOIN Transactions as t on  b.Category = t.Category AND b.Username = t.Username WHERE  b.Username = @user AND b.Category = @cat";

						SqlCommand^ command = gcnew SqlCommand(tmpQuery, % sqlConn);
						command->Parameters->AddWithValue("@user", user->username);
						command->Parameters->AddWithValue("@cat", "Healthcare");
						SqlDataReader^ reader = command->ExecuteReader();

						if (reader->Read()) {
							health_spent = reader->GetInt64(0);
						}
						else {
							health_spent = 0;
						}
						reader->Close();
					}

					catch (Exception^ e) {
						MessageBox::Show(e->Message);
						//label2->Text = e->Message;
					}

					try {
						String^ conn_str = "Data Source=MIANZAIN\\SQLEXPRESS;Initial Catalog=APP;Integrated Security=True";
						SqlConnection sqlConn(conn_str);

						sqlConn.Open();

						String^ tmpQuery = "select COALESCE(SUM(Amount), 0), COALESCE(MAX(Budget), 0) from Budget as b JOIN Transactions as t on  b.Category = t.Category AND b.Username = t.Username WHERE  b.Username = @user AND b.Category = @cat";

						SqlCommand^ command = gcnew SqlCommand(tmpQuery, % sqlConn);
						command->Parameters->AddWithValue("@user", user->username);
						command->Parameters->AddWithValue("@cat", "Entertainment");
						SqlDataReader^ reader = command->ExecuteReader();

						if (reader->Read()) {
							ent_spent = reader->GetInt64(0);

						}
						else {
							ent_spent = 0;
						}
						reader->Close();
					}

					catch (Exception^ e) {
						MessageBox::Show(e->Message);
						//label2->Text = e->Message;
					}

				}
				else
				{
					// Handle the case when name_label is null
					// ...
				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Transaction()
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
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ name_label;

	protected:
	protected:
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
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1053, 110);
			this->panel1->TabIndex = 3;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Transaction::panel1_Paint_1);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label7);
			this->panel2->Location = System::Drawing::Point(-1, -1);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(333, 110);
			this->panel2->TabIndex = 3;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe Script", 26, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label7->ForeColor = System::Drawing::Color::Navy;
			this->label7->Location = System::Drawing::Point(-7, 22);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(317, 73);
			this->label7->TabIndex = 1;
			this->label7->Text = L"CoinControl";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label7->Click += gcnew System::EventHandler(this, &Transaction::label7_Click_1);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::SteelBlue;
			this->panel3->Controls->Add(this->name_label);
			this->panel3->Controls->Add(this->button3);
			this->panel3->Controls->Add(this->button2);
			this->panel3->Controls->Add(this->button1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel3->Location = System::Drawing::Point(0, 110);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(333, 451);
			this->panel3->TabIndex = 4;
			// 
			// name_label
			// 
			this->name_label->Location = System::Drawing::Point(98, -14);
			this->name_label->Name = L"name_label";
			this->name_label->Size = System::Drawing::Size(100, 23);
			this->name_label->TabIndex = 0;
			this->name_label->Click += gcnew System::EventHandler(this, &Transaction::name_label_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::SteelBlue;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button3->Location = System::Drawing::Point(0, 277);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(333, 58);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Budget/Goal Setup Form";
			this->button3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Transaction::button3_Click_1);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::SteelBlue;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button2->Location = System::Drawing::Point(0, 212);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(333, 58);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Transaction Log";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SteelBlue;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Location = System::Drawing::Point(0, 146);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(333, 58);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Dashboard";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Transaction::button1_Click);
			// 
			// panel4
			// 
			this->panel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->panel4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Controls->Add(this->button4);
			this->panel4->Controls->Add(this->comboBox3);
			this->panel4->Controls->Add(this->comboBox2);
			this->panel4->Controls->Add(this->comboBox1);
			this->panel4->Controls->Add(this->textBox3);
			this->panel4->Controls->Add(this->textBox2);
			this->panel4->Controls->Add(this->label5);
			this->panel4->Controls->Add(this->label4);
			this->panel4->Controls->Add(this->label3);
			this->panel4->Controls->Add(this->label2);
			this->panel4->Controls->Add(this->label1);
			this->panel4->Location = System::Drawing::Point(472, 145);
			this->panel4->Margin = System::Windows::Forms::Padding(4);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(520, 416);
			this->panel4->TabIndex = 5;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel5->Controls->Add(this->label6);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel5->Location = System::Drawing::Point(0, 0);
			this->panel5->Margin = System::Windows::Forms::Padding(4);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(520, 74);
			this->panel5->TabIndex = 16;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(27, 26);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(224, 31);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Transaction Log";
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button4->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button4->Location = System::Drawing::Point(379, 367);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(125, 38);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Submit";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Transaction::button4_Click);
			// 
			// comboBox3
			// 
			this->comboBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->IntegralHeight = false;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Utility", L"Food", L"Healthcare", L"Entertainment" });
			this->comboBox3->Location = System::Drawing::Point(243, 112);
			this->comboBox3->Margin = System::Windows::Forms::Padding(4);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(187, 24);
			this->comboBox3->TabIndex = 15;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Transaction::comboBox3_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"USD", L"GBP", L"EUR", L"PKR" });
			this->comboBox2->Location = System::Drawing::Point(243, 260);
			this->comboBox2->Margin = System::Windows::Forms::Padding(4);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(187, 24);
			this->comboBox2->TabIndex = 14;
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Income", L"Expense" });
			this->comboBox1->Location = System::Drawing::Point(243, 209);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(187, 24);
			this->comboBox1->TabIndex = 13;
			// 
			// textBox3
			// 
			this->textBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox3->Location = System::Drawing::Point(243, 160);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(187, 22);
			this->textBox3->TabIndex = 12;
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Location = System::Drawing::Point(243, 314);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(187, 22);
			this->textBox2->TabIndex = 11;
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(72, 260);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(117, 29);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Currency";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(72, 311);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 29);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Date";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(72, 160);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 29);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Amount";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(72, 209);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 29);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Type";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(72, 112);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 29);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Category";
			this->label1->Click += gcnew System::EventHandler(this, &Transaction::label1_Click);
			// 
			// Transaction
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1053, 561);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Transaction";
			this->Text = L"frontEndii";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Transaction::frontEndii_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


	public: bool switch_to_dashboard = false;


	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void frontEndii_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel5_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label7_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel5_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

		   bool ContainsDigit(String^ str)
		   {
			   if (str == nullptr || str->Length == 0)
			   {
				   // Handle empty string or null reference
				   return false;
			   }
			   else
			   {
				   for each (wchar_t ch in str)
				   {
					   // Check if the character is a digit
					   if (Char::IsLetter(ch))
					   {
						   return true; // Return true if any character is a digit
					   }
				   }
				   return false; // Return false if no character is a digit
			   }
		   }

    private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ category = this->comboBox3->Text;
        String^ type = this->comboBox1->Text;
        String^ amount = this->textBox3->Text;
        String^ currency = this->comboBox2->Text;
        String^ date = this->textBox2->Text;
        bool amount_validation = ContainsDigit(amount);

        try {
            if (amount->Length == 0 || amount_validation || category->Length == 0 || type->Length == 0 || currency->Length == 0 || date->Length == 0) {
                throw gcnew Exception("Please fill in all the fields");
            }

            int amount_int = Convert::ToInt32(amount);
            if (amount_int > balance) {
                MessageBox::Show("Not Enough balance to Process this Transaction!!");
            }
            else if (category == "Utility" && amount_int > utility_budget - utility_spent) {
                MessageBox::Show("You're reaching limit for this Category!!");
            }
            else if (category == "Entertainment" && amount_int > ent_budget - ent_spent) {
                MessageBox::Show("You're reaching limit for this Category!!");
            }
            else if (category == "Healthcare" && amount_int > healthcare_budget - health_spent) {
                MessageBox::Show("You're reaching limit for this Category!!");
            }
            else if (category == "Food" && amount_int > food_budget - food_spent) {
                MessageBox::Show("You're reaching limit for this Category!!");
            }
            else {
                String^ conn_str = "Data Source=MIANZAIN\\SQLEXPRESS;Initial Catalog=APP;Integrated Security=True";
                SqlConnection sqlConn(conn_str);
                sqlConn.Open();
                String^ sqlQuery = "INSERT INTO Transactions (Username, Category, Type, Date, Amount, Currency) VALUES (@user, @cat, @type, @date, @amount, @currency)";
                SqlCommand^ command = gcnew SqlCommand(sqlQuery, % sqlConn);
                command->Parameters->AddWithValue("@user", this->name_label->Text);
                command->Parameters->AddWithValue("@cat", category);
                command->Parameters->AddWithValue("@type", type);
                command->Parameters->AddWithValue("@date", date);
                command->Parameters->AddWithValue("@amount", amount_int);
                command->Parameters->AddWithValue("@currency", currency);
                command->ExecuteNonQuery();
                MessageBox::Show("Transaction Added Successfully", "Success", MessageBoxButtons::OK);

                if (type == "Expense") {
                    String^ sqlQuery2 = "UPDATE CREDENTIALS SET Balance  = Balance - @amount where Username = @user";
                    SqlCommand^ command2 = gcnew SqlCommand(sqlQuery2, % sqlConn);
                    command2->Parameters->AddWithValue("@user", this->name_label->Text);
                    command2->Parameters->AddWithValue("@amount", amount_int);
                    command2->ExecuteNonQuery();
                }
                else {
                    String^ sqlQuery2 = "UPDATE CREDENTIALS SET Balance  = Balance + @amount where Username = @user";
                    SqlCommand^ command2 = gcnew SqlCommand(sqlQuery2, % sqlConn);
                    command2->Parameters->AddWithValue("@user", this->name_label->Text);
                    command2->Parameters->AddWithValue("@amount", amount_int);
                    command2->ExecuteNonQuery();
                }
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show(ex->Message, "Transaction Failed", MessageBoxButtons::OK);
        }
    }
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switch_to_dashboard = true;
		this->Close();
	}
	private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void name_label_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	public: bool switch_to_budget = false;
	private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
		this->switch_to_budget = true;
		this->Close();
	}
	};
}