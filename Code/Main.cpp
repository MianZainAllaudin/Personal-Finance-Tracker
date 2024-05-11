#include "login_form.h"
#include "dashboard.h"
#include "Account.h"
#include "Transaction.h"
#include "Budget_Setter.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	USER^ user = nullptr;
	while (true) {
		Project::login_form log;
		log.ShowDialog();
		user = log.user;
		if (log.switch_to_account) {
			Project::Account account;
			account.ShowDialog();
			if (account.switch_to_login) {
				continue;
			}
			else {
				user = account.user;
				break;
			}
		}

		if (user != nullptr) {
			break;
		}
	}

	while (true) {
		Project::Dashboard dash(user);
		Application::Run(% dash);
		if (dash.switch_to_transaction) {
			Project::Transaction transaction(user);
			transaction.ShowDialog();
			if (transaction.switch_to_dashboard) {
				continue;
			}
			else if (transaction.switch_to_budget) {
				Project::Budget_Setter setter(user);
				setter.ShowDialog();
			}

		}
		else if (dash.switch_to_budget) {
			Project::Budget_Setter setter(user);
			setter.ShowDialog();
			if (setter.switch_to_dashboard) {
				continue;
			}
			else if (setter.switch_to_transaction) {
				Project::Transaction transaction(user);
				transaction.ShowDialog();
			}

		}

		else if (dash.switch_to_login) {
			Project::login_form log;
			log.ShowDialog();
		}
		else {
			break;
		}
	}

}
