#ifndef BLUETOOTH_CONTROL_H
#define BLUETOOTH_CONTROL_H

#include <Arduino.h>
#include <BluetoothSerial.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include "co2_sensor.h"
#include "config.h"
#include "controller.h"
#include "oled_control.h"

using std::string, std::vector;

class bluetooth_control {
  private:
   /* data */
   //*Tạo một đối tượng thuộc lớp BluetoothSerial
   BluetoothSerial SerialBT;
   String remoteName;
   //*Kiem tra xem có thiết bị bluetooth nao kết nối hay không
   bool isConnected();
   //*Đọc dữ liệu từ bluetooth
   void bluetooth_read();
   //*Tạo một đối tượng lớp controller để điều khiển xe từ tín hiệu nhận được từ
   // bluetooth
   controller* con = new controller();
   /*
    *Tạo một đối tượng lớp oled_control để hiển thị thông tin trên màn hình led
    *của mạch heltec WiFi Lora bao gồm: Hiển thị giá trị % xung PWM Một thanh đo
    *hiển thị % xung PWM Giá trị cảm biến đơn vị ppm
    */
   oled_control* led = new oled_control();
   //*Tạo một đối tượng lớp co2_sensor để lấy giá trị đo được từ cảm biến
   co2_sensor* sensor = new co2_sensor();

  public:
   bluetooth_control(/* args */);
   ~bluetooth_control();
   //*Khởi động tất cả các thiết bị
   void init();
   /*
    *Xử lý dữ liệu từ hầm bluetooth_read và điều khiển xe dựa trên dữ liệu nhận
    *được: Nếu byte đầu tiên nhân được trong 2 bytes gửi từ HC-05 là 0x50(POWER)
    *thì sẽ lấy bytes tiếp theo là giá trị xung PWM được băm vào 2 chân ENA và
    *ENB của mạch L298 Nếu byte đầu tiên là 0x43(CONTROL) thì byte tiếp theo sẽ
    *điều khiển xe tương ứng là:
    *f: xe đi thẳng
    *b: xe đi lùi
    *s: xe dừng lại
    *r: rẽ phải
    *l: rẽ trái
    */
   void handleData();
};

#endif  // BLUETOOTH_CONTROL_H