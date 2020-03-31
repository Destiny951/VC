
// exp4View.h : Cexp4View 类的接口
//

#pragma once


class Cexp4View : public CView
{
protected: // 仅从序列化创建
	Cexp4View();
	DECLARE_DYNCREATE(Cexp4View)

// 特性
public:
	Cexp4Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CRect circle;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp4View.cpp 中的调试版本
inline Cexp4Doc* Cexp4View::GetDocument() const
   { return reinterpret_cast<Cexp4Doc*>(m_pDocument); }
#endif

