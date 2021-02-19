// Fill out your copyright notice in the Description page of Project Settings.


#include "LV_Approaching.h"

LV_Approaching::LV_Approaching()
{
	equations.push_back(FuzzyLinearEquation(-100.f, 100.f, 0.f, 1.f));
	equations.push_back(FuzzyLinearEquation(100.f, 800.f, 1.f, 1.f));
}