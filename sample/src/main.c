#include <psp2/kernel/processmgr.h>
#include <stdio.h>
#include <debugnet.h>

#include "debugScreen.h"
#define ip_server "192.168.1.3"
#define port_server 18194
#define printf psvDebugScreenPrintf
char *myChar[6];
int flag=1;
int main(int argc, char *argv[]) {
	int remain = 5;
	psvDebugScreenInit();
	int ret;
	printf("Welcome to the libkb sample !\n");
	printf("Use your keyboard to write on screen and in debugnet listener!\n");
	printf("This is only a little sample to show basic use still WIP!\n");
	printf("Wait the best MSX emulator experience in your Vita TV soon :P\n");
	printf("Press ESC key to go out!\n");
	
	
	printf("\n");
	printf("\n");
	
	int i;
	ret=debugNetInit(ip_server,port_server,DEBUG);
	ret=kbInit(DEBUG);
	if(ret>0)
	{
	
		while(flag)
		{
			ret=kbRead(myChar);
			
			if(ret==-1)
			{
				flag=0;
				
			}
			else
			{
				if(ret!=0)
				{
					for(i=0;i<ret;i++)
					{
						printf("%s",myChar[i]);
					}
				}
			}
		}
	}
	kbFinish();
	debugNetFinish();
	printf("\n");

	/* \r demo using a countdown */
	while(remain-->0){
		printf("This sample will close in %i s...\r", remain);
		sceKernelDelayThread(1000*1000);
	}

	/* print at specific col;row */
	printf("\e[10;20HBye Bye");
	sceKernelDelayThread(2*1000*1000);

	sceKernelExitProcess(0);
	return 0;
}
