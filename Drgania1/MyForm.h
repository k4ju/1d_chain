#pragma once
#define _USING_MATH_DEFINES
#include <math.h>
#include <string>
#include <fstream>

using namespace std;


namespace Drgania1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const int N = 72; ///12
	static double k = 0.1;//[kN/m]
	static double q;
	static long double w; //czestosc

	//rk4
	double km[N];
	double kx1[N], kx2[N], kx3[N], kx4[N];
	double kv1[N], kv2[N], kv3[N], kv4[N];
	int Re[N];
	//const
	static double a = 5.63;//[A]
	static double A = 0.1;//[A]
	static double B = 0.2;//[A]
	const double dt = 0.03;

	struct atom
	{
		int m;//[u]
		double R;//[A]
		double x;//[A]
		double du; //wychylenie
		double v;//[km/s]
		atom()	{ m = 2; R = 1; x = v = du = 0.0; }
	};

	atom Atom[N];

	//1domieszka//luŸne

	ifstream d1_s10_amp64;
	ifstream d1_s3_amp9;

	//1domieszka//periodyczne

	ifstream d1_wP_s3_amp68;
	ifstream d1_wP_s10_amp63;

	ifstream d2_sw;
	ifstream d2_s10_amp65;
	ifstream d2_per;
	ifstream d2_wP_s10_amp65;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  labelE;
	private: System::Windows::Forms::HScrollBar^  hScrollBark;
	private: System::Windows::Forms::Label^  labelk;
	private: System::Windows::Forms::Button^  button0;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  labeldx;
	private: System::Windows::Forms::HScrollBar^  hScrollBardx;

	private: System::Windows::Forms::HScrollBar^  hScrollBari;

	private: System::Windows::Forms::Button^  button1;






	private: System::Windows::Forms::VScrollBar^  vScrollBarZoom;
	private: System::Windows::Forms::HScrollBar^  hScrollBar1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  radioButtonP;
	private: System::Windows::Forms::RadioButton^  radioButtonU;
	private: System::Windows::Forms::RadioButton^  radioButtonS;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  labelw;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ³añcuchJednoatomowyToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  ³añcuchDwuatomowyToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  drganiaAkustyczneToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  drganiaOptyczneToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pojedynczaDomieszkaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  warunkiLuŸneToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  mdM02ToolStripMenuItem2;



	private: System::Windows::Forms::ToolStripMenuItem^  warunkiPeriodyczneToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  mdM05ToolStripMenuItem2;




	private: System::Windows::Forms::ToolStripMenuItem^  dwieDomieszkiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  warunkiSwobodneToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  warunkiPeriodyczneToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem6;
	private: System::Windows::Forms::ToolStripMenuItem^  niewychylona3ToolStripMenuItem;









	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->labelw = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonP = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonU = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonS = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->labeldx = (gcnew System::Windows::Forms::Label());
			this->hScrollBardx = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollBari = (gcnew System::Windows::Forms::HScrollBar());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button0 = (gcnew System::Windows::Forms::Button());
			this->hScrollBark = (gcnew System::Windows::Forms::HScrollBar());
			this->labelk = (gcnew System::Windows::Forms::Label());
			this->labelE = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->vScrollBarZoom = (gcnew System::Windows::Forms::VScrollBar());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->³añcuchJednoatomowyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->³añcuchDwuatomowyToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->drganiaAkustyczneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->drganiaOptyczneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pojedynczaDomieszkaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->warunkiLuŸneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mdM02ToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->warunkiPeriodyczneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mdM05ToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dwieDomieszkiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->warunkiSwobodneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->warunkiPeriodyczneToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->niewychylona3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(204, 33);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(655, 691);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->labelw);
			this->panel1->Controls->Add(this->groupBox3);
			this->panel1->Controls->Add(this->groupBox2);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Controls->Add(this->button0);
			this->panel1->Controls->Add(this->hScrollBark);
			this->panel1->Controls->Add(this->labelk);
			this->panel1->Controls->Add(this->labelE);
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 33);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(204, 711);
			this->panel1->TabIndex = 1;
			// 
			// labelw
			// 
			this->labelw->AutoSize = true;
			this->labelw->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->labelw->Location = System::Drawing::Point(0, 671);
			this->labelw->Name = L"labelw";
			this->labelw->Size = System::Drawing::Size(37, 20);
			this->labelw->TabIndex = 13;
			this->labelw->Text = L"w = ";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->listBox1);
			this->groupBox3->Location = System::Drawing::Point(9, 479);
			this->groupBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox3->Size = System::Drawing::Size(186, 138);
			this->groupBox3->TabIndex = 12;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Wektor falowy";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"q = 0", L"q = 1PI/6a", L"q = 2PI/6a", L"q = 3PI/6a",
					L"q = 4PI/6a", L"q = 5PI/6a", L"q = PI/a"
			});
			this->listBox1->Location = System::Drawing::Point(8, 23);
			this->listBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(172, 104);
			this->listBox1->TabIndex = 11;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButtonP);
			this->groupBox2->Controls->Add(this->radioButtonU);
			this->groupBox2->Controls->Add(this->radioButtonS);
			this->groupBox2->Location = System::Drawing::Point(9, 348);
			this->groupBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Size = System::Drawing::Size(186, 125);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Warunki:";
			// 
			// radioButtonP
			// 
			this->radioButtonP->AutoSize = true;
			this->radioButtonP->Checked = true;
			this->radioButtonP->Location = System::Drawing::Point(8, 86);
			this->radioButtonP->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioButtonP->Name = L"radioButtonP";
			this->radioButtonP->Size = System::Drawing::Size(120, 24);
			this->radioButtonP->TabIndex = 2;
			this->radioButtonP->TabStop = true;
			this->radioButtonP->Text = L"Periodyczne";
			this->radioButtonP->UseVisualStyleBackColor = true;
			this->radioButtonP->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonP_CheckedChanged);
			// 
			// radioButtonU
			// 
			this->radioButtonU->AutoSize = true;
			this->radioButtonU->Location = System::Drawing::Point(8, 56);
			this->radioButtonU->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioButtonU->Name = L"radioButtonU";
			this->radioButtonU->Size = System::Drawing::Size(123, 24);
			this->radioButtonU->TabIndex = 1;
			this->radioButtonU->Text = L"Utwierdzone";
			this->radioButtonU->UseVisualStyleBackColor = true;
			this->radioButtonU->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonU_CheckedChanged);
			// 
			// radioButtonS
			// 
			this->radioButtonS->AutoSize = true;
			this->radioButtonS->Location = System::Drawing::Point(7, 26);
			this->radioButtonS->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioButtonS->Name = L"radioButtonS";
			this->radioButtonS->Size = System::Drawing::Size(110, 24);
			this->radioButtonS->TabIndex = 0;
			this->radioButtonS->Text = L"Swobodne";
			this->radioButtonS->UseVisualStyleBackColor = true;
			this->radioButtonS->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonS_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox1->Controls->Add(this->labeldx);
			this->groupBox1->Controls->Add(this->hScrollBardx);
			this->groupBox1->Controls->Add(this->hScrollBari);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(3, 158);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(195, 182);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Wychylenie";
			// 
			// labeldx
			// 
			this->labeldx->AutoSize = true;
			this->labeldx->Location = System::Drawing::Point(10, 31);
			this->labeldx->Name = L"labeldx";
			this->labeldx->Size = System::Drawing::Size(92, 20);
			this->labeldx->TabIndex = 8;
			this->labeldx->Text = L"i = 0; dx = 0;";
			// 
			// hScrollBardx
			// 
			this->hScrollBardx->Location = System::Drawing::Point(6, 104);
			this->hScrollBardx->Maximum = 24;
			this->hScrollBardx->Minimum = -15;
			this->hScrollBardx->Name = L"hScrollBardx";
			this->hScrollBardx->Size = System::Drawing::Size(186, 24);
			this->hScrollBardx->TabIndex = 7;
			this->hScrollBardx->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBardx_Scroll);
			// 
			// hScrollBari
			// 
			this->hScrollBari->Location = System::Drawing::Point(6, 69);
			this->hScrollBari->Maximum = 1008;
			this->hScrollBari->Name = L"hScrollBari";
			this->hScrollBari->Size = System::Drawing::Size(186, 25);
			this->hScrollBari->TabIndex = 6;
			this->hScrollBari->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBari_Scroll);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(43, 140);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 36);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Wychyl";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button0
			// 
			this->button0->Location = System::Drawing::Point(46, 116);
			this->button0->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button0->Name = L"button0";
			this->button0->Size = System::Drawing::Size(90, 36);
			this->button0->TabIndex = 4;
			this->button0->Text = L"Zeruj";
			this->button0->UseVisualStyleBackColor = true;
			this->button0->Click += gcnew System::EventHandler(this, &MyForm::button0_Click);
			// 
			// hScrollBark
			// 
			this->hScrollBark->Location = System::Drawing::Point(9, 79);
			this->hScrollBark->Maximum = 509;
			this->hScrollBark->Minimum = 10;
			this->hScrollBark->Name = L"hScrollBark";
			this->hScrollBark->Size = System::Drawing::Size(186, 23);
			this->hScrollBark->TabIndex = 3;
			this->hScrollBark->Value = 10;
			this->hScrollBark->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBark_Scroll);
			// 
			// labelk
			// 
			this->labelk->AutoSize = true;
			this->labelk->Location = System::Drawing::Point(9, 49);
			this->labelk->Name = L"labelk";
			this->labelk->Size = System::Drawing::Size(104, 20);
			this->labelk->TabIndex = 2;
			this->labelk->Text = L"k = 0.1 [kN/m]";
			// 
			// labelE
			// 
			this->labelE->AutoSize = true;
			this->labelE->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->labelE->Location = System::Drawing::Point(0, 691);
			this->labelE->Name = L"labelE";
			this->labelE->Size = System::Drawing::Size(42, 20);
			this->labelE->TabIndex = 1;
			this->labelE->Text = L"En =";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(14, 12);
			this->checkBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(111, 24);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"SYMULUJ";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// vScrollBarZoom
			// 
			this->vScrollBarZoom->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->vScrollBarZoom->Dock = System::Windows::Forms::DockStyle::Right;
			this->vScrollBarZoom->LargeChange = 1;
			this->vScrollBarZoom->Location = System::Drawing::Point(859, 33);
			this->vScrollBarZoom->Maximum = 495;
			this->vScrollBarZoom->Name = L"vScrollBarZoom";
			this->vScrollBarZoom->Size = System::Drawing::Size(20, 711);
			this->vScrollBarZoom->TabIndex = 2;
			this->vScrollBarZoom->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::vScrollBarZoom_Scroll);
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->hScrollBar1->Location = System::Drawing::Point(204, 724);
			this->hScrollBar1->Minimum = -100;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(655, 20);
			this->hScrollBar1->TabIndex = 3;
			this->hScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar1_Scroll);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->³añcuchJednoatomowyToolStripMenuItem,
					this->³añcuchDwuatomowyToolStripMenuItem1, this->pojedynczaDomieszkaToolStripMenuItem, this->dwieDomieszkiToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(879, 33);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ³añcuchJednoatomowyToolStripMenuItem
			// 
			this->³añcuchJednoatomowyToolStripMenuItem->Name = L"³añcuchJednoatomowyToolStripMenuItem";
			this->³añcuchJednoatomowyToolStripMenuItem->Size = System::Drawing::Size(212, 29);
			this->³añcuchJednoatomowyToolStripMenuItem->Text = L"£añcuch jednoatomowy";
			this->³añcuchJednoatomowyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::³añcuchJednoatomowyToolStripMenuItem_Click);
			// 
			// ³añcuchDwuatomowyToolStripMenuItem1
			// 
			this->³añcuchDwuatomowyToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->drganiaAkustyczneToolStripMenuItem,
					this->drganiaOptyczneToolStripMenuItem
			});
			this->³añcuchDwuatomowyToolStripMenuItem1->Name = L"³añcuchDwuatomowyToolStripMenuItem1";
			this->³añcuchDwuatomowyToolStripMenuItem1->Size = System::Drawing::Size(201, 29);
			this->³añcuchDwuatomowyToolStripMenuItem1->Text = L"£añcuch dwuatomowy";
			// 
			// drganiaAkustyczneToolStripMenuItem
			// 
			this->drganiaAkustyczneToolStripMenuItem->Name = L"drganiaAkustyczneToolStripMenuItem";
			this->drganiaAkustyczneToolStripMenuItem->Size = System::Drawing::Size(237, 30);
			this->drganiaAkustyczneToolStripMenuItem->Text = L"Drgania akustyczne";
			this->drganiaAkustyczneToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::drganiaAkustyczneToolStripMenuItem_Click);
			// 
			// drganiaOptyczneToolStripMenuItem
			// 
			this->drganiaOptyczneToolStripMenuItem->Name = L"drganiaOptyczneToolStripMenuItem";
			this->drganiaOptyczneToolStripMenuItem->Size = System::Drawing::Size(237, 30);
			this->drganiaOptyczneToolStripMenuItem->Text = L"Drgania optyczne";
			this->drganiaOptyczneToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::drganiaOptyczneToolStripMenuItem_Click);
			// 
			// pojedynczaDomieszkaToolStripMenuItem
			// 
			this->pojedynczaDomieszkaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->warunkiLuŸneToolStripMenuItem,
					this->warunkiPeriodyczneToolStripMenuItem
			});
			this->pojedynczaDomieszkaToolStripMenuItem->Name = L"pojedynczaDomieszkaToolStripMenuItem";
			this->pojedynczaDomieszkaToolStripMenuItem->Size = System::Drawing::Size(203, 29);
			this->pojedynczaDomieszkaToolStripMenuItem->Text = L"Pojedyncza domieszka";
			// 
			// warunkiLuŸneToolStripMenuItem
			// 
			this->warunkiLuŸneToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->mdM02ToolStripMenuItem2,
					this->toolStripMenuItem3
			});
			this->warunkiLuŸneToolStripMenuItem->Name = L"warunkiLuŸneToolStripMenuItem";
			this->warunkiLuŸneToolStripMenuItem->Size = System::Drawing::Size(250, 30);
			this->warunkiLuŸneToolStripMenuItem->Text = L"Warunki luŸne";
			// 
			// mdM02ToolStripMenuItem2
			// 
			this->mdM02ToolStripMenuItem2->Name = L"mdM02ToolStripMenuItem2";
			this->mdM02ToolStripMenuItem2->Size = System::Drawing::Size(174, 30);
			this->mdM02ToolStripMenuItem2->Text = L"Md = 10 M";
			this->mdM02ToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::mdM02ToolStripMenuItem2_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(174, 30);
			this->toolStripMenuItem3->Text = L"Md = 3 M";
			this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem3_Click);
			// 
			// warunkiPeriodyczneToolStripMenuItem
			// 
			this->warunkiPeriodyczneToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripMenuItem2,
					this->mdM05ToolStripMenuItem2
			});
			this->warunkiPeriodyczneToolStripMenuItem->Name = L"warunkiPeriodyczneToolStripMenuItem";
			this->warunkiPeriodyczneToolStripMenuItem->Size = System::Drawing::Size(250, 30);
			this->warunkiPeriodyczneToolStripMenuItem->Text = L"Warunki periodyczne";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(174, 30);
			this->toolStripMenuItem2->Text = L"Md = 10 M";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem2_Click);
			// 
			// mdM05ToolStripMenuItem2
			// 
			this->mdM05ToolStripMenuItem2->Name = L"mdM05ToolStripMenuItem2";
			this->mdM05ToolStripMenuItem2->Size = System::Drawing::Size(174, 30);
			this->mdM05ToolStripMenuItem2->Text = L"Md = 3 M";
			this->mdM05ToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::mdM05ToolStripMenuItem2_Click);
			// 
			// dwieDomieszkiToolStripMenuItem
			// 
			this->dwieDomieszkiToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->warunkiSwobodneToolStripMenuItem,
					this->warunkiPeriodyczneToolStripMenuItem1
			});
			this->dwieDomieszkiToolStripMenuItem->Name = L"dwieDomieszkiToolStripMenuItem";
			this->dwieDomieszkiToolStripMenuItem->Size = System::Drawing::Size(148, 29);
			this->dwieDomieszkiToolStripMenuItem->Text = L"Dwie domieszki";
			// 
			// warunkiSwobodneToolStripMenuItem
			// 
			this->warunkiSwobodneToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripMenuItem4,
					this->toolStripMenuItem5
			});
			this->warunkiSwobodneToolStripMenuItem->Name = L"warunkiSwobodneToolStripMenuItem";
			this->warunkiSwobodneToolStripMenuItem->Size = System::Drawing::Size(250, 30);
			this->warunkiSwobodneToolStripMenuItem->Text = L"Warunki swobodne";
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(169, 30);
			this->toolStripMenuItem4->Text = L"Md = 10M";
			this->toolStripMenuItem4->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem4_Click);
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->Size = System::Drawing::Size(169, 30);
			this->toolStripMenuItem5->Text = L"Md = 3M";
			this->toolStripMenuItem5->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem5_Click);
			// 
			// warunkiPeriodyczneToolStripMenuItem1
			// 
			this->warunkiPeriodyczneToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripMenuItem6,
					this->niewychylona3ToolStripMenuItem
			});
			this->warunkiPeriodyczneToolStripMenuItem1->Name = L"warunkiPeriodyczneToolStripMenuItem1";
			this->warunkiPeriodyczneToolStripMenuItem1->Size = System::Drawing::Size(250, 30);
			this->warunkiPeriodyczneToolStripMenuItem1->Text = L"Warunki periodyczne";
			// 
			// toolStripMenuItem6
			// 
			this->toolStripMenuItem6->Name = L"toolStripMenuItem6";
			this->toolStripMenuItem6->Size = System::Drawing::Size(169, 30);
			this->toolStripMenuItem6->Text = L"Md = 10M";
			this->toolStripMenuItem6->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem6_Click);
			// 
			// niewychylona3ToolStripMenuItem
			// 
			this->niewychylona3ToolStripMenuItem->Name = L"niewychylona3ToolStripMenuItem";
			this->niewychylona3ToolStripMenuItem->Size = System::Drawing::Size(169, 30);
			this->niewychylona3ToolStripMenuItem->Text = L"Md = 3M";
			this->niewychylona3ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::niewychylona3ToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(879, 744);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->hScrollBar1);
			this->Controls->Add(this->vScrollBarZoom);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"Symulacja drgañ grupy atomów";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		
		int t = 0; //do rysowania co 3
		double E; //do obliczania energii
		int wychyli = 0;
		double wychyldx = 0.0;
		double zoom;
		double scroll;
		static char typ; //do zmiany obliczeñ w i du w zale¿noœci od typu drgañ
		const double C = 1.0 / 6.0;	//rk4 const
		static double mi = 1.0;

		//wspolrzedne
		static const double xp = 0, xk = (N+1)*a, yp = -25, yk = 25;
		static double sxp = xp, sxk = xk, syp = yp, syk = yk;
		int ex(double sx){ return int((sx - sxp) / (sxk - sxp)*pictureBox1->Width); }
		int ey(double sy){ return int((syk - sy) / (syk - syp)*pictureBox1->Height); }

		//rysowanie
		array<Point>^points = gcnew array<Point>(N);
		Pen^pioro = gcnew Pen(Color::Gray);
		Pen^pioro2 = gcnew Pen(Color::Red);
		SolidBrush^pedzel = gcnew SolidBrush(Color::Black);

		void En(void)
		{
			E = 0;
			for (int i = 0; i < N; i++)
			{
				E += 0.5*(k*pow(Atom[i].x, 2) + pow(Atom[i].v, 2));
			}
			labelE->Text = L"En = " + E.ToString("F2");
		}

		void UstawAtomy(void)
		{
			for (int i = 0; i < N; i++)
			{
				Atom[i].du = 0.0;
				Atom[i].x = (i + 1)*a;
				Atom[i].v = 0.0;
				Atom[i].m = 2;
				Atom[i].R = 1;
			}
		}

		void Wychyl(int i, double dx)
		{
			Atom[i].du += dx;
		}

		void ZerujK()
		{
			for (int i = 0; i < N; i++)
			{
				kx1[i] = 0;
				kx2[i] = 0;
				kx3[i] = 0;
				kx4[i] = 0;
				kv1[i] = 0;
				kv2[i] = 0;
				kv3[i] = 0;
				kv4[i] = 0;

			}
		}

		void PROM()
		{
			for (int i = 0; i < N; i++)
			{
				Re[i] = 4*ex(Atom[i].R);
			}
		}

		void sta³aSi³owa()
		{
			for (int i = 0; i < N; i++)
			{
				km[i] = k / Atom[i].m;
			}
		}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
				 UstawAtomy();
				 ZerujK();
				 PROM();
				 sta³aSi³owa();
				 hScrollBari->Maximum = N+8;
				 wychyli = N / 2;
				 hScrollBari->Value = wychyli;
				 hScrollBark->Value = k*100;
	}
	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{
				 
				 //uk³ad
				 e->Graphics->DrawLine(pioro, ex(sxp), ey(0.0), ex(sxk), ey(0.0));
				 pioro->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;
				 //siatka for (int i = 1; i <=N; i++) {	e->Graphics->DrawLine(pioro, ex(i*a), ey(syp), ex(i*a), ey(syk)); }

				 //Atomy
				 for (int i = 0; i < N; i++)
				 {
					 e->Graphics->FillEllipse(pedzel, ex(Atom[i].x)-Re[i], ey(0.0) - Re[i], 2*Re[i], 2*Re[i]);
				 }

				 //Wychylenie

				 for (int i = 0; i < N; i++)
				 {
					 points[i].X = ex((i + 1)*a);
					 points[i].Y = ey(Atom[i].du * 100);
					
					 e->Graphics->FillEllipse(pedzel, points[i].X - 1, points[i].Y - 1, 2, 2);
				 }

				 pioro->Color = System::Drawing::Color::Black;
				 if (Atom[0].m == Atom[1].m)
				 {
					 e->Graphics->DrawLines(pioro, points);
				 }
				 else
				 {
					 for (int i = 0; i < N / 2 - 1; i++)
					 {
						 e->Graphics->DrawLine(pioro, points[2 * i], points[2 * i + 2]);
					 }
					 for (int i = 0; i < N/2 - 2; i++)
					 {
						 e->Graphics->DrawLine(pioro2, points[2 * i + 1], points[2 * i + 3]);
					 }
				 }
				 En();

	}
	private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e)
	{
				 pictureBox1->Invalidate();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
				 if (radioButtonP->Checked)/////////////////////////PERIODYCZNE
				 {
					 //pierwszy k1
						 kv1[0] = dt*(km[0]*(Atom[1].du + Atom[N - 1].du - 2 * Atom[0].du));
						 kx1[0] = dt*Atom[0].v;
					 for (int i = 1; i < N - 1; i++)
					 {
						 kv1[i] = dt*(km[i]*(Atom[i + 1].du + Atom[i - 1].du - 2 * Atom[i].du));
						 kx1[i] = dt*Atom[i].v;
					 }
					 //ostatni k1
						 kv1[N - 1] = dt*(km[N-1]*(Atom[0].du + Atom[N - 2].du - 2 * Atom[N - 1].du));
						 kx1[N - 1] = dt*Atom[N - 1].v;
					 //pierwszy k2
						 kv2[0] = dt*(km[0]*((Atom[1].du + kx1[1] * 0.5) + (Atom[N - 1].du + kx1[N - 1] * 0.5) - 2 * (Atom[0].du + kx1[0] * 0.5)));
						 kx2[0] = dt*(Atom[0].v + kv1[0] * 0.5);
					 for (int i = 1; i < N - 1; i++)
					 {
						 kv2[i] = dt*(km[i]*((Atom[i + 1].du + kx1[i + 1] * 0.5) + (Atom[i - 1].du + kx1[i - 1] * 0.5) - 2 * (Atom[i].du + kx1[i] * 0.5)));
						 kx2[i] = dt*(Atom[i].v + kv1[i] * 0.5);
					 }
					 //ostatni k2
						 kv2[N - 1] = dt*(km[N-1]*((Atom[0].du + kx1[0] * 0.5) + (Atom[N - 2].du + kx1[N - 2] * 0.5) - 2 * (Atom[N - 1].du + kx1[N - 1] * 0.5)));
						 kx2[N - 1] = dt*(Atom[N - 1].v + kv1[N - 1] * 0.5);
					 //pierwszy k3
						 kv3[0] = dt*(km[0]*((Atom[1].du + kx2[1] * 0.5) + (Atom[N - 1].du + kx2[N - 1] * 0.5) - 2 * (Atom[0].du + kx2[0] * 0.5)));
						 kx3[0] = dt*(Atom[0].v + kv2[0] * 0.5);
					 for (int i = 1; i < N - 1; i++)
					 {
						 kv3[i] = dt*(km[i]*((Atom[i + 1].du + kx2[i + 1] * 0.5) + (Atom[i - 1].du + kx2[i - 1] * 0.5) - 2 * (Atom[i].du + kx2[i] * 0.5)));
						 kx3[i] = dt*(Atom[i].v + kv2[i] * 0.5);
					 }
					 //ostatni k3
						 kv3[N - 1] = dt*(km[N-1]*((Atom[0].du + kx2[0] * 0.5) + (Atom[N - 2].du + kx2[N - 2] * 0.5) - 2 * (Atom[N - 1].du + kx2[N - 1] * 0.5)));
						 kx3[N - 1] = dt*(Atom[N - 1].v + kv2[N - 1] * 0.5);
					 //pierwszy k4
						 kv4[0] = dt*(km[0]*((Atom[1].du + kx3[1]) + (Atom[N - 1].du + kx3[N - 1]) - 2 * (Atom[0].du + kx3[0])));
						 kx4[0] = dt*(Atom[0].v + kv3[0]);
					 for (int i = 1; i < N - 1; i++)
					 {
						 kv4[i] = dt*(km[i]*((Atom[i + 1].du + kx3[i + 1]) + (Atom[i - 1].du + kx3[i - 1]) - 2 * (Atom[i].du + kx3[i])));
						 kx4[i] = dt*(Atom[i].v + kv3[i]);
					 }
					 //ostatni k4
						 kv4[N - 1] = dt*(km[N-1]*((Atom[0].du + kx3[0]) + (Atom[N - 2].du + kx3[N - 2]) - 2 * (Atom[N - 1].du + kx3[N - 1])));
						 kx4[N - 1] = dt*(Atom[N - 1].v + kv3[N - 1]);

					 //pierwszy
						 Atom[0].v += C*(kv1[0] + 2 * kv2[0] + 2 * kv3[0] + kv4[0]);
						 Atom[0].du += C*(kx1[0] + 2 * kx2[0] + 2 * kx3[0] + kx4[0]);
						 Atom[0].x = a + Atom[0].du;
					 for (int i = 1; i < N - 1; i++)
					 {
						 Atom[i].v += C*(kv1[i] + 2 * kv2[i] + 2 * kv3[i] + kv4[i]);
						 Atom[i].du += C*(kx1[i] + 2 * kx2[i] + 2 * kx3[i] + kx4[i]);
						 Atom[i].x = (i+1)*a + Atom[i].du;
					 }
					 //ostatni
						 Atom[N - 1].v += C*(kv1[N - 1] + 2 * kv2[N - 1] + 2 * kv3[N - 1] + kv4[N - 1]);
						 Atom[N - 1].du += C*(kx1[N - 1] + 2 * kx2[N - 1] + 2 * kx3[N - 1] + kx4[N - 1]);
						 Atom[N - 1].x = N*a + Atom[N - 1].du;
				}
				 else if (radioButtonU->Checked)//////////////////UTWIERDZONE
				 {
					 //pierwszy k1
					 kv1[0] = dt*(km[0]*(Atom[1].du + Atom[N - 1].du - 2 * Atom[0].du));
					 kx1[0] = dt*Atom[0].v;
					 for (int i = 1; i < N - 1; i++)
					 {
						 kv1[i] = dt*(km[i]*(Atom[i + 1].du + Atom[i - 1].du - 2 * Atom[i].du));
						 kx1[i] = dt*Atom[i].v;
					 }
					 //ostatni k1
					 kv1[N - 1] = dt*(km[N-1]*(Atom[0].du + Atom[N - 2].du - 2 * Atom[N - 1].du));
					 kx1[N - 1] = dt*Atom[N - 1].v;
					 //pierwszy k2
					 kv2[0] = dt*(km[0]*((Atom[1].du + kx1[1] * 0.5) + (Atom[N - 1].du + kx1[N - 1] * 0.5) - 2 * (Atom[0].du + kx1[0] * 0.5)));
					 kx2[0] = dt*(Atom[0].v + kv1[0] * 0.5);
					 for (int i = 1; i < N - 1; i++)
					 {
						 kv2[i] = dt*(km[i]*((Atom[i + 1].du + kx1[i + 1] * 0.5) + (Atom[i - 1].du + kx1[i - 1] * 0.5) - 2 * (Atom[i].du + kx1[i] * 0.5)));
						 kx2[i] = dt*(Atom[i].v + kv1[i] * 0.5);
					 }
					 //ostatni k2
					 kv2[N - 1] = dt*(km[N-1]*((Atom[0].du + kx1[0] * 0.5) + (Atom[N - 2].du + kx1[N - 2] * 0.5) - 2 * (Atom[N - 1].du + kx1[N - 1] * 0.5)));
					 kx2[N - 1] = dt*(Atom[N - 1].v + kv1[N - 1] * 0.5);
					 //pierwszy k3
					 kv3[0] = dt*(km[0]*((Atom[1].du + kx2[1] * 0.5) + (Atom[N - 1].du + kx2[N - 1] * 0.5) - 2 * (Atom[0].du + kx2[0] * 0.5)));
					 kx3[0] = dt*(Atom[0].v + kv2[0] * 0.5);
					 for (int i = 1; i < N - 1; i++)
					 {
						 kv3[i] = dt*(km[i]*((Atom[i + 1].du + kx2[i + 1] * 0.5) + (Atom[i - 1].du + kx2[i - 1] * 0.5) - 2 * (Atom[i].du + kx2[i] * 0.5)));
						 kx3[i] = dt*(Atom[i].v + kv2[i] * 0.5);
					 }
					 //ostatni k3
					 kv3[N - 1] = dt*(km[N-1]*((Atom[0].du + kx2[0] * 0.5) + (Atom[N - 2].du + kx2[N - 2] * 0.5) - 2 * (Atom[N - 1].du + kx2[N - 1] * 0.5)));
					 kx3[N - 1] = dt*(Atom[N - 1].v + kv2[N - 1] * 0.5);
					 //pierwszy k4
					 kv4[0] = dt*(km[0]*((Atom[1].du + kx3[1]) + (Atom[N - 1].du + kx3[N - 1]) - 2 * (Atom[0].du + kx3[0])));
					 kx4[0] = dt*(Atom[0].v + kv3[0]);
					 for (int i = 1; i < N - 1; i++)
					 {
						 kv4[i] = dt*(km[i]*((Atom[i + 1].du + kx3[i + 1]) + (Atom[i - 1].du + kx3[i - 1]) - 2 * (Atom[i].du + kx3[i])));
						 kx4[i] = dt*(Atom[i].v + kv3[i]);
					 }
					 //ostatni k4
					 kv4[N - 1] = dt*(km[N-1]*((Atom[0].du + kx3[0]) + (Atom[N - 2].du + kx3[N - 2]) - 2 * (Atom[N - 1].du + kx3[N - 1])));
					 kx4[N - 1] = dt*(Atom[N - 1].v + kv3[N - 1]);

					 //pierwszy = const
					 for (int i = 1; i < N - 1; i++)
					 {
						 Atom[i].v += C*(kv1[i] + 2 * kv2[i] + 2 * kv3[i] + kv4[i]);
						 Atom[i].du += C*(kx1[i] + 2 * kx2[i] + 2 * kx3[i] + kx4[i]);
						 Atom[i].x = (i + 1)*a + Atom[i].du;
					 }
					 //ostatni = const
				 }
				 else /////////////////////////////////////////SWOBODNE
				 {
					 //pierwszy k1
					 kv1[0] = dt*(km[0]*(Atom[1].du - Atom[0].du));
					 kx1[0] = dt*Atom[0].v;
					 for (int i = 1; i < N - 1; i++)
					 {
						 kv1[i] = dt*(km[i]*(Atom[i + 1].du + Atom[i - 1].du - 2 * Atom[i].du));
						 kx1[i] = dt*Atom[i].v;
					 }
					 //ostatni k1
					 kv1[N - 1] = dt*(km[N-1]*(Atom[N - 2].du - Atom[N - 1].du));
					 kx1[N - 1] = dt*Atom[N - 1].v;
					 //pierwszy k2
					 kv2[0] = dt*(km[0]*((Atom[1].du + kx1[1] * 0.5) - (Atom[0].du + kx1[0] * 0.5)));
					 kx2[0] = dt*(Atom[0].v + kv1[0] * 0.5);
					 for (int i = 1; i < N - 1; i++)
					 {
						 kv2[i] = dt*(km[i]*((Atom[i + 1].du + kx1[i + 1] * 0.5) + (Atom[i - 1].du + kx1[i - 1] * 0.5) - 2 * (Atom[i].du + kx1[i] * 0.5)));
						 kx2[i] = dt*(Atom[i].v + kv1[i] * 0.5);
					 }
					 //ostatni k2
					 kv2[N - 1] = dt*(km[N-1]*((Atom[N-2].du + kx1[N-2] * 0.5) - (Atom[N - 1].du + kx1[N - 1] * 0.5)));
					 kx2[N - 1] = dt*(Atom[N - 1].v + kv1[N - 1] * 0.5);
					 //pierwszy k3
					 kv3[0] = dt*(km[0]*((Atom[1].du + kx2[1] * 0.5) - (Atom[0].du + kx2[0] * 0.5)));
					 kx3[0] = dt*(Atom[0].v + kv2[0] * 0.5);
					 for (int i = 1; i < N - 1; i++)
					 {
						 kv3[i] = dt*(km[i]*((Atom[i + 1].du + kx2[i + 1] * 0.5) + (Atom[i - 1].du + kx2[i - 1] * 0.5) - 2 * (Atom[i].du + kx2[i] * 0.5)));
						 kx3[i] = dt*(Atom[i].v + kv2[i] * 0.5);
					 }
					 //ostatni k3
					 kv3[N - 1] = dt*(km[N-1]*((Atom[N-2].du + kx2[N-2] * 0.5) - (Atom[N - 1].du + kx2[N - 1] * 0.5)));
					 kx3[N - 1] = dt*(Atom[N - 1].v + kv2[N - 1] * 0.5);
					 //pierwszy k4
					 kv4[0] = dt*(km[0]*((Atom[1].du + kx3[1]) - (Atom[0].du + kx3[0])));
					 kx4[0] = dt*(Atom[0].v + kv3[0]);
					 for (int i = 1; i < N - 1; i++)
					 {
						 kv4[i] = dt*(km[i]*((Atom[i + 1].du + kx3[i + 1]) + (Atom[i - 1].du + kx3[i - 1]) - 2 * (Atom[i].du + kx3[i])));
						 kx4[i] = dt*(Atom[i].v + kv3[i]);
					 }
					 //ostatni k4
					 kv4[N - 1] = dt*(km[N-1]*((Atom[N-2].du + kx3[N-2]) - (Atom[N - 1].du + kx3[N - 1])));
					 kx4[N - 1] = dt*(Atom[N - 1].v + kv3[N - 1]);

					 //pierwszy
					 Atom[0].v += C*(kv1[0] + 2 * kv2[0] + 2 * kv3[0] + kv4[0]);
					 Atom[0].du += C*(kx1[0] + 2 * kx2[0] + 2 * kx3[0] + kx4[0]);
					 Atom[0].x = a + Atom[0].du;
					 for (int i = 1; i < N - 1; i++)
					 {
						 Atom[i].v += C*(kv1[i] + 2 * kv2[i] + 2 * kv3[i] + kv4[i]);
						 Atom[i].du += C*(kx1[i] + 2 * kx2[i] + 2 * kx3[i] + kx4[i]);
						 Atom[i].x = (i + 1)*a + Atom[i].du;
					 }
					 //ostatni
					 Atom[N - 1].v += C*(kv1[N - 1] + 2 * kv2[N - 1] + 2 * kv3[N - 1] + kv4[N - 1]);
					 Atom[N - 1].du += C*(kx1[N - 1] + 2 * kx2[N - 1] + 2 * kx3[N - 1] + kx4[N - 1]);
					 Atom[N - 1].x = N*a + Atom[N - 1].du;
				 }


				 //rysowanie co 3 kroki
				 t += 100 * dt;
				 if ((t % 9) == 0)
				 {
					 pictureBox1->Invalidate();
				 }
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
				 timer1->Enabled = checkBox1->Checked;
	}
	private: System::Void hScrollBark_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e)
	{
				 k = hScrollBark->Value*0.01;
				 labelk->Text = L"k = " + k.ToString() + " [kN/m]";
	}
	private: System::Void button0_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 UstawAtomy();
				 ZerujK();
	}
	private: System::Void hScrollBari_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e)
	{
				 wychyli = hScrollBari->Value;
				 labeldx->Text = L"i = " + wychyli.ToString() + "; dx = " + wychyldx.ToString("F2") + " [A]";
	}
	private: System::Void hScrollBardx_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e)
	{
				 wychyldx = 0.01*hScrollBardx->Value;
				 labeldx->Text = L"i = " + wychyli.ToString() + "; dx = " + wychyldx.ToString("F2") + " [A]";
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 Wychyl(wychyli, wychyldx);
	}
	private: System::Void vScrollBarZoom_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e)
	{
				 zoom = N*a*(0.001*vScrollBarZoom->Value);
				 sxp = xp + zoom;
				 sxk = xk - zoom;
				 pictureBox1->Invalidate();
	}
	private: System::Void hScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e)
	{
				 scroll = zoom*(0.01*hScrollBar1->Value);
				 sxp = (xp + zoom) + scroll;
				 sxk = (xk - zoom) + scroll;
				 pictureBox1->Invalidate();
	}
	private: System::Void radioButtonS_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
				 timer1->Enabled = false;
				 checkBox1->Checked = false;
				 ZerujK();
				 UstawAtomy();
				 pictureBox1->Invalidate();
	}
private: System::Void radioButtonU_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
				 timer1->Enabled = false;
				 checkBox1->Checked = false;
				 ZerujK();
				 UstawAtomy();
				 pictureBox1->Invalidate();
	}
private: System::Void radioButtonP_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
				 timer1->Enabled = false;
				 checkBox1->Checked = false;
				 ZerujK();
				 UstawAtomy();
				 pictureBox1->Invalidate();
	}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
				 ZerujK();
				 for (int i = 0; i < N; i++)
				 {
					 Atom[i].du = 0.0;
					 Atom[i].x = (i + 1)*a;
					 Atom[i].v = 0.0;
				 }

				 switch (listBox1->SelectedIndex)
				 {
				 case 1:
					 q = Math::PI/(6*a);
					 break;
				 case 2:
					 q = 2* Math::PI/(6*a);
					 break;
				 case 3:
					 q = 3* Math::PI / (6 * a);
					 break;
				 case 4:
					 q = 4* Math::PI / (6 * a);
					 break;
				 case 5:
					 q = 5* Math::PI / (6 * a);
					 break;
				 case 6:
					 q = Math::PI/a;
					 break;
				 default:
					 q = 0;
					 break;
				 }

				 if (Atom[0].m == Atom[1].m)
				 {
					 w = abs(0.7760245*sqrt(4 * k / Atom[0].m)*sin(0.5*q*a)); //0.77602456727327520601*w -> pHz
					 for (int i = 0; i < N; i++)
					 {
						 Atom[i].du = A*cos(i*a*q);
						 Atom[i].v = 0;
					 }
				 }
				 else
				 {
					 if (typ == 'a')
					 {
						 w = abs(0.7760245*sqrt(k*(1. / mi - sqrt(1. / (mi*mi) - 4 * sin(q*a)*sin(q*a) / (Atom[0].m*Atom[1].m))))); //0.77602456727327520601*w -> pHz
						 for (int i = 0; i < N / 2; i++)
						 {
							 Atom[2 * i].du = A*cos(2 * i*a*q);
							 Atom[2 * i + 1].du = A*cos((2 * i + 1)*a*q);
							 Atom[i].v = 0;
						 }
					 }
					 if (typ == 'o')
					 {
						 w = abs(0.7760245*sqrt(k*(1. / mi + sqrt(1. / (mi*mi) - 4 * sin(q*a)*sin(q*a) / (Atom[0].m*Atom[1].m))))); //0.77602456727327520601*w -> pHz
						 for (int i = 0; i < N / 2; i++)
						 {
							 Atom[2*i].du = A*cos((2*i-1)*a*q);
							 Atom[2*i+1].du = - B*cos((2*i)*a*q);
							 Atom[i].v = 0;
						 }
					 }
				 }

				 pictureBox1->Invalidate();

				 labelw->Text = L"w = " + w.ToString("F2") + " [pHz]";
	}

private: System::Void ³añcuchJednoatomowyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
				 timer1->Enabled = false;
				 checkBox1->Checked = false;
				 ZerujK();
				 UstawAtomy();

				 mi = (Atom[0].m*Atom[1].m) / (Atom[0].m + Atom[1].m);

				 PROM();
				 sta³aSi³owa();
				 pictureBox1->Invalidate();
	}
private: System::Void drganiaAkustyczneToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
				 timer1->Enabled = false;
				 checkBox1->Checked = false;
				 ZerujK();
				 UstawAtomy();
				 for (int i = 1; i < N; i += 2)
				 {
					 Atom[i].R = 0.5;
					 Atom[i].m = 1;
				 }
				 mi = Atom[0].m*Atom[1].m / float(Atom[0].m + Atom[1].m);
				 PROM();
				 sta³aSi³owa();
				 typ = 'a';
				 pictureBox1->Invalidate();
	}
private: System::Void drganiaOptyczneToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
				 timer1->Enabled = false;
				 checkBox1->Checked = false;
				 ZerujK();
				 UstawAtomy();
				 for (int i = 1; i < N; i += 2)
				 {
					 Atom[i].R = 0.5;
					 Atom[i].m = 1;
				 }
				 mi = (Atom[0].m*Atom[1].m) / float(Atom[0].m + Atom[1].m);
				 PROM();
				 sta³aSi³owa();
				 typ = 'o';
				 pictureBox1->Invalidate();
	}
private: System::Void mdM02ToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 timer1->Enabled = false;
			 checkBox1->Checked = false;
			 radioButtonS->Checked = true;
			 ZerujK();
			 UstawAtomy();
			 //d1_s10_amp64.open("D:\\studia\\SPEC\\Praca in¿ynierska\\Domieszkowanie\\1domieszka_war_sw\\d1_s10_amp64.csv");
			 d1_s10_amp64.open("d1_s10_amp64.csv");
			 Atom[39].m = 20;
			 Atom[39].R = 2;
			 for (int i = 0; i < N; i++)
			 {
				 string Amp;
				 getline(d1_s10_amp64, Amp);
				 Atom[i].du = stof(Amp)/sqrt(Atom[i].m);
			 }
			 d1_s10_amp64.close();
			 PROM();
			 sta³aSi³owa();
			 labelw->Text = L"w = " + "0.3406" + " [pHz]";
			 pictureBox1->Invalidate();
}
private: System::Void toolStripMenuItem3_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 timer1->Enabled = false;
			 checkBox1->Checked = false;
			 radioButtonS->Checked = true;
			 //d1_s3_amp9.open("D:\\studia\\SPEC\\Praca in¿ynierska\\Domieszkowanie\\1domieszka_war_sw\\d1_s3_amp9.csv");
			 d1_s3_amp9.open("d1_s3_amp9.csv");
			 ZerujK();
			 UstawAtomy();
			 Atom[39].m = 6;
			 Atom[39].R = 3;
			 for (int i = 0; i < N; i++)
			 {
				 string Amp;
				 getline(d1_s3_amp9, Amp);
				 Atom[i].du = stof(Amp) / sqrt(Atom[i].m);
			 }
			 d1_s3_amp9.close();
			 PROM();
			 sta³aSi³owa();
			 labelw->Text = L"w = " + "0.0601" + " [pHz]";
			 pictureBox1->Invalidate();
}
////////////////////////////////////////////periodyczne
private: System::Void mdM05ToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 timer1->Enabled = false;
			 checkBox1->Checked = false;
			 radioButtonP->Checked = true;
			 //d1_wP_s3_amp68.open("D:\\studia\\SPEC\\Praca in¿ynierska\\Domieszkowanie\\1domieszka_war_per\\d1_wP_s3_amp68.csv");
			 d1_wP_s3_amp68.open("d1_wP_s3_amp68.csv");
			 ZerujK();
			 UstawAtomy();
			 Atom[39].m = 6;
			 Atom[39].R = 2;
			 for (int i = 0; i < N; i++)
			 {
				 string Amp;
				 getline(d1_wP_s3_amp68, Amp);
				 Atom[i].du = stof(Amp) / sqrt(Atom[i].m);
			 }
			 PROM();
			 sta³aSi³owa();
			 d1_wP_s3_amp68.close();
			 pictureBox1->Invalidate();
			 labelw->Text = L"w = " + "0.3457" + " [pHz]";
}
private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e)
{
			 timer1->Enabled = false;
			 checkBox1->Checked = false;
			 radioButtonP->Checked = true;
			 //d1_wP_s10_amp63.open("D:\\studia\\SPEC\\Praca in¿ynierska\\Domieszkowanie\\1domieszka_war_per\\d1_wP_s10_amp63.csv");
			 d1_wP_s10_amp63.open("d1_wP_s10_amp63.csv");
			 ZerujK();
			 UstawAtomy();
			 Atom[39].m = 20;
			 Atom[39].R = 2;
			 for (int i = 0; i < N; i++)
			 {
				 string Amp;
				 getline(d1_wP_s10_amp63, Amp);
				 Atom[i].du = stof(Amp) / sqrt(Atom[i].m);
			 }
			 d1_wP_s10_amp63.close();
			 PROM();
			 sta³aSi³owa();
			 pictureBox1->Invalidate();
			 labelw->Text = L"w = " + "0.3404" + " [pHz]";
}
		 ////////////////////2 domieszki
private: System::Void toolStripMenuItem5_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 timer1->Enabled = false;
			 checkBox1->Checked = false;
			 radioButtonS->Checked = true;
			 ZerujK();
			 UstawAtomy();
			 ///////////////////d2_sw.open("D:\\studia\\SPEC\\Praca in¿ynierska\\Domieszkowanie\\2d_war_sw\\d2_s3_amp3.csv");
			 d2_sw.open("d2_s3_amp3.csv");
			 Atom[17].m = 6;
			 Atom[17].R = 2;
			 Atom[53].m = 6;
			 Atom[53].R = 2;
			 for (int i = 0; i < N; i++)
			 {
				 string Amp;
				 getline(d2_sw, Amp);
				 Atom[i].du = stof(Amp) / sqrt(Atom[i].m);
			 }
			 d2_sw.close();
			 PROM();
			 sta³aSi³owa();
			 pictureBox1->Invalidate();
			 labelw->Text = L"w = " + "0.0151" + " [pHz]";
}
private: System::Void toolStripMenuItem4_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 timer1->Enabled = false;
			 checkBox1->Checked = false;
			 radioButtonS->Checked = true;
			 ZerujK();
			 UstawAtomy();
			 //d2_s10_amp65.open("D:\\studia\\SPEC\\Praca in¿ynierska\\Domieszkowanie\\2d_war_sw\\d2_s10_amp65.csv");
			 d2_s10_amp65.open("d2_s10_amp65.csv");
			 Atom[17].m = 20;
			 Atom[17].R = 2;
			 Atom[53].m = 20;
			 Atom[53].R = 2;
			 for (int i = 0; i < N; i++)
			 {
				 string Amp;
				 getline(d2_s10_amp65, Amp);
				 Atom[i].du = stof(Amp) / sqrt(Atom[i].m);
			 }
			 d2_s10_amp65.close();
			 PROM();
			 sta³aSi³owa();
			 pictureBox1->Invalidate();
			 labelw->Text = L"w = " + "0.3415" + " [pHz]"; 

}
/////////////periodyczne
private: System::Void toolStripMenuItem6_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 timer1->Enabled = false;
			 checkBox1->Checked = false;
			 radioButtonP->Checked = true;
			 //d2_wP_s10_amp65.open("D:\\studia\\SPEC\\Praca in¿ynierska\\Domieszkowanie\\2d_war_per\\d2_wP_s10_amp65.csv");
			 d2_wP_s10_amp65.open("d2_wP_s10_amp65.csv");
			 ZerujK();
			 UstawAtomy();
			 Atom[17].m = 20;
			 Atom[17].R = 2;
			 Atom[53].m = 20;
			 Atom[53].R = 2;
			 for (int i = 0; i < N; i++)
			 {
				 string Amp;
				 getline(d2_wP_s10_amp65, Amp);
				 Atom[i].du = stof(Amp) / sqrt(Atom[i].m);
			 }
			 d2_wP_s10_amp65.close();
			 PROM();
			 sta³aSi³owa();
			 labelw->Text = L"w = " + "0.3418" + " [pHz]";
			 pictureBox1->Invalidate();
}
private: System::Void niewychylona3ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 timer1->Enabled = false;
			 checkBox1->Checked = false;
			 radioButtonP->Checked = true;
			 //d2_per.open("D:\\studia\\SPEC\\Praca in¿ynierska\\Domieszkowanie\\2d_war_per\\d2_wP_s3_amp3.csv");
			 d2_per.open("d2_wP_s3_amp3.csv");
			 ZerujK();
			 UstawAtomy();
			 Atom[17].m = 6;
			 Atom[17].R = 2;
			 Atom[53].m = 6;
			 Atom[53].R = 2;
			 for (int i = 0; i < N; i++)
			 {
				 string Amp;
				 getline(d2_per, Amp);
				 Atom[i].du = stof(Amp) / sqrt(Atom[i].m);
			 }
			 d2_per.close();
			 PROM();
			 sta³aSi³owa();
			 labelw->Text = L"w = " + "0.0286" + " [pHz]";
			 pictureBox1->Invalidate();
}
};
}
