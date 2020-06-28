
// exp34View.h : Cexp34View 类的接口
//

#pragma once


class Cexp34View : public CView
{
protected: // 仅从序列化创建
	Cexp34View();
	DECLARE_DYNCREATE(Cexp34View)

// 特性
public:
	Cexp34Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp34View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp34View.cpp 中的调试版本
inline Cexp34Doc* Cexp34View::GetDocument() const
   { return reinterpret_cast<Cexp34Doc*>(m_pDocument); }
#endif

