// Fill out your copyright notice in the Description page of Project Settings.


#include "LinguisticVariable.h"

float LinguisticVariable::GetValue(float input)
{
	const int size = static_cast<int>(equations.size());

	for (int i = 0; i < size; ++i)
	{
		auto value = equations[i].GetValue(input);

		if (value != 0.f)
			return value;
	}

	return 0.f;
}

float LinguisticVariable::GetRangeMin()
{
	float min = equations[0].GetRangeMin();

	const int size = static_cast<int>(equations.size());

	for (int i = 1; i < size; ++i)
		min = std::min(min, equations[i].GetRangeMin());

	return min;
}

float LinguisticVariable::GetRangeMax()
{
	float max = equations[0].GetRangeMax();

	const int size = static_cast<int>(equations.size());

	for (int i = 1; i < size; ++i)
		max = std::max(max, equations[i].GetRangeMax());

	return max;
}