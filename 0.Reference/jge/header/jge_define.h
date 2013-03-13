#ifndef _jge_define_20080125pm0348_
#define _jge_define_20080125pm0348_

//////////////////////////////////////////////////////////////////////////
// ¿ù»~½X¥N¸¹
#define DEF_JGE_OK								0
#define DEF_JGE_NO_TIMEMANAGER					1
#define DEF_JGE_NO_RENDER						2
#define DEF_JGE_DEBUG_LOG_OPENFILE_FAIL			3
#define DEF_JGE_PROJECT_NAME_TOO_LONG			4
#define DEF_JGE_NO_FRAME						5
#define DEF_JGE_D3D_CREATE_FAIL					6
#define DEF_JGE_D3D_DEVICE_CREATE_FAIL			7
#define DEF_JGE_GAMEEND							8
#define DEF_JGE_DIN_CREATE_FAIL					9
#define DEF_JGE_DIN_CREATE_KB_FAIL				10
#define DEF_JGE_DIN_CREATE_MS_FAIL				11
#define DEF_JGE_DIN_CREATE_JE_FAIL				12
#define DEF_JGE_CREATE_D3D_VERTEX_BUFFER_FAIL	13
#define DEF_JGE_INIT_D3D_MATRICES_FAIL			14
#define DEF_JGE_D3D_GET_DISPLAY_MODE_FAIL		15
#define DEF_JGE_FILE_OPEN_FAIL					16
#define DEF_JGE_END_OF_FILE						17
#define DEF_JGE_FILE_READ_ERROR					18
#define DEF_JGE_FILE_CREATE_FAIL				19
#define DEF_JGE_FILE_WRITE_ERROR				20
#define DEF_JGE_GRAPHICS_NO_DRAW				21



//////////////////////////////////////////////////////////////////////////
// ÄÝ©Ê
#define DEF_JGE_PROJECT_NAME_LEN			(128)
#define DEF_JGE_PATH_LEN					(256)
#define DEF_JGE_UNICODE_HEADER				(0xFEFF)


//////////////////////////////////////////////////////////////////////////
// 
#define _JGE_BEGIN	namespace JGE {
#define _JGE_END	}

#define _USERINTERFACE_BEGIN namespace UserInterface {
#define _USERINTERFACE_END }

#define _JGE_UI_BEGIN _JGE_BEGIN _USERINTERFACE_BEGIN
#define _JGE_UI_END _USERINTERFACE_END _JGE_END
#endif