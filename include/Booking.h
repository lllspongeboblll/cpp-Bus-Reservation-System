#pragma once
#using <System.dll>
#include "QR.h"
namespace Project2 {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Booking
	/// </summary>
	public ref class Booking : public System::Windows::Forms::Form
	{

	private:
		List<String^>^ _selectedSeats;
		String^ _selectedBusLine;    // Declare at the top
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Button^ button5;
		   String^ _selectedBusType;    // Declare at the top
	private:
		double pricePerSeat = 10.0;  // Example base price
		double luxuryBusPrice = 20.0;
		double normalBusPrice = 15.0;
		double totalPrice = 0.0;



		// To track the total   // Total price
	private:
		void UpdateTotalPrice() {
			totalPrice = pricePerSeat * _selectedSeats->Count; // Assume numberOfSeats is another member variable
			// Add logic for bus type if applicable, e.g., totalPrice += luxuryBusPrice;
		}
		void CreateSeatButtons()
		{
			const int rows = 7;
			const int cols = 6;
			const int width = 40;
			const int height = 48;
			const int pad = 10;
			const int aisle = 30;
			const int offX = 180;
			const int offY = 4;

			System::Drawing::Image^ seatImg = System::Drawing::Image::FromFile("seat.png");

			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < cols; ++j)
				{
					System::Windows::Forms::Button^ btn = gcnew System::Windows::Forms::Button();
					btn->Size = System::Drawing::Size(width, height);
					int x = offX + j * (width + pad);
					if (j >= 3) x += aisle;
					int y = offY + i * (height + pad);
					btn->Location = System::Drawing::Point(x, y);
					btn->Image = seatImg;
					btn->ImageAlign = ContentAlignment::MiddleCenter;
					btn->Text = " " + (i * cols + j + 1);
					btn->ForeColor = System::Drawing::Color::White;
					btn->Font = gcnew System::Drawing::Font("Segoe UI", 8, FontStyle::Bold);
					btn->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
					btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
					btn->FlatAppearance->BorderSize = 0;
					btn->Click += gcnew System::EventHandler(this, &Booking::SeatButton_Click);
					this->panel1->Controls->Add(btn);
				}
			}
			this->panel1->AutoScroll = true;
		}

		void CreateSeatButtonsStandard()
		{
			const int rows = 7;
			const int cols = 4;
			const int width = 40;
			const int height = 45;
			const int pad = 10;
			const int aisle = 30;
			const int offX = 230;
			const int offY = 10;

			System::Drawing::Image^ seatImg = System::Drawing::Image::FromFile("chair1.png");

			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < cols; ++j)
				{
					System::Windows::Forms::Button^ btn = gcnew System::Windows::Forms::Button();
					btn->Size = System::Drawing::Size(width, height);
					int x = offX + j * (width + pad);
					if (j >= 2) x += aisle;
					int y = offY + i * (height + pad);
					btn->Location = System::Drawing::Point(x, y);
					btn->Image = seatImg;
					btn->ImageAlign = ContentAlignment::MiddleCenter;
					btn->Text = " " + (i * cols + j + 1);
					btn->ForeColor = System::Drawing::Color::White;
					btn->Font = gcnew System::Drawing::Font("Segoe UI", 8, FontStyle::Bold);
					btn->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
					btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
					btn->FlatAppearance->BorderSize = 0;
					btn->Click += gcnew System::EventHandler(this, &Booking::SeatButton_Click);
					this->panel5->Controls->Add(btn);
				}
			}
			this->panel5->AutoScroll = true;
		}

		void CreateSeatButtonsMini()
		{
			const int rows = 3;
			const int cols = 4;
			const int width = 40;
			const int height = 70;
			const int pad = 10;
			const int aisle = 30;
			const int offX = 250;
			const int offY = 40;

			System::Drawing::Image^ seatImg = System::Drawing::Image::FromFile("chairMini.png");

			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < cols; ++j)
				{
					System::Windows::Forms::Button^ btn = gcnew System::Windows::Forms::Button();
					btn->Size = System::Drawing::Size(width, height);
					int x = offX + j * (width + pad);
					if (j >= 3) x += aisle;
					int y = offY + i * (height + pad);
					btn->Location = System::Drawing::Point(x, y);
					btn->Image = seatImg;
					btn->ImageAlign = ContentAlignment::MiddleCenter;
					btn->Text = " " + (i * cols + j + 1);
					btn->ForeColor = System::Drawing::Color::White;
					btn->Font = gcnew System::Drawing::Font("Segoe UI", 8, FontStyle::Bold);
					btn->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
					btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
					btn->FlatAppearance->BorderSize = 0;
					btn->Click += gcnew System::EventHandler(this, &Booking::SeatButton_Click);
					this->panel7->Controls->Add(btn);
				}
			}
			this->panel7->AutoScroll = true;
		}

		// Click event handler for seat buttons
	private: System::Void SeatButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::Button^ button = dynamic_cast<System::Windows::Forms::Button^>(sender);
		if (button != nullptr)
		{
			String^ seatNumber = button->Text->Trim();  // Get seat number
			if (_selectedSeats->Contains(seatNumber))
			{
				// If seat is already selected, remove it (deselect)
				_selectedSeats->Remove(seatNumber);
				button->BackColor = System::Drawing::Color::Red;  // Indicate available
				MessageBox::Show("Seat " + seatNumber + " deselected.");
			}
			else
			{
				// If seat is not selected, add it
				_selectedSeats->Add(seatNumber);
				button->BackColor = System::Drawing::Color::Green;  // Indicate selection
				MessageBox::Show("You selected seat " + seatNumber);
			}
			UpdateTotalPrice();  // Recalculate total price
			// Update the price label based on the visible panel
			if (panel2->Visible) {
				label15->Text = "\"" + totalPrice.ToString("C") + "\"";  // Super Jet
			}
			else if (panel4->Visible) {
				label13->Text = "\"" + totalPrice.ToString("C") + "\"";  // Bus
			}
			else if (panel6->Visible) {
				label17->Text = "\"" + totalPrice.ToString("C") + "\"";  // Mini Bus
			}
		}
	}

	public:
		Booking(void)
		{
			InitializeComponent();
			CreateSeatButtons();
			CreateSeatButtonsStandard();
			CreateSeatButtonsMini();
			this->AutoScroll = true;
			_selectedBusLine = nullptr;  // Initialize to nullptr
			_selectedBusType = nullptr;  // Initialize to nullptr
			_selectedSeats = gcnew List<String^>();
		}

		~Booking()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label14;


	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::RadioButton^ radioButton2;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::RadioButton^ radioButton10;
	private: System::Windows::Forms::RadioButton^ radioButton9;
	private: System::Windows::Forms::RadioButton^ radioButton8;
	private: System::Windows::Forms::RadioButton^ radioButton7;
	private: System::Windows::Forms::RadioButton^ radioButton6;
	private: System::Windows::Forms::RadioButton^ radioButton5;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton11;
	private: System::Windows::Forms::PictureBox^ pictureBox7;

	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton12;
	private: System::Windows::Forms::RadioButton^ radioButton13;
	private: System::Windows::Forms::RadioButton^ radioButton14;
	private: System::Windows::Forms::RadioButton^ radioButton15;
	private: System::Windows::Forms::RadioButton^ radioButton16;
	private: System::Windows::Forms::RadioButton^ radioButton17;
	private: System::Windows::Forms::RadioButton^ radioButton18;
	private: System::Windows::Forms::RadioButton^ radioButton19;
	private: System::Windows::Forms::RadioButton^ radioButton20;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::PictureBox^ pictureBox9;

	private: System::Windows::Forms::PictureBox^ pictureBox11;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::PictureBox^ pictureBox13;
	private: System::Windows::Forms::PictureBox^ pictureBox12;
	private: System::Windows::Forms::Panel^ panel6;

	private: System::Windows::Forms::RadioButton^ radioButton21;
	private: System::Windows::Forms::RadioButton^ radioButton22;
	private: System::Windows::Forms::RadioButton^ radioButton23;
	private: System::Windows::Forms::RadioButton^ radioButton24;
	private: System::Windows::Forms::RadioButton^ radioButton25;
	private: System::Windows::Forms::RadioButton^ radioButton26;
	private: System::Windows::Forms::RadioButton^ radioButton27;
	private: System::Windows::Forms::RadioButton^ radioButton28;
	private: System::Windows::Forms::RadioButton^ radioButton29;
	private: System::Windows::Forms::RadioButton^ radioButton30;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::PictureBox^ pictureBox10;
	private: System::Windows::Forms::PictureBox^ pictureBox14;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::PictureBox^ pictureBox15;
	private: System::Windows::Forms::PictureBox^ pictureBox16;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;







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
			System::Windows::Forms::Button^ button7;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Booking::typeid));
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->radioButton11 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton12 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton13 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton14 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton15 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton16 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton17 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton18 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton19 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton20 = (gcnew System::Windows::Forms::RadioButton());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->radioButton21 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton22 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton23 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton24 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton25 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton26 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton27 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton28 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton29 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton30 = (gcnew System::Windows::Forms::RadioButton());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			button7 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->BeginInit();
			this->SuspendLayout();
			// 
			// button7
			// 
			button7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			button7->FlatAppearance->BorderSize = 0;
			button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			button7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.Image")));
			button7->Location = System::Drawing::Point(1718, 12);
			button7->Name = L"button7";
			button7->Size = System::Drawing::Size(74, 70);
			button7->TabIndex = 62;
			button7->UseVisualStyleBackColor = true;
			button7->Click += gcnew System::EventHandler(this, &Booking::button7_Click_1);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(-4, -1);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(1898, 400);
			this->pictureBox3->TabIndex = 44;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &Booking::pictureBox3_Click);
			// 
			// label14
			// 
			this->label14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30.75F, System::Drawing::FontStyle::Bold));
			this->label14->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label14->Location = System::Drawing::Point(230, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(372, 55);
			this->label14->TabIndex = 45;
			this->label14->Text = L"Pick Your Bus Type";
			this->label14->Click += gcnew System::EventHandler(this, &Booking::label14_Click_1);
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->button6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12.75F, System::Drawing::FontStyle::Bold));
			this->button6->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.Image")));
			this->button6->Location = System::Drawing::Point(19, 108);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(192, 89);
			this->button6->TabIndex = 49;
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Booking::button6_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12.75F, System::Drawing::FontStyle::Bold));
			this->button3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(286, 114);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(205, 89);
			this->button3->TabIndex = 50;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Booking::button3_Click);
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12.75F, System::Drawing::FontStyle::Bold));
			this->button4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->Location = System::Drawing::Point(580, 114);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(206, 89);
			this->button4->TabIndex = 51;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Booking::button4_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 15.75F));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(70, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 24);
			this->label1->TabIndex = 52;
			this->label1->Text = L"Mini Bus";
			this->label1->Click += gcnew System::EventHandler(this, &Booking::label1_Click);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 19.75F));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(358, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 30);
			this->label2->TabIndex = 53;
			this->label2->Text = L"Bus";
			this->label2->Click += gcnew System::EventHandler(this, &Booking::label2_Click);
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 16.75F));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(621, 86);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(139, 25);
			this->label3->TabIndex = 54;
			this->label3->Text = L"Super Jet";
			this->label3->Click += gcnew System::EventHandler(this, &Booking::label3_Click);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel2->Controls->Add(this->label15);
			this->panel2->Controls->Add(this->label16);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Controls->Add(this->pictureBox7);
			this->panel2->Controls->Add(this->radioButton11);
			this->panel2->Controls->Add(this->radioButton10);
			this->panel2->Controls->Add(this->radioButton9);
			this->panel2->Controls->Add(this->radioButton8);
			this->panel2->Controls->Add(this->radioButton7);
			this->panel2->Controls->Add(this->radioButton6);
			this->panel2->Controls->Add(this->radioButton5);
			this->panel2->Controls->Add(this->radioButton4);
			this->panel2->Controls->Add(this->radioButton3);
			this->panel2->Controls->Add(this->radioButton2);
			this->panel2->Controls->Add(this->panel1);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Location = System::Drawing::Point(-4, 648);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1886, 788);
			this->panel2->TabIndex = 56;
			this->panel2->Visible = false;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Booking::panel2_Paint);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30.75F, System::Drawing::FontStyle::Bold));
			this->label15->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label15->Location = System::Drawing::Point(849, 488);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(214, 55);
			this->label15->TabIndex = 66;
			this->label15->Text = L"\"              \"";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30.75F, System::Drawing::FontStyle::Bold));
			this->label16->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label16->Location = System::Drawing::Point(592, 485);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(237, 55);
			this->label16->TabIndex = 65;
			this->label16->Text = L"Your bill is :";
			// 
			// button1
			// 
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Cyan;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18.75F, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Location = System::Drawing::Point(1069, 485);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(227, 52);
			this->button1->TabIndex = 64;
			this->button1->Text = L"BOOK NOW!";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Booking::button2_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(1074, 3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(735, 396);
			this->pictureBox2->TabIndex = 48;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Booking::pictureBox2_Click);
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(211, 287);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(188, 106);
			this->pictureBox7->TabIndex = 52;
			this->pictureBox7->TabStop = false;
			// 
			// radioButton11
			// 
			this->radioButton11->AutoSize = true;
			this->radioButton11->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton11->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton11->Location = System::Drawing::Point(248, 161);
			this->radioButton11->Name = L"radioButton11";
			this->radioButton11->Size = System::Drawing::Size(82, 34);
			this->radioButton11->TabIndex = 51;
			this->radioButton11->TabStop = true;
			this->radioButton11->Text = L"8 AM";
			this->radioButton11->UseVisualStyleBackColor = true;
			this->radioButton11->CheckedChanged += gcnew System::EventHandler(this, &Booking::radioButton2_CheckedChanged);
			// 
			// radioButton10
			// 
			this->radioButton10->AutoSize = true;
			this->radioButton10->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton10->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton10->Location = System::Drawing::Point(160, 161);
			this->radioButton10->Name = L"radioButton10";
			this->radioButton10->Size = System::Drawing::Size(82, 34);
			this->radioButton10->TabIndex = 51;
			this->radioButton10->TabStop = true;
			this->radioButton10->Text = L"4 AM";
			this->radioButton10->UseVisualStyleBackColor = true;
			this->radioButton10->CheckedChanged += gcnew System::EventHandler(this, &Booking::radioButton2_CheckedChanged);
			// 
			// radioButton9
			// 
			this->radioButton9->AutoSize = true;
			this->radioButton9->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton9->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton9->Location = System::Drawing::Point(248, 121);
			this->radioButton9->Name = L"radioButton9";
			this->radioButton9->Size = System::Drawing::Size(88, 34);
			this->radioButton9->TabIndex = 51;
			this->radioButton9->TabStop = true;
			this->radioButton9->Text = L"10 PM";
			this->radioButton9->UseVisualStyleBackColor = true;
			this->radioButton9->CheckedChanged += gcnew System::EventHandler(this, &Booking::radioButton2_CheckedChanged);
			// 
			// radioButton8
			// 
			this->radioButton8->AutoSize = true;
			this->radioButton8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton8->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton8->Location = System::Drawing::Point(160, 121);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(80, 34);
			this->radioButton8->TabIndex = 51;
			this->radioButton8->TabStop = true;
			this->radioButton8->Text = L"8 PM";
			this->radioButton8->UseVisualStyleBackColor = true;
			this->radioButton8->CheckedChanged += gcnew System::EventHandler(this, &Booking::radioButton2_CheckedChanged);
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton7->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton7->Location = System::Drawing::Point(169, 121);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(82, 34);
			this->radioButton7->TabIndex = 51;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"4 AM";
			this->radioButton7->UseVisualStyleBackColor = true;
			this->radioButton7->CheckedChanged += gcnew System::EventHandler(this, &Booking::radioButton2_CheckedChanged);
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton6->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton6->Location = System::Drawing::Point(72, 121);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(80, 34);
			this->radioButton6->TabIndex = 51;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"6 PM";
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &Booking::radioButton2_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton5->Location = System::Drawing::Point(72, 161);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(90, 34);
			this->radioButton5->TabIndex = 51;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"12 AM";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &Booking::radioButton2_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton4->Location = System::Drawing::Point(248, 81);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(80, 34);
			this->radioButton4->TabIndex = 51;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"4 PM";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &Booking::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton3->Location = System::Drawing::Point(160, 81);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(80, 34);
			this->radioButton3->TabIndex = 51;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"2 PM";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Booking::radioButton2_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton2->Location = System::Drawing::Point(73, 81);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(88, 34);
			this->radioButton2->TabIndex = 51;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"12 PM";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Booking::radioButton2_CheckedChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel1->Controls->Add(this->pictureBox5);
			this->panel1->Controls->Add(this->pictureBox6);
			this->panel1->Controls->Add(this->pictureBox4);
			this->panel1->Location = System::Drawing::Point(412, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(662, 406);
			this->panel1->TabIndex = 49;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Booking::panel1_Paint);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(93, 3);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(42, 385);
			this->pictureBox5->TabIndex = 0;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(321, 6);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(40, 385);
			this->pictureBox6->TabIndex = 0;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(560, 3);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(24, 385);
			this->pictureBox4->TabIndex = 0;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(20, 287);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(188, 106);
			this->pictureBox1->TabIndex = 47;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Booking::pictureBox1_Click);
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20.75F, System::Drawing::FontStyle::Bold));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Location = System::Drawing::Point(31, 31);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(368, 38);
			this->label5->TabIndex = 46;
			this->label5->Text = L"Select your bus pickup time";
			this->label5->Click += gcnew System::EventHandler(this, &Booking::label4_Click);
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30.75F, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Location = System::Drawing::Point(16, 229);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(176, 55);
			this->label4->TabIndex = 46;
			this->label4->Text = L"Services";
			this->label4->Click += gcnew System::EventHandler(this, &Booking::label4_Click);
			// 
			// panel4
			// 
			this->panel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel4->Controls->Add(this->label13);
			this->panel4->Controls->Add(this->label12);
			this->panel4->Controls->Add(this->button2);
			this->panel4->Controls->Add(this->radioButton1);
			this->panel4->Controls->Add(this->radioButton12);
			this->panel4->Controls->Add(this->radioButton13);
			this->panel4->Controls->Add(this->radioButton14);
			this->panel4->Controls->Add(this->radioButton15);
			this->panel4->Controls->Add(this->radioButton16);
			this->panel4->Controls->Add(this->radioButton17);
			this->panel4->Controls->Add(this->radioButton18);
			this->panel4->Controls->Add(this->radioButton19);
			this->panel4->Controls->Add(this->radioButton20);
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Controls->Add(this->pictureBox12);
			this->panel4->Controls->Add(this->label6);
			this->panel4->Controls->Add(this->label7);
			this->panel4->Controls->Add(this->pictureBox13);
			this->panel4->Location = System::Drawing::Point(12, 651);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1886, 788);
			this->panel4->TabIndex = 57;
			this->panel4->Visible = false;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30.75F, System::Drawing::FontStyle::Bold));
			this->label13->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label13->Location = System::Drawing::Point(755, 472);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(214, 55);
			this->label13->TabIndex = 63;
			this->label13->Text = L"\"              \"";
			this->label13->Click += gcnew System::EventHandler(this, &Booking::label13_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30.75F, System::Drawing::FontStyle::Bold));
			this->label12->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label12->Location = System::Drawing::Point(498, 472);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(237, 55);
			this->label12->TabIndex = 62;
			this->label12->Text = L"Your bill is :";
			this->label12->Click += gcnew System::EventHandler(this, &Booking::label12_Click);
			// 
			// button2
			// 
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Cyan;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18.75F, System::Drawing::FontStyle::Bold));
			this->button2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button2->Location = System::Drawing::Point(1005, 472);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(227, 52);
			this->button2->TabIndex = 53;
			this->button2->Text = L"BOOK NOW!";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Booking::button2_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton1->Location = System::Drawing::Point(248, 161);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(82, 34);
			this->radioButton1->TabIndex = 51;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"8 AM";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton12
			// 
			this->radioButton12->AutoSize = true;
			this->radioButton12->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton12->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton12->Location = System::Drawing::Point(160, 161);
			this->radioButton12->Name = L"radioButton12";
			this->radioButton12->Size = System::Drawing::Size(82, 34);
			this->radioButton12->TabIndex = 51;
			this->radioButton12->TabStop = true;
			this->radioButton12->Text = L"4 AM";
			this->radioButton12->UseVisualStyleBackColor = true;
			// 
			// radioButton13
			// 
			this->radioButton13->AutoSize = true;
			this->radioButton13->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton13->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton13->Location = System::Drawing::Point(248, 121);
			this->radioButton13->Name = L"radioButton13";
			this->radioButton13->Size = System::Drawing::Size(88, 34);
			this->radioButton13->TabIndex = 51;
			this->radioButton13->TabStop = true;
			this->radioButton13->Text = L"10 PM";
			this->radioButton13->UseVisualStyleBackColor = true;
			// 
			// radioButton14
			// 
			this->radioButton14->AutoSize = true;
			this->radioButton14->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton14->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton14->Location = System::Drawing::Point(160, 121);
			this->radioButton14->Name = L"radioButton14";
			this->radioButton14->Size = System::Drawing::Size(80, 34);
			this->radioButton14->TabIndex = 51;
			this->radioButton14->TabStop = true;
			this->radioButton14->Text = L"8 PM";
			this->radioButton14->UseVisualStyleBackColor = true;
			// 
			// radioButton15
			// 
			this->radioButton15->AutoSize = true;
			this->radioButton15->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton15->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton15->Location = System::Drawing::Point(169, 121);
			this->radioButton15->Name = L"radioButton15";
			this->radioButton15->Size = System::Drawing::Size(82, 34);
			this->radioButton15->TabIndex = 51;
			this->radioButton15->TabStop = true;
			this->radioButton15->Text = L"4 AM";
			this->radioButton15->UseVisualStyleBackColor = true;
			// 
			// radioButton16
			// 
			this->radioButton16->AutoSize = true;
			this->radioButton16->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton16->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton16->Location = System::Drawing::Point(72, 121);
			this->radioButton16->Name = L"radioButton16";
			this->radioButton16->Size = System::Drawing::Size(80, 34);
			this->radioButton16->TabIndex = 51;
			this->radioButton16->TabStop = true;
			this->radioButton16->Text = L"6 PM";
			this->radioButton16->UseVisualStyleBackColor = true;
			// 
			// radioButton17
			// 
			this->radioButton17->AutoSize = true;
			this->radioButton17->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton17->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton17->Location = System::Drawing::Point(72, 161);
			this->radioButton17->Name = L"radioButton17";
			this->radioButton17->Size = System::Drawing::Size(90, 34);
			this->radioButton17->TabIndex = 51;
			this->radioButton17->TabStop = true;
			this->radioButton17->Text = L"12 AM";
			this->radioButton17->UseVisualStyleBackColor = true;
			// 
			// radioButton18
			// 
			this->radioButton18->AutoSize = true;
			this->radioButton18->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton18->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton18->Location = System::Drawing::Point(248, 81);
			this->radioButton18->Name = L"radioButton18";
			this->radioButton18->Size = System::Drawing::Size(80, 34);
			this->radioButton18->TabIndex = 51;
			this->radioButton18->TabStop = true;
			this->radioButton18->Text = L"4 PM";
			this->radioButton18->UseVisualStyleBackColor = true;
			// 
			// radioButton19
			// 
			this->radioButton19->AutoSize = true;
			this->radioButton19->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton19->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton19->Location = System::Drawing::Point(160, 81);
			this->radioButton19->Name = L"radioButton19";
			this->radioButton19->Size = System::Drawing::Size(80, 34);
			this->radioButton19->TabIndex = 51;
			this->radioButton19->TabStop = true;
			this->radioButton19->Text = L"2 PM";
			this->radioButton19->UseVisualStyleBackColor = true;
			// 
			// radioButton20
			// 
			this->radioButton20->AutoSize = true;
			this->radioButton20->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton20->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton20->Location = System::Drawing::Point(73, 81);
			this->radioButton20->Name = L"radioButton20";
			this->radioButton20->Size = System::Drawing::Size(88, 34);
			this->radioButton20->TabIndex = 51;
			this->radioButton20->TabStop = true;
			this->radioButton20->Text = L"12 PM";
			this->radioButton20->UseVisualStyleBackColor = true;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel5->Controls->Add(this->pictureBox9);
			this->panel5->Controls->Add(this->pictureBox11);
			this->panel5->Location = System::Drawing::Point(412, 4);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(662, 394);
			this->panel5->TabIndex = 49;
			this->panel5->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Booking::panel5_Paint);
			// 
			// pictureBox9
			// 
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(93, 3);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(42, 385);
			this->pictureBox9->TabIndex = 0;
			this->pictureBox9->TabStop = false;
			// 
			// pictureBox11
			// 
			this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.Image")));
			this->pictureBox11->Location = System::Drawing::Point(560, 3);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(24, 385);
			this->pictureBox11->TabIndex = 0;
			this->pictureBox11->TabStop = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.Image")));
			this->pictureBox12->Location = System::Drawing::Point(26, 287);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(376, 106);
			this->pictureBox12->TabIndex = 47;
			this->pictureBox12->TabStop = false;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20.75F, System::Drawing::FontStyle::Bold));
			this->label6->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label6->Location = System::Drawing::Point(31, 31);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(368, 38);
			this->label6->TabIndex = 46;
			this->label6->Text = L"Select your bus pickup time";
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30.75F, System::Drawing::FontStyle::Bold));
			this->label7->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label7->Location = System::Drawing::Point(16, 229);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(176, 55);
			this->label7->TabIndex = 46;
			this->label7->Text = L"Services";
			// 
			// pictureBox13
			// 
			this->pictureBox13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->pictureBox13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox13.Image")));
			this->pictureBox13->Location = System::Drawing::Point(1077, 6);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(735, 396);
			this->pictureBox13->TabIndex = 48;
			this->pictureBox13->TabStop = false;
			this->pictureBox13->Click += gcnew System::EventHandler(this, &Booking::pictureBox13_Click);
			// 
			// panel3
			// 
			this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel3->Controls->Add(this->label1);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->button4);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->button6);
			this->panel3->Controls->Add(this->button3);
			this->panel3->Controls->Add(this->label14);
			this->panel3->Location = System::Drawing::Point(501, 405);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(863, 240);
			this->panel3->TabIndex = 57;
			this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Booking::panel3_Paint);
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel6->Controls->Add(this->label17);
			this->panel6->Controls->Add(this->label18);
			this->panel6->Controls->Add(this->button5);
			this->panel6->Controls->Add(this->radioButton21);
			this->panel6->Controls->Add(this->radioButton22);
			this->panel6->Controls->Add(this->radioButton23);
			this->panel6->Controls->Add(this->radioButton24);
			this->panel6->Controls->Add(this->radioButton25);
			this->panel6->Controls->Add(this->radioButton26);
			this->panel6->Controls->Add(this->radioButton27);
			this->panel6->Controls->Add(this->radioButton28);
			this->panel6->Controls->Add(this->radioButton29);
			this->panel6->Controls->Add(this->radioButton30);
			this->panel6->Controls->Add(this->panel7);
			this->panel6->Controls->Add(this->pictureBox14);
			this->panel6->Controls->Add(this->label8);
			this->panel6->Controls->Add(this->label9);
			this->panel6->Controls->Add(this->pictureBox15);
			this->panel6->Location = System::Drawing::Point(15, 651);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(1886, 788);
			this->panel6->TabIndex = 58;
			this->panel6->Visible = false;
			this->panel6->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Booking::panel6_Paint);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30.75F, System::Drawing::FontStyle::Bold));
			this->label17->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label17->Location = System::Drawing::Point(846, 486);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(214, 55);
			this->label17->TabIndex = 69;
			this->label17->Text = L"\"              \"";
			this->label17->Click += gcnew System::EventHandler(this, &Booking::label17_Click);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30.75F, System::Drawing::FontStyle::Bold));
			this->label18->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label18->Location = System::Drawing::Point(594, 482);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(237, 55);
			this->label18->TabIndex = 68;
			this->label18->Text = L"Your bill is :";
			// 
			// button5
			// 
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::Cyan;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18.75F, System::Drawing::FontStyle::Bold));
			this->button5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button5->Location = System::Drawing::Point(1077, 479);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(218, 55);
			this->button5->TabIndex = 67;
			this->button5->Text = L"BOOK NOW!";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Booking::button2_Click);
			// 
			// radioButton21
			// 
			this->radioButton21->AutoSize = true;
			this->radioButton21->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton21->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton21->Location = System::Drawing::Point(248, 161);
			this->radioButton21->Name = L"radioButton21";
			this->radioButton21->Size = System::Drawing::Size(82, 34);
			this->radioButton21->TabIndex = 51;
			this->radioButton21->TabStop = true;
			this->radioButton21->Text = L"8 AM";
			this->radioButton21->UseVisualStyleBackColor = true;
			// 
			// radioButton22
			// 
			this->radioButton22->AutoSize = true;
			this->radioButton22->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton22->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton22->Location = System::Drawing::Point(160, 161);
			this->radioButton22->Name = L"radioButton22";
			this->radioButton22->Size = System::Drawing::Size(82, 34);
			this->radioButton22->TabIndex = 51;
			this->radioButton22->TabStop = true;
			this->radioButton22->Text = L"4 AM";
			this->radioButton22->UseVisualStyleBackColor = true;
			// 
			// radioButton23
			// 
			this->radioButton23->AutoSize = true;
			this->radioButton23->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton23->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton23->Location = System::Drawing::Point(248, 121);
			this->radioButton23->Name = L"radioButton23";
			this->radioButton23->Size = System::Drawing::Size(88, 34);
			this->radioButton23->TabIndex = 51;
			this->radioButton23->TabStop = true;
			this->radioButton23->Text = L"10 PM";
			this->radioButton23->UseVisualStyleBackColor = true;
			// 
			// radioButton24
			// 
			this->radioButton24->AutoSize = true;
			this->radioButton24->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton24->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton24->Location = System::Drawing::Point(160, 121);
			this->radioButton24->Name = L"radioButton24";
			this->radioButton24->Size = System::Drawing::Size(80, 34);
			this->radioButton24->TabIndex = 51;
			this->radioButton24->TabStop = true;
			this->radioButton24->Text = L"8 PM";
			this->radioButton24->UseVisualStyleBackColor = true;
			// 
			// radioButton25
			// 
			this->radioButton25->AutoSize = true;
			this->radioButton25->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton25->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton25->Location = System::Drawing::Point(169, 121);
			this->radioButton25->Name = L"radioButton25";
			this->radioButton25->Size = System::Drawing::Size(82, 34);
			this->radioButton25->TabIndex = 51;
			this->radioButton25->TabStop = true;
			this->radioButton25->Text = L"4 AM";
			this->radioButton25->UseVisualStyleBackColor = true;
			// 
			// radioButton26
			// 
			this->radioButton26->AutoSize = true;
			this->radioButton26->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton26->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton26->Location = System::Drawing::Point(72, 121);
			this->radioButton26->Name = L"radioButton26";
			this->radioButton26->Size = System::Drawing::Size(80, 34);
			this->radioButton26->TabIndex = 51;
			this->radioButton26->TabStop = true;
			this->radioButton26->Text = L"6 PM";
			this->radioButton26->UseVisualStyleBackColor = true;
			// 
			// radioButton27
			// 
			this->radioButton27->AutoSize = true;
			this->radioButton27->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton27->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton27->Location = System::Drawing::Point(72, 161);
			this->radioButton27->Name = L"radioButton27";
			this->radioButton27->Size = System::Drawing::Size(90, 34);
			this->radioButton27->TabIndex = 51;
			this->radioButton27->TabStop = true;
			this->radioButton27->Text = L"12 AM";
			this->radioButton27->UseVisualStyleBackColor = true;
			// 
			// radioButton28
			// 
			this->radioButton28->AutoSize = true;
			this->radioButton28->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton28->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton28->Location = System::Drawing::Point(248, 81);
			this->radioButton28->Name = L"radioButton28";
			this->radioButton28->Size = System::Drawing::Size(80, 34);
			this->radioButton28->TabIndex = 51;
			this->radioButton28->TabStop = true;
			this->radioButton28->Text = L"4 PM";
			this->radioButton28->UseVisualStyleBackColor = true;
			// 
			// radioButton29
			// 
			this->radioButton29->AutoSize = true;
			this->radioButton29->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton29->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton29->Location = System::Drawing::Point(160, 81);
			this->radioButton29->Name = L"radioButton29";
			this->radioButton29->Size = System::Drawing::Size(80, 34);
			this->radioButton29->TabIndex = 51;
			this->radioButton29->TabStop = true;
			this->radioButton29->Text = L"2 PM";
			this->radioButton29->UseVisualStyleBackColor = true;
			// 
			// radioButton30
			// 
			this->radioButton30->AutoSize = true;
			this->radioButton30->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold));
			this->radioButton30->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioButton30->Location = System::Drawing::Point(73, 81);
			this->radioButton30->Name = L"radioButton30";
			this->radioButton30->Size = System::Drawing::Size(88, 34);
			this->radioButton30->TabIndex = 51;
			this->radioButton30->TabStop = true;
			this->radioButton30->Text = L"12 PM";
			this->radioButton30->UseVisualStyleBackColor = true;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel7->Controls->Add(this->pictureBox8);
			this->panel7->Controls->Add(this->pictureBox10);
			this->panel7->Location = System::Drawing::Point(412, 4);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(662, 394);
			this->panel7->TabIndex = 49;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(93, 3);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(42, 385);
			this->pictureBox8->TabIndex = 0;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(560, 3);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(24, 385);
			this->pictureBox10->TabIndex = 0;
			this->pictureBox10->TabStop = false;
			// 
			// pictureBox14
			// 
			this->pictureBox14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->pictureBox14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox14.Image")));
			this->pictureBox14->Location = System::Drawing::Point(20, 287);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(376, 106);
			this->pictureBox14->TabIndex = 47;
			this->pictureBox14->TabStop = false;
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20.75F, System::Drawing::FontStyle::Bold));
			this->label8->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label8->Location = System::Drawing::Point(31, 31);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(368, 38);
			this->label8->TabIndex = 46;
			this->label8->Text = L"Select your bus pickup time";
			// 
			// label9
			// 
			this->label9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30.75F, System::Drawing::FontStyle::Bold));
			this->label9->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label9->Location = System::Drawing::Point(16, 229);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(176, 55);
			this->label9->TabIndex = 46;
			this->label9->Text = L"Services";
			// 
			// pictureBox15
			// 
			this->pictureBox15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->pictureBox15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox15.Image")));
			this->pictureBox15->Location = System::Drawing::Point(1077, 6);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(735, 396);
			this->pictureBox15->TabIndex = 48;
			this->pictureBox15->TabStop = false;
			// 
			// pictureBox16
			// 
			this->pictureBox16->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox16.BackgroundImage")));
			this->pictureBox16->Location = System::Drawing::Point(-82, 405);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(1909, 237);
			this->pictureBox16->TabIndex = 59;
			this->pictureBox16->TabStop = false;
			this->pictureBox16->Click += gcnew System::EventHandler(this, &Booking::pictureBox16_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30.75F, System::Drawing::FontStyle::Bold));
			this->label10->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label10->Location = System::Drawing::Point(77, 442);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(154, 55);
			this->label10->TabIndex = 60;
			this->label10->Text = L"label10";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30.75F, System::Drawing::FontStyle::Bold));
			this->label11->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label11->Location = System::Drawing::Point(1607, 486);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(148, 55);
			this->label11->TabIndex = 61;
			this->label11->Text = L"label11";
			// 
			// Booking
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->ClientSize = System::Drawing::Size(1804, 1061);
			this->Controls->Add(button7);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->pictureBox16);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel2);
			this->Name = L"Booking";
			this->Load += gcnew System::EventHandler(this, &Booking::Booking_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private:
		void LoadAndDisplayRoute()
		{
			try
			{
				String^ filePath = "database_el5laba.csv";

				if (File::Exists(filePath))
				{
					array<String^>^ allLines = File::ReadAllLines(filePath);

					if (allLines->Length > 1) // Skip header line
					{
						// Get last route (most recent)
						String^ lastRoute = allLines[allLines->Length - 1];

						// Split exactly on " / " 
						array<String^>^ parts = lastRoute->Split(
							gcnew array<String^>{" / "}, StringSplitOptions::None);

						if (parts->Length == 2)
						{
							label10->Text = parts[0]->Trim();  // Before " / "
							label11->Text = parts[1]->Trim();  // After " / "
							_selectedBusLine = label10->Text + " / " + label11->Text;
						}
					}
				}
			}
			catch (Exception^ ex)
			{
				label10->Text = "Error";
				label11->Text = ex->Message;
			}
		}
#pragma endregion
	private:
	private: System::Void label14_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label14_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		panel2->Visible = true;
		panel4->Visible = false;
		panel6->Visible = false;
		_selectedBusType = "Super jet";
		pricePerSeat = luxuryBusPrice;
		_selectedSeats->Clear();           // Clear previous selections
		totalPrice = 0.0;                  // Reset total price
		label15->Text = "\"0.00\"";
		// Update Super Jet panel's price label
		for each (Control ^ ctrl in panel1->Controls) {
			if (dynamic_cast<Button^>(ctrl) != nullptr)
				ctrl->BackColor = System::Drawing::Color::Transparent;
		}
		for each (Control ^ ctrl in panel5->Controls) {
			if (dynamic_cast<Button^>(ctrl) != nullptr)
				ctrl->BackColor = System::Drawing::Color::Transparent;
		}
		for each (Control ^ ctrl in panel7->Controls) {
			if (dynamic_cast<Button^>(ctrl) != nullptr)
				ctrl->BackColor = System::Drawing::Color::Transparent;
		}
		for each (Control ^ ctrl in panel2->Controls) {
			if (dynamic_cast<RadioButton^>(ctrl) != nullptr)
				(dynamic_cast<RadioButton^>(ctrl))->Checked = false;
		}

	}
	private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
		pricePerSeat = luxuryBusPrice; // Set price for luxury bus
		UpdateTotalPrice();
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		panel2->Visible = false;
		panel4->Visible = false;
		panel6->Visible = true;
		_selectedBusType = "Mini bus";
		pricePerSeat = 10.0;
		_selectedSeats->Clear();           // Clear previous selections
		totalPrice = 0.0;                  // Reset total price
		label17->Text = "\"0.00\"";
		for each (Control ^ ctrl in panel1->Controls) {
			if (dynamic_cast<Button^>(ctrl) != nullptr)
				ctrl->BackColor = System::Drawing::Color::Transparent;
		}
		for each (Control ^ ctrl in panel5->Controls) {
			if (dynamic_cast<Button^>(ctrl) != nullptr)
				ctrl->BackColor = System::Drawing::Color::Transparent;
		}
		for each (Control ^ ctrl in panel7->Controls) {
			if (dynamic_cast<Button^>(ctrl) != nullptr)
				ctrl->BackColor = System::Drawing::Color::Transparent;
		}
		for each (Control ^ ctrl in panel6->Controls) {
			if (dynamic_cast<RadioButton^>(ctrl) != nullptr)
				(dynamic_cast<RadioButton^>(ctrl))->Checked = false;
		}
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Booking_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadAndDisplayRoute();

	}
	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox13_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel5_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		panel2->Visible = false;
		panel4->Visible = true;
		panel6->Visible = false;
		_selectedBusType = "Bus";
		pricePerSeat = normalBusPrice;
		_selectedSeats->Clear();           // Clear previous selections
		totalPrice = 0.0;                  // Reset total price
		label13->Text = "\"0.00\"";
		for each (Control ^ ctrl in panel1->Controls) {
			if (dynamic_cast<Button^>(ctrl) != nullptr)
				ctrl->BackColor = System::Drawing::Color::Transparent;
		}
		for each (Control ^ ctrl in panel5->Controls) {
			if (dynamic_cast<Button^>(ctrl) != nullptr)
				ctrl->BackColor = System::Drawing::Color::Transparent;
		}
		for each (Control ^ ctrl in panel7->Controls) {
			if (dynamic_cast<Button^>(ctrl) != nullptr)
				ctrl->BackColor = System::Drawing::Color::Transparent;
		}
		for each (Control ^ ctrl in panel4->Controls) {
			if (dynamic_cast<RadioButton^>(ctrl) != nullptr)
				(dynamic_cast<RadioButton^>(ctrl))->Checked = false;
		}
	}
	private: System::Void panel6_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void pictureBox16_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label13_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (String::IsNullOrEmpty(_selectedBusLine))
		{
			MessageBox::Show("Bus line information is missing. Please restart the booking process.", "Error");
			return;
		}

		String^ selectedTime = nullptr;
		if (radioButton20->Checked) selectedTime = radioButton20->Text; // 12 PM
		else if (radioButton19->Checked) selectedTime = radioButton19->Text; // 2 PM
		else if (radioButton18->Checked) selectedTime = radioButton18->Text; // 4 PM
		else if (radioButton16->Checked) selectedTime = radioButton16->Text; // 6 PM
		else if (radioButton14->Checked) selectedTime = radioButton14->Text; // 8 PM
		else if (radioButton13->Checked) selectedTime = radioButton13->Text; // 10 PM
		else if (radioButton17->Checked) selectedTime = radioButton17->Text; // 12 AM
		else if (radioButton12->Checked) selectedTime = radioButton12->Text; // 4 AM
		else if (radioButton1->Checked) selectedTime = radioButton1->Text;   // 8 AM

		if (String::IsNullOrEmpty(_selectedBusType) || String::IsNullOrEmpty(selectedTime))
		{
			MessageBox::Show("Please select a bus type and time.", "Selection Required");
			return;
		}

		if (_selectedSeats->Count == 0)
		{
			MessageBox::Show("Please select at least one seat.", "Selection Required");
			return;
		}

		try
		{
			String^ filePath = "Trips.csv";
			StreamWriter^ sw = gcnew StreamWriter(filePath, true);

			if (sw->BaseStream->Length == 0)
			{
				sw->WriteLine("Bus_Line,Bus_type,Time,Seats,price");
			}

			String^ seats = String::Join(";", _selectedSeats->ToArray());
			UpdateTotalPrice();
			sw->WriteLine(String::Format("{0},{1},{2},{3},{4}", _selectedBusLine, _selectedBusType, selectedTime, seats, totalPrice.ToString("F2")));
			sw->Close();

			// QR.txt
			String^ qrFilePath = "Qr.txt";
			StreamWriter^ qrSw = gcnew StreamWriter(qrFilePath);
			qrSw->WriteLine("Bus_line: " + _selectedBusLine);
			qrSw->WriteLine("Bus_type: " + _selectedBusType);
			qrSw->WriteLine("Time: " + selectedTime);
			qrSw->WriteLine("Seats: " + seats);
			qrSw->WriteLine("price: " + totalPrice.ToString("F2"));
			qrSw->WriteLine("(: bn7nbk ya Dr.shaf3y 3> "); // to txt file
			qrSw->Close();

			MessageBox::Show("Booking confirmed! Seats: " + seats + ", Total Price: " + totalPrice.ToString("C"), "Success");

			_selectedSeats->Clear();
			for each(Control ^ ctrl in panel1->Controls)
			{
				if (dynamic_cast<Button^>(ctrl) != nullptr)
					ctrl->BackColor = System::Drawing::Color::Transparent;
			}
			for each(Control ^ ctrl in panel5->Controls)
			{
				if (dynamic_cast<Button^>(ctrl) != nullptr)
					ctrl->BackColor = System::Drawing::Color::Transparent;
			}
			for each(Control ^ ctrl in panel7->Controls)
			{
				if (dynamic_cast<Button^>(ctrl) != nullptr)
					ctrl->BackColor = System::Drawing::Color::Transparent;
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error while saving booking: " + ex->Message, "Error");
		}
		Project2::QR^ loginForm = gcnew Project2::QR(); //replace my form with the name of the form you want to open
		loginForm->Show();
		 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////QR window ///////////////////////////////////////////////////////////////////////////////
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		UpdateTotalPrice();
		label17->Text = "\"" + totalPrice.ToString("C") + "\"";
		label15->Text = "\"" + totalPrice.ToString("C") + "\"";
		label13->Text = "\"" + totalPrice.ToString("C") + "\"";
	

	}
	private: System::Void label17_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button7_Click_1(System::Object^ sender, System::EventArgs^ e);

	};
}
