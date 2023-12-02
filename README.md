How to compile for ESPboy:

1 install Arduino IDE

2 unzip the archive to a folder convenient for use

3 move the gyverPortal library from the lib folder to the folder \Documents\Arduino\libraries

3.1 check the name of folders and sketch( there should be a folder ESPboy_micro_readerV3 in it sketch and other folders )

4 Open the file "ESPboy_micro_readerV3.ino" in Arduino IDE and compile it for the board "Lolin(WeMos) D1 R2 & mini (ESP8266)".

5 Upload the read-only files to the data folder or via the built-in Wi-Fi downloader.
Note: the file name must be test1, test2, test3, test4.... or you can change 1 line in the sketch
" String origName = "/test"; "

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
