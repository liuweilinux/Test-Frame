#pragma once
#include "afxwin.h"
class CMyButton :
	public CButton
{
public:
	CMyButton();
	~CMyButton();

public:
	void SetText(CString str);
	void SetForeColor(COLORREF color);//设置文本颜色
	void SetBkColor(COLORREF color);//设置背景颜色
	void SetTextFont(int FontHight, LPCTSTR FontName);//设置字体

private:
	int m_Style;
	BOOL b_InRect;
	CString m_strText;
	COLORREF m_ForeColor;
	COLORREF m_BackColor;
	COLORREF m_LockForeColor;
	CRect m_ButRect;
	CFont* p_Font;
	void DrawButton(CDC *pDC);
	virtual void PreSubclassWindow();
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

