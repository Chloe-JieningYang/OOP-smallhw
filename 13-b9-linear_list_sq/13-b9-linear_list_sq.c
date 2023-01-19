/*2050598 ͨ�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>		//malloc/realloc����
#if __linux__
#include <unistd.h>		//exit����
#endif
#include <math.h>               //fabs����
#include <string.h>		//strcpy/strcmp�Ⱥ���
#include "13-b9-linear_list_sq.h"	//��ʽ����

/* ��ʼ�����Ա� */
Status InitList(sqlist *L)
{
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (L->elem == NULL)
    	exit(LOVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

/* ɾ�����Ա� */
Status DestroyList(sqlist *L)
{
    /* ����ָ��������Ҫ�ͷŶ����ռ� */
#if defined (ELEMTYPE_IS_CHAR_P) || defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    int i;

    /* �����ͷŶ����ռ� */
    for(i=0; i<L->length; i++)
        free(L->elem[i]);
#endif

    /* ��δִ�� InitList��ֱ��ִ�б�����������ܳ�������Ϊָ���ʼֵδ�� */
    if (L->elem)
    	free(L->elem);
    L->length   = 0;
    L->listsize = 0;

    return OK;
}

/* ������Ա����ѳ�ʼ�������ͷſռ䣬ֻ������ݣ� */
Status ClearList(sqlist *L)
{
    /* ����ָ��������Ҫ�ͷŶ����ռ� */
#if defined (ELEMTYPE_IS_CHAR_P) || defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    int i;

    /* �����ͷŶ����ռ� */
    for(i=0; i<L->length; i++)
        free(L->elem[i]);
#endif

    L->length = 0;
    return OK;
}

/* �ж��Ƿ�Ϊ�ձ� */
Status ListEmpty(sqlist L)
{
    if (L.length == 0)
    	return TRUE;
    else
    	return FALSE;
}

/* ����ĳ��� */
int ListLength(sqlist L)
{
    return L.length;
}

/* ȡ����Ԫ�� */
Status GetElem(sqlist L, int i, ElemType *e)
{
    if (i<1 || i>L.length)  //����Ҫ��� || L.length>0
    	return ERROR;

    /* ѭ���Ƚ��������Ա� */
#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    strcpy(*e, L.elem[i-1]);	//�±��0��ʼ����i��ʵ����elem[i-1]��
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(e, &(L.elem[i-1]), sizeof(ElemType)); //�±��0��ʼ����i��ʵ����elem[i-1]��
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    memcpy(*e, L.elem[i-1], sizeof(ET)); //�±��0��ʼ����i��ʵ����elem[i-1]��
#else	//int��doubleֱ�Ӹ�ֵ
    *e = L.elem[i-1];	//�±��0��ʼ����i��ʵ����elem[i-1]��
#endif

    return OK;
}

/* ���ҷ���ָ��������Ԫ�� */
int LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2))
{
    ElemType *p = L.elem;
    int       i = 1;

    while(i<=L.length && (*compare)(*p++, e)==FALSE)
        i++;
        
    return (i<=L.length) ? i : 0;	//�ҵ�����i�����򷵻�0
}

/* ���ҷ���ָ��������Ԫ�ص�ǰ��Ԫ�� */
Status PriorElem(sqlist L, ElemType cur_e, ElemType *pre_e, Status(*compare)(ElemType e1, ElemType e2))
{
    ElemType *p = L.elem;
    int       i = 1;

    /* ѭ���Ƚ��������Ա� */
    while (i <= L.length && (*compare)(*p, cur_e) == FALSE) {
        i++;
        p++;
    }

    if (i==1 || i>L.length) //�ҵ���1��Ԫ�ػ�δ�ҵ�
    	return ERROR;

#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined(ELEMTYPE_IS_CHAR_P)
    strcpy(*pre_e, *--p);	//ȡǰ��Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(pre_e, --p, sizeof(ElemType));	//ȡǰ��Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    memcpy(*pre_e, *--p, sizeof(ET));	//ȡǰ��Ԫ�ص�ֵ
#else	//int��doubleֱ�Ӹ�ֵ
    *pre_e = *--p;	//ȡǰ��Ԫ�ص�ֵ
#endif
    return OK;
}

/* ���ҷ���ָ��������Ԫ�صĺ��Ԫ�� */
Status NextElem(sqlist L, ElemType cur_e, ElemType* next_e, Status(*compare)(ElemType e1, ElemType e2))
{
    ElemType* p = L.elem;
    int       i = 1;

    /* ѭ���Ƚ��������Ա�(����βԪ��) */

    while (i < L.length && (*compare)(*p, cur_e) == FALSE) {
        i++;
        p++;
    }

    if (i >= L.length)	//δ�ҵ������һ��Ԫ��δ�Ƚϣ�
        return ERROR;

#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    strcpy(*next_e, *++p);	//ȡ���Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(next_e, ++p, sizeof(ElemType));	//ȡ���Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    memcpy(*next_e, *++p, sizeof(ET));	//ȡ���Ԫ�ص�ֵ
#else	//int��doubleֱ�Ӹ�ֵ
    * next_e = *++p;	//ȡ���Ԫ�ص�ֵ
#endif

    return OK;
}

/* ��ָ��λ��ǰ����һ����Ԫ�� */
Status ListInsert(sqlist *L, int i, ElemType e)
{
    ElemType *p, *q; //������㷨��һ�����ʡ�ԣ�������

    if (i<1 || i>L->length+1)   //������Χ�� 1..length+1
    	return ERROR;
    
    /* �ռ�����������ռ� */
    if (L->length >= L->listsize) {
	ElemType *newbase;
	newbase = (ElemType *)realloc(L->elem, (L->listsize+LISTINCREMENT)*sizeof(ElemType));
	if (!newbase)
	    return LOVERFLOW;

	L->elem = newbase;
	L->listsize += LISTINCREMENT;
	//L->length��ʱ����
	}

    q = &(L->elem[i-1]);  //��i��Ԫ�أ����µĲ���λ��

    /* �����һ����length����[length-1]�С���ʼ����i��Ԫ�����κ���һ�� */
    for (p=&(L->elem[L->length-1]); p>=q; --p)
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
        strcpy(*(p+1), *p);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
        memcpy(p+1, p, sizeof(ElemType));	//������strcpy
#else	//int��double��charָ�롢struct studentָ�붼��ֱ�Ӹ�ֵ
        *(p+1) = *p;
#endif

    /* ������Ԫ�أ�����+1 */
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
    strcpy(*q, e);
#elif defined (ELEMTYPE_IS_CHAR_P)
    /* ԭ��L->elem[i-1]��ָ���ѷ���[i]�У�Ҫ��������ռ䣬������Ԫ�أ�����+1 */
    L->elem[i-1] = (ElemType)malloc((strlen(e)+1) * sizeof(char));
    if (L->elem[i-1]==NULL)
    	return LOVERFLOW;

    strcpy(*q, e);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(q, &e, sizeof(ElemType));
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    L->elem[i-1] = (ElemType)malloc(sizeof(ET));
    if (L->elem[i-1]==NULL)
    	return LOVERFLOW;

    memcpy(*q, e, sizeof(ET));
#else	//int��doubleֱ�Ӹ�ֵ
    *q = e;
#endif

    L->length ++;

    return OK;
}

/* ɾ��ָ��λ�õ�Ԫ�أ�������ɾ��Ԫ�ص�ֵ����e�з��� */
Status ListDelete(sqlist *L, int i, ElemType *e)
{
    ElemType *p, *q; //������㷨��һ�����ʡ�ԣ�������

    if (i<1 || i>L->length) //������Χ�� 1..length
    	return ERROR;

    p = &(L->elem[i-1]); 		//ָ���i��Ԫ��

#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    strcpy(*e, *p); 				//ȡ��i��Ԫ�ص�ֵ����e��
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(e, p, sizeof(ElemType));	//ȡ��i��Ԫ�ص�ֵ����e��
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    memcpy(*e, *p, sizeof(ET));		//ȡ��i��Ԫ�ص�ֵ����e��
#else	//int��doubleֱ�Ӹ�ֵ
    *e = *p; 				//ȡ��i��Ԫ�ص�ֵ����e��
#endif

    q = &(L->elem[L->length-1]);	//ָ�����һ��Ԫ�أ�Ҳ���� q = L->elem+L->length-1

#if defined (ELEMTYPE_IS_CHAR_P) || defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    free(*p);	//�ͷſռ�
#endif

    /* �ӵ�i+1���������ǰ��һ�� */
    for (++p; p<=q; ++p) {
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
	strcpy(*(p-1), *p);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	memcpy((p-1), p, sizeof(ElemType));
#else	//int��double��charָ�롢struct studentָ�붼��ֱ�Ӹ�ֵ
	*(p-1) = *p;
#endif
	}

    L->length --;	//����-1
    return OK;
}

/* �������Ա� */
Status ListTraverse(sqlist L, Status (*visit)(ElemType e))
{
    extern int line_count; //��main�ж���Ĵ�ӡ���м����������㷨�޹أ�
    ElemType *p = L.elem;
    int       i = 1;

    line_count = 0;		//�������ָ���ʼֵ�����㷨�޹أ�
    while(i<=L.length && (*visit)(*p++)==TRUE)
        i++;

    if (i<=L.length)
    	return ERROR;

    printf("\n");//����ӡһ�����У�ֻ��Ϊ�˺ÿ������㷨�޹�
    return OK;
}


/*����Ϊ�Լ�д�ĺ���*/

/* ������Ա����ѳ�ʼ�������ͷſռ䣬ֻ������ݣ� */
Status ClearList1(sqlist* L)
{
    /*����ָ��������Ҫ�ͷŶ����ռ�*/
#if defined (ELEMTYPE_IS_CHAR_P)||defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    int i;
    for (i = 0; i < L->length; i++)
        free(L->elem[i]);
#endif

    /*�����չ���ռ�Ҫ�ͷŶ���Ŀռ�*/
    if (L->listsize > LIST_INIT_SIZE)
    {
        ElemType* newbase;
        newbase = (ElemType*)realloc(L->elem, LISTINCREMENT * sizeof(ElemType));
        if (newbase == NULL)
            return LOVERFLOW;
        L->elem = newbase;
        L->listsize = LIST_INIT_SIZE;
    }
    
    L->length = 0;
    return OK;
}


/*��ָ��Ԫ��ǰ����һ��Ԫ��*/
Status ListInsert1(sqlist* L, ElemType cur_e, ElemType e, Status(*compare)(ElemType e1, ElemType e2))
{
    int i;
    int find = 0;
    for (i = L->length - 1; i >= 0; i--)
    {
        if ((*compare)(L->elem[i], cur_e) == TRUE)
        {
            find = 1;
            break;
        }
    }

    if (find == 0)//�Ҳ���ָ��Ԫ��
        return ERROR;

    /*�ռ�����������ռ�*/
    if (L->length >= L->listsize)
    {
        ElemType* newbase;
        newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (newbase == NULL)
            return LOVERFLOW;
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }

    /*�����һ��Ԫ�ص�ָ��λ�õ�Ԫ�أ�ÿ��Ԫ��������һ��λ��*/
    int j;
    for (j = L->length - 1; j >= i; j--)
    {
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
        strcpy(L->elem[j + 1], L->elem[j]);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
        memcpy(&(L->elem[j + 1]), &(L->elem[j]), sizeof(ElemType));
#else   // int��double��charָ�롢struct studentָ�붼��ֱ�Ӹ�ֵ
        L->elem[j + 1] = L->elem[j];
#endif
    }

    /*������Ԫ�أ�����λ���±�Ϊi,����+1*/
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
    strcpy(L->elem[i], e);
#elif defined (ELEMTYPE_IS_CHAR_P)
    /*���¶�������ռ�*/
    L->elem[i] = (ElemType)malloc((strlen(e) + 1) * sizeof(char));
    if (L->elem[i] == NULL)
        return LOVERFLOW;
    strcpy(L->elem[i], e);
#elif defined(ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(&(L->elem[i]), &e, sizeof(ElemType));
#elif defined(ELEMTYPE_IS_STRUCT_STUDENT_P)
    /*���¶�������ռ�*/
    L->elem[i] = (ElemType)malloc(sizeof(ET));
    if (L->elem[i] == NULL)
        return LOVERFLOW;
    memcpy(L->elem[i], e, sizeof(ET));
#else          //int doubleֱ�Ӹ�ֵ
    L->elem[i] = e;
#endif

    L->length++;
    return OK;
}


/*ɾ��ָ��Ԫ��cur_e,����ָ��ֵ��ͬ��Ԫ���ж����ֻɾ����һ�����ӿռ���С����*/
Status ListDelete1(sqlist* L, ElemType cur_e, Status(*compare)(ElemType e1, ElemType e2))
{
    ElemType* p, * q;
    int find = 0;
    for (p = &(L->elem[0]); p <= &(L->elem[L->length - 1]); p++)
    {
        if ((*compare)(*p, cur_e) == TRUE)
        {
            find = 1;
            break;
        }
    }
    if (find == 0)//û�ҵ���ָ��Ԫ����ͬ��Ԫ��
        return ERROR;

    if (p - L->elem != L->length - 1)
    {
        /*��p+1�����ÿ��Ԫ����ǰ�ƶ�һ��*/
        for (q = p + 1; q <= &(L->elem[L->length - 1]); q++)
        {
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
            strcpy(*(q - 1), *q);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
            memcpy(q - 1, q, sizeof(ElemType));
#else
            * (q - 1) = *q;
#endif
        }
    }

    L->length--;

    /*�ռ���С*/
    if (L->length >= 95 && L->length % 10 == 5 && L->listsize - L->length >= 15)
    {
        ElemType* newbase;
        newbase = (ElemType*)realloc(L->elem, (L->length + 5) * sizeof(ElemType));
        if (newbase == NULL)
            return LOVERFLOW;
        L->elem = newbase;
        L->listsize = L->length + 5;
    }

    return OK;
}


/*ɾ��ָ��Ԫ��cur_e,����ָ��ֵ��ͬ��Ԫ���ж������ȫ��ɾ�����ӿռ���С����*/
Status ListDelete2(sqlist* L, ElemType cur_e, Status(*compare)(ElemType e1, ElemType e2))
{
    ElemType* p, * q;
    int find = 0;
    for (p = &(L->elem[L->length - 1]); p >= &(L->elem[0]); p--)//�Ӻ���ǰ��
    {
        if ((*compare)(*p, cur_e) == TRUE)
        {
            find = 1;
            if (p - L->elem != L->length - 1)
            {
                /*����p�����Ԫ����ǰ��һ��*/
                for (q = p + 1; q <= &(L->elem[L->length - 1]); q++)
                {
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
                    strcpy(*(q - 1), *q);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
                    memcpy(q - 1, q, sizeof(ElemType));
#else
                    * (q - 1) = *q;
#endif
                }
            }
            L->length--;
            /*�ռ���С*/
            if (L->length >= 95 && L->length % 10 == 5 && L->listsize - L->length >= 15)
            {
                ElemType* newbase;
                newbase = (ElemType*)realloc(L->elem, (L->length + 5) * sizeof(ElemType));
                if (newbase == NULL)
                    return LOVERFLOW;
                L->elem = newbase;
                L->listsize = L->length + 5;
            }
        }
    }

    if (find == 0)//û�ҵ���ָ��Ԫ����ͬ��Ԫ��
        return ERROR;

    return OK;
}