
// exp36Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// Cexp36Dlg �Ի���
class Cexp36Dlg : public CDialogEx
{
// ����
public:
	Cexp36Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXP36_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
