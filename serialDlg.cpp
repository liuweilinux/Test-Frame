
// serialDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "serial.h"
#include "serialDlg.h"
#include "afxdialogex.h"
#include "MyButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CserialDlg 对话框



CserialDlg::CserialDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SERIAL_DIALOG, pParent)
	, m_edit_receive(_T(""))
	, m_showcheck(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON);
}

void CserialDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_check_serial);
	DDX_Control(pDX, IDC_COMBO2, m_baud_rate);
	DDX_Control(pDX, IDC_MSCOMM1, m_mscomm);
	DDX_Control(pDX, IDC_BUTTON_box1, m_box1);
	DDX_Control(pDX, IDC_BUTTON_box02, m_box2);
	DDX_Control(pDX, IDC_BUTTON_box4, m_box4);
	DDX_Control(pDX, IDC_BUTTON_box5, m_box5);
	DDX_Control(pDX, IDC_BUTTON_box6, m_box6);
	DDX_Control(pDX, IDC_BUTTON_box7, m_box7);
	DDX_Control(pDX, IDC_BUTTON_box8, m_box8);
	DDX_Control(pDX, IDC_BUTTON_box9, m_box9);
	DDX_Control(pDX, IDC_BUTTON_box10, m_box10);
	DDX_Control(pDX, IDC_BUTTON_box11, m_box11);
	DDX_Control(pDX, IDC_BUTTON_box12, m_box12);
	DDX_Control(pDX, IDC_BUTTON_box13, m_box13);
	DDX_Control(pDX, IDC_BUTTON_box14, m_box14);
	DDX_Control(pDX, IDC_BUTTON_box15, m_box15);
	DDX_Control(pDX, IDC_BUTTON_box16, m_box16);
	DDX_Control(pDX, IDC_BUTTON_box17, m_box17);
	DDX_Control(pDX, IDC_BUTTON_box18, m_box18);
	DDX_Control(pDX, IDC_BUTTON_box19, m_box19);
	DDX_Control(pDX, IDC_BUTTON_box20, m_box20);
	DDX_Control(pDX, IDC_CHECK_machine_test, m_machine_test);
	DDX_Control(pDX, IDC_CHECK_frame_test, m_frame_test);
	DDX_Control(pDX, IDC_BUTTON_box3, m_box3);
	DDX_Control(pDX, IDC_BUTTON_box3, m_box3);
}

BEGIN_MESSAGE_MAP(CserialDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Open, &CserialDlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_Clean, &CserialDlg::OnBnClickedButtonClean)
	ON_BN_CLICKED(IDC_BUTTON_Close, &CserialDlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_box02, &CserialDlg::OnBnClickedButtonbox02)
	ON_BN_CLICKED(IDC_BUTTON_box4, &CserialDlg::OnBnClickedButtonbox4)
	ON_BN_CLICKED(IDC_BUTTON_box5, &CserialDlg::OnBnClickedButtonbox5)
	ON_BN_CLICKED(IDC_BUTTON_box6, &CserialDlg::OnBnClickedButtonbox6)
	ON_BN_CLICKED(IDC_BUTTON_box7, &CserialDlg::OnBnClickedButtonbox7)
	ON_BN_CLICKED(IDC_BUTTON_box8, &CserialDlg::OnBnClickedButtonbox8)
	ON_BN_CLICKED(IDC_BUTTON_box9, &CserialDlg::OnBnClickedButtonbox9)
	ON_BN_CLICKED(IDC_BUTTON_box12, &CserialDlg::OnBnClickedButtonbox12)
	ON_BN_CLICKED(IDC_BUTTON_box14, &CserialDlg::OnBnClickedButtonbox14)
	ON_BN_CLICKED(IDC_BUTTON_box13, &CserialDlg::OnBnClickedButtonbox13)
	ON_BN_CLICKED(IDC_BUTTON_box15, &CserialDlg::OnBnClickedButtonbox15)
	ON_BN_CLICKED(IDC_BUTTON_box16, &CserialDlg::OnBnClickedButtonbox16)
	ON_BN_CLICKED(IDC_BUTTON_box17, &CserialDlg::OnBnClickedButtonbox17)
	ON_BN_CLICKED(IDC_BUTTON_box18, &CserialDlg::OnBnClickedButtonbox18)
	ON_BN_CLICKED(IDC_BUTTON_box19, &CserialDlg::OnBnClickedButtonbox19)
	ON_BN_CLICKED(IDC_BUTTON_box20, &CserialDlg::OnBnClickedButtonbox20)
	ON_BN_CLICKED(IDC_BUTTON_box10, &CserialDlg::OnBnClickedButtonbox10)
	ON_BN_CLICKED(IDC_BUTTON_box11, &CserialDlg::OnBnClickedButtonbox11)
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_box1, &CserialDlg::OnBnClickedButtonbox1)
	ON_BN_CLICKED(IDC_BUTTON_box3, &CserialDlg::OnBnClickedButtonbox3)
	ON_BN_CLICKED(IDC_BUTTON_updatestate, &CserialDlg::OnBnClickedButtonupdatestate)
	ON_STN_CLICKED(IDC_STATIC_note, &CserialDlg::OnStnClickedStaticnote)
END_MESSAGE_MAP()


// CserialDlg 消息处理程序

BOOL CserialDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	//::SetWindowPos(this->m_baud_rate, HWND_BOTTOM, 50, 50, 800, 400, SWP_NOZORDER);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	str[1024] = { 0 };

	//m_Font.CreatePointFont(300, _T("华文行楷"), NULL);
	//m_tile.SetFont(&m_Font, true);
	//m_tile.SetWindowTextW("100");
	// TODO: 在此添加额外的初始化代码
	// 串口选择组合框  
	CString str;  int i; 
	for (i = 0; i<15; i++) {
		str.Format(_T("com %d"), i + 1);
		m_check_serial.InsertString(i, str);
	}
	m_check_serial.SetCurSel(0);//预置COM口 

	//波特率选择组合框 
	//CString str1[] = { _T("300"),_T("600"),_T("1200"),_T("2400"),_T("4800"),_T("9600"),_T("19200"),_T("38400"),_T("43000"),_T("56000"),_T("57600"),_T("115200") };
	CString str1[] = {_T("9600"),_T("115200") };
	for (int i = 0; i<2; i++)
	{
		int judge_tf = m_baud_rate.AddString(str1[i]);   
		if ((judge_tf == CB_ERR) || (judge_tf == CB_ERRSPACE))
			MessageBox(_T("build baud error!"));
	}
	m_baud_rate.SetCurSel(1);//预置波特率为"9600"

	for (int i = 0; i < 20;i++)
		showWhiteSmoke(i);

	// x = 380 y = 744
	m_showcheckc.MoveWindow(120, 200, 140, 245);

	m_box20.MoveWindow(50, 50, 40, 40);
	m_box19.MoveWindow(95, 50, 40, 40);
	m_box18.MoveWindow(140, 50, 40, 40);
	m_box17.MoveWindow(185, 50, 40, 40);
	m_box16.MoveWindow(230, 50, 40, 40);
	m_box15.MoveWindow(275, 50, 40, 40);
	m_box14.MoveWindow(320, 50, 40, 40);
	m_box13.MoveWindow(365, 50, 40, 40);
	m_box12.MoveWindow(410, 50, 40, 40);
	m_box11.MoveWindow(455, 50, 40, 40);

	m_box1.MoveWindow(50, 150, 40, 40);
	m_box2.MoveWindow(95, 150, 40, 40);
	m_box3.MoveWindow(140, 150, 40, 40);
	m_box4.MoveWindow(185, 150, 40, 40);
	m_box5.MoveWindow(230, 150, 40, 40);
	m_box6.MoveWindow(275, 150, 40, 40);
	m_box7.MoveWindow(320, 150, 40, 40);
	m_box8.MoveWindow(365, 150, 40, 40);
	m_box9.MoveWindow(410, 150, 40, 40);
	m_box10.MoveWindow(455, 150, 40, 40);
/*
	m_box1text.MoveWindow(50, 91, 40, 20);
	m_box2text.MoveWindow(95, 91, 40, 20);
	m_box3text.MoveWindow(140, 91, 40, 20);
	m_box4text.MoveWindow(185, 91, 40, 20);
	m_box5text.MoveWindow(230, 91, 40, 20);
	m_box6text.MoveWindow(275, 91, 40, 20);
	m_box7text.MoveWindow(320, 91, 40, 20);
	m_box8text.MoveWindow(365, 91, 40, 20);
	m_box9text.MoveWindow(410, 91, 40, 20);
	m_box10text.MoveWindow(455, 91, 40, 20);

	m_box11text.MoveWindow(50, 191, 40, 20);
	m_box12text.MoveWindow(95, 191, 40, 20);
	m_box13text.MoveWindow(140, 191, 40, 20);
	m_box14text.MoveWindow(185, 191, 40, 20);
	m_box15text.MoveWindow(230, 191, 40, 20);
	m_box16text.MoveWindow(275, 191, 40, 20);
	m_box17text.MoveWindow(320, 191, 40, 20);
	m_box18text.MoveWindow(365, 191, 40, 20);
	m_box19text.MoveWindow(410, 191, 40, 20);
	m_box20text.MoveWindow(455, 191, 40, 20);
	*/

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CserialDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CserialDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CRect rect;
		CPaintDC dc(this);
		GetClientRect(rect);
		//dc.FillSolidRect(rect, RGB(108, 123, 139));

		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CserialDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CserialDlg::OnBnClickedButtonOpen()
{
	// TODO: 在此添加控件通知处理程序代码

	CString str, str1, n;
	//定义字符串 
	GetDlgItemText(IDC_BUTTON_Open, str);
	CWnd *h1;
	h1 = GetDlgItem(IDC_BUTTON_Open);
	//指向控件的caption 

	if (!m_mscomm.get_PortOpen()) {
		m_baud_rate.GetLBText(m_baud_rate.GetCurSel(), str1);//取得所选的字符串，并存放在str1里面   
		str1=str1+','+'n'+','+'8'+','+'1';   //这句话很关键 

		m_mscomm.put_CommPort((m_check_serial.GetCurSel() + 1)); //选择串口   
		m_mscomm.put_InputMode(1);   //设置输入方式为二进制方式 
		m_mscomm.put_Settings(str1);  //波特率为（波特率组?合框）无校验，8数据位，1个停止位

		m_mscomm.put_InputLen(11);  //设置当前接收区数据长度为1024   
		m_mscomm.put_InBufferSize(1024);

		m_mscomm.put_OutBufferSize(512);

		m_mscomm.put_RThreshold(11);   //缓冲区一个字符引发事件   
		m_mscomm.put_RTSEnable(1);   

							 //设置RT允许 
		m_mscomm.put_PortOpen(true);
		//打开串口 

		check = m_machine_test.GetCheck();
		frame_check = m_frame_test.GetCheck();

		if (check && !frame_check)
		{
			m_mscomm.put_RThreshold(1);   //缓冲区一个字符引发事件 
			boxnum = 0;
			SetTimer(2, 1500, NULL);
			//OnBnClickedButtonbox1();
		}

		if (frame_check && !check)
		{
			flag = 1;
			framestate = 0;
			boxno = 0;

			SetTimer(1, 80, NULL);

		}

		if (m_mscomm.get_PortOpen()) {

			str = _T("结束测试");
			UpdateData(true);
			h1->SetWindowText(str);   //改变按钮名称为‘’关闭串口” 
		}
	}
	else {
		m_mscomm.put_PortOpen(false); 

		if (check)
		{
			check = 0;
			KillTimer(2);
			KillTimer(3);
		}
		if (frame_check)
		{
			frame_check = 0;
			KillTimer(1);
		}
		if (str != _T("开始测试"))   
		{    
			str=_T("开始测试");    
			UpdateData(true);    
			h1->SetWindowText(str); 
			//改变按钮名称为打开串口
		}
	}
}

DWORD WINAPI ListenThreadFunc()
{
	//CserialDlg *pDlg = (CserialDlg *)lpParameter;

	int i = 0;
	while(TRUE)
	{
		TRACE("theadbox: %d\n", i++);

		Sleep(20);
	}
}

UINT CserialDlg::ThreadFunc(LPVOID pParam)
{
	CserialDlg *pMy = (CserialDlg *)pParam;

	//threadInfo* pInfo = (threadInfo*)serial;

	if (pMy->threadbox >= 20)
		pMy->threadbox = 0;
	while (pMy->threadbox < 20)
	{
		pMy->get_state(pMy->threadbox++);

		TRACE("tread; %d\n", pMy->threadbox);

		Sleep(20);
	};
	return 0;
}

void CserialDlg::OnBnClickedButtonClean()
{
	// TODO: 在此添加控件通知处理程序代码

	m_edit_receive = _T(""); //给接收编辑框发送空格符  
	UpdateData(false); //更新数据 
}


void CserialDlg::OnBnClickedButtonClose()
{
	// TODO: 在此添加控件通知处理程序代码

	if (m_mscomm.get_PortOpen())
		m_mscomm.put_PortOpen(false);  
	CDialogEx::OnCancel();
}
BEGIN_EVENTSINK_MAP(CserialDlg, CDialogEx)
	ON_EVENT(CserialDlg, IDC_MSCOMM1, 1, CserialDlg::OnCommMscomm1, VTS_NONE)
END_EVENTSINK_MAP()


void CserialDlg::OnCommMscomm1()
{
	// TODO: 在此处添加消息处理程序代码

	if (m_mscomm.get_CommEvent() == 2) {
		long k;
		VARIANT InputData = m_mscomm.get_Input(); //读缓冲区 

		COleSafeArray fs;
		fs = InputData; //VARIANT型变?量转换为COleSafeArray型变量   

	//	TRACE("GETlen: %s\n",m_mscomm.get_Input());
	//	TRACE("LEN: %d\n", fs.GetOneDimSize());

		for (k = 0; k < fs.GetOneDimSize(); k++)
			fs.GetElement(&k, str + k); //转换为BYTE型数组

		m_edit_receive += str;      // 接收到编辑框里面  

		if (m_edit_receive.Compare(_T("done")) != -1)
		{
			m_edit_receive = _T("");
			str[11] = { 0 };

			if (frame_check)
				SetTimer(1, 80, NULL);
			if (check)
			{
				SetTimer(3, 100, NULL);
			}
		}

		if (str[0] == 'H' && str[1] == 'H' && str[2] == 'L' && str[3] == 'N')
		{
			TRACE("str[6]boxno--------------------- %d\n", str[6]);


			char CHK = 0;

			for (int i = 5; i < 10; i++)
			{
				CHK = (CHK ^ (str[i]));
			}

			if (CHK == str[10])
			{
				if (str[9] == 0)
				{
					state = 1;
		
					if (frame_check)
					{
						showboxno = str[6];
						str[11] = { 0 };

						KillTimer(1);
						open_box(showboxno);

						showblue(showboxno);
					}

					if (check)
						showblue(str[6]);
				}
				else
				{
					state = 0;
					if(check)
						showred(str[6]);
				}
			}
			m_edit_receive = _T("");
			str[11] = { 0 };

		}

		m_edit_receive = _T("");
		str[20] = { 0 };

		UpdateData(false);
	}
}

/*
void CserialDlg::shownormaltext()
{
	CString cStr;

	if (0 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box1text.SetWindowText(lpctStr);
		m_box1text.ShowWindow(SW_SHOW);

	}
	if (1 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box2text.SetWindowText(lpctStr);
		m_box2text.ShowWindow(SW_SHOW);

	}
	if (2 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box3text.SetWindowText(lpctStr);
		m_box3text.ShowWindow(SW_SHOW);

	}
	if (3 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box4text.SetWindowText(lpctStr);
		m_box4text.ShowWindow(SW_SHOW);

	}
	if (4 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box5text.SetWindowText(lpctStr);
		m_box5text.ShowWindow(SW_SHOW);

	}
	if (5 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box6text.SetWindowText(lpctStr);
		m_box6text.ShowWindow(SW_SHOW);

	}
	if (6 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box7text.SetWindowText(lpctStr);
		m_box7text.ShowWindow(SW_SHOW);

	}
	if (7 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box8text.SetWindowText(lpctStr);
		m_box8text.ShowWindow(SW_SHOW);

	}
	if (8 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box9text.SetWindowText(lpctStr);
		m_box9text.ShowWindow(SW_SHOW);

	}
	if (9 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box10text.SetWindowText(lpctStr);
		m_box10text.ShowWindow(SW_SHOW);

	}
	if (10 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box11text.SetWindowText(lpctStr);
		m_box11text.ShowWindow(SW_SHOW);

	}
	if (11 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box12text.SetWindowText(lpctStr);
		m_box12text.ShowWindow(SW_SHOW);

	}
	if (12 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box13text.SetWindowText(lpctStr);
		m_box13text.ShowWindow(SW_SHOW);

	}
	if (13 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box14text.SetWindowText(lpctStr);
		m_box14text.ShowWindow(SW_SHOW);

	}
	if (14 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box15text.SetWindowText(lpctStr);
		m_box15text.ShowWindow(SW_SHOW);

	}
	if (15 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box16text.SetWindowText(lpctStr);
		m_box16text.ShowWindow(SW_SHOW);

	}
	if (16 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box17text.SetWindowText(lpctStr);
		m_box17text.ShowWindow(SW_SHOW);

	}
	if (17 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box18text.SetWindowText(lpctStr);
		m_box18text.ShowWindow(SW_SHOW);

	}
	if (18 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box19text.SetWindowText(lpctStr);
		m_box19text.ShowWindow(SW_SHOW);

	}
	if (19 == showboxno)
	{
		cStr += "正常";

		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_box20text.SetWindowText(lpctStr);
		m_box20text.ShowWindow(SW_SHOW);

	}
}*/
void CserialDlg::select_open_close()
{
	if (check)
	{

		if (1 == state)
		{
			KillTimer(3);

			//showblue(boxnum);
		}
		else
		{
		//	showred();
		}
	}

	if (frame_check)
	{
		//TRACE("boxno: %d\n", showboxno);
		if (1 == state)
		{
			//showblue();
		}
		else;
			//showred();
	}
}

void CserialDlg::showblue(int showboxno)
{
	if (0 == showboxno)
		m_box1.SetBkColor(RGB(0, 200, 255));
	if (1 == showboxno)
		m_box2.SetBkColor(RGB(0, 200, 255));
	if (2 == showboxno)
		m_box3.SetBkColor(RGB(0, 200, 255));
	if (3 == showboxno)
		m_box4.SetBkColor(RGB(0, 200, 255));
	if (4 == showboxno)
		m_box5.SetBkColor(RGB(0, 200, 255));
	if (5 == showboxno)
		m_box6.SetBkColor(RGB(0, 200, 255));
	if (6 == showboxno)
		m_box7.SetBkColor(RGB(0, 200, 255));
	if (7 == showboxno)
		m_box8.SetBkColor(RGB(0, 200, 255));
	if (8 == showboxno)
		m_box9.SetBkColor(RGB(0, 200, 255));
	if (9 == showboxno)
		m_box10.SetBkColor(RGB(0, 200, 255));
	if (10 == showboxno)
		m_box11.SetBkColor(RGB(0, 200, 255));
	if (11 == showboxno)
		m_box12.SetBkColor(RGB(0, 200, 255));
	if (12 == showboxno)
		m_box13.SetBkColor(RGB(0, 200, 255));
	if (13 == showboxno)
		m_box14.SetBkColor(RGB(0, 200, 255));
	if (14 == showboxno)
		m_box15.SetBkColor(RGB(0, 200, 255));
	if (15 == showboxno)
		m_box16.SetBkColor(RGB(0, 200, 255));
	if (16 == showboxno)
		m_box17.SetBkColor(RGB(0, 200, 255));
	if (17 == showboxno)
		m_box18.SetBkColor(RGB(0, 200, 255));
	if (18 == showboxno)
		m_box19.SetBkColor(RGB(0, 200, 255));
	if (19 == showboxno)
		m_box20.SetBkColor(RGB(0, 200, 255));

	str[1024] = { 0 };
}

void CserialDlg::showred(int showboxno)
{
	if (0 == showboxno)
		m_box1.SetBkColor(RGB(198, 25, 32));
	if (1 == showboxno)
		m_box2.SetBkColor(RGB(198, 25, 32));
	if (2 == showboxno)
		m_box3.SetBkColor(RGB(198, 25, 32));
	if (3 == showboxno)
		m_box4.SetBkColor(RGB(198, 25, 32));
	if (4 == showboxno)
		m_box5.SetBkColor(RGB(198, 25, 32));
	if (5 == showboxno)
		m_box6.SetBkColor(RGB(198, 25, 32));
	if (6 == showboxno)
		m_box7.SetBkColor(RGB(198, 25, 32));
	if (7 == showboxno)
		m_box8.SetBkColor(RGB(198, 25, 32));
	if (8 == showboxno)
		m_box9.SetBkColor(RGB(198, 25, 32));
	if (9 == showboxno)
		m_box10.SetBkColor(RGB(198, 25, 32));
	if (10 == showboxno)
		m_box11.SetBkColor(RGB(198, 25, 32));
	if (11 == showboxno)
		m_box12.SetBkColor(RGB(198, 25, 32));
	if (12 == showboxno)
		m_box13.SetBkColor(RGB(198, 25, 32));
	if (13 == showboxno)
		m_box14.SetBkColor(RGB(198, 25, 32));
	if (14 == showboxno)
		m_box15.SetBkColor(RGB(198, 25, 32));
	if (15 == showboxno)
		m_box16.SetBkColor(RGB(198, 25, 32));
	if (16 == showboxno)
		m_box17.SetBkColor(RGB(198, 25, 32));
	if (17 == showboxno)
		m_box18.SetBkColor(RGB(198, 25, 32));
	if (18 == showboxno)
		m_box19.SetBkColor(RGB(198, 25, 32));
	if (19 == showboxno)
		m_box20.SetBkColor(RGB(198, 25, 32));

	//if (frame_check)
	//	SetTimer(1, 100, NULL);
}

void CserialDlg::showWhiteSmoke(int boxno)
{
	if (0 == boxno)
		m_box1.SetBkColor(RGB(245, 245, 245));
	if (1 == boxno)
		m_box2.SetBkColor(RGB(245, 245, 245));
	if (2 == boxno)
		m_box3.SetBkColor(RGB(245, 245, 245));
	if (3 == boxno)
		m_box4.SetBkColor(RGB(245, 245, 245));
	if (4 == boxno)
		m_box5.SetBkColor(RGB(245, 245, 245));
	if (5 == boxno)
		m_box6.SetBkColor(RGB(245, 245, 245));
	if (6 == boxno)
		m_box7.SetBkColor(RGB(245, 245, 245));
	if (7 == boxno)
		m_box8.SetBkColor(RGB(245, 245, 245));
	if (8 == boxno)
		m_box9.SetBkColor(RGB(245, 245, 245));
	if (9 == boxno)
		m_box10.SetBkColor(RGB(245, 245, 245));
	if (10 == boxno)
		m_box11.SetBkColor(RGB(245, 245, 245));
	if (11 == boxno)
		m_box12.SetBkColor(RGB(245, 245, 245));
	if (12 == boxno)
		m_box13.SetBkColor(RGB(245, 245, 245));
	if (13 == boxno)
		m_box14.SetBkColor(RGB(245, 245, 245));
	if (14 == boxno)
		m_box15.SetBkColor(RGB(245, 245, 245));
	if (15 == boxno)
		m_box16.SetBkColor(RGB(245, 245, 245));
	if (16 == boxno)
		m_box17.SetBkColor(RGB(245, 245, 245));
	if (17 == boxno)
		m_box18.SetBkColor(RGB(245, 245, 245));
	if (18 == boxno)
		m_box19.SetBkColor(RGB(245, 245, 245));
	if (19 == boxno)
		m_box20.SetBkColor(RGB(245, 245, 245));

	//if (frame_check)
	//	SetTimer(1, 100, NULL);
}

int CserialDlg::String2Hex(CString str, CByteArray &senddata)
{
	int hexdata, lowhexdata;
	int hexdatalen = 0;
	int len = str.GetLength();
	senddata.SetSize(len / 2);
	for (int i = 0; i<len;)
	{
		char lstr, hstr = str[i];
		if (hstr == ' ')
		{
			i++;
			continue;
		}
		i++;
		if (i >= len)
			break;
		lstr = str[i];
		hexdata = ConvertHexChar(hstr);
		lowhexdata = ConvertHexChar(lstr);
		if ((hexdata == 16) || (lowhexdata == 16))
			break;
		else
			hexdata = hexdata * 16 + lowhexdata;
		i++;
		senddata[hexdatalen] = (char)hexdata;
		hexdatalen++;
	}
	senddata.SetSize(hexdatalen);
	return hexdatalen;
}  

int CserialDlg::char2Hex(char* str, CByteArray &senddata,int len)
{
	int hexdata, lowhexdata;
	int hexdatalen = 0;
	//int len = str.length();
	//int len = str.GetLength();
	senddata.SetSize(len / 2);
	for (int i = 0; i<len;)
	{
		char lstr, hstr = str[i];
		if (hstr == ' ')
		{
			i++;
			continue;
		}
		i++;
		if (i >= len)
			break;
		char sum[1];
		char buf[1];
		int index = 0;
		char val = str[i];
		while (val > 0)
		{
			sum[index] = val % 16;
			val /= 16;
			index++;
		}
		int icount = 0;
		while (index--)
		{
			if (sum[index] > 9)
			{
				buf[icount] = sum[index] + 55;
			}
			else
			{
				buf[icount] = sum[index] + 48;
			}
			icount++;
		}
		lstr = buf[i];
		hexdata = ConvertHexChar(hstr);
		lowhexdata = ConvertHexChar(lstr);
		if ((hexdata == 16) || (lowhexdata == 16))
			break;
		else
			hexdata = hexdata * 16 + lowhexdata;
		i++;
		senddata[hexdatalen] = (char)hexdata;
		hexdatalen++;
	}
	senddata.SetSize(hexdatalen);
	return hexdatalen;
}

char CserialDlg::ConvertHexChar(char ch)
{
	if ((ch >= '0') && (ch <= '9'))
		return ch - 0x30;
	else if ((ch >= 'A') && (ch <= 'F'))
		return ch - 'A' + 10;
	else if ((ch >= 'a') && (ch <= 'f'))
		return ch - 'a' + 10;
	else return (-1);
}


int CserialDlg::getDoorStatus()
{
	CByteArray hexdata;
	CString a = _T("48 48 4C 4E 05 F3 01 00 00 00 F5");
	int len = String2Hex(a, hexdata);
	//int len = String2Hex(m_edit_send, hexdata); //此处返回的len可以用于计算发送了多少个十六进制数  
	m_mscomm.put_Output(COleVariant(hexdata)); //发送十六进制数据 
	
	return 0;
}

void CserialDlg::OnBnClickedButtonbox02()
{
	boxno = 1;
	if(check)
	open_box(boxno);
}

void CserialDlg::OnBnClickedButtonbox4()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 3;
	if (check)
	open_box(boxno);
}


void CserialDlg::OnBnClickedButtonbox5()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 4;
	if (check)
	open_box(boxno);
}


void CserialDlg::OnBnClickedButtonbox6()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 5;
	if (check)
	open_box(boxno);
}


void CserialDlg::OnBnClickedButtonbox7()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 6;
	if (check)
	open_box(boxno);
}


void CserialDlg::OnBnClickedButtonbox8()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 7;
	if (check)
	open_box(boxno);
}


void CserialDlg::OnBnClickedButtonbox9()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 8;
	if (check)
	open_box(boxno);
}


void CserialDlg::OnBnClickedButtonbox12()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 11;
	if (check)
	open_box(boxno);
}


void CserialDlg::OnBnClickedButtonbox14()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 13;
	if (check)
	open_box(boxno);
}


void CserialDlg::OnBnClickedButtonbox13()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 12;

	if (check)
	open_box(boxno);
}


void CserialDlg::OnBnClickedButtonbox15()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 14;
	if (check)
	open_box(boxno);
}


void CserialDlg::OnBnClickedButtonbox16()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 15;
	if (check)
	open_box(boxno);
}


void CserialDlg::OnBnClickedButtonbox17()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	boxno = 16;
	if (check)
	open_box(boxno);
}


void CserialDlg::OnBnClickedButtonbox18()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 17;
	if (check)
	open_box(boxno);
}

void CserialDlg::OnBnClickedButtonbox19()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 18;
	if (check)
	open_box(boxno);
}


void CserialDlg::OnBnClickedButtonbox20()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 19;
	if (check)
	open_box(boxno);
}

void CserialDlg::OnBnClickedButtonbox10()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 9;
	if (check)
	open_box(boxno);
}

void CserialDlg::OnBnClickedButtonbox11()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 10;
	if (check)
	open_box(boxno);
}

void CserialDlg::open_box(int boxno)
{
	str[20] = { 0 };

	//if(check)
	m_mscomm.put_InputLen(6);
	m_mscomm.put_RThreshold(6);

//	TRACE("open boxno: %d\n", boxno);
	UpdateData(true);
	//更新控件数据 
	CByteArray hexdata;

	hexdata.Add(0x48);
	hexdata.Add(0x48);
	hexdata.Add(0x4C);
	hexdata.Add(0x4E);
	hexdata.Add(0x05);
	hexdata.Add(0xF4);
	hexdata.Add(boxno);
	hexdata.Add(0x00);
	hexdata.Add(0x00);
	hexdata.Add(0x00);
	hexdata.Add(0x44);
	hexdata[10] = hexdata[5] ^ hexdata[6] ^ hexdata[7] ^ hexdata[8] ^ hexdata[9];
	m_mscomm.put_Output(COleVariant(hexdata)); //发送十六进制数据
	if (check)
	{
		SetTimer(2, 1000, NULL);
	}
}

void CserialDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	switch (nIDEvent)
	{
		case 1:
		if (boxno >= 20)
			boxno = 0;

		get_state(boxno++);
		
		//TRACE("tiemboxno: %d\n", boxno);

		break;
	case 2:
		Chekall();
		break;
	case 3:
		get_state(boxnum-1);
	case 4:
		//select_open_close();
	//	showblue();
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}

void CserialDlg::get_state(int boxno)
{
	str[20] = { 0 };

	//if(check)
	m_mscomm.put_InputLen(11);
	m_mscomm.put_RThreshold(11);

	UpdateData(true);
	//更新控件数据 
	CByteArray hexdata;
	TRACE("get_state%d\n", boxno);
	hexdata.Add(0x48);
	hexdata.Add(0x48);
	hexdata.Add(0x4C);
	hexdata.Add(0x4E);
	hexdata.Add(0x05);
	hexdata.Add(0xF3);
	hexdata.Add(boxno);
	hexdata.Add(0x00);
	hexdata.Add(0x00);
	hexdata.Add(0x00);
	hexdata.Add(0x44);
	hexdata[10] = hexdata[5] ^ hexdata[6] ^ hexdata[7] ^ hexdata[8] ^ hexdata[9];
	m_mscomm.put_Output(COleVariant(hexdata)); //发送十六进制数据

//	if (check)
//		KillTimer(3);
}

void CserialDlg::Chekall()
{
	// TODO: 在此添加控件通知处理程序代码
/*	if (boxno >= 20)
	{
		boxno = 0;
		KillTimer(2);
		KillTimer(3);

		CString cStr;
		cStr = "sfsdf";
		LPCTSTR lpctStr = (LPCTSTR)cStr;
		m_showcheckc.SetWindowText(lpctStr);
		m_showcheckc.ShowWindow(SW_SHOW);

		CString str;
		GetDlgItemText(IDC_BUTTON_Open, str);
		CWnd *h1;
		h1 = GetDlgItem(IDC_BUTTON_Open);

		//m_mscomm.put_PortOpen(false);
		if (str != _T("开始测试"))
		{
			str = _T("开始测试");
			UpdateData(true);
			h1->SetWindowText(str);
			//改变按钮名称为打开串口 
		}
	}
	else
	{*/
		KillTimer(2);
		open_box(boxnum++);
		Sleep(50);
//	}
}

void CserialDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	TRACE("cx %d cy %d\n", cx, cy);

	if (nType == 1) return;//最小化则什么都不做  
	 // TODO: Add your message handler code here  
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_STATIC);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_STATIC_title);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box1);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box02);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box3);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box4);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box5);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box6);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box7);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box8);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box9);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box10);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box11);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box12);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box13);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box14);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box15);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box16);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box17);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box18);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box19);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_box20);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_STATIC_note);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_STATIC_baud);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_COMBO1);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_COMBO2);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_CHECK_frame_test);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_CHECK_machine_test);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_updatestate);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_Open);
	ChangeSIZE(pWnd, cx, cy);
	pWnd = GetDlgItem(IDC_BUTTON_Close);
	ChangeSIZE(pWnd, cx, cy);

	GetClientRect(&m_rect);// 将变化后的对话框大小设为旧大小     
}

void CserialDlg::ChangeSIZE(CWnd * pWnd, int cx, int cy)
{
	if (pWnd)  //判断是否为空，因为对话框创建时会调用此函数，而当时控件还未创建   
	{
		CRect rect;   //获取控件变化前的大小    
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);//将控件大小转换为在对话框中的区域坐标  
		//cx / m_rect.Width(); //为对话框在横向的变化比例
		rect.left = rect.left*cx / m_rect.Width();//调整控件大小  
		rect.right = rect.right*cx / m_rect.Width();
		rect.top = rect.top*cy / m_rect.Height();
		rect.bottom = rect.bottom*cy / m_rect.Height();
		pWnd->MoveWindow(rect);//设置控件大小  
	}
}

void CserialDlg::OnBnClickedButtonbox1()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 0;
	if (check)
	open_box(boxno);
}

/*
void CserialDlg::OnBnClickedButtonbox03()
{
	boxno = 2;
	if (check)
	open_box(boxno);
}*/


int CserialDlg::auto_set_serial()
{

	return 0;
}


void CserialDlg::OnBnClickedButtonbox3()
{
	// TODO: 在此添加控件通知处理程序代码
	boxno = 2;
	if (check)
		open_box(boxno);
}


void CserialDlg::OnStnClickedStatictestreport()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CserialDlg::OnBnClickedButtonupdatestate()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < 20;i++)
		showWhiteSmoke(i);
}


void CserialDlg::OnStnClickedStaticnote()
{
	// TODO: 在此添加控件通知处理程序代码
}
