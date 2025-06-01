#include "MyForm.h" /*The window to open when the button is pressed*/
#include "CreateAcc.h" /*your current window*/
System::Void Project2::CreateAcc::button1_Click(System::Object^ sender, System::EventArgs^ e) //copy this line from .h file//
{
	Project2::MyForm^ loginForm = gcnew Project2::MyForm(); //replace my form with the name of the form you want to open
    loginForm->Show();
    this->Close();
}

