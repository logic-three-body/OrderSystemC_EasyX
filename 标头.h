#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
typedef struct guest {   //结构体定义
	struct guest* pre;
	char num[13];
	char name[10];
	char call[12];
	char time[6];
	int sum;
	char whether[4];
	char table1[4];
	int table2;
	struct guest* next;
}gue, * pointer;         //别名
extern int i, table_number[5], time_number[7];
extern IMAGE start, img, b,l;
void Copy_head(pointer head, pointer h[])
{
	printf("copy\n");
	int i = 0;
	for (pointer p = head; p != NULL; p = p->next, i++)
	{
		h[i] = (pointer)calloc(1, sizeof(guest));
		if (h[i] == NULL)
		{
			printf("分配空间失败!");
			return; //结束函数
		}
		h[i] = p;
	}
}
//将链表的地址存入指针数组[100]，该数组用于记录顺序
int check_num(pointer head, char num[])
{
	pointer p = head; int flag = 0;
	//检查编号
	while (p != NULL)
	{
		if (strcmp(p->num, num) == 0)
		{
			//printf("已有相同的编号；");

			putimage(0, 0, &start);
			settextcolor(RED);
			outtextxy(250, 200, "已有相同的编号");
			settextcolor(RGB(250, 100, 100));
			Sleep(1000);
			return 1;
		}
		else
		{
			p = p->next;
		}
	}
	return 0;
}
int check_name(char num[])
{
	//检查名字
	int flag = 0, s = 0;
	for (int n = 0; n < 10; n++)
	{
		if ((num[n] > 64 && num[n] < 91) || (num[n] > 96 && num[n] < 123) || (num[n] <= 0 && num[n] > -90))
		{
	
			flag = 0;
		}
		else
		{
			
			flag = 1; break;
		}
	}
	for (int n = 0; n < 9; n++)
	{
		if (num[n] == num[n + 1])
		{
			s++;
		}
	}
	if (flag || s == 9)
	{
		putimage(0, 0, &start);
		settextcolor(RED);
		outtextxy(100, 200, "名字只能是汉字或英文字母（暂不接受不常用汉字）");
		settextcolor(RGB(250, 100, 100));
		Sleep(1000);
		return 1;
	}
	return 0;
}
int check_call(char num[])
{
	int flag = 0;
	for (int n = 0; n < 11; n++)
	{
		if (num[n] >= '0' && num[n] <= '9');
		else { flag = 1; break; }
	}
	if (flag)
	{
		putimage(0, 0, &start);
		settextcolor(RED);
		outtextxy(250, 200, "电话只能是11为的数字");
		settextcolor(RGB(250, 100, 100));
		Sleep(1000);
		return 1;
	}
	return 0;
}
int check_time(char num[])
{
	int flag = 0;
	for (int n = 0; n < 5 && flag != 1; n++)
	{
		switch (n)
		{
		case 0:if (num[n] >= '0' && num[n] <= '2'); else flag = 1; break;
		case 1:if (num[n] >= '0' && num[n] <= '9'); else flag = 1; break;
		case 2:if (num[n] == ':' || num[n] == '：'); else flag = 1; break;
		case 3:if (num[n] >= '0' && num[n] <= '5'); else flag = 1; break;
		case 4:if (num[n] >= '0' && num[n] <= '9'); else flag = 1; break;
		}
	}
	if (flag)
	{
		putimage(0, 0, &start);
		settextcolor(RED);
		outtextxy(250, 200, "时间格式**:**（24小时制）");
		settextcolor(RGB(250, 100, 100));
		Sleep(1000);
		return 1;
	}
	return 0;
}
//四个检查函数，编码查重，其余检查格式
void Input(pointer* head, pointer* tail, char write[], int YN)//输入函数，可循环执行
{
	char n[13] = { '\0' }, people[3] = { '\0' }, b[1] = { '\0' };
	pointer p, q, r;
	int check, j = 0; bool tf;
	for (int s = 1; s == 1; i++)//循环输入，i用于计总订单个数
	{
		for (check = 1; check == 1;)
		{
		
			q = *head; p = *tail;
			if (YN == 1)
			{
				for (int x = 0; x < 13; x++)
				{
					n[x] = '\0';
				}
				InputBox(n, 13, "请输入编号", "输入", "FPY201900001", 0);
				check = check_num(*head, n);
			}
			else
			{
				int k = 0;
				if (j == 0)
				{
					for (; k < 12 && write[j] != 9 && write[j] != 13 && write[j] != '\0'; j++, k++)
						n[k] = write[j];
					check = 0;
				}
				else
				{
					for (; write[j] != 10 && write[j] != '\0'; j++);
					for (j++; k < 12 && write[j] != 9 && write[j] != 13 && write[j] != '\0'; j++, k++)
						n[k] = write[j];
					check = 0;

				}
			}
			printf("%s\n", n);
		}
		r = (pointer)calloc(1, sizeof(guest));
		if (r == NULL)
		{
			printf("分配空间失败!");
			return; //结束函数
		}
		else printf("succse\n");
		if (q == NULL) { *tail = *head = r; }
		else {
			p->next = r;
			r->pre = p;
			(*tail) = r;
		}
		strcpy_s(r->num, n);
		for (check = 1; check == 1;)
		{
			printf("check\n");
			if (YN == 1)
			{
				for (int x = 0; x < 10; x++)
				{
					r->name[x] = '\0';
				}
				InputBox(r->name, 10, "请输入名字", "输入", "张三", 0);
				check = check_name(r->name);
				printf("%d\n", check_name(r->name));
				printf("%d\n", check);
			}
			else
			{
				int k = 0;
				for (; write[j] != 10 && write[j] != '\0'; j++);
				for (j++; k < 10 && write[j] != 9 && write[j] != 13 && write[j] != '\0'; j++, k++)
					r->name[k] = write[j];
				check = 0;
			}
			printf("%s\n", r->name);
		}
		for (check = 1; check == 1;)
		{
			if (YN == 1)
			{
				for (int x = 0; x < 12; x++)
				{
					r->call[x] = '\0';
				}
				InputBox(r->call, 12, "请输入电话", "输入", "15137607332", 0);
				check = check_call(r->call);
			}
			else
			{
				int k = 0;
				for (; write[j] != 10&&write[j]!='\0'; j++);
				for (j++; k < 11 && write[j] != 9 && write[j] != 13; j++, k++)
					r->call[k] = write[j];
				check = 0;
			}

			printf("%s\n", r->call);
		}
		for (check = 1; check == 1;)
		{
			if (YN == 1)
			{
				for (int x = 0; x < 6; x++)
				{
					r->time[x] = '\0';
				}
				InputBox(r->time, 6, "请输入时间", "输入", "12:30", 0);
				check = check_time(r->time);
			}
			else
			{
				int k = 0;
				for (; write[j] != 10 && write[j] != '\0'; j++);
				for (j++; k < 5 && write[j] != 9 && write[j] != 13 && write[j] != '\0'; j++, k++)
					r->time[k] = write[j];
				check = 0;
			}

			printf("%s\n", &r->time);
		}
		for (check = 1; check == 1;)
		{
			if (YN == 1)
			{
				InputBox(people, 3, "请输入人数", "输入", "0<人数<11", 0);
				if (people[1] == '\0')
				{
					r->sum = people[0] - 48;
				}
				else r->sum = (people[0] - 48) * 10 + people[1] - 48;
				if (r->sum > 0 && r->sum <= 10) check = 0;
				else check = 1;
			}
			else
			{
				int k = 0;	people[1] = { '\0' };
				for (; write[j] != 10 && write[j] != '\0'; j++);
				for (j++; k < 2 && write[j] != 13 && write[j] != 9 && write[j] != 0 && write[j] != '\0'; j++, k++)
					people[k] = write[j];
				printf("%s\n", people);
				if (people[1] == '\0')
				{
					r->sum = (int)people[0] - 48;
				}
				else r->sum = ((int)people[0] - 48) * 10 + (int)people[1] - 48;
				printf("%d\n", r->sum);
				check = 0;
			}
		}
		if (YN == 1)
		{
			tf = InputBox(b, 0, "是否继续录入数据", "提示", "确认继续,取消退出", 0, 0, false);
			if (tf);
			else  s = 0;;
		}
		else
		{
			if (write[j] == 0) s = 0;//判断是否结束读取
		}
	}
}
//输入函数兼具逐步和批量输入功能。有YN的值[0或1]决定使用哪个功能。write，批量输入时数据载体
void Output_p(pointer head, int n, int i)
{
	for (pointer p = head; p != NULL && i > 0; p = p->next, i--, n++)
	{
		char s[3] = { '\0' };
		outtextxy(55, 60 + n * 25, p->num);
		outtextxy(160, 60 + n * 25, p->name);
		outtextxy(202, 60 + n * 25, p->call);
		outtextxy(300, 60 + n * 25, p->time);
		if (p->sum == 10)
		{
			s[0] = '1', s[1] = '0';
		}
		else
		{
			s[0] = p->sum + 48;
		}
		outtextxy(358, 60 + n * 25, s);
		s[1] = '\0';
		outtextxy(413, 60 + n * 25, p->whether);
		outtextxy(482, 60 + n * 25, p->table1);
		s[0] = p->table2 + 48;
		outtextxy(490, 60 + n * 25, s);
		line(50, 78 + n * 25, 515, 78 + n * 25);
	}
	n--;
	line(50, 55, 50, 78 + n * 25);
	line(156, 55, 156, 78 + n * 25);
	line(197, 55, 197, 78 + n * 25);
	line(298, 55, 298, 78 + n * 25);
	line(341, 55, 341, 78 + n * 25);
	line(386, 55, 386, 78 + n * 25);
	line(460, 55, 460, 78 + n * 25);
	line(515, 55, 515, 78 + n * 25);
}
//输出储存信息从head（任意地址依赖Search函数查询）开始，i控制个数，n控制行数
void Output_h(pointer h[], int n,int j, int i)
{
	for (; h[n]!=NULL && i>0; n++,i--,j++)
	{
		char s[3] = { '\0' };
		outtextxy(55, 60 + j * 25, h[n]->num);
		outtextxy(160, 60 + j * 25, h[n]->name);
		outtextxy(202, 60 + j * 25, h[n]->call);
		outtextxy(300, 60 + j * 25, h[n]->time);
		if (h[n]->sum == 10)
		{
			s[0] = '1', s[1] = '0';
		}
		else
		{
			s[0] = h[n]->sum + 48;
		}
		outtextxy(358, 60 + j * 25, s);
		s[1] = '\0';
		outtextxy(413, 60 + j * 25, h[n]->whether);
		outtextxy(482, 60 + j * 25, h[n]->table1);
		s[0] = h[n]->table2 + 48;
		outtextxy(490, 60 + j * 25, s);
		line(50, 78 + j * 25, 515, 78 + j * 25);
	}
	j--;
	line(50, 55, 50, 78 + j * 25);
	line(156, 55, 156, 78 + j * 25);
	line(197, 55, 197, 78 + j * 25);
	line(298, 55, 298, 78 + j * 25);
	line(341, 55, 341, 78 + j * 25);
	line(386, 55, 386, 78 + j * 25);
	line(460, 55, 460, 78 + j * 25);
	line(515, 55, 515, 78 + j * 25);
}
//输出h[]中所有信息，功能同上
void Swap(pointer p, pointer q)//结构体内容交换
{
	pointer e;
	e = (pointer)calloc(1, sizeof(guest));
	if (e == NULL)
	{
		printf("分配空间失败!");
		return; //结束函数
	}

	strcpy_s(e->name, p->name);
	e->sum = p->sum;
	strcpy_s(e->call, p->call);
	strcpy_s(e->time, p->time);

	strcpy_s(p->name, q->name);
	p->sum = q->sum;
	strcpy_s(p->call, q->call);
	strcpy_s(p->time, q->time);

	strcpy_s(q->name, e->name);
	q->sum = e->sum;
	strcpy_s(q->call, e->call);
	strcpy_s(q->time, e->time);
}
//交换两个结构体的部分值，用于修改功能
pointer Search_num(pointer head, char s[])//查询数据所在地址
{
	pointer p = head;
	while (p != NULL)
	{
		if (strcmp(p->num, s) == 0)
		{
			return p;
		}
		else
			p = p->next;
	}
	return NULL;
}
pointer Search_name(pointer head, char s[])//字符查询
{
	//char name[15] = { '\0' }, 
	pointer p = head;
	//printf("请输入:");
	//scanf_s("%s", name, sizeof(name));
	while (p != NULL)
	{
		if (strcmp(p->name, s) == 0)
		{
			return p;
		}
		else
			p = p->next;
	}
	return NULL;

}
pointer Search_time(pointer head, char s1[], char s2[])
{
	pointer p = head;
	while (p != NULL)
	{
		if (strcmp(p->time, s1) >= 0 && strcmp(p->time, s2) < 0)
		{
			printf("name\n");
			return p;
		}
		else
			p = p->next;
	}
	return NULL;
}
//按输入查询信息，返回信息所在地址。无返回NULL
void Insert(pointer* head, pointer* s)//插入*head之前
{
	pointer p, q, r; char n[15]; int check;
	r = (pointer)calloc(1, sizeof(guest));
	if (r == NULL)
	{
		printf("分配空间失败!");
		return; //结束函数
	}
label1:
	printf("请输入编码：");
	scanf_s("%s", &n, sizeof(n));
	check = check_num(*head, n);
	if (check == 1)goto label1;
	strcpy_s(r->num, n);
	printf("请输入姓名：");
	scanf_s("%s", r->name, sizeof(r->name));
	printf("请输入用餐总人数：");
	scanf_s("%d", &r->sum);
	printf("请输入用餐时间：");
	scanf_s("%s", &r->time, sizeof(r->time));
	i++;//记录链表长度
	if (*head == *s)
	{
		p = *head; q = r;
		q->next = p; p->pre = q;
		(*head) = q;
	}
	else
	{
		q = *s, q = q->pre;
		p = *s;
		q->next = r, r->pre = q;
		r->next = p, p->pre = r;
	}

}
//依赖Search定向插入信息。未调用
void Modify(pointer s, pointer p)
{
	/*pointer p; char b = '\0';
	p = (pointer)calloc(1, sizeof(guest));
	if (p == NULL)
	{
		printf("分配空间失败!");
		return; //结束函数
	}*/

	/*printf("请输入姓名：");
	scanf_s("%s", p->name, sizeof(p->name));
	printf("请输入用餐总人数：");
	scanf_s("%d", &p->sum);
	printf("请输入用餐时间：");
	scanf_s("%s", &p->time, sizeof(p->time));
	printf("确认修改!");*/
	/*label2:
		scanf_s("%c", &b);
		if (b == 'n' || b == 'N')
		{
			return;
		}
		else if (b == 'y' || b == 'Y')
		{*/
	strcpy_s(s->name, p->name);
	strcpy_s(s->call, p->call);
	s->sum = p->sum;
	strcpy_s(s->time, p->time);
	//printf("已更改");
/*}
else
{
	printf("请输入y（继续）n（退出）"); goto label2;//回到y/n的输入出
}*/
}
//基于链表设计，因为可视化只能实现将p内的值赋给s
void Delete(pointer* head, pointer* s)
{
	pointer p, q;
	q = p = *s;
	i--;
	if (p == *head)//删去头地址
	{
		p = p->next;
		if (p != NULL) { p->pre = NULL; }
		free(*head);
		*head = p;
	}
	else
	{
		if (p->next == NULL)//删去尾地址
		{
			q = q->pre; q->next = NULL;
		}
		else//删去中间地址
		{
			q = q->pre; p = p->next;
			q->next = p; p->pre = q;
		}
		free(*s);
	}
}
//删除s内的信息
void Sort_num(pointer h[])
{
	char min[20]; int n = 0; int r; pointer e;
	for (int s = 0; s < i-1; s++)
	{
		r = s; strcpy_s(min, h[s]->num);
		for (n = s + 1; n < i; n++)
		{
			if (strcmp(min, h[n]->num) > 0)
			{
				strcpy_s(min, h[n]->num);
				r = n;
			}
		}
		e = h[s];
		h[s] = h[r];
		h[r] = e;
	}
}
void Sort_name(pointer h[])
{
	char min[20]; int n = 1; int r; pointer e;
	for (int s = 0; s < i-1; s++)
	{
		r = s; strcpy_s(min, h[s]->name);
		for (n = s + 1; n < i; n++)
		{
			if (strcmp(min, h[n]->name) > 0)
			{
				strcpy_s(min, h[n]->name);
				r = n;
			}
		}
		e = h[s];
		h[s] = h[r];
		h[r] = e;
	}
}
void Sort_time(pointer h[])
{
	char min[20]; int n = 1; int r; pointer e;
	for (int s = 0; s < i-1; s++)
	{
		r = s; strcpy_s(min, h[s]->time);
		for (n = s + 1; n < i; n++)
		{
			if (strcmp(min, h[n]->time) > 0)
			{
				strcpy_s(min, h[n]->time);
				r = n;
			}
		}
		e = h[s];
		h[s] = h[r];
		h[r] = e;
	}
}
void Sort_sum(pointer h[])
{
	int min; int n = 1; int r; pointer e;
	for (int s = 0; s < i-1; s++)
	{
		r = s; min = h[s]->sum;
		for (n = s + 1; n < i; n++)
		{
			if (min > h[n]->sum)
			{
				min = h[n]->sum;
				r = n;
			}
		}
		e = h[s];
		h[s] = h[r];
		h[r] = e;
	}
}
//选择法排序，排列h[]中的指针顺序
void Arrange(pointer h[], int i)//记录订餐结果,统计餐桌数，个时间人数
{
	printf("arrange\n");
	char Time[8][6] = { {"11:00"} ,{"11:30"}, {"12:00"}, {"12:30"}, {"13:00"}, {"13:30"} ,{"2:00"} };
	//char Timew[8][6] = { {"17:00"} ,{"17:30"}, {"18:00"}, {"18:30"}, {"19:00"}, {"19:30"} ,{"2:00"} };晚餐时间
	int A = 5, B = 5, C = 5;
	for (int n = 0; n < 6; n++)
	{
		time_number[n] = 0;
	}
	for (int n = 0; n < i; n++)
	{
		for (int t = 0; t < 6; t++)
		{
			if (strcmp(h[n]->time, Time[t]) >= 0 && strcmp(h[n]->time, Time[t + 1]) < 0)
			{
				time_number[t]++;
			}
		}
		if (h[n]->sum <= 4)
		{
			if (C > 0)
			{
				strcpy_s(h[n]->whether, "是"); C--;
				strcpy_s(h[n]->table1, "C");
				h[n]->table2 = 5 - C;
			}
			else strcpy_s(h[n]->whether, "否");
		}
		else if (h[n]->sum >= 8)
		{
			if (A > 0)
			{
				strcpy_s(h[n]->whether, "是"); A--;
				strcpy_s(h[n]->table1, "A");
				h[n]->table2 = 5 - A;
			}
			else strcpy_s(h[n]->whether, "否");
		}
		else
		{
			if (B > 0)
			{
				strcpy_s(h[n]->whether, "是"); B--;
				strcpy_s(h[n]->table1, "B");
				h[n]->table2 = 5 - B;
			}
			else strcpy_s(h[n]->whether, "否");
		}
	}
	table_number[1] = 5 - A;
	table_number[2] = 5 - B;
	table_number[3] = 5 - C;
	table_number[4] = 15 - A - B - C;
}
//安排订单的餐桌。同时用全局变量记录时间和餐桌的信息
void Statisics(pointer h[])//负责输出统计结果，统计结果有Arrange函数提供
{
	int i;//字符转数字
	char c[3];
	char Time[8][6] = { {"11:00"} ,{"11:30"}, {"12:00"}, {"12:30"}, {"13:00"}, {"13:30"} ,{"14:00"} };
	outtextxy(80, 70, "时间分段统计：圆圈中数字表示大于等于前一个小于后一个的个数");
	rectangle(95, 95, 532, 120);
	for (int show = 0; show < 7; show++)
	{
		outtextxy(100 + 65 * show, 100, Time[show]);
	}
	for (int show = 0; show < 6; show++)
	{
		i = time_number[show];
		if (i < 0) break;
		sprintf_s(c, "%d", i);//字符转数字
		if (i < 10)	outtextxy(147 + 65 * show, 100, c);
		else	outtextxy(143 + 65 * show, 100, c);
		circle(150 + 65 * show, 107, 11);
	}
	outtextxy(100, 200, "大餐桌（A）：");
	outtextxy(100, 225, "中餐桌（B）：");
	outtextxy(100, 250, "小餐桌（C）：");
	outtextxy(100, 275, "总餐桌个数 ：");

	for (int show = 1; show <= 4; show++)
	{
		i = table_number[show];
		if (i < 0) break;
		sprintf_s(c, "%d", i);
		outtextxy(200, 175 + show * 25, c);
	}
}
//负责输出统计信息。信息有Arrange提供
//---------------------------------------------以上为功能函数
//---------------------------------------------以下为内容输出函数
void Output_code()
{
	putimage(0, 0, &b);
	setbkcolor(GREEN);
	outtextxy(140, 100, "欢");
	Sleep(300);
	outtextxy(240, 100, "迎");
	Sleep(300);
	outtextxy(340, 100, "使");
	Sleep(300);
	outtextxy(440, 100, "用");
	Sleep(500);
	outtextxy(140, 200, "中");
	Sleep(300);
	outtextxy(240, 200, "南");
	Sleep(300);
	outtextxy(340, 200, "大");
	Sleep(300);
	outtextxy(440, 200, "学");
	Sleep(500);
	outtextxy(40, 300, "电");
	Sleep(300);
	outtextxy(140, 300, "话");
	Sleep(300);
	outtextxy(240, 300, "订");
	Sleep(300);
	outtextxy(340, 300, "餐");
	Sleep(300);
	outtextxy(440, 300, "系");
	Sleep(300);
	outtextxy(540, 300, "统");
	Sleep(500);
	setbkcolor(BLACK);
}
//进入动画
void start_output(void)
{
	putimage(0, 0, &start);
	setbkmode(TRANSPARENT);//字符背景透明
	settextcolor(RGB(250, 100, 100));//设置字体颜色
	setlinecolor(RGB(200, 10, 10));//设置线条颜色
	for (int x = 45, y = 70; y <= 280; x += 30, y += 30)//多个矩形框
	{
		rectangle(275, x, 377, y);
	}
	outtextxy(305, 50, "主菜单");
	outtextxy(280, 80, "输入客户信息");
	outtextxy(280, 110, "查找客户信息");
	outtextxy(280, 140, "删除客户信息");
	outtextxy(280, 170, "更改客户信息");
	outtextxy(288, 200, "排序与显示");
	outtextxy(280, 230, "统计用户信息");
	outtextxy(295, 260, "退出系统");
}
//菜单
void SR_output(void)
{
	putimage(0, 0, &start);
	rectangle(275, 75, 377, 100);
	outtextxy(295, 80, "批量输入");
	rectangle(275, 105, 377, 130);
	outtextxy(295, 110, "逐个输入");
	rectangle(275, 135, 377, 160);
	outtextxy(310, 140, "返回");
}
//输入
void PX_output(void)
{
	putimage(0, 0, &start);
	rectangle(275, 75, 377, 100);
	outtextxy(295, 80, "原始顺序");
	rectangle(275, 105, 377, 130);
	outtextxy(295, 110, "编号降序");
	rectangle(275, 135, 377, 160);
	outtextxy(295, 140, "姓名降序");
	rectangle(275, 165, 377, 190);
	outtextxy(295, 170, "时间降序");
	rectangle(275, 195, 377, 220);
	outtextxy(295, 200, "人数降序");
	rectangle(275, 225, 377, 250);
	outtextxy(310, 230, "返回");
}
//排序
void CX_output(void)
{
	putimage(0, 0, &start);
	rectangle(275, 75, 377, 100);
	outtextxy(279, 80, "按照编号查询");
	rectangle(275, 105, 377, 130);
	outtextxy(279, 110, "按照姓名查询");
	rectangle(275, 135, 377, 160);
	outtextxy(279, 140, "按照时间查询");
	rectangle(275, 165, 377, 190);
	outtextxy(310, 170, "返回");
}
//查询
void Output_gailan(void)
{
	putimage(0, 0, &start);
	outtextxy(95, 60, "编号");
	outtextxy(160, 60, "姓名");
	outtextxy(230, 60, "电话");
	outtextxy(303, 60, "时间");
	outtextxy(347, 60, "人数");
	outtextxy(390, 60, "是否成功");
	outtextxy(465, 60, "桌子号");
	line(50, 55, 515, 55);
	line(50, 78, 515, 78);
	line(50, 55, 50, 78);
	line(156, 55, 156, 78);
	line(197, 55, 197, 78);
	line(298, 55, 298, 78);
	line(341, 55, 341, 78);
	line(386, 55, 386, 78);
	line(460, 55, 460, 78);
	line(515, 55, 515, 78);

}
//目录
void last_output(void)
{
	putimage(0, 0, &l);
	Sleep(1500);
}
//结尾thanks
//----------------------------------------------鼠标点击返回函数
void Return_(void)
{
	settextcolor(RGB(250, 100, 100));
	rectangle(560, 440, 630, 470);
	outtextxy(582, 448, "返回");
	while (1)
	{
		MOUSEMSG tj = GetMouseMsg();
		if (tj.x >= 560 && tj.x <= 630 && tj.y >= 440 && tj.y <= 470 && tj.mkLButton)
		{
			break;
		}
	}
}
//提供一个返回按钮
void Return_output(void)
{
	rectangle(560, 360, 630, 390);
	outtextxy(572, 368, "上一页");
	rectangle(560, 400, 630, 430);
	outtextxy(572, 408, "下一页");
	rectangle(560, 440, 630, 470);
	outtextxy(582, 448, "返回");
}
/*提供三个按钮，目前只实现了返回功能
由于屏幕大小有限，翻页功能暂未实现，排序后最多只能显示15份数据（可以加大屏幕，但只能勉强解决）*/


