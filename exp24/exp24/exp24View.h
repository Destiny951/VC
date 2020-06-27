
// exp24View.h : Cexp24View 类的接口
//

#pragma once


class Cexp24View : public CView
{
protected: // 仅从序列化创建
	Cexp24View();
	DECLARE_DYNCREATE(Cexp24View)

// 特性
public:
	Cexp24Doc* GetDocument() const;
// 操作
public:
	CPoint pt;      //确认字符输入的坐标
	CRect mes;     
	CSize textsize;     //字符的大小

	CArray < TCHAR, TCHAR& > ch;   //字符数组

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cexp24View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
};

#ifndef _DEBUG  // exp24View.cpp 中的调试版本
inline Cexp24Doc* Cexp24View::GetDocument() const
   { return reinterpret_cast<Cexp24Doc*>(m_pDocument); }
#endif

