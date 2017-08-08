# [ENGLISH] Project 8: Weather Station
This project is aimed to give you a simple example about how to use microcontroller as the main processor of weather station. In this project we will monitor the ambient temperature of a room. The system in this project will utilize the MCP9700 Temperature Sensor and OLED Module to display the readings.

<img src="/images/Weather_Station.png" height="400">

### In this project you will need:
* Arduino 101 (1),
* I/O Expansion Shield (1),
* MCP9700 Temperature Sensor (1),
* OLED Module (1).

Before you start to program your Arduino 101, you will need u8g2 library from olikraus. You can found the github page for u8g2 library [here](https://github.com/olikraus/u8g2). Instalation for u8g2 can be done through Arduino IDE (**Sketch | Include Library | Manage Libraries...**).

<img src="/images/u8g2.png" height="400">

### Assemble the modules following these steps:
1. **Change the PWR_SEL jumper on I/O Expansion Shield to 3V3**,
2. Plug the I/O Expansion Shield to the top of Arduino 101,
3. Plug the Rotation Sensor to the header on the I/O Expansion Shield labelled **A0**,
4. Plug the Micro Servo to the header on the I/O Expansion Shield labelled **6**,
5. Upload the [Potentiometer_Controlled_Servo](/05_Potentiometer_Controlled_Servo/Potentiometer_Controlled_Servo) code into Arduino 101.

If there are no mistakes, Micro Servo movement will be determined by the rotation of Rotation Sensor. If you don't get the full swing from the servo, it might be you didn't change the position of PWR_SEL jumper to 3V3.

# [BAHASA INDONESIA] Proyek 8: Weather Station
Proyek ini ditujukan untuk memberikan contoh sederhana mengenai penggunaan mikrokontroler sebagai sebuah stasiun cuaca. Adapun pada proyek ini hal yang akan dipantau adalah suhu sekitar dari sebuah ruangan. Sistem pada proyek ini akan memanfaatkan MCP9700 Temperature Sensor untuk pendeteksian suhu, serta OLED Module sebagai tampilannya.

<img src="/images/Weather_Station.png" height="400">

### Modul-modul yang dibutuhkan pada proyek ini:
* Arduino 101 (1),
* I/O Expansion Shield (1),
* Rotation Sensor (1),
* Micro Servo (1).

Sebelum Anda memulai memprogram Arduino 101, Anda terlebih dahulu perlu untuk menyertakan library u8g2 dari olikraus. Halaman github untuk u8g2 dapat ditemukan pada [link berikut](https://github.com/olikraus/u8g2). Instalasi untuk u8g2 dapat dilakukan melalui Arduino IDE (**Sketch | Include Library | Manage Libraries...**).

<img src="/images/u8g2.png" height="400">

### Hubungkan modul-modul di atas mengikuti langkah-langkah di bawah ini:
1. **Ubah posisi jumper PWR_SEL pada I/O Expansion Shield ke 3V3**,
2. Pasang I/O Expansion Shield di atas Arduino 101,
3. Hubungkan Rotation Sensor ke header I/O Expansion Shield yang berlabel **A0**,
4. Hubungkan Micro Servo ke header I/O Expansion Shield yang berlabel **6**,
5. Upload kode program [Potentiometer_Controlled_Servo](/05_Potentiometer_Controlled_Servo/Potentiometer_Controlled_Servo) ke Arduino 101.

Apabila tidak terdapat kesalahan, gerakan Micro Servo akan ditentukan dari putaran yang diberikan ke Rotation Sensor. Apabila gerakan servo tidak penuh 180 derajat kemungkinan posisi jumper PWR_SEL belum diubah ke 3V3.
