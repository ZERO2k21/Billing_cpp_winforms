#pragma once

namespace MyApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            // Set the background image here
            this->BackgroundImage = Image::FromFile("bg.jpeg");
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        String^ customerName;
        String^ phoneNumber;
        String^ address;

    private: System::ComponentModel::Container^ components;
    private: System::Windows::Forms::TextBox^ itemTextBox;
    private: System::Windows::Forms::TextBox^ priceTextBox;
    private: System::Windows::Forms::Label^ itemLabel;
    private: System::Windows::Forms::Label^ priceLabel;
    private: System::Windows::Forms::Label^ nameLabel;
    private: System::Windows::Forms::TextBox^ nameTextBox;
    private: System::Windows::Forms::Label^ phoneLabel;
    private: System::Windows::Forms::TextBox^ phoneTextBox;
    private: System::Windows::Forms::Label^ addressLabel;
    private: System::Windows::Forms::TextBox^ addressTextBox;
    private: System::Windows::Forms::Button^ addButton;
    private: System::Windows::Forms::Button^ printButton;
    private: System::Windows::Forms::Label^ invoiceLabel;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ totalAmountLabel; // Add this line to declare the totalAmountLabel control
    private: System::Windows::Forms::Button^ calculateButton;

    private: double totalAmount = 0.0;





    private: System::Windows::Forms::Label^ invoiceTextLabel;

           void InitializeComponent(void)
           {
               this->calculateButton = (gcnew System::Windows::Forms::Button());
               this->itemTextBox = (gcnew System::Windows::Forms::TextBox());
               this->priceTextBox = (gcnew System::Windows::Forms::TextBox());
               this->itemLabel = (gcnew System::Windows::Forms::Label());
               this->priceLabel = (gcnew System::Windows::Forms::Label());
               this->nameLabel = (gcnew System::Windows::Forms::Label());
               this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
               this->phoneLabel = (gcnew System::Windows::Forms::Label());
               this->phoneTextBox = (gcnew System::Windows::Forms::TextBox());
               this->addressLabel = (gcnew System::Windows::Forms::Label());
               this->addressTextBox = (gcnew System::Windows::Forms::TextBox());
               this->addButton = (gcnew System::Windows::Forms::Button());
               this->printButton = (gcnew System::Windows::Forms::Button());
               this->invoiceLabel = (gcnew System::Windows::Forms::Label());
               this->invoiceTextLabel = (gcnew System::Windows::Forms::Label());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->SuspendLayout();
               // 
               // calculateButton
               // 
               this->calculateButton->AutoSize = true;
               this->calculateButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                   static_cast<System::Int32>(static_cast<System::Byte>(0)));
               this->calculateButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
               this->calculateButton->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
               this->calculateButton->Location = System::Drawing::Point(161, 823);
               this->calculateButton->Name = L"calculateButton";
               this->calculateButton->Size = System::Drawing::Size(245, 49);
               this->calculateButton->TabIndex = 12;
               this->calculateButton->Text = L"Calculate Total";
               this->calculateButton->UseVisualStyleBackColor = false;
               this->calculateButton->Click += gcnew System::EventHandler(this, &MyForm::calculateButton_Click);
               // 
               // itemTextBox
               // 
               this->itemTextBox->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->itemTextBox->Location = System::Drawing::Point(161, 252);
               this->itemTextBox->Name = L"itemTextBox";
               this->itemTextBox->Size = System::Drawing::Size(292, 31);
               this->itemTextBox->TabIndex = 0;
               this->itemTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::itemTextBox_TextChanged);
               // 
               // priceTextBox
               // 
               this->priceTextBox->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
               this->priceTextBox->Location = System::Drawing::Point(161, 307);
               this->priceTextBox->Name = L"priceTextBox";
               this->priceTextBox->Size = System::Drawing::Size(292, 31);
               this->priceTextBox->TabIndex = 1;
               // 
               // itemLabel
               // 
               this->itemLabel->AutoSize = true;
               this->itemLabel->BackColor = System::Drawing::Color::Transparent;
               this->itemLabel->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->itemLabel->ForeColor = System::Drawing::Color::White;
               this->itemLabel->Location = System::Drawing::Point(12, 245);
               this->itemLabel->Name = L"itemLabel";
               this->itemLabel->Size = System::Drawing::Size(94, 38);
               this->itemLabel->TabIndex = 2;
               this->itemLabel->Text = L"Item:";
               // 
               // priceLabel
               // 
               this->priceLabel->AutoSize = true;
               this->priceLabel->BackColor = System::Drawing::Color::Transparent;
               this->priceLabel->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->priceLabel->ForeColor = System::Drawing::Color::White;
               this->priceLabel->Location = System::Drawing::Point(12, 303);
               this->priceLabel->Name = L"priceLabel";
               this->priceLabel->Size = System::Drawing::Size(106, 38);
               this->priceLabel->TabIndex = 3;
               this->priceLabel->Text = L"Price:";
               this->priceLabel->Click += gcnew System::EventHandler(this, &MyForm::priceLabel_Click);
               // 
               // nameLabel
               // 
               this->nameLabel->AutoSize = true;
               this->nameLabel->BackColor = System::Drawing::Color::Transparent;
               this->nameLabel->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->nameLabel->ForeColor = System::Drawing::Color::White;
               this->nameLabel->Location = System::Drawing::Point(12, 356);
               this->nameLabel->Name = L"nameLabel";
               this->nameLabel->Size = System::Drawing::Size(111, 38);
               this->nameLabel->TabIndex = 4;
               this->nameLabel->Text = L"Name:";
               // 
               // nameTextBox
               // 
               this->nameTextBox->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->nameTextBox->Location = System::Drawing::Point(161, 360);
               this->nameTextBox->Name = L"nameTextBox";
               this->nameTextBox->Size = System::Drawing::Size(292, 31);
               this->nameTextBox->TabIndex = 8;
               // 
               // phoneLabel
               // 
               this->phoneLabel->AutoSize = true;
               this->phoneLabel->BackColor = System::Drawing::Color::Transparent;
               this->phoneLabel->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->phoneLabel->ForeColor = System::Drawing::Color::White;
               this->phoneLabel->Location = System::Drawing::Point(12, 409);
               this->phoneLabel->Name = L"phoneLabel";
               this->phoneLabel->Size = System::Drawing::Size(122, 38);
               this->phoneLabel->TabIndex = 5;
               this->phoneLabel->Text = L"Phone:";
               // 
               // phoneTextBox
               // 
               this->phoneTextBox->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
               this->phoneTextBox->Location = System::Drawing::Point(161, 413);
               this->phoneTextBox->Name = L"phoneTextBox";
               this->phoneTextBox->Size = System::Drawing::Size(292, 31);
               this->phoneTextBox->TabIndex = 9;
               // 
               // addressLabel
               // 
               this->addressLabel->AutoSize = true;
               this->addressLabel->BackColor = System::Drawing::Color::Transparent;
               this->addressLabel->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->addressLabel->ForeColor = System::Drawing::Color::White;
               this->addressLabel->Location = System::Drawing::Point(12, 462);
               this->addressLabel->Name = L"addressLabel";
               this->addressLabel->Size = System::Drawing::Size(143, 38);
               this->addressLabel->TabIndex = 6;
               this->addressLabel->Text = L"Address:";
               // 
               // addressTextBox
               // 
               this->addressTextBox->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
               this->addressTextBox->Location = System::Drawing::Point(161, 466);
               this->addressTextBox->Multiline = true;
               this->addressTextBox->Name = L"addressTextBox";
               this->addressTextBox->Size = System::Drawing::Size(292, 264);
               this->addressTextBox->TabIndex = 10;
               // 
               // addButton
               // 
               this->addButton->AutoSize = true;
               this->addButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                   static_cast<System::Int32>(static_cast<System::Byte>(0)));
               this->addButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
               this->addButton->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
               this->addButton->Location = System::Drawing::Point(161, 762);
               this->addButton->Name = L"addButton";
               this->addButton->Size = System::Drawing::Size(139, 49);
               this->addButton->TabIndex = 4;
               this->addButton->Text = L"Add";
               this->addButton->UseVisualStyleBackColor = false;
               this->addButton->Click += gcnew System::EventHandler(this, &MyForm::addButton_Click);
               // 
               // printButton
               // 
               this->printButton->AutoSize = true;
               this->printButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                   static_cast<System::Int32>(static_cast<System::Byte>(0)));
               this->printButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
               this->printButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
               this->printButton->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
               this->printButton->Location = System::Drawing::Point(281, 762);
               this->printButton->Name = L"printButton";
               this->printButton->Size = System::Drawing::Size(125, 49);
               this->printButton->TabIndex = 5;
               this->printButton->Text = L"Print";
               this->printButton->UseVisualStyleBackColor = false;
               this->printButton->Click += gcnew System::EventHandler(this, &MyForm::printButton_Click);
               // 
               // invoiceLabel
               // 
               this->invoiceLabel->AllowDrop = true;
               this->invoiceLabel->AutoEllipsis = true;
               this->invoiceLabel->BackColor = System::Drawing::SystemColors::Window;
               this->invoiceLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->invoiceLabel->ForeColor = System::Drawing::Color::Black;
               this->invoiceLabel->Location = System::Drawing::Point(727, 235);
               this->invoiceLabel->Name = L"invoiceLabel";
               this->invoiceLabel->Size = System::Drawing::Size(799, 622);
               this->invoiceLabel->TabIndex = 6;
               // 
               // invoiceTextLabel
               // 
               this->invoiceTextLabel->AutoSize = true;
               this->invoiceTextLabel->BackColor = System::Drawing::Color::Transparent;
               this->invoiceTextLabel->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->invoiceTextLabel->ForeColor = System::Drawing::Color::White;
               this->invoiceTextLabel->Location = System::Drawing::Point(721, 192);
               this->invoiceTextLabel->Name = L"invoiceTextLabel";
               this->invoiceTextLabel->Size = System::Drawing::Size(118, 32);
               this->invoiceTextLabel->TabIndex = 7;
               this->invoiceTextLabel->Text = L"Invoice:";
               this->invoiceTextLabel->Click += gcnew System::EventHandler(this, &MyForm::invoiceTextLabel_Click);
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->BackColor = System::Drawing::Color::Transparent;
               this->label1->Font = (gcnew System::Drawing::Font(L"Snap ITC", 36, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
               this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
               this->label1->Location = System::Drawing::Point(701, 87);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(447, 63);
               this->label1->TabIndex = 11;
               this->label1->Text = L"INVOICERPRO";
               this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
               // 
               // MyForm
               // 
               this->AcceptButton = this->addButton;
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
               this->AutoScroll = true;
               this->AutoSize = true;
               this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
               this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
               this->BackColor = System::Drawing::Color::Black;
               this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
               this->ClientSize = System::Drawing::Size(1924, 1061);
               this->Controls->Add(this->label1);
               this->Controls->Add(this->invoiceTextLabel);
               this->Controls->Add(this->invoiceLabel);
               this->Controls->Add(this->printButton);
               this->Controls->Add(this->addButton);
               this->Controls->Add(this->priceLabel);
               this->Controls->Add(this->itemLabel);
               this->Controls->Add(this->phoneLabel);
               this->Controls->Add(this->addressLabel);
               this->Controls->Add(this->nameLabel);
               this->Controls->Add(this->priceTextBox);
               this->Controls->Add(this->itemTextBox);
               this->Controls->Add(this->phoneTextBox);
               this->Controls->Add(this->addressTextBox);
               this->Controls->Add(this->nameTextBox);
               this->Controls->Add(this->calculateButton);
               this->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->MinimumSize = System::Drawing::Size(600, 0);
               this->Name = L"MyForm";
               this->Text = L"Invoice App";
               this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
               this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
               this->ResumeLayout(false);
               this->PerformLayout();

           }


           // ... (Previous code remains unchanged)

private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Get the entered item and price
    String^ item = itemTextBox->Text;
    String^ price = priceTextBox->Text;

    // Ensure both item and price are provided
    if (item->Trim() == "" || price->Trim() == "")
    {
        MessageBox::Show("Please enter both item and price.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Convert the price to a double value
    double itemPrice = 0.0;
    if (!Double::TryParse(price, itemPrice) || itemPrice <= 0)
    {
        MessageBox::Show("Please enter a valid price.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Update the invoice label with the new item and price
    invoiceLabel->Text += item + L" - ₹" + price + L"\r\n";

    // Add the item price to the total amount
    totalAmount += itemPrice;


    // Clear the text boxes for the next entry
    itemTextBox->Clear();
    priceTextBox->Clear();
}
       private: System::Void calculateButton_Click(System::Object^ sender, System::EventArgs^ e)
       {
           // Show the total amount in a MessageBox
           MessageBox::Show("Total Amount: Rs. " + totalAmount.ToString("F2"), "Total Amount", MessageBoxButtons::OK, MessageBoxIcon::Information);
       }

private: System::Void printButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Ensure there are items in the invoice before printing
    if (invoiceLabel->Text->Trim() == "")
    {
        MessageBox::Show("Please add items to the invoice before printing.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Get the customer information
    String^ customerName = nameTextBox->Text;
    String^ phoneNumber = phoneTextBox->Text;
    String^ address = addressTextBox->Text;

    // Get the invoice text from the label
    String^ invoiceText = L"Customer Name: " + customerName + L"\r\n";
    invoiceText += L"Phone Number: " + phoneNumber + L"\r\n";
    invoiceText += L"Address: " + address + L"\r\n";
    invoiceText += L"\r\nInvoice Items:\r\n" + invoiceLabel->Text;

    // Append the total amount to the invoice text
    invoiceText += L"\r\nTotal Amount: ₹" + totalAmount.ToString("F2");

    // Show a SaveFileDialog to choose the file location
    SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
    saveFileDialog->Filter = "Text Files|*.txt";
    saveFileDialog->Title = "Save Invoice as Text File";
    if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
        // Save the invoice text to the selected file
        String^ filePath = saveFileDialog->FileName;
        StreamWriter^ writer = gcnew StreamWriter(filePath);
        writer->Write(invoiceText);
        writer->Close();

        MessageBox::Show("Invoice saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
}


    private: System::Void itemTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void priceLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void nameLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void addressLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}



private: System::Void invoiceTextLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
