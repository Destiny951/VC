
// exp15View.h : Cexp15View 类的接口
//

#pragma once


class Cexp15View : public CView
{
protected: // 仅从序列化创建
	Cexp15View();
	DECLARE_DYNCREATE(Cexp15View)

// 特性
public:
	Cexp15Doc* GetDocument() const;

// 操作
public:
	CRect m;
	CRect model;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp15View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp15View.cpp 中的调试版本
inline Cexp15Doc* Cexp15View::GetDocument() const
   { return reinterpret_cast<Cexp15Doc*>(m_pDocument); }
#endif

