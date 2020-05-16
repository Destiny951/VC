
// exp17View.h : Cexp17View 类的接口
//

#pragma once


class Cexp17View : public CView
{
protected: // 仅从序列化创建
	Cexp17View();
	DECLARE_DYNCREATE(Cexp17View)

// 特性
public:
	Cexp17Doc* GetDocument() const;

// 操作
public:
	int i = 0;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp17View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCircle();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // exp17View.cpp 中的调试版本
inline Cexp17Doc* Cexp17View::GetDocument() const
   { return reinterpret_cast<Cexp17Doc*>(m_pDocument); }
#endif

