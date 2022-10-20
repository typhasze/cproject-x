#include "cprocessing.h"
#include "splashscreen.h"
#include <stdio.h>
#include <stdlib.h>

CP_Image logo;
CP_Color red;

void splash_screen_init(void)
{
	//set to 60fps
	//CP_System_SetFrameRate(60.0f);
	logo = CP_Image_Load("Assets/DigiPen_BLACK.png");
	CP_Settings_ImageMode(CP_POSITION_CORNER);
	CP_Settings_ImageWrapMode(CP_IMAGE_WRAP_CLAMP);
	CP_System_SetWindowSize(CP_Image_GetWidth(logo), CP_Image_GetHeight(logo));
	
}

void splash_screen_update(void)
{


	//float currentElapsedTime = CP_System_GetDt();
	float currentElapsedTime = 7;
	static float totalElapsedTime = 0;
	totalElapsedTime += currentElapsedTime;
	totalElapsedTime = (int) totalElapsedTime % 255;

	char buffer[16] = { 0 };
	sprintf_s(buffer, _countof(buffer), "%.2f", totalElapsedTime);
	CP_Font_DrawText(buffer, 200, 200);

	//Display Image
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
	CP_Image_Draw(logo, 0.f, 0.f, CP_Image_GetWidth(logo), CP_Image_GetHeight(logo), totalElapsedTime);

	if (CP_Input_KeyDown(KEY_Q))
	{
		CP_Engine_Terminate();
	}

	red = CP_Color_Create(255, 0, 0, 255);
	//This function sets the color of all subsequently drawn shapes or text.
	CP_Settings_Fill(red);
	//Draw a circle at the current mouse pointer
	CP_Graphics_DrawCircle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 20.0f);
	
}

void splash_screen_exit(void)
{
	CP_Image_Free(&logo);
}