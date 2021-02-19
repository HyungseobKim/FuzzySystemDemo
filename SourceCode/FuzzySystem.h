// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>

#include "LV_Far.h"
#include "LV_Near.h"
#include "LV_Approaching.h"
#include "LV_Departing.h"
#include "LV_Stay.h"
#include "LV_MoveSlow.h"
#include "LV_MoveFast.h"

#include "CoreMinimal.h"

/**
 * 
 */
class MAT367PROJECT1_API FuzzySystem
{
public:
	FuzzySystem();

	float Defuzzyfication(float distance, float speed);

private:
	void ClearTable();

	void FuzzyRule(int rule, LinguisticVariable* antecedent1, float input1, LinguisticVariable* antecedent2, float input2, LinguisticVariable* consequence);

private:
	LV_Near A1Near;
	LV_Far A2Far;
	LV_Departing B1Departing;
	LV_Approaching B2Approaching;
	LV_Stay C1Stay;
	LV_MoveSlow C2MoveSlow;
	LV_MoveFast C3MoveFast;

	std::vector<std::vector<float>> table;
};
