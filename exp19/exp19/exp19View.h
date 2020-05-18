
// exp19View.h : Cexp19View 类的接口
//

#pragma once


class Cexp19View : public CView
{
protected: // 仅从序列化创建
	Cexp19View();
	DECLARE_DYNCREATE(Cexp19View)

// 特性
public:
	Cexp19Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp19View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp19View.cpp 中的调试版本
inline Cexp19Doc* Cexp19View::GetDocument() const
   { return reinterpret_cast<Cexp19Doc*>(m_pDocument); }
#endif

