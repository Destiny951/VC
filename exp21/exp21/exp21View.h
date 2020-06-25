
// exp21View.h : Cexp21View 类的接口
//

#pragma once


class Cexp21View : public CView
{
protected: // 仅从序列化创建
	Cexp21View();
	DECLARE_DYNCREATE(Cexp21View)

// 特性
public:
	Cexp21Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp21View();
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

#ifndef _DEBUG  // exp21View.cpp 中的调试版本
inline Cexp21Doc* Cexp21View::GetDocument() const
   { return reinterpret_cast<Cexp21Doc*>(m_pDocument); }
#endif

