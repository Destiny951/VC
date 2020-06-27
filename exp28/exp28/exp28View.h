
// exp28View.h : Cexp28View 类的接口
//

#pragma once


class Cexp28View : public CView
{
protected: // 仅从序列化创建
	Cexp28View();
	DECLARE_DYNCREATE(Cexp28View)

// 特性
public:
	Cexp28Doc* GetDocument() const;

// 操作
public:
	bool select;
	CRect ce;
	CPoint start;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp28View();
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

#ifndef _DEBUG  // exp28View.cpp 中的调试版本
inline Cexp28Doc* Cexp28View::GetDocument() const
   { return reinterpret_cast<Cexp28Doc*>(m_pDocument); }
#endif

