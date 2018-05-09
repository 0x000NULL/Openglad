//intro.cpp
/* ChangeLog
	buffers: 8/9/02: *added return 0 to finish func
*/

#include "graph.h"
//#include "pixie.h"
// Z's script: #include <process.h>
#include <cstring>

#define SHOW_TIME 130
#define FROM 1
#define TO 0
#include "input.h"

int show();
int show(int howlong);
int cleanup();

int pal[256][3];
unsigned char mypalette[768];
//screen *myscreen;

void intro_main(Sint32 argc, char** argv)
{
	// Zardus: PORT: doesn't seem to be used, and causes a memory leak
	//char **args = (char **)new int;
	text& mytext = myscreen->text_normal;
	pixie *gladiator;
	pixie *bigfoot;
	pixie *ul, *ur, *ll, *lr; // for full-screen displays
	PixieData uldata, urdata, lldata, lrdata;
	PixieData gladdata, bigdata;
	char message[80];

	ul = ur = ll = lr = NULL;

	myscreen->viewob[0]->resize(PREF_VIEW_FULL);
	grab_timer();
	
	load_and_set_palette("our.pal", mypalette);
	//  load_scenario("current", myscreen);
	//buffers: PORT:  for (i=0;i<256;i++)
	//buffers: PORT:         set_palette_reg(i,0,0,0);
    
    myscreen->fadeblack(TO);
    
	myscreen->clear();

	gladdata = read_pixie_file("3mages2.pix");
	gladiator = new pixie(gladdata);
	gladiator->drawMix(120,55,myscreen->viewob[0]);
	mytext.write_y(100,"Ethan Aldrich PRESENTS", 230, myscreen->viewob[0]);
	//myscreen->refresh();
	delete gladiator;
	gladdata.free();

	if (show() < 0)
	{
		cleanup();
		return;
	}

	//gladdata = read_pixie_file("glad.pix");
	gladdata = read_pixie_file("glad2.pix");
	gladiator = new pixie(gladdata);
	bigdata = read_pixie_file("bigfoot.pix");
	bigfoot = new pixie(bigdata);
	myscreen->clear();
	bigfoot->drawMix(120,50,myscreen->viewob[0]);
	//gladiator->drawMix(110,65,myscreen->viewob[0]);
	gladiator->drawMix(100, 110, myscreen->viewob[0]);
	//myscreen->refresh();

	gladdata.free();
	delete gladiator;
	delete bigfoot;
	bigdata.free();

	if (show() < 0)
	{
		cleanup();
		return;
	}

	myscreen->clear();
	mytext.write_y(70,"THOSE WHO ARE ABOUT TO DIE SALUTE YOU", 230, myscreen->viewob[0]);
	//myscreen->refresh();

	if (show() < 0)
	{
		cleanup();
		return;
	}

	// Programming Credits, Page 1
	myscreen->clear();
	mytext.write_y(80,"Programming By:", 230, myscreen->viewob[0]);
	mytext.write_y(100,"Ethan Aldrich  Asher Weller", 230, myscreen->viewob[0]);
	mytext.write_y(110,"Clayton Taylor  Tiernan Minnalez", 230, myscreen->viewob[0]);

	//myscreen->refresh();

	if (show() < 0)
	{
		cleanup();
		return;
	}

	// First 'interlude' snapshot
	myscreen->clear();
	uldata = read_pixie_file("game2ul.pix");
	ul = new pixie(uldata);
	ul->setxy(41, 12);
	ul->draw(myscreen->viewob[0]);
	delete ul;
	uldata.free();
	ul = NULL;

	urdata = read_pixie_file("game2ur.pix");
	ur = new pixie(urdata);
	ur->setxy(160, 12);
	ur->draw(myscreen->viewob[0]);
	delete ur;
	urdata.free();
	ur = NULL;

	lldata = read_pixie_file("game2ll.pix");
	ll = new pixie(lldata);
	ll->setxy(41, 103);
	ll->draw(myscreen->viewob[0]);
	delete ll;
	lldata.free();
	ll = NULL;

	lrdata = read_pixie_file("game2lr.pix");
	lr = new pixie(lrdata);
	lr->setxy(160, 103);
	lr->draw(myscreen->viewob[0]);
	delete lr;
	lrdata.free();
	lr = NULL;

	//myscreen->refresh();

	if (show(SHOW_TIME+30) < 0)
	{
		cleanup();
		return;
	}

	// Programming Credits, Page 2
	myscreen->clear();
	mytext.write_y(90,"Additional Coding by Jacob Willis", 230, myscreen->viewob[0]);
	//buffers: PORT: w00t w00t
	mytext.write_y(110,"Artwork by Ethan Aldrich Jacob Willis",230,myscreen->viewob[0]);
	//myscreen->refresh();

	if (show() < 0)
	{
		cleanup();
		return;
	}



	//myscreen->refresh();

	if (show(SHOW_TIME*4) < 0)
	{
		cleanup();
		return;
	}

	// cleanup
	/*
	  for (i = 0; i<256; i++)
	  {
	         red = pal[i][0];
	         green = pal[i][1];
	         blue = pal[i][2];
	         set_palette_reg(i, red, green, blue);
	  }
	*/

	cleanup();
}


int cleanup()
{
	Sint32 i;
	int red,green,blue; //buffers: PORT: changed to ints
	query_palette_reg((unsigned char)0, &red, &green, &blue); // Resets palette to read mode
	release_timer();
	myscreen->clear();
	myscreen->refresh();

	for (i = 0; i<256; i++)
	{
		red = pal[i][0];
		green = pal[i][1];
		blue = pal[i][2];
		set_palette_reg(i, red, green, blue);
	}
	load_and_set_palette("our.pal", mypalette);
	return 1;
}

int show() // default uses SHOW_TIME
{
	return show(SHOW_TIME);
}

int show(int howlong)
{
	if (myscreen->fadeblack(FROM) == -1) return -1;

	reset_timer();
	while (query_timer() < howlong)
	{
		get_input_events(POLL);
		if (query_key_press_event())
			return -1;
	}

	if (myscreen->fadeblack(TO) == -1) return -1;
	return 1;
}
