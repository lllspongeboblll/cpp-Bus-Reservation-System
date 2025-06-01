#include "Booking.h"
#include "lines.h"
#include "QR.h"
System::Void Project2::Booking::button7_Click_1(System::Object^ sender, System::EventArgs^ e) //copy this line from .h file//
{
    Project2::lines^ loginForm = gcnew Project2::lines(); //replace my form with the name of the form you want to open
    loginForm->Show();
    this->Close();

}
