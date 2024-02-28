#include "MyForm.h"
#include <iostream>
using namespace Mesh;

void LoadTexture(const char* filename,bool);
void clear_texture_info();

[STAThreadAttribute]
int main(void)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());

	return 0;
}

//=================================" OpenGL Panel "====================================
void Mesh::MyForm::OnLoad(System::Object^ sender, System::EventArgs^ e)
{
	std::cout << "Load mesh panel finish" << endl;
	My_Init();
	updateTextureList();
	loadFinish = true;
	OnResize(glPanel, nullptr);
}

void Mesh::MyForm::OnPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	My_Paint();
}

void Mesh::MyForm::OnResize(System::Object^ sender, System::EventArgs^ e)
{
	if (loadFinish) {
		glPanel->makeContextCurrent();

		int width = glPanel->Width;
		int height = glPanel->Height;
		meshWindowCam.SetWindowSize(width, height);

		windowWidth = width;
		windowHeight = height;
		aspect = (float)width / (float)height;
		pickingTexture.Init(width, height);

		glViewport(0, 0, width, height);
	}
}

void Mesh::MyForm::OnMouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	int button = 0;
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		button = 0;
		meshWindowCam.mousePressEvent(GLUT_LEFT_BUTTON, e->X, e->Y);
	}
	else if (e->Button == System::Windows::Forms::MouseButtons::Right && !drawTexture) {
		isRightButtonPress = true;
		SelectionHandler(e->X, e->Y);
		Parameterization();
		button = 1;
	}
	else if (e->Button == System::Windows::Forms::MouseButtons::Middle) {
		button = 2;
		meshWindowCam.mousePressEvent(GLUT_MIDDLE_BUTTON, e->X, e->Y);
	}
	else {
		return System::Void();
	}
	meshWindowCam.mouseEvents(button, 0, e->X, e->Y);
}

void Mesh::MyForm::OnMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	int button = 0;
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		button = 0;
		meshWindowCam.mouseReleaseEvent(GLUT_LEFT_BUTTON, e->X, e->Y);
	}
	else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
		isRightButtonPress = false;
		button = 1;
	}
	else if (e->Button == System::Windows::Forms::MouseButtons::Middle) {
		button = 2;
		meshWindowCam.mouseReleaseEvent(GLUT_MIDDLE_BUTTON, e->X, e->Y);
	}
	else {
		return System::Void();
	}
	meshWindowCam.mouseEvents(button, 1, e->X, e->Y);
}

void Mesh::MyForm::OnMouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		meshWindowCam.mouseMoveEvent(e->X, e->Y);
	}
	else if (e->Button == System::Windows::Forms::MouseButtons::Right && !drawTexture) {
		SelectionHandler(e->X, e->Y);
		Parameterization();
	}
	else if (e->Button == System::Windows::Forms::MouseButtons::Middle) {
		meshWindowCam.mouseMoveEvent(e->X, e->Y);
	}
	panel->Focus();
	return System::Void();
}

void Mesh::MyForm::OnMouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (e->Delta > 0)
	{
		meshWindowCam.wheelEvent(-5);
	}
	else
	{
		meshWindowCam.wheelEvent(5);
	}
}

void Mesh::MyForm::OnLoaduv(System::Object^ sender, System::EventArgs^ e)
{
	// 1.
	std::cout << "Load texcoord panel finish" << endl;

	//InitOpenGL();
	//ResourcePath::modelPath = "../../Model/UnionSphere.obj";
	//LoadModel();
	My_Init();
	//InitOpenGL();

	loadFinish2 = true;
	OnResizeuv(this->glPanel_uv, nullptr);
}

void Mesh::MyForm::OnPaintuv(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	// 3.
	if(!textureIDList.empty()) uvPaint();
}

void Mesh::MyForm::OnResizeuv(System::Object^ sender, System::EventArgs^ e)
{
	if (loadFinish2) {
		glPanel_uv->makeContextCurrent();
	}
}

//=================================" Timer "====================================

System::Void Mesh::MyForm:: updateTimer_Tick(System::Object^ sender, System::EventArgs^ e) 
{
	glPanel->Invalidate();
	glPanel_uv->Invalidate();
}

//=================================" File "====================================

System::Void Mesh::MyForm:: loadModelbtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	//開啟選取檔案視窗，列印選取位置
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	ofd->Title = "載入模型檔案";
	ofd->Filter = "OBJ Files (*.obj)|*.obj|All Files (*.*)|*.*";
	if (ofd->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
		return;
	}
	const char* chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(ofd->FileName)).ToPointer();
	std::string dest = chars;
	printf("%s\n", dest.c_str());

	ResourcePath::modelPath = dest;

	LoadModel();

	glPanel_uv = gcnew OpenGLPanel();
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
	this->glPanel_uv->Visible = this->TexturedataGridView->SelectedCells->Count != 0;
	this->開新檔案objToolStripMenuItem->Enabled = false;
	this->讀取檔案ToolStripMenuItem->Enabled = true;
	this->儲存檔案ToolStripMenuItem->Enabled = true;
}

System::Void Mesh::MyForm::loadTexturebtn_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (!model.ReadFile())
	{
		std::cout << "Read File Fail!" << endl;
		this->label1->Visible = true;
		this->label1->Text = "此模型目前尚未擁有儲存過的紋理";
		return;
	}

	clear_texture_info();

	fstream file;
	int size;
	string modelName = ResourcePath::modelPath + "_texture.txt";
	file.open(modelName, ios::in);
	if (!file.is_open()) {
		this->label1->Visible = true;
		this->label1->Text = "此模型目前尚未擁有儲存過的紋理";
		return;
	}
	file >> size;	// 貼圖張數
	for (int i = 0; i < size; i++) {
		//new_texture_info();
		char tmp;
		string path;
		file >> tmp;
		while (tmp != '<') {
			path.push_back(tmp);
			file >> tmp;
		}
		std::cout << "load image:" << path << endl;
		LoadTexture(path.c_str(),false);
		file >> uvPreRotate[i] >> uvRotate[i];
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				file >> uvScale[i][j][k] >> uvTranslate[i][j][k];
			}
		}
	}
	std::cout << "Read Finish" << endl;
	for (int i = 0; i < size; i++)
	{
		model.Parameterization(uvRotate[i], i);
		uvPreRotate[i] = uvRotate[i];
	}
	file.close();
	updateTextureList();
}

System::Void Mesh::MyForm::writeTexturebtn_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (!model.WriteFile())
	{
		std::cout << "Wrire File Fail!" << endl;
		this->label1->Visible = true;
		this->label1->Text = "紋理儲存失敗!";
		return;
	}
	fstream file;
	string modelName = ResourcePath::modelPath + "_texture.txt";
	file.open(modelName, ios::out);
	if (!file.is_open()) {
		this->label1->Visible = true;
		this->label1->Text = "紋理儲存失敗!";
		return;
	}
	file << (int)textureIDList.size() << endl;	// 貼圖張數
	for (int i = 0; i < textureIDList.size(); i++) {
		file <<  textureFileName[i] << "< ";
		file << uvPreRotate[i] << " " << uvRotate[i] << " ";
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				file << uvScale[i][j][k] << " " << uvTranslate[i][j][k] << " ";
			}
		}
		file << endl;
	}
	this->label1->Visible = true;
	this->label1->Text = "紋理儲存成功!";
	std::cout << "Write Finish" << endl;
	file.close();
}

System::String^ Mesh::MyForm::getRelativePath(String^ path)
{
	Uri^ pathUri = gcnew Uri(path);
	String^ cd = Environment::CurrentDirectory;
	// Folders must end in a slash
	if (!cd->EndsWith(System::IO::Path::DirectorySeparatorChar.ToString()))
	{
		cd += System::IO::Path::DirectorySeparatorChar;
	}
	Uri^ cdUri = gcnew Uri(cd);
	return Uri::UnescapeDataString(cdUri->MakeRelativeUri(pathUri)->ToString()->Replace('/', System::IO::Path::DirectorySeparatorChar));
}

System::Void Mesh::MyForm::newTexturebtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	openTextureDialog->InitialDirectory = "./Image/";
	openTextureDialog->Title = "選擇貼圖";
	openTextureDialog->Filter = "PNG, JPG Files (*.png,*.jpg)|*.png;*.jpg|All Files (*.*)|*.*";
	openTextureDialog->Multiselect = true;
	openTextureDialog->CheckFileExists = true;
	if (openTextureDialog->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
		return;
	}
	for each (String ^ path in openTextureDialog->FileNames) {
		//String^ relPath = getRelativePath(path);
		IntPtr fileNamePtr = Marshal::StringToHGlobalAnsi(path);
		//LoadTexture((char*)fileNamePtr.ToPointer(), true);
		LoadTexture((char*)fileNamePtr.ToPointer(),false);
	}
	updateTextureList();
}

System::Void Mesh::MyForm::DelTextureBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (TexturedataGridView->SelectedCells->Count == 0)return;
	DisableID.insert(selectTextureIndex);
	updateTextureList();
}

//=================================" TextureList "====================================

System::Void Mesh::MyForm::addTexturetoList(int index,string _fileName)
{
	String^ nameTmp = gcnew String(_fileName.c_str());
	String^ strTmp = gcnew String((ResourcePath::imagePath + _fileName).c_str());
	TexturedataGridView->Rows->Add(index, nameTmp, Image::FromFile(strTmp));
}

System::Void Mesh::MyForm::updateTextureList() 
{
	for (int i : textureIDList) {
		std::cout << i << "　";
	}
	std::cout << endl;
	TexturedataGridView->Rows->Clear();
	for (int i = 0; i < textureIDList.size(); i++) {
		String^ nameTmp = gcnew String(textureFileName[i].c_str());
		TexturedataGridView->Rows->Add(i, getFileName(nameTmp), Image::FromFile(nameTmp));
	}

	for (int i : DisableID) {
		TexturedataGridView->Rows[i]->Visible = false;
	}
	TexturedataGridView->ClearSelection();
	int count=TexturedataGridView->Rows->Count;
	for (int i = 0; i < count ; i++) {
		if (!DisableID.count(i)) {
			TexturedataGridView->Rows[i]->Selected = true;
			break;
		}
	}
	bool tmp = TexturedataGridView->SelectedRows->Count == 0;
	if (tmp) {
		this->radioButton_Texture->Checked = true;
		drawTexture = true;
		this->groupBox_selectMode->Visible = false;
	}
	this->groupBox_tools->Visible = !tmp;
	this->glPanel_uv->Visible = !tmp;
	this->label2->Visible = tmp;
	this->radioButton_selectFace->Enabled = !tmp;
	
	
}

System::Void Mesh::MyForm::textureListValueChange(System::Object^ sender, System::EventArgs^ e)
{
	if (TexturedataGridView->SelectedCells->Count == 0)
		return;
	if (textureIDList.empty()) return;
	int id = Convert::ToInt32(TexturedataGridView->SelectedCells[0]->OwningRow->Cells[0]->Value);
	selectTextureIndex = id;
	trackBar_rotate->Value = uvRotate[selectTextureIndex];
	trackBar_moveX->Value = uvTranslate[selectTextureIndex][3][0] * 10;
	trackBar_moveY->Value = uvTranslate[selectTextureIndex][3][1] * 10;
	trackBar_scale->Value = uvScale[selectTextureIndex][0][0] * 5;
}

//=================================" Mode "====================================

System::Void Mesh::MyForm::renderMode_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (this->radioButton_selectFace->Checked) 
	{
		drawTexture = false;
		this->groupBox_selectMode->Visible = true;
	}
	else 
	{
		drawTexture = true;
		this->groupBox_selectMode->Visible = false;
	}
}

System::Void Mesh::MyForm::selectMode_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->radioButton_addFace->Checked)
		selectionMode = SelectMode::ADD_FACE;
	else if(this->radioButton_deleteFace->Checked)
		selectionMode = SelectMode::DEL_FACE;
	else if (this->radioButton_moveFace->Checked)
		selectionMode = SelectMode::MOVE_FACE;
}

System::Void Mesh::MyForm::ScaleAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
	model.Scale(selectTextureIndex);
	Parameterization();
}

System::Void Mesh::MyForm::ScaleDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
	model.Shrink(selectTextureIndex);
	Parameterization();
}

System::Void Mesh::MyForm::Parameterization_Click(System::Object^ sender, System::EventArgs^ e)
{
	Parameterization();
}

//=================================" Edict "====================================	

System::Void Mesh::MyForm::trackBarMoveX_Scroll(System::Object^ sender, System::EventArgs^ e) 
{
	TranslateTextureX(trackBar_moveX->Value);
}

System::Void Mesh::MyForm::trackBarMoveY_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	TranslateTextureY(trackBar_moveY->Value);
}

System::Void Mesh::MyForm::trackBarRotate_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	if (textureIDList.empty()) return;
	uvRotate[selectTextureIndex] = trackBar_rotate->Value;
}

System::Void Mesh::MyForm::trackBarScale_Scroll(System::Object^ sender, System::EventArgs^ e)
{
	ScaleTexture(trackBar_scale->Value);
}

//=================================" Helper "====================================	

System::String^ Mesh::MyForm::getFileName(String^ filepath) {
	int lastBackslashIndex = filepath->LastIndexOf('\\');
	System::String^ fileName = filepath->Substring(lastBackslashIndex + 1);
	return fileName;
}

std::string Mesh::MyForm::getFileName(std::string filepath) {
	int lastBackslashIndex = filepath.find('\\');
	std::string fileName = filepath.substr(lastBackslashIndex + 1);
	return fileName;
}

//=================================" Project2 Function "====================================


void clear_texture_info() {
	uvRotate.clear();
	uvPreRotate.clear();
	uvScale.clear();
	uvTranslate.clear();
	textureIDList.clear();
	textureFileName.clear();
}

void SelectionHandler(unsigned int x, unsigned int y)
{
	GLuint faceID = pickingTexture.ReadTexture(x, windowHeight - y - 1);
	//std::cout << "ID：" << faceID << "	editorHeight：" << windowHeight << "	x：" << x << "	y：" << y << std::endl;
	if (faceID != 0)
	{
		//cout << "ID : " << faceID << endl;
		currentFaceID = faceID;
	}
	static float last_move_time = 0;
	if (selectionMode == ADD_FACE)
	{
		if (faceID != 0)
		{
			model.AddSelectedFace(faceID - 1, selectTextureIndex);
		}
	}
	else if (selectionMode == DEL_FACE)
	{
		if (faceID != 0)
		{
			model.DeleteSelectedFace(faceID - 1, selectTextureIndex);
		}
	}
	else if (selectionMode == MOVE_FACE)
	{
		if (faceID != 0 && (glutGet(GLUT_ELAPSED_TIME)- last_move_time > 3.0f))
		{
			model.MoveSelectedFace(faceID - 1, selectTextureIndex);
			last_move_time = glutGet(GLUT_ELAPSED_TIME);
		}
	}

}

void LoadModel()
{
	if (model.Init(ResourcePath::modelPath))
	{
		puts("Load Model Finish");
	}
	else
	{
		puts("Load Model Failed");
	}
}



void LoadTexture(const char* _path,bool first)
{
	string path = _path;
	string filename;
	for (int i = path.length() - 1; i >= 0; i--) {
		//if (path[i] == '/' || path[i] == '\\') break;
		filename.insert(filename.begin(), path[i]);
	}

	std::cout << "_path: " << _path << endl;
	std::cout << "filename: " << filename << endl;
	std::cout << "textureFileName.size: " << textureFileName.size() << endl;
	if (first) textureFileName.insert(textureFileName.begin() + textureFileName.size() / 2, filename);
	else textureFileName.push_back(filename);

	TextureData tdata = Load_png((/*ResourcePath::imagePath +*/ filename).c_str());

	if (first) {
		textureIDList.insert(textureIDList.begin() + textureIDList.size() / 2, 1);
		glGenTextures(1, &textureIDList[textureIDList.size() / 2]);
		glBindTexture(GL_TEXTURE_2D, textureIDList[textureIDList.size() / 2]);
	}
	else {
		textureIDList.push_back(1);
		glGenTextures(1, &textureIDList[textureIDList.size() - 1]);
		glBindTexture(GL_TEXTURE_2D, textureIDList[textureIDList.size() - 1]);
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, tdata.width, tdata.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, tdata.data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	std::cout << "Load Texture Finish." << endl;

	uvRotate.push_back(0.0);
	uvPreRotate.push_back(0.0);
	uvScale.push_back(mat4(1.0));
	uvTranslate.push_back(mat4(1.0));
	//sequences.push_back(0);

	//model.selectedFaceList.push_back(std::vector<unsigned int>());
	//model.faceIDsPtrList.push_back(std::vector<unsigned int*>());
	//model.elementCountList.push_back(std::vector<int>());

	//model.model.meshList.push_back(MyMesh());
	//model.model.vaoList.push_back(GLuint());
	//model.model.eboList.push_back(GLuint());
	//model.model.vboNList.push_back(GLuint());
	//model.model.vboTList.push_back(GLuint());
	//model.model.vboVList.push_back(GLuint());
}

bool loaded = false;
void LoadTextures()
{
	if (loaded) return;

	loaded = true;
	string textureName;
	for (int i = 0; i < textureIDList.size(); i++) {
		switch (i)
		{
		case 0:
			textureName = "shell.jpg";
			break;
		case 1:
			textureName = "Scales.jpg";
			break;
		case 2:
			textureName = "eye.jpg";
			break;
		case 3:
			textureName = "eye.jpg";
			break;
		case 4:
			textureName = "teeth.jpg";
			break;
		case 5:
			textureName = "Scales.jpg";
			break;
		case 6:
			textureName = "Scales.jpg";
			break;
		case 7:
			textureName = "Scales.jpg";
			break;
		case 8:
			textureName = "Scales.jpg";
			break;
		case 9:
			textureName = "Scales.jpg";
			break;
		case 10:
			textureName = "Scales.jpg";
			break;
		case 11:
			textureName = "Scales.jpg";
			break;
		case 12:
			textureName = "Scales.jpg";
			break;
		case 13:
			textureName = "checkerboard4.jpg";
			break;
		default:
			std::cout << "has limit" << endl;
			return;
			break;
		}

		textureFileName.push_back(textureName);
		TextureData tdata = Load_png((ResourcePath::imagePath + textureName).c_str());

		glGenTextures(1, &textureIDList[i]);
		glBindTexture(GL_TEXTURE_2D, textureIDList[i]);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, tdata.width, tdata.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, tdata.data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	std::cout << "Load Texture Finish." << endl;
}

void InitOpenGL()
{
	glEnable(GL_TEXTURE_2D);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void InitData()
{   //TODO: 改為可以自由選擇模型
	ResourcePath::shaderPath = "Shader/";
	ResourcePath::imagePath = "Image/";
	//ResourcePath::modelPath = "Model/UnionSphere.obj";
	//ResourcePath::modelPath = "Model/armadillo.obj";

	

	drawTextureShader.Init();
	drawModelShader.Init();
	pickingShader.Init();
	pickingTexture.Init(windowWidth, windowHeight);
	drawPickingFaceShader.Init();

	glGenBuffers(1, &vboPoint);
		
	LoadTextures();

	LoadModel();
	// 根據Texture數量儲存矩陣
	for (int i = 0; i < textureIDList.size(); i++) 
	{
		uvRotate.push_back(0.0);
		uvPreRotate.push_back(0.0);
		uvScale.push_back(mat4(1.0));
		uvTranslate.push_back(mat4(1.0));
	}
}

void My_Init()
{
	InitOpenGL();
	InitData();
}

void My_Paint()
{

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, windowWidth, windowHeight);

	glm::mat4 mvMat = meshWindowCam.GetViewMatrix() * meshWindowCam.GetModelMatrix();
	glm::mat4 pMat = meshWindowCam.GetProjectionMatrix(aspect);
	glm::mat3 normalMat = glm::transpose(glm::inverse(glm::mat3(mvMat)));

	if (!drawTexture)
	{
		pickingTexture.Enable();

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		pickingShader.Enable();
		pickingShader.SetMVMat(value_ptr(mvMat));
		pickingShader.SetPMat(value_ptr(pMat));
		model.Render();

		pickingShader.Disable();
		pickingTexture.Disable();
	}

	//glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawModelShader.Enable();
	drawModelShader.SetWireColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	drawModelShader.SetFaceColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	drawModelShader.UseLighting(true);
	drawModelShader.DrawTexCoord(false);
	drawModelShader.DrawTexture(false);
	drawModelShader.DrawWireframe(!drawTexture);
	drawModelShader.SetNormalMat(normalMat);
	drawModelShader.SetMVMat(mvMat);
	drawModelShader.SetPMat(pMat);
	if (!textureIDList.empty()) {
		drawModelShader.SetUVTranslateMat(uvTranslate[selectTextureIndex]);
		drawModelShader.SetUVScaleMat(uvScale[selectTextureIndex]);
	}
	model.Render();

	if (drawTexture)
	{

		drawModelShader.DrawTexture(true);
		for (int i = 0; i < textureIDList.size() ; i++)
		{
			if (DisableID.count(i))continue;
			float radian = uvRotate[i] * M_PI / 180.0f;
			glm::mat4 uvRotMat = glm::rotate(radian, glm::vec3(0.0, 0.0, 1.0));

			glBindTexture(GL_TEXTURE_2D, textureIDList[i]);
			drawModelShader.SetUVRotMat(uvRotMat);
			drawModelShader.SetUVTranslateMat(uvTranslate[i]);
			drawModelShader.SetUVScaleMat(uvScale[i]);

			model.RenderParameterized(i);
		}
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	else
	{
		if (selectionMode == SelectMode::ADD_FACE || selectionMode == SelectMode::DEL_FACE || selectionMode == SelectMode::MOVE_FACE)
		{
			drawPickingFaceShader.Enable();
			drawPickingFaceShader.SetMVMat(value_ptr(mvMat));
			drawPickingFaceShader.SetPMat(value_ptr(pMat));
			model.RenderSelectedFace(selectTextureIndex);
			drawPickingFaceShader.Disable();
		}



	}

}

void uvPaint()
{
	if (textureIDList.empty()) return;
	float radian = (uvRotate[selectTextureIndex] - uvPreRotate[selectTextureIndex]) * M_PI / 180.0f;
	glm::mat4 uvRotMat = glm::rotate(radian, glm::vec3(0.0, 0.0, 1.0));
	glm::mat4 mvMat = texCoordWindowCam.GetViewMatrix() * Translate(0, 0, -10) * texCoordWindowCam.GetModelMatrix();
	glm::mat4 pMat = texCoordWindowCam.GetProjectionMatrix(aspect);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawModelShader.Enable();

	drawModelShader.SetFaceColor(glm::vec4(0.0f, 0.0f, 0.0f, 0.0f));
	drawModelShader.SetWireColor(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
	drawModelShader.UseLighting(false);
	drawModelShader.DrawWireframe(true);
	drawModelShader.DrawTexCoord(true);
	drawModelShader.DrawTexture(false);
	drawModelShader.SetMVMat(mvMat);
	drawModelShader.SetPMat(pMat);
	drawModelShader.SetUVRotMat(uvRotMat);
	drawModelShader.SetUVTranslateMat(uvTranslate[selectTextureIndex]);
	drawModelShader.SetUVScaleMat(uvScale[selectTextureIndex]);

	model.RenderParameterized(selectTextureIndex);

	drawModelShader.Disable();
}

//=================================" New Function "====================================

void Parameterization()
{
	if (textureIDList.empty()) return;
	model.Parameterization(uvRotate[selectTextureIndex], selectTextureIndex);
	uvPreRotate[selectTextureIndex] = uvRotate[selectTextureIndex];
}