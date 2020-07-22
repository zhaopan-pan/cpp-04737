#include <iostream>
using namespace std;

/**
 * @file static.cpp
 * @author zp
 * @brief 
 * @version 0.1
 * @date 2020-07-20
 * 
 * @copyright Copyright (c) 2020
 * 
 * ������ڴ��а����˳�Ա��������ͬ�Ķ���ռ�ò�ͬ���ڴ棬��ʹ�ò�ͬ����ĳ�Ա�����໥���������ǵ�ֵ�������������Ӱ�졣
 * ������������ͬ���͵Ķ��� a��b�����Ƕ���һ����Ա���� m_name����ô�޸� a.m_name ��ֵ����Ӱ�� b.m_name ��ֵ��
 * ������ʱ������ϣ���ڶ������֮�乲�����ݣ����� a �ı���ĳ�����ݺ���� b ���Լ�⵽���������ݵĵ���ʹ�ó����Ǽ�������ǰ��� Student ��Ϊ����
 * ���������֪���༶�й��ж�����ѧ�����Ϳ�������һ�ݹ����ı�����ÿ�δ�������ʱ�øñ����� 1��
 * 
 * static:��C++�У����ǿ���ʹ�þ�̬��Ա������ʵ�ֶ�����������ݵ�Ŀ�ꡣ��̬��Ա������һ������ĳ�Ա�����������ؼ���static����
 */
class Student
{
private:
    /* data */
    const char *m_name;
    int m_age;
    float m_score;

private: //��̬��Ա����
    //static���εĳ�Ա���������࣬������ĳ������Ķ��󣬼�ʹ�����������ҲֻΪ m_total ����һ���ڴ棬
    //���ж���ʹ�õĶ�������ڴ��е����ݡ���ĳ�������޸��� m_total��Ҳ��Ӱ�쵽��������
    static int m_total;

public:
    Student(const char *name, int age, float score);
    void show();
    ~Student();
};
//��ʼ����̬��Ա����
int Student::m_total = 0;

Student::Student(const char *name, int age, float score)
{
    this->m_name = name;
    this->m_age = age;
    this->m_score = score;
    m_total++; //������̬��Ա����
};
void Student::show()
{
    cout << m_name << "��������" << m_age << "���ɼ���" << m_score << "����ǰ����" << m_total << "��ѧ����" << endl;
};
Student::~Student()
{
    cout << "����" << endl;
}

int main()
{
    //������������ (��Ϊֻ����show()���������������������󣬵�ʹ�����������޷������ڴ棬�ᵼ���ڴ�й¶�����д��ͳ����в�����ʹ�á�)
    (new Student("С��", 15, 90))->show();
    (new Student("����", 16, 80))->show();
    (new Student("�Ż�", 16, 99))->show();
    (new Student("����", 14, 60))->show();
    return 0;
}
//��ʼ�� static��Ա�����ķ�ʽ
//      int Student::m_total = 10;      //ͨ��������� static ��Ա����
//      //���� static��Ա�����ķ�ʽ
//      Student stu("С��", 15, 92.5f); //ͨ������������ static ��Ա����
//      stu.m_total = 20;
//      //ͨ������ָ�������� static ��Ա����
//      Student *pstu = new Student("�", 16, 96);
//      pstu -> m_total = 20;

/**
 * @brief  ����С��
 * ��ʼ����static ��Ա�������������������ⲿ��ʼ����������ʽΪ��type class::name = value; 
 *        private��protected��public ���εľ�̬��Ա���������������ַ�ʽ��ʼ����
 * 
 *  ע�⣺static ��Ա�������ڴ�Ȳ�����������ʱ���䣬Ҳ�����ڴ�������ʱ���䣬�����ڣ����⣩��ʼ��ʱ���䡣
 *       ������˵��û���������ʼ���� static ��Ա��������ʹ�á�
 * 
 *  �ܽ�: 1��һ�����п�����һ��������̬��Ա���������еĶ��󶼹�����Щ��̬��Ա��������������������
 * 
 *       2��static ��Ա��������ͨ static ����һ���������ڴ�����е�ȫ�������������ڴ棬���������ʱ���ͷš�
 *         �����ζ�ţ�static ��Ա�����������Ĵ����������ڴ棬Ҳ�����������ٶ��ͷ��ڴ档����ͨ��Ա�����ڶ��󴴽�ʱ�����ڴ棬�ڶ�������ʱ�ͷ��ڴ档
 * 
 *       3����̬��Ա���������ʼ��������ֻ������������С���ʼ��ʱ���Ը���ֵ��Ҳ���Բ���ֵ���������ֵ����ô�ᱻĬ�ϳ�ʼ��Ϊ 0��
 *         ȫ���������ı�������Ĭ�ϵĳ�ʼֵ 0������̬��������������ջ����������Ĭ��ֵ�ǲ�ȷ���ģ�һ����Ϊ������ֵ��
 * 
 *       4����̬��Ա�����ȿ���ͨ�����������ʣ�Ҳ����ͨ���������ʣ���Ҫ��ѭ private��protected �� public �ؼ��ֵķ���Ȩ�����ơ�
 *         ��ͨ������������ʱ�����ڲ�ͬ�Ķ��󣬷��ʵ���ͬһ���ڴ档
 */