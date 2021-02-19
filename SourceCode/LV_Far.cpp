// Fill out your copyright notice in the Description page of Project Settings.


#include "LV_Far.h"

LV_Far::LV_Far()
{
	equations.push_back(FuzzyLinearEquation(300.f, 800.f, 0.f, 1.f));
	equations.push_back(FuzzyLinearEquation(800.f, 2000.f, 1.f, 1.f));
}