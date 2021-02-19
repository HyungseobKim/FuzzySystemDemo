// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>

#include "FuzzyLinearEquation.h"

#include "CoreMinimal.h"

/**
 * 
 */
class MAT367PROJECT1_API LinguisticVariable
{
public:
	float GetValue(float input);

	float GetRangeMin();
	float GetRangeMax();

protected:
	std::vector<FuzzyLinearEquation> equations;
};
