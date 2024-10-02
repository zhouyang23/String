#include "String.h"
#include<cmath>

int strlen(char* str)
{
	//��ֹ���ַ���ָ��
	if (!str) {
		return 0;
	}
	int i = 0;
	while (str[i]) {
		i++;
	}
	return i;
}

void copystr(char* src, char* dst)
{
	int i = 0;
	while (src[i]) {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int cmpstr(char* s1, char* s2)
{
	int i = 0;
	while (s1[i]) {
		if (s1[i] != s2[i]) {
			return 0;
		}
		i++;
	}
	if (s2[i]) {
		return 0;
	}
	return 1;
}

void removesLeadingAndTrailingSpaces(char* str)
{
	//��ɾ���ַ���ĩβ�Ŀո�
	int length = strlen(str);
	int i = length - 1;
	while (str[i] == ' ') {
		i--;
	}
	str[i + 1] = '\0';
	//��ɾ���ַ���ǰ��Ŀո�
	/*
	int j = 0;
	while (str[j] == ' ') {
		j++;
	}
	int k = 0;
	while (k <= i+1-j) {
		str[k] = str[k + j];
		k++;
	}
	*/
	int j=0, k=0;//j��¼�ַ�����ʼ�Ŀո���
	while (k <= i + 1) {
		if ( str[k] != ' ' && j == 0) {
			j = k; 
		}
		if (j) {
			str[k-j] = str[k];
		}
		k++;
	}
}

void substr(char* s, char* sub, int start, int length) {
	if (start < 0 || length < 0) {
		return;
	}
	if (0 == length) {
		sub[0] = '\0';
		return;
	}
	int slen = strlen(s);
	if (start + length > slen) {
		return;
	}
	int i = start;
	int j = 0;
	while (j<length) {
		sub[j++] = s[i++];
	}
	sub[j] = '\0';
}

void smaller(char* s1,char* s2)
{
	int i = 0;
	while (s1[i]) {
		if (s1[i] >= 65 && s1[i] <= 90 || s1[i] >= 97 && s1[i] <= 122) {
			s2[i] = s1[i] | 0b00100000;
		}
		else {
			s2[i] = s1[i];
		}
		i++;
	}
	s2[i] = '\0';
}

void replace(char* src, char* dst, char* pat, char* rpl)
{
	if (src == dst) {
		return;
	}
	int srclen = strlen(src);
	if (!strlen) {
		dst[0] = '\0';
		return;
	}
	int patlen = strlen(pat);
	int rpllen = strlen(rpl);
	if (patlen > srclen) {
		return;
	}

	int difflen = rpllen - patlen;
	int diff = 0;//��¼ƫ����

	int i = 0;
	while (i<srclen) {
		//��src��ƥ���ַ���pat
		bool flag = true;//flagΪtrue��־���ַ���pat���ַ���src��ƥ��ɹ�
		int j = 0;
		while (j<patlen) {
			if (src[i+j] != pat[j]) {
				flag = false;
				break;
			}
			j++;
		}
		if (flag) {//ƥ��ɹ�
			/*//����������Ժϲ�
			if (patlen == rpllen) {
				j = 0;
				while (j < rpllen) {
					dst[i+j] = rpl[j];
					j++;
				}
				i += patlen;
			}
			else if (patlen<rpllen) {
				j = 0;
				while (j < rpllen) {
					dst[i+j+diff] = rpl[j];
					j++;
				}
				diff += difflen;
				i += patlen;
			}
			else {
				j = 0;
				while (j < rpllen) {
					dst[i + j + diff] = rpl[j];
					j++;
				}
				diff += difflen;
				i += patlen;
			}
			*/
			j = 0;
			while (j < rpllen) {
				dst[i + j + diff] = rpl[j];
				j++;
			}
			diff += difflen;
			i += patlen;
		}
		else {//ƥ��ʧ��
			dst[i+diff] = src[i];
			i++;
		}
	}
	dst[i+diff] = '\0';
}

int split(char* s, char a[][100], char pat)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (s[i]) {
		if (s[i] == pat) {
			a[j][k] = '\0';
			j++;
			k = 0;
		}
		else {
			a[j][k] = s[i];
			k++;
		}
		i++;
	}
	a[j][k] = '\0';
	return j + 1;
}

void inverse(char* src, char* dst)
{
	int srclen = strlen(src);
	if (0 == srclen) {
		dst[0] = '\0';
		return;
	}
	int i = 0;
	while (i<srclen) {
		dst[i] = src[srclen - 1 - i];
		i++;
	}
	dst[i] = '\0';
}

float tofloat(char* s)
{
	int i = 0;
	float result = 0;
	bool flag = false;//flagΪflase��ʾû�г���С����
	bool digit=false;//digitΪfalse��ʾû�г�������
	bool sign = false;//signΪfalse��ʾû�г��ָ���
	int count = 0;
	while (s[i]) {
		if (s[i] == '.') {
			flag = true;
		}
		if ('-' == s[i]&&!flag&&!digit) {
			sign = true;
		}
		if (s[i] >= '0' && s[i] <= '9') {
			digit = true;
			if (!flag) {
				result = result * 10 + s[i]-'0';
			}
			else {
				count++;
				result = result + (s[i] - '0')*1.0 / pow(10, count);
			}
		}
		i++;
	}
	if (sign) {
		result = -result;
	}
	return result;
}

int startof(char* src, char* s)
{
	int srclen = strlen(src);
	int slen = strlen(s);
	if (srclen < slen) {
		return 0;
	}
	int i = 0;
	while (i < slen) {
		if (src[i] != s[i] || slen == 0) {
			return 0;
		}
		i++;
	}
	return 1;
}

int endof(char* src, char* s)
{
	int srclen = strlen(src);
	int slen = strlen(s);
	if (srclen < slen||slen==0) {
		return 0;
	}
	int i = 0;
	while (i < slen) {
		if (src[srclen-1-i] != s[slen-1-i]) {
			return 0;
		}
		i++;
	}
	return 1;
}

void catstr(char* s1, char* s2, char* dst)
{
	int i=0, j=0;
	while (s1[i]) {
		dst[i] = s1[i];
		++i;
	}
	while (s2[j]) {
		dst[i + j] = s2[j];
		++j;
	}
	dst[i + j] = '\0';
}

void removeStart(char* src, char* s, char* dst)
{
	if (startof(src, s)) {
		int slen = strlen(s);
		int srclen = strlen(src);
		int i = 0;
		while (i<srclen-slen) {
			dst[i] = src[i + slen];
			++i;
		}
		dst[i] = '\0';
	}
	else {
		copystr(src, dst);
	}
}

void removeEnd(char* src, char* s, char* dst)
{
	if (endof(src, s)) {
		int slen = strlen(s);
		int srclen = strlen(src);
		int i = 0;
		while (i < srclen - slen) {
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	else {
		copystr(src, dst);
	}
}

int indexof(char* src, char* s)
{
	int srclen = strlen(src);
	int slen = strlen(s);
	if (srclen < slen|| slen==0) {
		return -1;
	}
	int i = 0;
	while (i < srclen) {
		bool flag = true;
		int j = 0;
		while (j < slen) {
			if (src[i+j] != s[j]) {
				flag = false;
				break;
			}
			j++;
		}
		if (flag) {
			return i;
		}
		++i;
	}
	return -1;
}



