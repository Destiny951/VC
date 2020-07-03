#pragma once


// Edit 对话框

class Edit : public CDialogEx
{
	DECLARE_DYNAMIC(Edit)

public:
	Edit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Edit();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
