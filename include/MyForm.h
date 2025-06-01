#pragma once
namespace Project2 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            //----------------------------------------------------------
            // 1) Create the resource manager BEFORE it is first used.
            //----------------------------------------------------------
            System::ComponentModel::ComponentResourceManager^ resources =
                gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid);

            //----------------------------------------------------------
            // 2) Build designer-generated controls.
            //----------------------------------------------------------
            InitializeComponent();

            //----------------------------------------------------------
            // 3) Load background image (once).
            //----------------------------------------------------------
            bgImage = nullptr;
            System::Object^ obj = resources->GetObject(L"$this.BackgroundImage");
            if (obj != nullptr && dynamic_cast<System::Drawing::Bitmap^>(obj) != nullptr)
            {
                bgImage = cli::safe_cast<System::Drawing::Bitmap^>(obj);
            }
            else
            {
                MessageBox::Show("Failed to load background image.",
                    "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }

            //----------------------------------------------------------
            // 4) Hook the Paint event.
            //----------------------------------------------------------
            this->Paint += gcnew PaintEventHandler(this, &MyForm::MyForm_Paint);
        }

    protected:
        ~MyForm()
        {
            if (components)
                delete components;
        }

    private:
        System::ComponentModel::Container^ components;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Panel^ panel2;
    private: System::Windows::Forms::CheckBox^ checkBox1;
    private: System::Windows::Forms::Label^ label4;

    private: System::Windows::Forms::Button^ button2;




    private: System::Windows::Forms::PictureBox^ pictureBox4;
    private: System::Windows::Forms::Button^ button3;



           System::Drawing::Bitmap^ bgImage;  // Background image stored here

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
            this->button3 = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30.75F, System::Drawing::FontStyle::Bold));
            this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label1->Location = System::Drawing::Point(37, 467);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(152, 55);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Sign in";
            this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label2->Location = System::Drawing::Point(47, 579);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(92, 23);
            this->label2->TabIndex = 0;
            this->label2->Text = L"Username:";
            this->label2->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->label3->Location = System::Drawing::Point(47, 676);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(86, 23);
            this->label3->TabIndex = 0;
            this->label3->Text = L"Password:";
            this->label3->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
            // 
            // textBox1
            // 
            this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
                static_cast<System::Int32>(static_cast<System::Byte>(48)));
            this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox1->ForeColor = System::Drawing::SystemColors::InactiveBorder;
            this->textBox1->Location = System::Drawing::Point(51, 725);
            this->textBox1->Name = L"textBox1";
            this->textBox1->PasswordChar = '*';
            this->textBox1->Size = System::Drawing::Size(323, 28);
            this->textBox1->TabIndex = 1;
            this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
            // 
            // textBox2
            // 
            this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
                static_cast<System::Int32>(static_cast<System::Byte>(48)));
            this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox2->ForeColor = System::Drawing::SystemColors::InactiveBorder;
            this->textBox2->Location = System::Drawing::Point(47, 606);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(323, 28);
            this->textBox2->TabIndex = 1;
            this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::MediumBlue;
            this->panel1->Location = System::Drawing::Point(47, 638);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(323, 2);
            this->panel1->TabIndex = 2;
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::Color::MediumBlue;
            this->panel2->Location = System::Drawing::Point(51, 754);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(323, 2);
            this->panel2->TabIndex = 2;
            // 
            // checkBox1
            // 
            this->checkBox1->AutoSize = true;
            this->checkBox1->Checked = true;
            this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
            this->checkBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.75F, System::Drawing::FontStyle::Bold));
            this->checkBox1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
            this->checkBox1->Location = System::Drawing::Point(51, 782);
            this->checkBox1->Name = L"checkBox1";
            this->checkBox1->Size = System::Drawing::Size(119, 24);
            this->checkBox1->TabIndex = 3;
            this->checkBox1->Text = L"I agree to the";
            this->checkBox1->UseVisualStyleBackColor = true;
            this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
            this->label4->ForeColor = System::Drawing::Color::Blue;
            this->label4->Location = System::Drawing::Point(164, 784);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(157, 20);
            this->label4->TabIndex = 0;
            this->label4->Text = L"Terms and Condtions ";
            this->label4->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
            // 
            // button2
            // 
            this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12.75F, System::Drawing::FontStyle::Bold));
            this->button2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
            this->button2->Location = System::Drawing::Point(197, 846);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(140, 35);
            this->button2->TabIndex = 5;
            this->button2->Text = L"Create account";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            // 
            // pictureBox4
            // 
            this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
            this->pictureBox4->Location = System::Drawing::Point(749, 489);
            this->pictureBox4->Name = L"pictureBox4";
            this->pictureBox4->Size = System::Drawing::Size(1080, 499);
            this->pictureBox4->TabIndex = 10;
            this->pictureBox4->TabStop = false;
            // 
            // button3
            // 
            this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12.75F, System::Drawing::FontStyle::Bold));
            this->button3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
            this->button3->Location = System::Drawing::Point(51, 846);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(140, 35);
            this->button3->TabIndex = 12;
            this->button3->Text = L"Log in";
            this->button3->UseVisualStyleBackColor = false;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
            // 
            // MyForm
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
                static_cast<System::Int32>(static_cast<System::Byte>(48)));
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
            this->CausesValidation = false;
            this->ClientSize = System::Drawing::Size(1804, 1041);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->pictureBox4);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->checkBox1);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Name = L"MyForm";
            this->Text = L"Create account";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private:
        System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
        {
          
        }

        System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
        }
        System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        }
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        textBox1->PasswordChar = '*';
        textBox1->UseSystemPasswordChar = false;
    }
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (checkBox1->Checked) {
        button3->Enabled = true;
        button2->Enabled = true;
        button2->ForeColor = System::Drawing::Color::AntiqueWhite;
        button3->ForeColor = System::Drawing::Color::AntiqueWhite;
}
    else { button3->Enabled = false;
    button2->Enabled = false;
	

    }
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);

};
}