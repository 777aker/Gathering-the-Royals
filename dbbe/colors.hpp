#pragma once

// colors for drawing
struct color
{
	int r;
	int g;
	int b;

	bool operator==(const color &other) const
	{
		return (r == other.r && g == other.g && b == other.b);
	}
};

const struct color turquoise = {26, 188, 156};	 // rgb(26, 188, 156)
const struct color green_sea = {22, 160, 133};	 // rgb(22, 160, 133)
const struct color emerald = {46, 204, 113};	 // rgb(46, 204, 113)
const struct color nephritis = {39, 174, 96};	 // rgb(39, 174, 96)
const struct color wet_asphalt = {52, 73, 94};	 // rgb(52, 73, 94)
const struct color midnight_blue = {44, 62, 80}; // rgb(44, 62, 80)
const struct color sunflower = {241, 196, 15};	 // rgb(241, 196, 15)
const struct color carrot = {230, 126, 34};		 // rgb(230, 126, 34)
const struct color pumpkin = {211, 84, 0};		 // rgb(211, 84, 0)
const struct color alizarin = {231, 76, 60};	 // rgb(231, 76, 60)
const struct color pomegranate = {192, 57, 43};	 // rgb(192, 57, 43)
const struct color clouds = {236, 240, 241};	 // rgb(236, 240, 241)
const struct color concrete = {127, 140, 141};	 // rgb(127, 140, 141)
const struct color asbestos = {127, 140, 141};	 // rgb(127, 140, 141)
const struct color black = {0, 0, 0};			 // rgb(0, 0, 0)