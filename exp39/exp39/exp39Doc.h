
// exp39Doc.h : Cexp39Doc ��Ľӿ�
//


#pragma once
#include "exp39Set.h"


class Cexp39Doc : public CDocument
{
protected: // �������л�����
	Cexp39Doc();
	DECLARE_DYNCREATE(Cexp39Doc)

// ����
public:
	Cexp39Set m_exp39Set;

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
	virtual ~Cexp39Doc();
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
