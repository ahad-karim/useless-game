#ifndef PHYSICS_H
#define PHYSICS_H
#include "GameData.h"

// REUSABLE FUNCTION 1: Generic AABB Collision
// Returns true if two rectangles overlap
bool checkAABB(double x1, double y1, double w1, double h1,
	double x2, double y2, double w2, double h2) {
	return (x1 < x2 + w2 && x1 + w1 > x2 &&
		y1 < y2 + h2 && y1 + h1 > y2);
}

// REUSABLE FUNCTION 2: Physics Update
// Updates player and handles collisions with ANY level data
void updatePlayerPhysics(Player &p, Level &lvl) {
	// 1. Apply Gravity
	p.dy -= 1;

	// 2. Update Y Position & Check Vertical Collisions
	p.y += p.dy;
	p.isGrounded = false;

	for (int i = 0; i < lvl.objectCount; i++) {
		GameObject &obj = lvl.objects[i];

		if (obj.isVisible && checkAABB(p.x, p.y, 30, 30, obj.x, obj.y, obj.width, obj.height)) {
			// If hitting a spike, die
			if (obj.type == 2) p.isDead = true;

			// If hitting a solid block (Type 1), stop falling
			if (obj.type == 1) {
				if (p.dy < 0) { // Falling down
					p.y = obj.y + obj.height;
					p.isGrounded = true;
					p.dy = 0;
				}
			}
		}
	}

	// 3. Update X Position (Similar logic for horizontal collision)
	p.x += p.dx;
	// ... (Horizontal collision code here)
}
#endif