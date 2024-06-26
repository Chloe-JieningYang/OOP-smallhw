/* 班级 学号 姓名 */
#include <iostream>
#include <string> //C++ string类 需要用到
using namespace std;

struct student {
	string name;
	int num;
	char sex;
	struct student *next;//指向结构体自身的指针(下个结点)
};

#define OK	1
#define ERROR	0

int linklist_create(student **phead);
int linklist_traverse(student *head);
int linklist_destroy(student *head);

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int linklist_create(student **phead)
{
	student *p = NULL, *q = NULL;
	int i;

	for (i = 0; i < 5; i++) {
		if (i > 0)
			q = p;
		p = new(nothrow) student; //思考：为什么不能用malloc
		if (p == NULL)
			return ERROR;	//注:此处未释放之前的链表节点，就借助操作系统来释放（非标用法）
		if (i == 0)
			*phead = p; //head指向第1个结点
		else
			q->next = p;
		cout << "请输入第" << i + 1 << "个人的基本信息" << endl;
		cin >> p->name >> p->num >> p->sex; //键盘输入基本信息
		p->next = NULL;
	}
	return OK;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int linklist_traverse(student *head)
{
	student *p;

	p = head; //p复位，指向第1个结点
	while (p != NULL) { //循环进行输出
		cout << p->name << " " << p->num << " " << p->sex << endl;
		p = p->next;
	}
	return OK;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int linklist_destroy(student *head)
{
	student *p, *q;

	p = head; //p复位，指向第1个结点
	while (p) {  //循环进行各结点释放
		q = p->next;
		delete p;
		p = q;
	}
	return OK;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	student *head = NULL;

	if (linklist_create(&head) == OK) {
		linklist_traverse(head);
		linklist_destroy(head);
	}
	else
		cout << "LinkList Create failed." << endl;

	return 0;
}
