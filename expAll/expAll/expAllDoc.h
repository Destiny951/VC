
// expAllDoc.h : CexpAllDoc 类的接口
//


#pragma once
#include "expAllSet.h"


class CexpAllDoc : public CDocument
{
protected: // 仅从序列化创建
	CexpAllDoc();
	DECLARE_DYNCREATE(CexpAllDoc)

// 特性
public:
	CexpAllSet m_expAllSet;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CexpAllDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
