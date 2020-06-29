
// exp37View.h : Cexp37View 类的接口
//

#pragma once


class Cexp37View : public CView
{
protected: // 仅从序列化创建
	Cexp37View();
	DECLARE_DYNCREATE(Cexp37View)

// 特性
public:
	Cexp37Doc* GetDocument() const;

// 操作
public:
	bool sel = 0;
	int log = 0;
	CPoint start;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp37View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp37View.cpp 中的调试版本
inline Cexp37Doc* Cexp37View::GetDocument() const
   { return reinterpret_cast<Cexp37Doc*>(m_pDocument); }
#endif

