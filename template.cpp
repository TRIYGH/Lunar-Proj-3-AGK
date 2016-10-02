// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

void Congrats();

//constants for the screen resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int PAD = 1;
const int SHIP= 2;
const int MOON= 3;
const float MinPos = -40;
const float MinPosX = -40;

bool YouWin = false;

float x, y, LandingValueX, LandingValueY, HowCloseX, HowCloseY;

// Begin app, called once at the start
void app::Begin( void )
{
	//set the virtual resolution
	agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);
	agk::CreateSprite(PAD,"landing%20pad.png");
	agk::CreateSprite(SHIP,"lunar%20lander.png");
	agk::CreateSprite(MOON,"lunar%20surface.png");

	agk::SetClearColor(255,255,255);
	agk::SetSpriteDepth(MOON,1000);

	x = agk::Random(1,SCREEN_WIDTH - agk::GetSpriteWidth(PAD) );
	y = agk::Random(327,SCREEN_HEIGHT);
	agk::SetSpritePosition(PAD,x,y);
	LandingValueX = x;  //save this for later when you land
	LandingValueY = y-77;  //save this for later when you land

	x = agk::Random(1,SCREEN_WIDTH - agk::GetSpriteWidth(SHIP) );
	y = agk::Random(300,SCREEN_HEIGHT);
	agk::SetSpritePosition(SHIP,x,y);

	agk::SetSyncRate(10,1);
}

// Main loop, called every frame
void app::Loop ( void )
{
	
	if(agk::GetRawKeyState(AGK_KEY_LEFT))
		x = x + (agk::GetDirectionX()-2);
	if(agk::GetRawKeyState(AGK_KEY_RIGHT))
		x = x + (agk::GetDirectionX()+2);

	if(agk::GetRawKeyState(AGK_KEY_DOWN))
		y=y+5;

	agk::SetSpritePosition(SHIP,x,y);

	agk::Sync();

	if(agk::GetRawKeyState(AGK_KEY_SPACE))
		y=y-3;
	else
		y=y+1;

	if (y>4700)
		y=470;
	if(y<MinPos)
		y = MinPos;
	if(x>630)
		x=470;
	if(x<MinPosX)
		x=MinPosX;

	HowCloseX = LandingValueX - x;
	if(HowCloseX < 0)
		HowCloseX = HowCloseX * -1;

	HowCloseY = LandingValueY - y;
	if(HowCloseY < 0)
		HowCloseY = HowCloseY * -1;

	if(HowCloseY <= 3)
		if(HowCloseX <= 3)
			YouWin = true;

	if(YouWin)
		Congrats();

	//agk::Print(x);
	//agk::Print(y);
	//agk::Print(LandingValueX);
	//agk::Print(LandingValueY);

}

// Called when the app ends
void app::End ( void )
{
	
}

void Congrats()
{
	bool nothing = true;
	agk::Print("Congratulations - You landed your Ship.");
	do
	{}
		while(nothing);

}