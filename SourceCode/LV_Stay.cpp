// Fill out your copyright notice in the Description page of Project Settings.


#include "LV_Stay.h"

LV_Stay::LV_Stay()
{
	equations.push_back(FuzzyLinearEquation(-100.f, 0.f, 0.f, 1.f));
	equations.push_back(FuzzyLinearEquation(0.f, 100.f, 1.f, 0.f));
}