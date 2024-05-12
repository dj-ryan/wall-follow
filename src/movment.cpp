/**
 * Author: David Ryan
 * Created: 10/8/2020
 * Modified: 10/12/2020
 * Class: CSCE 236
 * Prof: Jeffrey Falkinburg
 */

#include <Arduino.h>
#include "movment.h"
#include "globalValues.h"

#define FOWARD_SET B00011000 // defining bit masks for direction values
#define FOWARD_CLEAR B10000100
#define LEFT B00010100
#define RIGHT B10001000

void movment::moveFoward(int speed, int duration)
{

    PORTD |= FOWARD_SET; // set direction to foward
    PORTD &= ~FOWARD_CLEAR;

    int tempSpeed = 0;

    TCCR0A |= 1 << COM0A1; // connect pwm to pin on timer 0, channel A
    TCCR0A |= 1 << COM0B1; // connect pwm to pin on timer 0, channel B

    while (tempSpeed != speed)
    {                      // let the robot accelerate
        OCR0A = tempSpeed; // set pwm duty
        OCR0B = tempSpeed;
        tempSpeed++; // increase pwm duty
        delay(10);
    }

    delay(duration); // delay the duration requested

    while (tempSpeed != 0)
    {                      // let the robot come to a stop
        OCR0A = tempSpeed; // set pwm duty
        OCR0B = tempSpeed;
        tempSpeed--; // decrease pwm duty
        delay(5);
    }
}

void movment::turnLeft(int degree)
{

    PORTD |= LEFT; // set direction to left
    PORTD &= ~RIGHT;

    TCCR0A |= 1 << COM0A1; // connect pwm to pin on timer 0, channel A
    TCCR0A |= 1 << COM0B1; // connect pwm to pin on timer 0, channel B

    OCR0A = turnSpeed; // set pwm duty
    OCR0B = turnSpeed;

    delay(degree * 17); // delay the duration requested

    OCR0A = 0; // set pwm duty to 0
    OCR0B = 0;
}

void movment::turnRight(int degree)
{

    PORTD |= RIGHT; // set direction to right
    PORTD &= ~LEFT;

    TCCR0A |= 1 << COM0A1; // connect pwm to pin on timer 0, channel A
    TCCR0A |= 1 << COM0B1; // connect pwm to pin on timer 0, channel B

    OCR0A = turnSpeed; // set pwm duty
    OCR0B = turnSpeed;

    delay(degree * 17); // delay the duration requested

    OCR0A = 0; // set pwm duty to 0
    OCR0B = 0;
}

void movment::moveReverse(int speed, int duration)
{

    PORTD |= FOWARD_CLEAR; // set direction to reverse
    PORTD &= ~FOWARD_SET;

    int tempSpeed = 0;

    TCCR0A |= 1 << COM0A1; // connect pwm to pin on timer 0, channel A
    TCCR0A |= 1 << COM0B1; // connect pwm to pin on timer 0, channel B

    while (tempSpeed != speed)
    {                      // let the robot accelerate
        OCR0A = tempSpeed; // set pwm duty
        OCR0B = tempSpeed;
        tempSpeed++; // increase pwm duty
        delay(10);
    }

    delay(duration); // delay the duration requested

    while (tempSpeed != 0)
    {                      // let the robot come to a stop
        OCR0A = tempSpeed; // set pwm duty
        OCR0B = tempSpeed;
        tempSpeed--; // decrease pwm duty
        delay(5);
    }
}