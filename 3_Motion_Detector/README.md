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

If there are no mistakes, LED Module should blink as long as there is movevment detected by PIR Module.
