// Fill out your copyright notice in the Description page of Project Settings.


#include "FuzzyLinearEquation.h"

FuzzyLinearEquation::FuzzyLinearEquation(float rangeMin, float rangeMax, float valueMin, float valueMax)
	: m_rangeMin(rangeMin), m_rangeMax(rangeMax), m_valueMin(valueMin), m_valueMax(valueMax) {}

float FuzzyLinearEquation::GetValue(float input)
{
	if (input < m_rangeMin || input > m_rangeMax)
		return 0.f;

	const float range = m_rangeMax - m_rangeMin;
	const float value = m_valueMax - m_valueMin;

	const float delta = input - m_rangeMin;

	return m_valueMin + value * delta / range;
}

float FuzzyLinearEquation::GetRangeMin()
{
	return m_rangeMin;
}

float FuzzyLinearEquation::GetRangeMax()
{
	return m_rangeMax;
}