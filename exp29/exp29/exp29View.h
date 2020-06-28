
// exp29View.h : Cexp29View 类的接口
//

#pragma once


class Cexp29View : public CView
{
protected: // 仅从序列化创建
	Cexp29View();
	DECLARE_DYNCREATE(Cexp29View)

// 特性
public:
	Cexp29Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp29View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShow();
};

#ifndef _DEBUG  // exp29View.cpp 中的调试版本
inline Cexp29Doc* Cexp29View::GetDocument() const
   { return reinterpret_cast<Cexp29Doc*>(m_pDocument); }
#endif

