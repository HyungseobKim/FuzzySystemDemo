// Fill out your copyright notice in the Description page of Project Settings.


#include "LV_Departing.h"

LV_Departing::LV_Departing()
{
	equations.push_back(FuzzyLinearEquation(-800.f, -100.f, 1.f, 1.f));
	equations.push_back(FuzzyLinearEquation(-100.f, 100.f, 1.f, 0.f));
}