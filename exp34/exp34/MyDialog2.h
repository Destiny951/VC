#pragma once


// MyDialog2 对话框

class MyDialog2 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog2)

public:
	MyDialog2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDialog2();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int red;
	int green;
	int blue;
	afx_msg void OnBnClickedOk();
};
