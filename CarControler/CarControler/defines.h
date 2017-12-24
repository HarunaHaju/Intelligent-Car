#ifndef DEFINES_H
#define DEFINES_H

//ͨ��ͼ�����õ��Ľ��
enum CarSignal
{
	CAR_DO_NOTHING = 0,
	CAR_MOVE_FORWARD,
	CAR_MOVE_BACK,
	CAR_MOVE_LEFT,
	CAR_MOVE_RIGHT
};

enum Color
{
	COLOR_NOT_DEFINED = 0,
	COLOR_RED,
	COLOR_BLUE,
	COLOR_GREEN
};

enum Position
{
	POSITION_NOT_DEFINED = 0,
	POSITION_VERTICAL,
	POSITION_HORIZONTAL
};

#define IN
#define OUT
#define INOUT

#define RED_ENABLE true
#define BLUE_ENABLE true
#define GREEN_ENABLE false

#endif