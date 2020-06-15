#include <cvirte.h>		
#include <userint.h>
#include "myuir.h"
#include <ansi_c.h>
#include <visa.h>
#include <stdio.h>

ViStatus status;	  //定义状态变量
ViSession  defRM;	  //定义系统资源会话变量
ViSession  instr1;	  //定义仪器会话变量
ViSession  instr2;	  //定义仪器会话变量
ViChar     desc1[128]; //定义资源描述符缓冲区
ViChar     desc2[128]; //定义资源描述符缓冲区
ViUInt32   numInstrs;	//定义存放找到仪器数量的变量

int cnt; //定义计数器变量
char inbuf[128];  //定义输入缓冲区
static int panelHandle;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "myuir.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

int CVICALLBACK Main_Callback (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface(panelHandle); 
			break;
	}
	return 0;
}
/*
	int i,quit;
	
	status = viOpenDefaultRM(&defRM);   //打开系统资源
	status = viOpen(defRM, desc, VI_NULL, VI_NULL, &instr); //打开仪器会话
	
	viClose(defRM);	   //关闭系统资源
	
*/
