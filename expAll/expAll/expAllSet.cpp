
// expAllSet.cpp : CexpAllSet ���ʵ��
//

#include "stdafx.h"
#include "expAll.h"
#include "expAllSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CexpAllSet ʵ��

// ���������� 2020��7��3��, 9:54

IMPLEMENT_DYNAMIC(CexpAllSet, CRecordset)

CexpAllSet::CexpAllSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_4 = L"";
	m_5 = L"";
	m_6 = L"";
	m_7 = L"";
	m_8 = L"";
	m_nFields = 9;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û�������֤��
CString CexpAllSet::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x7efc\x5408\x5b9e\x9a8c;DBQ=C:\\USERS\\DAGRO\\DESKTOP\\Database2.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CexpAllSet::GetDefaultSQL()
{
	return _T("[����Դ_�ۺ�ʵ��]");
}

void CexpAllSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Text(pFX, _T("[�ֶ�4]"), m_4);
	RFX_Text(pFX, _T("[�ֶ�5]"), m_5);
	RFX_Text(pFX, _T("[�ֶ�6]"), m_6);
	RFX_Text(pFX, _T("[�ֶ�7]"), m_7);
	RFX_Text(pFX, _T("[�ֶ�8]"), m_8);

}
/////////////////////////////////////////////////////////////////////////////
// CexpAllSet ���

#ifdef _DEBUG
void CexpAllSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CexpAllSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
