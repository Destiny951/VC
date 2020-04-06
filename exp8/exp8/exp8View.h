
// exp8View.h : Cexp8View 类的接口
//

#pragma once


class Cexp8View : public CView
{
protected: // 仅从序列化创建
	Cexp8View();
	DECLARE_DYNCREATE(Cexp8View)

// 特性
public:
	Cexp8Doc* GetDocument() const;

// 操作
public:
	bool ans;
	CRect circle;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp8View();
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

#ifndef _DEBUG  // exp8View.cpp 中的调试版本
inline Cexp8Doc* Cexp8View::GetDocument() const
   { return reinterpret_cast<Cexp8Doc*>(m_pDocument); }
#endif

