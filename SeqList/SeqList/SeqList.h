#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//����˳���������������

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType * arr;
	int size;//��Ч���ݸ���
	int capacity;//�ռ��С
}SL;

//˳����ʼ��
void SLInit(SL* ps);

//˳��������
void SLDestroy(SL* ps);

//˳���Ĵ�ӡ
void SLPrint(SL s);

//���ռ��Ƿ��㹻
void SLCheckCapacity(SL* ps);

//β������
void SLPushBack(SL* ps, SLDataType x);

//ͷ������
void SLPushFront(SL* ps, SLDataType x);

//β��ɾ��
void SLPopBack(SL* ps);

//ͷ��ɾ��
void SLPopFront(SL* ps);

//ָ��λ��֮ǰ����
void SLInsert(SL* ps, int pos, SLDataType x);

//ָ��λ��֮ǰɾ��
void SLErase(SL* ps, int pos);

//����ĳԪ��
int SLFind(SL* ps, SLDataType x);
