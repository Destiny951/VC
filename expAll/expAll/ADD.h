#pragma once


// ADD 对话框

class ADD : public CDialogEx
{
	DECLARE_DYNAMIC(ADD)

public:
	ADD(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ADD();

// 对话框数据
	enum { IDD = IDD_ADD };

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
