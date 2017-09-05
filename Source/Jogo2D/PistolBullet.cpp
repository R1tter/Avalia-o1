// Fill out your copyright notice in the Description page of Project Settings.

#include "PistolBullet.h"

void APistolBullet::BeginPlay() {
	Super::BeginPlay();

	Damage = FMath::RandRange(1,10);

}


