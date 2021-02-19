// Fill out your copyright notice in the Description page of Project Settings.


#include "LV_Near.h"

LV_Near::LV_Near()
{
	equations.push_back(FuzzyLinearEquation(0.f, 300.f, 1.f, 1.f));
	equations.push_back(FuzzyLinearEquation(300.f, 800.f, 1.f, 0.f));
}