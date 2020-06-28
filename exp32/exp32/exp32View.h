
// exp32View.h : Cexp32View 类的接口
//

#pragma once


class Cexp32View : public CView
{
protected: // 仅从序列化创建
	Cexp32View();
	DECLARE_DYNCREATE(Cexp32View)

// 特性
public:
	Cexp32Doc* GetDocument() const;

// 操作
public:
	CString filename;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp32View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnShow();
};

#ifndef _DEBUG  // exp32View.cpp 中的调试版本
inline Cexp32Doc* Cexp32View::GetDocument() const
   { return reinterpret_cast<Cexp32Doc*>(m_pDocument); }
#endif

