
// exp12View.h : Cexp12View 类的接口
//

#pragma once


class Cexp12View : public CView
{
protected: // 仅从序列化创建
	Cexp12View();
	DECLARE_DYNCREATE(Cexp12View)

// 特性
public:
	Cexp12Doc* GetDocument() const;

// 操作
public:
	int sum = 0;
	int log = 0;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp12View();
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
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp12View.cpp 中的调试版本
inline Cexp12Doc* Cexp12View::GetDocument() const
   { return reinterpret_cast<Cexp12Doc*>(m_pDocument); }
#endif

