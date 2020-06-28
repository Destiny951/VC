
// exp30View.h : Cexp30View 类的接口
//

#pragma once


class Cexp30View : public CView
{
protected: // 仅从序列化创建
	Cexp30View();
	DECLARE_DYNCREATE(Cexp30View)

// 特性
public:
	Cexp30Doc* GetDocument() const;

// 操作
public:
	CRect ce;
	CRect circle;
	bool start, exp;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp30View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp30View.cpp 中的调试版本
inline Cexp30Doc* Cexp30View::GetDocument() const
   { return reinterpret_cast<Cexp30Doc*>(m_pDocument); }
#endif

