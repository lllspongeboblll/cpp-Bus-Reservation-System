#include "MyForm.h"
#include "CreateAcc.h"
#include "lines.h"

System::Void Project2::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    Project2::CreateAcc^ form = gcnew Project2::CreateAcc();
    form->Show();
    this->Hide();
}

System::Void Project2::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    System::String^ username = textBox2->Text; // Username entered by the user
    System::String^ password = textBox1->Text; // Password entered by the user
    bool found = false; // Variable to check if a match is found

    // Check if users.csv exists
    if (System::IO::File::Exists("users.csv"))
    {
        System::IO::StreamReader^ reader = gcnew System::IO::StreamReader("users.csv");
        System::String^ line;
        // Read the file line by line
        while ((line = reader->ReadLine()) != nullptr)
        {
            array<System::String^>^ fields = line->Split(','); // Split the line by comma
            // Ensure the line has at least 3 fields (Username, Phone, Password) and check for a match
            if (fields->Length >= 3 && fields[0] == username && fields[2] == password)
            {
                found = true; // Match found
                break; // Exit the loop
            }
        }
        reader->Close(); // Close the file after reading
    }

    // If a match is found, open the lines form
    if (found)
    {
        Project2::lines^ form = gcnew Project2::lines();
        MessageBox::Show("Have a nice trip, " + username + "!", "Login Succeeded");
        form->Show();
        this->Hide();
    }
    // If no match is found, display an error message
    else
    {
        MessageBox::Show("Incorrect username or password", "Login Failed");
    }
}
