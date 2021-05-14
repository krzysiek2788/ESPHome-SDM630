# ESPHome+SDM630

# 1. About
This repository is an instruction how to use energy meter SDM630 Modbus V2 with ESP32/8266 loaded with ESPHome. Program is meant to read all needed data from the counter if you need something more feel free to modify the code.

# 2. Needed things to start

1. SDM630 Modbus V2 can be bought from Aliexpress example link below:
https://pl.aliexpress.com/item/32755125115.html?spm=a2g0s.9042311.0.0.7f515c0fyqdQLy
2. Modbus konwerter from RS485 to UART
https://pl.aliexpress.com/item/1005001346792286.html?spm=a2g0o.productlist.0.0.379b6239Khooh1&algo_pvid=null&algo_expid=null&btsid=2100bdcf16209689305085851eb468&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_
3. ESP board can be ESP8266 or ESP32
4. Home Assistant with ESPHome addon installed

# 3. Connection diagram
Wemos D1 ESP32
![image](https://user-images.githubusercontent.com/61471407/118225712-e88ae980-b485-11eb-9c2b-428857e21f10.png)

Wemos D1 ESP8266
![image](https://user-images.githubusercontent.com/61471407/118225594-b24d6a00-b485-11eb-94c8-515687f81e91.png)

Usually any board which is compatible with ESPHome should work. Only connect TX port of ESP to TX of converter, RX to RX, A+ from converter to A+ of SDM630, B- to B- and G to G.

# 4. Programming
1. Download folder SDM and paste it into below location of your Home Assistant server
    <B>\\\your_Home_Assistant_address\config\esphome\custom_components</B>
    If folder custom_components doesn't exist create it.
2. Create <B>New node</B> according to your board type. <B><font size=16>Paste example code to your node and modify it according to your code and configuration!!</B></font>
3. Validate code, compile and upload it.
4. <B><font size = 16>Rememmber that RS converter and SDM630 need to be connected and powered on, otherwise in logs you will see nothing and ESP board will be resetting and unavailable. So the best way to test is the code working, connect ing SDM630 normal cable with plug to wall socket and make connection according to diagram in point 3</B></font>
