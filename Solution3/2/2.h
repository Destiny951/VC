// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MY2_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MY2_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef MY2_EXPORTS
#define MY2_API __declspec(dllexport)
#else
#define MY2_API __declspec(dllimport)
#endif

// �����Ǵ� 2.dll ������
class MY2_API CMy2 {
public:
	CMy2(void);
	// TODO:  �ڴ�������ķ�����
};

extern MY2_API int nMy2;

MY2_API int fnMy2(void);

MY2_API int factorial(int n);

class MY2_API FAC {
public:
	float convert(float reg);
	// TODO:  �ڴ�������ķ�����
};