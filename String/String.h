#pragma once

//���ַ����ĳ���
int strlen(char*);

//�ַ�������
void copystr(char*, char*);

//�ַ����Ƚ�
int cmpstr(char*, char*);

//ȥ���ַ�����β�ո�
void removesLeadingAndTrailingSpaces(char*);

//��ȡ���ַ���
void substr(char*, char*, int, int);

//�ַ�����Сд��ĸ,��д��ĸ�����Ƶ���λ0��Ϊ1����Сд��ĸ
void smaller(char*,char*);

//�ַ����滻
void replace(char*, char*, char*, char*);

//�ַ������
int split(char*, char a[][100], char);

//�ַ�������
void inverse(char*, char*);

//�ַ���ת����
float tofloat(char*);

//�ж��ַ����Ƿ���ĳ���ַ�����ʼ�������
int startof(char*, char*);
int endof(char*, char*);

//�ַ���ƴ��
void catstr(char*, char*, char*);

//ȥ����β�Ӵ�
void removeStart(char*,char*,char*);
void removeEnd(char*, char*, char*);

//�������ַ���λ��
int indexof(char*, char*);