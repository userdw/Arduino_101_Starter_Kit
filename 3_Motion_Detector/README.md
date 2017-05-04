# [ENGLISH] Project 3: Motion Detector
How to add movement detection feature to your project? The answer is PIR sensor, which is ababbreviation for Passive Infrared sensor. PIR sensor works by measuring infrared light emitted by objects in its field of view. Every objects emit infrared light, therefore PIR sensor should be able to detect their movement as long as the emitted infrared light is high enough to pass the PIR's threshold. The most common application of PIR is an automatic door which can open automatically when someone walking closer to it. On this project we will make a simple system that will detect our body movement utilizing PIR Module and LED Module. If the system is detecting our body movement, then it will light up the LED Module.

<img src="/images/HC-SR501.jpg" height="225">

### In this project you will need:
* Genuino 101 (1),
* Adapter Shield (1),
* LED Module (1),
* PIR Module (1).

### Assemble the modules following these steps:
1. Plug the Adapter Shield to the top of Genuino 101,
2. Plug the LED Module to the header on the Adapter Shield labelled **9**,
3. Configure the trigger of PIR Module to single trigger,
4. Plug the PIR Module to the header on the Adapter Shield labelled **2**,
5. Upload the [Motion_Detector](https://github.com/IETrainingDiv/Genuino_101_Starter_Kit/tree/master/3_Motion_Detector/Motion_Detector) code into Genuino 101.

If there are no mistakes, the LED Module should start blinking then increase and fade in its brightness.

# [BAHASA INDONESIA] Proyek 1: Blinking and Fading a LED
Bagi Anda yang sudah mengenal Arduino beserta pemrogramannya, proyek ini tentu tidak akan sulit untuk dipahami, karena Arduino/Genuino 101 dikembangkan dengan tingkat kompatibilitas yang tinggi dengan Arduino pada umumnya. Hal tersebut dapat diartikan bahwa (hampir semua) kode program apapun yang bisa berjalan pada modul Arduino akan dapat berjalan pula pada modul Arduino/Genuino 101. Apabila ini adalah pertama kalinya Anda memprogram modul Arduino, kode program Arduino relatif mudah untuk dipelajari sehingga Anda dapat memahami proses pengendalian pin output dengan cepat.

Modul-modul yang dibutuhkan pada proyek ini:
* Genuino 101 (1),
* Adapter Shield (1),
* LED Module (1).

Hubungkan modul-modul di atas mengikuti langkah-langkah di bawah ini:
1. Pasang Adapter Shield di atas Genuino 101,
2. Hubungkan LED Module ke header Adapter Shield yang berlabel **9**,
3. Upload kode program [Blinking and Fading a LED](https://github.com/IETrainingDiv/Genuino_101_Starter_Kit/tree/master/1_Blinking_and_Fading_a_LED/Blinking_and_Fading_a_LED) ke Genuino 101.

Apabila tidak terdapat kesalahan, maka LED Module akan berkedip kemudian tingkat kecerahannya akan berubah.
