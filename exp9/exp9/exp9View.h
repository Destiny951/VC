
// exp9View.h : Cexp9View 类的接口
//

#pragma once


class Cexp9View : public CView
{
protected: // 仅从序列化创建
	Cexp9View();
	DECLARE_DYNCREATE(Cexp9View)

// 特性
public:
	Cexp9Doc* GetDocument() const;

// 操作
public:
	int x, y;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp9View();
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
};

#ifndef _DEBUG  // exp9View.cpp 中的调试版本
inline Cexp9Doc* Cexp9View::GetDocument() const
   { return reinterpret_cast<Cexp9Doc*>(m_pDocument); }
#endif

