#include <debugnet.h>
#include <psp2/types.h>
#include <psp2/hid.h>
#include "kb.h"

SceUInt32 handle[SCE_HID_MAX_DEVICE_COUNT];
SceHidKeyboardReport reports[2];
int kb_initialized=0;
SceBool caps_key=SCE_FALSE;
SceBool shift_key=SCE_FALSE;
SceBool control_key=SCE_FALSE;
SceBool alt_key=SCE_FALSE;
SceBool alt_graph_key=SCE_FALSE;
char *kbNames[2][256];
int ind=0;
char cad[6];
void kbInitKeyNames()
{
	kbNames[0][KEY_A]="a"; //0x04  Keyboard a and A
	kbNames[0][KEY_B]="b"; //0x05 // Keyboard b and B
	kbNames[0][KEY_C]="c"; //0x06 // Keyboard c and C
	kbNames[0][KEY_D]="d"; //0x07 // Keyboard d and D
	kbNames[0][KEY_E]="e"; //0x08 // Keyboard e and E
	kbNames[0][KEY_F]="f"; //0x09 // Keyboard f and F
	kbNames[0][KEY_G]="g"; //0x0a // Keyboard g and G
	kbNames[0][KEY_H]="h"; //0x0b // Keyboard h and H
	kbNames[0][KEY_I]="i"; //0x0c // Keyboard i and I
	kbNames[0][KEY_J]="j"; //0x0d // Keyboard j and J
	kbNames[0][KEY_K]="k"; //0x0e // Keyboard k and K
	kbNames[0][KEY_L]="l"; //0x0f // Keyboard l and L
	kbNames[0][KEY_M]="m"; //0x10 // Keyboard m and M
	kbNames[0][KEY_N]="n"; //0x11 // Keyboard n and N
	kbNames[0][KEY_O]="o"; //0x12 // Keyboard o and O
	kbNames[0][KEY_P]="p"; //0x13 // Keyboard p and P
	kbNames[0][KEY_Q]="q"; //0x14 // Keyboard q and Q
	kbNames[0][KEY_R]="r"; //0x15 // Keyboard r and R
	kbNames[0][KEY_S]="s"; //0x16 // Keyboard s and S
	kbNames[0][KEY_T]="t"; //0x17 // Keyboard t and T
	kbNames[0][KEY_U]="u"; //0x18 // Keyboard u and U
	kbNames[0][KEY_V]="v"; //0x19 // Keyboard v and V
	kbNames[0][KEY_W]="w"; //0x1a // Keyboard w and W
	kbNames[0][KEY_X]="x"; //0x1b // Keyboard x and X
	kbNames[0][KEY_Y]="y"; //0x1c // Keyboard y and Y
	kbNames[0][KEY_Z]="z"; //0x1d // Keyboard z and Z
	
	kbNames[1][KEY_A]="A"; //0x04  Keyboard a and A
	kbNames[1][KEY_B]="B"; //0x05 // Keyboard b and B
	kbNames[1][KEY_C]="C"; //0x06 // Keyboard c and C
	kbNames[1][KEY_D]="D"; //0x07 // Keyboard d and D
	kbNames[1][KEY_E]="E"; //0x08 // Keyboard e and E
	kbNames[1][KEY_F]="F"; //0x09 // Keyboard f and F
	kbNames[1][KEY_G]="G"; //0x0a // Keyboard g and G
	kbNames[1][KEY_H]="H"; //0x0b // Keyboard h and H
	kbNames[1][KEY_I]="I"; //0x0c // Keyboard i and I
	kbNames[1][KEY_J]="J"; //0x0d // Keyboard j and J
	kbNames[1][KEY_K]="K"; //0x0e // Keyboard k and K
	kbNames[1][KEY_L]="L"; //0x0f // Keyboard l and L
	kbNames[1][KEY_M]="M"; //0x10 // Keyboard m and M
	kbNames[1][KEY_N]="N"; //0x11 // Keyboard n and N
	kbNames[1][KEY_O]="O"; //0x12 // Keyboard o and O
	kbNames[1][KEY_P]="P"; //0x13 // Keyboard p and P
	kbNames[1][KEY_Q]="Q"; //0x14 // Keyboard q and Q
	kbNames[1][KEY_R]="R"; //0x15 // Keyboard r and R
	kbNames[1][KEY_S]="S"; //0x16 // Keyboard s and S
	kbNames[1][KEY_T]="T"; //0x17 // Keyboard t and T
	kbNames[1][KEY_U]="U"; //0x18 // Keyboard u and U
	kbNames[1][KEY_V]="V"; //0x19 // Keyboard v and V
	kbNames[1][KEY_W]="W"; //0x1a // Keyboard w and W
	kbNames[1][KEY_X]="X"; //0x1b // Keyboard x and X
	kbNames[1][KEY_Y]="Y"; //0x1c // Keyboard y and Y
	kbNames[1][KEY_Z]="Z"; //0x1d // Keyboard z and Z

	kbNames[0][KEY_1]="1"; //0x1e // Keyboard 1 and !
	kbNames[0][KEY_2]="2"; //0x1f // Keyboard 2 and @
	kbNames[0][KEY_3]="3"; //0x20 // Keyboard 3 and #
	kbNames[0][KEY_4]="4"; //0x21 // Keyboard 4 and $
	kbNames[0][KEY_5]="5"; //0x22 // Keyboard 5 and %
	kbNames[0][KEY_6]="6"; //0x23 // Keyboard 6 and ^
	kbNames[0][KEY_7]="7"; //0x24 // Keyboard 7 and &
	kbNames[0][KEY_8]="8"; //0x25 // Keyboard 8 and *
	kbNames[0][KEY_9]="9"; //0x26 // Keyboard 9 and (
	kbNames[0][KEY_0]="0"; //0x27 // Keyboard 0 and )
	
	kbNames[0][KEY_1]="!"; //0x1e // Keyboard 1 and !
	kbNames[0][KEY_2]="@"; //0x1f // Keyboard 2 and @
	kbNames[0][KEY_3]="#"; //0x20 // Keyboard 3 and #
	kbNames[0][KEY_4]="$"; //0x21 // Keyboard 4 and $
	kbNames[0][KEY_5]="%"; //0x22 // Keyboard 5 and %
	kbNames[0][KEY_6]="^"; //0x23 // Keyboard 6 and ^
	kbNames[0][KEY_7]="&"; //0x24 // Keyboard 7 and &
	kbNames[0][KEY_8]="*"; //0x25 // Keyboard 8 and *
	kbNames[0][KEY_9]="("; //0x26 // Keyboard 9 and (
	kbNames[0][KEY_0]=")"; //0x27 // Keyboard 0 and )
	

	kbNames[0][KEY_ENTER]="\n"; //0x28 // Keyboard Return (ENTER)
	kbNames[0][KEY_ESC]="^["; //0x29 // Keyboard ESCAPE
	kbNames[0][KEY_BACKSPACE]=""; //0x2a // Keyboard DELETE (Backspace)
	kbNames[0][KEY_TAB]="	"; //0x2b // Keyboard Tab
	kbNames[0][KEY_SPACE]=" "; //0x2c // Keyboard Spacebar
	kbNames[0][KEY_MINUS]="-"; //0x2d // Keyboard - and _
	kbNames[1][KEY_MINUS]="_"; //0x2d // Keyboard - and _
	kbNames[0][KEY_EQUAL]="="; //0x2e // Keyboard = and +
	kbNames[1][KEY_EQUAL]="+"; //0x2e // Keyboard = and +
	
	kbNames[0][KEY_LEFTBRACE]="["; //0x2f // Keyboard [ and {
	kbNames[1][KEY_LEFTBRACE]="{"; //0x2f // Keyboard [ and {
	kbNames[0][KEY_RIGHTBRACE]="]"; //0x30 // Keyboard ] and }
	kbNames[1][KEY_RIGHTBRACE]="}"; //0x30 // Keyboard ] and }
	
	kbNames[0][KEY_BACKSLASH]="\\"; //0x31 // Keyboard \ and | not in spanish
	kbNames[1][KEY_BACKSLASH]="|"; //0x31 // Keyboard \ and | not in spanish
	
	kbNames[0][KEY_HASHTILDE]="#"; //0x32 // Keyboard Non-US # and ~ in spanish ç
	kbNames[1][KEY_HASHTILDE]="~"; //0x32 // Keyboard Non-US # and ~ in spanish ç
	
	kbNames[0][KEY_SEMICOLON]=";"; //0x33 // Keyboard ; and :
	kbNames[1][KEY_SEMICOLON]=":"; //0x33 // Keyboard ; and :
	
	kbNames[0][KEY_APOSTROPHE]="'"; //0x34 // Keyboard ' and "
	kbNames[1][KEY_APOSTROPHE]="\""; //0x34 // Keyboard ' and "
	
	kbNames[0][KEY_GRAVE]="`"; //0x35 // Keyboard ` and ~ in spanish º
	kbNames[1][KEY_GRAVE]="~"; //0x35 // Keyboard ` and ~ in spanish º
	
	kbNames[0][KEY_COMMA]=","; //0x36 // Keyboard , and <
	kbNames[1][KEY_COMMA]="<"; //0x36 // Keyboard , and <
	
	kbNames[0][KEY_DOT]="."; //0x37 // Keyboard . and >
	kbNames[1][KEY_DOT]=">"; //0x37 // Keyboard . and >
	
	kbNames[0][KEY_SLASH]="/"; //0x38 // Keyboard / and ? in spanish -
	kbNames[1][KEY_SLASH]="?"; //0x38 // Keyboard / and ? in spanish -
	
	kbNames[0][KEY_CAPSLOCK]=""; //0x39 // Keyboard Caps Lock not in normal keycode vita use special key 0x2 in reports.modifiers[1]

	kbNames[0][KEY_F1]=""; //0x3a // Keyboard F1
	kbNames[0][KEY_F2]=""; //0x3b // Keyboard F2
	kbNames[0][KEY_F3]=""; //0x3c // Keyboard F3
	kbNames[0][KEY_F4]=""; //0x3d // Keyboard F4
	kbNames[0][KEY_F5]=""; //0x3e // Keyboard F5
	kbNames[0][KEY_F6]=""; //0x3f // Keyboard F6
	kbNames[0][KEY_F7]=""; //0x40 // Keyboard F7
	kbNames[0][KEY_F8]=""; //0x41 // Keyboard F8
	kbNames[0][KEY_F9]=""; //0x42 // Keyboard F9
	kbNames[0][KEY_F10]=""; //0x43 // Keyboard F10
	kbNames[0][KEY_F11]=""; //0x44 // Keyboard F11
	kbNames[0][KEY_F12]=""; //0x45 // Keyboard F12
	
	kbNames[0][KEY_SYSRQ]=""; //0x46 // Keyboard Print Screen
	kbNames[0][KEY_SCROLLLOCK]=""; //0x47 // Keyboard Scroll Lock
	kbNames[0][KEY_PAUSE]=""; //0x48 // Keyboard Pause
	kbNames[0][KEY_INSERT]=""; //0x49 // Keyboard Insert
	kbNames[0][KEY_HOME]=""; //0x4a // Keyboard Home
	kbNames[0][KEY_PAGEUP]=""; //0x4b // Keyboard Page Up
	kbNames[0][KEY_DELETE]=""; //0x4c // Keyboard Delete Forward
	kbNames[0][KEY_END]=""; //0x4d // Keyboard End
	kbNames[0][KEY_PAGEDOWN]=""; //0x4e // Keyboard Page Down
	kbNames[0][KEY_RIGHT]=""; //0x4f // Keyboard Right Arrow
	kbNames[0][KEY_LEFT]=""; //0x50 // Keyboard Left Arrow
	kbNames[0][KEY_DOWN]=""; //0x51 // Keyboard Down Arrow
	kbNames[0][KEY_UP]=""; //0x52 // Keyboard Up Arrow

	
}
/**
 * Init kb library 
 *
 * @par Example:
 * @code  
 * int ret;
 * ret = kbInit(NONE);
 * @endcode
 *
 * @param level - DEBUG,ERROR,INFO or NONE 
 */
int kbInit(int level)
{
	int ret;
	int i;
	if(kb_initialized==0)
	{
		for(i=0;i<SCE_HID_MAX_DEVICE_COUNT;i++)
		{
			handle[i]=0;
		}
		ret=sceHidKeyboardEnumerate(handle,SCE_HID_MAX_DEVICE_COUNT);
		if(ret<=0)
		{
			//errors can be 
			debugNetPrintf(level,"sceHidKeyboardEnumerate error: 0x%08X\n %d\n",ret);
			kb_initialized=0;
			return ret;
		}
		kbInitKeyNames();
		kb_initialized=1;
	}
	else
	{
		debugNetPrintf(level,"sceHidKeyboardEnumerate already initialized: 0x%08X\n",kb_initialized);
		
		ret=kb_initialized;
	}
	return ret;
}
/**
 * Finish kb library 
 *
 * @par Example:
 * @code  
 * kbFinish();
 * @endcode
 *
 * @param level - DEBUG,ERROR,INFO or NONE 
 */
void kbFinish()
{
	int i;
	for(i=0;i<SCE_HID_MAX_DEVICE_COUNT;i++)
	{
		handle[i]=0;
	}
	kb_initialized=0;
	
}
void kbGetSpecialKeys()
{
	switch(reports[0].modifiers[1])
	{
		case 0x2:
			caps_key=SCE_TRUE;
			break;
		default:
			caps_key=SCE_FALSE;
			break;
		
	}
	switch(reports[0].modifiers[0])
	{
		
		case 0x0:
			control_key=SCE_FALSE;
			shift_key=SCE_FALSE;
			alt_key=SCE_FALSE;
			alt_graph_key=SCE_FALSE;
			break;
		case 0x1:
			control_key=SCE_TRUE;
			shift_key=SCE_FALSE;
			alt_key=SCE_FALSE;
			alt_graph_key=SCE_FALSE;
			break;
		case 0x2:
			control_key=SCE_FALSE;
			shift_key=SCE_TRUE;
			alt_key=SCE_FALSE;
			alt_graph_key=SCE_FALSE;
			break;
		case 0x3:
			control_key=SCE_TRUE;
			shift_key=SCE_TRUE;
			alt_key=SCE_FALSE;
			alt_graph_key=SCE_FALSE;
			break;
		case 0x4:
			control_key=SCE_FALSE;
			shift_key=SCE_FALSE;
			alt_key=SCE_TRUE;
			alt_graph_key=SCE_FALSE;
			break;
		case 0x5:
			control_key=SCE_TRUE;
			shift_key=SCE_FALSE;
			alt_key=SCE_TRUE;
			alt_graph_key=SCE_FALSE;
			break;
		case 0x6:
			control_key=SCE_TRUE;
			shift_key=SCE_FALSE;
			alt_key=SCE_TRUE;
			alt_graph_key=SCE_FALSE;
			break;
		case 0x7:
			control_key=SCE_TRUE;
			shift_key=SCE_TRUE;
			alt_key=SCE_TRUE;
			alt_graph_key=SCE_FALSE;
			break;
		case 0x10:
			control_key=SCE_TRUE;
			shift_key=SCE_FALSE;
			alt_key=SCE_FALSE;
			alt_graph_key=SCE_FALSE;
			break;
		case 0x20:
			control_key=SCE_FALSE;
			shift_key=SCE_TRUE;
			alt_key=SCE_FALSE;
			alt_graph_key=SCE_FALSE;
			break;
		case 0x30:
			control_key=SCE_TRUE;
			shift_key=SCE_TRUE;
			alt_key=SCE_FALSE;
			alt_graph_key=SCE_FALSE;
			break;
		case 0x40:
			control_key=SCE_FALSE;
			shift_key=SCE_FALSE;
			alt_key=SCE_FALSE;
			alt_graph_key=SCE_TRUE;
			break;
		case 0x50:
			control_key=SCE_TRUE;
			shift_key=SCE_FALSE;
			alt_key=SCE_FALSE;
			alt_graph_key=SCE_TRUE;
			break;			
		case 0x60:
			control_key=SCE_FALSE;
			shift_key=SCE_TRUE;
			alt_key=SCE_FALSE;
			alt_graph_key=SCE_TRUE;
			break;						
		case 0x70:
			control_key=SCE_TRUE;
			shift_key=SCE_TRUE;
			alt_key=SCE_FALSE;
			alt_graph_key=SCE_TRUE;
			break;			
		default:
			control_key=SCE_FALSE;
			shift_key=SCE_FALSE;
			alt_key=SCE_FALSE;
			alt_graph_key=SCE_FALSE;
			break;				
	}
	
	
}
char *kbKey2Char(int key)
{
	if(caps_key || shift_key)
	{
		ind=1;
	}
	else
	{
		ind=0;
	}
	return kbNames[ind][key];
	
	
}
int kbRead(char **cad)
{
	int ret=0;
	int i;
	if(kb_initialized)
	{
		ret=sceHidKeyboardRead(handle[0], &reports[0], 1);
		if(ret)
		{
			
			kbGetSpecialKeys();
			ret=0;
			for(i=0;i<6;i++)
			{
				if(reports[0].keycodes[i]!=0)
				{
					ret++;
					cad[i]=(kbKey2Char(reports[0].keycodes[i]));
				//	debugNetUDPPrintf("%s%d\n",kbKey2Char(reports[0].keycodes[i]),ret);
					debugNetUDPPrintf("%s",cad[i]);
					
					if(reports[0].keycodes[i]==KEY_ESC)
					{
						return -1;
					}
				}
			}
			 
		}
	}
	return ret;
}
