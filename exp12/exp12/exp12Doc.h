
// exp12Doc.h : Cexp12Doc ��Ľӿ�
//


#pragma once


class Cexp12Doc : public CDocument
{
protected: // �������л�����
	Cexp12Doc();
	DECLARE_DYNCREATE(Cexp12Doc)

// ����
public:

// ����
public:
	CArray<int> xa;
	CArray<int> xb;
	CArray<int> xc;
	CArray<char> command;
	CArray<CRect, CRect&> cr;
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~Cexp12Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ�����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};