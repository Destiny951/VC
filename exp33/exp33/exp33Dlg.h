
// exp33Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// Cexp33Dlg �Ի���
class Cexp33Dlg : public CDialogEx
{
// ����
public:
	Cexp33Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXP33_DIALOG };

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
	double a;
	double b;
	double c;
	CComboBox select;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
};
