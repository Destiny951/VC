
// exp10View.h : Cexp10View 类的接口
//

#pragma once


class Cexp10View : public CView
{
protected: // 仅从序列化创建
	Cexp10View();
	DECLARE_DYNCREATE(Cexp10View)

// 特性
public:
	Cexp10Doc* GetDocument() const;

// 操作
public:
	CString s;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp10View();
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
};

#ifndef _DEBUG  // exp10View.cpp 中的调试版本
inline Cexp10Doc* Cexp10View::GetDocument() const
   { return reinterpret_cast<Cexp10Doc*>(m_pDocument); }
#endif

