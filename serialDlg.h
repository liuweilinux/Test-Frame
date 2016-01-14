
// serialDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "mscomm1.h"
#include "MyButton.h"

// CserialDlg 对话框

//UINT ThreadFunc(LPVOID pParam);
//DWORD WINAPI ListenThreadFunc(LPVOID lpParameter);

class CserialDlg : public CDialogEx
{
// 构造
public:
	CserialDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERIAL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CWinThread* pThread;
	
	//void get_state(int boxno);
private:
	CString m_edit_receive;
	CString m_edit_receive2;
	CComboBox m_check_serial;
	CComboBox m_baud_rate;
	CFont m_Font;
	CRect m_rect;

public:
	CMscomm1 m_mscomm;
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonClean();
	afx_msg void OnBnClickedButtonClose();
	DECLARE_EVENTSINK_MAP()
	void OnCommMscomm1();
	int String2Hex(CString str, CByteArray &senddata);
	int char2Hex(char* str, CByteArray &senddata,int a);
	char ConvertHexChar(char );
	int getDoorStatus();
	CButton m_ctrlHexSend;
	afx_msg void OnBnClickedButtonbox02();
	CMyButton m_box2;
	char boxnostate[2];
	afx_msg void OnBnClickedButtonbox4();
	afx_msg void OnBnClickedButtonbox5();
	afx_msg void OnBnClickedButtonbox6();
	afx_msg void OnBnClickedButtonbox7();
	afx_msg void OnBnClickedButtonbox8();
	afx_msg void OnBnClickedButtonbox9();
	CMyButton m_box4;
	CMyButton m_box5;
	CMyButton m_box6;
	CMyButton m_box7;
	CMyButton m_box8;
	CMyButton m_box9;
	CMyButton m_box10;
	CMyButton m_box11;
	CMyButton m_box12;
	CMyButton m_box13;
	afx_msg void OnBnClickedButtonbox12();
	CMyButton m_box14;
	CMyButton m_box15;
	CMyButton m_box16;
	CMyButton m_box17;
	CMyButton m_box18;
	CMyButton m_box19;
	CMyButton m_box20;
	afx_msg void OnBnClickedButtonbox14();
	afx_msg void OnBnClickedButtonbox13();
	afx_msg void OnBnClickedButtonbox15();
	afx_msg void OnBnClickedButtonbox16();
	afx_msg void OnBnClickedButtonbox17();
	afx_msg void OnBnClickedButtonbox18();
	afx_msg void OnBnClickedButtonbox19();
	afx_msg void OnBnClickedButtonbox20();
	afx_msg void OnBnClickedButtonbox10();
	afx_msg void OnBnClickedButtonbox11();
	void open_box(int boxno);
	char str[1024] = { 0 };
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void get_state(int boxno);
	int state;
	int openbox;
    int boxno;
	int check;
	int frame_check;
	void Chekall();
	void select_open_close();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void ChangeSIZE(CWnd * pWnd, int cx, int cy);
	afx_msg void OnBnClickedButtonbox1();
	CMyButton m_box1;
	int auto_set_serial();
	CString m_showcheck;
	CStatic m_showcheckc;
	CButton m_machine_test;
	CButton m_frame_test;
	afx_msg void OnBnClickedButtonbox3();
	CMyButton m_box3;
	void showred(int boxno);
	int state1[20];
	int state2[20];
	int comparestate[20];
	int flag;
	int framestate;
	void showblue(int boxno);
	int showboxno =23;
	int num;
	int test[1024] = { 0 };

	int filter;
	
	afx_msg void OnStnClickedStatictestreport();

	CStatic m_box1text;
	CStatic m_box2text;
	CStatic m_box3text;
	CStatic m_box4text;
	CStatic m_box5text;
	CStatic m_box6text;
	CStatic m_box7text;
	CStatic m_box8text;
	CStatic m_box9text;
	CStatic m_box10text;
	CStatic m_box11text;
	CStatic m_box12text;
	CStatic m_box13text;
	CStatic m_box14text;
	CStatic m_box15text;
	CStatic m_box16text;
	CStatic m_box17text;
	CStatic m_box18text;
	CStatic m_box19text;
	CStatic m_box20text;
	static DWORD WINAPI ListenThreadFunc();
	static UINT ThreadFunc(LPVOID pParam);
	void shownormaltext();
	void showWhiteSmoke(int boxno);
	int threadbox;
	afx_msg void OnBnClickedButtonupdatestate();
	afx_msg void OnStnClickedStaticnote();
	int boxnum;
};

struct threadInfo
{
	CProgressCtrl* pctrlProgress;
};