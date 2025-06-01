#include "lines.h"
#include "Booking.h"
#include <msclr/marshal_cppstd.h>
#include <fstream>

using namespace System::IO;  // Add this namespace for File and StreamWriter
using namespace System::Runtime::InteropServices;

System::Void Project2::lines::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    // 1. Get selected bus line
    String^ selectedLine = comboBox2->Text;

    // 2. Validate selection
    if (String::IsNullOrEmpty(selectedLine) ||
        selectedLine->Equals("  The Best Public Transportation in Egypt"))
    {
        MessageBox::Show("Please select a valid bus line first", "Selection Required");
        return;
    }

    // 3. CSV File Handling
    try
    {
        // File operations
        String^ filePath = "database_el5laba.csv";

        // Create or append to file
        StreamWriter^ sw = gcnew StreamWriter(filePath, true);

        // Write header if file is new
        if (sw->BaseStream->Length == 0) {
            sw->WriteLine("Selected Bus Lines");
        }

        // Write data
        sw->WriteLine(selectedLine);
        sw->Close();

        MessageBox::Show("Bus line saved successfully!", "Success");

        // 4. Open booking form
        Project2::Booking^ bookingForm = gcnew Project2::Booking();
        bookingForm->Show();
        this->Hide();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error: " + ex->Message, "Error");
    }
}