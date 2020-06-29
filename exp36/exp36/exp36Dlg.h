
// exp36Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// Cexp36Dlg 对话框
class Cexp36Dlg : public CDialogEx
{
// 构造
public:
	Cexp36Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EXP36_DIALOG };

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
public:
	CString change;
	CListBox student;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLbnSelchangeList1();
	int index;
	CString filename;
	afx_msg void OnBnClickedButton2();
};
