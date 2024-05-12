/**
 * Author: David Ryan
 * Created: 3/2/2020
 * Modified: 3/8/2020
 * Class: CSCE 236
 * Prof: Jeffrey Falkinburg
 */

// Movment class header




class movment
{
private:

public:

    void moveFoward(int speed, int duration);

    void turnRight(int degree);

    void turnLeft(int degree);

    void moveReverse(int speed, int duration);
    
    void movmentInit();

    void FolloWall(int servo_pos, int target_distance, int duration);

};

