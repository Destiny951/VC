
// exp35View.h : Cexp35View 类的接口
//

#pragma once


class Cexp35View : public CView
{
protected: // 仅从序列化创建
	Cexp35View();
	DECLARE_DYNCREATE(Cexp35View)

// 特性
public:
	Cexp35Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp35View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChoose();
	afx_msg void OnPlay();
};

#ifndef _DEBUG  // exp35View.cpp 中的调试版本
inline Cexp35Doc* Cexp35View::GetDocument() const
   { return reinterpret_cast<Cexp35Doc*>(m_pDocument); }
#endif

