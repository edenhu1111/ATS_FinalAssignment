#include <cvirte.h>		
#include <userint.h>
#include "myuir.h"
#include <ansi_c.h>
#include <visa.h>
#include <stdio.h>

ViStatus status;	  //����״̬����
ViSession  defRM;	  //����ϵͳ��Դ�Ự����
ViSession  instr1;	  //���������Ự����
ViSession  instr2;	  //���������Ự����
ViChar     desc1[128]; //������Դ������������
ViChar     desc2[128]; //������Դ������������
ViUInt32   numInstrs;	//�������ҵ����������ı���

int cnt; //�������������
char inbuf[128];  //�������뻺����
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
	
	status = viOpenDefaultRM(&defRM);   //��ϵͳ��Դ
	status = viOpen(defRM, desc, VI_NULL, VI_NULL, &instr); //�������Ự
	
	viClose(defRM);	   //�ر�ϵͳ��Դ
	
*/
