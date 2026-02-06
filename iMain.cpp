#include "iGraphics.h"

int gameState = 0;
bool vol = true;
int logo, newgamebut, continuebut, volon, voloff, scores, levelbut;

void iDraw()
{
	iClear();

	if (gameState == 0) {
		// --- DRAW MAIN MENU ---
		iSetColor(30, 30, 30); // Background Brown
		iFilledRectangle(0, 0, 1080, 600);

		iSetColor(255, 255, 255); // White for boxes

		// Logo (Top Center)
		//iRectangle(390, 450, 300, 160);
		//iText(520, 525, "Logo");
		//iShowBMP(390, 450, "logo1.bmp");
		iShowImage(390, 325, 300, 300, logo);

		// Name Box (Middle)
		//iRectangle(390, 375, 300, 70);
		//iText(520, 405, "RageRush");

		// "Con" Button (Bottom Left)
		//iRectangle(215, 250, 240, 80);
		//iText(320, 285, "Continue");
		iShowImage(285, 255, 215, 65, continuebut);

		// "New Game" Button (Bottom Right)
		//iRectangle(550, 250, 240, 80);
		//iText(620, 285, "New Game");
		iShowImage(580, 250, 240, 80, newgamebut);

		//score button
		iShowImage(440, 165, 180, 95, scores);

		//levels button
		iShowImage(440, 90, 180, 95, levelbut);

		if (vol) {
			iShowImage(0, 0, 70, 70, volon);
		}
		else {
			iShowImage(0, 0, 70, 70, voloff);
		}
	}
	else if (gameState == 1) {
		// --- DRAW LEVEL 1 PAGE ---

		iSetColor(180, 110, 80); // Background Brown
		iFilledRectangle(0, 0, 1080, 600);

		iSetColor(120, 70, 50); // A slightly different brown for the UI box

		// Brown rectangular box of size 1080 * 200 (at the top)
		iFilledRectangle(0, 0, 1080, 200);

		iSetColor(255, 255, 255);
		// "Level 1" at top center
		// Note: GLUT_BITMAP_TIMES_ROMAN_24 is the largest standard font.
		iText(490, 550, "Level 1", GLUT_BITMAP_TIMES_ROMAN_24);
	}

}

void iMouseMove(int mx, int my)
{
	
}

void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// Only check for clicks if we are currently on the menu
		if (gameState == 0) {
			// "New Game" coordinates based on the rectangle above:
			// x: 550 to 790 (550 + 240)
			// y: 250 to 330 (250 + 80)
			if (mx >= 550 && mx <= 790 && my >= 250 && my <= 330) {
				gameState = 1; // Change state to Level 1

				// Logic for "Registering new player"
				printf("New Player Registered. Loading Level 1...\n");
			}

			//changing volume
			if (mx >= 0 && my >= 0 && mx <= 70 && my <= 70) {
				vol = !vol;

				
			}
		}
		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

// Special Keys:
// GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
// GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT

void fixedUpdate()
{
	if (isKeyPressed('w') || isSpecialKeyPressed(GLUT_KEY_UP))
	{
		
	}
	if (isKeyPressed('a') || isSpecialKeyPressed(GLUT_KEY_LEFT))
	{
		
	}
	if (isKeyPressed('s') || isSpecialKeyPressed(GLUT_KEY_DOWN))
	{
		
	}
	if (isKeyPressed('d') || isSpecialKeyPressed(GLUT_KEY_RIGHT))
	{
		
	}

	if (isKeyPressed(' ')) {
		// Playing the audio once
		//mciSendString("play ggsong from 0", NULL, 0, NULL);
	}
}

void initImages() {
	logo = iLoadImage("Images//logo3.png");
	newgamebut = iLoadImage("Images//newgame.png");
	continuebut = iLoadImage("Images//continue.png");
	volon = iLoadImage("Images//volon.png");
	voloff = iLoadImage("Images//voloff.png");
	scores = iLoadImage("Images//score2.png");
	levelbut = iLoadImage("Images//levels.png");
}


int main()
{
	// Opening/Loading the audio files
	//mciSendString("open \"Audios//background.mp3\" alias bgsong", NULL, 0, NULL);
	//mciSendString("open \"Audios//gameover.mp3\" alias ggsong", NULL, 0, NULL);

	// Playing the background audio on repeat
	//mciSendString("play bgsong repeat", NULL, 0, NULL);

	// If the use of an audio is finished, close it to free memory
	// mciSendString("close bgsong", NULL, 0, NULL);
	// mciSendString("close ggsong", NULL, 0, NULL);

	iInitialize(1080, 600, "RageRush");

	initImages();

	iStart();
	return 0;
}