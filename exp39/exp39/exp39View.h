
// exp39View.h : Cexp39View 类的接口
//

#pragma once

class Cexp39Set;

class Cexp39View : public CRecordView
{
protected: // 仅从序列化创建
	Cexp39View();
	DECLARE_DYNCREATE(Cexp39View)

public:
	enum{ IDD = IDD_EXP39_FORM };
	Cexp39Set* m_pSet;

// 特性
public:
	Cexp39Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cexp39View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	double number;
	long age;
	long phont;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // exp39View.cpp 中的调试版本
inline Cexp39Doc* Cexp39View::GetDocument() const
   { return reinterpret_cast<Cexp39Doc*>(m_pDocument); }
#endif

