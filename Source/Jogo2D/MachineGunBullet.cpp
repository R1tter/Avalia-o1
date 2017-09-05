// Fill out your copyright notice in the Description page of Project Settings.

#include "MachineGunBullet.h"

void AMachineGunBullet::BeginPlay() {
	Super::BeginPlay();

	Damage = FMath::RandRange(5, 20);
}


