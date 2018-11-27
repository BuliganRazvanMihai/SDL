
#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen2.h"
#include<stdlib.h>
#include<time.h>
#include "swarm.h"
using namespace std;
using namespace razvan;

int main(int argc,char *argv[]) {

	srand(time(NULL));//vede random generatorul

	Screen2 screen;

	if (screen.init() == false) {
		cout << "Error initialising SDL." << endl;
	}

	Swarm swarm;


	while (true) {
		// Update particles

		// Draw particles

		int elapsed = SDL_GetTicks();


		
		swarm.update(elapsed);

		unsigned char green = (1 + sin(elapsed*0.0001)) * 128;
		unsigned char red = (1 + sin(elapsed*0.0002)) * 128;
		unsigned char blue = (1 + cos(elapsed*0.0003)) * 128;


		const Particle *const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x +1)*Screen2::SCREEN_WIDTH/2;
			int y = particle.m_y * Screen2::SCREEN_WIDTH / 2+ Screen2::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green,blue);

		}
		
		screen.boxBlur();

		// Draw the screen
		screen.update();

		// Check for messages/events
		if (screen.processEvents() == false) {
			break;
		}
	}//game loop
	
	screen.close();

	return 0;
}