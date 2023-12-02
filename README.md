How to compile for ESPboy:

1 install the Arduino IDE

2 unzip the archive to a convenient folder for use

3 unzip lib.zip and data.zip into the sketch folder, move the gyverPortal library from the lib folder to the \Documents\Arduino\libraries folder.

![readm1](https://github.com/Sasha-Yagupov2010/ESPboy_micro_reader/assets/150813595/069f1e08-8c92-4a1b-9f25-d69f1991ec1a)

3.1 check the name of the folders and the sketch (there should be a folder ESPboy_micro_readerV3 with the sketch and other folders in it).

4 Open the file "ESPboy_micro_readerV3.ino" in Arduino IDE and compile it for the board "Lolin(WeMos) D1 R2 & mini (ESP8266)".

5 Upload the read-only files to the data folder or via the inbuilt Wi-Fi downloader.
Note: the file name must be test1, test2, test3, test4.... or you can change 1 line in the sketch
" String origName = "/test"; "

6 Enjoy using it =)

There will be 3 - 5 example files in the data folder demonstrating how it works.
You can also change the firmware using the inbuilt wifi bootloader.
The bootloader works on any device


Controlling ESPboy_micro_reader:
pressing the LEFT, RIGHT buttons moves horizontally in the menu:  

1 - boot menu
ESP creates an access point.
You must be connected to the network from a computer or other device to download files.
to exit, press any button 

2 - reading files
Press the UP, DOWN buttons to select a file, 
after selection press button A
to close the file press the ESC button

3 - text colour
Press the UP, DOWN buttons to select the colour of the text.
to exit press the ESC button
6 Enjoy using it =)

There will be 3 example files in the data folder to demonstrate how it works.
You can also change the firmware using the built-in wifi bootloader.
The bootloader works on any device




ESPboy_micro_reader control:
pressing the LEFT, RIGHT buttons moves horizontally in the menu:  

1 - boot menu
ESP creates an access point.
You must be connected to the network from a computer or other device to download files.
to exit, press any button 

2 - reading files
Press the UP, DOWN buttons to select a file, 
after selection press button A
to close the file press the ESC button

3 - text color
Press the UP, DOWN buttons to select the text color.
to exit press ESC
  



ESPboy github https://github.com/ESPboy-edu
Community https://community.espboy.com/
ESPboy case https://community.espboy.com/t/espboy-enclosures/250/7


