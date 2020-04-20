
// exp14View.h : Cexp14View 类的接口
//

#pragma once


class Cexp14View : public CView
{
protected: // 仅从序列化创建
	Cexp14View();
	DECLARE_DYNCREATE(Cexp14View)

// 特性
public:
	Cexp14Doc* GetDocument() const;

// 操作
public:
	int sum;
	int totalpixel;
	int avepixel;
	bool down;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp14View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp14View.cpp 中的调试版本
inline Cexp14Doc* Cexp14View::GetDocument() const
   { return reinterpret_cast<Cexp14Doc*>(m_pDocument); }
#endif

