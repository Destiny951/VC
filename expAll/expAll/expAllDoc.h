
// expAllDoc.h : CexpAllDoc ��Ľӿ�
//


#pragma once
#include "expAllSet.h"


class CexpAllDoc : public CDocument
{
protected: // �������л�����
	CexpAllDoc();
	DECLARE_DYNCREATE(CexpAllDoc)

// ����
public:
	CexpAllSet m_expAllSet;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CexpAllDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
