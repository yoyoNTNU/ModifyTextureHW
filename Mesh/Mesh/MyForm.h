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
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
			this->glPanel = (gcnew Mesh::OpenGLPanel);
			this->glPanel->SuspendLayout();
			this->panel->SuspendLayout();
			this->glPanel->createContext = true;
			this->glPanel->Name = "glPanel";
			this->glPanel->Dock = DockStyle::Fill;
			//事件初始化
			this->glPanel->Load += gcnew System::EventHandler(this, &Mesh::MyForm::OnLoad);
			this->glPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Mesh::MyForm::OnPaint);
			this->glPanel->Resize += gcnew System::EventHandler(this, &Mesh::MyForm::OnResize);
			this->glPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Mesh::MyForm::OnMouseDown);
			this->glPanel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Mesh::MyForm::OnMouseUp);
			this->glPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Mesh::MyForm::OnMouseMove);
			this->glPanel->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Mesh::MyForm::OnMouseWheel);
			//加入子控制項
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
		/// 清除任何使用中的資源。
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


	private: System::Windows::Forms::ToolStripMenuItem^ 讀取檔案ToolStripMenuItem;



	private: System::Windows::Forms::RadioButton^ radioButton_moveFace;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TexureName;
	private: System::Windows::Forms::DataGridViewImageColumn^ Image;
	private: System::Windows::Forms::Button^ AddTextureBtn;
	private: System::Windows::Forms::Button^ DelTextureBtn;
	private: System::Windows::Forms::OpenFileDialog^ openTextureDialog;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ToolStripMenuItem^ 開新檔案objToolStripMenuItem;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::ToolStripMenuItem^ 儲存檔案ToolStripMenuItem;

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
		/// 設計工具所需的變數。
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->updateTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->開新檔案objToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->讀取檔案ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->儲存檔案ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TexureName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Image = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->AddTextureBtn = (gcnew System::Windows::Forms::Button());
			this->DelTextureBtn = (gcnew System::Windows::Forms::Button());
			this->openTextureDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
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
			resources->ApplyResources(this->panel, L"panel");
			this->panel->Name = L"panel";
			// 
			// updateTimer
			// 
			this->updateTimer->Enabled = true;
			this->updateTimer->Interval = 10;
			this->updateTimer->Tick += gcnew System::EventHandler(this, &MyForm::updateTimer_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			resources->ApplyResources(this->menuStrip1, L"menuStrip1");
			this->menuStrip1->Name = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->開新檔案objToolStripMenuItem,
					this->讀取檔案ToolStripMenuItem, this->儲存檔案ToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			resources->ApplyResources(this->fileToolStripMenuItem, L"fileToolStripMenuItem");
			// 
			// 開新檔案objToolStripMenuItem
			// 
			this->開新檔案objToolStripMenuItem->Name = L"開新檔案objToolStripMenuItem";
			resources->ApplyResources(this->開新檔案objToolStripMenuItem, L"開新檔案objToolStripMenuItem");
			this->開新檔案objToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadModelbtn_Click);
			// 
			// 讀取檔案ToolStripMenuItem
			// 
			resources->ApplyResources(this->讀取檔案ToolStripMenuItem, L"讀取檔案ToolStripMenuItem");
			this->讀取檔案ToolStripMenuItem->Name = L"讀取檔案ToolStripMenuItem";
			this->讀取檔案ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadTexturebtn_Click);
			// 
			// 儲存檔案ToolStripMenuItem
			// 
			resources->ApplyResources(this->儲存檔案ToolStripMenuItem, L"儲存檔案ToolStripMenuItem");
			this->儲存檔案ToolStripMenuItem->Name = L"儲存檔案ToolStripMenuItem";
			this->儲存檔案ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::writeTexturebtn_Click);
			// 
			// groupBox_Mode
			// 
			this->groupBox_Mode->Controls->Add(this->radioButton_Texture);
			this->groupBox_Mode->Controls->Add(this->radioButton_selectFace);
			resources->ApplyResources(this->groupBox_Mode, L"groupBox_Mode");
			this->groupBox_Mode->Name = L"groupBox_Mode";
			this->groupBox_Mode->TabStop = false;
			// 
			// radioButton_Texture
			// 
			resources->ApplyResources(this->radioButton_Texture, L"radioButton_Texture");
			this->radioButton_Texture->Checked = true;
			this->radioButton_Texture->Name = L"radioButton_Texture";
			this->radioButton_Texture->TabStop = true;
			this->radioButton_Texture->UseVisualStyleBackColor = true;
			this->radioButton_Texture->Click += gcnew System::EventHandler(this, &MyForm::renderMode_Click);
			// 
			// radioButton_selectFace
			// 
			resources->ApplyResources(this->radioButton_selectFace, L"radioButton_selectFace");
			this->radioButton_selectFace->Name = L"radioButton_selectFace";
			this->radioButton_selectFace->UseVisualStyleBackColor = true;
			this->radioButton_selectFace->Click += gcnew System::EventHandler(this, &MyForm::renderMode_Click);
			// 
			// groupBox_selectMode
			// 
			this->groupBox_selectMode->Controls->Add(this->radioButton_moveFace);
			this->groupBox_selectMode->Controls->Add(this->radioButton_deleteFace);
			this->groupBox_selectMode->Controls->Add(this->radioButton_addFace);
			resources->ApplyResources(this->groupBox_selectMode, L"groupBox_selectMode");
			this->groupBox_selectMode->Name = L"groupBox_selectMode";
			this->groupBox_selectMode->TabStop = false;
			// 
			// radioButton_moveFace
			// 
			resources->ApplyResources(this->radioButton_moveFace, L"radioButton_moveFace");
			this->radioButton_moveFace->Name = L"radioButton_moveFace";
			this->radioButton_moveFace->TabStop = true;
			this->radioButton_moveFace->UseVisualStyleBackColor = true;
			this->radioButton_moveFace->CheckedChanged += gcnew System::EventHandler(this, &MyForm::selectMode_Click);
			// 
			// radioButton_deleteFace
			// 
			resources->ApplyResources(this->radioButton_deleteFace, L"radioButton_deleteFace");
			this->radioButton_deleteFace->Name = L"radioButton_deleteFace";
			this->radioButton_deleteFace->TabStop = true;
			this->radioButton_deleteFace->UseVisualStyleBackColor = true;
			this->radioButton_deleteFace->Click += gcnew System::EventHandler(this, &MyForm::selectMode_Click);
			// 
			// radioButton_addFace
			// 
			resources->ApplyResources(this->radioButton_addFace, L"radioButton_addFace");
			this->radioButton_addFace->Checked = true;
			this->radioButton_addFace->Name = L"radioButton_addFace";
			this->radioButton_addFace->TabStop = true;
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
			resources->ApplyResources(this->groupBox_tools, L"groupBox_tools");
			this->groupBox_tools->Name = L"groupBox_tools";
			this->groupBox_tools->TabStop = false;
			// 
			// label_Rotate
			// 
			resources->ApplyResources(this->label_Rotate, L"label_Rotate");
			this->label_Rotate->Name = L"label_Rotate";
			// 
			// label_Scale
			// 
			resources->ApplyResources(this->label_Scale, L"label_Scale");
			this->label_Scale->Name = L"label_Scale";
			// 
			// label_moveY
			// 
			resources->ApplyResources(this->label_moveY, L"label_moveY");
			this->label_moveY->Name = L"label_moveY";
			// 
			// label_moveX
			// 
			resources->ApplyResources(this->label_moveX, L"label_moveX");
			this->label_moveX->Name = L"label_moveX";
			// 
			// trackBar_rotate
			// 
			resources->ApplyResources(this->trackBar_rotate, L"trackBar_rotate");
			this->trackBar_rotate->LargeChange = 1;
			this->trackBar_rotate->Maximum = 360;
			this->trackBar_rotate->Name = L"trackBar_rotate";
			this->trackBar_rotate->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar_rotate->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBarRotate_Scroll);
			// 
			// trackBar_scale
			// 
			resources->ApplyResources(this->trackBar_scale, L"trackBar_scale");
			this->trackBar_scale->LargeChange = 1;
			this->trackBar_scale->Minimum = 1;
			this->trackBar_scale->Name = L"trackBar_scale";
			this->trackBar_scale->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar_scale->Value = 5;
			this->trackBar_scale->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBarScale_Scroll);
			// 
			// trackBar_moveY
			// 
			resources->ApplyResources(this->trackBar_moveY, L"trackBar_moveY");
			this->trackBar_moveY->LargeChange = 1;
			this->trackBar_moveY->Minimum = -10;
			this->trackBar_moveY->Name = L"trackBar_moveY";
			this->trackBar_moveY->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar_moveY->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBarMoveY_Scroll);
			// 
			// trackBar_moveX
			// 
			resources->ApplyResources(this->trackBar_moveX, L"trackBar_moveX");
			this->trackBar_moveX->LargeChange = 1;
			this->trackBar_moveX->Minimum = -10;
			this->trackBar_moveX->Name = L"trackBar_moveX";
			this->trackBar_moveX->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar_moveX->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBarMoveX_Scroll);
			// 
			// button_ScaleDelete
			// 
			resources->ApplyResources(this->button_ScaleDelete, L"button_ScaleDelete");
			this->button_ScaleDelete->Name = L"button_ScaleDelete";
			this->button_ScaleDelete->UseVisualStyleBackColor = true;
			this->button_ScaleDelete->Click += gcnew System::EventHandler(this, &MyForm::ScaleDelete_Click);
			// 
			// button_ScaleAdd
			// 
			resources->ApplyResources(this->button_ScaleAdd, L"button_ScaleAdd");
			this->button_ScaleAdd->Name = L"button_ScaleAdd";
			this->button_ScaleAdd->UseVisualStyleBackColor = true;
			this->button_ScaleAdd->Click += gcnew System::EventHandler(this, &MyForm::ScaleAdd_Click);
			// 
			// TexturedataGridView
			// 
			this->TexturedataGridView->AllowUserToAddRows = false;
			this->TexturedataGridView->AllowUserToDeleteRows = false;
			this->TexturedataGridView->AllowUserToResizeColumns = false;
			this->TexturedataGridView->AllowUserToResizeRows = false;
			resources->ApplyResources(this->TexturedataGridView, L"TexturedataGridView");
			this->TexturedataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->TexturedataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->ID,
					this->TexureName, this->Image
			});
			this->TexturedataGridView->MultiSelect = false;
			this->TexturedataGridView->Name = L"TexturedataGridView";
			this->TexturedataGridView->ReadOnly = true;
			this->TexturedataGridView->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->TexturedataGridView->RowTemplate->Height = 100;
			this->TexturedataGridView->SelectionChanged += gcnew System::EventHandler(this, &MyForm::textureListValueChange);
			// 
			// ID
			// 
			resources->ApplyResources(this->ID, L"ID");
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			// 
			// TexureName
			// 
			this->TexureName->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->TexureName->FillWeight = 80;
			resources->ApplyResources(this->TexureName, L"TexureName");
			this->TexureName->Name = L"TexureName";
			this->TexureName->ReadOnly = true;
			// 
			// Image
			// 
			this->Image->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			resources->ApplyResources(this->Image, L"Image");
			this->Image->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->Image->Name = L"Image";
			this->Image->ReadOnly = true;
			// 
			// panel1
			// 
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->Name = L"panel1";
			// 
			// AddTextureBtn
			// 
			resources->ApplyResources(this->AddTextureBtn, L"AddTextureBtn");
			this->AddTextureBtn->Name = L"AddTextureBtn";
			this->AddTextureBtn->UseVisualStyleBackColor = true;
			this->AddTextureBtn->Click += gcnew System::EventHandler(this, &MyForm::newTexturebtn_Click);
			// 
			// DelTextureBtn
			// 
			resources->ApplyResources(this->DelTextureBtn, L"DelTextureBtn");
			this->DelTextureBtn->Name = L"DelTextureBtn";
			this->DelTextureBtn->UseVisualStyleBackColor = true;
			this->DelTextureBtn->Click += gcnew System::EventHandler(this, &MyForm::DelTextureBtn_Click);
			// 
			// openTextureDialog
			// 
			this->openTextureDialog->FileName = L"openFileDialog1";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
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
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
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
	private: System::Void DelTextureBtn_Click(System::Object^ sender, System::EventArgs^ e);
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
		//=================================" Helper "====================================	
	private: System::String^ getFileName(String^ filepath);
	private: std::string getFileName(std::string filepath);
};
}
