
// exp40Set.cpp : Cexp40Set ���ʵ��
//

#include "stdafx.h"
#include "exp40.h"
#include "exp40Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp40Set ʵ��

// ���������� 2020��6��29��, 18:31

IMPLEMENT_DYNAMIC(Cexp40Set, CRecordset)

Cexp40Set::Cexp40Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = 0.0;
	m_3 = 0;
	m_4 = 0;
	m_5 = L"";
	m_nFields = 6;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cexp40Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f;DBQ=C:\\Users\\dagro\\Desktop\\Database1.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Cexp40Set::GetDefaultSQL()
{
	return _T("[����Դ_ѧ��]");
}

void Cexp40Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Double(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Long(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Long(pFX, _T("[�ֶ�4]"), m_4);
	RFX_Text(pFX, _T("[�ֶ�5]"), m_5);

}
/////////////////////////////////////////////////////////////////////////////
// Cexp40Set ���

#ifdef _DEBUG
void Cexp40Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cexp40Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

