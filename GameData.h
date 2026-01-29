#ifndef GAMEDATA_H
#define GAMEDATA_H

// 1. The Player Object
struct Player {
	double x, y;
	double dx, dy; // Velocity
	bool isGrounded;
	bool isDead;
};

// 2. The Universal Object (for tiles, traps, goals)
struct GameObject {
	double x, y;
	double width, height;
	int type;       // 0=Empty, 1=Block, 2=Spike, 3=MovingTrap, 4=Goal
	int state;      // 0=Normal, 1=Triggered/Falling
	bool isVisible;
};

// 3. Global Game State
#define MAX_BLOCKS 100 // Max objects per level
struct Level {
	GameObject objects[MAX_BLOCKS]; // An array of blocks
	int objectCount;
	int startX, startY; // Where player spawns
};

#endif