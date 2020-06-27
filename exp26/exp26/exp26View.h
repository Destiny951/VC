
// exp26View.h : Cexp26View 类的接口
//

#pragma once


class Cexp26View : public CView
{
protected: // 仅从序列化创建
	Cexp26View();
	DECLARE_DYNCREATE(Cexp26View)

// 特性
public:
	Cexp26Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp26View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnShow();
};

#ifndef _DEBUG  // exp26View.cpp 中的调试版本
inline Cexp26Doc* Cexp26View::GetDocument() const
   { return reinterpret_cast<Cexp26Doc*>(m_pDocument); }
#endif

