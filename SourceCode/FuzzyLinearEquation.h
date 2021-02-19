// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MAT367PROJECT1_API FuzzyLinearEquation
{
public:
	FuzzyLinearEquation(float rangeMin, float rangeMax, float valueMin, float valueMax);

	float GetValue(float input);

	float GetRangeMin();
	float GetRangeMax();

private:
	float m_rangeMin;
	float m_rangeMax;
	float m_valueMin;
	float m_valueMax;
};
