#ifndef CONFIG_H
#define CONFIG_H

#define UP                   1
#define DOWN                 2
#define LEFT                 3
#define RIGHT                4
#define STOP                 0

#define FORWARD              1
#define BACKWARD             -1

#define PWMFREQ              1000
#define PWMRES               8
#define PWMCHANNEL           1

#define ENA                  12
#define IN_1                 13
#define IN_2                 21

#define ENB                  0
#define IN_3                 23
#define IN_4                 22

#define BAUDRATE             115200

#define HEIGHT               64
#define WIDTH                128

#define MG_PIN               14
#define DC_GAIN              5
#define READ_SAMPLE_INTERVAL 50
#define READ_SAMPLE_TIMES    5
#define ZERO_POINT_VOLTAGE   0.220
#define REACTION_VOLTGAE     0.030

#endif  // CONFIG_H