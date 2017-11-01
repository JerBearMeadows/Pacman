#include "SDL_Plotter.h"
#include "color.h"
#include "point.h"
#include "line.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    SDL_Plotter g(1001,1001);
    int dir = 0;
    int eat = 1;
    int count = 0;
    Color wallColor = Color(0, 0, 255);
    Color testColor = Color(255, 100, 100);

    Rectangle background(Point(0, 0), Point(1000, 1000), Color());
    background.draw(g);

    {
    Rectangle wall1(Point(94, 85), Point(200, 150), Color(0, 0, 255));
    wall1.draw(g);
    Rectangle wall2(Point(94, 213), Point(200, 238), wallColor);
    wall2.draw(g);
    Rectangle wall3a(Point(170, 310), Point(200, 425), wallColor);
    wall3a.draw(g);
    Rectangle wall3b(Point(94, 400), Point(200, 425), wallColor);
    wall3b.draw(g);
    Rectangle wall4a(Point(170, 500), Point(200, 625), wallColor);
    wall4a.draw(g);
    Rectangle wall4b(Point(94, 500), Point(200, 525), wallColor);
    wall4b.draw(g);
    Rectangle wall5a(Point(170, 688), Point(200, 813), wallColor);
    wall5a.draw(g);
    Rectangle wall5b(Point(94, 688), Point(200, 720), wallColor);
    wall5b.draw(g);
    Rectangle wall6(Point(94, 875), Point(200, 905), wallColor);
    wall6.draw(g);
    Rectangle wall7(Point(275, 85), Point(400, 150), wallColor);
    wall7.draw(g);
    Rectangle wall8a(Point(275, 213), Point(300, 335), wallColor);
    wall8a.draw(g);
    Rectangle wall8b(Point(275, 310), Point(400, 335), wallColor);
    wall8b.draw(g);
    Rectangle wall9(Point(275, 400), Point(300, 625), wallColor);
    wall9.draw(g);
    Rectangle wall10(Point(275, 688), Point(400, 720), wallColor);
    wall10.draw(g);
    Rectangle wall11a(Point(275, 785), Point(300, 905), wallColor);
    wall11a.draw(g);
    Rectangle wall11b(Point(275, 875), Point(400, 905), wallColor);
    wall11b.draw(g);
    Rectangle wall12a(Point(475, 150), Point(513, 335), wallColor);
    wall12a.draw(g);
    Rectangle wall12b(Point(375, 213), Point(625, 238), wallColor);
    wall12b.draw(g);
    Rectangle wall13(Point(375, 600), Point(625, 625), wallColor);
    wall13.draw(g);
    Rectangle wall14a(Point(475, 688), Point(513, 905), wallColor);
    wall14a.draw(g);
    Rectangle wall14b(Point(375, 785), Point(625, 813), wallColor);
    wall14b.draw(g);
    Rectangle wall15(Point(588, 85), Point(720, 150), wallColor);
    wall15.draw(g);
    Rectangle wall16a(Point(700, 213), Point(725, 335), wallColor);
    wall16a.draw(g);
    Rectangle wall16b(Point(588, 310), Point(725, 335), wallColor);
    wall16b.draw(g);
    Rectangle wall17(Point(700, 400), Point(725, 625), wallColor);
    wall17.draw(g);
    Rectangle wall18(Point(588, 688), Point(725, 720), wallColor);
    wall18.draw(g);
    Rectangle wall19a(Point(700, 785), Point(725, 905), wallColor);
    wall19a.draw(g);
    Rectangle wall19b(Point(588, 875), Point(725, 905), wallColor);
    wall19b.draw(g);
    Rectangle wall20(Point(800, 85), Point(910, 150), wallColor);
    wall20.draw(g);
    Rectangle wall21(Point(800, 215), Point(910, 238), wallColor);
    wall21.draw(g);
    Rectangle wall22a(Point(800, 310), Point(838, 425), wallColor);
    wall22a.draw(g);
    Rectangle wall22b(Point(800, 400), Point(910, 425), wallColor);
    wall22b.draw(g);
    Rectangle wall23a(Point(800, 500), Point(838, 625), wallColor);
    wall23a.draw(g);
    Rectangle wall23b(Point(800, 500), Point(910, 525), wallColor);
    wall23b.draw(g);
    Rectangle wall24a(Point(800, 688), Point(838, 813), wallColor);
    wall24a.draw(g);
    Rectangle wall24b(Point(800, 688), Point(910, 720), wallColor);
    wall24b.draw(g);
    Rectangle wall25(Point(800, 875), Point(910, 905), wallColor);
    wall25.draw(g);
    Rectangle wall26(Point(0, 310), Point(88, 335), wallColor);
    wall26.draw(g);
    Rectangle wall27(Point(0, 600), Point(88, 625), wallColor);
    wall27.draw(g);
    Rectangle wall28(Point(0, 785), Point(88, 813), wallColor);
    wall28.draw(g);
    Rectangle wall29(Point(913, 310), Point(1000, 335), wallColor);
    wall29.draw(g);
    Rectangle wall30(Point(913, 600), Point(1000, 625), wallColor);
    wall30.draw(g);
    Rectangle wall31(Point(913, 785), Point(1000, 813), wallColor);
    wall31.draw(g);
    Rectangle wall32(Point(375, 513), Point(625, 525), wallColor);
    wall32.draw(g);
    Rectangle wall33a(Point(375, 400), Point(388, 525), wallColor);
    wall33a.draw(g);
    Rectangle wall33b(Point(600, 400), Point(613, 525), wallColor);
    wall33b.draw(g);
    Rectangle wall34a(Point(375, 400), Point(388, 525), wallColor);
    wall34a.draw(g);
    Rectangle wall34b(Point(550, 400), Point(613, 413), testColor);
    wall34b.draw(g);
    //Rectangle wall35(Point(0, 0), Point(513, 85), testColor);
    //wall35.draw(g);
    }

    Circle pacman(20, Point (500, 450), Color(250, 250, 20));
    Triangle mouth(pacman.getCenter(), Point(pacman.getCenter().x + 20, pacman.getCenter().y - 10), Point(pacman.getCenter().x + 20, pacman.getCenter().y + 10), Color(255, 255, 255));
    Point p;
    pacman.draw(g);
    g.update();

    while (!g.getQuit())
    {
    	if(g.kbhit())
        {
    	    switch(g.getKey())
    	    {
    	        case RIGHT_ARROW:   dir = 1;
                                    break;
    	        case LEFT_ARROW:    dir = 2;
                                    break;
    	        case UP_ARROW:      dir = 3;
                                    break;
    	        case DOWN_ARROW:    dir = 4;
                                    break;
    	    }
    	}
    	switch (dir)
    	{
        case 1:   pacman.erase(g);
                  p = pacman.getCenter();
                  p.x += 1;
                  pacman.setCenter(p);
                  pacman.draw(g);
                  break;
        case 2:   pacman.erase(g);
                  p = pacman.getCenter();
                  p.x -= 1;
                  pacman.setCenter(p);
                  pacman.draw(g);
                  break;
        case 3:   pacman.erase(g);
                  p = pacman.getCenter();
                  p.y -= 1;
                  pacman.setCenter(p);
                  pacman.draw(g);
                  break;
        case 4:   pacman.erase(g);
                  p = pacman.getCenter();
                  p.y += 1;
                  pacman.setCenter(p);
                  pacman.draw(g);
                  break;
    	}
    	if (eat > 0 && dir != 0)
        {
            if (count == 100)
            {
                mouth.erase(g);
                mouth.setVertex(pacman.getCenter());
                mouth.setPoint1(Point(pacman.getCenter().x + 20, pacman.getCenter().y - 10));
                mouth.setPoint2(Point(pacman.getCenter().x + 20, pacman.getCenter().y + 10));
                mouth.draw(g);
                eat *= -1;
                count = 0;
            } else
            {
                mouth.erase(g);
                mouth.setVertex(pacman.getCenter());
                mouth.setPoint1(Point(pacman.getCenter().x + 20, pacman.getCenter().y - 10));
                mouth.setPoint2(Point(pacman.getCenter().x + 20, pacman.getCenter().y + 10));
                mouth.draw(g);
            }
            count++;
        } else
        {
            if (count == 100)
            {
                mouth.erase(g);
                eat *= -1;
                count = 0;
            }
            count++;
        }
        g.update();
        g.Sleep(10);
    }
}
