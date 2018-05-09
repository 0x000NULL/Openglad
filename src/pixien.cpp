
//pixien.cpp

/* ChangeLog
	buffers: 7/31/02: *include cleanup
*/
#include "graph.h"

// ************************************************************
//  PixieN -- N-Frame pixie
//  It is identical to the PIXIE class except it handles
//  multiple frames and switch frames before a put.
// ************************************************************

pixieN::pixieN(const PixieData& data):
		pixie(data)
{
	facings = data.data;
	frames = data.frames;
	frame = 0;
}

pixieN::pixieN(const PixieData& data, int doaccel):
		pixie(data)
{
	facings = data.data;
	frames = data.frames;
	frame = 0;
	if(doaccel)
		init_sdl_surface();
}

pixieN::~pixieN()
{
	bmp = NULL;
	facings = NULL;
	frames = 0;
	frame = 0;
}

// Changes the frame number and poshorts the BMP data poshorter to
//  the correct frame's data
short pixieN::set_frame(short framenum)
{
	if (framenum < 0 || framenum >= frames)
	{
		//Log("setting frame less than 0.\n");
		return 0;
	}
	bmp = facings+framenum*size;
	frame = framenum;
	return 1;
}

short pixieN::next_frame()
{
	return set_frame(frame++ % frames);
}

short pixieN::query_frame()
{
	return frame;
}
