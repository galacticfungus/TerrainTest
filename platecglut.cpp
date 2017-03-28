// platecglut.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "GL/glut.h"
#include <cstdlib>
#include <cfloat>
#include <vector>
#include "platecglut.h"
#include <iostream>


std::vector<float> GeometryGenerator::CreateTestTerrain(int terrain_size, float starting_height =  0.5f)
{
	m_size = terrain_size;//(1 << terrain_size) + 1;//Find the nearest value that is log 2 + 1
	m_total_size = m_size*m_size;
	m_current_map = std::vector<float>(m_total_size);
	generate_map(starting_height);
	return m_current_map;
}

void GeometryGenerator::generate_squares(int sideLength) const
{
	for (int x = 0; x < m_size - 1; x += sideLength) {
		for (int y = 0; y<m_size - 1; y += sideLength) {
			//x, y is upper left corner of square
			//calculate average of existing corners
			float avg_left = x + (y*m_size); //top left
			float avg_right = x + sideLength + (y*m_size);//top right
			float avg_lower_left = x + ((y + sideLength)*m_size); //lower left
			float avg_lower_right = x + sideLength+((y + sideLength)*m_size);//lower right
			//avg /= 4.0;
			std::cout << "Square Step" << '\n';
			std::cout << "Top Left:" << avg_left << '\n';
			std::cout << "Top Right:" << avg_right << '\n';
			std::cout << "Bottom Left:" << avg_lower_left << '\n';
			std::cout << "Bottom Right:" << avg_lower_right << '\n';
			//center is average plus random offset
			//m_current_map[x + halfSide + ((y + halfSide)*m_size)] =
			//We calculate random value in range of 2h
			//and then subtract h so the end value is
			//in the range (-h, +h)
			//avg + (r.nextDouble() * 2 * h) - h;
		}
	}
}

void GeometryGenerator::generate_diamonds(int sideLength, int halfSide) const
{
	for (int x = halfSide; x < m_size - 1; x += sideLength) {
		//and y is x offset by half a side, but moved by
		//the full side length
		//NOTE: if the data shouldn't wrap then y < DATA_SIZE
		//to generate the far edge values
		for (int y = (halfSide) % sideLength; y < m_size - 1; y += sideLength) {
			//x, y is center of diamond
			std::cout << "Center of diamond at: (" << x << "," << y << ")" << '\n';
			//note we must use mod  and add DATA_SIZE for subtraction 
			//so that we can wrap around the array to find the corners

			std::cout << "Diamond values" << '\n';
			//[(x - halfSide + DATA_SIZE - 1) % (DATA_SIZE - 1)][y]
			float center_left = (x - halfSide)+ (y * (m_size)); //left of center
			float center_right = (x + (y * (m_size)))+halfSide;//right of center
			float center_below = x + ((y+halfSide)*m_size); //below center - not 1 but halfSide
			float center_top = x + ((y-halfSide)*m_size); //above center
			std::cout << "Left of center:" << center_left << '\n';
			std::cout << "Right of center:" << center_right << '\n';
			std::cout << "Above center:" << center_top << '\n';
			std::cout << "Below center:" << center_below << '\n';
				
			//new value = average plus random offset
			//We calculate random value in range of 2h
			//and then subtract h so the end value is
			//in the range (-h, +h)
			//avg = avg + (r.nextDouble() * 2 * h) - h;
			//update value for center of diamond
			//data[x][y] = avg;

			//wrap values on the edges, remove
			//this and adjust loop condition above
			//for non-wrapping values.
			//if (x == 0)  data[DATA_SIZE - 1][y] = avg;
			//if (y == 0)  data[x][DATA_SIZE - 1] = avg;
		}
	}
}

void GeometryGenerator::generate_map(float initial_height)
{
	
	//0,0 TL
	//0,map_size BL
	//map_size,0 TR
	//map_size,map_size BR
	//Seed map
	
	m_current_map[0] = initial_height;//initial_height is a seed
	m_current_map[m_size - 1] = initial_height;
	m_current_map[(m_total_size) - m_size] = initial_height;
	m_current_map[(m_total_size) - 1] = initial_height;
	
	for (int sideLength = m_size - 1;sideLength >= 2;sideLength >>= 1)//, h >>= 1)
	{
		//half the length of the side of a square
		//or distance from diamond center to one corner
		//(just to make calcs below a little clearer)
		int halfSide = sideLength >> 1;
		std::cout << "New side length" << '\n' << '\n';
		//generate the new square values
		generate_squares(sideLength);

		//generate the diamond values
		//since the diamonds are staggered we only move x
		//by half side
		//NOTE: if the data shouldn't wrap then x < DATA_SIZE
		//to generate the far edge values
		generate_diamonds(sideLength, halfSide);
	}


	return;
}



float GeometryGenerator::diamond_average(int d, int stride)
{
	//Average four corner values of a square
	//x and y are in the centre of the square
	//
	//
	int offset = d + stride;
	return 0.0f;
}

float GeometryGenerator::square_average(int d, int stride)
{
	return 0.0f;
}

