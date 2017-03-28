#pragma once
#include <vector>

class GeometryGenerator
{
public:
	std::vector<float> CreateTestTerrain(int terrain_size, float startingHeight);
	void generate_squares(int sideLength) const;
	void generate_diamonds(int sideLength, int halfSide) const;

	int get_size() const
	{
		return m_size;
	}

private:
	int m_size = 0;
	int m_total_size = 0;
	std::vector<float> m_current_map;

private:
	void generate_map(float initial_height);
	float diamond_average(int d, int stride);
	float square_average(int d, int stride);
};
