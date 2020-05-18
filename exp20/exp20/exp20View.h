
// exp20View.h : Cexp20View 类的接口
//

#pragma once


class Cexp20View : public CView
{
protected: // 仅从序列化创建
	Cexp20View();
	DECLARE_DYNCREATE(Cexp20View)

// 特性
public:
	Cexp20Doc* GetDocument() const;

// 操作
public:
	int i;
	int x1, y1, x2, y2;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp20View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLine();
	afx_msg void OnSquire();
	afx_msg void OnCircle();
};

#ifndef _DEBUG  // exp20View.cpp 中的调试版本
inline Cexp20Doc* Cexp20View::GetDocument() const
   { return reinterpret_cast<Cexp20Doc*>(m_pDocument); }
#endif

