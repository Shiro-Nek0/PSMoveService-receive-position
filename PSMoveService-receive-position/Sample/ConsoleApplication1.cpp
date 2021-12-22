#include "stdafx.h"
#include <windows.h>
#include "PSMoveService/PSMoveClient_CAPI.h"

PSMControllerList controllerList;
PSMVector3f ctrlPos[32];
PSMController* ctrl[32];
//PSMTrackerList trackerList;

int main()
{
	SetConsoleTitle(_T("PSMoveService - get position tracking data"));

	bool success = true;

	if (PSM_Initialize(PSMOVESERVICE_DEFAULT_ADDRESS, PSMOVESERVICE_DEFAULT_PORT, PSM_DEFAULT_TIMEOUT) != PSMResult_Success)
	{
		printf("Failed to initialize the client network manager");
		success = false;
	}
	

	if (success)
	{
		memset(&controllerList, 0, sizeof(PSMControllerList));
		PSM_GetControllerList(&controllerList, PSM_DEFAULT_TIMEOUT);

		//memset(&trackerList, 0, sizeof(PSMTrackerList));
		//PSM_GetTrackerList(&trackerList, PSM_DEFAULT_TIMEOUT);


		// Register as listener and start streams
		unsigned int data_stream_flags =
			PSMControllerDataStreamFlags::PSMStreamFlags_includePositionData |
			PSMControllerDataStreamFlags::PSMStreamFlags_includePhysicsData |
			PSMControllerDataStreamFlags::PSMStreamFlags_includeCalibratedSensorData |
			PSMControllerDataStreamFlags::PSMStreamFlags_includeRawTrackerData;


		//Controller1
		for (int i = 0; i < controllerList.count; i++){
			if (PSM_AllocateControllerListener(controllerList.controller_id[i]) == PSMResult_Success && PSM_StartControllerDataStream(controllerList.controller_id[i], data_stream_flags, PSM_DEFAULT_TIMEOUT) == PSMResult_Success) {
				success = true;
			}
		}
	}


	while (success)
	{
		if ((GetAsyncKeyState(VK_ESCAPE) & 0x8000) != 0) break;

		PSM_Update();

		system("cls");



		for (int i = 0; i < controllerList.count; i++)
		{
			PSM_GetControllerPosition(controllerList.controller_id[i], &ctrlPos[i]);

			ctrl[i] = PSM_GetController(controllerList.controller_id[i]);
			printf("Tracker ID:%d Pos: X%.2f Y%.2f Z%.2f \r\n", i, ctrlPos[i].x, ctrlPos[i].y, ctrlPos[i].z);
		}

		printf("\r\nPress escape to exit");
	}


	PSM_Shutdown();

    return 0;
}