﻿# PSMoveService receive position
Receiving positioning data for trackers. As trackers can be used ping pong balls with LED or Playstation Move controllers.

## Setup tracking
1. Download [PSMoveService](https://github.com/cboulay/PSMoveService), run and close it.
2. Go to folder "%appdata%\PSMoveService" and change some parameters. Specify the number of required trackers.<br>
For VR controllers in the file "ControllerManagerConfig.json" in the parameter "virtual_controller_count" specify the number of virtual controllers (for example, "1" or "2").<br>
In the files "VirtualController_ID.json"change the parameter "bulb_radius" to "2" if you are using ping pong balls with LED.<br>
In the files "VirtualController_ID.json" you can change the controller index the parameter "gamepad_index".<br>
3. Run "PSMoveService", "PSMoveConfigTool" and configure according to the instructions [[1]](https://github.com/cboulay/PSMoveService/wiki/Virtual-HMDs)[[2]](https://github.com/HipsterSloth/PSVRTracker/wiki/Virtual-HMD-Setup)[[3]](https://github.com/cboulay/PSMoveService/wiki/Color-Filter-Calibration)[[4]](https://github.com/cboulay/PSMoveService/wiki/Tracker-Pose-Calibration).<br>
Then you can use the example and use the position tracking data.

*Remember to manually add the .lib from thirdparty\lib\x86\debug to VSC also copy the dll in the same folder to the built .exe folder

# PSMoveService получение позиционирования
Получение данных позиционирования трекеров. В качестве трекеров могут использоваться пинг понг шарики со светодиодом или Playstation Move контроллеры.

## Настройка отслеживания
1. Загрузить [PSMoveService](https://github.com/cboulay/PSMoveService), запустить и закрыть его.
2. Перейти в папку "%appdata%\PSMoveService" и изменить некоторые параметры. Указать количество необходимых трекеров.<br>
Для VR контроллеров, в файле "ControllerManagerConfig.json", в параметре - "virtual_controller_count", указать количество виртуальных контроллеров (например, "1" или "2").<br>
В файлах "VirtualController_ID.json" изменить параметр "bulb_radius" на "2", если вы используете пинг понг шарики со светодиодом.<br>
В файлах "VirtualController_ID.json" можно изменить индекс контроллера, параметр "gamepad_index".<br>
3. Запустить "PSMoveService", "PSMoveConfigTool" и настроить согласно инструкциям [[1]](https://github.com/cboulay/PSMoveService/wiki/Virtual-HMDs)[[2]](https://github.com/HipsterSloth/PSVRTracker/wiki/Virtual-HMD-Setup)[[3]](https://github.com/cboulay/PSMoveService/wiki/Color-Filter-Calibration)[[4]](https://github.com/cboulay/PSMoveService/wiki/Tracker-Pose-Calibration), на ютубе есть инструкции на русском.<br>
После чего можно использовать пример и использовать данные позиционного трекинга.
