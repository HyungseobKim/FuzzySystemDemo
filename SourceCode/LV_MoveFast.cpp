// Fill out your copyright notice in the Description page of Project Settings.


#include "LV_MoveFast.h"

LV_MoveFast::LV_MoveFast()
{
	equations.push_back(FuzzyLinearEquation(100.f, 200.f, 0.f, 1.f));
	equations.push_back(FuzzyLinearEquation(200.f, 500.f, 1.f, 1.f));
}