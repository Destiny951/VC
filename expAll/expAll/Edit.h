#pragma once


// Edit �Ի���

class Edit : public CDialogEx
{
	DECLARE_DYNAMIC(Edit)

public:
	Edit(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Edit();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString number;
	CString major;
	CString sex;
	CString birth;
	CString phone;
	CString address;
	CString picture;
};
