#pragma once
#include "Common.h"
#include "Main.h"
#include "OpenGLPanel.h"

bool loadFinish = false;
bool loadFinish2 = false;

namespace Mesh {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// MyForm ���K�n
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  �b���[�J�غc�禡�{���X
			//
			this->glPanel = (gcnew Mesh::OpenGLPanel);
			this->glPanel->SuspendLayout();
			this->panel->SuspendLayout();
			this->glPanel->createContext = true;
			this->glPanel->Name = "glPanel";
			this->glPanel->Dock = DockStyle::Fill;
			//�ƥ��l��
			this->glPanel->Load += gcnew System::EventHandler(this, &Mesh::MyForm::OnLoad);
			this->glPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Mesh::MyForm::OnPaint);
			this->glPanel->Resize += gcnew System::EventHandler(this, &Mesh::MyForm::OnResize);
			this->glPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Mesh::MyForm::OnMouseDown);
			this->glPanel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Mesh::MyForm::OnMouseUp);
			this->glPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Mesh::MyForm::OnMouseMove);
			this->glPanel->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Mesh::MyForm::OnMouseWheel);
			//�[�J�l���
			this->panel->Controls->Add(this->glPanel);
			this->glPanel->ResumeLayout(false);
			this->panel->ResumeLayout(false);



			this->glPanel_uv = (gcnew Mesh::OpenGLPanel);
			this->glPanel_uv->SuspendLayout();
			this->panel1->SuspendLayout();
			this->glPanel_uv->createContext = true;
			this->glPanel_uv->Name = "glPanel";
			this->glPanel_uv->Dock = DockStyle::Fill;
			this->glPanel_uv->Load += gcnew System::EventHandler(this, &Mesh::MyForm::OnLoaduv);
			this->glPanel_uv->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Mesh::MyForm::OnPaintuv);
			this->glPanel_uv->Resize += gcnew System::EventHandler(this, &Mesh::MyForm::OnResizeuv);
			this->panel1->Controls->Add(this->glPanel_uv);
			this->glPanel_uv->ResumeLayout(true);
			this->panel1->ResumeLayout(true);

		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panel;
	private: System::Windows::Forms::Panel^ panel1;
	private: Mesh::OpenGLPanel^ glPanel;
	private: Mesh::OpenGLPanel^ glPanel_uv;
	private: System::Windows::Forms::Timer^ updateTimer;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;


	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;

	private: System::Windows::Forms::GroupBox^ groupBox_Mode;
	private: System::Windows::Forms::RadioButton^ radioButton_Texture;
	private: System::Windows::Forms::RadioButton^ radioButton_selectFace;
	private: System::Windows::Forms::GroupBox^ groupBox_selectMode;
	private: System::Windows::Forms::RadioButton^ radioButton_deleteFace;
	private: System::Windows::Forms::RadioButton^ radioButton_addFace;
	private: System::Windows::Forms::GroupBox^ groupBox_tools;
	private: System::Windows::Forms::Button^ button_ScaleAdd;
	private: System::Windows::Forms::Button^ button_ScaleDelete;

	private: System::Windows::Forms::DataGridView^ TexturedataGridView;


	private: System::Windows::Forms::ToolStripMenuItem^ Ū���ɮ�ToolStripMenuItem;



	private: System::Windows::Forms::RadioButton^ radioButton_moveFace;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TexureName;
	private: System::Windows::Forms::DataGridViewImageColumn^ Image;
	private: System::Windows::Forms::Button^ AddTextureBtn;
	private: System::Windows::Forms::Button^ DelTextureBtn;
	private: System::Windows::Forms::OpenFileDialog^ openTextureDialog;

	private: System::Windows::Forms::ToolStripMenuItem^ �x�s�ɮ�ToolStripMenuItem;

	private: String^ getRelativePath(String^ path);




	private: System::Windows::Forms::Label^ label_moveY;
	private: System::Windows::Forms::Label^ label_moveX;
	private: System::Windows::Forms::Label^ label_Rotate;
	private: System::Windows::Forms::Label^ label_Scale;

	private: System::Windows::Forms::TrackBar^ trackBar_rotate;
	private: System::Windows::Forms::TrackBar^ trackBar_scale;
	private: System::Windows::Forms::TrackBar^ trackBar_moveX;
	private: System::Windows::Forms::TrackBar^ trackBar_moveY;







	private: System::ComponentModel::IContainer^ components;

	
	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->updateTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Ū���ɮ�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�x�s�ɮ�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox_Mode = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton_Texture = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_selectFace = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox_selectMode = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton_moveFace = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_deleteFace = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_addFace = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox_tools = (gcnew System::Windows::Forms::GroupBox());
			this->label_Rotate = (gcnew System::Windows::Forms::Label());
			this->label_Scale = (gcnew System::Windows::Forms::Label());
			this->label_moveY = (gcnew System::Windows::Forms::Label());
			this->label_moveX = (gcnew System::Windows::Forms::Label());
			this->trackBar_rotate = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar_scale = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar_moveY = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar_moveX = (gcnew System::Windows::Forms::TrackBar());
			this->button_ScaleDelete = (gcnew System::Windows::Forms::Button());
			this->button_ScaleAdd = (gcnew System::Windows::Forms::Button());
			this->TexturedataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TexureName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Image = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->AddTextureBtn = (gcnew System::Windows::Forms::Button());
			this->DelTextureBtn = (gcnew System::Windows::Forms::Button());
			this->openTextureDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->groupBox_Mode->SuspendLayout();
			this->groupBox_selectMode->SuspendLayout();
			this->groupBox_tools->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_rotate))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_scale))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_moveY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_moveX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TexturedataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// panel
			// 
			this->panel->Location = System::Drawing::Point(18, 43);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(758, 500);
			this->panel->TabIndex = 0;
			// 
			// updateTimer
			// 
			this->updateTimer->Enabled = true;
			this->updateTimer->Interval = 10;
			this->updateTimer->Tick += gcnew System::EventHandler(this, &MyForm::updateTimer_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1384, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->Ū���ɮ�ToolStripMenuItem,
					this->�x�s�ɮ�ToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->fileToolStripMenuItem->Text = L"�ɮ�";
			// 
			// Ū���ɮ�ToolStripMenuItem
			// 
			this->Ū���ɮ�ToolStripMenuItem->Name = L"Ū���ɮ�ToolStripMenuItem";
			this->Ū���ɮ�ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->Ū���ɮ�ToolStripMenuItem->Text = L"Ū���ɮ�";
			this->Ū���ɮ�ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadTexturebtn_Click);
			// 
			// �x�s�ɮ�ToolStripMenuItem
			// 
			this->�x�s�ɮ�ToolStripMenuItem->Name = L"�x�s�ɮ�ToolStripMenuItem";
			this->�x�s�ɮ�ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->�x�s�ɮ�ToolStripMenuItem->Text = L"�x�s�ɮ�";
			this->�x�s�ɮ�ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::writeTexturebtn_Click);
			// 
			// groupBox_Mode
			// 
			this->groupBox_Mode->Controls->Add(this->radioButton_Texture);
			this->groupBox_Mode->Controls->Add(this->radioButton_selectFace);
			this->groupBox_Mode->Location = System::Drawing::Point(38, 561);
			this->groupBox_Mode->Name = L"groupBox_Mode";
			this->groupBox_Mode->Size = System::Drawing::Size(113, 46);
			this->groupBox_Mode->TabIndex = 2;
			this->groupBox_Mode->TabStop = false;
			this->groupBox_Mode->Text = L"���";
			// 
			// radioButton_Texture
			// 
			this->radioButton_Texture->AutoSize = true;
			this->radioButton_Texture->Location = System::Drawing::Point(59, 21);
			this->radioButton_Texture->Name = L"radioButton_Texture";
			this->radioButton_Texture->Size = System::Drawing::Size(47, 16);
			this->radioButton_Texture->TabIndex = 1;
			this->radioButton_Texture->Text = L"����";
			this->radioButton_Texture->UseVisualStyleBackColor = true;
			this->radioButton_Texture->Click += gcnew System::EventHandler(this, &MyForm::renderMode_Click);
			// 
			// radioButton_selectFace
			// 
			this->radioButton_selectFace->AutoSize = true;
			this->radioButton_selectFace->Checked = true;
			this->radioButton_selectFace->Location = System::Drawing::Point(6, 21);
			this->radioButton_selectFace->Name = L"radioButton_selectFace";
			this->radioButton_selectFace->Size = System::Drawing::Size(47, 16);
			this->radioButton_selectFace->TabIndex = 0;
			this->radioButton_selectFace->TabStop = true;
			this->radioButton_selectFace->Text = L"�ﭱ";
			this->radioButton_selectFace->UseVisualStyleBackColor = true;
			this->radioButton_selectFace->Click += gcnew System::EventHandler(this, &MyForm::renderMode_Click);
			// 
			// groupBox_selectMode
			// 
			this->groupBox_selectMode->Controls->Add(this->radioButton_moveFace);
			this->groupBox_selectMode->Controls->Add(this->radioButton_deleteFace);
			this->groupBox_selectMode->Controls->Add(this->radioButton_addFace);
			this->groupBox_selectMode->Location = System::Drawing::Point(38, 613);
			this->groupBox_selectMode->Name = L"groupBox_selectMode";
			this->groupBox_selectMode->Size = System::Drawing::Size(161, 46);
			this->groupBox_selectMode->TabIndex = 3;
			this->groupBox_selectMode->TabStop = false;
			this->groupBox_selectMode->Text = L"�ﭱ�Ҧ�";
			// 
			// radioButton_moveFace
			// 
			this->radioButton_moveFace->AutoSize = true;
			this->radioButton_moveFace->Location = System::Drawing::Point(108, 24);
			this->radioButton_moveFace->Name = L"radioButton_moveFace";
			this->radioButton_moveFace->Size = System::Drawing::Size(47, 16);
			this->radioButton_moveFace->TabIndex = 2;
			this->radioButton_moveFace->TabStop = true;
			this->radioButton_moveFace->Text = L"����";
			this->radioButton_moveFace->UseVisualStyleBackColor = true;
			this->radioButton_moveFace->CheckedChanged += gcnew System::EventHandler(this, &MyForm::selectMode_Click);
			// 
			// radioButton_deleteFace
			// 
			this->radioButton_deleteFace->AutoSize = true;
			this->radioButton_deleteFace->Location = System::Drawing::Point(59, 24);
			this->radioButton_deleteFace->Name = L"radioButton_deleteFace";
			this->radioButton_deleteFace->Size = System::Drawing::Size(47, 16);
			this->radioButton_deleteFace->TabIndex = 1;
			this->radioButton_deleteFace->TabStop = true;
			this->radioButton_deleteFace->Text = L"�R��";
			this->radioButton_deleteFace->UseVisualStyleBackColor = true;
			this->radioButton_deleteFace->Click += gcnew System::EventHandler(this, &MyForm::selectMode_Click);
			// 
			// radioButton_addFace
			// 
			this->radioButton_addFace->AutoSize = true;
			this->radioButton_addFace->Checked = true;
			this->radioButton_addFace->Location = System::Drawing::Point(6, 24);
			this->radioButton_addFace->Name = L"radioButton_addFace";
			this->radioButton_addFace->Size = System::Drawing::Size(47, 16);
			this->radioButton_addFace->TabIndex = 0;
			this->radioButton_addFace->TabStop = true;
			this->radioButton_addFace->Text = L"�s�W";
			this->radioButton_addFace->UseVisualStyleBackColor = true;
			this->radioButton_addFace->Click += gcnew System::EventHandler(this, &MyForm::selectMode_Click);
			// 
			// groupBox_tools
			// 
			this->groupBox_tools->Controls->Add(this->label_Rotate);
			this->groupBox_tools->Controls->Add(this->label_Scale);
			this->groupBox_tools->Controls->Add(this->label_moveY);
			this->groupBox_tools->Controls->Add(this->label_moveX);
			this->groupBox_tools->Controls->Add(this->trackBar_rotate);
			this->groupBox_tools->Controls->Add(this->trackBar_scale);
			this->groupBox_tools->Controls->Add(this->trackBar_moveY);
			this->groupBox_tools->Controls->Add(this->trackBar_moveX);
			this->groupBox_tools->Controls->Add(this->button_ScaleDelete);
			this->groupBox_tools->Controls->Add(this->button_ScaleAdd);
			this->groupBox_tools->Location = System::Drawing::Point(223, 561);
			this->groupBox_tools->Name = L"groupBox_tools";
			this->groupBox_tools->Size = System::Drawing::Size(480, 111);
			this->groupBox_tools->TabIndex = 4;
			this->groupBox_tools->TabStop = false;
			this->groupBox_tools->Text = L"�վ�u��";
			// 
			// label_Rotate
			// 
			this->label_Rotate->AutoSize = true;
			this->label_Rotate->Location = System::Drawing::Point(298, 74);
			this->label_Rotate->Name = L"label_Rotate";
			this->label_Rotate->Size = System::Drawing::Size(29, 12);
			this->label_Rotate->TabIndex = 10;
			this->label_Rotate->Text = L"����";
			// 
			// label_Scale
			// 
			this->label_Scale->AutoSize = true;
			this->label_Scale->Location = System::Drawing::Point(298, 28);
			this->label_Scale->Name = L"label_Scale";
			this->label_Scale->Size = System::Drawing::Size(29, 12);
			this->label_Scale->TabIndex = 11;
			this->label_Scale->Text = L"�Y��";
			// 
			// label_moveY
			// 
			this->label_moveY->AutoSize = true;
			this->label_moveY->Location = System::Drawing::Point(116, 74);
			this->label_moveY->Name = L"label_moveY";
			this->label_moveY->Size = System::Drawing::Size(37, 12);
			this->label_moveY->TabIndex = 10;
			this->label_moveY->Text = L"Y�첾";
			// 
			// label_moveX
			// 
			this->label_moveX->AutoSize = true;
			this->label_moveX->Location = System::Drawing::Point(116, 28);
			this->label_moveX->Name = L"label_moveX";
			this->label_moveX->Size = System::Drawing::Size(37, 12);
			this->label_moveX->TabIndex = 9;
			this->label_moveX->Text = L"X�첾";
			// 
			// trackBar_rotate
			// 
			this->trackBar_rotate->AutoSize = false;
			this->trackBar_rotate->LargeChange = 1;
			this->trackBar_rotate->Location = System::Drawing::Point(332, 68);
			this->trackBar_rotate->Maximum = 360;
			this->trackBar_rotate->Name = L"trackBar_rotate";
			this->trackBar_rotate->Size = System::Drawing::Size(119, 22);
			this->trackBar_rotate->TabIndex = 8;
			this->trackBar_rotate->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar_rotate->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBarRotate_Scroll);
			// 
			// trackBar_scale
			// 
			this->trackBar_scale->AutoSize = false;
			this->trackBar_scale->LargeChange = 1;
			this->trackBar_scale->Location = System::Drawing::Point(332, 24);
			this->trackBar_scale->Minimum = 1;
			this->trackBar_scale->Name = L"trackBar_scale";
			this->trackBar_scale->Size = System::Drawing::Size(119, 22);
			this->trackBar_scale->TabIndex = 7;
			this->trackBar_scale->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar_scale->Value = 5;
			this->trackBar_scale->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBarScale_Scroll);
			// 
			// trackBar_moveY
			// 
			this->trackBar_moveY->AutoSize = false;
			this->trackBar_moveY->LargeChange = 1;
			this->trackBar_moveY->Location = System::Drawing::Point(150, 68);
			this->trackBar_moveY->Minimum = -10;
			this->trackBar_moveY->Name = L"trackBar_moveY";
			this->trackBar_moveY->Size = System::Drawing::Size(119, 22);
			this->trackBar_moveY->TabIndex = 6;
			this->trackBar_moveY->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar_moveY->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBarMoveY_Scroll);
			// 
			// trackBar_moveX
			// 
			this->trackBar_moveX->AutoSize = false;
			this->trackBar_moveX->LargeChange = 1;
			this->trackBar_moveX->Location = System::Drawing::Point(150, 24);
			this->trackBar_moveX->Minimum = -10;
			this->trackBar_moveX->Name = L"trackBar_moveX";
			this->trackBar_moveX->Size = System::Drawing::Size(119, 22);
			this->trackBar_moveX->TabIndex = 5;
			this->trackBar_moveX->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar_moveX->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBarMoveX_Scroll);
			// 
			// button_ScaleDelete
			// 
			this->button_ScaleDelete->Location = System::Drawing::Point(17, 52);
			this->button_ScaleDelete->Name = L"button_ScaleDelete";
			this->button_ScaleDelete->Size = System::Drawing::Size(68, 23);
			this->button_ScaleDelete->TabIndex = 1;
			this->button_ScaleDelete->Text = L"�Y�p�ﭱ";
			this->button_ScaleDelete->UseVisualStyleBackColor = true;
			this->button_ScaleDelete->Click += gcnew System::EventHandler(this, &MyForm::ScaleDelete_Click);
			// 
			// button_ScaleAdd
			// 
			this->button_ScaleAdd->Location = System::Drawing::Point(17, 23);
			this->button_ScaleAdd->Name = L"button_ScaleAdd";
			this->button_ScaleAdd->Size = System::Drawing::Size(67, 23);
			this->button_ScaleAdd->TabIndex = 0;
			this->button_ScaleAdd->Text = L"��j�ﭱ";
			this->button_ScaleAdd->UseVisualStyleBackColor = true;
			this->button_ScaleAdd->Click += gcnew System::EventHandler(this, &MyForm::ScaleAdd_Click);
			// 
			// TexturedataGridView
			// 
			this->TexturedataGridView->AllowUserToAddRows = false;
			this->TexturedataGridView->AllowUserToDeleteRows = false;
			this->TexturedataGridView->AllowUserToResizeColumns = false;
			this->TexturedataGridView->AllowUserToResizeRows = false;
			this->TexturedataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->TexturedataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->ID,
					this->TexureName, this->Image
			});
			this->TexturedataGridView->Location = System::Drawing::Point(829, 43);
			this->TexturedataGridView->MultiSelect = false;
			this->TexturedataGridView->Name = L"TexturedataGridView";
			this->TexturedataGridView->ReadOnly = true;
			this->TexturedataGridView->RowHeadersWidth = 25;
			this->TexturedataGridView->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->TexturedataGridView->RowTemplate->Height = 100;
			this->TexturedataGridView->Size = System::Drawing::Size(529, 467);
			this->TexturedataGridView->TabIndex = 6;
			this->TexturedataGridView->SelectionChanged += gcnew System::EventHandler(this, &MyForm::textureListValueChange);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(742, 561);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(111, 111);
			this->panel1->TabIndex = 7;
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			this->ID->Width = 50;
			// 
			// TexureName
			// 
			this->TexureName->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->TexureName->FillWeight = 80;
			this->TexureName->HeaderText = L"Name";
			this->TexureName->Name = L"TexureName";
			this->TexureName->ReadOnly = true;
			// 
			// Image
			// 
			this->Image->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Image->HeaderText = L"Texture";
			this->Image->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->Image->Name = L"Image";
			this->Image->ReadOnly = true;
			// 
			// AddTextureBtn
			// 
			this->AddTextureBtn->Location = System::Drawing::Point(875, 520);
			this->AddTextureBtn->Name = L"AddTextureBtn";
			this->AddTextureBtn->Size = System::Drawing::Size(180, 23);
			this->AddTextureBtn->TabIndex = 8;
			this->AddTextureBtn->Text = L"�s�W�K��";
			this->AddTextureBtn->UseVisualStyleBackColor = true;
			this->AddTextureBtn->Click += gcnew System::EventHandler(this, &MyForm::newTexturebtn_Click);
			// 
			// DelTextureBtn
			// 
			this->DelTextureBtn->Location = System::Drawing::Point(1143, 520);
			this->DelTextureBtn->Name = L"DelTextureBtn";
			this->DelTextureBtn->Size = System::Drawing::Size(180, 23);
			this->DelTextureBtn->TabIndex = 9;
			this->DelTextureBtn->Text = L"�R���K��";
			this->DelTextureBtn->UseVisualStyleBackColor = true;
			// 
			// openTextureDialog
			// 
			this->openTextureDialog->FileName = L"openFileDialog1";

			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1384, 684);
			this->Controls->Add(this->DelTextureBtn);
			this->Controls->Add(this->AddTextureBtn);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox_tools);
			this->Controls->Add(this->TexturedataGridView);
			this->Controls->Add(this->groupBox_selectMode);
			this->Controls->Add(this->groupBox_Mode);
			this->Controls->Add(this->panel);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox_Mode->ResumeLayout(false);
			this->groupBox_Mode->PerformLayout();
			this->groupBox_selectMode->ResumeLayout(false);
			this->groupBox_selectMode->PerformLayout();
			this->groupBox_tools->ResumeLayout(false);
			this->groupBox_tools->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_rotate))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_scale))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_moveY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar_moveX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TexturedataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//=================================" OpenGL Panel "====================================
		void OnLoad(System::Object^ sender, System::EventArgs^ e);
		void OnPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
		void OnResize(System::Object^ sender, System::EventArgs^ e);
		void OnMouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		void OnMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		void OnMouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		void OnMouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		void OnLoaduv(System::Object^ sender, System::EventArgs^ e);
		void OnPaintuv(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
		void OnResizeuv(System::Object^ sender, System::EventArgs^ e);
		//=================================" Timer "====================================
	private: System::Void updateTimer_Tick(System::Object^ sender, System::EventArgs^ e);
		//=================================" File "====================================
	private: System::Void loadModelbtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void loadTexturebtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void writeTexturebtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void newTexturebtn_Click(System::Object^ sender, System::EventArgs^ e);
		//=================================" TextureList "====================================
	private: System::Void addTexturetoList(int index,string _fileName);
	private: System::Void updateTextureList();
	private: System::Void textureListValueChange(System::Object^ sender, System::EventArgs^ e);
		//=================================" Mode "====================================	
	private: System::Void renderMode_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void selectMode_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ScaleAdd_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ScaleDelete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Parameterization_Click(System::Object^ sender, System::EventArgs^ e);
		//=================================" Edict "====================================	
	private: System::Void trackBarMoveX_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBarMoveY_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBarRotate_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBarScale_Scroll(System::Object^ sender, System::EventArgs^ e);
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
