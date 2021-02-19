// Fill out your copyright notice in the Description page of Project Settings.


#include "LV_MoveSlow.h"

LV_MoveSlow::LV_MoveSlow()
{
	equations.push_back(FuzzyLinearEquation(0.f, 100.f, 0.f, 1.f));
	equations.push_back(FuzzyLinearEquation(100.f, 200.f, 1.f, 0.f));
}