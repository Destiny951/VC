
// exp7View.h : Cexp7View 类的接口
//

#pragma once


class Cexp7View : public CView
{
protected: // 仅从序列化创建
	Cexp7View();
	DECLARE_DYNCREATE(Cexp7View)

// 特性
public:
	Cexp7Doc* GetDocument() const;

// 操作
public:
	bool ans;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp7View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp7View.cpp 中的调试版本
inline Cexp7Doc* Cexp7View::GetDocument() const
   { return reinterpret_cast<Cexp7Doc*>(m_pDocument); }
#endif

