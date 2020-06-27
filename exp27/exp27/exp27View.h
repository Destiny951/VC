
// exp27View.h : Cexp27View 类的接口
//

#pragma once


class Cexp27View : public CView
{
protected: // 仅从序列化创建
	Cexp27View();
	DECLARE_DYNCREATE(Cexp27View)

// 特性
public:
	Cexp27Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp27View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEdit();
};

#ifndef _DEBUG  // exp27View.cpp 中的调试版本
inline Cexp27Doc* Cexp27View::GetDocument() const
   { return reinterpret_cast<Cexp27Doc*>(m_pDocument); }
#endif

