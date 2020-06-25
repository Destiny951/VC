
// exp22View.h : Cexp22View 类的接口
//

#pragma once


class Cexp22View : public CView
{
protected: // 仅从序列化创建
	Cexp22View();
	DECLARE_DYNCREATE(Cexp22View)

// 特性
public:
	Cexp22Doc* GetDocument() const;

// 操作
public:
	CString filename;
	int log = 0;
	CImage image;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // exp22View.cpp 中的调试版本
inline Cexp22Doc* Cexp22View::GetDocument() const
   { return reinterpret_cast<Cexp22Doc*>(m_pDocument); }
#endif

