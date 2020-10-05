//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<Windows.h>
#include"标头.h"
int i = 0;//记录链表长度
int table_number[5] = { 0 }; int time_number[7] = { 0 };//统计信息记录
IMAGE start;//主图片
IMAGE img, b, l;
int main()
{
	initgraph(640, 480);
	char code[7]; MOUSEMSG m_start; int check = 1;//check用于保证只判断一次退出，因为鼠标消息太灵敏了。
	pointer head = NULL, tail = NULL;
	pointer h[100] = { NULL };//保存链表的地址，加快排序
	//pointer h_[100] = { NULL };//本想用于跳表查询，记录上级指针
	//-----------------------------------------------------------------------------------------------------------定义
	loadimage(&img, "a.jpg", 640, 480);
	loadimage(&b, "b.jpg", 640, 480);
	loadimage(&l, "l.gif", 640, 480);
	loadimage(&start, "start.jpg", 640, 480);//刷新屏幕
	//----------------------------------------------------------------------------------------------------------加载图片
	putimage(0, 0, &img);
	InputBox(code, 7, "请输入密码", "密码", "六位相同的数字", 0, 0);//考虑账户申请
	if (strcmp(code, "666666") == 0)
	{
		putimage(0, 0, &start);
		settextcolor(BLUE);
		settextstyle(50, 0, ("华文彩云"));
		Output_code();
		settextstyle(18, 8, ("新宋体"));
		settextcolor(WHITE);
	}
	else
	{
		for (int i = 0; i == 0;)
		{
			InputBox(code, 7, "请重新输入", "密码错误", 0, 0);
			if (strcmp(code, "666666") == 0)
			{
				settextcolor(BLUE);
				settextstyle(50, 0, ("华文彩云"));
				Output_code();
				i = 1;//增加音效
				settextstyle(20, 8, ("楷体"));
				settextcolor(WHITE);
			}
			else i = 0;
		}
	}
	//------------------------------------------------------------------------------------------------------登录密码与动画
	for (int i1 = 1; i1 == 1;)
	{
		start_output();
		for (int i2 = 1; i2 == 1;)
		{
			if (check == -3)//-------------------------------------------------------------------------保证退出系统正常，消耗鼠标反应
			{
				check++;
				start_output();
			}
			else if (check == 1);
			else
			{
				check++;
				start_output();
			}
			m_start = GetMouseMsg();//-------------------------------------------------------------------------------------主菜单控制部分
			if (m_start.x >= 275 && m_start.x <= 377 && m_start.y >= 75 && m_start.y <= 100 && m_start.mkLButton)
			{
				int checksr = 1;
				SR_output();
				while (1)
				{
					if (checksr == -5)//保证返回系统正常，消耗鼠标反应
					{
						checksr++;
						SR_output();
					}
					else if (checksr == 1);
					else
					{
						checksr++;
						SR_output();
					}
					MOUSEMSG sr = GetMouseMsg();
					if (sr.x >= 275 && sr.x <= 377 && sr.y >= 75 && sr.y <= 100 && sr.mkLButton && checksr == 1)
					{
						//批量输入
						char plsr[540];
						putimage(0, 0, &start);
						InputBox(plsr, 540, "在此输入不做格式检查，请确认数据格式无误后，复制粘贴到输入框中中", "请输入顾客信息", "一次输入最多10份信息，以回车隔开每个数据", 300, 400);
						Input(&head, &tail, plsr, 0);
						Copy_head(head, h);
						Arrange(h, i);
						checksr = -5;
						break;
					}
					if (sr.x >= 275 && sr.x <= 377 && sr.y >= 105 && sr.y <= 130 && sr.mkLButton && checksr == 1)
					{
						//逐个输入
						char s[1] = { '\0' };
						putimage(0, 0, &start);
						Input(&head, &tail, s, 1);
						Copy_head(head, h);
						Arrange(h, i);
						checksr = -5;
					}
					if (sr.x >= 275 && sr.x <= 377 && sr.y >= 135 && sr.y <= 160 && sr.mkLButton)
					{
						//返回
						break;
					}
				}
				break;
			}
			//输入
			if (m_start.x >= 275 && m_start.x <= 377 && m_start.y >= 105 && m_start.y <= 130 && m_start.mkLButton)
			{

				MOUSEMSG cx = GetMouseMsg();
				int checksr = 1;
			lable1:
				putimage(0, 0, &start);
				CX_output();
				while (1)
				{
					if (check == -3)//保证退出系统正常
					{
						check++;
						CX_output();
					}
					else if (check == 1);
					else
					{
						check++;
						CX_output();
					}
					MOUSEMSG sr = GetMouseMsg();
					if (sr.x >= 275 && sr.x <= 377 && sr.y >= 75 && sr.y <= 100 && sr.mkLButton && check == 1)
					{
						//编号查询
						char num_[13]; pointer p_num;
						InputBox(num_, 13, "请输入订餐编号", "编号输入", "FPY201900001", 0, 0);
						p_num = Search_num(head, num_);
						if (p_num == NULL)
						{
							putimage(0, 0, &start);
							settextcolor(RED);
							outtextxy(290, 200, "没有查询到");
							settextcolor(RGB(250, 100, 100));
							Sleep(1000); check = -3;
							goto lable1;
						}
						else
						{
							Output_gailan();
							Output_p(p_num, 1, 1);
							rectangle(560, 440, 630, 470);
							outtextxy(582, 448, "返回");
							MOUSEMSG yssx;
							while (1)
							{
								yssx = GetMouseMsg();
								if (yssx.x >= 275 && yssx.x <= 377 && yssx.y >= 195 && yssx.y <= 220 && yssx.mkLButton)
								{

								}
								if (yssx.x >= 275 && yssx.x <= 377 && yssx.y >= 195 && yssx.y <= 220 && yssx.mkLButton)
								{

								}
								if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
								{
									//返回上一级
									goto lable1;
								}
							}
						}

					}
					if (sr.x >= 275 && sr.x <= 377 && sr.y >= 105 && sr.y <= 130 && sr.mkLButton && check == 1)
					{
						//姓名查询
						char name_[10]; pointer p_name = head; int h = 1, flag = 0; MOUSEMSG yssx;
						InputBox(name_, 10, "请输入订餐者姓名", "姓名输入", "张三", 0, 0);
						for (h = 1, Output_gailan(); p_name != NULL; h++)
						{
							p_name = Search_name(p_name, name_);
							if (p_name != NULL)flag = 1;
							Output_p(p_name, h, 1);
							rectangle(560, 440, 630, 470);
							outtextxy(582, 448, "返回");
							if (p_name != NULL)
							{
								p_name = p_name->next;
							}
						}
						if (flag)
						{

							while (1)
							{
								yssx = GetMouseMsg();
								if (yssx.x >= 275 && yssx.x <= 377 && yssx.y >= 195 && yssx.y <= 220 && yssx.mkLButton)
								{

								}
								if (yssx.x >= 275 && yssx.x <= 377 && yssx.y >= 195 && yssx.y <= 220 && yssx.mkLButton)
								{

								}
								if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
								{
									goto lable1;
								}
							}
						}
						else
						{
							putimage(0, 0, &start);
							settextcolor(RED);
							outtextxy(290, 200, "没有查询到");
							settextcolor(RGB(250, 100, 100));
							Sleep(1000); check = -3;
							goto lable1;
						}
					}
					if (sr.x >= 275 && sr.x <= 377 && sr.y >= 135 && sr.y <= 160 && sr.mkLButton && check == 1)
					{
						//时间查询
						char time1[6], time2[6]; pointer p_time = head; int h = 1, flag = 0; MOUSEMSG yssx;
						InputBox(time1, 6, "请输入起始订餐时间", "时间输入", "12:30", 0, 0);
						InputBox(time2, 6, "请输入结束订餐时间", "时间输入", "12:30", 0, 0);
						for (h = 1, Output_gailan(); p_time != NULL; h++)
						{
							p_time = Search_time(p_time, time1, time2);
							if (p_time != NULL)flag = 1;
							Output_p(p_time, h, 1);
							rectangle(560, 440, 630, 470);
							outtextxy(582, 448, "返回");
							if (p_time != NULL)
							{
								p_time = p_time->next;
							}
						}
						if (flag)
						{

							while (1)
							{
								yssx = GetMouseMsg();
								if (yssx.x >= 275 && yssx.x <= 377 && yssx.y >= 195 && yssx.y <= 220 && yssx.mkLButton)
								{

								}
								if (yssx.x >= 275 && yssx.x <= 377 && yssx.y >= 195 && yssx.y <= 220 && yssx.mkLButton)
								{

								}
								if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
								{
									goto lable1;
								}
							}
						}
						else
						{
							putimage(0, 0, &start);
							settextcolor(RED);
							outtextxy(290, 200, "没有查询到");
							settextcolor(RGB(250, 100, 100));
							Sleep(1000); check = -3;
							goto lable1;
						}
					}
					if (sr.x >= 275 && sr.x <= 377 && sr.y >= 165 && sr.y <= 190 && sr.mkLButton)
					{
						//返回
						break;
					}
				}
				break;
			}
			//查找
			if (m_start.x >= 275 && m_start.x <= 377 && m_start.y >= 135 && m_start.y <= 160 && m_start.mkLButton)
			{
				putimage(0, 0, &start); int flag = 0;
				char num_[13]; pointer p_num;
				InputBox(num_, 13, "请输入订餐编号", "编号输入", "FPY201900001", 0, 0);
				p_num = Search_num(head, num_);
				if (p_num == NULL)
				{
					putimage(0, 0, &start);
					settextcolor(RED);
					outtextxy(290, 200, "没有查询到");
					settextcolor(RGB(250, 100, 100));
					Return_(); break;
				}
				else
				{
					char n[1]; bool b; MOUSEMSG tj;
					Output_gailan();
					Output_p(p_num, 1, 1);
					rectangle(560, 400, 630, 430);
					outtextxy(582, 408, "返回");
					rectangle(560, 440, 630, 470);
					outtextxy(582, 448, "确认");
					while (1)
					{
						tj = GetMouseMsg();
						if (tj.x >= 560 && tj.x <= 630 && tj.y >= 400 && tj.y <= 430 && tj.mkLButton)
						{
							flag = 1; break;
						}
						if (tj.x >= 560 && tj.x <= 630 && tj.y >= 440 && tj.y <= 470 && tj.mkLButton)
						{
							break;
						}
					}
					if (flag) { break; }
					b = InputBox(n, 0, "确认删除此信息", "删除确认", "确认删除，取消返回", 0, 0, false);
					if (b)
					{
						Delete(&head, &p_num);
						Copy_head(head, h);
						Arrange(h, i);
						putimage(0, 0, &start);
						settextcolor(GREEN);
						outtextxy(250, 250, "删除成功");
						settextcolor(RGB(250, 100, 100));
						Sleep(1000);
						break;
					}
					else
					{
						break;
					}
				}
			}
			//删除
			if (m_start.x >= 275 && m_start.x <= 377 && m_start.y >= 165 && m_start.y <= 190 && m_start.mkLButton)
			{
				putimage(0, 0, &start); int flag = 0; int checkgg;
				char num_[13]; pointer p_num;
				InputBox(num_, 13, "请输入订餐编号", "编号输入", "FPY201900001", 0, 0);
				p_num = Search_num(head, num_);
				if (p_num == NULL)
				{
					putimage(0, 0, &start);
					settextcolor(RED);
					outtextxy(290, 200, "没有查询到");
					settextcolor(RGB(250, 100, 100));
					Return_(); break;
				}
				else
				{
					char n[1]; bool b; MOUSEMSG tj; pointer r; char people[3] = { '\0' };
					r = (pointer)calloc(1, sizeof(guest));
					if (r == NULL)
					{
						putimage(0, 0, &start);
						settextcolor(RED);
						outtextxy(0, 0, "分配空间失败!");
						settextcolor(RGB(250, 100, 100));
						system("pause");
					}
					Output_gailan();
					Output_p(p_num, 1, 1);
					rectangle(560, 400, 630, 430);
					outtextxy(582, 408, "返回");
					rectangle(560, 440, 630, 470);
					outtextxy(582, 448, "确认");
					while (1)
					{
						tj = GetMouseMsg();
						if (tj.x >= 560 && tj.x <= 630 && tj.y >= 400 && tj.y <= 430 && tj.mkLButton)
						{
							flag = 1;
							break;
						}
						if (tj.x >= 560 && tj.x <= 630 && tj.y >= 440 && tj.y <= 470 && tj.mkLButton)
						{
							break;
						}
					}
					if (flag) break;
					for (checkgg = 1; checkgg == 1;)
					{
						InputBox(r->name, 10, "请输入名字", "输入", "张三", 0);
						checkgg = check_name(r->name);
					}
					for (checkgg = 1; checkgg == 1;)
					{
						InputBox(r->call, 12, "请输入电话", "输入", "15137607332", 0);
						checkgg = check_call(r->call);
					}
					for (checkgg = 1; checkgg == 1;)
					{
						InputBox(r->time, 6, "请输入时间", "输入", "12:30", 0);
						checkgg = check_time(r->time);
					}
					for (checkgg = 1; checkgg == 1;)
					{
						InputBox(people, 3, "请输入人数", "输入", "0<人数<11", 0);
						if (people[1] == '\0')
						{
							r->sum = people[0] - 48;
						}
						else r->sum = (people[0] - 48) * 10 + people[1] - 48;
						if (r->sum > 0 && r->sum <= 10) checkgg = 0;
						else checkgg = 1;
					}
					Output_gailan();
					Output_p(p_num, 1, 1);
					Swap(r, p_num);
					Arrange(h, i);
					Output_p(p_num, 2, 1);
					while (1)
					{
						tj = GetMouseMsg();
						if (tj.x >= 560 && tj.x <= 630 && tj.y >= 440 && tj.y <= 470 && tj.mkLButton)
						{
							break;
						}
					}
					b = InputBox(n, 0, "确认更改此信息", "更改确认", "确认更改，取消返回", 0, 0, false);
					if (b)
					{
						putimage(0, 0, &start);
						settextcolor(GREEN);
						outtextxy(250, 200, "更改成功");
						settextcolor(RGB(250, 100, 100));
						Sleep(1000);
						break;
					}
					else
					{
						Swap(r, p_num);
						Arrange(h, i);
						break;
					}
					break;
				}
			}
			//更改
			if (m_start.x >= 275 && m_start.x <= 377 && m_start.y >= 195 && m_start.y <= 220 && m_start.mkLButton)
			{
				MOUSEMSG sr;
			lable://返回本级
				putimage(0, 0, &start);
				PX_output();
				while (1)
				{
					sr = GetMouseMsg();//五个排序方式，一个返回
					if (sr.x >= 275 && sr.x <= 377 && sr.y >= 75 && sr.y <= 100 && sr.mkLButton)
					{
						int th = i; pointer p = head; int flag = 0;
						Output_gailan();
						if (i <= 15)
						{
							Output_p(head, 1, i);
						}
						else Output_p(head, 1, 15);
						Return_output();
						MOUSEMSG yssx;
						while (1)
						{
							yssx = GetMouseMsg();
						up:
							if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 360 && yssx.y <= 390 && yssx.mkLButton&&flag>0)
							{
								printf("上一页");
								flag--;
								for (int i = 0; i < 15; i++)
								{
									p = p->pre;
								}
								Output_gailan();
								Return_output();
								th = th + 15;
								if (th <= 15)
								{
									Output_p(p, 1, th);
								}
								else Output_p(p, 1, 15);
								while (1)
								{
									yssx = GetMouseMsg();
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 360 && yssx.y <= 390 && yssx.mkLButton && flag > 0)
									{
										goto up;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 400 && yssx.y <= 430 && yssx.mkLButton && th > 15)
									{
										goto down;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
									{
										goto lable;
									}
								}
							}
						down:
							if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 400 && yssx.y <= 430 && yssx.mkLButton&&th>15)
							{
								flag++; printf("下一页");
								for (int i = 0; i < 15; i++)
								{
									p = p->next;
								}
								Output_gailan();
								Return_output();
								th = th - 15;
								if (th <= 15)
								{
									Output_p(p, 1, th);
								}
								else Output_p(p, 1, 15);
								while (1)
								{
									yssx = GetMouseMsg();
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 360 && yssx.y <= 390 && yssx.mkLButton && flag > 0)
									{
										goto up;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 400 && yssx.y <= 430 && yssx.mkLButton && th > 15)
									{
										goto down;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
									{
										goto lable;
									}
								}
							}
							if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
							{
								goto lable;
							}
						}
						break;
					}
					if (sr.x >= 275 && sr.x <= 377 && sr.y >= 105 && sr.y <= 130 && sr.mkLButton)
					{
						int th = i,head=0, flag = 0;
						Output_gailan();
						Sort_num(h);
						if (i <= 15)
						{
							Output_h(h, head, 1, i);
						}
						else Output_h(h,head, 1, 15);
						Return_output();
						MOUSEMSG yssx;
						while (1)
						{
							yssx = GetMouseMsg();
						up_num:
							if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 360 && yssx.y <= 390 && yssx.mkLButton && flag > 0)
							{
								printf("上一页");
								flag--;
								head = head - 15;
								Output_gailan();
								Return_output();
								th = th + 15;
								if (th <= 15)
								{
									Output_h(h,head, 1, th);
								}
								else Output_h(h,head, 1, 15);
								while (1)
								{
									yssx = GetMouseMsg();
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 360 && yssx.y <= 390 && yssx.mkLButton && flag > 0)
									{
										goto up_num;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 400 && yssx.y <= 430 && yssx.mkLButton && th > 15)
									{
										goto down_num;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
									{
										goto lable;
									}
								}
							}
						down_num:
							if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 400 && yssx.y <= 430 && yssx.mkLButton && th > 15)
							{
								flag++; printf("下一页");
								head = head + 15;
								Output_gailan();
								Return_output();
								th = th - 15;
								if (th <= 15)
								{
									Output_h(h, head, 1, th);
								}
								else Output_h(h, head, 1, 15);
								while (1)
								{
									yssx = GetMouseMsg();
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 360 && yssx.y <= 390 && yssx.mkLButton && flag > 0)
									{
										goto up_num;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 400 && yssx.y <= 430 && yssx.mkLButton && th > 15)
									{
										goto down_num;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
									{
										goto lable;
									}
								}
							}
							if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
							{
								goto lable;
							}
						}
						break;
					}
					if (sr.x >= 275 && sr.x <= 377 && sr.y >= 135 && sr.y <= 160 && sr.mkLButton)
					{
						int th = i, head = 0, flag = 0;
						Output_gailan();
						Sort_name(h);
						if (i <= 15)
						{
							Output_h(h, head, 1, i);
						}
						else Output_h(h, head, 1, 15);
						Return_output();
						MOUSEMSG yssx;
						while (1)
						{
							yssx = GetMouseMsg();
						up_name:
							if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 360 && yssx.y <= 390 && yssx.mkLButton && flag > 0)
							{
								printf("上一页");
								flag--;
								head = head - 15;
								Output_gailan();
								Return_output();
								th = th + 15;
								if (th <= 15)
								{
									Output_h(h, head, 1, th);
								}
								else Output_h(h, head, 1, 15);
								while (1)
								{
									yssx = GetMouseMsg();
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 360 && yssx.y <= 390 && yssx.mkLButton && flag > 0)
									{
										goto up_name;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 400 && yssx.y <= 430 && yssx.mkLButton && th > 15)
									{
										goto down_name;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
									{
										goto lable;
									}
								}
							}
						down_name:
							if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 400 && yssx.y <= 430 && yssx.mkLButton && th > 15)
							{
								flag++; printf("下一页");
								head = head + 15;
								Output_gailan();
								Return_output();
								th = th - 15;
								if (th <= 15)
								{
									Output_h(h, head, 1, th);
								}
								else Output_h(h, head, 1, 15);
								while (1)
								{
									yssx = GetMouseMsg();
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 360 && yssx.y <= 390 && yssx.mkLButton && flag > 0)
									{
										goto up_name;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 400 && yssx.y <= 430 && yssx.mkLButton && th > 15)
									{
										goto down_name;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
									{
										goto lable;
									}
								}
							}
							if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
							{
								goto lable;
							}
						}
						break;
					}
					if (sr.x >= 275 && sr.x <= 377 && sr.y >= 165 && sr.y <= 190 && sr.mkLButton)
					{
						int th = i, head = 0, flag = 0;
						Output_gailan();
						Sort_time(h);
						if (i <= 15)
						{
							Output_h(h, head, 1, i);
						}
						else Output_h(h, head, 1, 15);
						Return_output();
						MOUSEMSG yssx;
						while (1)
						{
							yssx = GetMouseMsg();
						up_time:
							if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 360 && yssx.y <= 390 && yssx.mkLButton && flag > 0)
							{
								printf("上一页");
								flag--;
								head = head - 15;
								Output_gailan();
								Return_output();
								th = th + 15;
								if (th <= 15)
								{
									Output_h(h, head, 1, th);
								}
								else Output_h(h, head, 1, 15);
								while (1)
								{
									yssx = GetMouseMsg();
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 360 && yssx.y <= 390 && yssx.mkLButton && flag > 0)
									{
										goto up_time;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 400 && yssx.y <= 430 && yssx.mkLButton && th > 15)
									{
										goto down_time;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
									{
										goto lable;
									}
								}
							}
						down_time:
							if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 400 && yssx.y <= 430 && yssx.mkLButton && th > 15)
							{
								flag++; printf("下一页");
								head = head + 15;
								Output_gailan();
								Return_output();
								th = th - 15;
								if (th <= 15)
								{
									Output_h(h, head, 1, th);
								}
								else Output_h(h, head, 1, 15);
								while (1)
								{
									yssx = GetMouseMsg();
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 360 && yssx.y <= 390 && yssx.mkLButton && flag > 0)
									{
										goto up_time;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 400 && yssx.y <= 430 && yssx.mkLButton && th > 15)
									{
										goto down_time;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
									{
										goto lable;
									}
								}
							}
							if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
							{
								goto lable;
							}
						}
						break;
					}
					if (sr.x >= 275 && sr.x <= 377 && sr.y >= 195 && sr.y <= 220 && sr.mkLButton)
					{
						int th = i, head = 0, flag = 0;
						Output_gailan();
						Sort_sum(h);
						if (i <= 15)
						{
							Output_h(h, head, 1, i);
						}
						else Output_h(h, head, 1, 15);
						Return_output();
						MOUSEMSG yssx;
						while (1)
						{
							yssx = GetMouseMsg();
						up_sum:
							if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 360 && yssx.y <= 390 && yssx.mkLButton && flag > 0)
							{
								printf("上一页");
								flag--;
								head = head - 15;
								Output_gailan();
								Return_output();
								th = th + 15;
								if (th <= 15)
								{
									Output_h(h, head, 1, th);
								}
								else Output_h(h, head, 1, 15);
								while (1)
								{
									yssx = GetMouseMsg();
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 360 && yssx.y <= 390 && yssx.mkLButton && flag > 0)
									{
										goto up_sum;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 400 && yssx.y <= 430 && yssx.mkLButton && th > 15)
									{
										goto down_sum;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
									{
										goto lable;
									}
								}
							}
						down_sum:
							if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 400 && yssx.y <= 430 && yssx.mkLButton && th > 15)
							{
								flag++; printf("下一页");
								head = head + 15;
								Output_gailan();
								Return_output();
								th = th - 15;
								if (th <= 15)
								{
									Output_h(h, head, 1, th);
								}
								else Output_h(h, head, 1, 15);
								while (1)
								{
									yssx = GetMouseMsg();
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 360 && yssx.y <= 390 && yssx.mkLButton && flag > 0)
									{
										goto up_sum;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 400 && yssx.y <= 430 && yssx.mkLButton && th > 15)
									{
										goto down_sum;
									}
									if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
									{
										goto lable;
									}
								}
							}
							if (yssx.x >= 560 && yssx.x <= 630 && yssx.y >= 440 && yssx.y <= 470 && yssx.mkLButton)
							{
								goto lable;
							}
						}
						break;
					}
					if (sr.x >= 275 && sr.x <= 377 && sr.y >= 225 && sr.y <= 250 && sr.mkLButton)
					{
						break;
					}
				}
				break;
			}
			//显示&&排序
			if (m_start.x >= 275 && m_start.x <= 377 && m_start.y >= 225 && m_start.y <= 250 && m_start.mkLButton)
			{
				MOUSEMSG tj;
				putimage(0, 0, &start);
				Statisics(h);
				rectangle(560, 440, 630, 470);
				outtextxy(582, 448, "返回");
				while (1)
				{
					tj = GetMouseMsg();
					if (tj.x >= 560 && tj.x <= 630 && tj.y >= 440 && tj.y <= 470 && tj.mkLButton)
					{
						break;
					}
				}
				break;
			}
			//统计
			if (m_start.x >= 275 && m_start.x <= 377 && m_start.y >= 255 && m_start.y <= 280 && m_start.mkLButton && check == 1)
			{
				char tc[10];
				putimage(0, 0, &start);
				bool b = InputBox(tc, 10, "确认退出(无需输入)", "警告", "确认退出，取消返回", 0, 0, false);
				if (b)
				{
					last_output();//退出图片
					exit(0);
				}
				else
				{
					check = -3;
				}
			}
			//退出
		}
	}
	//----------------------------------------------------------------------------------------------------------------------主菜单控制部分
	getchar();
	closegraph();//关闭
	return 0;
}
