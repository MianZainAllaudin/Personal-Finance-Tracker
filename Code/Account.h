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
	/// Summary for Account
	/// </summary>
	public ref class Account : public System::Windows::Forms::Form
	{
	public:
		Account(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->CenterToScreen();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Account()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:

	protected:

	protected:






	private: System::Windows::Forms::TextBox^ username_box;
	private: System::Windows::Forms::TextBox^ pass_box;
	private: System::Windows::Forms::TextBox^ Income_box;
	private: System::Windows::Forms::Button^ account_button;
	private: System::Windows::Forms::LinkLabel^ login_link;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Account::typeid));
			this->username_box = (gcnew System::Windows::Forms::TextBox());
			this->pass_box = (gcnew System::Windows::Forms::TextBox());
			this->Income_box = (gcnew System::Windows::Forms::TextBox());
			this->account_button = (gcnew System::Windows::Forms::Button());
			this->login_link = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// username_box
			// 
			this->username_box->Location = System::Drawing::Point(1104, 350);
			this->username_box->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->username_box->Name = L"username_box";
			this->username_box->Size = System::Drawing::Size(544, 22);
			this->username_box->TabIndex = 5;
			// 
			// pass_box
			// 
			this->pass_box->Location = System::Drawing::Point(1104, 491);
			this->pass_box->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pass_box->Name = L"pass_box";
			this->pass_box->Size = System::Drawing::Size(544, 22);
			this->pass_box->TabIndex = 6;

			// Income_box
			// 
			this->Income_box->Location = System::Drawing::Point(1104, 623);
			this->Income_box->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Income_box->Name = L"Income_box";
			this->Income_box->Size = System::Drawing::Size(544, 22);
			this->Income_box->TabIndex = 7;
			// 
			// account_button
			// 
			this->account_button->BackColor = System::Drawing::Color::AliceBlue;
			this->account_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->account_button->ForeColor = System::Drawing::Color::MidnightBlue;
			this->account_button->Location = System::Drawing::Point(1300, 687);
			this->account_button->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->account_button->Name = L"account_button";
			this->account_button->Size = System::Drawing::Size(200, 42);
			this->account_button->TabIndex = 8;
			this->account_button->Text = L"Create";
			this->account_button->UseVisualStyleBackColor = false;
			this->account_button->Click += gcnew System::EventHandler(this, &Account::account_button_Click);
			// 
			// login_link
			// 
			this->login_link->AutoSize = true;
			this->login_link->BackColor = System::Drawing::Color::LightSteelBlue;
			this->login_link->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login_link->LinkColor = System::Drawing::Color::DarkBlue;
			this->login_link->Location = System::Drawing::Point(1512, 754);
			this->login_link->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->login_link->Name = L"login_link";
			this->login_link->Size = System::Drawing::Size(87, 29);
			this->login_link->TabIndex = 10;
			this->login_link->TabStop = true;
			this->login_link->Text = L"LOGIN";
			this->login_link->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Account::login_link_LinkClicked);
			// 
			// Account
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1763, 817);
			this->Controls->Add(this->login_link);
			this->Controls->Add(this->account_button);
			this->Controls->Add(this->Income_box);
			this->Controls->Add(this->pass_box);
			this->Controls->Add(this->username_box);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Account";
			this->Text = L"Account";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Account::Account_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Account_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	public: bool switch_to_login = false;
	private: System::Void login_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		this->switch_to_login = true;
		this->Close();
	}

		   bool IsFirstCharacterAlphabet(String^ str)
		   {
			   if (str == nullptr || str->Length == 0)
			   {
				   // Handle empty string or null reference
				   return true;
			   }
			   else
			   {
				   wchar_t firstChar = str[0]; // Get the first character

				   // Check if the first character is a letter (alphabet)
				   return Char::IsLetter(firstChar);
			   }
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

	public: USER^ user = nullptr;
	private: System::Void account_button_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ username = username_box->Text;
		String^ password = pass_box->Text;
		String^ income = Income_box->Text;

		bool username_validation = IsFirstCharacterAlphabet(username);
		bool income_validation = ContainsDigit(income);

		if (username->Length == 0 || password->Length == 0 || income->Length == 0 || (!username_validation) || (income_validation)) {
			MessageBox::Show("PlEASE ENTER ALL THE FIELDS AND ENTER VALID DATA!!", "One or More Empty Fields", MessageBoxButtons::OK);
			return;
		}
		else {
			int incomeInt = Convert::ToInt32(income);
			try {

				String^ conn_str = "Data Source=MIANZAIN\\SQLEXPRESS;Initial Catalog=APP;Integrated Security=True";
				SqlConnection sqlConn(conn_str);

				sqlConn.Open();

				String^ sqlQuery = "INSERT INTO Credentials (Username , Passkey , Income , Balance) VALUES (@user  , @pwd , @income , @balance)";

				SqlCommand^ command = gcnew SqlCommand(sqlQuery, % sqlConn);
				command->Parameters->AddWithValue("@user", username);
				command->Parameters->AddWithValue("@pwd", password);
				command->Parameters->AddWithValue("@income", incomeInt);
				command->Parameters->AddWithValue("@balance", incomeInt);

				command->ExecuteNonQuery();

				user = gcnew USER;
				user->username = username;
				user->income = incomeInt;
				user->balance = incomeInt;

				this->Close();

			}
			catch (Exception^ e) {
				MessageBox::Show("Failed to Create Account", "Account Creation Failed", MessageBoxButtons::OK);
			}

		}
	}
	};
}