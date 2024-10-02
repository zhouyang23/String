#pragma once

//求字符串的长度
int strlen(char*);

//字符串复制
void copystr(char*, char*);

//字符串比较
int cmpstr(char*, char*);

//去除字符串首尾空格
void removesLeadingAndTrailingSpaces(char*);

//截取子字符串
void substr(char*, char*, int, int);

//字符串变小写字母,大写字母二进制第六位0变为1就是小写字母
void smaller(char*,char*);

//字符串替换
void replace(char*, char*, char*, char*);

//字符串拆分
int split(char*, char a[][100], char);

//字符串逆序
void inverse(char*, char*);

//字符串转数字
float tofloat(char*);

//判断字符串是否以某个字符串开始或结束的
int startof(char*, char*);
int endof(char*, char*);

//字符串拼接
void catstr(char*, char*, char*);

//去掉首尾子串
void removeStart(char*,char*,char*);
void removeEnd(char*, char*, char*);

//查找子字符串位置
int indexof(char*, char*);