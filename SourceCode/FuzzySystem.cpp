// Fill out your copyright notice in the Description page of Project Settings.


#include <numeric>

#include "FuzzySystem.h"

FuzzySystem::FuzzySystem()
{
	// Initialize range.
	const float rangeMin = C1Stay.GetRangeMin();
	const float rangeMax = C3MoveFast.GetRangeMax();
	const float range = rangeMax - rangeMin;

	for (int i = 0; i < 5; ++i)
		table.push_back(std::vector<float>(range / 10.f));

	for (int i = 0; i < range / 10.f; ++i)
		table[0][i] = rangeMin + i * 10.f;

	ClearTable();
}

float FuzzySystem::Defuzzyfication(float distance, float speed)
{
	ClearTable();

	// Each method will write the result of each rule to the table.
	FuzzyRule(1, &A1Near, distance, &B1Departing, speed, &C2MoveSlow);
	FuzzyRule(2, &A1Near, distance, &B2Approaching, speed, &C3MoveFast);
	FuzzyRule(3, &A2Far, distance, &B1Departing, speed, &C1Stay);
	FuzzyRule(4, &A2Far, distance, &B2Approaching, speed, &C2MoveSlow);

	float numerator = 0.f;
	float denominator = 0.f;

	const int size = static_cast<int>(table[0].size());

	// Compute Riemann Sum
	for (int i = 0; i < size; ++i)
	{
		const float input = table[0][i];
		float max = table[1][i];

		for (int j = 2; j < 5; ++j)
			max = std::max(max, table[j][i]);

		numerator += input * max;
		denominator += input;
	}

	return numerator / denominator;
}

void FuzzySystem::ClearTable()
{
	const int size = table[0].size();

	for (int i = 1; i < 5; ++i)
	{
		auto& temp = table[i];

		for (int j = 0; j < size; ++j)
			temp[j] = std::numeric_limits<float>::min();
	}
}

void FuzzySystem::FuzzyRule(int rule, LinguisticVariable* antecedent1, float input1, LinguisticVariable* antecedent2, float input2, LinguisticVariable* consequence)
{
	const float alpha1 = antecedent1->GetValue(input1);
	const float alpha2 = antecedent2->GetValue(input2);

	// Take minimum of two results from antecedents.
	const float firingLevel = std::min(alpha1, alpha2);

	constexpr float epsilon = std::numeric_limits<float>::epsilon();

	const auto& xAxis = table[0];
	auto& yAxis = table[rule];

	const int size = xAxis.size();

	// Take maximum of firing level and consequence.
	for (int i = 0; i < size; ++i)
	{
		const float value = consequence->GetValue(xAxis[i]);

		if (value <= firingLevel)
			yAxis[i] = std::max(yAxis[i], value);
		else
			yAxis[i] = std::max(yAxis[i], firingLevel);
	}
}