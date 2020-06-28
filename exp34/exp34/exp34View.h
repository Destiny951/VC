
// exp34View.h : Cexp34View 类的接口
//

#pragma once


class Cexp34View : public CView
{
protected: // 仅从序列化创建
	Cexp34View();
	DECLARE_DYNCREATE(Cexp34View)

// 特性
public:
	Cexp34Doc* GetDocument() const;

// 操作
public:
	CRect circle;
	CRect ce;
	CBrush brush;
	CBrush *oldbrush;
	CPen* newPen = new CPen(PS_DOT, 1, RGB(0, 0, 0));
	CRect yuan;
	CPoint start;
	bool log = 0;
	bool t = 0;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp34View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawcircle();
	afx_msg void OnDrawcolor();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp34View.cpp 中的调试版本
inline Cexp34Doc* Cexp34View::GetDocument() const
   { return reinterpret_cast<Cexp34Doc*>(m_pDocument); }
#endif

